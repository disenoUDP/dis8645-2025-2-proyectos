# sesion-14a

11/11

Falte esa clase por la operación pero me contaron lo que hicieron.

## Indicaciones Generales del Proyecto

- Entrega del 21: presentación de un prototipo funcional (nivel prototipo, no producto final).
- Para el examen final, el prototipo debe ser refinado, maquillado y estabilizado para funcionar de manera coherente.
- Para el 21 de noviembre se prioriza:

   - La interacción
   - El relato y su coherencia
   - No enfocarse aún en la carcasa externa.

- Como grupo: investigar referentes de objetos abstractos, formas irregulares y posibles montajes.

## Proyecto
### Materiales

- Hilo conductor, integrado en superficie táctil.
- Sensor de fuerza FSR para detectar presión.
- Resistencia de 100 kΩ para estabilizar lectura.
- Lanas y textiles (gama blanco/crudo/beige) como material envolvente.
- Proyector + altavoces como actuadores para respuestas visuales y sonoras.

### Manifiesto
Versión Integrada

La Máquina Sentimental es un organismo artificial que reacciona al tacto, al sonido y a estímulos del entorno como si poseyera emociones propias. Busca explorar la afectividad en los objetos tecnológicos y cuestionar los límites entre lo vivo y lo mecánico.

Su cuerpo está construido con materiales blandos, cálidos y textiles, invitando al contacto humano y transmitiendo vulnerabilidad. En su interior, un sistema basado en Arduino, sensores de fuerza, táctiles y de sonido, recoge estímulos del usuario. Esos datos se traducen en respuestas luminosas, gráficas y sonoras, que representan un paisaje emocional.

La máquina no pretende imitar lo humano, sino evocar emociones a través de la interacción. Cada gesto (apretar, estirar, acariciar) se convierte en un lenguaje que la máquina interpreta, devolviendo patrones visuales y sonoros que expresan distintos estados emocionales. Su comportamiento puede ser suave, errático o sorprendido, dependiendo del tipo de estímulo.

La Máquina Sentimental propone un espacio donde lo tecnológico se vuelve sensible, y donde el usuario duda entre enfrentarse a un objeto inerte o a una presencia viva. A través de la interacción, se genera una experiencia poética, empática y reflexiva sobre nuestra necesidad de conexión.

### Montaje y Presentación
Ideas para el montaje visual

- Proyección dentro de un marco de fotos, simulando una pintura que se mueve.
- Referentes:

   - youtube.com/shorts/7q5ClkfMzao
   - youtube.com/shorts/LNoZ6w_9Ybw
   - youtube.com/shorts/eotrsJn_CD0

#### Bocetos y módulos textiles

- Colores: blancos, crudos, beige.
- Se sugiere subir imágenes de pruebas.
- Ideas de módulos: estructuras blandas, volúmenes textiles, relieves, tejido experimental.
- Inspiración: https://pin.it/7jbuxfWtN

### Código Arduino (Sensor de Fuerza FSR)
```cpp
// Pines del Sensor
const int Sensor_Fuerza = A0;


// Pines del LED RGB (PWM)
const int pinRojo = 9;
const int pinVerde = 10;
const int pinAzul = 11;


// Rangos de Fuerza (ajustables)
const int UMBRAL_0 = 10;
const int UMBRAL_1 = 150;
const int UMBRAL_2 = 300;
const int UMBRAL_3 = 450;
const int UMBRAL_4 = 600;
const int UMBRAL_5 = 750;
const int UMBRAL_6 = 900;


void setup() {
    Serial.begin(9600);
    pinMode(Sensor_Fuerza, INPUT);
    pinMode(pinRojo, OUTPUT);
    pinMode(pinVerde, OUTPUT);
    pinMode(pinAzul, OUTPUT);
    setColor(0, 0, 0);
}


void loop() {
    int valorFuerza = analogRead(Sensor_Fuerza);
    Serial.print("Sensor de Fuerza: ");
    Serial.print(valorFuerza);


    if (valorFuerza < UMBRAL_0) {
        Serial.println(" -> Nivel 0: SIN PRESION");
        setColor(0, 0, 0);
    } else if (valorFuerza < UMBRAL_1) {
        Serial.println(" -> Nivel 1: MUY BAJA");
        setColor(0, 50, 255);
    } else if (valorFuerza < UMBRAL_2) {
        Serial.println(" -> Nivel 2: BAJA");
        setColor(0, 150, 255);
    } else if (valorFuerza < UMBRAL_3) {
        Serial.println(" -> Nivel 3: MEDIA-BAJA");
        setColor(0, 255, 0);
    } else if (valorFuerza < UMBRAL_4) {
        Serial.println(" -> Nivel 4: MEDIA-ALTA");
        setColor(255, 255, 0);
    } else if (valorFuerza < UMBRAL_5) {
        Serial.println(" -> Nivel 5: ALTA");
        setColor(255, 100, 0);
    } else if (valorFuerza < UMBRAL_6) {
        Serial.println(" -> Nivel 6: MUY ALTA");
        setColor(255, 0, 0);
    } else {
        Serial.println(" -> Nivel 7: MAXIMA");
        setColor(255, 0, 0);
    }


    delay(500);
}


void setColor(int r, int g, int b) {
    analogWrite(pinRojo, 255 - r);
    analogWrite(pinVerde, 255 - g);
    analogWrite(pinAzul, 255 - b);
}
```
### Processing
¿Qué es?

- Processing es un lenguaje y entorno basado en Java diseñado para animación, arte visual, prototipado e interacción con sensores.

¿Para qué sirve?

- Animación 2D/3D
- Arte generativo
- Visualizaciones
- Lectura de sensores (Arduino, cámara, mouse)
- Instalaciones interactivas

Estructura básica

``` cpp 
void setup() {
  size(600, 600);
  background(255);
}


void draw() {
  circle(mouseX, mouseY, 40);
}
```

Ejemplo: rectángulo rojo centrado

``` cpp
void setup() {
  size(400, 400);
}


void draw() {
  background(220);
  fill(255, 0, 0);
  rectMode(CENTER);
  rect(width/2, height/2, 200, 100);
}
```

Variables útiles

- `mouseX`, `mouseY`
- `pmouseX`, `pmouseY`
- `key`, `keyCode`
- Eventos: `mousePressed()`

Más info en: https://processing.org

## Referentes

- Tactile Orchestra — https://www.fillipstudios.com/projects/tactile-orchestra
- Referente audiovisual 1 — https://vimeo.com/145796518
- Referente 2 — https://www.youtube.com/watch?v=sVvUY3gBx9I

### Sensores de Presión Usados

- Sensor Flexible Flex 4.5″
- Sensor de Fuerza FSR402 / FSR406
- Código de prueba incluido arriba.

Video recomendado: ARDUINO - Sensor de Fuerza Resistivo FSR 402: Conexión Paso a Paso

