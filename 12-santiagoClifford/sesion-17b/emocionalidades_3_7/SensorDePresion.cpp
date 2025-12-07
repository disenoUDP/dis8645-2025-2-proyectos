// incluye el archivo.h
#include "SensorDePresion.h"

// hacer que la clase claseee
SensorDePresion::SensorDePresion() {}


void SensorDePresion::configurarDePresion() {

  pinDePresion = A0;
  valorDePresion = 0;
  watitaRascada;
  //hay q calibrar la presion/revisar cableado
  presionMinimaAceptable = 8;
  pinMode(SensorDePresion::pinDePresion, INPUT);
}

void SensorDePresion::funcionaDePresion() {
  //asignar el valor del pin del sensor de presion, a la variable valorDePresion
  SensorDePresion::valorDePresion = analogRead(SensorDePresion::pinDePresion);
  //si valorDePresion es mayor a presionMinimaAceptable, hayBrazo es true
  if (SensorDePresion::valorDePresion > SensorDePresion::presionMinimaAceptable) {
    //recibiendo abrazo
    watitaRascada = true;
  } else {
    //si no vuelve a false, llama a ese estaod todo el rato
    watitaRascada = false;
  }
}