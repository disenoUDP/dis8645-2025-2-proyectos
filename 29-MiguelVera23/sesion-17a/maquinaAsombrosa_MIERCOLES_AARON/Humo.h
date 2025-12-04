//base de funcionamiento para clases
#ifndef HUMO_H
#define HUMO_H

#include <Arduino.h>

class Humo {
public:
  // constructor
  Humo();

  void preparar(bool modo);
  void actualizar(int rangoEncoder);
  void usar();

  // variable para controlar modo de prueba
  bool emitirSerial;

  int humo = 13;
  int punto = 0;
  bool tiraHumo = false;
};
#endif