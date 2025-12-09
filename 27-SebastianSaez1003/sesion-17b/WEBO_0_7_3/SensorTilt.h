#ifndef SENSOR_TILT_H
#define SENSOR_TILT_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR
#include "TimersMillis.h"


// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
class SensorTilt {
public:
  SensorTilt();
  // especificar todos los voids que seran utilizados en el archivo.cpp
  void configuracionTilt();
  // que funcione el sensor de inclinacion
  void funcionaTilt();

  // si es que se necesita especificar variables, deberian ir aqui
  // ya sean bool int, ect.

  // establecer el pin en el que se recibira la señal del sensor de inclinacion
  const int tiltPin = 12;

  // una booleana para confirmar si es que esta caido o no
  bool caido = false;

  // una booleana que confirma si es que ha empezado a inclinarse
  bool enProcesoDeCaida = false;

  // considera que es lo leido por el pin digital
  int lecturaActual = 0;

  // la cantidad de tiempo que esta inclinado
  int tiempoInicioCaida = 0;
};
#endif