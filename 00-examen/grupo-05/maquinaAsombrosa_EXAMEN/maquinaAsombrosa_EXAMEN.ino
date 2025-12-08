//incluye todos los archivos de los componentes
#include "Encoder.h"
#include "Leds.h"
#include "Audio.h"
#include "Vibrador.h"
#include "Humo.h"

//define como se llamará cada cpp en este código
Encoder encoder;
Leds leds;
Audio audio;
Vibrador vibrador;
Humo humo;

//cada uno de estos serían un void setup() en un código particular
//para llamar cada función dentro de otra página se pone el nombre en minúscula, un punto y la función void de otro cpp.
void setup() {
  audio.prepararAudio();
  encoder.prepararEncoder();

  leds.prepararLeds();
  vibrador.prepararVibrador();
  humo.prepararHumo();
}

void loop() {
  //todo está ordenado según la prioridad dentro del código y dependiendo de cuando ocurre en la interacción
  encoder.usarEncoder();

  //el valor que manda va al final
  //en este caso encoder.rango es el que cambia al resto
  //todos los valores equivalentes al rango se igualan a este constantemente
  //así ocurren las cosas que corresponden a cada rango 
  leds.nivelLuz = audio.fase = vibrador.intervalo = humo.punto = encoder.rango;

  //Esta función activa el audio solo cuando se añade una vuelta
  //Se activa solo cuando vueltaActual y vueltaAnterior son diferentes
  //la gracia es que inmediatamente cuando son diferentes suma a vueltaAnterior para que queden iguales
  //de esta manera solo suena una vez y no se interrumpe
  if (encoder.vueltaActual != encoder.vueltaAnterior) {
    audio.reproducirAudioPorfase();
    encoder.vueltaAnterior++;
  }
  
  //activa las leds rigiéndose por el rango que leyó anteriormente 
  leds.usarLeds();


  //vibrador llama a velocidadVibrador para controlar velocidad
  //otras funciones se activan como las leds
  vibrador.usarVibrador();
  humo.usarHumo();
}
