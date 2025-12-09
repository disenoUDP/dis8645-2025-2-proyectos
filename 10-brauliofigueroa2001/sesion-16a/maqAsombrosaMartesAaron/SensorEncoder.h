//hace que exista el archivo y no se declare más de una vez
#ifndef SENSOR_ENCODER_H
#define SENSOR_ENCODER_H

#include <Arduino.h>
#include <RotaryEncoder.h>


class SensorEncoder {
public:
  SensorEncoder();
  // //establece las funciones que van a realizar los componentes
  void preparar();
  void usar();

  // // variables de la  manivela
  // int step = 0;
  // int currentStateCLK;
  // int lastStateCLK;
  // int vueltas;
  // int rango;
  // String currentDir = "";
  // unsigned long lastButtonPress = 0;
  // bool giroReproducirAudio = false;
  int vueltaAnterior = 0;
  int vueltaActual = 0;


  // // establecer donde estara conectado cada pin
  // int CLK = 9;
  // int DT = 10;
  // int SW = 11;
};

#endif