#ifndef SENSOR_TILT_H
#define SENSOR_TILT_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR
#include <Arduino.h>

// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
  class SensorTilt {
  public:
  SensorTilt();
// especificar todos los voids que seran utilizados en el archivo.cpp
  void configuracionTilt();
// que funcione el sensor de inclinacion
  void funcionaTilt();

// si es que se necesitas especificar variables, deberian ir aqui
// ya sean bool int, ect.
  
  // establecer el pin en el que se recibira la señal del sensor de inclinacion
  const int tiltPin = 10;	

  // crear una variable booleana para establecer si esta caida la maquina o no
  bool caido;

};
#endif