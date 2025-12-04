#include "Presion.h"

// constructor
Presion::Presion() {}

//pponer tus voids escrbiendo la clase antes, por buenos modales
// aqui ocurre el setup
void Presion::configurar() {
  pinMode(Presion::pinDePresion, INPUT);
}

// aqui ocurre el loop
void Presion::leer() {
  // asignar el valor del pin del sensor de presion, a la variable valorDePresion
  Presion::valorDePresion = analogRead(Presion::pinDePresion);
  // si valorDePresion es mayor a presionMinimaAceptable, hayBrazo es true
  Presion::hayBrazo = (Presion::valorDePresion > Presion::presionMinimaAceptable);
}