# sesion-14a

## Elementos importantes
- int con valores se debe resetear facilmente. Podríamos ayudarnos de una función que detecte presión en el encoder.


### Primeras aproximaciones a código
Para iniciar el proyecto me encargaré de 2 actuadores: Parlante y Luces. Para el parlante pienso adaptar el código usado en el proyecto anterior para recibir datos de del encoder. Ligando audios a rangos de valores con if haremos que se reproduzcan solo cuando pasen por un punto específico. Para las luces podríamos programarlas en serie para que actúen según el resto. Debemos alternar de manera precisa cuando se prenden y apagan y por cuanto tiempo.

### Buscar
- Referencias de código para manipular multiples led
<https://mecabot-ula.org/tutoriales/arduino/practica1-encender-y-apagar-con-arduino/>
- Fuentes de audio
<https://www.epidemicsound.com/sound-effects/categories/objects/>

### LED's
Esencialmente funcionan así:
```cpp
// Práctica encender y apagar dos LED
const int LED1=13;
const int LED2=12;
void setup()
{
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
}
void loop()
{
digitalWrite(LED1,HIGH);
delay(1000);
digitalWrite(LED1,LOW);
digitalWrite(LED2,HIGH);
delay(1000);
digitalWrite(LED2,LOW);
}
```

El tema es ser muy consciente de las conexiones y ligar cada led a los rangos de progreso de la manivela. Para estar en la misma página decidimos que los valores de la manivela se traducirán en int que ordenaremos en rangos. Estos rangos abarcarán cada posible estado de la manivela y activarán los distintos actuadores paralelamente.

### RANGOS
- Rango 1: 0% - 29%
- Rango 2: 30% - 49%
- Rango 3: 50% - 69%
- Rango 4: 70% - 99%
- Rango 5: 100%

El orden de eventos que sufren las led son los siguientes (entre paréntesis está el punto de inicio - punto de término):
1. LED 1 encendida (0% - 100%)
2. + LED 2 encendida (30% - 100%)
3. + LED 3 encendida (50% - 100%)
4. + LED 4 encendida (70% - 100%)
5. + LED 5 encendida y variación de encendida/apagada de todas las led por lo que dure la salida de humo.
6. LED 1 encendida


## El Audio
Para el reproductor mp3 decidí usar el código hecho anteriormente de ***Gustavo, el alien*** como base. Decidí usar una versión bastante preliminar ya que lo único que necesitaba era que funcionara. Esencialmente este código debe reproducir audio cuando se lo indique la función de la manivela y alternar entre que audio reproduce según la misma función. Lo más delicado es que no se atrape leyendo continuamente el valor de la función o que la vuelta de manivela sea muy rápida para leer el siguiente valor. Para tener por dónde empezar le dí una pasada por chat gpt para que me explique y agregue elementos esenciales que desconozco. Así quedó:
```cpp
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

// --- Conexión DFPlayer ---
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// --- Variables del encoder (estas vendrán de tu otro código) ---
int rangoEncoder = 0;     // Rango actual (1–5)
int puntoEncoder = 0;     // Punto actual del encoder
int rangoAnterior = -1;   // Para detectar cambio de rango
int puntoAnterior = -1;   // Para detectar paso por punto 1

void setup() {
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);

  // Inicializar DFPlayer
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Error al inicializar DFPlayer. Verifica conexiones y SD.");
    while(true);
  }

  myDFPlayer.volume(20); // Volumen (0–30)
  Serial.println("DFPlayer listo.");
}

void loop() {
  // --------------------------
  // Aquí deberías actualizar:
  // rangoEncoder → según vueltas totales
  // puntoEncoder → posición actual del encoder
  // --------------------------

  // EJEMPLO DE PRUEBA (borra esto cuando uses tu encoder real):
  static unsigned long timerTest = millis();
  if (millis() - timerTest > 6000) {
    timerTest = millis();
    rangoEncoder++;
    if (rangoEncoder > 5) rangoEncoder = 1;
    puntoEncoder = 1;  // Simula paso por punto 1
    Serial.print("Simulación: Rango = ");
    Serial.print(rangoEncoder);
    Serial.println(" | Punto = 1");
  } else {
    puntoEncoder = 0; // No está en punto 1
  }

  // --- Detección del punto de activación ---
  if (puntoEncoder == 1 && puntoAnterior != 1) {
    reproducirAudioPorRango(rangoEncoder);
  }

  // Guardar estados anteriores
  puntoAnterior = puntoEncoder;
  rangoAnterior = rangoEncoder;
}

// --- Función para reproducir audio según el rango ---
void reproducirAudioPorRango(int rango) {
  if (rango == 1) {
    myDFPlayer.play(1); // archivo 001.mp3
    Serial.println("Reproduciendo Rango 1 (0% - 29%)");
  } 
  else if (rango == 2) {
    myDFPlayer.play(2); // archivo 002.mp3
    Serial.println("Reproduciendo Rango 2 (30% - 49%)");
  } 
  else if (rango == 3) {
    myDFPlayer.play(3); // archivo 003.mp3
    Serial.println("Reproduciendo Rango 3 (50% - 69%)");
  } 
  else if (rango == 4) {
    myDFPlayer.play(4); // archivo 004.mp3
    Serial.println("Reproduciendo Rango 4 (70% - 99%)");
  } 
  else if (rango == 5) {
    myDFPlayer.play(5); // archivo 005.mp3
    Serial.println("Reproduciendo Rango 5 (100%)");
  } 
  else {
    Serial.println("Rango fuera de límites.");
  }
}
```
Al darle un primer vistazo reconozco líneas que se pueden elíminar como la detección del rango anterior ya que solo necesitamos saber donde está en este momento. Los rangos serán parte de la función del encoder y aquí solo llegarán los resultados para saber que pista poner. En este código también hace falta una función que pause la recepción de datos cuando se reproduce un audio, que reciclaré de ***Gustavo*** nuevamente. En este caso es mejor dictar cuando detecta y cuando no según el estado de reproducción del audio, ya que todo ocurrirá más rapido y de manera continua. Las pistas deben ser muy cortas (menos de un segundo) o debemos poner algún tipo de impedimento en la manivela que haga más dificil girarla con rapidez. De lo contrario la máquina podría quedarse atrás y no alcanzar a reproducir audio en todos los giros.

### Pseudocódigo audio
- Establecer conexiones
- Ordenar 5 audios en tarjeta SD
- Recibir datos de encoder
- Pasó por el punto 1? SI/NO
- En que Rango está? 1-5
- Reproduce audio correspondiente
- Pausa detección de punto
- Audio se detiene después de reproducirse una vez
- Se reactiva la detección del punto
- Audio elegido cambia a medida que progresan los rangos
- Cuando se reproduce el audio 5 se reinicia todo
