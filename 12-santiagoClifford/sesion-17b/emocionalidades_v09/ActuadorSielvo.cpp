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
  
}
void ActuadorSielvo::SielvoLumbar(){}