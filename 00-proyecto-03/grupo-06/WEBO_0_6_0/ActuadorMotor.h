#ifndef ACTUADOR_MOTOR_H
#define ACTUADOR_MOTOR_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR
 #include <Arduino.h>

// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
  class ActuadorMotor {
  public:
  ActuadorMotor();
// especificar todos los voids que seran utilizados en el archivo.cpp
  void configuracionMotor();
  void funcionaMotor();

  // si es que se necesitas especificar variables, deberian ir aqui
  // ya sean bool int, ect.

  // pin al que será conectado el motor para ser controlado
  int motorPin = 9;


};
#endif