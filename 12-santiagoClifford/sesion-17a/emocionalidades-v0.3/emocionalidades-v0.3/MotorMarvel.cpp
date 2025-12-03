#include "MotorMarvel.h"

MotorMarvel::MotorMarvel() {
  able = 3;
  input1 = 5;
  input2 = 6;
      pinMode(able, OUTPUT);
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
}

void MotorMarvel::setear() {

  //asignar velocidad
  analogWrite(able, 100);
}

void MotorMarvel::abrazar() {
  bool abrazo=false;
  if (abrazo==true) {
    //asignar velocidad
    analogWrite(able, 100);
    //prender en direccion1
    digitalWrite(input1, HIGH);
  } else {
    //apagar
    digitalWrite(input1, LOW);
  }
}

void MotorMarvel::tersiana() {
  //direccion1 ON
  digitalWrite(input1, HIGH);
  // direccion1 OFF
  digitalWrite(input1, LOW);

  //direccion ON
  digitalWrite(input2, HIGH);
  //direccion2 OFF
  digitalWrite(input2, LOW);
}
