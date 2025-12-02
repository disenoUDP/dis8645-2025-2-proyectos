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
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int nivelLuz = 0;


};
//termina la definición de leds
#endif 