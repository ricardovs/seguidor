#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int pinV, int pinP, int pinE )
	: _pinV(pinV), _pinE(pinE), _pinP(pinP)
{
	
}

void Motor::anda(int vD, int vE)
{
	return;
}
