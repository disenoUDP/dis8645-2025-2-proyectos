# sesion-14b

14-11-2025

## Apuntes

- Bash language: sirve para controlar terminales, que corre en la PowerShell.
- MAC Addres: identificador único e inmutable asignado por el fabricante a la interfaz de red de un dispositivo, como una computadora o un teléfono.
- Estuvimos trabajando directamente en el proyecto 03

---

Código para sensor de fuerza: 

```cpp
const int Sensor_Fuerza = A0;  // Pin del sensor de fuerza 

void setup() {
    Serial.begin(9600);
    pinMode(Sensor_Fuerza, INPUT);
}

void loop() {
    int valorFuerza = analogRead(Sensor_Fuerza);  // Leer el valor del sensor
    Serial.print("Sensor de Fuerza: ");
    Serial.println(valorFuerza);
    
    delay(500);  
}
```

```cpp
// Pines del Sensor
const int Sensor_Fuerza = A0;    // Pin analógico para el sensor de fuerza

// Pines del LED RGB (cambia estos pines según tu conexión)
// Usamos pines PWM (~)
const int pinRojo = 9;   // Pin PWM para el color Rojo
const int pinVerde = 10; // Pin PWM para el color Verde
const int pinAzul = 11;  // Pin PWM para el color Azul

// --- DEFINICIÓN DE RANGOS DE FUERZA (¡AJUSTAR ESTOS VALORES!) ---
// Rango Analógico: 0 (sin presión) a 1023 (máxima presión)
const int UMBRAL_0 = 10;   // Sin fuerza / Apagado
const int UMBRAL_1 = 150;  // Muy Baja
const int UMBRAL_2 = 300;  // Baja
const int UMBRAL_3 = 450;  // Media-Baja
const int UMBRAL_4 = 600;  // Media-Alta
const int UMBRAL_5 = 750;  // Alta
const int UMBRAL_6 = 900;  // Muy Alta (Máxima)

void setup() {
    Serial.begin(9600);
    // Configurar pines
    pinMode(Sensor_Fuerza, INPUT);
    pinMode(pinRojo, OUTPUT);
    pinMode(pinVerde, OUTPUT);
    pinMode(pinAzul, OUTPUT);
    
    // Apagar el LED al inicio
    setColor(0, 0, 0); 
}

void loop() {
    int valorFuerza = analogRead(Sensor_Fuerza); // Leer el valor del sensor
    
    // Determinar el rango y establecer el color
    Serial.print("Sensor de Fuerza: ");
    Serial.print(valorFuerza);
    
    if (valorFuerza < UMBRAL_0) {
        // Nivel 0: Sin Presión
        Serial.println(" -> Nivel 0: SIN PRESION (APAGADO)");
        setColor(0, 0, 0); // Apagado
        
    } else if (valorFuerza < UMBRAL_1) {
        // Nivel 1: Muy Baja (Azul)
        Serial.println(" -> Nivel 1: MUY BAJA (Azul/Cian)");
        setColor(0, 50, 255); 
        
    } else if (valorFuerza < UMBRAL_2) {
        // Nivel 2: Baja (Cian)
        Serial.println(" -> Nivel 2: BAJA (Cian)");
        setColor(0, 150, 255); 
        
    } else if (valorFuerza < UMBRAL_3) {
        // Nivel 3: Media-Baja (Verde)
        Serial.println(" -> Nivel 3: MEDIA-BAJA (Verde)");
        setColor(0, 255, 0); 
        
    } else if (valorFuerza < UMBRAL_4) {
        // Nivel 4: Media-Alta (Amarillo)
        Serial.println(" -> Nivel 4: MEDIA-ALTA (Amarillo)");
        setColor(255, 255, 0); 
        
    } else if (valorFuerza < UMBRAL_5) {
        // Nivel 5: Alta (Naranja)
        Serial.println(" -> Nivel 5: ALTA (Naranja)");
        setColor(255, 100, 0); 
        
    } else if (valorFuerza < UMBRAL_6) {
        // Nivel 6: Muy Alta (Rojo Brillante)
        Serial.println(" -> Nivel 6: MUY ALTA (Rojo Brillante)");
        setColor(255, 0, 0);
        
    } else {
        // Nivel 7: Máxima (Rojo Fuerte)
        Serial.println(" -> Nivel 7: MAXIMA (Rojo Fuerte)");
        setColor(255, 0, 0); // O podrías usar otro color como el Magenta: setColor(255, 0, 255);
    }
    
    delay(500);  
}

// Función para establecer el color (Ánodo Común)
void setColor(int r, int g, int b) {
    // Si es Ánodo Común: 255 - valor (0 es MAX brillo, 255 es MIN brillo)
    // Si usas Cátodo Común: analogWrite(pin, valor);
    analogWrite(pinRojo, 255 - r);
    analogWrite(pinVerde, 255 - g);
    analogWrite(pinAzul, 255 - b);
}
```

### Presentación Textual

"ECOS DE GESTOS"

