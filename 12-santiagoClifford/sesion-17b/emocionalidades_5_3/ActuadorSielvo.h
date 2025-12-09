#ifndef ACTUADOR_SIELVO_H
#define ACTUADOR_SIELVO_H

#include <Arduino.h>
#include <Servo.h>

class ActuadorSielvo {
public:

   int pinSielvoLumbarA = 6;
   int pinSielvoLumbarZ = 7;
   int pinSielvoRotor;

   // Objetos servo
    Servo sielvoLumbarA;
    Servo sielvoLumbarZ;

    Servo sielvoRotor;

  ActuadorSielvo();

 void SetearSielvo();

void SielvoRotar();

void SielvoErguir();

void SielvoAflijir();

void SielvoTersiana();

};

#endif