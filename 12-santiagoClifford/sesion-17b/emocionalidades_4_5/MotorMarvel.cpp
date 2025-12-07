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
  analogWrite(able, 100);
  abrazando = false;
}

void MotorMarvel::activarAbrazo() {
  abrazando = true;
  inicioAbrazo = millis();
}


void MotorMarvel::actualizarAbrazo() {
  if (abrazando == true) {
    analogWrite(able, 100);
    digitalWrite(in1, HIGH);
    // si ya pasó el tiempo , abrazando es false
    if (millis() - inicioAbrazo >= duracionAbrazo) {
      abrazando = false;
      digitalWrite(in1, LOW);
    } else {
      digitalWrite(in1, LOW);
    }
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