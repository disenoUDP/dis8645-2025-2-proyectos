#ifndef ACTUADOR_SIELVO_H
#define ACTUADOR_SIELVO_H

#include <Arduino.h>
#include <Servo.h>

class ActuadorSielvo {
public:

   int pinSielvoLumbar = 4;
   int pinSielvoRotor = 12;

   // Objetos servo
    Servo sielvoLumbar;
    Servo sielvoRotor;

  ActuadorSielvo();

 void SetearSielvo();

void SielvoRotar();

void SielvoLumbar();
  //servo

};

#endif