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

int pinDePresion; 
int valorDePresion;
bool watitaRascada;
int presionMinimaAceptable;
};

#endif