void Matrix_SetClock() {
  animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 1, 1, 1, 0, 0, 0,
                  0, 1, 0, 1, 0, 1, 0, 0,
                  1, 0, 0, 1, 0, 0, 1, 0,
                  1, 0, 0, 1, 1, 0, 1, 0,
                  1, 0, 0, 0, 0, 0, 1, 0,
                  0, 1, 0, 0, 0, 1, 0, 0,
                  0, 0, 1, 1, 1, 0, 0, 0);
}

void Matrix_SetAlarm_ADF() {
  if (presentMillis - previousMillis_Matrix_Animation >= 200) {
    Matrix_Animation_Frame++;
    previousMillis_Matrix_Animation = presentMillis;
  }

  switch (Matrix_Animation_Frame) {
    case 0:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 1, 1, 0, 0, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 0, 1, 0, 0, 0, 0);
      break;
    case 1:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 1, 1, 0, 0, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 0, 1, 0, 0, 0, 0);
      break;
    case 2:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 1, 1, 0, 0, 0,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      1, 0, 1, 0, 0, 1, 0, 1,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 0, 0, 1, 0, 0, 0);
      break;
    case 3:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                      0, 1, 0, 1, 1, 0, 1, 0,
                      1, 0, 1, 0, 0, 1, 0, 1,
                      1, 0, 1, 0, 0, 1, 0, 1,
                      1, 0, 1, 0, 0, 1, 0, 1,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 0, 0, 1, 0, 0, 0);
      break;
    default:
      Matrix_Animation_Frame = 0;
      break;
  }
}

void Matrix_SetAlarm_ADT() {
  animation_frame(1, 0, 0, 0, 0, 0, 0, 0,
                  0, 1, 0, 1, 1, 0, 0, 0,
                  0, 0, 1, 0, 0, 1, 0, 0,
                  0, 0, 1, 1, 0, 1, 0, 0,
                  0, 0, 1, 0, 1, 1, 0, 0,
                  0, 0, 1, 0, 0, 1, 0, 0,
                  0, 1, 1, 1, 1, 1, 1, 0,
                  0, 0, 0, 0, 0, 0, 0, 1);
}

void Matrix_GeneralSetting() {
  if (presentMillis - previousMillis_Matrix_Animation >= 500) {
    Matrix_Animation_Frame++;
    previousMillis_Matrix_Animation = presentMillis;
  }

  switch (Matrix_Animation_Frame) {
    case 0:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 1, 0, 1, 0, 0, 0,
                      0, 0, 1, 1, 1, 1, 1, 0,
                      0, 1, 1, 0, 0, 1, 0, 0,
                      0, 0, 1, 0, 0, 1, 1, 0,
                      0, 1, 1, 1, 1, 1, 0, 0,
                      0, 0, 0, 1, 0, 1, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0);
      break;
    case 1:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 1, 0, 1, 0, 0,
                      0, 1, 1, 1, 1, 1, 0, 0,
                      0, 0, 1, 0, 0, 1, 1, 0,
                      0, 1, 1, 0, 0, 1, 0, 0,
                      0, 0, 1, 1, 1, 1, 1, 0,
                      0, 0, 1, 0, 1, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0);
      break;
    default:
      Matrix_Animation_Frame = 0;
      break;
  }
}

void Matrix_Max_SevenSeg_Brightness() {
  if (Max_SevenSeg_Brightness < 5) {
    animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 1, 1, 0, 0, 0,
                    0, 0, 1, 0, 0, 1, 0, 0,
                    0, 0, 1, 0, 0, 1, 0, 0,
                    0, 0, 0, 1, 1, 0, 0, 0,
                    0, 0, 0, 1, 1, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0);
  }
  else if (Max_SevenSeg_Brightness > 9) {
    animation_frame(1, 0, 0, 0, 0, 0, 0, 1,
                    0, 1, 0, 0, 0, 0, 1, 0,
                    0, 0, 0, 1, 1, 0, 0, 0,
                    0, 0, 1, 0, 0, 1, 0, 0,
                    0, 0, 1, 0, 0, 1, 0, 0,
                    0, 0, 0, 1, 1, 0, 0, 0,
                    0, 1, 0, 1, 1, 0, 1, 0,
                    1, 0, 0, 0, 0, 0, 0, 1);
  }
  else {
    animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                    0, 1, 0, 0, 0, 0, 1, 0,
                    0, 0, 0, 1, 1, 0, 0, 0,
                    0, 0, 1, 0, 0, 1, 0, 0,
                    0, 0, 1, 0, 0, 1, 0, 0,
                    0, 0, 0, 1, 1, 0, 0, 0,
                    0, 1, 0, 1, 1, 0, 1, 0,
                    0, 0, 0, 0, 0, 0, 0, 0);
  }
}

