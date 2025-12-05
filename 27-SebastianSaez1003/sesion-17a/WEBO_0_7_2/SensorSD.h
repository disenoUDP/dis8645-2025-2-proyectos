#ifndef SENSOR_SD_H
#define SENSOR_SD_H

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

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
  int intervaloAudio = 4000;

  int pinBusy = A4;  // BUSY pin

  unsigned long lastPlayTime = 0;

  int busy;
};

#endif
