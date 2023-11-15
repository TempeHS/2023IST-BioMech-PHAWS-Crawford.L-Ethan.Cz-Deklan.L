static float no1 = 3;
static float no2 = 4;

void setup (){
    Serial.begin(9600);
    Serial.println("SM Working!");
    Serial.println("------------------------------------------");
    Serial.println(answer(no1, no2));
}

void loop (){
  while(Serial.available()) {
    float in1 = Serial.read();
    Serial.println(answer(no1, in1));
  }
}