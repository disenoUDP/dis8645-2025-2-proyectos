#ifndef AUDIO_H
#define AUDIO_H

#include <Arduino.h>

#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

class Audio {
public:

  //constructor
  Audio();

  // funciones
  void preparar(bool modo);
  void actualizar(int rangoEncoder);
  void reproducirAudioPorfase();

  // variable para controlar modo de prueba
  bool emitirSerial;

  // constantes para conexiones
  const int patitaRX = 0;
  const int patitaTX = 1;

  // variables
  bool reproducirAudio = false;
  bool vueltaEncoder = true;
  int fase = 0;
  int faseAnterior = 0;
};
#endif