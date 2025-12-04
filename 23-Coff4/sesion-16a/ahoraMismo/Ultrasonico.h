#ifndef Ultrasonico_H
#define Ultrasonico_H 

#include <Arduino.h>

class Sonic {

public:
  Sonic ();

  // establecer las 3 partes del 
  // funcionamiento para el sensor
  void configurar();
  void reconocerDistancia();
  void leerDistancia();

// definir cuales seran los pines para la funcion de
// trigger y echo en el sensor
  int pinTrix = 7;
  int pinEkeko = 8;
// definir datos para el calculo de la distancia
  int distancia = 0;
  int duracion = 5000;
// definir una booleana sobre la existencia de una persona
  bool persona = false;
};

// destructor para este archivo del proyecto para no causar problemas en el codigo
#endif