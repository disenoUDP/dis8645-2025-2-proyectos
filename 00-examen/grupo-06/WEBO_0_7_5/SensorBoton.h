#ifndef SENSOR_BOTON_H
#define SENSOR_BOTON_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR
#include "TimersMillis.h"

// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
class SensorBoton {
public:
  SensorBoton();
  // especificar todos los voids que seran utilizados en el archivo.cpp
  void configuracionBoton();
  void funcionaBoton();

  // si es que se necesita especificar variables, deberian ir aqui
  // ya sean bool int, ect.

  // escribir una booleana para representar si el boton esta prendido o no
  bool estadoBoton = false;

  // el pin 11 del arduino es donde sera recibida la señal
  int botonPin = A1;

  // prueba de la aplicacion de millis
  int tiempoActualTemporizador = 0;

  // tiempo el cual ha pasado desde la ultima actualizacion del temporizador
  int tiempoNuevoTemporizador = millis();
};
#endif