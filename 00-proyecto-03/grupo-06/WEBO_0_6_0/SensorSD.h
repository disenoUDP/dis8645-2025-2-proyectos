#ifndef SENSOR_SD_H
#define SENSOR_SD_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR
#include <Arduino.h>
#include <SoftwareSerial.h>
// biblioteca de uso del reproductor
#include <DFRobotDFPlayerMini.h>

// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
  class SensorSD {
  public:
  SensorSD();
  // especificar todos los voids que seran utilizados en el archivo.cpp
  void configuracionSD();

  // crear funcion donde ocurrira la reproduccion de una alarma de alto volumen
  void funcionaSDAlarmaFuerte();
  // crear funcion donde ocurrira la reproduccion de una alarma de bajo volumen
  void funcionaSDAlarmaDebil();

// si es que se necesitas especificar variables, deberian ir aqui
// ya sean bool int, ect.


};
#endif