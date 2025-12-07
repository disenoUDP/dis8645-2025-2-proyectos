#include "MotorMarvel.h"

MotorMarvel::MotorMarvel() {
  able = 3;
  in1 = 5;
  in2 = 6;
  pinMode(able, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void MotorMarvel::Setear() {

  //asignar velocidad
  analogWrite(able, 20);
  abrazando = false;

  // que parta apagado
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void MotorMarvel::activarAbrazo() {
  abrazando = true;
  duracionAbrazo = tiempo;
  inicioAbrazo = millis();

    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

   analogWrite(able, 20); // Velocidad (0-255)
}


void MotorMarvel::actualizarAbrazo() {
  if (abrazando == false) {
    return;
  }

  // si ya pasó el tiempo , abrazando es false
  if (millis() - inicioAbrazo >= duracionAbrazo) {
    abrazando = false;
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    analogWrite(able, 0);
    Serial.println("STOP MOTOR");
  }
}


// void MotorMarvel::abrazar() {

//   if (abrazando == true) {
//     analogWrite(able, 100);
//     digitalWrite(in1, HIGH);
//   } else {
//     digitalWrite(in1, LOW);
//   }
// }

void MotorMarvel::tersiana() {
  //direccion1 ON
  digitalWrite(in1, HIGH);
  // direccion1 OFF
  digitalWrite(in1, LOW);

  //direccion ON
  digitalWrite(in2, HIGH);
  //direccion2 OFF
  digitalWrite(in2, LOW);
}