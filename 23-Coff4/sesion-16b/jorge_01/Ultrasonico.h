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

void leerDistancia();

long Distancia;


// agregar variables coo booleanas ints o strings



// todo lo que vaya empezado con letras azules
// que no sean voids, irian aqui

 float duracion;
//Sustancia = Distancia
float sustancia;

int pinTrix = 9;
//Pin Echo
int pinEkeko = 8;

bool persona;



};

#endif