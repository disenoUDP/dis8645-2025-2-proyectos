#ifndef SENSOR_SONIC_H
#define SENSOR_SONIC_H

// incluir biblliotecas
#include "Arduino.h"

// crear la clase
class SensorSonic {
public:
  SensorSonic();

  //crear los voids
  void configurarSonic();

  void funcionaSonic();

  float duracion;
  // sustancia = distancia
  float sustancia;

  int pinTrix = 8;
  //Pin Echo
  int pinEkeko = 9;
};

#endif