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


