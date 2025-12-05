#ifndef ACTUADOR_N3P_H
#define ACTUADOR_N3P_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

class ActuadorN3P {
public:
  // constructor
  ActuadorN3P();


  void configurar();

  void emitirAlarma(int estadoActual);

  SoftwareSerial mp3Serial = SoftwareSerial(10, 11);
  DFRobotDFPlayerMini modulito;

int randomFile;
int tiempoActualAudio;
int tiempoNuevoE1;
int tiempoNuevoE2;
int tiempoNuevoE3;
int tiempoNuevoE4;

  // bool debug = false;

};

#endif
