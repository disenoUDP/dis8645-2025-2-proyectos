#include "Audio.h"

Audio::Audio(){}

void Audio::prepararAudio(){
  SoftwareSerial mySoftwareSerial(2, 3);

  Serial.begin(115200);
  mySoftwareSerial.begin(9600);  // DFPlayer default baud

  Serial.println("Initializing DFPlayer...");

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Error al iniciar DFPlayer");
  } else {
    Serial.println("DFPlayer detectado correctamente!");
    myDFPlayer.volume(30); // volumen máximo
  }
}

void Audio::usarAudio(){
  if (vueltaEncoder == true) {
    vueltaEncoder = false;
    reproducirAudioPorfase();
    reproducirAudio = true;
  }

  Serial.println("estoy funcionando");
  Serial.println(fase);

  if (myDFPlayer.available()) {
    uint8_t tipo = myDFPlayer.readType();
    int valor = myDFPlayer.read();

    if (tipo == DFPlayerPlayFinished) {
      Serial.println("Audio finalizado por DFPlayer");
      reproducirAudio = false;
      vueltaEncoder = false;
    }
  }
}

void Audio::reproducirAudioPorfase() {
  if (fase == 1) {
    myDFPlayer.play(1);
    Serial.println("fase 1");
  } 
  else if (fase == 2) {
    myDFPlayer.play(2);
    Serial.println("fase 2");
  } 
  else if (fase == 3) {
    myDFPlayer.play(3);
    Serial.println("fase 3");
  } 
  else if (fase == 4) {
    myDFPlayer.play(4);
    Serial.println("fase 4");
  } 
  else if (fase == 5) {
    myDFPlayer.play(5);
    Serial.println("fase 5");
  } 
  else {
    Serial.println("fuera de límites.");
  }
}