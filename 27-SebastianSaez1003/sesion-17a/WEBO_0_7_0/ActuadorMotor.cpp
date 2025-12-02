#include "ActuadorMotor.h"

ActuadorMotor::ActuadorMotor() {}

  void ActuadorMotor::configuracionMotor(){
    //establecer que el pin que va a mandar una señal
    // sera el que fue declarado antes
    pinMode(motorPin, OUTPUT);
  }

  void ActuadorMotor::funcionaMotor(){
    tiempoActual = millis();
     if (motorPrendido) {
        if (tiempoActual - tiempoNuevoTemporizadorPrendido >= intervaloMotorPrendido) {
            digitalWrite(motorPin, LOW);     // apagar motor
            Serial.println("Motor se apago");
            motorPrendido = false;           // cambiamos de estado
            tiempoNuevoTemporizadorApagado = tiempoActual;  // iniciamos el temporizador de apagado
        }
    }

    else { // motor está apagado
        if (tiempoActual - tiempoNuevoTemporizadorApagado >= intervaloMotorApagado) {
            digitalWrite(motorPin, HIGH);    // encender motor
            Serial.println("Motor se prendio");
            motorPrendido = true;            // nuevo estado
            tiempoNuevoTemporizadorPrendido = tiempoActual; // iniciamos el temporizador de encendido
        }
    }
}
