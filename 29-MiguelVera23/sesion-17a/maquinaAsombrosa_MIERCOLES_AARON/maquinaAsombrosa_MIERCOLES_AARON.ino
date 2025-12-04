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

  // las funciones preparar()
  // necesitan un boolean
  // true: emiten info por puerto serial
  // false: no emiten, funcionan en silencio

  // preparar sensores
  encoder.preparar(false);

  // preparar actuadores
  audio.preparar(true);
  humo.preparar(false);
  leds.preparar(false);
  vibrador.preparar(false);
}

void loop() {

  // leer valor del sensor
  encoder.leer();

  // propagar el rango del sensores encoder
  // a los actuadores
  audio.actualizar(encoder.rango);
  humo.actualizar(encoder.rango);
  leds.actualizar(encoder.rango);
  vibrador.actualizar(encoder.rango);


  // el valor que manda va al final
  // en este caso encoder.rango es el que cambia al resto
  // leds.nivelLuz = audio.fase = vibrador.intervalo = humo.punto = encoder.rango;

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
