#ifndef VIBRADOR_H
#define VIBRADOR_H

#include "Arduino.h"

class Vibrador {
public:
  // constructor
  Vibrador();

  void preparar();
  void usar();
  void velocidadVibrador(int pausaHIGH, int pausaLOW);

  // variable para conexion
  const int patitaVibrador = 12;

  // unsigned hace que el numero vaya desde 0
  // long significa que tiene mas resolucion que un int
  // variable para almacenar tiempo en ms
  unsigned long momentoPasado = 0;

  // variable para definir estado
  bool estado = HIGH;

  // TODO: cambiamos el valor el encoder
  int intervalo = 0;
};
#endif