  #ifndef MOTOR_MARVEL_H
#define MOTOR_MARVEL_H

#include <Arduino.h>

class MotorMarvel {
public:
  int able;
  int in1;
  int in2;
  bool abrazando;
  unsigned long inicioAbrazo = 0;
unsigned long duracionAbrazo = 6000; // por ejemplo 800ms
unsigned long tiempo;

  MotorMarvel();

  void Setear();

  void abrazar();

  void actualizarAbrazo();

  void activarAbrazo();

  void tersiana();
};

#endif