//WEBO
// Toma mango
// Aqui pasaran todas las interacciones entre todos los componentes

#include "ActuadorDisplay.h"
#include "ActuadorLED.h"
#include "ActuadorMotor.h"
#include "SensorBoton.h"
#include "SensorTilt.h"
#include "SensorSD.h"

// sensor y actuador correspondientes
 ActuadorDisplay actuadorDisplay;
 ActuadorLED actuadorLED;
 ActuadorMotor actuadorMotor;
 SensorBoton sensorBoton;
 SensorTilt sensorTilt;
 SensorSD sensorSD;

void setup () {
  sensorTilt.configuracionTilt();
  actuadorDisplay.configuracionDisplay();
  sensorBoton.configuracionBoton();
  sensorSD.configuracionSD();
  actuadorMotor.configuracionMotor();
}

void loop() {
  sensorTilt.funcionaTilt();
  actuadorDisplay.funcionaDisplay();
  sensorBoton.funcionaBoton();
  sensorSD.funcionaSDAlarmaFuerte();
  actuadorMotor.funcionaMotor();
}