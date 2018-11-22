#include "Motor.h"
#include "Arduino.h"

Motor::Motor(const int pinV, const int pinP,const int pinE )
	: _pinV(pinV), _pinE(pinE), _pinP(pinP)
{
	pinMode(_pinV, OUTPUT);
  pinMode(_pinP, OUTPUT);
  pinMode(_pinE, OUTPUT);
}

const void Motor::frente(int velocidade)
{
  digitalWrite(_pinP, HIGH);
  digitalWrite(_pinE, LOW);
  analogWrite(_pinV, velocidade);
  delay(50);  
}

const void Motor::atras(int velocidade){
  digitalWrite(_pinP, LOW);
  digitalWrite(_pinE, HIGH);
  analogWrite(_pinV, velocidade);
  delay(50);
}
    
const void Motor::freia(){
  digitalWrite(_pinP, HIGH);
  digitalWrite(_pinE, HIGH);  
}


const void Motor::anda(int velocidade)
{
	 if(velocidade >= 0) {
	    this->frente(velocidade);
	 }else{
	    this->atras(-velocidade); 
	 }
}
