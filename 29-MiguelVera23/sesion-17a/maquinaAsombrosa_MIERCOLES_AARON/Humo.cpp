#include "Humo.h"

Humo::Humo() {}

void Humo::preparar(bool modo) {

  Humo::emitirSerial = modo;

  if (Humo::emitirSerial) {
    Serial.begin(9600);
  }

  pinMode(humo, OUTPUT);
}

void Humo::actualizar(int rangoEncoder) {
  Humo::punto = rangoEncoder;
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
