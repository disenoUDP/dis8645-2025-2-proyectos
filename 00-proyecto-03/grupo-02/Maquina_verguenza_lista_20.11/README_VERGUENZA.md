# Máquina de la Vergüenza (Versión Final)

## Resumen conceptual  
La Máquina de la Vergüenza representa **incomodidad, retraimiento y rechazo progresivo**.  
Cuando no hay nadie cerca mantiene un parpadeo cian y el servo en reposo. A medida que algo se acerca (como una persona o la Máquina de la Ansiedad), 
el servo empieza a agitarse y el LED parpadea cada vez más rápido, como una reacción nerviosa de vergüenza.  

El comportamiento se construye a partir de:  
- **Filtro suavizador** para estabilizar las mediciones de distancia.  
- **Microvariaciones reales**, por el ruido natural del sensor ultrasónico.  
- **Mapeo progresivo**: la distancia se transforma en velocidad y amplitud de movimiento.

---

## Materiales  
- Arduino UNO + cable USB  
- Sensor ultrasónico **HC-SR04**  
- Servo **SG90**  
- LED RGB ánodo común (solo **G + B** para cian)  
- Resistencias para los canales G y B  
- Protoboard y cables  

**Enlaces de referencia:**  
- HC-SR04: https://afel.cl/products/sensor-de-ultrasonico-hc-sr04  
- Servo SG90: https://www.electronicos.cl/producto/servo-sg90-tower-pro/  

---

## Conexión (pines por defecto)

### Sensor ultrasónico HC-SR04  
- **TRIG → D2**  
- **ECHO → D3**

### Servo SG90  
- **SEÑAL → D9**  
- **5V → +5 V**  
- **GND → GND**

### LED RGB (ánodo común)  
- **G → D6**  
- **B → D5**  
- **Ánodo común → 5V**  
*(Cada canal debe tener su resistencia. El canal R no se usa.)*

---

## Funcionamiento técnico  
- Mide distancia entre **5 cm y 100 cm** con el HC-SR04.  
- Usa un **filtro suavizado (EMA simple)** para suavizar las lecturas.  
- El servo se mueve con velocidad y amplitud crecientes cuando algo se acerca.  
- El LED cian parpadea más rápido al disminuir la distancia.  
- El ruido natural del sensor aporta pequeñas variaciones (no hay jitter artificial), lo que añade carácter.

---

## ¿Por qué usar un filtro suavizado?  
El filtro ayuda a que:  
- El servo no salte bruscamente por lecturas erráticas.  
- El parpadeo del LED sea más coherente y menos errático.  
- La respuesta se sienta más “emotiva” y menos digital.

---

## Notas de seguridad  
- No forzar el servo fuera de su rango (~0°–180°).  
- Proveer alimentación estable al servo para evitar comportamientos erráticos.  
- Usar resistencias en los canales del LED.  
- Asegurar conexiones firmes para el sensor ultrasónico.

---

## Referencias bibliográficas 

### Hardware y código  
- Servo Motor SG90 — Datasheet
https://components101.com/sites/default/files/component_datasheet/SG90-Datasheet.pdf
- HC-SR04 Ultrasonic Sensor Datasheet
https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
- Arduino UNO Technical Specifications (I/O limits)
https://docs.arduino.cc/hardware/uno-rev3/ 
- LED RGB / Uso correcto y resistencias por canal
https://learn.adafruit.com/rgb-leds/overview 

}}

- Servo Library — Arduino
https://www.arduino.cc/reference/en/libraries/servo/ 
- map() — Arduino Reference (mapeo de distancias a amplitud/velocidad)
https://www.arduino.cc/reference/en/language/functions/math/map/
- pulseIn() — Arduino Reference (lectura del eco ultrasónico)
https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/ 


- Apertura automática de caja (Arduino + HC-SR04 + servo): 
https://github.com/lukman-rtx/Automatic-distance-sensing-Trash-Can-with-Arduino-UNO
- Robot autónomo con sensor ultrasónico giratorio: 
https://www.learnrobotics.org/blog/robot-tank-ultrasonic-sensor/

### Referencias de proyectos similares (arte / instalacion interactiva)  
- Proyecto educativo de robótica con ultrasonido y servo: 
https://iotchile.blogspot.com/2016/05/arduino-y-robotica-educativa-proyecto.html
- Sistema radar ultrasonico + servo (tutorial Arduino):
https://robotuno.com/radar-arduino-sensor-ultrasonidos-hc-sr04/
- Radar con Arduino (Project Hub): 
https://projecthub.arduino.cc/diegogalvan_1294/building-an-ultrasonic-radar-using-arduino-and-processing-59053e
---

## Qué rescatamos de estos referentes  
- **Proyectos servo + ultrasonido** muestran cómo esta combinación permite dar a una máquina la capacidad de “mirar” e “interactuar” con su entorno.  
- El uso del **filtro** y del **ruido del sensor** es habitual en proyectos interactivos para añadir naturalidad, no solo para mejorar la medición.  
- Las **esculturas reactivas** demuestran que con hardware simple se puede construir un comportamiento emocional: responder a la presencia, moverse, activar luces o sonido.

---