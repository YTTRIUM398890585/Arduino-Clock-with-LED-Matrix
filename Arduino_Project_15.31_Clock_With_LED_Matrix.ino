//Connection For 7-Segment and RTC
//SDA to A4
//SCL to A5
//https://learn.adafruit.com/adafruit-7-segment-led-featherwings/arduino-usage
//https://lastminuteengineers.com/ds3231-rtc-arduino-tutorial/

//Connection For LED Matrix
//DIN to 11
//CS  to CS_PIN 12  //Any
//CLK to 13
//https://lastminuteengineers.com/max7219-dot-matrix-arduino-tutorial/

/*Version of Software*/
uint16_t Version = 1531;


/*RTC*/
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc = RTC_DS3231();


/*7-Segmant Display*/               //<Wire.h> is also needed for 7-segment
#include <Adafruit_GFX.h>           //this 
#include <Adafruit_LEDBackpack.h>   //and this are both needed for 7-segment

#define DISPLAY_ADDRESS 0x70
#define Max_SevenSeg_Brightness_Address 48

uint8_t Max_SevenSeg_Brightness;    //Read form EEPROM 48

Adafruit_7segment Seven_Segment = Adafruit_7segment();


/*LED Matrix*/
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

#define No_DEVICES 1
#define CS_PIN 10

MD_MAX72XX Mat_MAX72XX = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, No_DEVICES);


/*For EEPROM*/
#include <EEPROM.h>
//0-47  for Alarm_Time_Array and Alarm_State_Array
//48    for Max_SevenSeg_Brightness
//49    for Alarm_Duration
//50-51 for Night_Time_Off
//52-53 for Morning_Time_On
//54    for Buzzer_Enable
//55    for Alarm_Sound
//56    for Alarm_Disable
//57    for Snooze_Duration
//58-59 for Highest_Score

#define Highest_Score_0_7_Address 58
#define Highest_Score_8_15_Address 59

/*For Clock Logic*/
uint16_t year = 0;
uint8_t month = 0;
uint8_t day = 0;
uint8_t dayOfTheWeek = 0;

uint8_t hours = 0;
uint8_t minutes = 0;
uint8_t seconds = 0;

uint16_t Clock_Time = 9999; //display on seven segment, cant be a value same as any Alarm_Time otherwise alarm we sound

bool LED_Colon = true;

unsigned long previousMillis_ClockLogic = 0;


/*For Set Clock Logic*/
uint8_t Clock_Set_Mode = 0; //Setting options, 0 is setting minutes, 1 for hours, 2 for enter setting

bool Clock_Set = false;
bool decimalpoint = false;


/*For Alarm Logic*/
uint16_t Alarm_Time_Array[32];

bool Alarm_State_Array[16];

const uint8_t No_of_Alarm = 16;

#define Alarm_Duration_Address 49
uint8_t Alarm_Duration;  //Read form EEPROM 49
#define Snooze_Duration_Address 57
uint8_t Snooze_Duration;

bool Alarm = false;
bool Snooze = false;

bool Next_Minute = false;
//this will disable alarm till the next min so that the same alarm won't keep sounding after its cleared.

#define Alarm_Disable_Address 56
bool Alarm_Disable;
//to permanently disable all the alarms

bool Buzzer_Alarm = false;
uint8_t Buzzer_PWM = 0;

#define Alarm_Sound_Address 55
uint8_t Alarm_Sound;

unsigned long Alarm_Millis = 0;
unsigned long previousMillis_AlarmNoise = 0;


/*For Setting Alarm*/
uint8_t Alarm_No = 0;
uint8_t SetAlarmTime_Mode = 0;

bool Alarm_Set = false;
bool Alarm_Time_Set = false;


/*For Spacial Day*/
// Chirstmas, Morse code day, New year's eve
uint8_t SD_Date[] = {25, 12,
                     27,  4,
                     31, 12
                    };  //day 1, month 1, day 2, month 2, ...

bool Spacial_Day = false;
bool Temporarily_SD_Disable = false;

uint8_t No_of_SD = 16;
uint8_t ID_of_SD_Triggered = 16;

unsigned long previousMillis_SD_Disable = 0;


/*For LED Matrix Display*/
uint8_t Mat_Mode = 0;
uint8_t Previous_Mat_Mode = 1;

uint8_t Matrix_Animation_Frame = 0;

uint8_t x_coordinate = 0;
uint8_t y_coordinate = 0;

unsigned long previousMillis_Matrix_Animation = 0;

bool Matrix_First_Time_Animation = true;


/*For Menu*/
uint8_t Menu_Mode = 0;

bool Menu = false;


/*For General Setting*/
uint8_t Gen_Set_Mode = 0;

bool Gen_Set = false;


/*General Stuffs*/
#define Button_A A2
#define Button_B A3

#define Buzzer 4
#define LED_1 5
#define LED_2 6

#define RandomPin A0

bool Button_A_State = HIGH;
bool Button_B_State = HIGH;

bool Sleep_Mode = false;

unsigned long presentMillis = 0;

#define Buzzer_Enable_Address 54
bool Buzzer_Enable;  //Read form EEPROM 54

#define Night_Time_Off_Address_hr 50
#define Night_Time_Off_Address_min 51
#define Morning_Time_On_Address_hr 52
#define Morning_Time_On_Address_min 53
uint16_t Night_Time_Off;   //Read form EEPROM 50 and 51
uint16_t Morning_Time_On;  //Read form EEPROM 52 and 53


