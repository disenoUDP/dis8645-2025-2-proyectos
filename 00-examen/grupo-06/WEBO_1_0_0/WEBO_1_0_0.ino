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
  // Constantemente funciona el sensor de inclinacion, de esto dependen casi todas las siguientes interacciones
  sensorTilt.funcionaTilt();

  // El boton controla el pasar del tiempo, el poder aumentar el temporizador y que lo que aparezca el display sea correcto segun los segundos actuales
  sensorBoton.funcionaBoton();

  // El display muestra a AVA celebrando, siempre y cuando el temporizador termina correctamente con 0 segundos
  actuadorDisplay.celebracionDisplay();


  // Cuando no esta caido, osea:

  //----------------------------------
  //-------- WEBO ESTA PARADO --------
  //----------------------------------

  // Si es que el sensor de inclinacion esta hacia arriba, osea no inclinado
  if (!sensorTilt.caido) {
    // El display muestra el tiempo restante en segundos, con AVA realizando al cuent regresiva
    actuadorDisplay.cuentaDisplay();
    // Que el motor se active y se desactive en intervalos establecidos
    actuadorMotor.funcionaMotor();
    // cuando el motor se activa y esta girando, AVA tambien gira
    actuadorDisplay.girandoDisplay();

    // Siempre y cuando el temporizador sea menor a 1 segundo y recien se va a empezar la interaccion, o despues de la celebracion de AVA, ya que se cansa y se queda dormida
    actuadorDisplay.duermeDisplay();

    // El boton controla el pasar del tiempo, el poder aumentar el temporizador y que lo que aparezca el display sea correcto segun los segundos actuales
    sensorBoton.funcionaBoton();

    if (segundosTiempo < 1 && !estadoDurmiendo) {
      sensorSD.funcionaSDAlarmaFuerte();
    }
  }

  // Cuando esta inclinado, osea:

  //----------------------------------
  //-------- WEBO ESTA CAIDO ---------
  //----------------------------------

  else {
    // suena la pataleta y AVA esta enojada porque se cayo
    actuadorDisplay.caidaDisplay();
    sensorSD.funcionaSDAlarmaFuerte();
  }
}