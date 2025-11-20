# grupo-02 - Gatolate ₊˚⊹ᰔ

**Integrantes:**  
- 01-antokiaraa
- 16-javieramoraga-rgb
- 18-ppia97

## Introducción .☘︎ ݁˖

Este proyecto surge desde la idea de crear **máquinas emocionales**, es decir, dispositivos que no buscan cumplir una función práctica, sino expresar una emoción a través del comportamiento físico: movimiento, luz, ritmo y tiempo.

Durante el taller, experimentamos con la idea de transformar emociones en acciones corporales de una máquina. En lugar de explicarlas con palabras, exploramos cómo una emoción puede **manifestarse físicamente**, como ocurre en una máquina que saluda, o un poema que reacciona al entorno.

Siguiendo esa lógica, diseñamos dos pequeñas máquinas que reaccionan a la presencia del usuario como si **sintieran algo**, sin hablar, solo comportándose.

Elegimos dos emociones silenciosas, difíciles de verbalizar, pero muy evidentes cuando se observan en un cuerpo: **Ansiedad** y **Vergüenza.**


## Significado de emociones .☘︎ ݁˖

### ⤷ Ansiedad:
> Es un estado de **anticipación y alerta constante**. No siempre ocurre algo, pero el cuerpo actúa como si algo estuviera por pasar. Se manifiesta en forma de tensión, latido rápido, vibración o inquietud permanente. No descansa del todo.

### ⤷ Vergüenza:
> Es el sentimiento que aparece cuando uno **se siente observado**. El cuerpo solo quiere esconderse, apagarse o evitar la mirada. No busca llamar la atención, sino desaparecer.


Estas emociones casi nunca se explican hablando; se expresan **con gestos, posturas y reacciones corporales**. Por eso, nuestras máquinas **no hablan, se comportan.**



### Máquina de la Ansiedad ᵎᵎ

Representa un cuerpo que **nunca consigue estar completamente quieto**.

- Vibra constantemente, incluso cuando no hay nadie cerca (motor N20 controlado con MOSFET).
- Cuando detecta aproximación (sensor ultrasónico), la vibración aumenta y el LED late más rápido, simulando un corazón nervioso.
- Al alejarse la persona, no vuelve inmediatamente a la calma: mantiene vibraciones leves, simulando el *residuo de tensión*.


──── ୨୧ ────


### Máquina de la Vergüenza ᵎᵎ
Representa un cuerpo que **prefiere no ser observado**.

- Cuando no hay nadie cerca, permanece encendida con luz suave y movimientos muy leves.
- Si alguien se acerca, la máquina apaga su LED y gira repentinamente con el servomotor, como un gesto de evasión.
- No vuelve a activarse inmediatamente. Espera antes de volver a mostrarse, como quien necesita tiempo para recuperarse después de sentirse observado.



### Relación emocional entre ambas .☘︎ ݁˖

Aunque funcionan por separado, comparten una lógica emocional:

| Situación | Reacción esperada |
|-----------|--------------------|
| La vergüenza se esconde | La ansiedad aumenta |
| La ansiedad se agita | La vergüenza se intensifica |

> No conversan entre sí, pero **se afectan emocionalmente**, igual que las personas.


## Planificación y proceso previo 𓏲 ๋࣭ ࣪ ˖🎐

Durante el proyecto, utilizamos una planificación modular por etapas. Aunque la Carta Gantt fue diseñada inicialmente, el cronograma fue ajustándose, ya que algunas decisiones técnicas (como el cambio de motor y uso de MOSFET) surgieron en etapas avanzadas.

![cartagantt](./imagenes/cartagantt.jpeg)

### Etapas de trabajo

**1. Exploración conceptual**
- Investigación sobre emociones y cómo se manifiestan físicamente.
- Selección de Ansiedad y Vergüenza como emociones principales.
- Primeras ideas sobre cómo traducirlas en gestos mecánicos (temblor, giro, luz).

**2. Definición de componentes y posibles comportamientos**
- Búsqueda de actuadores que representaran físicamente cada emoción.
- Vergüenza → servomotor (giro evasivo) y LED que se apaga.
- Ansiedad → motor vibrador (luego reemplazado por motor N20 con MOSFET) y LED con pulso irregular.

**3. Primer prototipo técnico**
- Pruebas individuales de cada componente: sensor ultrasónico, servo, LED, motor vibrador.
- Primera programación básica de reacción a distancia.
- Problemas con la intensidad del motor vibrador → se detecta que no es suficiente.

**4. Redefinición técnica y compra de componentes**
- Se decide reemplazar el motor vibrador por un **micromotor N20** más potente.
- Se integra **MOSFET IRF520** (o equivalente) para controlar el motor con PWM.
- Ajustes en el diseño del código y reorganización del circuito.

