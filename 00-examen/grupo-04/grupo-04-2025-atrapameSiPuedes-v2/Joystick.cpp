#include "Joystick.h"
#include <Arduino.h>

Joystick::Joystick()
    : valorX(0), valorY(0), boton(1),
      _pinVRX(A3), _pinVRY(A2), _pinSW(7) {}   // definimos los pines

void Joystick::configurar(int pinVRX, int pinVRY, int pinSW) {   // configuramos los pines
    _pinVRX = pinVRX;
    _pinVRY = pinVRY;
    _pinSW = pinSW;

    pinMode(_pinSW, INPUT_PULLUP);
}

void Joystick::leer() {
    valorX = analogRead(_pinVRX);
    valorY = analogRead(_pinVRY);
    boton = digitalRead(_pinSW);  // 1 = suelto, 0 = apretado
}
