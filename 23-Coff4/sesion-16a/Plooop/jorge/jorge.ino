// incluir los archivos .h de todos los componentes
#include "Presion.h"
#include "Servomotor.h"
#include "Ultrasonico.h"
#include "Motor.h"


//pasar la clase a minusculas no se porque
Presion presion;
Servomotor servomotor;
Ultrasonico ultrasonico;
Motor motor;


//void setup en donde se escribe todos los
// setups de los componentes
void setup(){
// escribelos priemro el nombre del componente, nuego cual era su setup
presion.configurarPresion();
servomotor.configurarServo();
ultrasonico.configurarSonico();
motor.configurarMotor();
}

// aqui van todas las acciones
void loop(){
  presion.funcionaPresion();
  servomotor.funcionaServo();
  ultrasonico.funcionaSonico();
  motor.funcionaMotor();
}