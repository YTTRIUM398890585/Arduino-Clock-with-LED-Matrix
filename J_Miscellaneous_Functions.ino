void Beep() {
  digitalWrite(Buzzer, Buzzer_Enable);
  delay(100);
  digitalWrite(Buzzer, LOW);
}

void Initial_Sequence() {
  delay(500);
  Seven_Segment.drawColon(false);
  Seven_Segment.writeDigitRaw(0, B00000001);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(0, B00000000);
  Seven_Segment.writeDigitRaw(1, B00000001);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(1, B00000000);
  Seven_Segment.writeDigitRaw(3, B00000001);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(3, B00000000);
  Seven_Segment.writeDigitRaw(4, B00000001);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(4, B00000010);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(4, B00000100);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(4, B00001000);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(4, B00000000);
  Seven_Segment.writeDigitRaw(3, B00001000);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(3, B00000000);
  Seven_Segment.writeDigitRaw(1, B00001000);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(1, B00000000);
  Seven_Segment.writeDigitRaw(0, B00001000);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(0, B00010000);
  Seven_Segment.writeDisplay();
  delay(50);
  Seven_Segment.writeDigitRaw(0, B00100000);
  Seven_Segment.writeDisplay();
  delay(50);

  Beep();
}

void decimalpointoffall (uint8_t Minutes, uint8_t Hours) {
  Seven_Segment.writeDigitNum(0, (Hours / 10), false);
  Seven_Segment.writeDigitNum(1, (Hours % 10), false);
  Seven_Segment.writeDigitNum(3, (Minutes / 10), false);
  Seven_Segment.writeDigitNum(4, (Minutes % 10), false);

  Seven_Segment.writeDisplay();
}

void decimalrunright (uint8_t Minutes, uint8_t Hours) {
  decimalpointoffall(Minutes, Hours);

  Seven_Segment.writeDigitNum(0, (Hours / 10), true);
  Seven_Segment.writeDisplay();
  delay(100);
  Seven_Segment.writeDigitNum(1, (Hours % 10), true);
  Seven_Segment.writeDisplay();
  delay(100);
  Seven_Segment.writeDigitNum(3, (Minutes / 10), true);
  Seven_Segment.writeDisplay();
  delay(100);
  Seven_Segment.writeDigitNum(4, (Minutes % 10), true);
  Seven_Segment.writeDisplay();
  delay(200);

  Seven_Segment.writeDigitNum(0, (Hours / 10), false);
  Seven_Segment.writeDisplay();
  delay(100);
  Seven_Segment.writeDigitNum(1, (Hours % 10), false);
  Seven_Segment.writeDisplay();
  delay(100);
  Seven_Segment.writeDigitNum(3, (Minutes / 10), false);
  Seven_Segment.writeDisplay();
  delay(100);
  Seven_Segment.writeDigitNum(4, (Minutes % 10), false);
  Seven_Segment.writeDisplay();
  delay(100);
}