void Matrix_Buzzer_Enable() {
  if (Buzzer_Enable == true) {
    animation_frame(0, 0, 0, 0, 1, 0, 0, 0,
                    0, 0, 0, 1, 1, 0, 1, 0,
                    1, 1, 1, 0, 1, 0, 0, 1,
                    1, 0, 1, 0, 1, 1, 0, 1,
                    1, 0, 1, 0, 1, 1, 0, 1,
                    1, 1, 1, 0, 1, 0, 0, 1,
                    0, 0, 0, 1, 1, 0, 1, 0,
                    0, 0, 0, 0, 1, 0, 0, 0);
  } else {
    animation_frame(1, 0, 0, 0, 1, 0, 0, 0,
                    0, 1, 0, 1, 1, 0, 0, 0,
                    1, 1, 1, 0, 1, 0, 0, 0,
                    1, 0, 1, 1, 1, 0, 0, 0,
                    1, 0, 1, 0, 1, 0, 0, 0,
                    1, 1, 1, 0, 1, 1, 0, 0,
                    0, 0, 0, 1, 1, 0, 1, 0,
                    0, 0, 0, 0, 1, 0, 0, 1);
  }
}

void Matrix_Alarm_Duration() {
  animation_frame(0, 1, 0, 1, 0, 0, 0, 0,
                  1, 0, 1, 1, 0, 0, 0, 0,
                  1, 1, 1, 1, 0, 0, 0, 0,
                  1, 0, 1, 1, 1, 1, 0, 0,
                  1, 1, 0, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 1, 0, 0, 1, 0, 0, 0);
}

void Matrix_Snooze_Duration() {
  animation_frame(0, 1, 0, 1, 0, 0, 1, 0,
                  1, 0, 1, 0, 1, 1, 0, 1,
                  0, 1, 1, 0, 1, 1, 0, 1,
                  1, 0, 1, 0, 1, 0, 1, 0,
                  1, 1, 0, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 1, 0, 0, 1, 0, 0, 0);
}

void Matrix_Alarm_Sound() {
  animation_frame(0, 1, 0, 1, 0, 0, 0, 0,
                  1, 0, 1, 1, 0, 0, 0, 0,
                  1, 1, 1, 1, 0, 0, 0, 0,
                  1, 0, 1, 1, 1, 1, 0, 0,
                  0, 1, 0, 1, 0, 1, 1, 0,
                  1, 0, 1, 0, 1, 1, 0, 1,
                  0, 1, 1, 0, 1, 1, 0, 1,
                  1, 0, 1, 0, 1, 1, 1, 0);
}

void Matrix_Night_Time_Off() {
  animation_frame(0, 1, 0, 1, 1, 1, 0, 0,
                  1, 0, 1, 0, 1, 0, 0, 0,
                  1, 0, 1, 0, 1, 0, 0, 0,
                  1, 0, 1, 0, 1, 0, 0, 0,
                  0, 1, 0, 1, 1, 1, 1, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 1, 1, 1, 0,
                  0, 1, 0, 1, 0, 1, 0, 0);
}

void Matrix_Morning_Time_On() {
  animation_frame(0, 1, 0, 1, 0, 1, 1, 1,
                  1, 0, 1, 0, 1, 0, 1, 0,
                  1, 0, 1, 0, 1, 0, 1, 0,
                  1, 0, 0, 0, 1, 0, 1, 0,
                  0, 1, 0, 0, 1, 0, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  0, 1, 0, 1, 0, 1, 0, 0);
}

void Matrix_Alarm_ON() {
  animation_frame(0, 1, 0, 0, 1, 0, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  0, 1, 0, 1, 0, 1, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0);
}

