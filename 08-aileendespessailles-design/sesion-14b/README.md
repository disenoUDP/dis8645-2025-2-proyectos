# sesion-14b

1. Parlante
- Función: Emite sonido o música (usado junto al módulo MP3).
- Conexión: No se conecta directamente al Arduino, sino al módulo MP3. El módulo MP3 tiene salidas SPK+ y SPK− o L/R para el parlante.
- Importante: Nunca conectar el parlante directamente a un pin del Arduino — el voltaje/corriente pueden dañarlo.

2. Servomotores (x3)
- Función: Motores que giran un ángulo específico (0° a 180° aprox.), útiles para movimiento controlado.
- Conexión (por servo): Rojo → 5V, Marrón/Negro → GND, Naranja/Amarillo → Pin digital PWM (ej. D3, D5, D6)
- Si usas varios servos, usa una fuente de 5V externa (no del Arduino directamente) y conecta todas las tierras (GND) juntas.
  
3. Sensor ultrasónico (HC-SR04)
- Función: Mide distancia usando ondas de sonido (eco).
- Conexión: VCC → 5V, GND → GND, TRIG → Pin digital (ej. D9), ECHO → Pin digital (ej. D10)
- Se usa la función pulseIn() en Arduino para medir el tiempo del eco y calcular la distancia.

4. Módulo MP3 (ej. DFPlayer Mini)
- Función: Reproduce archivos MP3 desde una microSD, controlado por Arduino.
- Conexión: VCC → 5V, GND → GND, TX → Pin digital (ej. D10), RX → Pin digital (ej. D11), SPK+ y SPK− → Parlante
- Se controla con la librería DFPlayer_Mini_Mp3.

5. Sensor de presión (FSR o piezoeléctrico)
- Función: Detecta fuerza o presión aplicada.
- Conexión: Un extremo → 5V, El otro extremo → Pin analógico (ej. A0), Además, una resistencia (10kΩ) entre el pin analógico y GND (forma un divisor de voltaje).
- El valor leído varía según la presión ejercida.
  
## intento de uso del parlante

video gritos de pánico de mono bebé: <https://www.youtube.com/watch?v=AKsrxOVDYhI>
videos como usar parlante: <https://www.youtube.com/watch?v=DH4OeB81dic>
estuve intentando utilizar el parlante sin el reproductor mp3, pero no se pudo, por una razon que desconozco, después lo deje de intentar, ya que al no tener módulo mp3 solo se podia reproducir sonidos de 4 segundos y necesitamos mas para el proyecto.
![alt text](https://github.com/aileendespessailles-design/dis8645-2025-2-proyectos/blob/main/08-aileendespessailles-design/sesion-15a/imagenes/WhatsApp%20Image%202025-11-18%20at%2018.56.58.jpeg) 
