//base de funcionamiento para clases
#ifndef HUMO_H
#define HUMO_H

#include <Arduino.h>

class Humo {
public:
  // constructor
  Humo();
  
  void preparar();
  void usar();

  int humo = 13;
  int punto = 0;
  bool tiraHumo = false;
};
#endif