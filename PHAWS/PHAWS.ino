#define SPEAKER 3
#include "LSM6DS3.h"
#include "Wire.h"
int gsr = A0;
int sensorValue = 0;
int gsr_average = 0;
LSM6DS3 myIMU(I2C_MODE, 0x6A);
int BassTab[]={1911,1702,1516,1431,1275,1136,1012};
boolean led_state = LOW;                         
static unsigned int LED = 6;
unsigned char counter;
unsigned long temp[21];
unsigned long sub;
bool data_effect = true;
unsigned int heart_rate = 0; 
const int max_heartpluse_duty = 2000;


void setup() {

  pinInit();
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  delay(5000);
  arrayInit();
  attachInterrupt(0, interrupt, RISING);
  while (!Serial);
    if (myIMU.begin() != 0) {
        Serial.println("Accelerometer error");
    } else {
        Serial.println("Accelerometer working");
    }
}



void loop() {



  digitalWrite(LED, led_state);
  Accel();

}