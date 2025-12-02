//hace que exista el archivo y no se declare más de una vez
#ifndef ENCODER_H
#define ENCODER_H

#include "Arduino.h"


class Encoder {
  public:
  Encoder();
  //establece las funciones que van a realizar los componentes
  void prepararEncoder();
  void usarEncoder();

// variables de la  manivela
int step = 0;
int currentStateCLK;
int lastStateCLK;
int vueltas;
int rango;
String currentDir = "" ;
unsigned long lastButtonPress = 0;


// establecer donde estara conectado cada pin
int CLK = 9;
int DT = 10;
int SW = 11;


};

#endif 