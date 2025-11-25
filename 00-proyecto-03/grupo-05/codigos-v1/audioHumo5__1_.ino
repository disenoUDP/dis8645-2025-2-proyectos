#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(2, 3); // RX = 2, TX = 3
DFRobotDFPlayerMini myDFPlayer;

// Variables originales
bool reproducirAudio = false;
bool vueltaEncoder = true;
int rango = 2;

void setup() {
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

void loop() {
  if (vueltaEncoder == true) {
    vueltaEncoder = false;
    reproducirAudioPorRango();
    reproducirAudio = true;
  }

  Serial.println("estoy funcionando");
  Serial.println(rango);

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

void reproducirAudioPorRango() {
  if (rango == 1) {
    myDFPlayer.play(1);
    Serial.println("Rango 1");
  } 
  else if (rango == 2) {
    myDFPlayer.play(2);
    Serial.println("Rango 2");
  } 
  else if (rango == 3) {
    myDFPlayer.play(3);
    Serial.println("Rango 3");
  } 
  else if (rango == 4) {
    myDFPlayer.play(4);
    Serial.println("Rango 4");
  } 
  else if (rango == 5) {
    myDFPlayer.play(5);
    Serial.println("Rango 5");
  } 
  else {
    Serial.println("fuera de límites.");
  }
}
