// incluye el archivo.h
#include "Ultrasonico.h"

// constructor
Ultrasonico::Ultrasonico() {}


// pponer tus voids escrbiendo la clase antes, por buenos modales
// aqui ocurre el setup
void Ultrasonico::configurar() {

  pinMode(Ultrasonico::pinEkeko, INPUT);
  pinMode(Ultrasonico::pinTrix, OUTPUT);

  if (Ultrasonico::sustancia > 400 || Ultrasonico::sustancia <= 0) {
    Ultrasonico::sustancia = 400;
  }
}

void Ultrasonico::leer() {
  digitalWrite(Ultrasonico::pinTrix, LOW);
  delayMicroseconds(2);
  //enviar un pulso ultrasonico
  digitalWrite(Ultrasonico::pinTrix, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ultrasonico::pinTrix, LOW);

  long duracion = pulseIn(pinEkeko, HIGH);

  Ultrasonico::distancia = duracion / 58;
  // Determinar si hay una persona (ejemplo: a menos de 30 cm)
  persona = (Ultrasonico::distancia < 30);

  if (Ultrasonico::distancia > 0 && Ultrasonico::distancia <= 30) {
    Serial.print("Persona detectada a: ");
    Serial.print(Ultrasonico::distancia);  // Sin comillas para ver el numero
    Serial.println(" cm");
  } else {
    Serial.print("No hay persona");
    delay(1000);
  }
}