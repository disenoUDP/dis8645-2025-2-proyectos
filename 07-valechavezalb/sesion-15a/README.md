# 🌷 sesion-15a
Martes 18 de noviembre 

## 🪩 Apuntes de clase 
Martes **25 de noviembre**
- 09:30 Metro Salvador
- 11:00 MAC Parque Forestal

## 🔮 Avance del proyecto

### Explicación del proyecto
Es una máquina interactiva que se controla con gestos de la mano. El usuario mueve su mano frente a un sensor, y ese movimiento controla un punto en la pantalla. El objetivo parece sencillo: mover ese punto y atrapar un objeto que aparece frente a ti.

Pero la máquina está programada para escaparse justo cuando estás por ganar. Cuando detecta que estás demasiado cerca, activa un “glitch”, mueve el objetivo rápidamente y te deja con las ganas. Lo hace una y otra vez, de una forma que parece casi personal, como si te estuviera leyendo y respondiendo a tu intención.

Este punto, se reemplazará por las gráficas que aparecerán más adeñante.
### Pseudocódigo
```cpp
cpp 
INICIAR variables:
    estado = "espera"
    puntaje = 0
    objetivo = posición_inicial

MIENTRAS el sistema esté encendido:
    
    leer gestos y distancia del usuario

    SI estado == "espera" Y el usuario se acerca:
        mostrar_mensaje("¿Vienes a perder?")
        estado = "invitación"

    SI estado == "invitación" Y el usuario hace el gesto de empezar:
        calibrar_controles()
        estado = "jugando"

    SI estado == "jugando":
        mover_cursor_segun_gestos()
        mover_objetivo_con_su_logica()

        SI el usuario está muy cerca de atrapar:
            decidir_si_trollear()

        SI el jugador atrapa el objetivo:
            SI hay_trolleo:
                hacer_glitch_y_huir()
                burlarse_del_usuario()
            SINO:
                sumar_puntos()
                mostrar_feedback_positivo()

                SI puntaje alcanza el mínimo para ganar:
                    estado = "victoria"

    SI estado == "victoria":
        SI hay_trolleo:
            hacer_glitch_y_huir()
            mostrar_mensaje("¿Pensaste que te dejaría ganar?")
            estado = "jugando"
        SINO:
            celebrar()
            reiniciar_juego()

    esperar_pequeño_momento()
```

### Diagrama de flujo
![imagen de referencia](imagenes/diagrama.png)

### Devolviéndonos al sensor de fuerza
Después de probar el sensor gestual, nos dimos cuenta de que era muy difícil que reconociera los gestos que queríamos reconocer, es por eso que nos quedamos con el sensor de fuerza, que ya lo habíamos investigando mucho más que el de gestualidad.

La idea es que para nuestro proyecto fuera como un control joystick pero en vez de botones, estos estuvieran reemplazados por los sensores de fuerza. Estos sensores tendrían las siguientes direcciones `arriba-abajo` `izquierda-derecha` esto haría que se moviera el puntito en toda la pantalla y permitiera la interacción.

El día lunes 17 de noviembre logramos que el punto subiera y bajara con los siguientes códigos:

`Izquierda-derecha`
```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO 64

// Crear display OLED
Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, -1);

const int Sensor_Fuerza = A0;  // Pin del sensor de fuerza

void setup() {
    Serial.begin(9600);
    pinMode(Sensor_Fuerza, INPUT);

    // Inicializar pantalla OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("ERROR: Pantalla OLED no encontrada");
        while (true);  
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("FSR + OLED OK");
    display.display();
    delay(1000);
}

void loop() {
    int valorFuerza = analogRead(Sensor_Fuerza);

    Serial.print("Sensor de Fuerza: ");
    Serial.println(valorFuerza);

    // Convertir presión en posición HORIZONTAL
    // 0 -> izquierda (x=5)
    // 1023 -> derecha (x=120)
    int posicionX = map(valorFuerza, 0, 1023, 5, 120);

    // Limitar movimientos
    if (posicionX < 0) posicionX = 0;
    if (posicionX > 127) posicionX = 127;

    // Dibujar puntito
    display.clearDisplay();
    display.fillCircle(posicionX, 32, 3, SSD1306_WHITE);  // y=32 (centro vertical)
    display.display();

    delay(50);
}
```

`Derecha`
```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO 64

// Crear display OLED
Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, -1);

const int Sensor_Fuerza = A0;  // Pin del sensor de fuerza

void setup() {
    Serial.begin(9600);
    pinMode(Sensor_Fuerza, INPUT);

    // Inicializar pantalla OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("ERROR: Pantalla OLED no encontrada");
        while (true);  
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("FSR + OLED OK");
    display.display();
    delay(1000);
}

void loop() {
    int valorFuerza = analogRead(Sensor_Fuerza);

    Serial.print("Sensor de Fuerza: ");
    Serial.println(valorFuerza);

    // Convertir presión en posición vertical
    // 0 -> abajo (y=60)
    // 1023 -> arriba (y=5)
    int posicionY = map(valorFuerza, 0, 1023, 60, 5);

    // Limitar movimientos
    if (posicionY < 0) posicionY = 0;
    if (posicionY > 63) posicionY = 63;

    // Dibujar puntito
    display.clearDisplay();
    display.fillCircle(64, posicionY, 3, SSD1306_WHITE);
    display.display();

    delay(50);
}
```

### 👾🧚🏻 Para las animaciones
Al final decidimos usar pixel art para nuestras gráficas, para esto se crearon ilustraciones que serán cargadas en p5 que es donde estará la interfaz del juego.
![imagen](imagenes/graficas.png)

