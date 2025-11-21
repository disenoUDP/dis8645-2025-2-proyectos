#ifndef SENSOR_SD_H
#define SENSOR_SD_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>



// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
  class SensorSD {
  public:
  SensorSD();
// especificar todos los voids que seran utilizados en el archivo.cpp
  void configuracionSD();
  void funcionaSDAlarmaFuerte();
  void funcionaSDAlarmaDebil();

// si es que se necesitas especificar variables, deberian ir aqui
// ya sean bool int, ect.


};
#endif