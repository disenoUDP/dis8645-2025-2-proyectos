// incluir 1 clase para recibir datos de sensores
// incluir 1 clase para emitir datos segun eso

#include "SensorFuerza.h" // incluye las clases SensorFuerza y Puntito

SensorFuerza ejeX;
SensorFuerza ejeY;
// Puntito puntito;

void setup() {
  Serial.begin(9600);
  ejeX.configurar(A0);   // se asigna un sensor al pinA0
  ejeY.configurar(A1);   // se asigna un sensor al pinA1
}

void loop() {   // se actualiza el valor del sensor del eje X y del eje Y
  ejeX.leer();
  ejeY.leer();

  Serial.println(ejeX.valorCrudo);  // manda al serial monitor el valor crudo del sensor X
  Serial.println(ejeY.valorCrudo);

  Serial.print("valorX");
  Serial.print(",");
  Serial.println("valorY");

  delay(40);
  // enviar valores a p5
  // enviar valor ejeX.valorCrudo
  // luego enviar ejeY.valorCrudo
  // Serial.write(ejeX.valorCrudo, ejeY.valorCrudo);
}