### Código de las animaciones en p5
```java
PS5.JS —-> mosquitos código

let colors = {};   // Se inicializan vacío
let sprite4;       // Se declara antes, pero se llena en setup()

function setup() {
  createCanvas(370, 330);
  noStroke();

  // Definición de colores
  colors = {
    0: color(0, 0, 0, 0),        // transparente
    1: color(0),                 // negro
    2: color(255,224,189),       // piel
    3: color(200),               // gris polera
    4: color(130,200,255),       // celeste alas
    5: color(40,90,200),         // azul pantalón
    6: color(255,120,180),       // rosa
    7: color(255,255,255),       // blanco
    8: color(220),               // gris claro
    9: color(180,230,255)       // celeste claro
  };

  // Se inicia el sprite
  sprite4 = [
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,1,1,2,2,2,2,2,1,1,1,6,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,1,1,2,2,2,2,2,2,1,1,6,6,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,1,1,1,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,1,1,2,2,1,1,2,2,1,1,1,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,6,6,2,2,2,2,6,6,2,1,1,1,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,6,6,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0],
    [0,0,0,9,9,9,9,9,4,4,4,4,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,4,4,4,4,9,9,9,9,0],
    [0,9,9,9,9,9,9,9,4,4,4,4,1,1,1,1,3,3,7,7,7,7,3,3,1,1,1,1,4,4,4,4,4,9,7,9,9],
    [9,7,9,9,9,9,4,4,4,4,4,4,1,1,1,3,8,3,7,7,7,7,3,8,3,1,1,4,4,4,4,4,9,7,9,9,9],
    [9,9,7,9,9,9,4,4,4,4,4,4,4,1,3,8,8,3,7,7,7,7,3,8,8,3,1,1,4,4,4,4,7,9,9,9,9],
    [0,9,9,7,9,9,4,4,4,4,4,4,1,3,8,8,8,3,7,7,7,7,3,8,8,8,3,1,4,4,4,4,9,9,9,9,0],
    [0,9,9,9,9,9,9,9,4,4,4,4,3,8,8,8,8,3,7,7,7,7,3,8,8,8,8,3,4,4,4,9,9,9,9,9,0],
    [0,0,0,0,0,9,9,9,9,9,9,4,3,8,8,8,8,3,3,7,7,3,3,8,8,8,8,3,4,4,9,9,9,9,9,0,0],
    [0,0,0,0,0,0,9,9,9,9,7,4,3,8,3,8,8,8,3,7,7,3,8,8,8,3,8,3,4,9,9,9,9,0,0,0,0],
    [0,0,0,0,0,0,0,0,9,9,9,4,3,8,3,8,8,8,3,7,7,3,8,8,8,3,8,3,9,9,9,9,0,0,0,0,0],
    [0,0,0,0,0,9,9,9,9,9,9,4,3,8,3,8,8,8,3,7,7,3,8,8,8,3,8,3,4,9,9,9,9,0,0,0,0],
    [0,0,0,9,9,9,9,9,9,9,4,4,3,8,3,8,8,8,3,7,7,3,8,8,8,3,8,3,4,9,9,9,9,9,0,0,0],
    [0,0,9,9,9,9,9,7,9,9,9,9,3,3,3,3,3,3,3,7,7,3,3,3,3,3,3,3,4,4,9,9,9,9,0,0,0],
    [0,0,9,9,9,9,7,9,9,9,9,7,2,2,2,5,5,5,5,5,5,5,5,5,5,2,2,2,9,9,9,9,9,0,0,0,0],
    [0,0,9,9,9,7,9,9,9,9,9,7,2,2,2,5,5,5,5,5,5,5,5,5,5,2,2,2,9,9,9,9,0,0,0,0,0],
    [0,0,0,9,7,9,9,9,9,9,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,0,0,9,9,9,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,0,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,1,1,1,1,1,0,1,1,1,1,7,1,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0],
    
  ];
}

function draw() {
  background(0);
  let pixelSize = 10;

  for (let y = 0; y < sprite4.length; y++) {
    for (let x = 0; x < sprite4[y].length; x++) {
      fill(colors[sprite4[y][x]]);
      rect(x * pixelSize, y * pixelSize, pixelSize, pixelSize);
    }
  }
```

## Conexión Arduino con P5.js
Primero vi estos videos para entender la conexión.
(https://www.youtube.com/watch?v=MtO1nDoM41Y)

Primero probaremos la conexión serial. Pero antes de esto hay que descargar un programa intermediario que hace que pueda leer el puerto serial desde una página web, que por motivos de seguridad están bloqueados. **Este es el link de descarga**: (https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2).

### P5.serialcontrol
Esta aplicación ejecuta p5.serialserver, que permite la conectividad entre dispositivos serie locales y aplicaciones web mediante la biblioteca p5.serialport de p5.js.

Probando, me di cuenta de que esta aplicación no funcionaba como corresponde, no encontraba el puerto serial y no lograba hacer la conexión, es por eso que le pedimos ayuda a Aarón, y nos guió con la biblioteca para poder usar el arduino con p5.
![imagen](imagenes/conexion.p5.ino.png)


### p5.webserial.js de Gohai
(https://github.com/gohai/p5.webserial?tab=readme-ov-file#getting-started)

Esta es una biblioteca para p5 que añade compatbilidad para interactuar con dispositivos serie mediante la API Web Serial, que actualmente está compatible con Chrome y Edge.

### Para comenzar la conexión
Primero hay que descargar este archivo: (https://github.com/gohai/p5.webserial/blob/main/libraries/p5.webserial.js) e incluirlo en head del html, debajo de la línea que carga p5. <script src="https://unpkg.com/@gohai/p5.webserial@^1/libraries/p5.webserial.js"></script>

Segundo, crear una variable globar y asignarle una nueva puerto de serie dentro de la configuración.











