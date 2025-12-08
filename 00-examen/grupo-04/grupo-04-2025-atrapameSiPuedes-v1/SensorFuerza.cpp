#include "SensorFuerza.h"
// incluye el .h de SensorFuerza

SensorFuerza::SensorFuerza() {} //constructor

SensorFuerza::~SensorFuerza() {} // destructor

void SensorFuerza::configurar(int nuevaPatita) { // aqui se configura el sensor
  SensorFuerza::patita = nuevaPatita;
  pinMode(SensorFuerza::patita, INPUT);  // pin donde se encuentra el sensor
}

void SensorFuerza::leer() {   // funcion para leer el sensor
  SensorFuerza::valorCrudo = analogRead(SensorFuerza::patita);  // guarda el valor de la presion del sensor
                                                                // y cada vez que se llama .leer, se actualiza el valor
}