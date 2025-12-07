#include "ActuadorMotor.h"

ActuadorMotor::ActuadorMotor() {}

void ActuadorMotor::configuracionMotor() {
  //establecer que el pin que va a mandar una señal
  // sera el que fue declarado antes
  pinMode(motorPin, OUTPUT);
}

void ActuadorMotor::funcionaMotor() {
  if (segundosTiempo > 0) {
    tiempoActual = millis();
    if (!motorPrendido) {
      if (tiempoActual - tiempoNuevoTemporizadorPrendido >= intervaloMotorPrendido) {
        digitalWrite(motorPin, LOW);  // apagar motor
        Serial.println("Motor se apago");
        motorPrendido = true;                          // cambiamos de estado
        tiempoNuevoTemporizadorApagado = tiempoActual;  // iniciamos el temporizador de apagado
      }
    } else {  // motor está apagado
      if (tiempoActual - tiempoNuevoTemporizadorApagado >= intervaloMotorApagado) {
        digitalWrite(motorPin, HIGH);  // encender motor
        Serial.println("Motor se prendio");
        motorPrendido = false;                            // nuevo estado
        tiempoNuevoTemporizadorPrendido = tiempoActual;  // iniciamos el temporizador de encendido
      }
    }
  } else {
    digitalWrite(motorPin, LOW);
    motorPrendido = true;
  }
}
