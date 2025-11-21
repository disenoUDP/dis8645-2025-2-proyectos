#include "SensorSD.h"
#include <Arduino.h>

// esto no deberia ir aqui pero no sabemos aplicarlo en el .h para que funcione correctamente
SoftwareSerial dfSerial(2, 3); // RX, TX
DFRobotDFPlayerMini player;

SensorSD::SensorSD() {}

void SensorSD::configuracionSD() {
  //comienza la comunicacion serial general
  //esta comunicacion es entre arduino y el computador/laptop al que se encuentre conectado
  Serial.begin(115200);

  //comienza la comunicacion serial del reproductor MP3
  //el número varia del serial.begin por que esta comunicacion es exclusiva entre el arduino y el reproductor
  dfSerial.begin(9600);
  
  // esta funcion if esta para verificar en el monitor serial si el reproductor funciona o no
  if (!player.begin(dfSerial)) {

  //si funciona correctamente saldra este mensaje
  Serial.println("DFPlayer online!");

 }

}

//vamos a hacer un void por sonido a ocupar, para poder diferenciar en el archivo .INO
void SensorSD::funcionaSDAlarmaFuerte() {
  //Esta variable es para manejar el volumen del archivo que sera reproducido
  //En este este caso tiene que ser fuerte
  player.volume(20);

  //Esta variable se define el archivo .mp3 que se encuentra en la tarjeta SD
  player.play(2);

  //Esta variable es temporal en algun momento de estas semanas pasara a millis()
  //Por mientras lo estamos simulando con delay la idea es que cada 1 segundo suene
  delay(500);
  // notificar por el monitor Serial que fue reproducida la alarma fuerte
  Serial.println("alarma fuerte");


}

void SensorSD::funcionaSDAlarmaDebil() {
  //Esta variable es para manejar el volumen del archivo que sera reproducido
  //En este este caso tiene que ser fuerte
  player.volume(1);

  //Esta variable se define el archivo .mp3 que se encuentra en la tarjeta SD
  player.play(1);

  //Esta variable es temporal en algun momento de estas semanas pasara a millis()
  //Por mientras lo estamos simulando con delay la idea es que cada 4 segundos suene
  delay(500);

  // notificar por el monitor Serial que fue reproducida la alarma debil
  Serial.println("alarma debil");
  
}