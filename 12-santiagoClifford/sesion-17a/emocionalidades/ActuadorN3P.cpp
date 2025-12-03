#include "ActuadorN3P.h"


ActuadorN3P::ActuadorN3P() {}

void ActuadorN3P::configurar() {
  Serial.begin(115200);
  ActuadorN3P::modulito.begin(9600);
}

void ActuadorN3P::emitirAlarma(int estado, int distancia) {

  if (estado == 0) {

  } else if (estado == 1) {

  } else if (estado == 2) {
    
  } else if (estado == 3) {
    
  }



  ActuadorN3P::modulito.volume(20);
  ActuadorN3P::modulito.play(int audiosFase1[random(0, 3)]);
  delay(500);
  Serial.println("rascame la watita xfis :p");
}