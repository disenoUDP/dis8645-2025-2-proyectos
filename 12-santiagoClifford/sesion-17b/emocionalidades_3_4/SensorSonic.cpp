// incluye el archivo.h
#include "SensorSonic.h"

// hacer que la clase claseee
SensorSonic::SensorSonic() {


}

//poner tus voids escrbiendo la clase antes, por buenos modales
// aqui ocurre el setup
void SensorSonic::configurarSonic() {
    // carinoPotencial = false;
  sustancia=999;
  valorSonic = 0;
  presionMinimaAceptable = 50;
  pinTrix = 8;
  //Pin Echo
  pinEkeko = 9;


  //int presionDolorosa = 230;
  pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);
  if (sustancia > 400 || sustancia <= 0) {
    sustancia = 400;
  }
}

// aqui ocurre el loop
void SensorSonic::funcionaSonic() {
  // carinoPotencial=false;
  digitalWrite(pinTrix, LOW);
  delayMicroseconds(2);
  //enviar un pulso ultrasonico

  digitalWrite(pinTrix, HIGH);
  delayMicroseconds(10);

  digitalWrite(pinTrix, LOW);

  duracion = pulseIn(pinEkeko, HIGH);

  sustancia = duracion / 58;
  Serial.print(duracion);
  Serial.println(sustancia);


  if (sustancia < 30 && sustancia > 0) {
    carinoPotencial = true;
  }
}
