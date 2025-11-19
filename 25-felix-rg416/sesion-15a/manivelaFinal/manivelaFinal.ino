#include "Manivela.h"
#include <Arduino.h>

Manivela manivela;
const int humo = 7;

void setup() {
  pinMode(humo, LOW);
  manivela.configurar();
  Serial.begin(9600);
}

void loop(){
  manivela.calcularRango();
  manivela.calculoVueltas();
  if (manivela.rango = 1){
    digitalWrite(humo, HIGH);
    delay (6000);
    digitalWrite(humo, LOW);
  }
  Serial.print(manivela.vueltas);
  Serial.println(manivela.rango);
  Serial.println(manivela.paso);
}