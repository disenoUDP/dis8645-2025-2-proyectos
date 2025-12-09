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

  sielvoLumbarA.write(180);
  sielvoLumbarZ.write(0);
  sielvoRotor.write(0);
}

void ActuadorSielvo::SielvoErguir() {

  sielvoLumbarA.write(0);
  sielvoLumbarZ.write(180);
}

void ActuadorSielvo::SielvoAflijir() {
  sielvoLumbarA.write(180);
  sielvoLumbarZ.write(0);
}

void ActuadorSielvo::SielvoRotar() {
for (pos = 0; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sielvoRotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void ActuadorSielvo::SielvoTersiana() {
  // sielvoLumbarA.write(0);
  // sielvoLumbarZ.write(30);
}