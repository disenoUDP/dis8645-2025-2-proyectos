# sesion-14b
14/11

Falte por licencia pero tambien me contaron que hicieron.

## Conceptos Técnicos

- Bash: Lenguaje utilizado para operar terminales y automatizar tareas dentro de entornos como PowerShell.
- Dirección MAC: Identificador permanente asignado por el fabricante a la tarjeta de red de cualquier dispositivo (computador, teléfono, etc.). Es único y no se modifica

## Clase
Durante la sesión se avanzo directamente en el Proyecto 03, revisando el funcionamiento del sensor de fuerza y cómo integrarlo con un LED RGB.

### Codigo

Código Base: Lectura de Sensor de Fuerza
```cpp
const int Sensor_Fuerza = A0; // Entrada analógica del sensor


void setup() {
    Serial.begin(9600);
    pinMode(Sensor_Fuerza, INPUT);
}


void loop() {
    int valorFuerza = analogRead(Sensor_Fuerza);
    Serial.print("Sensor de Fuerza: ");
    Serial.println(valorFuerza);
    delay(500);
}
```
Código Extendido: Sensor + LED RGB Reactivo
```cpp
// Sensor de fuerza
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
setColor(0, 0, 0); // LED apagado
}


void loop() {
int valorFuerza = analogRead(Sensor_Fuerza);


Serial.print("Sensor de Fuerza: ");
Serial.print(valorFuerza);


if (valorFuerza < UMBRAL_0) {
Serial.println(" → Nivel 0: Sin presión");
setColor(0, 0, 0);


} else if (valorFuerza < UMBRAL_1) {
Serial.println(" → Nivel 1: Muy baja");
setColor(0, 50, 255);


} else if (valorFuerza < UMBRAL_2) {
Serial.println(" → Nivel 2: Baja");
setColor(0, 150, 255);


} else if (valorFuerza < UMBRAL_3) {
Serial.println(" → Nivel 3: Media-baja");
setColor(0, 255, 0);


} else if (valorFuerza < UMBRAL_4) {
Serial.println(" → Nivel 4: Media-alta");
setColor(255, 255, 0);


} else if (valorFuerza < UMBRAL_5) {
Serial.println(" → Nivel 5: Alta");
setColor(255, 100, 0);


} else if (valorFuerza < UMBRAL_6) {
Serial.println(" → Nivel 6: Muy alta");
setColor(255, 0, 0);


} else {
Serial.println(" → Nivel 7: Máxima");
setColor(255, 0, 0);
}


delay(500);
}


// LED con ánodo común
void setColor(int r, int g, int b) {
analogWrite(pinRojo, 255 - r);
analogWrite(pinVerde, 255 - g);
analogWrite(pinAzul, 255 - b);
}
```

### Presentación Textual del Proyecto
"Ecos de Gestos"

Este proyecto propone un objeto que, aunque pareciera inerte, reacciona al contacto humano. La intensidad con la que la persona lo presiona determina cómo cambia una visualización proyectada frente a ella: la gráfica responde en tiempo real, acompañada de paisajes sonoros que se ajustan al nivel de presión. La experiencia busca envolver al usuario por un breve instante, generando un momento inmersivo que conecta cuerpo, sonido y visualización.

#### Manifiesto Reescrito

La máquina sentimental funciona como una criatura artificial que interpreta el tacto humano y lo traduce en gestos visuales y sonoros. No pretende copiar emociones humanas, sino sugerirlas mediante respuestas digitales.

Su superficie blanda invita a tocarla, pero su comportamiento impredecible hace que la interacción se vuelva un territorio ambiguo entre lo vivo y lo mecánico. Ese cruce abre un espacio donde la tecnología deja de ser herramienta para convertirse en un cuerpo sensible.

Cada presión se vuelve un mensaje: una señal que la máquina transforma en un paisaje audiovisual, casi como si los gestos pudieran convertirse en ecos emocionales.

#### Comentarios 

- Aterrizar mejor las decisiones para no perderse entre tantas posibilidades.
- Falta un contexto claro: ¿cuándo usaría alguien esta máquina?, ¿para qué estado?
- Evitar explicaciones demasiado literales.
- Identificar cuál es el "triunfo" del proyecto.
- Reducir el infinito de posibilidades a un sistema con límites claros.
- Definir conceptos como calma, curiosidad, etc.
- Pensar en la máquina como un dispositivo especulativo.
- Se deben establecer 4 parámetros.

Parámetros propuestos:

- Presión suave
- Presión media
- Presión medio-fuerte
- Presión muy fuerte

Colores sugeridos para las gráficas:

- Magenta
- Turquesa
- Verde flúor
- Azul flúor

Emociones/metáforas para cada nivel:

- Curiosidad
- Calma (desestrés)

#### Planificación

- Carta Gantt
- Diagrama de flujo
- Presupuesto
- Bocetos físicos

### Exploración 

La idea original surgió de exagerar acciones que usualmente se hacen con delicadeza. La intención era tomar tareas que exigen precisión y realizarlas de forma absurda o torpe. Desde ahí nacieron varias propuestas:

1. Objeto que se altera cuando es tocado suavemente, pero se calma con presión fuerte.
2. Radio que no sintoniza señales, sino estados emocionales, creando paisajes sonoros distorsionados.
3. Máquina que reacciona a variables biométricas como pulso o temperatura.
4. Caja que registra fragmentos de sonido y los transforma en una “melodía memoria”.
5. Dispositivo que “llora” mediante agua al detectar ruidos fuertes.

#### Ideas 

- Reacción específica según fuerza aplicada.
- ¿Qué ocurre al ejercer presión mínima? ¿Y al aplicar mucha fuerza?
- Sensor FSR como opción simple pero poco precisa.
- Inspiración en fluidos no newtonianos y su reacción a golpes.
- Posible lectura de impacto además de presión.
- Materialidades inspiradas en líquidos y comportamientos de la materia.









