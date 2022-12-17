void Setting_Menu() {
  switch (Menu_Mode) {
    case 0:  //Setting Clock
      Matrix_SetClock();

      if (Button_A_State == LOW) {
        //temp
        Beep();
        delay(100);

        Button_A_State = digitalRead (Button_A);

        if (Button_A_State == LOW) {
          Clock_Set = true;
          Menu = false;
          Beep();
          delay(200);
        }
      }
      break;
    case 1:  //Setting Alarm
      if (Alarm_Disable == false) {
        Matrix_SetAlarm_ADF();
      } else {
        Matrix_SetAlarm_ADT();
      }

      if (Button_A_State == LOW) {
        Alarm_Disable = !Alarm_Disable;
        Beep();
        delay(100);

        Button_A_State = digitalRead (Button_A);

        if (Button_A_State == LOW) {
          Alarm_Disable = !Alarm_Disable;
          Alarm_Set = true;
          Menu = false;
          Beep();
          delay(200);
        }
      }
      break;
    case 2:  //General Setting
      Matrix_GeneralSetting();

      if (Button_A_State == LOW) {
        //temp
        Beep();
        delay(100);

        Button_A_State = digitalRead (Button_A);

        if (Button_A_State == LOW) {
          Gen_Set = true;
          Menu = false;
          Beep();
          delay(200);
        }
      }
      break;
    default:
      Menu_Mode = 0;
      break;
  }

  if (Button_B_State == LOW) {
    Menu_Mode++;
    Beep();

    delay(100);

    Button_B_State = digitalRead (Button_B);

    if (Button_B_State == LOW) {
      Menu_Mode = 0;
      Menu = false;

      EEPROM.update(Alarm_Disable_Address, Alarm_Disable);

      Beep();
      delay(200);
    }
  }
}

