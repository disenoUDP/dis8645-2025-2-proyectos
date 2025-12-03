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
  void apagaMotor();

  // si es que se necesita especificar variables, deberian ir aqui
  // ya sean bool int, ect.

  // pin al que será conectado el motor para ser controlado
  int motorPin = 9;

  // tiempo el cual ha pasado desde la ultima actualizacion del temporizador
  int tiempoNuevoTemporizadorPrendido = millis();

  // tiempo el cual ha pasado desde la ultima actualizacion del temporizador
  int tiempoNuevoTemporizadorApagado = millis();

  // cuantos milisegundos durara prendido el motor
  int intervaloMotorPrendido = 4000;

  // cuantos milisegundos durara apagado el motor
  int intervaloMotorApagado = 2000;

  int tiempoActual = 0;

  bool motorPrendido = true; 

};
#endif