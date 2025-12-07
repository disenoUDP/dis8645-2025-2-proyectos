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
}

void MotorMarvel::abrazar() {
  // bool abrazo = false;
  if (abrazo == true) {
    //asignar velocidad
    analogWrite(able, 100);
    //prender en direccion1
    digitalWrite(in1, HIGH);
  } else {
    //apagar
    digitalWrite(in1, LOW);
  }
}

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