
#include "Ultrasonico.h"

Sonic::Sonic() {
}

//
void Sonic::configurar() {
// Conectar los pines.
  pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);
  Serial.begin(9600);
}

void Sonic::reconocerDistancia() {
// Configuración reconocimiento distancia
  digitalWrite(pinTrix, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrix, LOW);
// Medir duración del eco.
  duracion = pulseIn(pinEkeko, HIGH);
// Calcular distancia en cm.
  distancia = duracion / 58; 
// Determinar si hay una persona (ejemplo: a menos de 30 cm)
  persona = (distancia < 10 - 40);
}

void Sonic::leerDistancia() {
// Imprimir en el monitor serial la distancia detectada en cm.
 if (persona) {
  // se escribira en el monitor serial la distancia de la persona
    Serial.println("la persona esta a: ");
    Serial.print(distancia);
    Serial.println(" cm");
  // si no se escribira en el monitor serial que no hay una persona
   } else {
    Serial.println("No hay persona.");
  }
}