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