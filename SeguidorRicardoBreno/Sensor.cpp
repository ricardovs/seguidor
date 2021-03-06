#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor (int pin, int max){
    pinMode(pin, OUTPUT);
    _pin = pin;
    _max = max;
    _value = 0;
}

Sensor::~Sensor (){

}

int Sensor::value(){
  return _value;
}

void Sensor::reload(){
  _value = analogRead(_pin);
}

bool Sensor::sreload(){
  this -> reload();
  return this -> state();
}

bool Sensor::state(){
  return (_value >= _max);
}
