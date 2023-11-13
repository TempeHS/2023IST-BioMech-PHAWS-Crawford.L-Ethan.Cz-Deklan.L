#define SPEAKER 3
int BassTab[]={1911,1702,1516,1431,1275,1136,1012};//bass 1~7
  boolean led_state = LOW;  
                          
static unsigned int LED = 6;
unsigned char counter;
unsigned long temp[21];
unsigned long sub;
bool data_effect = true;
unsigned int heart_rate; 

const int max_heartpluse_duty = 2000;  

void setup() {

  pinInit();
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Please ready your chest belt.");
  delay(5000);
  arrayInit();
  Serial.println("Heart rate test begin.");
  attachInterrupt(0, interrupt, RISING);
}


void loop() {



  digitalWrite(LED, led_state);


}