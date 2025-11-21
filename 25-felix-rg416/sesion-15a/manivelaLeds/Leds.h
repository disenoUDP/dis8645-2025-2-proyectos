#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

class Leds {
public:

  Leds();
  ~Leds();

#include <Arduino.h>
#include "Manivela.h"

  void configurar();
  void prepLuces();
  void actuarLuces();
  void finalLuces();

  int patitaLed1 = 1;
  int patitaLed2 = 2;
  int patitaLed3 = 3;
  int patitaLed4 = 4;
  int patitaLed5 = 5;

  // // ===============================
  // //       VARIABLES Y ESTADOS
  // // ===============================

  // // valor del Rango 1 - 5 que activa las funciones
  // extern int rango;

  // // función del encoder que alimenta la función anterior
  // extern int leerRango;

  // // ===============================
  // //       PINES DE LOS LEDS
  // // ===============================

  // extern const int led1;
  // extern const int led2;
  // extern const int led3;
  // extern const int led4;
  // extern const int led5;

  // // ===============================
  // //       FUNCIONES PRINCIPALES
  // // ===============================

  // void prepLuces();
  // void actuarLuces();
  // void finalLuces();
};
#endif