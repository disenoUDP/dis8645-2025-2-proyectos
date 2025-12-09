#include "TimersMillis.h"

const int segundoNumero = 1000;

const int tiempoNecesarioCaido = segundoNumero * 0.5;

int segundosTiempo = 0;

int intervaloSegundo = segundoNumero;

// cuantos milisegundos durara prendido el motor
int intervaloMotorPrendido = 4 * segundoNumero;

// cuantos milisegundos durara apagado el motor
int intervaloMotorApagado = random(2, 10) * segundoNumero;

int cambioGiro = 0.1 * segundoNumero;

bool caido = false;

bool motorPrendido = false;

bool estadoCelebracion = false;

bool estadoDurmiendo = true;
