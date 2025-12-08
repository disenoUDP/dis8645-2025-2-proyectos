#ifndef SENSOR_FUERZA_H // si no esta Sensor fuerza definido
#define SENSOR_FUERZA_H // aqui lo definimos 

#include <Arduino.h>  // incluimos las funciones basicas de arduino

class SensorFuerza {     // definimos la clase sensor fuerza
public:
  SensorFuerza();  // constructor
  ~SensorFuerza(); // destructor

  void configurar(int nuevaPatita); // guarda en que pin se encuentra el sensor
  void leer();  // declara la funcion para leer el sensor

  int patita;       // guarda el numero del pin (A0,A1)
  int valorCrudo;   // guarda el numero del sensor, entre 0 a 1023 (segun presion)
  int valorMapeado; 
};

#endif
