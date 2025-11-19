# sesion-13a
## CLASE 04.11.25
* Se tomaron decisiones sobre qué máquinas realizaremos, los profesores nos comentaron que sería interesante tener la máquina de ansiedad + la de la verguenza interactuando entre ellas, ya que tienen un comportamiento parecido ante la cercanía con una presencia. Sería una interacción entre ellas y no con el usuario en sí. ¿Hay que configurarlas internamente para que interactúen, o será solo por proximidad (sensor ultrasónico)?

### 𓆩♱𓆪  **MÁQUINA DE LA ANSIEDAD:**
- **Emociones**: Inquietud, anticipación, tensión.
- **Concepto**: Se mueve o vibra irregularmente como si estuviera esperando algo. Reacciona a la presencia de algo cercano; cuando alguien se aproxima, empieza a tiritar más y cuando la persona se aleja recién empieza a calmarse.
- No entiende la diferencia entre cuidado y amenaza, cualquier estímulo lo puede alterar.
- Metáfora del cuerpo ansioso incluso en “calma” siempre siente que algo podría salir mal.

⋆. 𐙚 ˚ **MATERIALES:**

- Placa arduino uno + cable (ya la tenemos)
- Protoboard.
- Cables

Actuadores:
  * Motor vibrador PWM Switch DC: actuador que generará la vibración/temblor. (https://afel.cl/products/motor-vibrador-pwm-switch-dc) **Nos enteramos después que este modelo viene con módulo mosfet incluído**
  
  * Módulo Mosfet IRF520: Módulo de potencia para encender y apagar el motor y controlar su intensidad (PWM). (https://afel.cl/products/modulo-mosfet-irf520)

Sensores:
* Sensor Ultrasonico HC-SR04: para medir la distancia y detectar cuándo alguien se acerca o se aleja. (https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)
> Para carcasa, un material ligero y resonante amplificará el efecto de la vibración.

La idea es que la máquina siempre tenga una tensión de fondo, así que al inicio solo tendrá una vibración mínima y constante (un valor bajo de PWM) para simular esa calma que nunca es total en un cuerpo ansioso. En el momento en que alguien se acerca (y el sensor ultrasónico lo detecta), la máquina entra inmediatamente en un estado de inquietud creciente: la vibración no debe subir de forma lineal, sino con picos erráticos y acelerados, como si estuviera tiritando más y más a medida que la persona se acerca. Si la persona llega a la máxima proximidad, la máquina tiene que ir al pico de pánico y disparar la vibración a su máximo (PWM 255). Luego, la clave es cuando la persona se aleja, la vibración no debe detenerse de golpe, sino que tiene que ir disminuyendo de manera lenta y prolongada, mostrando que el cuerpo no se relaja al instante y que la tensión residual permanece por un tiempo, incluso cuando el "peligro" ya pasó.


### 𓆩♱𓆪 MÁQUINA DE VERGÜENZA:
- **Emociones:** Incomodidad y rechazo.
- **Concepto:** No soporta ser observada. Cuando detecta una presencia o algo de atención gira sigilosamente y se oculta o se apaga. Si nadie la mira empezará a moverse de manera tímida o a emitir una luz tenue, como si disfrutara del anonimato. Tiene una personalidad introspectiva que teme y prefiere pasar desapercibida. Representa la incomodidad de ser visto, evitando la exposición.

⋆. 𐙚 ˚ **MATERIALES:**

- Placa arduino uno + cable (ya la tenemos)
- Protoboard.
- Cables

Sensor:

* Sensor Ultrasónico (HC-SR04): medir la distancia y reaccionar a la presencia de algo cercano. (https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)

Actuadores:

* Micro Servomotor SG90: para el movimiento sigiloso de ocultamiento y el movimiento tímido en anonimato. (https://afel.cl/products/micro-servomotor-sg90)
* Diodo Led (Rojo o color deseado): Para emitir esa luz tenue y tímida cuando está sola. Usar función analogWrite (PWM) para controlar brillo y simular el disfrute del anonimato. (https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes) **TERMINAMOS CAMBIANDOLO EL DIODO LED POR DIODO RGB.**
* Diodo Led RGB 5mm: para alternar entre colores alegres (simulación) y el apagado/colores oscuros (vulnerabilidad). (https://afel.cl/products/diodo-led-rgb-5mm)E
* Resistencia de 220 para proteger el LED. (https://afel.cl/products/kit-600-resistencias-1-4w-30-valores)

La Máquina de la Vergüenza opera en dos estados fundamentales: el Anonimato y el Rechazo. En su estado predeterminado de Anonimato (cuando el sensor Ultrasónico detecta una distancia máxima), la máquina esta tranquila; el LED emite una luz tenue controlada por PWM, y el Servomotor realiza un movimiento muy lento y tímido. Cuando el sensor de proximidad detecta la presencia de una persona, se activa inmediatamente el estado de Rechazo: el motor ejecuta un movimiento rápido y sigiloso para llevar la máquina a su posición de ocultamiento, mientras que el LED se apaga abruptamente para pasar desapercibida. La máquina solo retornará al estado de Anonimato lentamente y tras un breve periodo de latencia una vez que la presencia se haya retirado, volviendo a su forma inicial.

> Inspiradas en la relación entre interacción humana y emoción contenida, estas máquinas exploran la materialización de sentimientos a través del comportamiento lumínico y la respuesta táctil. Ambas funcionan como pequeños organismos emocionales que, aunque digitales, imitan la forma en que los humanos recuerdan, esperan y sienten.
