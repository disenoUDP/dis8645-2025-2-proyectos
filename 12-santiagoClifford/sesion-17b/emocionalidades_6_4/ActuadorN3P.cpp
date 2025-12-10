#include "ActuadorN3P.h"
#include <Arduino.h>

ActuadorN3P::ActuadorN3P() {
  // tiempoNuevoEstado1 = 0;
  // intervaloAudio = 5000;  // 5 segundos por ejemplo
}

void ActuadorN3P::configurar() {
  mp3Serial.begin(9600);

  if (!modulito.begin(mp3Serial)) {
    Serial.println("Error iniciando DFPlayer");
  } else {
    Serial.println("DFPlayer listo!");
  }
}

void ActuadorN3P::emitirAlarmaEstado1() {
  if (!audioReproduciendo) {
    //  tiempoActualAudio = millis();
    modulito.volume(25);
    // if (tiempoActualAudio - tiempoNuevoEstado1 >= intervaloAudio) {
    int randomFile = random(0, 2);
    modulito.playFolder(1, randomFile);
      Serial.println("audio1");

    audioReproduciendo = true;
    Serial.print("Reproduciendo archivo ");
    Serial.println(randomFile);
    // tiempoNuevoEstado1 = tiempoActualAudio;
  }
  // Detectar fin del audio
  if (modulito.available()) {
    if (modulito.readType() == DFPlayerPlayFinished) {
      audioReproduciendo = false;
      Serial.println("Audio finalizado");
    }
  }
}

void ActuadorN3P::emitirAlarmaEstado2() {
  if (!audioReproduciendo) {
    //  tiempoActualAudio = millis();
    modulito.volume(25);
    // if (tiempoActualAudio - tiempoNuevoEstado1 >= intervaloAudio) {
    int randomFile = random(1, 3);
    modulito.playFolder(2, randomFile);
    audioReproduciendo = true;
    Serial.print("Reproduciendo archivo ");
    Serial.println(randomFile);
    // tiempoNuevoEstado1 = tiempoActualAudio;
  }
  // Detectar fin del audio
  if (modulito.available()) {
    if (modulito.readType() == DFPlayerPlayFinished) {
      audioReproduciendo = false;
      Serial.println("Audio finalizado");
    }
  }
}

void ActuadorN3P::emitirAlarmaEstado3() {
  if (!audioReproduciendo) {
    //  tiempoActualAudio = millis();
    modulito.volume(25);
    // if (tiempoActualAudio - tiempoNuevoEstado1 >= intervaloAudio) {
    int randomFile = random(1, 3);
    modulito.playFolder(3, randomFile);
    audioReproduciendo = true;
    Serial.print("Reproduciendo archivo ");
    Serial.println(randomFile);
    // tiempoNuevoEstado1 = tiempoActualAudio;
  }
  // Detectar fin del audio
  if (modulito.available()) {
    if (modulito.readType() == DFPlayerPlayFinished) {
      audioReproduciendo = false;
      Serial.println("Audio finalizado");
    }
  }
}

void ActuadorN3P::emitirAlarmaEstado4 () {
  if (!audioReproduciendo) {
    //  tiempoActualAudio = millis();
    modulito.volume(25);
    // if (tiempoActualAudio - tiempoNuevoEstado1 >= intervaloAudio) {
    int randomFile = random(1, 3);
    modulito.playFolder(4, randomFile);
    audioReproduciendo = true;
    Serial.print("Reproduciendo archivo ");
    Serial.println(randomFile);
    // tiempoNuevoEstado1 = tiempoActualAudio;
  }
  // Detectar fin del audio
  if (modulito.available()) {
    if (modulito.readType() == DFPlayerPlayFinished) {
      audioReproduciendo = false;
      Serial.println("Audio finalizado");
    }
  }
}
//   }
//     //ver si hay audios en la cola
//     if (modulito.available()) {

//     //reproducir audio random del estado 1(pedirAmor)
//     // randomFile = random(1, 3);
//     modulito.playFolder(1, 1);
//     // delay(20);

//     // notificar por el monitor Serial que fue reproducida la alarma fuerte
//     Serial.print("audio estado 1_PEDIR_AMOR , ");
//     Serial.println(randomFile);

//     tiempoNuevoEstado1 = tiempoActualAudio;
//     // tiempoNuevoEstado1 = tiempoActualAudio;
//   }
// }


// void ActuadorN3P::emitirAlarmaEstado2() {}
// void ActuadorN3P::emitirAlarmaEstado3() {}
// void ActuadorN3P::emitirAlarmaEestado4() {}


/*
void ActuadorN3P::emitirAlarma(int estadoActual) {
// 0_CALMAO



// 1_PEDIR_AMOR
// 2_PATALETA_LEVE
// 3_PATALETA_BRIGIDA
// 4_AUTODESTRUCCION

  if (estadoActual == 1) {
    //reproducir audio random del estado 1(pedirAmor)
    //print "rascame la watita"
    //tiempoInicioEstado=millis();
    randomFile = random(1, 3);
    modulito.playFolder(1, randomFile);
    //si el tiempoInicioEstado es mayor a 8seg, pasa a estado 2(pataletaLeve)
  } else if (estadoActual == 2) {
    //reproducir audio random del estado 2(pataletaLeve)
      randomFile = random(1, 3);
    modulito.playFolder(2, randomFile);
    //tiempoInicioEstado=millis();
    //si el tiempoInicioEstado es mayor a 12seg, pasa a estado 3(pataletaBrigida)
  } else if (estadoActual == 3) {
    //reproducir audio random del estado 3(pataletaBrigida)
        randomFile = random(1, 3);
    modulito.playFolder(3, randomFile);
    //tiempoInicioEstado=millis();
    //si el tiempoInicioEstado es mayor a 12seg, pasa a estado 4(autodestruccion)
  } else if (estadoActual == 4) {
    //reproducir audio largo del estado 4(autodestruccion)
    modulito.playFolder(3, 1);

  }
*/


//   ActuadorN3P::modulito.volume(20);
//   ActuadorN3P::modulito.play();
//   delay(500);
//   Serial.println("rascame la watita xfis :p");
// }