void Matrix_Alarm_OFF() {
  animation_frame(0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 1, 0, 1, 1, 1, 1, 0,
                  1, 0, 1, 1, 0, 1, 0, 0,
                  1, 0, 1, 1, 1, 1, 1, 0,
                  0, 1, 0, 1, 0, 1, 0, 0);
}

void Matrix_Super_Computer() {
  digitalWrite(LED_2, HIGH);

  if (presentMillis - previousMillis_Matrix_Animation >= random(40, 60)) {
    for (int i = 0; i < 32; i++) {
      Mat_MAX72XX.setPoint(random(0, 8), random(0, 8), random(0, 2));
    }
    previousMillis_Matrix_Animation = presentMillis;
  }
}

void Conways_Game_of_Life() {
  static bool GOL_array_preprevious[8][8];  //2D array, [row][col]
  static bool GOL_array_previous[8][8];
  static bool GOL_array_current[8][8];
  static uint16_t no_of_generations = 0;
  static uint16_t Highest_Score = ((uint16_t)EEPROM.read(Highest_Score_8_15_Address) << 8) | EEPROM.read(Highest_Score_0_7_Address);

  //Initial Seed
  if (Matrix_First_Time_Animation == true) {
    Mat_MAX72XX.clear();
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        GOL_array_preprevious[8][8] = 0;
        GOL_array_previous[r][c] = 0;
        GOL_array_current[r][c] = 0;
      }
    }
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        GOL_array_current[r][c] = random(0, 2);
        Mat_MAX72XX.setPoint(c, r, GOL_array_current[r][c]);
      }
    }

    no_of_generations = 0;
    Matrix_First_Time_Animation = false;
    previousMillis_Matrix_Animation = presentMillis;
  }

  //Increment
  if (presentMillis - previousMillis_Matrix_Animation >= 1000) {
    //Check for all dead so restart
    int total_alive = 0;
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (GOL_array_current[r][c] == true) {
          total_alive++;
        }
      }
    }

    //Check for Still_Lifes
    bool Still_Lifes = true;
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (GOL_array_current[r][c] != GOL_array_previous[r][c]) {
          Still_Lifes = false;
        }
      }
    }

    //Check for oscillation of period 2
    bool Osc_Period_2 = true;
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (GOL_array_current[r][c] != GOL_array_preprevious[r][c]) {
          Osc_Period_2 = false;
        }
      }
    }

    if (total_alive == 0) {  //all dead so restart
      animation_frame(1, 0, 1, 0, 0, 1, 0, 1,
                      0, 1, 0, 0, 0, 0, 1, 0,
                      1, 0, 1, 0, 0, 1, 0, 1,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      1, 1, 1, 1, 1, 1, 1, 1,
                      0, 0, 0, 0, 1, 0, 0, 1,
                      0, 0, 0, 0, 1, 0, 0, 1,
                      0, 0, 0, 0, 0, 1, 1, 0);
      if (no_of_generations > 9999) {
        Seven_Segment.writeDigitRaw(0, B01000000);
        Seven_Segment.writeDigitRaw(1, B01000000);
        Seven_Segment.writeDigitRaw(3, B01000000);
        Seven_Segment.writeDigitRaw(4, B01000000);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      } else {
        Seven_Segment.print(no_of_generations, DEC);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      }
      digitalWrite(LED_2, HIGH);
      delay(1000);
      if (no_of_generations > Highest_Score) {
        Highest_Score = no_of_generations;
        EEPROM.update(Highest_Score_0_7_Address, ((uint8_t) (Highest_Score & 0b11111111)));
        EEPROM.update(Highest_Score_8_15_Address, ((uint8_t) ((Highest_Score >> 8) & 0b11111111)));
      }
      if (Highest_Score > 9999) {
        Seven_Segment.writeDigitRaw(0, B01000000);
        Seven_Segment.writeDigitRaw(1, B01000000);
        Seven_Segment.writeDigitRaw(3, B01000000);
        Seven_Segment.writeDigitRaw(4, B01000000);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      } else {
        Seven_Segment.print(Highest_Score, DEC);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      }
      delay(1000);
      digitalWrite(LED_2, LOW);
      Matrix_First_Time_Animation = true;
    } else if (Still_Lifes == true) {
      if (no_of_generations > 9999) {
        Seven_Segment.writeDigitRaw(0, B01000000);
        Seven_Segment.writeDigitRaw(1, B01000000);
        Seven_Segment.writeDigitRaw(3, B01000000);
        Seven_Segment.writeDigitRaw(4, B01000000);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      } else {
        Seven_Segment.print(no_of_generations, DEC);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      }
      digitalWrite(LED_2, HIGH);
      delay(2000);
      digitalWrite(LED_2, LOW);
      Matrix_First_Time_Animation = true;
    } else if (Osc_Period_2 == true) {  //Filter out oscillation of period 2
      if (no_of_generations - 1 > 9999) {  //-1 to compensate for the osc, so that its displaying the gen that first started the osc
        Seven_Segment.writeDigitRaw(0, B01000000);
        Seven_Segment.writeDigitRaw(1, B01000000);
        Seven_Segment.writeDigitRaw(3, B01000000);
        Seven_Segment.writeDigitRaw(4, B01000000);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      } else {
        Seven_Segment.print(no_of_generations - 1, DEC);
        Seven_Segment.drawColon(false);
        Seven_Segment.writeDisplay();
      }
      digitalWrite(LED_2, HIGH);
      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
          Mat_MAX72XX.setPoint(c, r, GOL_array_previous[r][c]);
        }
      }
      delay(1000);
      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
          Mat_MAX72XX.setPoint(c, r, GOL_array_current[r][c]);
        }
      }
      delay(1000);
      digitalWrite(LED_2, LOW);
      Matrix_First_Time_Animation = true;
    } else {  //Next generation
      no_of_generations++;
      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
          GOL_array_preprevious[r][c] = GOL_array_previous[r][c];
          GOL_array_previous[r][c] = GOL_array_current[r][c];
        }
      }

      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
          int no_of_life = 0;

          for (int row = r - 1; row <= r + 1; row++) {
            for (int col = c - 1; col <= c + 1; col++) {
              if ((row == r && col == c) || (row < 0) || (row > 7) || (col < 0) || (col > 7)) {
                //skips current iteration for not applicable states
                continue;
              }
              if (GOL_array_previous[row][col] == true) {
                no_of_life++;
              }
            }
          }

          if (no_of_life == 2) {
            //No change: Dead->Dead, Alive->Alive
          } else if (no_of_life == 3) {
            //Dead->Alive, Alive->Alive
            GOL_array_current[r][c] = true;
          } else {
            //Dead->Dead, Alive->Dead
            GOL_array_current[r][c] = false;
          }
        }
      }

      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
          Mat_MAX72XX.setPoint(c, r, GOL_array_current[r][c]);
        }
      }
    }
    previousMillis_Matrix_Animation = presentMillis;
  }
}

