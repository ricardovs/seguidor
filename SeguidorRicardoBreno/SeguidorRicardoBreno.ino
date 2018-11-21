#define pS1 A1
#define pS2 A2
#define pS3 A3
#define pS4 A4
#define pS5 A5
#include "Sensor.h"

char estado = 0;
Sensor s1(A1, 55); 
void setup() {
  // put your setup code here, to run once:
  //Sensores
    Serial.begin(9500);
}

void loop() {
  // put your main code here, to run repeatedly:
  s1.sreload();
}
