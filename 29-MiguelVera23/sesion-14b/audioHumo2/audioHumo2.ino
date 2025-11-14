#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int leerRango = 4;
//reemplazar por función de rango/total
int rangoEncoder = 0;  
//Rango de porcentaje de avance 1-5
int leerEncoder = 1;
//reemplazar por función de encoder
int puntoEncoder = 0;
//Dónde se encuentra el encoder actualmente
bool reproducirAudio = false;
//para alternar facilmente entre reproducir y no


void setup() {
  Serial1.begin(9600);
  Serial.begin(115200);

  if (!myDFPlayer.begin(Serial1, true, true)) {
    Serial.println("Error al iniciar DFPlayer");
    //avisa si no inicia
  }

  myDFPlayer.volume(12);
  //volumen máximo 30
}

void loop() {
  puntoEncoder = leerEncoder;
  //Para saber donde está constantemente
  //¿Está en el punto 1?
  rangoEncoder = leerRango;
  //Cuanto progreso lleva
  //Que audio debe reproducir
  
   if (puntoEncoder == 1 ) {
    reproducirAudioPorRango(rangoEncoder);
    puntoEncoder = leerEncoder;
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
      puntoEncoder = !1;
      //Resetea reproductor
      //puntoEncoder = leerEncoder
    }
  }
}


void reproducirAudioPorRango(int rangoEncoder) {
  if (rangoEncoder == 1) {
    myDFPlayer.playFolder(1,1); // archivo 001.mp3
    Serial.println("(0% - 29%)");
  } 
  else if (rangoEncoder == 2) {
    myDFPlayer.playFolder(1,2); // archivo 002.mp3
    Serial.println("(30% - 49%)");
  } 
  else if (rangoEncoder == 3) {
    myDFPlayer.playFolder(1,3); // archivo 003.mp3
    Serial.println("(50% - 69%)");
  } 
  else if (rangoEncoder == 4) {
    myDFPlayer.playFolder(1,4); // archivo 004.mp3
    Serial.println("(70% - 99%)");
  } 
  else if (rangoEncoder == 5) {
    myDFPlayer.playFolder(1,5); // archivo 005.mp3
    Serial.println("(100%)");
  } 
  else {
    Serial.println("fuera de límites.");
  }
}