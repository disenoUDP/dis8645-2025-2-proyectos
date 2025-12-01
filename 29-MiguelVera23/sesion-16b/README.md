# sesion-16b

## Fusión del código usando clases
Para hacer funcionar todos los componentes en conjunto fue necesario usar clases. Este método es la mejor manera de ordenar y separar los elementos para tener control al hacer cambios o arreglos. Sebastián Saez me ayudó a hacer las clases y me mostró lo básico para hacer que todo funcione. A continuación hay algunos segmentos de nuestro código (en progreso) que demuestran el uso de estos elementos:

Estructura de archivo.h
```cpp
//base de funcionamiento para clases
#ifndef AUDIO_H
#define AUDIO_H
//declara una vez la clase Audio
class Audio {
  public:
//declara la existencia de la clase Audio
  Audio();
//declara los voids que hacen funcionar los componentes en el principal
void prepararAudio();
  void usarAudio();

};
//termina la definición de Audio
#endif
```
De esta manera se crea una clase usando las bibliotecas y se declaran los void y las funciones que se usarán. Lo único necesario para llamar y aplicar la clase en el cpp es esto:

```cpp
#include "Audio.h"

Audio::Audio(){}

void Leds::prepararLeds(){}
```
En el código principal que usa todos estos elementos se deben llamar las funciones dependiendo de si preparan o activan. También ocurren los cruces de valores entre un actuador y otro. Al ser el único lugar en el que "existen" todas las páginas, en el código principal también se leen estos cambios de valor y asociaciones. Se ve como algo así:

```cpp
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
```

