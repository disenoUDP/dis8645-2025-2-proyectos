#include "SensorTilt.h"
#include "TimersMillis.h"

SensorTilt::SensorTilt() {}

void SensorTilt::configuracionTilt() {
  //Aca definimos el pin del sensor como entrada
  //Habilitamos el pull-up interno para el pin del sensor
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
}

void SensorTilt::funcionaTilt() {
  // definir la lectura si es que esta parado o inclinado
  // - LOW  = sensor cerrado = inclinado
  // - HIGH = sensor abierto = parado
  // la lecturaActual  parasa a ser aquello que es
  // recibido por el tiltPin
  lecturaActual = digitalRead(tiltPin);

  // ------------------------------------------
  // CASO 1: Si es que el sensor esta inclinado
  // ------------------------------------------

  if (lecturaActual == HIGH) {
    // Si esta es la **primera** vez que se ha detectado una inclinacion
    // graba el tiempo en el que comenzo la inclinacion
    if (!enProcesoDeCaida) {
      enProcesoDeCaida = true;
      tiempoInicioCaida = millis();
    }

    // Comprueba el tiempo en el que ha estado incinado
    if (millis() - tiempoInicioCaida >= tiempoNecesarioCaido) {
      // Si es que la comporacion de tiempo se cumple
      if (!caido) {
        Serial.println("esta caido");
      }
      // el estado de caido sera real
      caido = true;
    }
  }

  // -----------------------------------------
  // CASO 2: El sensor no esta inclinado ahora
  // -----------------------------------------

  else {
    // Resetar el proceso de caida siempre que este parado
    // para que no se pueda cumplir el estado de inclinado
    enProcesoDeCaida = false;

    // Si es que previeamente estaba inclinado
    if (caido) {
      // mostar en el monitor serial que en realidad cambio a estar parado
      Serial.println("esta parado");
    }
    // NO esta caido
    // ESTA parado
    caido = false;
  }
}
