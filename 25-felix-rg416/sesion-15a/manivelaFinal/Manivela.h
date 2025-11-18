#ifndef MANIVELA_H
#define MANIVELA_H

#include <Arduino.h>

class Manivela {
public:

  Manivela();
  ~Manivela();

  void configurar();
  void calculoVueltas();
  void calcularRango();
  int getVueltas();

  // patitas del encoder
  int patitaCLK = 2;
  int patitaDT = 3;
  int patitaSW = 4;

  int estadoActualCLK;
  int ultimoEstadoCLK;

  // int para el cálculo de vueltas
  int paso = 0;
  int vueltas;

  int rango;

  bool direccionActual = 1;
  unsigned long ultimaPresionBoton = 0;
};
#endif