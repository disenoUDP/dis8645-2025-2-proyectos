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
  void funcionaTilt();

// si es que se necesitas especificar variables, deberian ir aqui
// ya sean bool int, ect.
  
  
  const int tiltPin = 10;	

  //El estado actual de la lectura del sensor
  int tiltState;
  //La lectura previa del sensor
  int lastTiltState = LOW;	

  //Para almacenar el ultimo evento de inclinación y tiempo de rebote 
  unsigned long time = 0;		
  unsigned long debounceDelay = 50;	  

};
#endif