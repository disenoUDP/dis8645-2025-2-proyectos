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

void ActuadorN3P::emitirAlarma(int estado, int distancia) {

  if (estado == 0) {
    // estado: calmao
    // si se detecta una presencia a menos de 20cm. Pasa a estado pedirAmor
  } else if (estado == 1) {
    //reproducir audio random del estado 1(pedirAmor)
    //print "rascame la watita"
    //tiempoInicioEstado=millis();
    //si el tiempoInicioEstado es mayor a 8seg, pasa a estado 2(pataletaLeve)
  } else if (estado == 2) {
    //reproducir audio random del estado 2(pataletaLeve)
    //tiempoInicioEstado=millis();
    //si el tiempoInicioEstado es mayor a 12seg, pasa a estado 3(pataletaBrigida)
  } else if (estado == 3) {
    //reproducir audio random del estado 3(pataletaBrigida)
    //tiempoInicioEstado=millis();
    //si el tiempoInicioEstado es mayor a 12seg, pasa a estado 4(autodestruccion)
  } else if (estado == 4) {
    //reproducir audio largo del estado 4(autodestruccion)
  }

  ActuadorN3P::modulito.volume(20);
  ActuadorN3P::modulito.play();
  delay(500);
  Serial.println("rascame la watita xfis :p");
}