#include "SensorSD.h"

// eliminamos SoftwareSerial porque ahora usamos el UART hardware Serial1
DFRobotDFPlayerMini player;

SensorSD::SensorSD() {}

void SensorSD::configuracionSD() {
  // comienza la comunicacion serial general
  // esta comunicacion es entre arduino y el computador/laptop al que se encuentre conectado
  Serial.begin(115200);

  // comienza la comunicacion serial del reproductor MP3
  // ahora usamos Serial1 porque es el UART de hardware del Arduino R4
  Serial1.begin(9600);

  pinMode(pinBusy, INPUT);

  // esta funcion if esta para verificar en el monitor serial si el reproductor funciona o no
  if (!player.begin(Serial1)) {
    // si NO funciona correctamente saldra este mensaje
    Serial.println("DFPlayer ERROR: no se pudo inicializar");
  } else {
    // si funciona correctamente saldra este mensaje
    Serial.println("DFPlayer online!");
  }
}

void SensorSD::funcionaSDAlarmaFuerte() {
  if (caido = true && !estadoDurmiendo) {
    busy = digitalRead(pinBusy);
    // DFPlayer NO esta reproduciendo
    if (busy == HIGH) {
      // Esta variable es para manejar el volumen del archivo que sera reproducido
      // En este este caso tiene que ser fuerte
      player.volume(30);

      // Se define el archivo .mp3 que se encuentra en la tarjeta SD
      player.play(2);

      // notificar por el monitor Serial que fue reproducida la alarma fuerte
      Serial.println("Reproduciendo alarma fuerte");

      delay(200);  // prevent double-trigger
    } else {
      Serial.println("Alarma fuerte ya está sonando...");
    }
  }
}

void SensorSD::funcionaSDAlarmaDebil() {
  if (segundosTiempo < 1 && !estadoDurmiendo) {
    busy = digitalRead(pinBusy);

    // DFPlayer NO esta reproduciendo
    if (busy == HIGH) {
      // Esta variable es para manejar el volumen del archivo que sera reproducido
      // En este este caso tiene que ser despacio
      player.volume(5);

      // Se define el archivo .mp3 que se encuentra en la tarjeta SD
      player.play(1);

      // notificar por el monitor Serial que fue reproducida la alarma debil
      Serial.println("Reproduciendo alarma débil");

      delay(200);  // prevent double-trigger
    } else {
    }
  }
}
