# sesion-14b 14.11.2025

## Inicio de clase

### Presentación Textual

"Ecos de gestos"

El proyecto consiste en un objeto inerte que responde al contacto directo mediante las manos, dependiendo de la intensidad de fuerza, la acción con la cual se manipule el objeto, como respuesta de este tacto, en la pantalla que esta en frente de la persona, la grafica que se proyecta (describir la grafica) cambia justo con sonidos (describir sonidos), los cuales en conjunto generan un momento en el cual el usuario queda inmerso en el proyecto por un momento (definir cuanto tiempo).

Manifiesto

La máquina sentimental es un organismo artificial que responde al tacto humano como si tuviera emociones propias. Representa el intento de traducir afectos en datos; de convertir gestos en lenguaje digital.

Su cuerpo, hecho de una materialidad blanda y orgánica, invita al acercamiento, pero también despierta la curiosidad por lo desconocido que habita en lo artificial.

Esa mezcla de suavidad y extrañeza genera un momento de duda: el usuario no sabe si enfrentarse a un objeto inerte o a una presencia viva. En ese instante, la tecnología deja de ser solo herramienta y se vuelve territorio sensible, un espacio de descubrimiento donde lo mecánico parece respirar.

La máquina no busca imitar lo humano, sino evocar emociones a través de la interacción.

Cada gesto (presionar) es un lenguaje que el cuerpo humano ofrece y la máquina interpreta, devolviendo una respuesta sonora y visual que traduce ese impulso en un paisaje emocional.

### Revisiones y mejoras

- Tomar decisiones para no marearse con las posibilidades
- Tenemos que ser muy especificas
- describir lo mas posible para que no existan dudas del proyecto
- ¿Contexto?

### Cambios en el proyecto

Luego de clases la vale nos mando un mensaje por discord para darle una vuelta al proyecto ya que no nos gustaba al 100% y eso nos atrasaba en el momento de definir acciones, cual era la metafora, que queriamos expresar, etc

Trabajo sabado y domingo oara una nueva propuesta.

Incluir nuevo sensor

[Sensor Reconocimiento Gestual PAJ7620](https://afel.cl/products/sensor-reconocimiento-gestual-paj7620?srsltid=AfmBOopTMd45wqFCijlvZfBzDqyKl81fLgheVw-oIWmZD7SD4NCVMNws)

[Conversor de nivel lógico I2C 5V a 3.3V](https://afel.cl/products/sensor-reconocimiento-gestual-paj7620?srsltid=AfmBOopTMd45wqFCijlvZfBzDqyKl81fLgheVw-oIWmZD7SD4NCVMNws](https://afel.cl/products/conversor-de-nivel-logico-i2c-5v-a-3-3v?_pos=4&_sid=f6f87811a&_ss=r))

Repositorio que habla del sensor: [SparkFun Electronics](https://github.com/sparkfun/APDS-9960_RGB_and_Gesture_Sensor)


```cpp

#include <Wire.h>
#include "paj7620.h"

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Inicializar el sensor
  if (paj7620Init()) {
    Serial.println(" Error al iniciar PAJ7620");
  } else {
    Serial.println(" PAJ7620 listo. Mueve tu mano para probar gestos.");
  }

  delay(2000);
}

void loop() {
  uint8_t gesture = 0;
  paj7620ReadReg(0x43, 1, &gesture);  // Registro de gestos

  if (gesture != 0) {
    switch (gesture) {
      case GES_UP_FLAG:
        Serial.println(" Gesto: ARRIBA");
        break;

      case GES_DOWN_FLAG:
        Serial.println(" Gesto: ABAJO");
        break;

      case GES_LEFT_FLAG:
        Serial.println(" Gesto: IZQUIERDA");
        break;

      case GES_RIGHT_FLAG:
        Serial.println(" Gesto: DERECHA");
        break;

      case GES_FORWARD_FLAG:
        Serial.println(" Gesto: ADELANTE");
        break;

      case GES_BACKWARD_FLAG:
        Serial.println(" Gesto: ATRÁS");
        break;

      case GES_WAVE_FLAG:
        Serial.println(" Gesto: SALUDO (WAVE)");
        break;
    }
  }

  delay(50);
}
```
