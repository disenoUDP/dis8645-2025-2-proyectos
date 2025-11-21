#include "SensorBoton.h"

SensorBoton::SensorBoton(){}

void SensorBoton::configuracionBoton() {
  // establecer cual es el pin que estara conectado el boton
  // sera un input, osea que recibira el paso de señal
  pinMode(botonPin, INPUT);
  Serial.begin(9600);
}

// funcionamiento del boton
void SensorBoton::funcionaBoton() {

// una variable llamada estadoBoton
// es equivalente al dato que es recibido por la
// lectura de señal del pint establecido para el boton
  estadoBoton = digitalRead(botonPin); 

// si es que el estado del boton esta activado
// osea, recibe señal
// este se puede mantener presionado, aumentando constantemente
// lo cual no aporta para la frustacion de la maquina, corregir en el futuro
  if (estadoBoton == HIGH){
    // los segundos van a aumentar en 5
    segundos +=5;
  }

// los segundos disminuiran en 1
  segundos -= 1;
  // enviar al monitor Serial la cantidad de segundos actuales
  Serial.println(segundos);
  // enviar al monitor Serial si es que el boton esta siendo presionado
  Serial.println(estadoBoton);
  // cada 1 segundo, para hacer que (segundos -= 1) sea similar al paso de tiempo
  delay(1000);

}