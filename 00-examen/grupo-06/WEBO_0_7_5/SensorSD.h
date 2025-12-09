#ifndef SENSOR_SD_H
#define SENSOR_SD_H

#include "DFRobotDFPlayerMini.h"
#include "TimersMillis.h"

// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
class SensorSD {
public:
  SensorSD();

  void configuracionSD();
  void funcionaSDAlarmaFuerte();
  void funcionaSDAlarmaDebil();
  void leerBusyPin();

  int tiempoNuevoAudioDebil = 0;
  int tiempoActualAudio = 0;
  int tiempoNuevoAudioFuerte = 0;

  int pinBusy = A4;  // BUSY pin

  int busy;
};

#endif
