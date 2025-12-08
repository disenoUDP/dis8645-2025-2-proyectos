#include "Acelerometro.h"

Acelerometro accelManager;

void setup() {
  Serial.begin(9600);
  Serial.println("Accelerometer Test\n");

  accelManager.iniciar();
  accelManager.displaySensorDetails();
}

void loop() {
  accelManager.actualizar();
  accelManager.imprimirDatos();
  delay(200);
}
