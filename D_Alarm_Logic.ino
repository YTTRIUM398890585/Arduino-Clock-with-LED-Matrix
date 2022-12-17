void Alarm_Logic() {
  if (Snooze == true && presentMillis - Alarm_Millis >= Snooze_Duration * 60000) {  //Alarm will trigger again after Snooze_Duration (in min)
    Alarm = true;
    Alarm_Millis = presentMillis;
    previousMillis_AlarmNoise = presentMillis;
  }

  for (int n = 0; n < No_of_Alarm; n++) {
    if (Alarm_Time_Array[n] == Clock_Time && Alarm_State_Array[n] == true && Next_Minute == true && Alarm_Disable == false) {
      Next_Minute = false;
      Alarm = true;
      Alarm_Millis = presentMillis;
      previousMillis_AlarmNoise = presentMillis;
    }
  }
}

void Alarm_Noise() {
  switch (Alarm_Sound) {
    case 0:
      Alarm_Sound_0();
      break;
    case 1:
      Alarm_Sound_1();
      break;
//    case 2:
//      Alarm_Sound_2();
//      break;
    default:
      Alarm_Sound = 0;  //In case of bug
      break;
  }
}

void Alarm_Sound_0() {
  if (presentMillis - previousMillis_AlarmNoise >= 100) {
    digitalWrite(Buzzer, Buzzer_Alarm);

    if (Buzzer_Alarm) {
      Matrix_All_On();
      digitalWrite(LED_2, HIGH);
    } else {
      Mat_MAX72XX.clear();
      digitalWrite(LED_2, LOW);
    }

    Buzzer_Alarm = !Buzzer_Alarm;

    previousMillis_AlarmNoise = presentMillis;
  }
}

void Alarm_Sound_1() {
  if (presentMillis - previousMillis_AlarmNoise < 100) {
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LED_2, HIGH);
    Matrix_All_On();
  } else if (presentMillis - previousMillis_AlarmNoise < 130) {
    digitalWrite(Buzzer, LOW);
    digitalWrite(LED_2, LOW);
    Mat_MAX72XX.clear();
  } else if (presentMillis - previousMillis_AlarmNoise < 230) {
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LED_2, HIGH);
    Matrix_All_On();
  } else if (presentMillis - previousMillis_AlarmNoise < 260) {
    digitalWrite(Buzzer, LOW);
    digitalWrite(LED_2, LOW);
    Mat_MAX72XX.clear();
  } else if (presentMillis - previousMillis_AlarmNoise < 360) {
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LED_2, HIGH);
    Matrix_All_On();
  } else if (presentMillis - previousMillis_AlarmNoise < 390) {
    digitalWrite(Buzzer, LOW);
    digitalWrite(LED_2, LOW);
    Mat_MAX72XX.clear();
  } else if (presentMillis - previousMillis_AlarmNoise < 490) {
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LED_2, HIGH);
    Matrix_All_On();
  } else if (presentMillis - previousMillis_AlarmNoise >= 1000) {
    previousMillis_AlarmNoise = presentMillis;
  } else {
    digitalWrite(Buzzer, LOW);
    digitalWrite(LED_2, LOW);
    Mat_MAX72XX.clear();
  }
}

//void Alarm_Sound_2() {
//  if (presentMillis - previousMillis_AlarmNoise >= 10) {
//    analogWrite(Buzzer, Buzzer_PWM);
//    Buzzer_PWM++;
//    previousMillis_AlarmNoise = presentMillis;
//  }
//}
