#include "Sensor.h"
#include "Motor.h"
#include "Arduino.h"


int estado = -1;
Sensor s1(A1, 500); 
Sensor s2(A2, 400); 
Sensor s3(A3, 400); 
Sensor s4(A4, 500); 
Sensor s5(A5, 500); 

Motor m_d(5,6,7);
Motor m_e(10,8,9);

const int ve0[] = {50, 250};
const int ve1[] = {150, 200};
const int ve2[] = {255, 255};
const int ve3[] = {250, 255};
const int ve4[] = {200, 150};
const int ve5[] = {250, 50};
const int veO[] = {250, 10};

void printEstado()
{
   Serial.print("\n");
   Serial.print("S1 \t");
   Serial.print(s1.state());
   Serial.print("\n");
   Serial.print("S2 \t");
   Serial.print(s2.state());
   Serial.print("\n");
   Serial.print("S3 \t");
   Serial.print(s3.state());
   Serial.print("\n");
   Serial.print("S4 \t");
   Serial.print(s4.state());
   Serial.print("\n");
   Serial.print("S5 \t");
   Serial.print(s5.state());
   Serial.print("\n\n");
   Serial.print("Estado;  \t");
   Serial.print(estado);
   Serial.print("---------------------------\n");
   
}

void andar(const int v[])
{
 	m_d.frente(v[0]);
 	m_e.frente(v[1]); 
}

 
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9500);
}

void loop() {
  switch(estado)
  {
    case 0:
      do{
        andar(ve0);  
      }while(!s1.sreload());
      printEstado(); 
      estado = 1;
      break;
    
    case 1:
    	do{
        	andar(ve1);  
      	}while( !(s1.sreload()  || s2.sreload()) ); 
      	if(s2.state())
      	{
      		estado = 2;
      	}
      	else
      	{
      		estado = 0;
      	}
        printEstado(); 

      break;
     
     case 2:
    	do{
        	andar(ve2);  
      	}while( !(s2.sreload()  || s3.sreload()) ); 
      	if(s3.state())
      	{
      		estado = 3;
      	}
      	else
      	{
      		estado = 1;
      	}
      	printEstado();
      break;
      
      case 3:
    	do{
        	andar(ve3);  
      	}while( !(s3.sreload()  || s4.sreload()) ); 
      	if(s3.state())
      	{
      		estado = 2;
      	}
      	else
      	{
      		estado = 4;
      	}
      	printEstado();
      break;
      
      case 4:
    	do{
        	andar(ve4);  
      	}while( !(s4.sreload()  || s5.sreload()) ); 
      	if(s4.state())
      	{
      		estado = 3;
      	}
      	else
      	{
      		estado = 5;
      	}
      	printEstado();
      break;
      
      case 5:
    	do{
        	andar(ve5);  
      	}while( !(s5.sreload()) ); 
      	estado = 4;
      	printEstado();
      break;
      
     default:
     	do{
     		andar(veO);
     	}while(!( s1.sreload() || s2.sreload() || s3.sreload() || s4.sreload() || s5.sreload() ));
 		if(s5.state()){
 			estado = 4;
 		}else if(s1.state()){
 			estado = 1;
 		}else if(s3.state()){
 			estado = 3;
 		}else if(s2.state()){ 
 			estado = 2;
 		}else{
 			estado = 4;
 		}
 		printEstado();   	
      break;
  }     
}
