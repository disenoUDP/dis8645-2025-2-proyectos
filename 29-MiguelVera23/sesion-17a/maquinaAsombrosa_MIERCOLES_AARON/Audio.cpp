#include "Audio.h"

// declarar instancias de clases
SoftwareSerial mySoftwareSerial(2, 3);
DFRobotDFPlayerMini myDFPlayer;

// constructor
Audio::Audio() {}

void Audio::preparar(bool modo) {

  Audio::emitirSerial = modo;

  if (Audio::emitirSerial) {
    Serial.begin(9600);
  }
  // DFPlayer default baud
  mySoftwareSerial.begin(9600);

  if (Audio::emitirSerial) {
    Serial.println("inicializando DFPlayer...");
  }

  if (!myDFPlayer.begin(mySoftwareSerial)) {

    if (Audio::emitirSerial) {
      Serial.println("Error al iniciar DFPlayer");
    }
  } else {
    // volumen maximo
    myDFPlayer.volume(30);
    if (Audio::emitirSerial) {
      Serial.println("DFPlayer detectado correctamente!");
    }
  }
}

void Audio::actualizar(int rangoEncoder) {
  // guardar el anterior
  Audio::faseAnterior = Audio::fase;
  // actualizar el actual
  Audio::fase = rangoEncoder;
}

//este es el seleccionador de pista
void Audio::reproducirAudioPorfase() {
  // solamente si la fase acaba de cambiar
  // reproduce un audio nuevo
  // si la fase se mantuvo igual, se salta
  // todo el codigo a continuacion
  if (Audio::faseAnterior != Audio::fase) {
    if (fase == 1) {
      myDFPlayer.play(1);
      if (Audio::emitirSerial) {
        Serial.println("fase 1");
      }
    } else if (fase == 2) {
      myDFPlayer.play(2);
      if (Audio::emitirSerial) {
        Serial.println("fase 2");
      }
    } else if (fase == 3) {
      myDFPlayer.play(3);
      if (Audio::emitirSerial) {
        Serial.println("fase 3");
      }
    } else if (fase == 4) {
      myDFPlayer.play(4);
      if (Audio::emitirSerial) {
        Serial.println("fase 4");
      }
    } else if (fase == 5) {
      myDFPlayer.play(5);
      if (Audio::emitirSerial) {
        Serial.println("fase 5");
      }
    } else if (fase == 6) {
      myDFPlayer.play(6);
      // delay(4000);
      if (Audio::emitirSerial) {
        Serial.println("fase 6");
        Serial.println("REINICIO");
      }
    } else {
      if (Audio::emitirSerial) {
        Serial.println("fuera de limites.");
      }
    }
  }
}