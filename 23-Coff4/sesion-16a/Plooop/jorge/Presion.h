#ifndef PRESION_H
#define PRESION_H

// incluir biblliotecas
#include "Arduino.h"

// crear la clase
class Presion{
public:
Presion();

//crear los voids
void configurarPresion();

void funcionaPresion();


// agregar variables coo booleanas ints o strings

bool waos;

// todo lo que vaya empezado con letras azules
// que no sean voids, irian aqui

const int pinDePresion = A0;
int valorDePresion = 0;
bool hayBrazo;
int presionMinimaAceptable = 50;



};

#endif
