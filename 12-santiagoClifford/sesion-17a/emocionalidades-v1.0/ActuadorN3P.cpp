#include "ActuadorN3P.h"


ActuadorN3P::ActuadorN3P() {}

void ActuadorN3P::configurar() {

  mp3Serial.begin(9600);

  if (!modulito.begin(mp3Serial)) {
    Serial.println("Error iniciando DFPlayer");
  } else {
    Serial.println("DFPlayer listo!");
  }
}

void ActuadorN3P::emitirAlarma() {

  if (estadoActual == 1) {
    //reproducir audio random del estado 1(pedirAmor)
    //print "rascame la watita"
    //tiempoInicioEstado=millis();
    ActuadorN3P::modulito.play(1,random(0,2));

    //si el tiempoInicioEstado es mayor a 8seg, pasa a estado 2(pataletaLeve)
  } else if (estadoActual == 2) {
    //reproducir audio random del estado 2(pataletaLeve)
    //tiempoInicioEstado=millis();
    //si el tiempoInicioEstado es mayor a 12seg, pasa a estado 3(pataletaBrigida)
  } else if (estadoActual == 3) {
    //reproducir audio random del estado 3(pataletaBrigida)
    //tiempoInicioEstado=millis();
    //si el tiempoInicioEstado es mayor a 12seg, pasa a estado 4(autodestruccion)
  } else if (estadoActual == 4) {
    //reproducir audio largo del estado 4(autodestruccion)
  }

  ActuadorN3P::modulito.volume(20);
  ActuadorN3P::modulito.play();
  delay(500);
  Serial.println("rascame la watita xfis :p");
}