// incluye todos los archivos de los componentes

// archivos de sensores
#include "Encoder.h"

// archivos de actuadores
#include "Audio.h"
#include "Leds.h"
#include "Humo.h"
#include "Vibrador.h"

// declarar instancias de las clases
Encoder encoder;
Leds leds;
Audio audio;
Vibrador vibrador;
Humo humo;

void setup() {

  // preparar sensores
  encoder.preparar();

  // preparar actuadores
  audio.preparar();
  humo.preparar();
  leds.preparar();
  vibrador.preparar();
}

void loop() {

  // leer valor del sensor
  encoder.leer();

  // el valor que manda va al final
  // en este caso encoder.rango es el que cambia al resto
  leds.nivelLuz = audio.fase = vibrador.intervalo = humo.punto = encoder.rango;

  // Esta función activa el audio solo cuando se añade una vuelta
  // Se activa solo cuando vueltaActual y vueltaAnterior son diferentes
  // la gracia es que inmediatamente cuando son diferentes suma a vueltaAnterior para que queden iguales
  // de esta manera solo suena una vez y no se interrumpe
  if (encoder.vueltaActual != encoder.vueltaAnterior) {
    audio.reproducirAudioPorfase();
    encoder.vueltaAnterior++;
  }

  leds.usar();

  // vibrador llama a velocidadVibrador para controlar velocidad
  vibrador.usar();
  humo.usar();
}
