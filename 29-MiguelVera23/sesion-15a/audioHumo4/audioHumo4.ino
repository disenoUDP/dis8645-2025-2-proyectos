#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(2, 3); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

//int leerRango = 5;
//reemplazar por función de rango/total
//int rangoEncoder = 0;  
//Rango de porcentaje de avance 1-5
//int leerEncoder = 1;
//reemplazar por función de encoder
//int puntoEncoder = 0;
//Dónde se encuentra el encoder actualmente
bool reproducirAudio = false;
//para alternar facilmente entre reproducir y no
bool vueltaEncoder = true;
int rango = 1;


void setup() {
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);
  myDFPlayer.volume(30);
  //volumen máximo 30
   Serial.println("Initializing DFPlayer...");

//if (!myDFPlayer.begin(mySoftwareSerial, true, true)) {
//    Serial.println("Error al iniciar DFPlayer");
    //avisa si no inicia

if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin. Check:");
    Serial.println("1. Wiring");
    Serial.println("2. SD card FAT32");
    Serial.println("3. Voltage divider on RX");
    while (true);
  }
}


void loop() {
  //puntoEncoder = leerEncoder;
  //Para saber donde está constantemente
  //¿Está en el punto 1?
  //rangoEncoder = leerRango;
  //Cuanto progreso lleva
  //Que audio debe reproducir

  
   if (vueltaEncoder == true ) {
    vueltaEncoder = false;
    reproducirAudioPorRango();
    reproducirAudio = true;

  }


//terminó el audio?
  if (myDFPlayer.available()) {
    //true si se ocurrió algo con el reproductor
    uint8_t tipo = myDFPlayer.readType();
    //lee el evento del DFPlayer
    int valor = myDFPlayer.read();
    //dice que audio fue reproducido

    if (tipo == DFPlayerPlayFinished) {
      //si el evento fue que terminó de reproducir ocurre lo siguiente
      Serial.println("Audio finalizado por DFPlayer");
      //devuelve texto en monitor serial
      reproducirAudio = false;
      //como terminó de reproducir no reproduce más
      //una vez reproduce hay un intervalo en que deja de reproducir
      vueltaEncoder = false;
      //Resetea reproductor
      //puntoEncoder = leerEncoder
    }
  }
}


void reproducirAudioPorRango() {
  if (rango == 1) {
    myDFPlayer.playFolder(1,1); // archivo 001.mp3
    Serial.println("Rango 1");
  } 
  else if (rango == 2) {
    myDFPlayer.playFolder(1,2); // archivo 002.mp3
    Serial.println("Rango 2");
  } 
  else if (rango == 3) {
    myDFPlayer.playFolder(1,3); // archivo 003.mp3
    Serial.println("Rango 3");
  } 
  else if (rango == 4) {
    myDFPlayer.playFolder(1,4); // archivo 004.mp3
    Serial.println("Rango 4");
  } 
  else if (rango == 5) {
    myDFPlayer.playFolder(1,5); // archivo 005.mp3
    Serial.println("Rango 5");
  } 
  else {
    Serial.println("fuera de límites.");
  }
}

