//incluye todos los archivos de los componentes
#include "Encoder.h"
#include "Leds.h"
#include "Audio.h"
#include "Vibrador.h"
#include "Humo.h"

Encoder encoder;
Leds leds;
//Audio audio;
//Vibrador vibrador;
//Humo humo;

void setup() {
  encoder.prepararEncoder();
  leds.prepararLeds();
 
}

void loop() {
  encoder.usarEncoder();
  //hace que nivelLuz valga lo mismo que rango
  //sirve para activar las leds
  leds.nivelLuz = encoder.rango;
  leds.usarLeds();

}
