#include "Manivela.h"

Manivela::Manivela() {}
Manivela::~Manivela() {}

// configuracion de patitas del encoder
void Manivela::configurar() {
  pinMode(Manivela::patitaCLK, INPUT);
  pinMode(Manivela::patitaDT, INPUT);
  pinMode(Manivela::patitaSW, INPUT_PULLUP);

  // lee el estado inicial del CLK
  Manivela::ultimoEstadoCLK = digitalRead(Manivela::patitaCLK);
}

void Manivela::calculoVueltas() {

  // lee el estado actual del CLK
  Manivela::estadoActualCLK = digitalRead(Manivela::patitaCLK);
  // si los ultimos estado actuales del CLK son diferentes ocurrió un pulso
  // reacciona solo a 1 cambio de estado para evitar un doble conteo

  if (Manivela::estadoActualCLK != Manivela::ultimoEstadoCLK && Manivela::estadoActualCLK == 1) {

    if (digitalRead(Manivela::patitaDT) != Manivela::estadoActualCLK) {
      Manivela::paso++;
      Manivela::direccionActual = "CW";
      Serial.print("| pasos ");
      Serial.println(Manivela::paso);
    } else {
      Manivela::paso--;
      Manivela::direccionActual = "CCW";
    }

    if (Manivela::paso % 20 == 0) {
      Manivela::vueltas++;
    }
  }
  // void Manivela::calcularRango() {
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
  Manivela::ultimoEstadoCLK = Manivela::estadoActualCLK;

  int btnState = digitalRead(Manivela::patitaSW);

  if (btnState == LOW) {

    if (millis() - ultimaPresionBoton > 50) {
      Serial.println("Boton presionado");
    }
    ultimaPresionBoton = millis();
  }
  delay(1);
}
