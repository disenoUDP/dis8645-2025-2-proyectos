// incluir los archivos .h de todos los componentes
#include "Presion.h"
#include "Ultrasonico.h"


//pasar la clase a minusculas no se porque
Presion presion;
Ultrasonico ultrasonico;



//void setup en donde se escribe todos los
// setups de los componentes
void setup(){
// escribelos priemro el nombre del componente, nuego cual era su setup
presion.configurarPresion();
ultrasonico.configurarSonico();
//motor.configurarMotor();
}

// aqui van todas las acciones
void loop(){
  presion.funcionaPresion();
 // ultrasonico.funcionaSonico();
  ultrasonico.leerDistancia();
}