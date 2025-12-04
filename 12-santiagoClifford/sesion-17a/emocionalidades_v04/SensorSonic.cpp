// incluye el archivo.h
#include "SensorSonic.h"

// hacer que la clase claseee
SensorSonic::SensorSonic() {}

 //poner tus voids escrbiendo la clase antes, por buenos modales
 // aqui ocurre el setup
void SensorSonic::configurarSonic() {

  const int pinSonic = A0;
  int valorSonic = 0;
  bool hayBrazo;
  int presionMinimaAceptable = 50;

  //int presionDolorosa = 230;
  pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);
  if (sustancia > 400 || sustancia <= 0) {
    sustancia = 400;
  }}

  // aqui ocurre el loop
  void SensorSonic::funcionaSonic() {
    digitalWrite(pinTrix, LOW);
    delayMicroseconds(2);
    //enviar un pulso ultrasonico
    digitalWrite(pinTrix, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrix, LOW);
  }