#include "ActuadorN3P.h"

// bool abrazo = false;

// declarar instancia de clase ActuadorN3P
ActuadorN3P n3p;

void setup() {
  n3p.configurar();
  Serial.begin(115200);
}

void loop() {
// llamar a SonicFunacionar(sensor ultrasonico esta "buscando" una presencia a menos de 40cm)
// si el bool "cariñoPotencial" pasa ser positivo, llamar a sensor MotorMarvel, y SensorDePresion
// MotorMarvel esta activo hasta que, en SensorDePresion la bool afirmateCabrito
// 
// llamar a sesnsor presión
}
}