#include "Humo.h"

Humo::Humo() {}

void Humo::preparar() {
  Serial.begin(9600);
  pinMode(humo, OUTPUT);
}

void Humo::usar() {
  if (tiraHumo == false && punto == 6) {
    digitalWrite(humo, HIGH);
    delay(3000);
    digitalWrite(humo, LOW);
    tiraHumo = true;
  }
  if (punto == 1) {
    tiraHumo = false;
  }
}
