void ClockLogic() {
  if (presentMillis - previousMillis_ClockLogic >= 1000) {
    DateTime now = rtc.now();
    year = now.year();
    month = now.month();
    day = now.day();
    dayOfTheWeek = now.dayOfTheWeek();

    hours = now.hour();
    minutes = now.minute();
    seconds = now.second();

    Clock_Time = hours * 100 + minutes;

    if (seconds == 0) {
      Next_Minute = true;
    }

    if (Clock_Time == Night_Time_Off && seconds == 0 && Sleep_Mode == false) {
      Previous_Mat_Mode = Mat_Mode;
      Mat_Mode = 0;
      Seven_Segment.setBrightness(0);
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
    }

    if (Clock_Time == Morning_Time_On && seconds == 0) {
      Mat_Mode = Previous_Mat_Mode;
      Matrix_First_Time_Animation = true;
      Seven_Segment.setBrightness(Max_SevenSeg_Brightness);
      Sleep_Mode = false;
      digitalWrite(LED_1, HIGH);
    }

    if (Clock_Time == 0 && seconds == 0) {
      for (int n = 0; n < No_of_SD; n++) {
        if (SD_Date[2 * n] == day && SD_Date[2 * n + 1] == month) {
          Spacial_Day = true;
          ID_of_SD_Triggered = n;
        }
      }
    }

    Seven_Segment.print(Clock_Time, DEC);

    if (hours == 0) {
      Seven_Segment.writeDigitNum(1, 0);  //this is so that it shows "0:XX" and not ":XX"
      if (minutes < 10) {
        Seven_Segment.writeDigitNum(3, 0);  //this is so that it shows "0:0X" and not "0: X"
      }
    }

    Seven_Segment.drawColon(LED_Colon);
    Seven_Segment.writeDisplay();

    LED_Colon = !LED_Colon;

    previousMillis_ClockLogic = presentMillis;
  }
}
