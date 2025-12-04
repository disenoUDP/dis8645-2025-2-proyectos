// incluye el archivo.h
#include "Ultrasonico.h"

// hacer que la clase claseee
Ultrasonico::Ultrasonico(){}
//YIOP
//pponer tus voids escrbiendo la clase antes, por buenos modales
// aqui ocurre el setup
void Ultrasonico::configurarSonico(){

pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);
  
   if (sustancia > 400 || sustancia <= 0) {
    sustancia = 400;
  }
}

// aqui ocurre el loop
void Ultrasonico::funcionaSonico(){
digitalWrite(pinTrix, LOW);
  delayMicroseconds(2);
  //enviar un pulso ultrasonico
  digitalWrite(pinTrix, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrix, LOW);

// Medir duración del eco.
  duracion = pulseIn(pinEkeko, HIGH, 30000);
// Calcular distancia en cm.
    if (duracion == 0) {
    sustancia = 400;
  } else {
    sustancia = (duracion * 0.0343) / 2;
  }
}

 
 void Ultrasonico::leerDistancia(){
  digitalWrite(pinTrix, LOW);
  delay(2);
  //enviar un pulso ultrasonico
  digitalWrite(pinTrix, HIGH);
  delay(10);
  digitalWrite(pinTrix, LOW);

  long duracion = pulseIn(pinEkeko, HIGH);

 Distancia = duracion / 58; 
// Determinar si hay una persona (ejemplo: a menos de 30 cm)
  persona = (Distancia < 30);

if (Distancia > 0 && Distancia <= 30){
    Serial.print("Persona detectada a: ");
    Serial.print(Distancia); // Sin comillas para ver el numero
    Serial.println(" cm");
  } else {
    Serial.print("No hay persona");
    delay(1000);
  }
 }