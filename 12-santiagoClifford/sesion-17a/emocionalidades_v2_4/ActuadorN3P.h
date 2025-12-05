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

  //void emitirAlarma(int estadoActual);

  void emitirAlarmaEstado1();

  SoftwareSerial mp3Serial = SoftwareSerial(10, 11);
  DFRobotDFPlayerMini modulito;

  int randomFile;
  int tiempoActualAudio=0;
  unsigned long tiempoNuevoEstado1 = millis();
  // int tiempoNuevoEstado2;
  // int tiempoNuevoEstado3;
  // int tiempoNuevoEstado4;
unsigned long intervaloAudio=10000;
bool audioReproduciendo= false;
  // bool debug = false;


};

#endif
