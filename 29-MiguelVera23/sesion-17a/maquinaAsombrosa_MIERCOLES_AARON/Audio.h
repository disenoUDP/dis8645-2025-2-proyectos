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
  // tipo void, no retornan nada
  void preparar();
  // void usar();
  void reproducirAudioPorfase();

  int RX = 0;
  int TX = 1;

  // Variables originales
  bool reproducirAudio = false;
  bool vueltaEncoder = true;
  int fase = 0;
};
#endif