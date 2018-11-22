#include "Sensor.h"

char estado = 0;
Sensor s1(A1, 500); 
Sensor s2(A2, 400); 
Sensor s3(A3, 400); 
Sensor s4(A4, 500); 
Sensor s5(A5, 500); 

void setup() {
  // put your setup code here, to run once:
  //Sensores
    Serial.begin(9500);
}

void loop() {
  //Recarrega todos os sensores e imprime seus status na tela
  Serial.println("-----------------");
  s1.reload();
  s1.printState();

  s2.reload();
  s2.printState();
  
  s3.reload();
  s3.printState();
  
  s4.reload();
  s4.printState();
  
  s5.reload();
  s5.printState();
  
  delay(800);
}
