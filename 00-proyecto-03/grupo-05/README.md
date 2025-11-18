# * ༄˖°. Máquina asombrosa - Grupo 05݁ .ೃ ࿔ * 

## Integrantes del equipo

- [Braulio Figueroa](https://github.com/brauliofigueroa2001) - Investigador y redactor
- [Camila Parada](https://github.com/Camila-Parada) - Diseño gráfico y registro
- [Félix Rodríguez](https://github.com/felix-rg416) - Modelado e impresión 3D
- [Miguel Vera](https://github.com/MiguelVera23) - Códigos y circuito

***
## Introducción

Para la última etapa del año es que se enfocó en la producción de una “máquina sentimental”. 

Esta idea es un constructo que combina los conocimientos vistos a lo largo del semestre (referente al desarrollo de mecanismos fabricados con la tecnología de Arduino, actuadores y sensores) en conjunto con rasgos y reacciones psicofisiológicas como lo son las emociones. Esta última se define como [“Alteración del ánimo intensa y pasajera (agradable o penosa) que va acompañada de cierta conmoción somática (relacionado con el cuerpo)”](https://dle.rae.es/emoci%C3%B3n).  

El eje de todo el proyecto se centra conseguir un resultado que involucre al usuario y genere una respuesta en torno a la interacción entre ambas partes (objeto/máquina – emoción; acción – reacción; causa - efecto).

Al tener libertad acerca de la propuesta es que como equipo se llegó al objetivo de crear una experiencia que tenga como efecto el generar decepción al usuario, trabajando mediante la metáfora de "vender humo".  

***

## Cuerpo de la obra: sentimiento y metáfora

Vender humo se refiere a ofrecer un objeto de nulo o escaso valor con mala fé. En este proyecto buscamos vender humo para evocar *decepción*, por lo que la venta debe ser muy convincente. La *decepción* viene al traicionar la *expectativa* por lo que no podemos tener una sin la otra. El primer paso para decepcionar al usuario es hacer que espere algo de la máquina ya que si no le importa el resultado no será efectiva. Debemos hacer que sienta que se le debe algo para pagar el esfuerzo invertido en activarla, en este caso girar la manivela. Para complementar esta "deuda" añadiremos de manera indirecta indicadores de progreso que dosifiquen la entrega de recompensas a medida que se progresa. Mostraremos que a corto plazo sus acciones tienen efectos en la máquina y daremos pistas de un gran climax al completar la secuencia:
1. Usuario aprenderá que al girar la manivela se activan solidos y se prenden luces
2. Las luces aumentarán a medida que progresa y al ser limitadas indica que hay un final
3. Se añadirán elementos al alcanzar *milestones* de progreso como vibración, compuertas que se abren o sonidos cambiantes.
4. Al completar la cantidad de vueltas las luces indicarán una sorpresa inminente
5. El esfuerzo del usuario se verá traducido en un poco de humo y un sonido patético
6. La máquina te vendió humo

Obviamente la decepción no será devastadora y es muy dificíl hacer que no tenga un tono cómico ya que la estructura de la interacción se asemeja a la de un chiste. Nuestra misión se habrá cumplido si el usuario llega al final de la interacción ya que significa que logramos hacer que compre humo de una máquina estática, sin leyenda y demandante. Vale mencionar que la máquina debe ser llamativa para que el usuario se acerque y empiece todo. Queremos aprovechar rasgos de las personas como la curiosidad o las ganas de no desperdiciar el esfuerzo/tiempo ya invertido. Estos aspectos serán el principal motor que hará funcionar nuestra máquina y contamos con ellos para que se generen interacciones.

***

## Planificación

Texto

### ⋅⋯⋯⋅ Carta Gant ⋅⋯⋯⋅

Para poder programar de forma más estratégica el avance y desarrollo del proyecto en cuestión es que se creó la siguente carta.

![carta-gantt](./imagenes/carta-gantt.png)

### ⋅⋯⋯⋅ Pseudocódigo ⋅⋯⋯⋅

Texto

### ⋅⋯⋯⋅ Diagrama de flujo ⋅⋯⋯⋅

Texto

### ⋅⋯⋯⋅ Bill of Materials ⋅⋯⋯⋅

| Componentes | Tipo | Qty | Valor/tipo | Precio | Link |
|-------------|------|-----|------------|--------|------|
| Arduino UNO R4 Mínima | Tarjetas de Desarrollo | 1 | 5V | $24.990 | https://mcielectronics.cl/shop/product/arduino-uno-r4-minima |
| Mini Protoboard 400 Puntos | Conexión | 1 | 10.000 inserciones | $1.500 | https://afel.cl/products/mini-protoboard-400-puntos |
| Pack 60 Cables Dupont | Conexión | Varios | 300 V | $2.500 | https://afel.cl/products/pack-60-cables-de-conexion |
| Encoder rotatorio KY-040 360 grados | Sensor | 1 | 5V | $2.000  | https://afel.cl/products/encoder-rotatorio-ky-040-360-grados |
| Modulo reproductor MP3 | Actuador | 1 | 3.2 a 5V | $2.990 | https://afel.cl/products/modulo-reproductor-mp3-dfplayer-mini |
| Motor vibrador PWM Switch DC | Actuador | 1 | 3 a 5.3 VDC | $2.000 | https://afel.cl/products/motor-vibrador-pwm-switch-dc |
| Mini humidificador USB tipo C de 5V | Actuador | 1 | 5V | $ 5.900 | https://www.tienda8.cl/mas-productos/humidificador-aire-domestico-generador-de-niebla-usb-5v-diy |
| Micro Servomotor SG90 | Actuador | 1 |  3 a 7.2 V | $1.990 | https://afel.cl/products/micro-servomotor-sg90 |
| Mini Parlante Altavoz de 3w | Salida audio | 1 | 3 VDC | $3.000 | https://afel.cl/products/mini-parlante-altavoz-de-3w |
| Pack Led 10mm (5) | Actuador | Varios | 1.9 a 3.2 V | $3.033 a $3.156 | https://www.electroart.cl/3376/5x-pack-led-10mm |

#### Materiales y herramientas extra

- Cautín
- Estaño
- Pasta de soldar
- Cinta aislante
- Destornillador
- Tornillos
- Cable USB C

### ⋅⋯⋯⋅ Instrucciones ⋅⋯⋯⋅

Antes de hacer funcionar el aparato hay que corroborar que este se encuentre conectado a una fuente de alimentación de 5V aprox. con un cable tipo USB C  (computador o corriente con un adaptador). Para saber si está encendido basta con ver si se enciende un led.

1. Ponerse frente a la máquina y sujetar la manibela.
2. Girar la manivela en sentido horario.
3. Ver cómo las luces se encienden progresivamente y escuchar el sonido que indica haber avanzado 1 nivel.
4. Seguir girando de forma continua. 


### ⋅⋯⋯⋅ Contexto de uso ⋅⋯⋯⋅

Esta máquina está para ser pensada como un "Artículo de broma". 

***

## Desarrollo circuito

Texto

### ⋅⋯⋯⋅ Construcción ⋅⋯⋯⋅

Texto

### ⋅⋯⋯⋅ Código ⋅⋯⋯⋅

Texto

***
/
⚡︎ ⋆.˚