void Matrix_Random_Off() {
  if (presentMillis - previousMillis_Matrix_Animation >= 30) {
    for (int i = 0; i < 20; i++) {
      Mat_MAX72XX.setPoint(random(0, 8), random(0, 8), LOW);
    }
    previousMillis_Matrix_Animation = presentMillis;
  }
}

void Matrix_All_On() {
  animation_frame(1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1);
}

void Matrix_Version_Info() {
  animation_frame(0, 0, 0, 1, 1, 0, 0, 0,
                  0, 0, 0, 1, 1, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 1, 1, 1, 0, 0, 0,
                  0, 0, 0, 1, 1, 0, 0, 0,
                  0, 0, 0, 1, 1, 0, 0, 0,
                  0, 0, 0, 1, 1, 0, 0, 0,
                  0, 0, 1, 1, 1, 1, 0, 0);
}

void Matrix_Day_And_Date() {
  if (Matrix_First_Time_Animation == true) {
    Mat_MAX72XX.clear();

    for (int i = 7; i > 4; i--) {
      Mat_MAX72XX.setPoint(i, 0, HIGH);
      Mat_MAX72XX.setPoint(i, 2, HIGH);
      Mat_MAX72XX.setPoint(i, 4, HIGH);
      Mat_MAX72XX.setPoint(i, 6, HIGH);
      Mat_MAX72XX.setPoint(i, 7, HIGH);
      delay(60);
    }

    Mat_MAX72XX.setPoint(4, 2, HIGH);
    Mat_MAX72XX.setPoint(4, 4, HIGH);
    Mat_MAX72XX.setPoint(4, 6, HIGH);
    Mat_MAX72XX.setPoint(4, 7, HIGH);
    delay(60);

    Mat_MAX72XX.setPoint(3, 2, HIGH);
    delay(60);

    Matrix_First_Time_Animation = false;
  }

  uint8_t dayOfTheWeek_0to6 = dayOfTheWeek;

  if (dayOfTheWeek_0to6 == 0) {
    dayOfTheWeek_0to6 = 7;
  }

  bool dayOfTheWeek_BIN_0 = bitRead(dayOfTheWeek_0to6, 0);
  bool dayOfTheWeek_BIN_1 = bitRead(dayOfTheWeek_0to6, 1);
  bool dayOfTheWeek_BIN_2 = bitRead(dayOfTheWeek_0to6, 2);

  bool Day_0 = bitRead(day, 0);
  bool Day_1 = bitRead(day, 1);
  bool Day_2 = bitRead(day, 2);
  bool Day_3 = bitRead(day, 3);
  bool Day_4 = bitRead(day, 4);

  bool Month_0 = bitRead(month, 0);
  bool Month_1 = bitRead(month, 1);
  bool Month_2 = bitRead(month, 2);
  bool Month_3 = bitRead(month, 3);

  uint8_t Year_BIN_3rd_Dig = ((year % 100) / 10);
  bool Year_BIN_3rd_Dig_0 = bitRead(Year_BIN_3rd_Dig, 0);
  bool Year_BIN_3rd_Dig_1 = bitRead(Year_BIN_3rd_Dig, 1);
  bool Year_BIN_3rd_Dig_2 = bitRead(Year_BIN_3rd_Dig, 2);
  bool Year_BIN_3rd_Dig_3 = bitRead(Year_BIN_3rd_Dig, 3);

  uint8_t Year_BIN_4th_Dig = (year % 10);
  bool Year_BIN_4th_Dig_0 = bitRead(Year_BIN_4th_Dig, 0);
  bool Year_BIN_4th_Dig_1 = bitRead(Year_BIN_4th_Dig, 1);
  bool Year_BIN_4th_Dig_2 = bitRead(Year_BIN_4th_Dig, 2);
  bool Year_BIN_4th_Dig_3 = bitRead(Year_BIN_4th_Dig, 3);

  digitalWrite(LED_2, HIGH);

  animation_frame(0, 0, 0,     0,                  0, dayOfTheWeek_BIN_2, dayOfTheWeek_BIN_1, dayOfTheWeek_BIN_0,   //Day of the week
                  0, 0, 0,     0,                  0,                  0,                  0,                  0,
                  0, 0, 0, Day_4,              Day_3,              Day_2,              Day_1,              Day_0,   //Date
                  0, 0, 0,     0,                  0,                  0,                  0,                  0,
                  0, 0, 0,     0,            Month_3,            Month_2,            Month_1,            Month_0,   //Month
                  0, 0, 0,     0,                  0,                  0,                  0,                  0,
                  0, 0, 0,     0, Year_BIN_3rd_Dig_3, Year_BIN_3rd_Dig_2, Year_BIN_3rd_Dig_1, Year_BIN_3rd_Dig_0,   //Year
                  0, 0, 0,     0, Year_BIN_4th_Dig_3, Year_BIN_4th_Dig_2, Year_BIN_4th_Dig_1, Year_BIN_4th_Dig_0);  //Year
}

