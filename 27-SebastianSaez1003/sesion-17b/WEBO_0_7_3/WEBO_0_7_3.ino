//WEBO
// Toma mango
// Aqui pasaran todas las interacciones entre todos los componentes

#include "ActuadorDisplay.h"
#include "ActuadorMotor.h"
#include "SensorBoton.h"
#include "SensorTilt.h"
#include "SensorSD.h"

// sensor y actuador correspondientes
ActuadorDisplay actuadorDisplay;
ActuadorMotor actuadorMotor;
SensorBoton sensorBoton;
SensorTilt sensorTilt;
SensorSD sensorSD;

void setup() {
  sensorTilt.configuracionTilt();
  actuadorDisplay.configuracionDisplay();
  sensorBoton.configuracionBoton();
  sensorSD.configuracionSD();
  actuadorMotor.configuracionMotor();
}

void loop() {
  // Read tilt once per loop
  sensorTilt.funcionaTilt();

  // Read button
  sensorBoton.funcionaBoton();

  // Cuando no esta caido, osea
  //----------------------------------
  //-------- WEBO ESTA PARADO --------
  //----------------------------------
  if (!sensorTilt.caido) {

    // Display countdown
    actuadorDisplay.cuentaDisplay();

    // Display sleeping feature
  actuadorDisplay.duermeDisplay();

    // que funcione constantemente el motor siempre y cuando este parado
    actuadorMotor.funcionaMotor();

    // si es countdown llega a un numero menor que 1
      sensorSD.funcionaSDAlarmaDebil();

   actuadorDisplay.girandoDisplay();
  }
  // Cuando no esta inclinado
  //----------------------------------
  //-------- WEBO ESTA CAIDO ---------
  //----------------------------------
  else {
    // suena la pataleta
    sensorSD.funcionaSDAlarmaFuerte();
  }
}