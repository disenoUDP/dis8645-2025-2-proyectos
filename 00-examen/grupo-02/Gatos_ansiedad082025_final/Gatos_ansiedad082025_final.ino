// ---------------------------------------------
// Proyecto: Gatitos en Ansiedad
// Versión: Arduino UNO R4 
// Descripción general:
// Este programa controla 4 pequeños motores que representan 
// a gatitos que “sienten ansiedad”. Cuando el sensor ultrasónico 
// detecta que algo (como un metro acercándose) está cerca, 
// los gatitos vibran con una intensidad definida. Si no hay nada 
// cerca, permanecen tranquilos. 
// ---------------------------------------------

// ----------- PINES DE LOS MOTORES ------------
// Cada pin controla un motor mediante PWM 
int gato1 = 3;
int gato2 = 5;
int gato3 = 6;
int gato4 = 10;

// ----------- PINES DEL SENSOR ULTRASÓNICO -----------
// pinTrig envía el pulso
// pinEcho recibe el eco
int pinTrig = 8;
int pinEcho = 9;

// Intensidad de vibración para todos los gatitos
// (valor PWM entre 0 y 255)
int intensidadGato = 180;

// Distancia mínima (en cm) para activar los motores
int distanciaUmbral = 20;

// Variables donde guardamos la duración del eco y la distancia calculada
long duracion;
int distancia;

void setup() {
  Serial.begin(9600);  // Activamos el monitor serial para ver datos en pantalla

  // Configuramos los pines del sensor
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

  // Configuramos los pines de los motores como salida
  pinMode(gato1, OUTPUT);
  pinMode(gato2, OUTPUT);
  pinMode(gato3, OUTPUT);
  pinMode(gato4, OUTPUT);

  // Dejamos todos los motores apagados al iniciar
  analogWrite(gato1, 0);
  analogWrite(gato2, 0);
  analogWrite(gato3, 0);
  analogWrite(gato4, 0);
}

void loop() {

  // --- MEDIR LA DISTANCIA CON EL SENSOR ---
  // Preparamos el pulso inicial
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);

  // Disparo del pulso ultrasónico por 10 microsegundos
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Medimos cuánto tiempo tarda en regresar el eco
  duracion = pulseIn(pinEcho, HIGH);

  // Convertimos ese tiempo a distancia en centímetros
  distancia = duracion * 0.034 / 2;

  // Mostramos la distancia por el monitor serial
  Serial.print("Distancia: ");
  Serial.println(distancia);

  // --- ACTIVAR O DESACTIVAR MOTORES SEGÚN DISTANCIA ---
  if (distancia > 0 && distancia < distanciaUmbral) {

    // Si algo está cerca del sensor:
    // Encendemos los 4 motores con la intensidad definida
    analogWrite(gato1, intensidadGato);
    analogWrite(gato2, intensidadGato);
    analogWrite(gato3, intensidadGato);
    analogWrite(gato4, intensidadGato);

  } else {
    // Si no hay nada cerca:
    // Apagamos completamente todos los motores
    analogWrite(gato1, 0);
    analogWrite(gato2, 0);
    analogWrite(gato3, 0);
    analogWrite(gato4, 0);
  }

  // Pequeño retardo para estabilizar la lectura
  delay(60);
}
