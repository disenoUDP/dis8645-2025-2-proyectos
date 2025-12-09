#include "ActuadorSielvo.h"

// 3 servos, 2 para columna, y 1 pa rotación

ActuadorSielvo::ActuadorSielvo() {
}

void ActuadorSielvo::SetearSielvo() {
  // Servo sielvoLumbarA;
  // Servo sielvoLumbarZ;

  // Servo sielvoRotor;

  sielvoLumbarA.attach(pinSielvoLumbarA);
  sielvoLumbarZ.attach(pinSielvoLumbarZ);

  sielvoRotor.attach(pinSielvoRotor);

  sielvoLumbarA.write(0);
  sielvoLumbarZ.write(180);
  sielvoRotor.write(0);
}

void ActuadorSielvo::SielvoErguir() {

  sielvoLumbarA.write(180);
  sielvoLumbarZ.write(0);
}

void ActuadorSielvo::SielvoAflijir() {
  sielvoLumbarA.write(0);
  sielvoLumbarZ.write(180);
}

void ActuadorSielvo::SielvoRotar() {
  sielvoRotor.write(120);
}

void ActuadorSielvo::SielvoTersiana() {
  // sielvoLumbarA.write(0);
  // sielvoLumbarZ.write(30);
}