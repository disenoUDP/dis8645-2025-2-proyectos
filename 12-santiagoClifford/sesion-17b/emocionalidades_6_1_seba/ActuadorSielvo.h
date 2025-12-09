#ifndef ACTUADOR_SIELVO_H
#define ACTUADOR_SIELVO_H

#include <Arduino.h>
#include <Servo.h>

class ActuadorSielvo {
public:

   int pinSielvoLumbarA=7;
   int pinSielvoLumbarZ=6;
   int pinSielvoRotor=12; 

   int pos;

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