#include "Audio.h"

SoftwareSerial mySoftwareSerial(2, 3);
DFRobotDFPlayerMini myDFPlayer;


Audio::Audio() {}

void Audio::prepararAudio() {
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);  // DFPlayer default baud

  Serial.println("Initializing DFPlayer...");

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Error al iniciar DFPlayer");
  } else {
    Serial.println("DFPlayer detectado correctamente!");
    myDFPlayer.volume(30);  // volumen máximo
  }
}

//este es el seleccionador de pista
void Audio::reproducirAudioPorfase() {
 // si está en la fase x 
 //reproduce el archivo x dentro de la tarjeta SD 
 //y escribe "fase x" en el monitor serial
  if (fase == 1) {
    myDFPlayer.play(1);
    Serial.println("fase 1");
  } else if (fase == 2) {
    myDFPlayer.play(2);
    Serial.println("fase 2");
  } else if (fase == 3) {
    myDFPlayer.play(3);
    Serial.println("fase 3");
  } else if (fase == 4) {
    myDFPlayer.play(4);
    Serial.println("fase 4");
  } else if (fase == 5) {
    myDFPlayer.play(6);
    Serial.println("fase 5");
  } else if (fase == 6) {
    myDFPlayer.play(5);
   // delay(4000);
    Serial.println("fase 6");
    Serial.println("REINICIO");
  } else {
    Serial.println("fuera de límites.");
  }
}