//incluye todos los archivos de los componentes
#include "Encoder.h"
#include "Leds.h"
#include "Audio.h"
#include "Vibrador.h"
#include "Humo.h"

Encoder encoder;
Leds leds;
Audio audio;
Vibrador vibrador;
//Humo humo;

void setup() {
  encoder.prepararEncoder();
 // audio.prepararAudio();
  leds.prepararLeds();
  vibrador.prepararVibrador();
}

void loop() {
  encoder.usarEncoder();
  //hace que nivelLuz valga lo mismo que rango
  //sirve para activar las leds

  leds.nivelLuz = encoder.rango;
  
  leds.usarLeds();
  //vibrador.fuerteVibrador();
  //vibrador.despacioVibrador();
  //vibrador.medianoVibrador();
//audio.usarAudio();

Serial.println("hola");
}
