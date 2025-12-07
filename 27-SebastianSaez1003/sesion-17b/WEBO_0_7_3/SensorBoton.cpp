#include "SensorBoton.h"

SensorBoton::SensorBoton() {}

void SensorBoton::configuracionBoton() {
  // establecer cual es el pin que estara conectado el boton
  // sera un input, osea que recibira el paso de señal
  pinMode(botonPin, INPUT);
  Serial.begin(9600);
}

// funcionamiento del boton
void SensorBoton::funcionaBoton() {

  tiempoActualTemporizador = millis();

  // una variable llamada estadoBoton
  // es equivalente al dato que es recibido por la
  // lectura de señal del pint establecido para el boton
  estadoBoton = digitalRead(botonPin);

  // si es que el estado del boton esta activado
  // osea, recibe señal
  // este se puede mantener presionado, aumentando constantemente
  // lo cual no aporta para la frustacion de la maquina, corregir en el futuro

  // si es que hay más de 0 segundos en el temporizador
  // el tiempo actual del temporizador menos el nuevo tiempo del temporizador
  // equivale a un número menor al intervalo segundo, osea a menos de 1000
  if (segundosTiempo > 0 && tiempoActualTemporizador - tiempoNuevoTemporizador >= intervaloSegundo) {
    // los segundos disminuyen en 1
    segundosTiempo -= 1;
    // enviar al monitor Serial la cantidad de segundos actuales
    Serial.println(segundosTiempo);
    // enviar al monitor Serial si es que el botón está siendo presionado
    Serial.println(estadoBoton);

    // esto esta incluido aqui para que solo cada 1 segundo es que se pueda aumentar el temporizador
    if (estadoBoton == HIGH) {
      // los segundos van a aumentar en 5
      segundosTiempo += 6;
    }

    // se actualiza el temporizador para poder realizar la comparación con el intervalo de segundos
    tiempoNuevoTemporizador = tiempoActualTemporizador;
  }
}