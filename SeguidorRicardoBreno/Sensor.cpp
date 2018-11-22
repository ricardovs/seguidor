#include "Arduino.h"
#include "Sensor.h"


Sensor::Sensor (int pin, int max){
    pinMode(pin, INPUT);
    _pin = pin;
    _max = max;
    _value = 0;
    for(int i= 0; i < 5; i++){
     _lastvalue[i] = 0;
    }
}


void Sensor::addToLast(int value){
  if(_plast < 5){
     _plast++; 
  }else{
    _plast=0;
  }
  _lastvalue[_plast] = value;
}


float Sensor::meanlast()
{
  float mean =0;
  for(int i= 0; i < 5; i++){
     mean += _lastvalue[i];
  }
  return (mean*0.2);
}

void Sensor::setLast(int value){
  for(int i= 0; i < 5; i++){
     _lastvalue[i] = value;
  }
}

Sensor::~Sensor () {

}


const int Sensor::value(){
  return _value;
}

void Sensor::reload() {
  this->addToLast(_value);
  _value = analogRead(_pin);
}

bool Sensor::sreload() {
  this -> reload();
  return this -> state();
}


const bool Sensor::state(){
  return (_value >= this->meanlast());
}

void Sensor::printValue() {
  Serial.print(_pin);
  Serial.print("Sensor ");
  Serial.print(_pin);
  Serial.print(" = ");
  Serial.println(this -> _value);
  Serial.println();
}

void Sensor::printState() {
  Serial.print(_pin);
  Serial.print("Sensor ");
  Serial.print(_pin);
  Serial.print(" = ");
  Serial.println(state());
  Serial.println();
}