**5. Integración de comportamientos emocionales**
- Ansiedad: implementación de vibración basal y vibración errática según cercanía.
- Vergüenza: programar apagado de color y giro evasivo.
- Se incorpora “residuo emocional”: tiempo de espera antes de calmarse.

**6. Montaje físico**
- Impresión 3D de piezas y pruebas de ensamblaje (cabeza de gatito para el ultrasónico).
- Consideración de caja como escondite emocional.
- Problemas iniciales con medidas y material (resina vs filamento).

**7. Pruebas de interacción y ajustes**
- Ajustes manuales de ángulos del servo.
- Ajuste de distancias mínimas y máximas para que cada máquina reaccione como se espera.
- Verificación de respuesta emocional (tiempo de reacción, intensidad, latencia).

**8. Documentación y preparación de entrega**
- Organización de bitácoras individuales.
- Redacción del informe final (este documento).
- Preparación de exposición.


──── ୨୧ ────


### Decisiones clave que modificaron el proyecto

| Problema | Cambio realizado |
|----------|------------------|
| Motor vibrador no tenía fuerza | Se reemplaza por motor N20 + MOSFET |
| Biblioteca NewPing incompatibilidad | Se decide usar lógica estándar de duración de pulso |
| Carcasa en resina rígida sin movilidad | Se decide pasar a impresión en filamento |
| Intensidad de gir muy brusca | Se ajusta PWM y delay para suavizar la respuesta |


──── ୨୧ ────


## Pseudocódigo Explicado ₊˚⊹ᰔ

### Componentes utilizados 

| Máquina   | Componentes principales | Función emocional                         |
|-----------|------------------------|-------------------------------------------|
| Ansiedad  | Sensor ultrasónico, motor DC N20 con MOSFET, LED RGB | Detecta cercanía, vibra, simula ritmo cardíaco |
| Vergüenza | Sensor ultrasónico, servomotor SG90, LED RGB | Detecta observación, se gira y apaga |



### Pseudocódigo — Máquina Ansiedad ⚡︎

```plaintext
INICIO

Definir pinSensorTrig = 2
Definir pinSensorEcho = 3
Definir pinLED = 9
Definir pinMotor = 5

Configurar pines como entrada o salida

Mientras la máquina está encendida:

  Leer distancia usando sensor ultrasónico

  Si distancia < 30 cm:
      // Ansiedad activa
      Aumentar PWM del motor (vibración fuerte)
      Aumentar velocidad de parpadeo del LED
      Guardar último tiempo en que se detectó presencia
  
  Sino si distancia >= 30 cm Y (tiempo desde la última detección < tiempo de residuo):
      // Ansiedad residual
      Mantener vibración leve (PWM medio-bajo)
      LED parpadea lento
  
  Sino:
      // Estado basal
      Vibración muy leve
      LED mantiene pulso lento

Fin

```


### Pseudocódigo — Máquina Vergüenza ⚡︎

```plaintext
INICIO

Definir pinSensorTrig = 2
Definir pinSensorEcho = 3
Definir pinServo = 6
Definir pinLED = 9

Configurar pines

Mientras la máquina está encendida:

  Leer distancia desde sensor ultrasónico

  Si distancia < 30 cm:
      // Se siente observada → se esconde
      Apagar LED
      Servo gira a posición de ocultamiento (ej. 120°)
      Guardar último tiempo de detección
  
  Sino si distancia >= 30 cm Y (tiempo desde la última detección < tiempo de recuperación):
      // Sigue escondida aunque ya no la miren
      Mantener LED apagado
      Mantener servo girado
  
  Sino:
      // Nadie la observa → tímida pero presente
      Encender LED con brillo suave
      Servo vuelve lentamente a posición inicial (ej. 0°)

Fin
```

────୨ৎ────


### Explicación del comportamiento emocional 𓏲 ๋࣭ ࣪ ˖🎐

| Estado del entorno | Máquina Ansiedad | Máquina Vergüenza |
|--------------------|------------------|-------------------|
| No hay nadie cerca | Vibra muy poco, LED lento (estado basal) | Luz tenue, servo centrado |
| Persona se acerca  | Vibra fuerte y LED acelera (alerta) | Apaga LED y se gira para esconderse |
| Persona se aleja   | Disminuye vibración lentamente (residuo emocional) | Espera antes de volver a mostrarse (recuperación emocional) |



### Idea central ๋ ࣭ ⭑

> Estas máquinas no cambian de estado inmediatamente.  
> Imitan el comportamiento emocional humano:  
> **las emociones tienen latencia, residuo y recuperación.**



