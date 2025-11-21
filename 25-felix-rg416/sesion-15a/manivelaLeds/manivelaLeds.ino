#include "Manivela.h"
#include "Leds.h"
#include <Arduino.h>

Leds leds;
Manivela manivela;

void setup() {
  Serial.begin(9600);
  leds.configurar();
  manivela.configurar();
}

void loop() {
  manivela.calculoVueltas();
  // manivela.calcularRango();

// comentado porque lo pase al Manivela.cpp
  // Serial.print("| pasos ");
  // Serial.println(manivela.paso);
  
  // Serial.print("| vueltas ");
  // Serial.println(manivela.vueltas);
  // Serial.print("| rango ");
  // Serial.println(manivela.rango);
  delay(1000);
}