El proyecto consiste en un objeto inerte que responde al contacto directo mediante las manos, dependiendo de la intensidad de fuerza, la acción con la cual se manipule el objeto, como respuesta de este tacto, en la pantalla que esta en frente de la persona, la grafica que se proyecta (describir la grafica) cambia justo con sonidos (describir sonidos), los cuales en conjunto generan un momento en el cual el usuario queda inmerso en el proyecto por un momento (definir cuanto tiempo).

`MANIFIESTO`

La máquina sentimental es un organismo artificial que responde al tacto humano como si tuviera emociones propias. Representa el intento de traducir afectos en datos; de convertir gestos en lenguaje digital.

Su cuerpo, hecho de una materialidad blanda y orgánica, invita al acercamiento, pero también despierta la curiosidad por lo desconocido que habita en lo artificial.

Esa mezcla de suavidad y extrañeza genera un momento de duda: el usuario no sabe si enfrentarse a un objeto inerte o a una presencia viva. En ese instante, la tecnología deja de ser solo herramienta y se vuelve territorio sensible, un espacio de descubrimiento donde lo mecánico parece respirar.

La máquina no busca imitar lo humano, sino evocar emociones a través de la interacción.

Cada gesto (presionar) es un lenguaje que el cuerpo humano ofrece y la máquina interpreta, devolviendo una respuesta sonora y visual que traduce ese impulso en un paisaje emocional.

```
// REVISIÓN QUE NOS HICIERON EN CLASES

decisiones para no marearse con las posibilidades 
FALTA CONTEXTO, EJEMPLO: CUANDO QUIERO DEPRIMIRME
SUPER ESPECÍFICO
MUY EXPLÍCITO
QUE ES EL TRIUNFO DE ESTE PROYECTO
DEFINIR BIEN
INFINITO A UN ESPECTRO ACOTADO
EJ: QUE ES LA CALMA
ESPECULAR, MÁQUINA IMAGINATIVA
```

DEFINIR 4 PARÁMETROS
- presionar suave
- presionar intermedio
- presionar medio tirao pa fuerte
- presionar muy fuerte

DEFINIR 4 COLORES PARA GRÁFICAS (UNA GRÁFICA REACTIVA A LOS 4 PARÁMETROS)
- MAGENTA
- TURQUESA
- VERDE FLUOR
- AZUL FLUOR

DEFINIR LA EMOCIÓN/LA METÁFORA
- CURIOSIDAD
- CALMA = DESESTRÉS

---

### PLanificación

"CARTA GANTT"

"DIAGRAMA DE FLUJO"

"PRESUPUESTO"

"BOCETOS FÍSICOS"

---

- Partimos con la idea de tomar una acción que normalmente se realiza de manera delicada y precisa, y ejecutarla de forma brusca o exageradamente rápida. La propuesta es elegir tareas cotidianas que suelen requerir cuidado, paciencia o detalle, y realizarlas de una manera totalmente opuesta: absurda, brusca o ridículamente distinta. Como si alguien intentara tejer a toda velocidad o lavarse los dientes con un objeto completamente inadecuado.

`Idea 1: Máquina ...`

Una máquina que reacciona al contacto cuando la tocas suavemente, se altera o colapsa, pero si la presionas con fuerza, se calma.

`Idea 2: Radio fantasma`

Una radio que no sintoniza estaciones reales, sino que genera un collage emocional de sonidos del entorno. Reproduce sonidos distorsionados o samples según el tono predominante. LEDs muestran visualmente las “emociones” del entorno. una radio que no comunica información, sino estados de ánimo.

`Idea 3: Máquina de resonancia sentimental`

Usa un sensor biométrico (pulso o temperatura de la piel) para generar sonido y visuales reactivos.
- Si el usuario está calmado, emite un sonido suave.
- Si está nervioso, la frecuencia sube y los LEDs titilan.

`Idea 4: Caja de memoria sonora`

Un dispositivo que graba pequeños fragmentos de sonido cada vez que alguien se acerca (sensor de proximidad). Luego los reproduce al azar con distorsiones suaves. Cuando alguien toca o se acerca a la caja, emite esta "melodia" creada de fragmentos de grabaciones. memoria afectiva.

`Idea 5: Máquina que llora`

Un artefacto que “llora” agua (con una pequeña bomba) cuando detecta ciertos sonidos, como gritos o altos volúmenes. convierte el ruido del mundo en lágrimas.

### Ideas para proyecto

Una maquina que reacciona cuando le aplicas una fuerza ¿cuál es la reacción? ¿qué hace cuando le aplicas mucha fuerza? ¿qué hace cuando le aplicas una menor fuerza?

- Punching bag, le pegas y se calma.
- Sensores de fuerza.
- Fluido no newtoniano.
- Reacción de fluidos con la presión.
- Cómo medir el impacto/velocidad de la fuerza.
- Sensores FSR de presión. Resistencia que cambia de valor cuando se le aplica la fuerza. Sensor muy sensible, ya que es poco preciso.
- Ver temas contingentes. que para acceder a este vivienda tengas que tener x horas de trabajo o x horas de algo.
- Materialidad, basándose en la naturaleza de la materia. Liquidps, etc.
