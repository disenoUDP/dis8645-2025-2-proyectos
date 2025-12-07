#ifndef SENSOR_DE_PRESION_H
#define SENSOR_DE_PRESION_H

// incluir biblliotecas
#include "Arduino.h"

// crear la clase
class SensorDePresion{
public:
SensorDePresion();

//crear los voids
void configurarDePresion();

void funcionaDePresion();

// todo lo que vaya empezado con letras azules
// que no sean voids, irian aqui

const int pinDePresion; 
int valorDePresion;
bool hayBrazo;
int presionMinimaAceptable;
};

#endif