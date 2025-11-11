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
