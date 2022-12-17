void SetClockLogic() {
  Seven_Segment.drawColon(true);
  Matrix_SetClock();

  if (Button_A_State == LOW) {
    Clock_Set_Mode = Clock_Set_Mode + 1;
    Beep();
    delay(100);
  }

  switch (Clock_Set_Mode) {
    case 0:
      SetClockLogic_Minute();
      break;
    case 1:
      SetClockLogic_Hour();
      break;
    case 2:
      SetClockLogic_Confirm();
      break;
    default:
      Clock_Set_Mode = 0;
      break;
  }
}

void SetClockLogic_Minute() {
  decimalpointoffall(minutes, hours);

  Seven_Segment.writeDigitNum(3, (minutes / 10), decimalpoint);
  Seven_Segment.writeDigitNum(4, (minutes % 10), decimalpoint);

  digitalWrite(LED_2, decimalpoint);

  decimalpoint = !decimalpoint;

  if (Button_B_State == LOW) {
    minutes = minutes + 1;

    if (minutes > 59) {
      minutes = 0;
    }

    Beep();
  }

  Seven_Segment.writeDisplay();

  delay(100);
}

void SetClockLogic_Hour() {
  decimalpointoffall(minutes, hours);

  Seven_Segment.writeDigitNum(0, (hours / 10), decimalpoint);
  Seven_Segment.writeDigitNum(1, (hours % 10), decimalpoint);

  digitalWrite(LED_2, decimalpoint);

  decimalpoint = !decimalpoint;

  if (Button_B_State == LOW) {
    hours = hours + 1;

    if (hours > 23) {
      hours = 0;
    }

    Beep();
  }

  Seven_Segment.writeDisplay();

  delay(100);
}

void SetClockLogic_Confirm() {
  decimalpointoffall(minutes, hours);
  Seven_Segment.writeDigitNum(0, (hours / 10), decimalpoint);
  Seven_Segment.writeDigitNum(1, (hours % 10), decimalpoint);
  Seven_Segment.writeDigitNum(3, (minutes / 10), decimalpoint);
  Seven_Segment.writeDigitNum(4, (minutes % 10), decimalpoint);

  digitalWrite(LED_2, decimalpoint);

  decimalpoint = !decimalpoint;

  if (Button_B_State == LOW) {
    seconds = 0;
    rtc.adjust(DateTime(year, month, day, hours, minutes, seconds));

    Clock_Set = false;
    Clock_Set_Mode = 0;

    Menu = true;

    digitalWrite(LED_2, LOW);

    Beep();
    delay(50);
    Beep();
    delay(50);
    Beep();
    delay(50);

    decimalrunright(minutes, hours);
  }

  Seven_Segment.writeDisplay();

  delay(100);
}
