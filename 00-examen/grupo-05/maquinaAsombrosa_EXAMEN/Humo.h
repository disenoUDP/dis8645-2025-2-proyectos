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

  //pin del humo
  int humo = 13;
  int punto = 0;
  //este bool dice si ya se activó el humo
  //al activar el humo "se consume" y no puede soltar más humo
  bool tiraHumo = false;
};
//termina la definición de Humo
#endif