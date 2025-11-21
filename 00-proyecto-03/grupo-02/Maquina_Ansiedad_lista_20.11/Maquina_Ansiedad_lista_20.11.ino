/*
  Máquina de la Ansiedad 
  ---------------------------------------------------------
  Esta máquina representa un estado de "ansiedad" usando un 
  motor N20 y un LED RGB. Percibe la distancia con un sensor 
  ultrasónico HC-SR04 y reacciona según qué tan cerca esté 
  un objeto o la otra máquina.

  Mientras más lejos está algo → vibración suave y luz morada tenue.  
  Mientras más se acerca → los movimientos y el parpadeo se vuelven 
  más rápidos e intensos.  
  A muy poca distancia (≤ 5 cm) → entra en un estado de caos total.

  No se comunica con otras placas: todas las reacciones dependen 
  únicamente de la distancia.

  Comportamientos:
  - LED RGB Ánodo Común → SIEMPRE morado (solo R+B).
  - A más distancia → calma, “latido” lento.
  - A medida que te acercas (<50 cm) → vibración + parpadeo aumentan.
  - A menos de 5 cm → caos total.

  Hardware:
  - HC-SR04:
      TRIG = D2
      ECHO = D3
  - Motor N20 con MOSFET → PWM en D5
  - LED RGB Ánodo Común:
      R = D9
      G = D10 (no se usa)
      B = D11

  Importante:
  - LED ánodo común → 255 = apagado / 0 = brillo máximo.
*/
// Biblioteca base de Arduino con funciones esenciales
#include <Arduino.h>

// Pin TRIG del sensor ultrasónico HC-SR04
#define TRIG 2
// Pin ECHO del sensor ultrasónico HC-SR04
#define ECHO 3
// Pin PWM donde está conectado el motor N20 mediante MOSFET
#define MOTOR 5

// Canal rojo del LED RGB (ánodo común)
#define LED_R 9
// Canal verde del LED RGB (no se usa)
#define LED_V 10
// Canal azul del LED RGB
#define LED_A 11

// Distancia límite donde empieza el comportamiento reactivo (50 cm)
const int DIST_MAX = 50;
// Valor inicial del filtro suavizado de distancia
long distanciaFiltrada = 50;

// -----------------------------------------------------------
// Función que mide la distancia usando el HC-SR04

long medirDistancia() {
  // Asegura el TRIG en LOW antes de enviar el pulso
  digitalWrite(TRIG, LOW);
  // Pausa muy corta para estabilizar
  delayMicroseconds(2);
  // Envía pulso HIGH para activar el disparo del sensor
  digitalWrite(TRIG, HIGH);
  // Mantiene el pulso 10 us, obligatorio para el HC-SR04
  delayMicroseconds(10);
  // Termina el pulso regresándolo a LOW
  digitalWrite(TRIG, LOW);

  // Mide cuánto tiempo el pin ECHO permanece HIGH
  long duracion = pulseIn(ECHO, HIGH, 30000);
  // Si no hay lectura, devuelve -1 como error
  if (duracion == 0) return -1;

  // Convierte duración a distancia en cm (velocidad del sonido)
  long distancia = duracion * 0.0343 / 2;
  // Si la lectura no es realista, la descarta
  if (distancia < 2 || distancia > 400) return -1;

 // Devuelve finalmente la distancia válida
  return distancia;
}

// -----------------------------------------------------------
// Filtro de suavizado

long filtrar(long nueva) {
  // Si el valor es inválido, conserva el último bueno
  if (nueva < 0) return distanciaFiltrada;
  // Mezcla 70% vieja + 30% nueva
  distanciaFiltrada = (0.7 * distanciaFiltrada) + (0.3 * nueva); 
  // Devuelve la distancia ya suavizada
  return distanciaFiltrada;
}

// -----------------------------------------------------------
// Función para controlar la vibración del motor con jitter 
   // Se usa jitter (variación aleatoria controlada) para evitar que el movimiento sea mecánico
   // y repetitivo. Esto simula temblores naturales, evita patrones rígidos y hace que el
   // comportamiento se sienta más orgánico, especialmente cuando la distancia varía cerca
   // de los límites del sensor.

void vibrar(int intensidad, int tiempo) {
  // Asegura que esté dentro del rango válido PWM
  intensidad = constrain(intensidad, 0, 255);

  // Genera ruido aleatorio para que la vibración no sea perfecta
  int jitter = random(-15, 15);
  // Aplica el jitter dentro de límites permitidos   
  int power = constrain(intensidad + jitter, 0, 255);

// Enciende el motor con la intensidad seleccionada
  analogWrite(MOTOR, power);
  // Mantiene la vibración el tiempo indicado
  delay(tiempo);
  // Apaga el motor después del pulso
  analogWrite(MOTOR, 0); 
}

