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
  String currentDir = "";
  unsigned long lastButtonPress = 0;
  bool giroReproducirAudio = false;
  int vueltaAnterior = 0;
  int vueltaActual = 0;


  // establecer donde estara conectado cada pin
  int CLK = 9;
  int DT = 10;
  int SW = 11;

//para que sepa cuanto tiempo ha pasado desde la última comparación de tiempo
  int tiempoActualEncoder = 0;
//la cantidad de tiempo que ha estado prendido el arduino
  int tiempoNuevoEncoder = millis();
//cuanto tiempo quiero que se pause
  int cantidadDeTiempo = 5000;

  int reiniciarTodo = 0;
};

#endif