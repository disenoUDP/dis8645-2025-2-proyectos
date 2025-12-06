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

// --- FIX: prevent strong alarm from running every loop ---
bool alarmaFuerteActiva = false;

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

  // Display sleeping feature
  actuadorDisplay.duermeDisplay();

  // Cuando no esta caido, osea
  //----------------------------------
  //-------- WEBO ESTA PARADO --------
  //----------------------------------
  if (!sensorTilt.caido) {

    // que los waoses del display equivalen a los segundos que estan siendo contados por el boton
    actuadorDisplay.waoses = sensorBoton.segundos;

    // Display countdown
    actuadorDisplay.cuentaDisplay();

    // que funcione constantemente el motor siempre y cuando este parado
    actuadorMotor.funcionaMotor();

    // si es countdown llega a un numero menor que 1
    if (actuadorDisplay.waoses < 1) {
      sensorSD.funcionaSDAlarmaDebil();
    }
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