#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor (int pin, int max) {
  pinMode(pin, INPUT);
  _pin = pin;
  _max = max;
  _value = 0;
}

Sensor::~Sensor () {

}

int Sensor::value() {
  return _value;
}

void Sensor::reload() {
  _value = analogRead(_pin);
}

bool Sensor::sreload() {
  this -> reload();
  return this -> state();
}

bool Sensor::state() {
  return (_value >= _max);
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
