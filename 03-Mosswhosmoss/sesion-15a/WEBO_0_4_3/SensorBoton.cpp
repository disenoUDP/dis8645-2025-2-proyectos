#include "SensorBoton.h"

SensorBoton::SensorBoton(){}

void SensorBoton::configuracionBoton() {
  pinMode(botonPin, INPUT);
  Serial.begin(9600);
  segundos = 40;
}

void SensorBoton::funcionaBoton() {

  estadoBoton = digitalRead(botonPin); 

  if (estadoBoton == HIGH){
    segundos +=5;
  }

  // // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  // if (buttonState == HIGH) {
  //   // turn LED on:
  //   digitalWrite(ledPin, HIGH);
  // } else {
  //   // turn LED off:
  //   digitalWrite(ledPin, LOW);
  // }

  segundos -= 1;
  Serial.println(segundos);
  Serial.println(estadoBoton);
  delay(1000);

}