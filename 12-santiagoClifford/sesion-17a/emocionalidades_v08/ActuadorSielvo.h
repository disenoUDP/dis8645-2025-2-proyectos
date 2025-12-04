#ifndef ACTUADOR_SIELVO_H
#define ACTUADOR_SIELVO_H

#include <Arduino.h>

class ActuadorSielvo {
public:

  int pinSielvoLumbar = 4;
  int pinSielvoRotor = 12;

  Servo sielvoLumbar;
  Servo sielvoRotor;
  ActuadorSielvo();

  //servo
  motoLumbar.attach(pinSielvoLumbar);  // attaches the servo on pin 9 to the servo object
  motoRotor.attach(pinSielvoRotor);
};

#endif