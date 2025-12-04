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
  analogWrite(able, 100);
  //prender direccion1, apagar direccion2
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(5000);
  //apagar ambas direcciones
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
 
}