void setup() {
  for (int n = 0; n < No_of_Alarm; n++) {
    Alarm_Time_Array[n] = (EEPROM.read(3 * n) * 100 + EEPROM.read(3 * n + 1));
    //  Alarm_Hours are stored in first of three EEPROM spaces, Alarm_Minutes second.
    //  Each spaces ca hold 8 bits

    Alarm_State_Array[n] = (EEPROM.read(3 * n + 2));
    //  Alarm_State in thrid
  }

  Max_SevenSeg_Brightness =  EEPROM.read(Max_SevenSeg_Brightness_Address);
  Buzzer_Enable           =  EEPROM.read(Buzzer_Enable_Address);
  Alarm_Duration          =  EEPROM.read(Alarm_Duration_Address);
  Night_Time_Off          = (EEPROM.read(Night_Time_Off_Address_hr)) * 100 + EEPROM.read(Night_Time_Off_Address_min);
  Morning_Time_On         = (EEPROM.read(Morning_Time_On_Address_hr)) * 100 + EEPROM.read(Morning_Time_On_Address_min);
  Alarm_Sound             =  EEPROM.read(Alarm_Sound_Address);
  Alarm_Disable           =  EEPROM.read(Alarm_Disable_Address);
  Snooze_Duration         =  EEPROM.read(Snooze_Duration_Address);

  rtc.begin();

  Seven_Segment.begin(DISPLAY_ADDRESS);
  Seven_Segment.setBrightness(Max_SevenSeg_Brightness);

  Mat_MAX72XX.begin();
  Mat_MAX72XX.clear();

  pinMode(Button_A, INPUT_PULLUP);
  pinMode(Button_B, INPUT_PULLUP);

  pinMode(Buzzer, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);

  digitalWrite(Buzzer, LOW);
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);

  pinMode(RandomPin, INPUT);
  randomSeed(analogRead(RandomPin));

  Initial_Sequence();

  //  rtc.adjust(DateTime(year, month, day, hours, minutes, seconds));
  //  rtc.adjust(DateTime(2021, 8, 27, 21, 59, 40));

  //        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  //sets the RTC to the date & time this sketch was compiled
}

void loop() {
  Button_A_State = digitalRead (Button_A);
  Button_B_State = digitalRead (Button_B);

  if (Button_A_State == LOW || Button_B_State == LOW) {
    Snooze = false;
  }

  presentMillis = millis();

  if (Alarm == true) {
    ClockLogic();
    Alarm_Noise();

    if (Button_A_State == LOW) {  //Snooze Alarm
      Alarm = false;
      Snooze = true;
      Alarm_Millis = presentMillis;
      Mat_MAX72XX.clear();
      digitalWrite(Buzzer, LOW);
      digitalWrite(LED_2, LOW);
      Beep();
      delay(100);
    }

    if (Button_B_State == LOW) {  //Dismiss Alarm
      Alarm = false;
      Snooze = false;
      Mat_MAX72XX.clear();
      digitalWrite(Buzzer, LOW);
      digitalWrite(LED_2, LOW);
      Beep();
      delay(100);
    }

    if (presentMillis - Alarm_Millis >= Alarm_Duration * 60000) { //Alarm will be snoozed after Alarm_Duration (in min)
      Mat_MAX72XX.clear();
      Alarm = false;
      Snooze = true;
      Alarm_Millis = presentMillis;
      digitalWrite(Buzzer, LOW);
      digitalWrite(LED_2, LOW);
    }
  }
  else if (Menu == true) {
    ClockLogic();
    Setting_Menu();
  }
  else if (Clock_Set == true) {
    SetClockLogic();
  }
  else if (Alarm_Set == true) {
    SetAlarmLogic();
  }
  else if (Gen_Set == true) {
    General_Setting();
  }
  else {  //normal operation
    ClockLogic();
    MatrixLogic();
    Alarm_Logic();
    Special_Day_Logic();

    if (Button_A_State == LOW) {
      Previous_Mat_Mode = Mat_Mode;
      Mat_Mode = 0;
      digitalWrite(LED_2, LOW);
      Beep();

      delay(100);

      Button_A_State = digitalRead (Button_A);

      if (Button_A_State == LOW) {
        Seven_Segment.setBrightness(0);
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        Sleep_Mode = true;
        Beep();
        delay(200);
      }
    }

    if (Button_B_State == LOW) {
      Sleep_Mode = false;

      if (Mat_Mode == 0) {
        Mat_Mode = Previous_Mat_Mode;
        Previous_Mat_Mode = 0;
        if (Mat_Mode == 0) {
          Mat_Mode = 1;
          // this is for the case where Mat_mode and Previous_Mat_mode are both zero
        }
      } else {
        Previous_Mat_Mode = Mat_Mode;
        Mat_Mode++;
      }

      Matrix_First_Time_Animation = true;
      Matrix_Animation_Frame = 0;
      Seven_Segment.setBrightness(Max_SevenSeg_Brightness);
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
      Beep();

      delay(100);

      Button_B_State = digitalRead (Button_B);

      if (Button_B_State == LOW) {
        Mat_Mode = Previous_Mat_Mode;
        Menu = true;
        Beep();
        delay(200);
      }
    }
  }
}
