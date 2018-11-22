#include "Sensor.h"
#include "Motor.h"
#include "Arduino.h"


char estado = 0;
Sensor s1(A1, 500); 
Sensor s2(A2, 400); 
Sensor s3(A3, 400); 
Sensor s4(A4, 500); 
Sensor s5(A5, 500); 

Motor m_d(5,7,6);

void setup() {
  // put your setup code here, to run once:
  //Sensores
    Serial.begin(9500);
}

void loop() {
  for(int i = -244; i < 244; i+=50){
    m_d.anda(i);
    Serial.println(i);
   
  }
  
  delay(800);
}
