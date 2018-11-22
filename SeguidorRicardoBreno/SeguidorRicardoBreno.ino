#include "Sensor.h"
#include "Arduino.h"


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
  //mudei alguma coisa
}
