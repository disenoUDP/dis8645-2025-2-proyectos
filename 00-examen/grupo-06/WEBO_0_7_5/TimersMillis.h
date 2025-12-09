#pragma once
// quiero incluir esta biblioteca en todos los archivos que contengan
// los temporizadores de millis
#include "Arduino.h"
// aqui se presentan todos los temporizadores de los componentes

// establecer una int que represente un segundo, para poder re utilizarlo en todo lo demas
extern const int segundoNumero;

//-----------------
// SENSOR TILT
//-----------------

// Cuanto tiempo en necesario para que se considerado que este caido
extern const int tiempoNecesarioCaido;

// una booleana para confirmar si es que esta caido o no
extern bool caido;

//--------------------
//   SENSOR BOTON
//--------------------

// establecer la cantidad de segundos iniciales
extern int segundosTiempo;

// cuantos milisegundos durara un segundo
extern int intervaloSegundo;

extern bool estadoCelebracion;

//--------------------
//   ACTUADOR MOTOR
//--------------------


// cuantos milisegundos durara prendido el motor
extern int intervaloMotorPrendido;

// cuantos milisegundos durara apagado el motor
extern int intervaloMotorApagado;

extern int cambioGiro;

extern bool motorPrendido;
//--------------------
//  ACTUADOR DISPLAY
//--------------------

extern bool estadoDurmiendo; 