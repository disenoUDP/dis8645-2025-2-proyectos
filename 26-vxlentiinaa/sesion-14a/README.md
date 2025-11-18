# sesion-14a

11-11-2025

## Apuntes

- la entrega del 21 es un prototipo; que funcione a nivel prototipo y para el examen bajarlo y maquillarlo para que quede lindo y funcional.
- 21 de nov: interacción y el relato, que sea coherente, no preocuparse tanto de la carcasa por ahora.
- Como grupo, buscamos referentes de objetos abstractos, formas irregulares y opciones para montar el proyecto
- El porqué la explicación del proyecto

---

`Materiales`
 
- Hilo conductor, integrado en la superficie táctil.
- Sensor de fuerza (FSR), para detectar la presión e iniciar la interacción.
- Resistencia de 100 kΩ, para estabilizar la lectura del sensor.
- Lanas u otros textiles, como materialidad envolvente del dispositivo.
- Proyector y altavoces, como actuadores que emitirán las respuestas visuales y sonoras.

`EXPLICACIÓN DEL PROYECTO - MANIFIESTO`

- Texto 1: El proyecto propone la creación de una máquina sentimental, un artefacto interactivo capaz de reaccionar sensiblemente al entorno especialmente al ruido, la voz o el tacto y de expresar esas emociones a través de visuales luminosos y patrones en movimiento. La máquina funciona como una especie de organismo emocional. Su cuerpo, hecho con materiales suaves y cálidos como lana, fieltro o telas táctiles, invita al contacto humano y sugiere vulnerabilidad o afecto. En su interior, un Arduino junto con sensores de sonido y tacto (micrófono, sensor piezoeléctrico o capacitivo) registran los estímulos externos. Estos datos son traducidos en tiempo real a respuestas visuales por ejemplo, luces que cambian de color, intensidad o ritmo, representando lo que ocurre en su interior emocional. La máquina no busca ser útil, sino sensible. Exagera la relación entre el cuerpo y la emoción, entre la materia y la respuesta, funcionando como un espejo de nuestra propia necesidad de conexión. Puede reaccionar de manera impredecible: a veces se ilumina suavemente ante una caricia, otras se sobresalta con un ruido brusco. El objetivo del proyecto es explorar la idea de afectividad en los objetos tecnológicos y cuestionar los límites entre lo vivo y lo mecánico. ¿Puede una máquina sentir? ¿O simplemente imitar nuestras formas de sentir? A través de su diseño táctil y sus respuestas lumínicas, la máquina sentimental busca generar una experiencia empática y poética entre el espectador y el objeto, donde la interacción se vuelve una forma de comunicación emocional.

- Texto 2: La máquina sentimental es un organismo artificial que responde al tacto humano como si tuviera emociones propias. Representa el intento de traducir afectos en datos; de convertir gestos en lenguaje digital. Su cuerpo, hecho de una materialidad blanda y orgánica, invita al acercamiento, pero también despierta la curiosidad por lo desconocido que habita en lo artificial. Esa mezcla de suavidad y extrañeza genera un momento de duda: el usuario no sabe si enfrentarse a un objeto inerte o a una presencia viva. En ese instante, la tecnología deja de ser solo herramienta y se vuelve territorio sensible, un espacio de descubrimiento donde lo mecánico parece respirar. La máquina no busca imitar lo humano, sino evocar emociones a través de la interacción. Cada gesto (apretar, estirar o acariciar) es un lenguaje que el cuerpo humano ofrece y la máquina interpreta, devolviendo una respuesta sonora y visual que traduce ese impulso en un paisaje emocional.

- Texto 3: La Máquina Sentimental es un organismo artificial que responde al tacto humano como si tuviera emociones propias. Representa el intento de traducir afectos en datos, de convertir gestos íntimos en lenguaje digital.
Su cuerpo, hecho de una materialidad blanda y orgánica, invita al acercamiento, pero también refleja la vulnerabilidad que implica ser tocado. En este sentido, la máquina no solo reacciona: siente y expresa a través de gráficas y sonidos.
Cada acción del usuario (apretar, estirar o acariciar) se convierte en una metáfora de distintos estados emocionales

`PARA EL MONTAJE`

