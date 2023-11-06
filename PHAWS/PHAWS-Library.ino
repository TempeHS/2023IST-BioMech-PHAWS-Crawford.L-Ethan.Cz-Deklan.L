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
  void sound(uint8_t note_index)
  {
    for(int i=0;i<60;i++)
    {
        digitalWrite(SPEAKER,HIGH);
        delayMicroseconds(BassTab[1]);
        digitalWrite(SPEAKER,LOW);
        delayMicroseconds(BassTab[7]);
    }
  }
  }





  void SPKR () {
  
  
  void loop() {
        /*sound bass 1~7*/
    for(int note_index=0;note_index<7;note_index++)
    {
        sound(note_index);
        delay(0);
    }
  }

  