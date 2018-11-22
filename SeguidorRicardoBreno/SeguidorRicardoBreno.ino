#include "Sensor.h"

char estado = 0;
Sensor s1(A1, 500); 
Sensor s2(A2, 500); 
Sensor s3(A3, 500); 
Sensor s4(A4, 500); 
Sensor s5(A5, 500); 

void setup() {
  // put your setup code here, to run once:
  //Sensores
    Serial.begin(9500);
}

void loop() {
  //Recarrega todos os sensores e imprime seus valores na tela
  Serial.println("-----------------");
  s1.reload();
  s1.printValue();

  s2.reload();
  s2.printValue();
  
  s3.reload();
  s3.printValue();
  
  s4.reload();
  s4.printValue();
  
  s5.reload();
  s5.printValue();
  
  delay(800);
}
