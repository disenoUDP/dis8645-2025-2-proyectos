#include "Manivela.h"
#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    manivela.configurar();
}

void loop(){
    manivela.calculoVueltas();
    Serial.print("Direccion: ");
    Serial.print(manivela.direccionActual);
    Serial.print(" | Paso: ");
    Serial.println(manivela.paso);
    Serial.print(" | Vueltas: ");
    Serial.println(manivela.getVueltas());
}
