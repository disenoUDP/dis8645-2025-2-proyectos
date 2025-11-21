#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

// ===============================
//   SIMULACIÓN DESDE SERIAL
// ===============================

// Variables internas para simular las vueltas
int vueltasSim = 0;   // vueltas acumuladas
int rangoSim = 0;     // rango calculado (1–5)

// Devuelve TRUE si desde el monitor serial se pidió una nueva vuelta
bool simNuevaVuelta = false;

// Lee comandos del monitor serial sin afectar el código real
void simularDesdeSerial() {

  if (!Serial.available()) return;

  String cmd = Serial.readStringUntil('\n');
  cmd.trim();

  // SUMAR UNA VUELTA
  if (cmd == "+") {
    vueltasSim++;
    simNuevaVuelta = true;
    Serial.print("Vuelta añadida. Total = ");
    Serial.println(vueltasSim);
  }

  // REINICIAR
  else if (cmd == "0") {
    vueltasSim = 0;
    rangoSim = 0;
    simNuevaVuelta = false;
    Serial.println("Reinicio manual realizado.");
  }

  // FORZAR RANGO
  else if (cmd.startsWith("r")) {
    int r = cmd.substring(1).toInt();
    if (r >= 1 && r <= 5) {
      rangoSim = r;
      Serial.print("Rango forzado a ");
      Serial.println(r);
    } else {
      Serial.println("Rango inválido.");
    }
  }
}

// Calcula el rango según la cantidad de vueltas simuladas
int simularRango() {
  // Definición de rangos (puedes ajustarlos)
  if (vueltasSim >= 0 && vueltasSim <= 9) rangoSim = 1;
  else if (vueltasSim >= 10 && vueltasSim <= 19) rangoSim = 2;
  else if (vueltasSim >= 20 && vueltasSim <= 29) rangoSim = 3;
  else if (vueltasSim >= 30 && vueltasSim <= 39) rangoSim = 4;
  else if (vueltasSim >= 40 && vueltasSim <= 49) rangoSim = 5;

  // Si se supera el rango 5 → reiniciar todo
  if (vueltasSim >= 50) {
    vueltasSim = 0;
    rangoSim = 0;
    Serial.println("Se superó rango 5 → reinicio automático.");
  }

  return rangoSim;
}

// Devuelve TRUE si se generó un avance de encoder simulado
bool simularEventoEncoder() {
  if (simNuevaVuelta) {
    simNuevaVuelta = false;
    return true;
  }
  return false;
}

// Devuelve el total de vueltas simuladas
int simularPuntoEncoder() {
  return vueltasSim > 0 ? 1 : 0;  
}

///////////////////////////////
/////FIN DE SIMULACIÓN/////////
//////////////////////////////

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int leerRango = 5;
//reemplazar por función de rango/total
int rangoEncoder = 0;  
//Rango de porcentaje de avance 1-5
int leerEncoder = 1;
//reemplazar por función de encoder
int puntoEncoder = 0;
//Dónde se encuentra el encoder actualmente
bool reproducirAudio = false;
//para alternar facilmente entre reproducir y no


void prepAudio() {
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);

if (!myDFPlayer.begin(mySoftwareSerial, true, true)) {
    Serial.println("Error al iniciar DFPlayer");
    //avisa si no inicia
  }

  myDFPlayer.volume(30);
  //volumen máximo 30
}

void actuarAudio() {
  //puntoEncoder = leerEncoder;
  //Para saber donde está constantemente
  //¿Está en el punto 1?
  //rangoEncoder = leerRango;
  //Cuanto progreso lleva
  //Que audio debe reproducir

  simularDesdeSerial();

  puntoEncoder = simularPuntoEncoder();
  rangoEncoder = simularRango();
  
   if (puntoEncoder == 1 ) {
    reproducirAudioPorRango();
    puntoEncoder = leerEncoder;
    reproducirAudio = true;
    puntoEncoder = 0;

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


void reproducirAudioPorRango() {
  if (rangoEncoder == 1) {
    myDFPlayer.playFolder(1,1); // archivo 001.mp3
    Serial.println("Rango 1");
  } 
  else if (rangoEncoder == 2) {
    myDFPlayer.playFolder(1,2); // archivo 002.mp3
    Serial.println("Rango 2");
  } 
  else if (rangoEncoder == 3) {
    myDFPlayer.playFolder(1,3); // archivo 003.mp3
    Serial.println("Rango 3");
  } 
  else if (rangoEncoder == 4) {
    myDFPlayer.playFolder(1,4); // archivo 004.mp3
    Serial.println("Rango 4");
  } 
  else if (rangoEncoder == 5) {
    myDFPlayer.playFolder(1,5); // archivo 005.mp3
    Serial.println("Rango 5");
  } 
  else {
    Serial.println("fuera de límites.");
  }
}

