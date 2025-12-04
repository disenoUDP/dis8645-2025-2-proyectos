#ifndef PRESION_H
#define PRESION_H

// incluir bibliotecas
#include "Arduino.h"

// crear la clase
class Presion {
public:
  // constructor
  Presion();

  // funciones
  void configurar();

  void leer();


  // constante de conexion
  const int pinDePresion = A0;
  
  // variables
  int valorDePresion = 0;
  bool hayBrazo = false;
  int presionMinimaAceptable = 50;
};

#endif
