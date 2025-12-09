#ifndef ULTRASONICO_H
#define ULTRASONICO_H

// incluir bibliotecas
#include "Arduino.h"

// crear la clase
class Ultrasonico {
public:
  // constructor
  Ultrasonico();

  // funciones
  void configurar();
  void leer();

  long distancia;

  // todo lo que vaya empezado con letras azules
  // que no sean funcione, irian aqui

  float duracion;
  //Sustancia = Distancia
  float sustancia;

  int pinTrix = 9;
  //Pin Echo
  int pinEkeko = 8;

  bool persona;
};

#endif