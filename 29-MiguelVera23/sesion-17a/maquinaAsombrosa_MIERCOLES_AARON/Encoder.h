#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder {
public:
  // constructor
  Encoder();
  
  // funciones
  void preparar();
  void leer();

  // constantes para conexiones
  const int patitaCLK = 9;
  const int patitaDT = 10;
  const int patitaSW = 11;

  // variables de la manivela
  int paso = 0;
  int estadoActualClock;
  int estadoAnteriorClock;
  int vueltas;
  int rango;
  String direccionActual = "";
  unsigned long lastButtonPress = 0;
  bool giroReproducirAudio = false;
  int vueltaAnterior = 0;
  int vueltaActual = 0;

  // para que sepa cuanto tiempo ha pasado desde la última comparación de tiempo
  int tiempoActualEncoder = 0;
  // la cantidad de tiempo que ha estado prendido el arduino
  int tiempoNuevoEncoder = millis();
  // cuanto tiempo quiero que se pause
  int cantidadDeTiempo = 5000;

  int reiniciarTodo = 0;
};

#endif