#ifndef LEDS_H
#define LEDS_H

#include "Arduino.h"
class Leds {
public:
  // constructor
  Leds();

  void preparar(bool modo);
  void actualizar(int rangoEncoder);
  void usar();

  // variable para controlar modo de prueba
  bool emitirSerial;

  // Entradas de los leds
  int led1 = 4;
  int led2 = 5;
  int led3 = 6;
  int led4 = 7;
  int led5 = 8;
  int nivelLuz = 0;
  //unsigned long momentoPasadoLED = 0;
  //bool estadoLED = false; // falso = patrón 1, verdadero = patrón 2
};
//termina la definición de leds
#endif