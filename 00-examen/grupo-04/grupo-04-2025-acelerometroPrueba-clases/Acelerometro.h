#ifndef ACELEROMETRO_H
#define ACELEROMETRO_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

class Acelerometro {
public:

   Acelerometro();  // constructor
  ~Acelerometro(); // destructor


  void iniciar();
  void actualizar();
  void imprimirDatos();

  void displaySensorDetails();
  void displayDataRate();
  void displayRange();

private:
  Adafruit_ADXL345_Unified accel;

  float xRaw, yRaw, zRaw;
  float xAbs, yAbs, zAbs;
  float totalMovement;
};

#endif
