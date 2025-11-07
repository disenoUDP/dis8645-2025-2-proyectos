# sesion-12b ⋆ 𐙚 ̊.

# ✦ ENCARGO 19 — Prototipos Emocionales Interactivos  

Este encargo propone el desarrollo de objetos sensibles capaces de transmitir emociones humanas mediante su comportamiento lumínico, táctil o sonoro.  
Cada propuesta busca materializar una emoción específica —como la contención, la ansiedad o la melancolía— explorando el vínculo entre el cuerpo humano y la respuesta de una máquina.  

A través del uso de sensores, actuadores y programación básica en Arduino, se experimenta con la idea de una “máquina emocional”, capaz de reaccionar ante la presencia o ausencia del otro.  

────୨ৎ────
## 𖤐 Objeto del Consuelo  
**Emociones:** Cuidado, contención.  

**Concepto:**  

Detecta el contacto de dos personas al mismo tiempo y cuando ambos se tocan, comienza a encender una luz cálida.  
Si alguna de las dos personas se va, la luz se apaga lentamente, como si lamentara la separación.  
Representa la necesidad humana de conexión y cómo la presencia compartida puede encender algo más que solo luz: el confort de no estar solo.

── .✦ ✦ **MATERIALES**  
+ Placa Arduino Uno + cable (ya disponible)  
+ Protoboard  
+ Cables
  
⋆ **Sensor:**  

