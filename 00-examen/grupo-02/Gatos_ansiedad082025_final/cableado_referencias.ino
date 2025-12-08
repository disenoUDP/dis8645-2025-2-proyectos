// ---------------------------------------------------------
// Archivo: cableado_referencias.ino
// Tipo: Archivo documental (no ejecuta código)
// ---------------------------------------------------------
// 1) LISTA DE COMPONENTES (BOM)
// ---------------------------------------------------------
//
// • Arduino UNO R4 Mínima
// • Sensor ultrasónico HC-SR04
// • 4 Motores vibradores tipo joystick
// • 4 Módulos MOSFET 15A / 400W PWM
// • LEDs simples (al menos 4)
// • Resistencias 220Ω
// • Protoboard grande
// • Fuente externa 6–9V
// • Cables Dupont
//
// ---------------------------------------------------------
// 2) LINKS DE COMPRA 
// ---------------------------------------------------------
//
// Módulo MOSFET 15A 400W PWM
// https://afel.cl/products/modulo-mosfet-15a-400w-pwm
//
// Pack de cables Hembra-Hembra
// https://afel.cl/products/pack-20-cables-de-conexion-hembra-hembra?_pos=2&_sid=79ff9b6a9&_ss=r
//
// Sensor ultrasónico HC-SR04
// https://afel.cl/products/sensor-de-ultrasonico-hc-sr04
//
// LED RGB 5mm / LED normal
// https://afel.cl/products/diodo-led-rgb-5mm
//
// ---------------------------------------------------------
// 3) CABLEADO DEL SENSOR ULTRASÓNICO HC-SR04
// ---------------------------------------------------------
//
// HC-SR04 → Arduino
// -------------------
// VCC  → 5V
// GND  → GND común
// TRIG → D8
// ECHO → D9
//
// El sensor funciona midiendo el tiempo que tarda un pulso
// ultrasónico en rebotar. Se usa pulseIn(), que viene con
// Arduino por defecto.
//
// ---------------------------------------------------------
// 4) CABLEADO DE LOS MOTORES (CON MOSFET)
// ---------------------------------------------------------
//
// Cada motor vibra gracias a un MOSFET.
// Arduino solo manda señal, NO alimenta los motores.
//
// Conexión del MOSFET:
// --------------------
// MOSFET +V     → +6–9V (FUENTE EXTERNA)
// MOSFET GND    → GND común
// MOSFET SIGNAL → Pin PWM Arduino
// Motor +       → +6–9V de la fuente
// Motor –       → OUT– del MOSFET
//
// Distribución de motores:
//  - Gato 1 → Pin 3
//  - Gato 2 → Pin 5
//  - Gato 3 → Pin 6
//  - Gato 4 → Pin 10
//
// ---------------------------------------------------------
// 5) CABLEADO DE LEDS
// ---------------------------------------------------------
//
// Ánodo (pierna larga)   → Pin digital Arduino
// Cátodo (pierna corta)  → Resistencia 220Ω → GND
//
// Pins usados:
//  LED 1 → D2
//  LED 2 → D4
//  LED 3 → D7
//  LED 4 → D12
//
// ---------------------------------------------------------
// 6) RESUMEN DEL CIRCUITO
// ---------------------------------------------------------
//
// Sensor → detecta distancia y dispara la ansiedad
//
// Arduino → interpreta distancia y envía señales PWM
//
// MOSFET → controla potencia real de los motores
//
// Motores vibradores → simulan temblor/emoción del gato
//
// LEDs → muestran estados emocionales con parpadeo
//
// ---------------------------------------------------------
// 7) NOTAS DE SEGURIDAD
// ---------------------------------------------------------
//
// • TODOS los GND deben estar unidos.
// • La fuente externa alimenta solo los motores.
// • Arduino solo controla, no debe recibir la corriente del motor.
// • Se recomienda capacitor de 470µF entre +V y GND de la fuente.
//
// ---------------------------------------------------------
// 8) REFERENCIAS TÉCNICAS Y BIBLIOGRÁFICAS
// ---------------------------------------------------------
//
// Esta sección cita las fuentes donde se investigó el uso
// correcto de cada componente.
//
// ---- DOCUMENTACIÓN OFICIAL ARDUINO ----
//
// • analogWrite() — PWM oficial
//   https://docs.arduino.cc/language-reference/en/functions/analog-io/analogWrite/?utm_source
//
// • pulseIn() — lectura del pulso del HC-SR04
//   https://docs.arduino.cc/language-reference/en/functions/advanced-io/pulseIn/?utm_source
//
// • PinMode y digitalWrite (uso básico de pines)
//   https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/?utm_source
//
// ---- REFERENCIAS DE SENSORES ----
//
// • HC-SR04 — Guía técnica en Arduino
//   https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/?utm_source
//
// ---- REFERENCIAS DE MOSFET ----
//
// • Cómo controlar motores con MOSFET y Arduino
//   https://dronebotworkshop.com/transistors-mosfets/?utm_source
//
//
// ---- REFERENCIAS DE MOTORES VIBRADORES ----
//
// • Guía de motores vibradores pequeños
//   https://deepbluembedded.com/arduino-vibration-motor-code-circuit/?utm_source
//