# sesion-13a

## IDEAS INICIALES

Máquina de la Ansiedad:

Emociones: Inquietud, anticipación, tensión.

Concepto: Se mueve o vibra irregularmente como si estuviera esperando algo. Reacciona a la presencia de algo cercano; cuando alguien se aproxima, empieza a tiritar más y cuando la persona se aleja recién empieza a calmarse.

No entiende la diferencia entre cuidado y amenaza, cualquier estímulo lo puede alterar.

Metáfora del cuerpo ansioso incluso en “calma” siempre siente que algo podría salir mal.

MATERIALES:

- Placa arduino uno + cable (ya la tenemos)
- Protoboard.
- Cables

Actuadores:

- Motor vibrador PWM Switch DC: actuador que generará la vibración/temblor. (https://afel.cl/products/motor-vibrador-pwm-switch-dc)
- Módulo Mosfet IRF520: Módulo de potencia para encender y apagar el motor y controlar su intensidad (PWM). (https://afel.cl/products/modulo-mosfet-irf520)

Sensores:

- Sensor Ultrasonico HC-SR04: para medir la distancia y detectar cuándo alguien se acerca o se aleja. (https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)
- Para carcasa, un material ligero y resonante amplificará el efecto de la vibración.

La idea es que la máquina siempre tenga una tensión de fondo, así que al inicio solo tendrá una vibración mínima y constante (un valor bajo de PWM) para simular esa calma que nunca es total en un cuerpo ansioso. En el momento en que alguien se acerca (y el sensor ultrasónico lo detecta), la máquina entra inmediatamente en un estado de inquietud creciente: la vibración no debe subir de forma lineal, sino con picos erráticos y acelerados, como si estuviera tiritando más y más a medida que la persona se acerca. Si la persona llega a la máxima proximidad, la máquina tiene que ir al pico de pánico y disparar la vibración a su máximo (PWM 255). Luego, la clave es cuando la persona se aleja, la vibración no debe detenerse de golpe, sino que tiene que ir disminuyendo de manera lenta y prolongada, mostrando que el cuerpo no se relaja al instante y que la tensión residual permanece por un tiempo, incluso cuando el "peligro" ya pasó.

Máquina de Vergüenza:

Emociones: Incomodidad y rechazo.

Concepto: No soporta ser observada. Cuando detecta una presencia o algo de atención gira sigilosamente y se oculta o se apaga. Si nadie la mira empezará a moverse de manera tímida o a emitir una luz tenue, como si disfrutara del anonimato. Tiene una personalidad introspectiva que teme y prefiere pasar desapercibida. Representa la incomodidad de ser visto, evitando la exposición.

MATERIALES:

- Placa arduino uno + cable (ya la tenemos)
- Protoboard.
- Cables

Sensor:

Sensor Ultrasónico (HC-SR04): medir la distancia y reaccionar a la presencia de algo cercano. (https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)

Actuadores:

- Micro Servomotor SG90: para el movimiento sigiloso de ocultamiento y el movimiento tímido en anonimato. (https://afel.cl/products/micro-servomotor-sg90)
- Diodo Led (Rojo o color deseado): Para emitir esa luz tenue y tímida cuando está sola. Usar función analogWrite (PWM) para controlar brillo y simular el disfrute del anonimato. (https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes)
- Resistencia de 220 para proteger el LED. (https://afel.cl/products/kit-600-resistencias-1-4w-30-valores)

La Máquina de la Vergüenza opera en dos estados fundamentales: el Anonimato y el Rechazo. En su estado predeterminado de Anonimato (cuando el sensor Ultrasónico detecta una distancia máxima), la máquina esta tranquila; el LED emite una luz tenue controlada por PWM, y el Servomotor realiza un movimiento muy lento y tímido. Cuando el sensor de proximidad detecta la presencia de una persona, se activa inmediatamente el estado de Rechazo: el motor ejecuta un movimiento rápido y sigiloso para llevar la máquina a su posición de ocultamiento, mientras que el LED se apaga abruptamente para pasar desapercibida. La máquina solo retornará al estado de Anonimato lentamente y tras un breve periodo de latencia una vez que la presencia se haya retirado, volviendo a su forma inicial.

Máquina negadora:

Emociones: Negación, tristeza, vulnerabilidad.

Concepto: Normalmente finge que todo está bien; emite sonidos alegres, colores, se mueve, pero cuando nadie la está mirando se detiene y cambia completamente, se vuelve oscura o emite sonidos raros o poco perceptibles

Su reacción cambiaria según la atención que recibe, frente a otros se “controla” y al quedarse sola se deja caer.

MATERIALES

- Placa arduino uno + cable (ya la tenemos)
- Protoboard.
- Cables

Sensor:

- Sensor Ultrasónico (HC-SR04): medir la distancia y reaccionar a la presencia de algo cercano, en este caso sería presencia detectada = actuación, ausencia de presencia = caída. (https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)

Actuadores:

- Diodo Led RGB 5mm: para alternar entre colores alegres (simulación) y el apagado/colores oscuros (vulnerabilidad). (https://afel.cl/products/diodo-led-rgb-5mm)
- Buzzer Pasivo Solo: Permite generar sonidos alegres (melodías) y sonidos raros/disonantes (vulnerabilidad), usariamos la función tone() de Arduino. (https://afel.cl/products/buzzer-pasivo-solo)
- Micro Servomotor SG90: Nos permite simular el "control" (posición erguida) y el "dejarse caer" (posición de desplome) de la máquina. (https://afel.cl/products/micro-servomotor-sg90)
- Para el LED RGB (enlace 1.1), necesitamos tres resistencias de 220 (una para cada color: Rojo, Verde, Azul) para conectarlo de forma segura a la placa Arduino. (https://afel.cl/products/kit-600-resistencias-1-4w-30-valores)

La máquina negadora exhibe una dualidad conductual, cuando el Sensor Ultrasónico detecta la presencia de un observador, el sistema entra en modo de simulación forzada: el LED RGB proyecta colores vivos y alegres, el Buzzer emite sonidos melódicos y consistentes, y el Servomotor mantiene el objeto en una posición estable y controlada. Esta actuación se mantiene mientras la atención esté presente. Sin embargo, al desaparecer la presencia detectada, la máquina abandona el control instantáneamente y pasa al estado de vulnerabilidad: el Servomotor ejecuta un movimiento para que el objeto se desplome o se deje caer, la luz del LED se reduce a una tonalidad oscura y tenue (o se apaga), y el sonido cambia a pulsos disonantes o frecuencias casi inaudibles. La rápida alternancia de estados, regida únicamente por la proximidad, enfatiza cómo la máquina se "controla" frente a otros y se "deja caer" al quedarse a solas.
✦ ✦ ✦
Inspiradas en la relación entre interacción humana y emoción contenida, estas máquinas exploran la materialización de sentimientos a través del comportamiento lumínico y la respuesta táctil.
Ambas funcionan como pequeños organismos emocionales que, aunque digitales, imitan la forma en que los humanos recuerdan, esperan y sienten.
