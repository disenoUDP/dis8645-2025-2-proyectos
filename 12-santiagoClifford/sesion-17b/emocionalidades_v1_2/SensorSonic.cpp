// incluye el archivo.h
#include "SensorSonic.h"

// hacer que la clase claseee
SensorSonic::SensorSonic() {}

 //poner tus voids escrbiendo la clase antes, por buenos modales
 // aqui ocurre el setup
void SensorSonic::configurarSonic() {

  int valorSonic = 0;
  bool hayBrazo;
  int presionMinimaAceptable = 50;
    pinTrix = 8;
  //Pin Echo
   pinEkeko = 9;

  //int presionDolorosa = 230;
  pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);
  if (sustancia > 400 || sustancia <= 0) {
    sustancia = 400;
  }}

  // aqui ocurre el loop
  void SensorSonic::funcionaSonic() {
    digitalWrite(SensorSonic::pinTrix, LOW);
    delayMicroseconds(2);
    //enviar un pulso ultrasonico

    digitalWrite(SensorSonic::pinTrix, HIGH);
    delayMicroseconds(10);

    digitalWrite(SensorSonic::pinTrix, LOW);

    duracion = pulseIn(pinEkeko, HIGH);

    SensorSonic::sustancia = duracion/58;

    if (SensorSonic::sustancia<30){
      carinoPotencial=true;
    }
  }