#include "Arduino.h"

// ===============================
//       VARIABLES Y ESTADOS
// ===============================

// valor del Rango 1 - 5 que activa las funciones
extern int rango;

// función del encoder que alimenta la función anterior
extern int leerRango;

// ===============================
//       PINES DE LOS LEDS
// ===============================

extern const int led1;
extern const int led2;
extern const int led3;
extern const int led4;
extern const int led5;

// ===============================
//       FUNCIONES PRINCIPALES
// ===============================

void prepLuces();
void actuarLuces();
void finalLuces();