// -----------------------------------------------------------
// Función que hace parpadear el LED en color morado

void parpadeoLED(int intensidad, int tiempo) {
  // Inversión necesaria en LEDs de ánodo común
  int brightness = 255 - intensidad;

  // Enciende canal rojo con intensidad invertida
  analogWrite(LED_R, brightness);
  // Enciende canal azul con intensidad invertida
  analogWrite(LED_A, brightness);
  // Mantiene el verde apagado siempre (morado = rojo + azul)
  analogWrite(LED_V, 255);

  // Mantiene el LED prendido el tiempo indicado
  delay(tiempo);

  // Apaga el canal rojo (255 en ánodo común = apagado)
  analogWrite(LED_R, 255);
  // Apaga canal azul
  analogWrite(LED_A, 255);
  // Pequeña pausa para simular parpadeo
  delay(tiempo * 0.6);
}

// -----------------------------------------------------------
// Configuración inicial

void setup() {
  // TRIG como salida
  pinMode(TRIG, OUTPUT);
  // ECHO como entrada
  pinMode(ECHO, INPUT);

  // Pin del motor como salida PWM
  pinMode(MOTOR, OUTPUT);

  // Canales del LED RGB como salida
  pinMode(LED_R, OUTPUT);
  pinMode(LED_V, OUTPUT);
  pinMode(LED_A, OUTPUT);

  // Semilla de números aleatorios usando ruido del pin analógico
  // Usamos el ruido eléctrico del pin analógico como semilla para random(), así la secuencia
  // de números aleatorios cambia realmente cada vez que se enciende el Arduino.
  randomSeed(analogRead(A0));
}

// -----------------------------------------------------------
// Bucle principal: reacciona según la distancia medida

void loop() {
  // Mide distancia actual
  long lectura = medirDistancia();
  // Suaviza esa distancia con el filtro
  long d = filtrar(lectura);
  // Si hay error de lectura
  if (lectura < 0) {
  // Apaga motor por seguridad
    analogWrite(MOTOR, 0);
  // LED indica estado de error con parpadeo suave
    parpadeoLED(30, 150);
  // Reinicia ciclo
    return;
  }

  // ---------------------------------------------------------
  // CASO 1: OBJETO LEJOS

  if (d > DIST_MAX) {
    // Vibración suave
    vibrar(20, 60);
    // Parpadeo lento
    parpadeoLED(40, 120);

    // A veces hace un pico aleatorio
    if (random(0, 10) == 0) {
      vibrar(40, 20);
      parpadeoLED(80, 40);
    }
    // Pequeña pausa
    delay(80);
    // Termina ciclo
    return;
  }

  // ---------------------------------------------------------
  // CASO 2: DISTANCIA INTERMEDIA (30–50 cm)

  if (d > 30 && d <= DIST_MAX) {
    // Más cerca → más intensidad
    int intensidad = map(d, DIST_MAX, 30, 60, 150);
    // Más cerca → menos pausa
    int pausa = map(d, DIST_MAX, 30, 200, 80);

    // Vibración principal
    vibrar(intensidad, 40);
    // Parpadeo sincronizado
    parpadeoLED(intensidad, 50);

    // Segundo pulso más caótico
    vibrar(intensidad + random(-20, 30), 25);
    parpadeoLED(intensidad + random(-30, 40), 30);

    // Pausa total del ciclo
    delay(pausa);
    return;
  }

  // ---------------------------------------------------------
  // CASO 3: DISTANCIA CERCANA (5–30 cm)

  if (d > 5 && d <= 30) {
    // Intensidad crece al acercarse
    int intensidad = map(d, 30, 5, 100, 255);
    // Ciclo se vuelve más rápido
    int rapidez = map(d, 30, 5, 80, 20);

    // Vibración principal
    vibrar(intensidad, 30);
    // Parpadeo acorde
    parpadeoLED(intensidad, 25);

    // Variaciones caóticas
    vibrar(intensidad - random(0, 60), random(10, 40));
    parpadeoLED(intensidad - random(0, 70), random(15, 40));

    // Ciclo acelerado
    delay(rapidez);
    return;
  }

  // ---------------------------------------------------------
  // CASO 4: CAOS TOTAL (≤ 5 cm)

  if (d <= 5) {
    // Vibración máxima
    vibrar(255, 20);
    // Parpadeo máximo
    parpadeoLED(255, 20);

    // Pulso irregular
    vibrar(180 + random(-40, 40), 15);
    // Luz muy inestable
    parpadeoLED(200 + random(-50, 50), 15);

    // Remate final
    vibrar(255, 10);
    parpadeoLED(255, 10);
    return;
  }
}
