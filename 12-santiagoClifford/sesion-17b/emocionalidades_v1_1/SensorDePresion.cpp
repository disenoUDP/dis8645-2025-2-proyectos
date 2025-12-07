//Yiop
// incluye el archivo.h
#include "SensorDePresion.h"

// hacer que la clase claseee
SensorDePresion::SensorDePresion(){}


void SensorDePresion::configurarDePresion(){

const int pinDePresion = A0;
int valorDePresion = 0;
bool hayBrazo;
int presionMinimaAceptable = 50;
//int presionDolorosa = 230;
 pinMode(pinDePresion, INPUT);

}

// aqui ocurre el loop
void SensorDePresion::funcionaDePresion(){

  //asignar el valor del pin del sensor de presion, a la variable valorDePresion
  valorDePresion = analogRead(pinDePresion);
  //si valorDePresion es mayor a presionMinimaAceptable, hayBrazo es true
  hayBrazo = (valorDePresion > presionMinimaAceptable);


}