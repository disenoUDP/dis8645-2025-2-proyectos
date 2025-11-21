# sesion-15a
## Clase
18/11

Hoy avanzamos bastante con el proyecto y también dejamos registradas varias fechas importantes. Primero, el martes 25 tendremos la salida a terreno (nos juntamos a las 09:30 en Metro Salvador y luego vamos al MAC del Parque Forestal). El miércoles 26 asistiremos a la charla de Mateo, y el viernes 28 será nuestra última sesión de trabajo en clases, donde se espera que el proyecto ya esté bien enfocado y definido.

Durante la mañana, con mi compañera Sofe estuvimos revisando y ajustando el diagrama de flujo que habíamos armado el lunes; habían ciertos pasos que no se leían del todo claros, así que limpiamos la lógica general y ordenamos mejor los estados del sistema. Más tarde, en la tarde, avancé por mi cuenta haciendo algunas gráficas que queremos incorporar dentro del juego, pensando en cómo se verá y cómo se moverán ciertos elementos en pantalla.

### Notas técnicas 
Conexión p5.js + Arduino

Para lograr que p5.js se comunique con Arduino necesitamos un intermediario: puede ser p5.serialcontrol o un servidor hecho en Node.js. Estos permiten abrir el puerto serial y recibir datos desde Arduino usando la librería p5.serialport dentro del proyecto de p5.js.

Si el objetivo fuera conectar un controlador de p5.js directamente al Arduino y luego usar eso para volver a interactuar con el entorno visual, ya necesitaríamos hardware adicional como una placa USB Host y la librería USB Host Library 2.0.

Entrada serial en p5.js:
p5.js recibe los datos mediante la librería p5.serialport, que interpreta la información enviada por el Arduino, ya sea líneas de texto, valores numéricos o respuestas del sensor que estemos usando.

### Cambios en el proyecto – Reflexión del fin de semana

El viernes, después de clases, envié un mensaje largo al grupo en Discord porque sentía que el proyecto no estaba fluyendo. Resultó que no era solo mi sensación: ninguna estaba completamente convencida de la dirección que habíamos tomado. Principalmente, se sentía forzada la idea de justificar el sensor y el uso de lanas en la materialidad.

Por eso dedicamos el sábado y domingo a repensar todo y avanzar lo más posible con una idea nueva. Terminamos definiendo una propuesta que nos hace más sentido tanto conceptual como técnicamente.

## Nueva propuesta 

Esta propuesta fue pensada el fin de semana y despues se fueron cambiando unos detalles el mismo martes

MÁQUINA SENTIMENTAL: “Atrápame si puedes”

Sentimientos que evoca

- Frustración
- Sensación de querer controlar
- Competitividad
- Impulso de dirigir y corregir

### Metáfora

La máquina simboliza ese momento en que sientes que estás a punto de lograr algo y, por un detalle mínimo, se te escapa. Es un reflejo de expectativas que parecen alcanzables, pero se deshacen justo antes del éxito. Representa esa tensión entre la intención humana y la respuesta impredecible de un sistema que, aunque parece dócil, juega con tus emociones.

### Descripción del funcionamiento

Es un juego controlado por gestos. La persona mueve la mano frente a un sensor y ese movimiento controla un punto en la pantalla. El desafío es alcanzar un objetivo… pero el sistema está diseñado para “escapar” justo cuando lo vas a atrapar.

El dispositivo detecta tu proximidad y activa un glitch visual que hace que el objetivo huya. A veces permite sumar puntos y otras te sabotea a propósito, generando un ciclo de humor, enojo y competencia emocional entre la persona y la máquina.

### Bill of Materials

| Componente                 | Característica                         | Cantidad | Detalles                                                                 |
|---------------------------|-----------------------------------------|----------|--------------------------------------------------------------------------|
| Sensor de gestualidad     | PAJ7620                                 | 1        | Reconoce 9 gestos: arriba, abajo, izq/der, push, pull, rotación y waving |
| Conversor de nivel lógico | I2C 5V ↔ 3.3V                            | 1        | Permite interconectar módulos de distintos voltajes                      |
| Arduino Uno               | R4 Minima                               | 1        | Microcontrolador de 32 bits, suficiente para control y lógica            |
| Pantalla                  | LCD/LED (laboratorio)                   | 1        | Hay que solicitarla en el laboratorio                                    |
| Carcasa                   | Impresión 3D                            | 1        | Material: filamento a definir                                            |
| Plinto                    | —                                       | 1        | Base estructural para montar la máquina                                  |
| Cables                    | —                                       | Varios   | Para alimentación y conexión de módulos                                  |

### Diagrama de flujo (resumen narrado)

El sistema parte en un estado de “espera”, detectando si alguien se acerca. Cuando la presencia es reconocida, muestra mensajes provocativos para invitar a jugar. Si la persona hace el gesto inicial, se calibran los controles y comienza el juego.

Durante la partida:

- Los gestos mueven el cursor,
- el objetivo se mueve según su propia lógica,
- y cuando el jugador está por ganar, la máquina decide si trolea o permite el punto.

Si la persona alcanza el puntaje necesario, entra en un estado de “victoria”, aunque el sistema aún puede escapar otra vez antes de conceder el triunfo real.

### Comportamiento general del sistema
Qué hace:

- Reconoce gestos con el PAJ7620.
- Muestra un cursor y un objetivo en pantalla.
- El objetivo huye cuando detecta demasiada cercanía.
- Reproduce glitches visuales.
- Se apaga al no detectar presencia.

Cómo lo logra:

El PAJ7620 entrega vectores de movimiento y proximidad, que se traducen en coordenadas para el cursor. El objetivo utiliza una lógica autónoma que puede decidir escapar, quedarse o trolear.

Qué provoca:

- Frustración divertida
- Competencia
- Repetición (ganas de seguir intentando)

Cómo invita a jugar:

- Mensajes desafiantes del tipo: “¿En serio crees que puedes esta vez?”
- Sonido inicial llamativo.

### Sensores y actuadores

Sensor principal: PAJ7620 (gestos + proximidad)
Actuadores:

- Pantalla (1080p o vertical)
- Audio para efectos
Controlador: Arduino UNO R4 (posible con pantalla dependiendo del tipo de gráficos)

### Entradas y salidas

Entradas:

- Gestos (x, y, velocidad, tipo)
- Proximidad
- Sonido ambiente (opcional)

Salidas:

- Cursor en pantalla
- Movimiento del objetivo
- Glitches y animaciones
- Sonidos o música

### Estética visual

- Colores tipo neón (magenta, cian, amarillo, verde)
- Tipografía pixelada
- Estructura física: pantalla frontal, sensor montado en caja sobre un pedestal
- Cursor como bolita luminosa

## Funcionamiento del sensor PAJ7620 (resumen simplificado)

El sensor detecta cambios de luz infrarroja cuando la mano pasa frente a él. No toma fotos, sino patrones de movimiento. Su procesador interno compara esos patrones con gestos predefinidos y entrega un código por I2C al Arduino.

Gestos que reconoce:
arriba, abajo, izquierda, derecha, push, pull, rotación horaria, rotación antihoraria y waving.

Conexión con Arduino R4:

- VCC → 3.3V
- GND → GND
- SDA → Pin 20
- SCL → Pin 21

## Códigos probados 
 17/11

Ese día logramos hacer que un punto en la pantalla subiera y bajara según la lectura de un sensor de fuerza. Más tarde probamos la lógica para mover el punto hacia los lados. (Conservo los códigos porque son necesarios como registro, pero no los reescribo para no afectar su funcionamiento).