+ Sensor táctil capacitivo TTP223: detecta el contacto simultáneo de dos personas.  
  [https://afel.cl/products/modulo-sensor-tactil-ttp223](https://afel.cl/products/modulo-sensor-tactil-ttp223)
  
⋆ **Actuadores:**

+ Diodo LED cálido: emite la luz de contención al detectar contacto.  
  [https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes](https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes)  
+ Resistencia 220Ω para proteger el LED.  
  [https://afel.cl/products/kit-600-resistencias-1-4w-30-valores](https://afel.cl/products/kit-600-resistencias-1-4w-30-valores)  

**Comportamiento:**  

El *Objeto del Consuelo* opera en dos estados principales: **Presencia Compartida** y **Ausencia**.  
+ En **Presencia Compartida**, cuando ambos sensores detectan contacto simultáneo, el LED cálido se enciende de forma progresiva, simulando el calor del afecto mutuo.  
+ En **Ausencia**, si uno de los contactos se interrumpe, la luz se desvanece lentamente, generando una sensación de melancolía y despedida.  

El brillo del LED se controla mediante *analogWrite (PWM)*, permitiendo una transición suave que refuerza la metáfora emocional de la conexión y el desapego.

────୨ৎ────

## 𔘓 𖤐 LATENCIA — Máquina de la Melancolía  
**Latencia:** retraso que ocurre entre una acción y su respuesta, comúnmente medido en milisegundos.  
**Emociones:** Sensible, afectiva, vulnerable, pausada, introspectiva.  

**Concepto:**  

Una máquina que extraña, aunque nunca tuvo nada que perder. Reacciona ante la presencia de una persona, pero su función principal es recordar lo que se ha perdido.  
Cada vez que alguien la toca, emitirá una luz tenue y mostrará una palabra suelta o frase incompleta, como si intentara reconstruir algo que ya no está.  

Su comportamiento transmite una emoción contenida: no brilla intensamente, no busca llamar la atención.  
En cambio, parpadea lentamente, simulando un recuerdo que se niega a desaparecer.  
Cuando no hay contacto, entra en un estado de reposo donde la luz late suavemente, manteniendo una sensación de espera.  
No comprende el significado del gesto humano, pero lo guarda y lo transforma en memoria.

── .✦ ✦ **MATERIALES**  

+ Placa Arduino Uno + cable (ya disponible)  
+ Protoboard  
+ Cables
  
⋆ **Sensores:**  

+ Sensor de proximidad infrarrojo: detecta la presencia del usuario.  
  [https://afel.cl/products/sensor-infrarrojo-de-proximidad](https://afel.cl/products/sensor-infrarrojo-de-proximidad)
  
⋆ **Actuadores:**  

+ Diodo LED blanco cálido: parpadea en patrones lentos y variables.  
  [https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes](https://afel.cl/products/kit-50-diodos-leds-de-5mm-ultrabrillantes)  
+ Pantalla LCD 16x2: muestra palabras sueltas o frases incompletas.  
  [https://afel.cl/products/modulo-lcd-16x2](https://afel.cl/products/modulo-lcd-16x2)  
+ Resistencia 220Ω (para LED).  
  [https://afel.cl/products/kit-600-resistencias-1-4w-30-valores](https://afel.cl/products/kit-600-resistencias-1-4w-30-valores)  

**Comportamiento:**  

La *Máquina de la Melancolía* tiene tres estados fundamentales: **Reposo**, **Recuerdo** y **Latencia**.  
+ En **Reposo**, la luz parpadea de manera tenue y cíclica, como si respirara lentamente.  
+ En **Recuerdo**, al detectar contacto, muestra palabras fragmentadas en la pantalla y emite un brillo suave; simula la evocación de una memoria incompleta.  
+ En **Latencia**, tras la pérdida del contacto, permanece un instante encendida, recordando el gesto antes de volver a su respiración luminosa inicial.  

────୨ৎ────

## 𖤐 Máquina de la Ansiedad  
**Emociones:** Inquietud, anticipación, tensión.  

**Concepto:**  

Se mueve o vibra irregularmente como si estuviera esperando algo.  
Reacciona a la presencia de algo cercano; cuando alguien se aproxima, empieza a tiritar más, y cuando la persona se aleja recién empieza a calmarse.  
La máquina siempre mantiene una vibración mínima de fondo, representando la imposibilidad de un descanso completo en un cuerpo ansioso.

── .✦ ✦ **MATERIALES**  

+ Placa Arduino Uno + cable (ya disponible)  
+ Protoboard  
+ Cables
  
⋆ **Sensor:**  

+ Sensor ultrasónico HC-SR04: detecta la distancia de una persona u objeto cercano.  
  [https://afel.cl/products/sensor-de-ultrasonico-hc-sr04](https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)
  
⋆ **Actuadores:**  

+ Motor vibrador PWM Switch DC: genera la vibración/temblor de la máquina.  
  [https://afel.cl/products/motor-vibrador-pwm-switch-dc](https://afel.cl/products/motor-vibrador-pwm-switch-dc)  
+ Módulo Mosfet IRF520: controla la potencia del motor y permite variar la intensidad mediante PWM.  
  [https://afel.cl/products/modulo-mosfet-irf520](https://afel.cl/products/modulo-mosfet-irf520)  

**Comportamiento:**  

La máquina parte con una vibración mínima constante (PWM bajo), simulando una calma tensa.  
Cuando el sensor detecta una proximidad creciente, la vibración aumenta de forma errática, con picos de intensidad que representan el estado de ansiedad.  
Al alcanzar la distancia mínima, la máquina entra en un *pico de pánico* con PWM máximo (255).  
Cuando la persona se aleja, la vibración disminuye lentamente, mostrando que la tensión no desaparece de inmediato, sino que se disipa con dificultad.

────୨ৎ────

## 𔘓 𖤐 Máquina Negadora  
**Emociones:** Simulación, vulnerabilidad, dualidad.  

**Concepto:**  

Exhibe dos comportamientos opuestos según la presencia de un observador.  
Cuando alguien se acerca, la máquina “actúa”: se ilumina con colores vivos, suena alegre y se mantiene erguida.  
Pero al quedar sola, se desploma, las luces se apagan y los sonidos se vuelven disonantes.  
Representa la idea de “mantener el control frente a otros” y “dejarse caer” cuando nadie observa.

── .✦ ✦ **MATERIALES**  

+ Placa Arduino Uno + cable (ya disponible)  
+ Protoboard  
+ Cables
  
⋆ **Sensor:**  

+ Sensor ultrasónico HC-SR04: detecta la presencia y distancia del observador.  
  [https://afel.cl/products/sensor-de-ultrasonico-hc-sr04](https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)
  
⋆ **Actuadores:**  

+ Diodo LED RGB 5mm: alterna entre colores alegres y oscuros.  
  [https://afel.cl/products/diodo-led-rgb-5mm](https://afel.cl/products/diodo-led-rgb-5mm)  
+ Buzzer Pasivo Solo: genera sonidos melódicos o disonantes según el estado.  
  [https://afel.cl/products/buzzer-pasivo-solo](https://afel.cl/products/buzzer-pasivo-solo)  
+ Micro Servomotor SG90: simula el control (posición erguida) y la caída (desplome).  
  [https://afel.cl/products/micro-servomotor-sg90](https://afel.cl/products/micro-servomotor-sg90)  
+ Resistencias 220Ω (x3 para cada color del LED RGB).  
  [https://afel.cl/products/kit-600-resistencias-1-4w-30-valores](https://afel.cl/products/kit-600-resistencias-1-4w-30-valores)  

**Comportamiento:**  

La máquina alterna entre los estados de **Simulación** y **Vulnerabilidad**.  
+ En **Simulación**, cuando el sensor detecta presencia, el LED RGB emite colores vivos, el buzzer toca una melodía alegre y el servomotor mantiene la posición erguida.  
+ En **Vulnerabilidad**, al perder la presencia, el LED cambia a tonos apagados o se apaga, el buzzer emite pulsos disonantes y el servomotor deja caer el cuerpo del objeto.  

Esta rápida alternancia refleja el desgaste emocional de mantener una imagen frente a otros, revelando la fragilidad que se esconde detrás del control.

────୨ৎ────

✦ ✦ ✦  
Inspiradas en la relación entre *interacción humana y emoción contenida*, estas máquinas exploran la materialización de sentimientos a través del comportamiento lumínico, sonoro y físico.  
Cada una propone una lectura distinta de la vulnerabilidad: desde la calma compartida del consuelo hasta la tensión constante de la ansiedad.  


