//base de funcionamiento para clases
#ifndef HUMO_H
#define HUMO_H
#include "Arduino.h"
//declara una vez la clase Humo
class Humo {
public:
  //declara la existencia de la clase Humo
  Humo();
  //declara los voids que hacen funcionar los componentes en el principal
  void prepararHumo();
  void usarHumo();

  //solo queda ese
  int humo = 13;
  int punto = 0;
  bool tiraHumo = false;
};
//termina la definición de Humo
#endif