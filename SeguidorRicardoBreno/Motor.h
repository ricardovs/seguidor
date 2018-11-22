#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor{
	private:
		const int _pinV;
		const int _pinE;
		const int _pinP;
	public:
		Motor(const int pinV,const int pinE,const int pinP );
		const void frente(int velocidade);
    const void atras(int velocidade);
    const void anda(int velocidade);
    const void freia();
};
#endif
