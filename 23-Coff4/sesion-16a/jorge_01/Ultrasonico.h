#ifndef ULTRASONICO_H
#define ULTRASONICO_H

// incluir biblliotecas
#include "Arduino.h"

// crear la clase
class Ultrasonico{
public:
Ultrasonico();

//crear los voids
void configurarSonico();

void funcionaSonico();


// agregar variables coo booleanas ints o strings

bool waos;

// todo lo que vaya empezado con letras azules
// que no sean voids, irian aqui

 float duracion;
//Sustancia = Distancia
float sustancia;

int pinTrix = 8;
//Pin Echo
int pinEkeko = 9;

int able = 3;
int input1 = 5;
int input2 = 6;

};

#endif