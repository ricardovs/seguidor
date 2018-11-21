#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"
// the #include statment and code go here...

class Sensor {
private:
  int _pin;
  int _max;
  int _value;

public:
  Sensor (int pin, int max);
  int value();
  void reload();
  bool ereload();
  bool state();
  virtual ~Sensor ();
};
#endif
