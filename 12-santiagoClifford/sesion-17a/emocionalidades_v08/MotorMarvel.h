#ifndef MOTOR_MARVEL_H
#define MOTOR_MARVEL_H

#include <Arduino.h>

class MotorMarvel {
public:
  int able;
  int in1;
  int in2;
  bool abrazo = false;

  MotorMarvel();

  void setear();

  void abrazar();

  void tersiana();
};

#endif