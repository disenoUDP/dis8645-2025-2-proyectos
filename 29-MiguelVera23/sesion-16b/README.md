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

### El problema del DFPlayer
En el proceso de ordenar el código, hacer clases y ver cómo funciona todo en conjunto, salió un elemento incordial: el DFPlayer. Los otros componentes si bien no colaboran (algunos si) permiten el funcionamiento de los demás. Pero el reproductor por otro lado no funciona y bloquea a los demás. Lo peor es que las condiciones para que funcione son totalmente arbitrarias. Los mínimos cambios hacen que el resto de elementos se desactiven, los valores no se leen como deben y lo peor es que de ninguna manera se reproduce el audio. La mejor opción es omitir el reproductor por el momento para poder seguir avanzando y evitar un aneurisma. 

### Otros problemas
En este momento estamos con otro problema que afecta la manivela y las leds.
- Leds no se prenden como deberían (dependiendo del rango).
- La manivela tira error si no está en una posición determinada.

### Solucionado (algo)
**El orden de los valores que se equiparan en el archivo.ino es crucial.** El que manda va al final.
```cpp
leds.nivelLuz = audio.fase = encoder.rango;
```

### FUNCIONOOOOO
En la última versión subida máquinaAsombrosa_encoderLedsMp3.ino funciona todo (lo listado) a la par como debería. Hay unos puntos que afinar pero es el avance que necesitábamos para empezar con lo último. Todo gracias al ***todopoderoso***, ***magnánimo*** y ***bondadoso*** Sebastián Saez. El cambio que hizo la diferencia fue el siguiente:

```cpp
  if (encoder.vueltaActual != encoder.vueltaAnterior){
    audio.reproducirAudioPorfase();
    encoder.vueltaAnterior++;
  }
```
Esta simple (n't) función deriva de la línea de código que añade vueltas al contador. La lógica es que cuando la vuelta actual es distinta a la vuelta anterior, se activa la pista adecuada según el rango presente (constantemente detectado). Para que ocurra una vez esta deferencia de valores se corrige sumando a la vuelta anterior.

## Pendientes (LUNES)
- Hay que revisar los audios que utilizamos y ver si son adecuados. El último debe ser especial y el resto debe evocar que la máquina está siendo afectada por ti.
- Necesitamos programar un final para toda la interacción que resetee el contador tras soltar el humo.
- Hay que añadir el código del vibrador (refinado por el Braulio) y el código (pin) del humidificador.
- Hay que armar la estructura con las led extra y la carcasa (último).
- Esto podría significar una reorganización de componentes o extensión de cables.
