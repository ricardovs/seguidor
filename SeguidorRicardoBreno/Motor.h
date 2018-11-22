#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor{
	private:
		const int _pinV;
		const int _pinE;
		const int _pinP;
	public:
		Motor(int pinV, int pinE, int pinP );
		void anda(int vD, int vE);
};
#endif
