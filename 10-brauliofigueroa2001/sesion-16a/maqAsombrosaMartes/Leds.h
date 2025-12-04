//base de funcionamiento para clases
#ifndef LEDS_H
#define LEDS_H
#include "Arduino.h"
//declara una vez la clase Leds
class Leds {
  public:
//declara la existencia de la clase leds
  Leds();
//declara los voids que hacen funcionar los componentes en el principal
void prepararLeds();
  void usarLeds();

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