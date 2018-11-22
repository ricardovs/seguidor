#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"
// the #include statment and code go here...

class Sensor {
private:
  int _pin;
  int _max;
  int _value;
  int _lastvalue[5];
  char _plast=0;

  float meanlast();
  void setLast(int new_values);
  void addToLast(int value);
public:
  Sensor (int pin, int max);
  const int value();
  void reload();
  bool sreload();
  const bool state();
  void printValue();
  void printState();
  ~Sensor ();
};
#endif
