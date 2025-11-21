#include "Arduino.h"
#include "leds.h"

// ===============================
//       VARIABLES Y ESTADOS
// ===============================

int rangoEncoder = 0;
int leerRango = 5;

// ===============================
//       PINES DE LOS LEDS
// ===============================

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;


// ===============================
//       FUNCIONES PRINCIPALES
// ===============================

void prepLuces() {
  // Configurar los pines como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  rangoEncoder = leerRango;
}

void actuarLuces() {
  //lee en que rango está

  //todas las luces empiezan apagadas
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  //si está en el rango 1 solo 1 led está prendido
  if (rangoEncoder == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

  }
  //si está en el rango 2, 2 led están prendidas
  else if (rangoEncoder == 2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  //si está en el rango 3, 3 led están prendidas
  else if (rangoEncoder == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  //si está en el rango 4, 4 led están prendidas
  else if (rangoEncoder == 4) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
  }
  //en el rango 5 se activa la función finalLuces que prende y apaga leds 2 veces por segundo
  //esto se repite 5 veces
  else if (rangoEncoder == 5) {
    for (int i = 0; i < 7; i++) {
      finalLuces();
      Serial.println(i);
    }
    //al terminar vuelve al rango 1
    rangoEncoder = 1;
  }
}

void finalLuces() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(300);
}
