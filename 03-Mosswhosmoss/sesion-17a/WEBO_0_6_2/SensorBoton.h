#ifndef SENSOR_BOTON_H
#define SENSOR_BOTON_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR
 #include <arduino.h>

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
  int botonPin = 11;

  // establecer la cantidad de segundos iniciales
  int segundos = 15;

  // establecer la cantidad de minutos iniciales, que no estan siendo ocupados por ahora
  int minutos = 0;




};
#endif