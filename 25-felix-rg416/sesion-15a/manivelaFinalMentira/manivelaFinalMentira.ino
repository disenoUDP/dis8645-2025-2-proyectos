#include "Manivela.h"
#include <Arduino.h>

Manivela manivela;

const int humo = 7;

void setup() {
  pinMode(humo, LOW);
  manivela.configurar();
  Serial.begin(9600);
}

void loop() {

  manivela.calculoVueltas();
  // manivela.calcularRango();

  // if (manivela.rango = 1) {
  //   digitalWrite(humo, HIGH);
  //   delay(6000);
  //   digitalWrite(humo, LOW);
  // }

  Serial.print("| pasos ");
  Serial.println(manivela.paso);
  Serial.print("| vueltas ");
  Serial.println(manivela.vueltas);
  Serial.print("| rango ");
  Serial.println(manivela.rango);
  delay(1000);
}