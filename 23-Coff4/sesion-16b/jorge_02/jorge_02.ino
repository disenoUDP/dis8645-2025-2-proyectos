// incluir los archivos .h de todos los componentes
#include "Presion.h"
#include "Ultrasonico.h"


// usar las clases
// para crear instancias de los objetos
Presion presion;
Ultrasonico ultrasonico;


void setup() {
  // escribelos primero el nombre del componente, nuego cual era su setup
  presion.configurar();
  ultrasonico.configurar();
  //motor.configurarMotor();
}

// aqui van todas las acciones
void loop() {
  presion.leer();
  ultrasonico.leer();
}