void Matrix_Hours_Minutes_Seconds_CentiSeconds() {
  if (Matrix_First_Time_Animation == true) {
    Mat_MAX72XX.clear();

    for (int i = 7; i > 2; i--) {
      Mat_MAX72XX.setPoint(i, 1, HIGH);
      Mat_MAX72XX.setPoint(i, 3, HIGH);
      Mat_MAX72XX.setPoint(i, 5, HIGH);
      Mat_MAX72XX.setPoint(i, 7, HIGH);
      delay(60);
    }

    Mat_MAX72XX.setPoint(2, 3, HIGH);
    Mat_MAX72XX.setPoint(2, 5, HIGH);
    Mat_MAX72XX.setPoint(2, 7, HIGH);
    delay(60);

    Mat_MAX72XX.setPoint(1, 7, HIGH);
    delay(60);

    Matrix_First_Time_Animation = false;
  }

  bool Hours_0 = bitRead(hours, 0);
  bool Hours_1 = bitRead(hours, 1);
  bool Hours_2 = bitRead(hours, 2);
  bool Hours_3 = bitRead(hours, 3);
  bool Hours_4 = bitRead(hours, 4);

  bool Minutes_0 = bitRead(minutes, 0);
  bool Minutes_1 = bitRead(minutes, 1);
  bool Minutes_2 = bitRead(minutes, 2);
  bool Minutes_3 = bitRead(minutes, 3);
  bool Minutes_4 = bitRead(minutes, 4);
  bool Minutes_5 = bitRead(minutes, 5);

  bool Seconds_0 = bitRead(seconds, 0);
  bool Seconds_1 = bitRead(seconds, 1);
  bool Seconds_2 = bitRead(seconds, 2);
  bool Seconds_3 = bitRead(seconds, 3);
  bool Seconds_4 = bitRead(seconds, 4);
  bool Seconds_5 = bitRead(seconds, 5);

  uint8_t CentiSeconds = ((presentMillis - previousMillis_ClockLogic) / 10);
  bool CentiSeconds_0 = bitRead(CentiSeconds, 0);
  bool CentiSeconds_1 = bitRead(CentiSeconds, 1);
  bool CentiSeconds_2 = bitRead(CentiSeconds, 2);
  bool CentiSeconds_3 = bitRead(CentiSeconds, 3);
  bool CentiSeconds_4 = bitRead(CentiSeconds, 4);
  bool CentiSeconds_5 = bitRead(CentiSeconds, 5);
  bool CentiSeconds_6 = bitRead(CentiSeconds, 6);

  analogWrite(LED_2, map(CentiSeconds, 0, 100, 0, 255));

  animation_frame(0,              0,              0,              0,              0,              0,              0,              0,
                  0,              0,              0,        Hours_4,        Hours_3,        Hours_2,        Hours_1,        Hours_0,   //Hours
                  0,              0,              0,              0,              0,              0,              0,              0,
                  0,              0,      Minutes_5,      Minutes_4,      Minutes_3,      Minutes_2,      Minutes_1,      Minutes_0,   //Minutes
                  0,              0,              0,              0,              0,              0,              0,              0,
                  0,              0,      Seconds_5,      Seconds_4,      Seconds_3,      Seconds_2,      Seconds_1,      Seconds_0,   //Seconds
                  0,              0,              0,              0,              0,              0,              0,              0,
                  0, CentiSeconds_6, CentiSeconds_5, CentiSeconds_4, CentiSeconds_3, CentiSeconds_2, CentiSeconds_1, CentiSeconds_0);  //CentiSeconds
}

