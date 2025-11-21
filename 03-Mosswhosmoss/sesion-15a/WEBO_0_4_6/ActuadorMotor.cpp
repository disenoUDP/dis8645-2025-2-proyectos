#include "ActuadorMotor.h"

ActuadorMotor::ActuadorMotor() {}

void ActuadorMotor::configuracionMotor(){
//establecer que el pin que va a mandar una señal
  // será el que fue declarado antes
  pinMode(motorPin, OUTPUT);
}

void ActuadorMotor::funcionaMotor(){
// manda una señal de encendido
  digitalWrite(motorPin, HIGH);  
  // cada 2 segundos
  delay(500);                   

  //apaga la señal
  digitalWrite(motorPin, LOW);  
  // cada 2 segundos 
  delay(1000);   

}