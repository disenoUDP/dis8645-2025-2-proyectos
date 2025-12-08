#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick {     // definimos la clase joystick
public:
    Joystick();  
    void configurar(int pinVRX, int pinVRY, int pinSW);  // guarda en que patita se encuentra los valores del joystick
    void leer();    // declara la funcion para leer el joystick

    int valorX;
    int valorY;
    int boton;

private:
    int _pinVRX;
    int _pinVRY;
    int _pinSW;
};

#endif
