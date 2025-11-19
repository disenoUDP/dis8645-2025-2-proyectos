#include "Manivela.h"

Manivela::Manivela() {}

Manivela::~Manivela() {}

void Manivela::configurar() {
  pinMode(Manivela::patitaCLK, INPUT);
  pinMode(Manivela::patitaDT, INPUT);
  pinMode(Manivela::patitaSW, INPUT_PULLUP);

  Manivela::ultimoEstadoCLK = digitalRead(Manivela::patitaCLK);

  Manivela::vueltas = 0;
}

void Manivela::calculoVueltas() {
  Manivela::estadoActualCLK = digitalRead(Manivela::patitaCLK);
  if (Manivela::estadoActualCLK != Manivela::ultimoEstadoCLK) {

    if (digitalRead(Manivela::patitaDT) != Manivela::estadoActualCLK) {
      Manivela::paso --;
      Manivela::direccionActual = "CW";
    } else {
      Manivela::paso ++;
      Manivela::direccionActual = "CCW";
    }

    if (Manivela::paso % 20 == 0) {
      Manivela::vueltas ++;
    }
  }
}

void Manivela::calcularRango() {
  if (Manivela::vueltas >= 0 && Manivela::vueltas <= 1) {
    Manivela::rango = 0;
  } else if (Manivela::vueltas >= 2 && Manivela::vueltas <= 8) {
    Manivela::rango = 1;
  } else if (Manivela::vueltas >= 9 && Manivela::vueltas <= 16) {
    Manivela::rango = 2;
  } else if (Manivela::vueltas >= 17 && Manivela::vueltas <= 24) {
    Manivela::rango = 3;
  } else if (Manivela::vueltas >= 25 && Manivela::vueltas <= 29) {
    Manivela::rango = 4;
  } else if (Manivela::vueltas >= 30) {
    Manivela::rango = 5;
  }
}