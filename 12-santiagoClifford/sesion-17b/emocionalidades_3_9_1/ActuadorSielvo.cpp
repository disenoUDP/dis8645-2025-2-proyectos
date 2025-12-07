#include "ActuadorSielvo.h"



ActuadorSielvo::ActuadorSielvo() {

}

void ActuadorSielvo::SetearSielvo(){
    Servo sielvoLumbar;
  Servo sielvoRotor;
sielvoLumbar.attach(pinSielvoLumbar);
sielvoRotor.attach(pinSielvoRotor);

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