void General_Setting() {
  switch (Gen_Set_Mode) {
    case 0:  //Max_SevenSeg_Brightness
      Matrix_Max_SevenSeg_Brightness();

      Seven_Segment.setBrightness(Max_SevenSeg_Brightness);
      Seven_Segment.writeDigitNum(0, 8, bitRead(byte(Max_SevenSeg_Brightness), 3));
      Seven_Segment.writeDigitNum(1, 8, bitRead(byte(Max_SevenSeg_Brightness), 2));
      Seven_Segment.drawColon(true);
      Seven_Segment.writeDigitNum(3, 8, bitRead(byte(Max_SevenSeg_Brightness), 1));
      Seven_Segment.writeDigitNum(4, 8, bitRead(byte(Max_SevenSeg_Brightness), 0));
      Seven_Segment.writeDisplay();

      if (Button_A_State == LOW) {
        Max_SevenSeg_Brightness++;
        if (Max_SevenSeg_Brightness > 15) {
          Max_SevenSeg_Brightness = 0;
        }
        Beep();
        delay(100);
      }
      break;
    case 1:  //Disable/Enable Buzzer
      Matrix_Buzzer_Enable();

      if (Buzzer_Enable == LOW) {
        Seven_Segment.writeDigitRaw(0, B00111111);
        Seven_Segment.writeDigitRaw(1, B01110001);
        Seven_Segment.writeDigitRaw(3, B01110001);
        Seven_Segment.writeDigitRaw(4, B00000000);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      } else {
        Seven_Segment.writeDigitRaw(0, B00111111);
        Seven_Segment.writeDigitRaw(1, B00110111);
        Seven_Segment.writeDigitRaw(3, B00000000);
        Seven_Segment.writeDigitRaw(4, B00000000);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      }

      if (Button_A_State == LOW) {
        Buzzer_Enable = !Buzzer_Enable;
        Beep();
        delay(100);
      }
      break;
    case 2:  //Alarm_Duration
      Matrix_Alarm_Duration();

      Seven_Segment.print(Alarm_Duration, DEC);
      Seven_Segment.drawColon(false);
      Seven_Segment.writeDisplay();

      if (Button_A_State == LOW) {
        Alarm_Duration++;
        if (Alarm_Duration > 5) {
          Alarm_Duration = 1;
        }
        Beep();
        delay(100);
      }
      break;
    case 3:  //Snooze_Duration
      Matrix_Snooze_Duration();

      Seven_Segment.print(Snooze_Duration, DEC);
      Seven_Segment.drawColon(false);
      Seven_Segment.writeDisplay();

      if (Button_A_State == LOW) {
        Snooze_Duration++;
        if (Snooze_Duration > 5) {
          Snooze_Duration = 1;
        }
        Beep();
        delay(100);
      }
      break;
    case 4:  //Alarm_Sound
      Matrix_Alarm_Sound();

      Seven_Segment.print(Alarm_Sound + 1, DEC);
      Seven_Segment.drawColon(false);
      Seven_Segment.writeDisplay();

      if (Button_A_State == LOW) {
        Alarm_Sound++;
        Beep();
        delay(100);

        Button_A_State = digitalRead (Button_A);

        if (Button_A_State == LOW) {
          Alarm_Sound--;
          Alarm = true;

          Beep();
          delay(200);
        }

        if (Alarm_Sound > 1) {  //1 is number of Alarm_Sound indexed 0
          Alarm_Sound = 0;
        }
      }
      Snooze = false;  //this is to ensure alarm demo isnt snoozed
      break;
    case 5:  //Night_Time_Off
      Matrix_Night_Time_Off();

      Seven_Segment.print(Night_Time_Off, DEC);
      Seven_Segment.drawColon(true);

      if (Night_Time_Off / 100 == 0) {
        Seven_Segment.writeDigitNum(1, 0);  //this is so that it shows "0:XX" and not ":XX"
        if (Night_Time_Off % 100 < 10) {
          Seven_Segment.writeDigitNum(3, 0);  //this is so that it shows "0:0X" and not "0: X"
        }
      }

      Seven_Segment.writeDisplay();

      if (Button_A_State == LOW) {
        Night_Time_Off = Night_Time_Off + 100;
        if (Night_Time_Off / 100 > 23) {
          Night_Time_Off = Night_Time_Off % 100;
        }

        Beep();

        delay(100);

        Button_A_State = digitalRead (Button_A);

        if (Button_A_State == LOW) {
          if (Night_Time_Off / 100 == 0) {
            Night_Time_Off = 2300 + Night_Time_Off;
          } else {
            Night_Time_Off = Night_Time_Off - 100;
          }

          Night_Time_Off = Night_Time_Off + 5;
          if (Night_Time_Off % 100 > 59) {
            Night_Time_Off = Night_Time_Off - Night_Time_Off % 100;
          }

          Beep();
          delay(200);
        }
      }
      break;
    case 6:  //Morning_Time_On
      Matrix_Morning_Time_On();

      Seven_Segment.print(Morning_Time_On, DEC);
      Seven_Segment.drawColon(true);

      if (Morning_Time_On / 100 == 0) {
        Seven_Segment.writeDigitNum(1, 0);  //this is so that it shows "0:XX" and not ":XX"
        if (Morning_Time_On % 100 < 10) {
          Seven_Segment.writeDigitNum(3, 0);  //this is so that it shows "0:0X" and not "0: X"
        }
      }

      Seven_Segment.writeDisplay();

      if (Button_A_State == LOW) {
        Morning_Time_On = Morning_Time_On + 100;
        if (Morning_Time_On / 100 > 23) {
          Morning_Time_On = Morning_Time_On % 100;
        }

        Beep();

        delay(100);

        Button_A_State = digitalRead (Button_A);

        if (Button_A_State == LOW) {
          if (Morning_Time_On / 100 == 0) {
            Morning_Time_On = 2300 + Morning_Time_On;
          } else {
            Morning_Time_On = Morning_Time_On - 100;
          }

          Morning_Time_On = Morning_Time_On + 5;
          if (Morning_Time_On % 100 > 59) {
            Morning_Time_On = Morning_Time_On - Morning_Time_On % 100;
          }

          Beep();
          delay(200);
        }
      }
      break;
    case 7: //Version
      Matrix_Version_Info();

      Seven_Segment.print(Version, DEC);
      Seven_Segment.writeDigitNum(1, (Version / 100) % 10, true);
      Seven_Segment.drawColon(false);
      Seven_Segment.writeDisplay();
      break;
    default:
      Gen_Set_Mode = 0;
      break;
  }

  if (Button_B_State == LOW) {
    Gen_Set_Mode++;
    Beep();

    delay(100);

    Button_B_State = digitalRead (Button_B);

    if (Button_B_State == LOW) {
      Gen_Set_Mode = 0;
      Gen_Set = false;
      Menu = true;

      EEPROM.update(Max_SevenSeg_Brightness_Address, Max_SevenSeg_Brightness);
      EEPROM.update(Buzzer_Enable_Address, Buzzer_Enable);
      EEPROM.update(Alarm_Duration_Address, Alarm_Duration);
      EEPROM.update(Snooze_Duration_Address, Snooze_Duration);
      EEPROM.update(Alarm_Sound_Address, Alarm_Sound);
      EEPROM.update(Night_Time_Off_Address_hr, Night_Time_Off / 100);
      EEPROM.update(Night_Time_Off_Address_min, Night_Time_Off % 100);
      EEPROM.update(Morning_Time_On_Address_hr, Morning_Time_On / 100);
      EEPROM.update(Morning_Time_On_Address_min, Morning_Time_On % 100);

      Beep();
      delay(200);
    }
  }
}
