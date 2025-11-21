/*
  Máquina de la Vergüenza
  ---------------------------------------------------------
  Esta máquina representa un estado de “vergüenza” usando 
  un servo SG90 y un LED RGB. Percibe la distancia mediante 
  un sensor ultrasónico HC-SR04 y reacciona dependiendo de 
  qué tan cerca esté un objeto o la otra máquina.

  A mayor distancia → parpadeo lento y servo quieto.  
  A medida que te acercas (< 50 cm) → el parpadeo acelera y 
  el servo oscila con mayor amplitud.  
  A muy poca distancia (≤ 5 cm) → entra en un estado de caos.

  No se comunica con otras placas: todas las reacciones dependen
  solo de la distancia.

  Comportamientos:
  // LED cian (verde + azul)
  // LED RGB Ánodo Común → SIEMPRE cian (solo V+B).

  - Lejos → calma, parpadeo lento.
  - Cercanía → servo inquieto + parpadeo rápido.
  - Muy cerca (≤ 5 cm) → caos total.

  Hardware:
  - HC-SR04:
      TRIG = D2
      ECHO = D3
  - LED RGB Ánodo Común:
      R = D9
      G = D10
      B = D11
  - Servo SG90 → D6

  Importante:
  - LED ánodo común → LOW = encendido / HIGH = apagado.
*/

#include <Servo.h> // Biblioteca para controlar el servo SG90

// Pin TRIG del sensor ultrasónico HC-SR04
#define TRIG 2
// Pin ECHO del sensor ultrasónico HC-SR04
#define ECHO 3

// Canal rojo del LED RGB (ánodo común)
#define LED_R 9
// Canal verde del LED RGB
#define LED_V 10
// Canal azul del LED RGB
#define LED_A 11

// Pin donde está conectado el servo SG90
#define SERVO_PIN 6

// Distancia donde empieza a reaccionar (50 cm)
const int DIST_MAX = 50;
// Distancia mínima real válida (5 cm)
const int DIST_MIN = 5;

// Objeto que controla el servo
Servo servoVerguenza;

// Variables internas del movimiento del servo
int centro = 90;        // Punto neutro del servo
int angulo = 90;        // Ángulo actual del servo
int direccion = 1;      // Hacia dónde se mueve el servo (1 o -1)


// -----------------------------------------------------------
// Configuración inicial

void setup() {
  // TRIG como salida
  pinMode(TRIG, OUTPUT);
  // ECHO como entrada
  pinMode(ECHO, INPUT);

  // LED RGB como salida
  pinMode(LED_R, OUTPUT);
  pinMode(LED_V, OUTPUT);
  pinMode(LED_A, OUTPUT);

  // El LED se encenderá con verde + azul → color cian.
  
  digitalWrite(LED_R, HIGH); // Rojo siempre apagado (no participa en el color)
  digitalWrite(LED_V, HIGH); // Verde apagado hasta parpadeo (LOW = encendido)
  digitalWrite(LED_A, HIGH); // Azul apagado hasta parpadeo

  // Inicializa el servo y lo centra
  servoVerguenza.attach(SERVO_PIN);
  servoVerguenza.write(90);

  // Serial para depuración opcional
  Serial.begin(9600);
}


// -----------------------------------------------------------
// Mide distancia usando el HC-SR04

long medirDistancia() {
  // Asegura TRIG en LOW antes del pulso
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Pulso HIGH de 10 us (activación del HC-SR04)
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Duración del pulso en ECHO
  long duracion = pulseIn(ECHO, HIGH, 30000);

  // Si no hay lectura → error
  if (duracion == 0) return -1;

  // Conversión a centímetros
  long distancia = duracion * 0.0343 / 2;

  // Filtra lecturas irreales
  if (distancia < 2 || distancia > 400) return -1;

  return distancia;
}


// -----------------------------------------------------------
// Parpadeo del LED en color cian (verde + azul)

void parpadeoLED(int tiempo) {
  //verde + azul encendidos → cian

  digitalWrite(LED_V, LOW); // Enciende verde (LOW = encendido)
  digitalWrite(LED_A, LOW); // Enciende azul  (LOW = encendido)

  // Mantiene encendido el tiempo indicado
  delay(tiempo);

  // Apaga los canales (HIGH = apagado)
  digitalWrite(LED_V, HIGH);
  digitalWrite(LED_A, HIGH);

  // Pausa antes del siguiente ciclo
  delay(tiempo * 0.6);
}


// -----------------------------------------------------------
// Movimiento del servo según amplitud y velocidad

void moverServo(int amplitud, int velocidad) {
  // Aumenta o disminuye ángulo según dirección
  angulo += direccion;

  // Invierte dirección cuando llega a los límites
  if (angulo >= centro + amplitud) direccion = -1;
  if (angulo <= centro - amplitud) direccion = 1;

  // Envía posición al servo
  servoVerguenza.write(angulo);

  // Pausa que define velocidad del movimiento
  delay(velocidad);
}


// -----------------------------------------------------------
// Bucle principal

void loop() {
  // Mide la distancia actual
  long d = medirDistancia();

  // Si la lectura es inválida
  if (d < 0) {
    // LED indica error con parpadeo suave
    parpadeoLED(150);
    // Servo queda quieto
    servoVerguenza.write(90);
    return;
  }

  // ---------------------------------------------------------
  // CASO 1: OBJETO LEJOS (distancia > 50 cm)

  if (d > DIST_MAX) {
    // Parpadeo lento → calma
    parpadeoLED(200);
    // Servo en posición neutra
    servoVerguenza.write(90);
    return;
  }

  // ---------------------------------------------------------
  // CASO 2: DISTANCIA INTERMEDIA (5–50 cm)

  if (d > DIST_MIN && d <= DIST_MAX) {
    // A menor distancia → parpadeo más rápido
    int tLed = map(d, DIST_MAX, DIST_MIN, 300, 20);
    tLed = constrain(tLed, 20, 300);

    // Parpadeo cian
    parpadeoLED(tLed);

    // A menor distancia → mayor amplitud
    int amplitud = map(d, DIST_MAX, DIST_MIN, 5, 50);
    amplitud = constrain(amplitud, 5, 50);

    // A menor distancia → más velocidad
    int velocidad = map(d, DIST_MAX, DIST_MIN, 40, 5);
    velocidad = constrain(velocidad, 5, 40);

    // Mueve el servo según cercanía
    moverServo(amplitud, velocidad);
    return;
  }

  // ---------------------------------------------------------
  // CASO 3: CAOS TOTAL (≤ 5 cm)

  if (d <= DIST_MIN) {
    // Movimiento aleatorio entre 60° y 120°
    int ang = random(60, 120);
    servoVerguenza.write(ang);

    // LED parpadea muy rápido (cian)
    parpadeoLED(20);

    // Pequeña pausa
    delay(5);
    return;
  }
}