- proyección dentro de un marco de fotos, pintura que se mueve.
  - <https://youtube.com/shorts/7q5ClkfMzao?si=rRIaTytEhv4LW9uU>
  - <https://youtube.com/shorts/LNoZ6w_9Ybw?si=EFPSyt77n94wicly>
  - <https://youtube.com/shorts/eotrsJn_CD0?si=O9JYGXjXdKLEiYoI>

---

### Código para sensor de fuerza

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

---

### Bocetos y propuestas

subir imágenes

### Ejemplos de módulos de tejidos

- color de los tejidos: gama de blancos, crudos, beige, etc

`IDEAS DE MÓDULOS`

subir imágenes

<https://pin.it/7jbuxfWtN>

--- 

### Processing

Processing es un entorno de programación flexible y un lenguaje para aprender a programar. Desde 2001, Processing ha fomentado la alfabetización digital en las artes visuales y la alfabetización visual en la tecnología. Decenas de miles de estudiantes, artistas, diseñadores, investigadores y aficionados utilizan Processing para aprender y crear prototipos.

Processing sigue siendo una alternativa a las herramientas de software propietario con licencias restrictivas y costosas, lo que lo hace accesible a centros educativos y estudiantes. Su carácter gratuito, libre y de código abierto fomenta la participación y la colaboración de la comunidad, fundamentales para su crecimiento. Los colaboradores comparten programas, aportan código y crean bibliotecas, herramientas y modos para ampliar las posibilidades del software. La comunidad de Processing ha desarrollado más de cien bibliotecas para visión artificial, visualización de datos, composición musical, redes, exportación de archivos 3D y programación electrónica.

Desde sus inicios, Processing se diseñó para ser lo más sencillo posible para principiantes, sabiendo que su simplicidad también beneficiaría a usuarios más experimentados. Se inspiró en la inmediatez de lenguajes anteriores como BASIC y Logo, así como en nuestra experiencia aprendiendo a programar y enseñando programación a personas con diversos perfiles. Processing enseña los mismos conceptos que en un curso básico de informática de secundaria o universidad, pero con un enfoque diferente.

<https://processing.org>

`¿Qué es processing?`

Processing es un lenguaje basado en Java, junto a un IDE muy simple, diseñado para facilitar la creación de:
  - Animaciones 2D y 3D
  - Visualizaciones gráficas
  - Interacciones con sensores (Arduino, mouse, teclado, cámara…)
  - Arte generativo
  - Instalaciones

`¿Cómo funciona el código?`

setup(): 
  - Se ejecuta una sola vez al inicio.
  - Aquí configuras el tamaño de la pantalla, los colores, la velocidad, etc.

```cpp
void setup() {
  size(600, 600);   // Tamaño de la ventana
  background(255);  // Fondo blanco
}
```

draw():
  - Se ejecuta infinitamente, unas 60 veces por segundo.
  - Aquí va la animación o interacción.

```cpp
void draw() {
  circle(mouseX, mouseY, 40);  // Dibuja un círculo donde está el mouse
}
```

`Ciclo básico de processing`

- Se abre la ventana.
- Se ejecuta setup().
- Se ejecuta draw() repetidamente.
- Dentro de draw() puedes:
  - Dibujar figuras
  - Cambiar colores
  - Leer entradas (mouse, teclado)
  - Actualizar animaciones

`Ejemplo: dibujar un rectángulo rojo al centro.`

```cpp
void setup() {
  size(400, 400);
}

void draw() {
  background(220); // Limpia cada frame
  fill(255, 0, 0);
  rectMode(CENTER);
  rect(width/2, height/2, 200, 100);
}
```

`Processing integra variables como:`

- mouseX, mouseY → posición del mouse
- pmouseX, pmouseY → posición anterior
- key / keyCode → teclas presionadas
- mousePressed() → se activa al hacer clic

Ejemplo: cambiar color con el mouse:

```cpp
void draw() {
  background(mouseX % 255, mouseY % 255, 150);
}
```

---

### Referentes

- <https://www.fillipstudios.com/projects/tactile-orchestra>
- <https://vimeo.com/145796518?from=outro-embed>
- <https://www.youtube.com/watch?v=sVvUY3gBx9I>
