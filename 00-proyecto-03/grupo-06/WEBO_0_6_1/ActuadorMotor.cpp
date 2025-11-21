#include "ActuadorMotor.h"

ActuadorMotor::ActuadorMotor() {}

void ActuadorMotor::configuracionMotor(){
//establecer que el pin que va a mandar una señal
  // sera el que fue declarado antes
  pinMode(motorPin, OUTPUT);
}

void ActuadorMotor::funcionaMotor(){
// manda una señal de encendido al pin establecido previamente
  digitalWrite(motorPin, HIGH);  
  // cada medio segundo
  delay(500);                   

  //apaga la señal del pin establecido previamente
  digitalWrite(motorPin, LOW);  
  // cada medio segundo 
  delay(500);   

}