void SetAlarmLogic() {
  Seven_Segment.drawColon(true);

  if (Alarm_Time_Set == true) {
    SetAlarmTimeLogic (Alarm_No, Alarm_Time_Array[Alarm_No], Alarm_State_Array[Alarm_No]);
  } else {
    Alarm_Setting (Alarm_No, Alarm_Time_Array[Alarm_No], Alarm_State_Array[Alarm_No]);

    if (Button_B_State == LOW) {
      Alarm_No = Alarm_No + 1;

      if (Alarm_No >= No_of_Alarm) {
        Alarm_No = 0;
      }

      Beep();
      delay(100);

      Button_B_State = digitalRead (Button_B);

      if (Button_B_State == LOW) {
        Alarm_No = 0;
        Alarm_Set = false;

        Menu = true;

        for (int n = 0; n < No_of_Alarm; n++) {
          EEPROM.update(3 * n + 2, Alarm_State_Array[n]);
        }
        
        Beep();
        delay(200);
      }
    }
  }
}

void SetAlarmTimeLogic (uint8_t Alarm_No, uint16_t &Alarm_Time, bool Alarm_State) {
  uint8_t Alarm_Hours = Alarm_Time / 100;
  uint8_t Alarm_Minutes = Alarm_Time % 100;

  if (Button_A_State == LOW) {
    SetAlarmTime_Mode = SetAlarmTime_Mode + 1;
    Beep();
    delay(100);
  }

  switch (SetAlarmTime_Mode) {
    case 0:
      SetAlarmTimeLogic_Minute(Alarm_Minutes, Alarm_Hours);
      break;
    case 1:
      SetAlarmTimeLogic_Hour(Alarm_Minutes, Alarm_Hours);
      break;
    case 2:
      SetAlarmTimeLogic_Confirm(Alarm_No, Alarm_Minutes, Alarm_Hours);
      break;
    default:
      SetAlarmTime_Mode = 0;
      break;
  }

  Alarm_Time = Alarm_Hours * 100 + Alarm_Minutes;
}

void SetAlarmTimeLogic_Minute (uint8_t &Alarm_Minutes, uint8_t &Alarm_Hours) {
  decimalpointoffall(Alarm_Minutes, Alarm_Hours);

  Seven_Segment.writeDigitNum(3, (Alarm_Minutes / 10), decimalpoint);
  Seven_Segment.writeDigitNum(4, (Alarm_Minutes % 10), decimalpoint);

  digitalWrite(LED_2, decimalpoint);

  decimalpoint = !decimalpoint;

  if (Button_B_State == LOW) {
    Alarm_Minutes = Alarm_Minutes + 1;

    if (Alarm_Minutes > 59) {
      Alarm_Minutes = 0;
    }

    Beep();
  }

  Seven_Segment.writeDisplay();

  delay(100);
}

void SetAlarmTimeLogic_Hour (uint8_t &Alarm_Minutes, uint8_t &Alarm_Hours) {
  decimalpointoffall(Alarm_Minutes, Alarm_Hours);

  Seven_Segment.writeDigitNum(0, (Alarm_Hours / 10), decimalpoint);
  Seven_Segment.writeDigitNum(1, (Alarm_Hours % 10), decimalpoint);

  digitalWrite(LED_2, decimalpoint);

  decimalpoint = !decimalpoint;

  if (Button_B_State == LOW) {
    Alarm_Hours = Alarm_Hours + 1;

    if (Alarm_Hours > 23) {
      Alarm_Hours = 0;
    }

    Beep();
  }

  Seven_Segment.writeDisplay();

  delay(100);
}

void SetAlarmTimeLogic_Confirm(uint8_t Alarm_No, uint8_t &Alarm_Minutes, uint8_t &Alarm_Hours) {
  decimalpointoffall(Alarm_Minutes, Alarm_Hours);
  Seven_Segment.writeDigitNum(0, (Alarm_Hours / 10), decimalpoint);
  Seven_Segment.writeDigitNum(1, (Alarm_Hours % 10), decimalpoint);
  Seven_Segment.writeDigitNum(3, (Alarm_Minutes / 10), decimalpoint);
  Seven_Segment.writeDigitNum(4, (Alarm_Minutes % 10), decimalpoint);

  digitalWrite(LED_2, decimalpoint);

  decimalpoint = !decimalpoint;

  if (Button_B_State == LOW) {
    Alarm_Time_Set = false;
    SetAlarmTime_Mode = 0;

    EEPROM.update(3 * Alarm_No    , Alarm_Hours);
    EEPROM.update(3 * Alarm_No + 1, Alarm_Minutes);

    digitalWrite(LED_2, LOW);

    Beep();
    delay(50);
    Beep();
    delay(50);
    Beep();
    delay(50);

    decimalrunright(Alarm_Minutes, Alarm_Hours);
  }

  Seven_Segment.writeDisplay();

  delay(100);
}

void Alarm_Setting (uint8_t Alarm_No, uint16_t Alarm_Time, bool &Alarm_State) {
  //"&" in "bool &Alarm_State" needed for it to update Alarm_State_X
  //https://forum.arduino.cc/t/get-a-function-to-update-a-passed-variable/44598/5

  byte Alarm_No_BIN = byte(Alarm_No);
  bool Alarm_No_0 = bitRead(Alarm_No_BIN, 0);
  bool Alarm_No_1 = bitRead(Alarm_No_BIN, 1);
  bool Alarm_No_2 = bitRead(Alarm_No_BIN, 2);
  bool Alarm_No_3 = bitRead(Alarm_No_BIN, 3);

  Seven_Segment.writeDigitNum(0, (Alarm_Time / 1000)             , Alarm_No_3);
  Seven_Segment.writeDigitNum(1, (Alarm_Time % 1000) / 100       , Alarm_No_2);
  Seven_Segment.writeDigitNum(3, ((Alarm_Time % 1000) % 100) / 10, Alarm_No_1);
  Seven_Segment.writeDigitNum(4, ((Alarm_Time % 1000) % 100) % 10, Alarm_No_0);

  Seven_Segment.writeDisplay();

  if (Alarm_State == true) {
    Matrix_Alarm_ON();
  } else {
    Matrix_Alarm_OFF();
  }

  if (Button_A_State == LOW) {
    Alarm_State = !Alarm_State;
    Beep();
    delay(100);

    Button_A_State = digitalRead (Button_A);

    if (Button_A_State == LOW) {
      Alarm_State = !Alarm_State;
      Alarm_Time_Set = true;
      Beep();
      delay(200);
    }
  }
}
