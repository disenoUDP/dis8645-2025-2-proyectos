// incluye el archivo.h
#include "SensorDePresion.h"

// hacer que la clase claseee
SensorDePresion::SensorDePresion() {}


void SensorDePresion::configurarDePresion() {

  pinDePresion = A0;
  valorDePresion = 0;
  watitaRascada=false;
  presionMinimaAceptable = 50;
  pinMode(SensorDePresion::pinDePresion, INPUT);
}

void SensorDePresion::funcionaDePresion() {
  //asignar el valor del pin del sensor de presion, a la variable valorDePresion
  SensorDePresion::valorDePresion = analogRead(SensorDePresion::pinDePresion);
  //si valorDePresion es mayor a presionMinimaAceptable, hayBrazo es true
  if (SensorDePresion::valorDePresion > SensorDePresion::presionMinimaAceptable) {
    watitaRascada= true;
  }
}