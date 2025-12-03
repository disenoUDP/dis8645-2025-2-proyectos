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
void usarVibrador();
void velocidadVibrador(int pausaHIGH, int pausaLOW);

// definir constantes vibrador
const int patitaVibrador = 12;
unsigned long momentoPasado = 0; // unsigned long significa que parte desde el 0 hacia el positivo, no usamos negativos
bool estado = HIGH;
int intervalo = 0;  // aquí cambiamos el valor el encoder


};
//termina la definición de Vibrador
#endif 