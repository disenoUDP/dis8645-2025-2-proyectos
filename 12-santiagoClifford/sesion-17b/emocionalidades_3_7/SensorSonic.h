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

  long duracion;
  // sustancia = distancia
  float sustancia;
int valorSonic;
  int pinTrix;
  //Pin Echo
  int pinEkeko;
  int presionMinimaAceptable;

  bool carinoPotencial;
};

#endif