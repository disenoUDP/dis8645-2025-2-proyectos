# Máquina de la Ansiedad (Versión Final)

## Resumen conceptual
La Máquina de la Ansiedad representa **inquietud, anticipación y tensión constante**.  
Incluso en reposo mantiene un leve temblor, y su vibración aumenta de forma progresiva y errática a medida que un objeto (o la Máquina de la Vergüenza) se aproxima.

Su comportamiento es **orgánico**, gracias al uso de:
- **Filtro suavizador**, que evita cambios bruscos no deseados.
- **Jitter**, que introduce variaciones aleatorias naturales.
- **Picos de ansiedad**, que simulan imprevisibilidad emocional.

---

## Materiales
- Arduino UNO + cable USB  
- Sensor ultrasónico **HC-SR04**  
- Motor vibrador DC (motor de vibración tipo joystick)  
- LED RGB **ánodo común** (solo se usan los canales **R + B** para generar morado)  
- Resistencias para cada canal del LED  
- Protoboard y cables  
- (Opcional) Fuente externa si el motor requiere más de 200 mA

**Enlaces de referencia:**
- HC-SR04: https://afel.cl/products/sensor-de-ultrasonico-hc-sr04  
- Motor vibrador: https://afel.cl/products/motor-vibrador-pwm-switch-dc  

---

## Conexión (pines por defecto)

### Sensor ultrasónico HC-SR04
- **TRIG → D2**  
- **ECHO → D3**

### Motor vibrador
- **PWM → D5**

### LED RGB (ánodo común)
- **R → D9**  
- **B → D6**  
- **Ánodo común → 5V** (IMPORTANTE: siempre con resistencias en cada canal)

*(El canal G no se usa en esta versión.)*

---

## Funcionamiento técnico
- Mide distancia entre **5 y 100 cm** mediante HC-SR04.
- Aplica un **filtro suavizado (EMA)** para obtener un valor estable sin ruido abrupto.
- Agrega **jitter aleatorio** para evitar que el comportamiento sea rígido o mecánico.
- Introduce picos aleatorios poco frecuentes para simular crisis breves.
- Mapea la distancia a un nivel de vibración **no lineal**, más intenso a menor distancia.
- Controla el motor mediante PWM y mantiene el LED en morado fijo.

---

## ¿Por qué se usa jitter?
El jitter introduce pequeñas variaciones aleatorias controladas que ayudan a que:
- El movimiento no sea repetitivo.
- La vibración tenga un carácter más humano/biológico.
- Se eviten patrones rígidos típicos de máquinas digitales.
- El comportamiento emocional se perciba más real y expresivo.

---

## Notas de seguridad
- Si el motor consume más de **200 mA**, usar una fuente externa y un MOSFET/driver.  
- No conectar motores directamente al pin del Arduino sin verificar consumo.  
- Añadir condensador de desacoplo cerca del motor para evitar caídas de voltaje.  
- Si corresponde, usar diodo flyback (según tipo de motor/driver).

---

## Referencias bibliográficas

### Hardware
- **HC-SR04 Ultrasonic Sensor Datasheet**  
  https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf   
- **Arduino UNO Technical Specifications**  
  https://docs.arduino.cc/hardware/uno-rev3/  
- **PWM en Arduino — analogWrite() Reference**  
  https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/  
- **Control seguro de motores DC (MOSFET + Diodo Flyback)**  
  https://www.pololu.com/docs/0J23/9  

### Conceptos utilizados
- **Filtro Exponential Moving Average (EMA)**  
  https://en.wikipedia.org/wiki/Moving_average#Exponential_moving_average  
- **Jitter y ruido en procesamiento de señales**  
  https://en.wikipedia.org/wiki/Jitter  
- **RandomSeed usando ruido analógico (técnica Arduino)**  
  https://www.arduino.cc/reference/en/language/functions/random-numbers/randomseed/  

### Referencias artísticas
- **Zimoun — referencia conceptual sonora y mecánica**  
  http://zimoun.net/


---

## Qué rescatamos de cada referente

- **HC-SR04 Datasheet** — Ayuda a entender cómo funciona el sensor, su rango real y qué tiempos necesita para medir bien. Básicamente, me dice qué puede y qué no puede hacer.
- **Arduino UNO Specs** — Sirve para no sobrepasar los límites eléctricos del Arduino y evitar quemar la placa o el motor.
- **analogWrite() / PWM** — Explica cómo controlar la intensidad del motor. Gracias a esto podemos hacer que la vibración sea suave o fuerte, no solo encendida o apagada.
- **Control de motores con MOSFET y diodo** — Se aprende por qué no debemos conectar un motor directo a un pin y cuál es la forma correcta de proteger la placa.
- **EMA (filtro suavizado)** — Ayudó a entender cómo suavizar las lecturas del sensor, que al inicio eran muy inestables.
- **Jitter** — Justifica por qué agregamos variación aleatoria. Así la vibración no se siente robótica, sino más natural.
- **RandomSeed con ruido analógico** — Explica cómo generar números realmente aleatorios y evitar patrones repetidos en el comportamiento.
- **Zimoun** — Un referente artístico que inspira el uso de vibración mecánica repetitiva para generar comportamientos que parecen vivos o expresivos.

---