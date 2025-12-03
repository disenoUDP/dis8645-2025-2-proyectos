// incluye el archivo.h
#include "Ultrasonico.h"

// hacer que la clase claseee
Ultrasonico::Ultrasonico(){}
//YIOP
//pponer tus voids escrbiendo la clase antes, por buenos modales
// aqui ocurre el setup
void Ultrasonico::configurarSonico(){

pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);
    if (sustancia > 400 || sustancia <= 0) {
    sustancia = 400;
  }
}

// aqui ocurre el loop
void Ultrasonico::funcionaSonico(){
   digitalWrite(pinTrix, LOW);
  delayMicroseconds(2);
  //enviar un pulso ultrasonico
  digitalWrite(pinTrix, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrix, LOW);
 
}