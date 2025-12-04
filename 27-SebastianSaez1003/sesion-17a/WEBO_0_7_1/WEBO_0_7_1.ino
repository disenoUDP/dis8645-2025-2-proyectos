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
  // tiene que funcionar el sensor tilt, de eso depende el estado de la maquina
  sensorTilt.funcionaTilt();
  // que el temporizador y el aumento de la cantidad de segundos funcione
  sensorBoton.funcionaBoton();

  actuadorDisplay.duermeDisplay();
  // si es que el valor de "caido" es falso, osea que esta parado

  if (sensorTilt.caido == false) {
    // asegurarme que el valor de waoses sean los segundos del boton
    // por si cambia segun el boton ha sido presionado, el display tambien recibira el cambio
    actuadorDisplay.waoses = sensorBoton.segundos;
    // mostrar la pantalla de Ava que hace la cuenta regresiva
    actuadorDisplay.cuentaDisplay();
    // que funcione el motor, ya que no esta establecida la manera de saber
    // si han pasado 30 segundos aun, este se activara cada 10 segundos constantemente
    actuadorMotor.funcionaMotor();
    // si el temporizador mostrado por Ava llega a un numero menor a 1
    if (actuadorDisplay.waoses < 1) {
      // sonara la alarma despacio, para no molestar al usuario
      sensorSD.funcionaSDAlarmaDebil();
    }
  }

  else {
    // como aqui esta inclinado, empezara a sonar la alarma fuerte
    // no se porque para todo al reproducir un archivo de audio
    sensorSD.funcionaSDAlarmaFuerte();
    sensorTilt.funcionaTilt();
  }
}
