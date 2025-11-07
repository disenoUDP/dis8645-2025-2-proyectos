# sesion-12a
## ENCARGO 

**𓇢𓆸** Definir 2 objetos (según la referencia dada en el libro de Harman publicada en discord). Sacar 15 cualidades de cada uno. Mientras más raras, mejor.

![Pagina del libro](./imagenes/HARMAN.jpg)

> ✿ Un objeto se define como cualquier entidad que tiene una forma de existencia unitaria, sin importar su tamaño, duración, tipo o realidad material. Esto significa que un átomo, una montaña, una canción o un personaje de ficción pueden considerarse objetos

1. **Una fotografía**
- Muestra un momento que ya no existe.
- Puede deteriorarse con el tiempo (se decolora, se raya, se dobla).
- Tiene una textura física (papel, brillo).
- Su significado depende del contexto o de quién la mire.
- Puede reproducirse en infinitas copias idénticas.
- Congela movimiento y lo convierte en apariencia de quietud.
- Refleja luz al ser observada, igual que los objetos que representa.
- Puede despertar emociones aunque no se entienda su contenido.
- Su tamaño afecta la forma en que se percibe (una miniatura no impacta igual que un póster).
- Tiene un reverso que también puede contener información (fecha, notas, marcas).
- Puede perder parte de su información visual con el paso de los años.
- Puede existir en formato físico o digital sin dejar de ser la misma imagen.
- A veces muestra detalles que el fotógrafo no vio al tomarla.
- Puede tener valor sentimental, histórico o documental.
- Representa un objeto o persona, pero es también un objeto en sí misma.

2. **Una lágrima**
- Existe solo unos segundos antes de caer.
- Lleva consigo sabor salado.
- Deja pasar la luz, pero distorsionada.
- Para un ojo puede ser liviana, pero emocionalmente pesa toneladas.
- Nace del calor del cuerpo.
- Al caer, se vuelve una esfera mínima.
- Contiene un momento entero comprimido en una gota.
- Devuelve el rostro del que llora, aunque deformado.
- Muchas veces no suena, pero se siente.
- Escapa del control, aunque intentes contenerla.
- Es prueba de algo que no se puede decir con palabras.
- A veces necesaria para cerrar o abrir algo.
- Limpia lo que duele.
- Puede evaporarse sin dejar rastro.
- Todos los seres vivos líquidos la entienden.


**𓇢𓆸** ⁠Junto al grupo, hacer una lluvia de ideas de máquinas sentimentales (máquinas que trabajan con emociones/sensaciones/afectos específicos), y decidir entre ustedes las más interesantes. No pensar en sensores o actuadores específicos aún.


### 𖤐 **Máquina de la Ansiedad**

Emociones: Inquietud, anticipación, tensión.

Concepto: Se mueve o vibra irregularmente como si estuviera esperando algo. Reacciona a la presencia de algo cercano; cuando alguien se aproxima, empieza a tiritar más y cuando la persona se aleja recién empieza a calmarse.

No entiende la diferencia entre cuidado y amenaza, cualquier estímulo lo puede alterar.

Metáfora del cuerpo ansioso incluso en “calma” siempre siente que algo podría salir mal.

── .✦

✦ **MATERIALES**

- Placa arduino uno + cable (ya la tenemos)
- Protoboard.
- Cables

