//base de funcionamiento para clases
#ifndef AUDIO_H
#define AUDIO_H
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

//declara una vez la clase Audio
class Audio {
  public:
//declara la existencia de la clase Audio
  Audio();
//declara los voids que hacen funcionar los componentes en el principal
void prepararAudio();
void usarAudio();
void reproducirAudioPorfase();

//SoftwareSerial mySoftwareSerial(2, 3); // RX = 2, TX = 3
int RX = 2;
int TX = 3;
DFRobotDFPlayerMini myDFPlayer;

// Variables originales
bool reproducirAudio = false;
bool vueltaEncoder = true;
int fase = 0;

};
//termina la definición de Audio
#endif 