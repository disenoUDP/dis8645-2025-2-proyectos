//base de funcionamiento para clases
#ifndef VIBRADOR_H
#define VIBRADOR_H
#include "Arduino.h"
//declara una vez la clase Vibrador
class Vibrador {
  public:
//declara la existencia de la clase Vibrador
  Vibrador();
//declara los voids que hacen funcionar los componentes en el principal
void prepararVibrador();
void despacioVibrador();
void medianoVibrador();
void fuerteVibrador();

int vibrador = 12;



};
//termina la definición de Vibrador
#endif 