⋆ **Actuadores**: 
- Motor vibrador PWM Switch DC: actuador que generará la vibración/temblor. (https://afel.cl/products/motor-vibrador-pwm-switch-dc)
- Módulo Mosfet IRF520: Módulo de potencia para encender y apagar el motor y controlar su intensidad (PWM). (https://afel.cl/products/modulo-mosfet-irf520)

⋆ **Sensores**:
- Sensor Ultrasonico HC-SR04: para medir la distancia y detectar cuándo alguien se acerca o se aleja. (https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)

> Para carcasa, un material ligero y resonante amplificará el efecto de la vibración.

La idea es que la máquina siempre tenga una tensión de fondo, así que al inicio solo tendrá una vibración mínima y constante (un valor bajo de PWM) para simular esa calma que nunca es total en un cuerpo ansioso. En el momento en que alguien se acerca (y el sensor ultrasónico lo detecta), la máquina entra inmediatamente en un estado de inquietud creciente: la vibración no debe subir de forma lineal, sino con picos erráticos y acelerados, como si estuviera tiritando más y más a medida que la persona se acerca. Si la persona llega a la máxima proximidad, la máquina tiene que ir al pico de pánico y disparar la vibración a su máximo (PWM 255). Luego, la clave es cuando la persona se aleja, la vibración no debe detenerse de golpe, sino que tiene que ir disminuyendo de manera lenta y prolongada, mostrando que el cuerpo no se relaja al instante y que la tensión residual permanece por un tiempo, incluso cuando el "peligro" ya pasó. 

### 𖤐 **Máquina de Vergüenza**

Emociones: Incomodidad y rechazo.

Concepto: No soporta ser observada. Cuando detecta una presencia o algo de atención gira sigilosamente y se oculta o se apaga. Si nadie la mira empezará a moverse de manera tímida o a emitir una luz tenue, como si disfrutara del anonimato.
Tiene una personalidad introspectiva que teme y prefiere pasar desapercibida. Representa la incomodidad de ser visto, evitando la exposición.

── .✦

✦ **MATERIALES**

- Placa arduino uno + cable (ya la tenemos)
- Protoboard.
- Cables

⋆ **Sensor**:
- Sensor Ultrasónico (HC-SR04): medir la distancia y reaccionar a la presencia de algo cercano. (https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)

⋆ **Actuadores**: 
- Micro Servomotor SG90: para el movimiento sigiloso de ocultamiento y el movimiento tímido en anonimato. (https://afel.cl/products/micro-servomotor-sg90)
- Diodo Led (Rojo o color deseado): Para emitir esa luz tenue y tímida cuando está sola. Usar función analogWrite (PWM) para controlar brillo y simular el disfrute del anonimato. (https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes)
- Resistencia de 220 para proteger el LED. (https://afel.cl/products/kit-600-resistencias-1-4w-30-valores)

La Máquina de la Vergüenza opera en dos estados fundamentales: el Anonimato y el Rechazo. En su estado predeterminado de Anonimato (cuando el sensor Ultrasónico detecta una distancia máxima), la máquina esta tranquila; el LED emite una luz tenue controlada por PWM, y el Servomotor realiza un movimiento muy lento y tímido. Cuando el sensor de proximidad detecta la presencia de una persona, se activa inmediatamente el estado de Rechazo: el motor ejecuta un movimiento rápido y sigiloso para llevar la máquina a su posición de ocultamiento, mientras que el LED se apaga abruptamente para pasar desapercibida. La máquina solo retornará al estado de Anonimato lentamente y tras un breve periodo de latencia una vez que la presencia se haya retirado, volviendo a su forma inicial.

### 𖤐 **Máquina de malentendido**

Emociones: Confusión, extrañeza, desconexión.

Concepto: Intenta comunicarse, pero siempre dice algo distinto de lo que se espera. Si la saludas, responde con una pausa larga o un sonido sin mucho sentido. Sus respuestas nunca coinciden con lo que le comunica el usuario, no entendería los códigos humanos.


### 𔘓 𖤐 **Máquina negadora**

Emociones: Negación, tristeza, vulnerabilidad.

Concepto: Normalmente finge que todo está bien; emite sonidos alegres, colores, se mueve, pero cuando nadie la está mirando se detiene y cambia completamente, se vuelve oscura o emite sonidos raros o poco perceptibles

Su reacción cambiaria según la atención que recibe, frente a otros se “controla” y al quedarse sola se deja caer.

### 𖤐 **Objeto del Consuelo** 

Emociones: Cuidado, contención.

Concepto: Detecta el contacto de dos personas al mismo tiempo y cuando ambos se tocan se comienza a encender una luz cálida. Si alguna de las 2 personas se va; comienza a apagarse lentamente, como si lamentara la separación.

### 𖤐 **Máquina de la Confianza - Cuidado, ternura**

Emociones: Cuidado, ternura.

Solo reacciona después de varias interacciones, al principio desconfía, luego se abre con una luz cálida. Máquina de “traducción de intenciones”

Reacciona distinto según el tipo de acercamiento (brusco o suave). No responde al “qué”, sino al “cómo”.

### 𔘓 𖤐 **El Traductor de las Intenciones**

Reacciona distinto según el tipo de acercamiento (brusco o suave). No responde al “qué”, sino al “cómo”.

### 𖤐 **El Mecanismo de la Autoexplotación - Agotamiento emocional**  

Cuanto más la usas o interactúas con ella, más rápido se deteriora. Representa al cuerpo o mente que no sabe descansar.

### 𔘓 𖤐 **LATENCIA — Máquina de la Melancolía**

> Latencia:  retraso que ocurre entre una acción y su respuesta, comúnmente medido en milisegundos
Emociones: Sensible, afectiva, vulnerable, pausada, introspectiva.

Concepto: Una máquina que extraña, aunque nunca tuvo nada que perder. Reacciona ante la presencia de una persona pero su función principal es recordar lo que se ha perdido. Cada vez que alguien la toca, emitirá una luz tenue y mostrará una palabra suelta o frase incompleta, como si intentara reconstruir algo que ya no está.

Su comportamiento transmite una emoción contenida: no brilla intensamente, no busca llamar la atención. En cambio, parpadea lentamente, simulando un recuerdo que se niega a desaparecer.

Cuando no hay contacto, entra en un estado de reposo, donde la luz late suavemente, manteniendo una sensación de espera. No comprende el significado del gesto humano, pero lo guarda, y lo transforma en memoria.


