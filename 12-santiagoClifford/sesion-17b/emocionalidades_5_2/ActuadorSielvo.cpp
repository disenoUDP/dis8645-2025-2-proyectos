#include "ActuadorSielvo.h"

// 3 servos, 2 para columna, y 1 pa rotación

ActuadorSielvo::ActuadorSielvo() {

}

void ActuadorSielvo::SetearSielvo(){
    Servo sielvoLumbarA;
    Servo sielvoLumbarZ;

  Servo sielvoRotor;

sielvoLumbar.attach(pinSielvoLumbarA);
sielvoLumbar.attach(pinSielvoLumbarZ);

sielvoRotor.attach(pinSielvoRotor);

sielvoLumbarA.write(0);
sielvoLumbarZ.write(180);


}

void ActuadorSielvo::SielvoRotar(){
  sielvoRotor.write(120);
}
void ActuadorSielvo::SielvoErguir(){
  sielvoLumbar.write(0);
}
void ActuadorSielvo::SielvoAflijir(){
  sielvoLumbar.write(90);
}
void ActuadorSielvo::SielvoTersiana(){
  sielvoLumbar.write(0);
  sielvoLumbar.write(30);
  sielvoLumbar.write(0);
  sielvoLumbar.write(30);
}