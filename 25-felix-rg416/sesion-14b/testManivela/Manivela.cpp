#include "Manivela.h"

Manivela::Manivela() {}

Manivela::~Manivela() {}

void Manivela::configurar() {
    pinMode(Manivela::patitaCLK, INPUT);
    pinMode(Manivela::patitaDT, INPUT);
    pinMode(Manivela::patitaSW, INPUT_PULLUP);

    Manivela::ultimoEstadoCLK = digitalRead(Manivela::patitaCLK);

    Manivela::vueltas = 0;
}

void Manivela::calculoVueltas() {
    Manivela::estadoActualCLK = digitalRead(Manivela::patitaCLK);
    if (Manivela::estadoActualCLK !=
        Manivela::ultimoEstadoCLK) {

            if (digitalRead(Manivela::patitaDT) !=
                Manivela::estadoActualCLK) {
                Manivela::paso++;
                Manivela::direccionActual = "CW";
            } else {
                Manivela::paso--;
                Manivela::direccionActual = "CCW";
            }

            if (Manivela::paso == Manivela::vueltas * 20) {
                Manivela::vueltas++;
            }

void rangos() {
    if (vueltas >= 0 && vueltas <= 1) {
        rango0();
    } else if (vueltas >= 2 && vueltas <= 8) {
        rango1();
    } else if (vueltas >= 9 && vueltas <= 16) {
        rango2();
    } else if (vueltas >= 17 && vueltas <= 24) {
        rango3();
    } else if (vueltas >= 25 && vueltas <= 29) {
        rango4();
    } else if (vueltas >= 30) {
        rango5();
    }
}