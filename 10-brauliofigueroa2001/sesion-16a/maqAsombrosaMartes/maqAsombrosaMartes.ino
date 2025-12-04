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
  audio.prepararAudio();
  encoder.prepararEncoder();
 
  leds.prepararLeds();
  vibrador.prepararVibrador();
}

void loop() {
  encoder.usarEncoder();
  //hace que nivelLuz valga lo mismo que rango
  //sirve para activar las leds

//el valor que manda va al final
//en este caso encoder.rango es el que cambia al resto
leds.nivelLuz = audio.fase = vibrador.intervalo = encoder.rango;
  
leds.usarLeds();
  //vibrador.fuerteVibrador();
  //vibrador.despacioVibrador();
  //vibrador.medianoVibrador();

//Esta función activa el audio solo cuando se añade una vuelta
//Se activa solo cuando vueltaActual y vueltaAnterior son diferentes
//la gracia es que inmediatamente cuando son diferentes suma a vueltaAnterior para que queden iguales
//de esta manera solo suena una vez y no se interrumpe
  if (encoder.vueltaActual != encoder.vueltaAnterior){
    audio.reproducirAudioPorfase();
    encoder.vueltaAnterior++;
  }

//vibrador llama a velocidadVibrador para controlar velocidad
vibrador.usarVibrador();

//Serial.println("hola");
//delay(100);
}
