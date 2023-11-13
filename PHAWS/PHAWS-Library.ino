void GSR() {
  const int GSR = A0;
  int sensorValue = 0;
  int gsr_average = 0;

  long sum = 0;
  for (int i = 0; i < 10; i++) /* Average the 10 measurements to remove the glitch */
  {
    sensorValue = analogRead(GSR);
    sum += sensorValue;
    delay(5);
  }
  gsr_average = sum / 10;
  Serial.println(gsr_average);
}



void pinInit() {
    pinMode(SPEAKER,OUTPUT);
    digitalWrite(SPEAKER,LOW);
}



void sound(uint8_t note_index) {
    for(int i=0;i<60;i++)
    {
        digitalWrite(SPEAKER,HIGH);
        delayMicroseconds(BassTab[1]);
        digitalWrite(SPEAKER,LOW);
        delayMicroseconds(BassTab[7]);
    }
}



void SPKR () {
    for(int note_index=0;note_index<7;note_index++)
    {
        sound(note_index);
        delay(0);
    }
}



void sum() {
  if (data_effect) {
    heart_rate = 1200000 / (temp[20] - temp[0]);
    Serial.print("Heart_rate_is:\t");
    Serial.println(heart_rate);
  }
  data_effect = 1;
}

void interrupt() {
  temp[counter] = millis();
  Serial.println(counter, DEC);
  Serial.println(temp[counter]);
  switch (counter) {
    case 0:
      sub = temp[counter] - temp[20];
      Serial.println(sub);
      break;
    default:
      sub = temp[counter] - temp[counter - 1];
      Serial.println(sub);
      break;
  }
  if (sub > max_heartpluse_duty)
  {
    data_effect = 0;
    counter = 0;
    Serial.println("Heart rate measure error,test will restart!");
    arrayInit();
  }
  if (counter == 20 && data_effect) {
    counter = 0;
    sum();
  } else if (counter != 20 && data_effect)
    counter++;
  else {
    counter = 0;
    data_effect = 1;
  }
}

void arrayInit() {
  for (unsigned char i = 0; i < 20; i++) {
    temp[i] = 0;
  }
  temp[20] = millis();
}