void animation_frame (bool AA, bool BA, bool CA, bool DA, bool EA, bool FA, bool GA, bool HA,
                      bool AB, bool BB, bool CB, bool DB, bool EB, bool FB, bool GB, bool HB,
                      bool AC, bool BC, bool CC, bool DC, bool EC, bool FC, bool GC, bool HC,
                      bool AD, bool BD, bool CD, bool DD, bool ED, bool FD, bool GD, bool HD,
                      bool AE, bool BE, bool CE, bool DE, bool EE, bool FE, bool GE, bool HE,
                      bool AF, bool BF, bool CF, bool DF, bool EF, bool FF, bool GF, bool HF,
                      bool AG, bool BG, bool CG, bool DG, bool EG, bool FG, bool GG, bool HG,
                      bool AH, bool BH, bool CH, bool DH, bool EH, bool FH, bool GH, bool HH)
{
  bool input_to_array[] = {AA, BA, CA, DA, EA, FA, GA, HA,
                           AB, BB, CB, DB, EB, FB, GB, HB,
                           AC, BC, CC, DC, EC, FC, GC, HC,
                           AD, BD, CD, DD, ED, FD, GD, HD,
                           AE, BE, CE, DE, EE, FE, GE, HE,
                           AF, BF, CF, DF, EF, FF, GF, HF,
                           AG, BG, CG, DG, EG, FG, GG, HG,
                           AH, BH, CH, DH, EH, FH, GH, HH
                          };

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      Mat_MAX72XX.setPoint(c, r, input_to_array[c + 8 * r]);
    }
  }
}
