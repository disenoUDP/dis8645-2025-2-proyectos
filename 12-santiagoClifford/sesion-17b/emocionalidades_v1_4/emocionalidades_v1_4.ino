//incluir archivos de clases
//módulo mp3 tf 16p DFPlayerMini
#include "ActuadorN3P.h"
//sensor de presion
#include "SensorDePresion.h"
//motor DC
#include "MotorMarvel.h"
// servomotores
#include "ActuadorSielvo.h"
// sensor ultrasónico
#include "SensorSonic.h"

// bool abrazo = false;

// declarar instancias de cada clase
ActuadorN3P n3p;
SensorDePresion depresion;
MotorMarvel motoMoto;
ActuadorSielvo sielvoLumbar;
ActuadorSielvo sielvoRotor;
SensorSonic hedgehog;

// parte en estado 0
// estados 0, 1, 2, 3 pueden avanzar al siguiente
// estados 2, 3, 4 pueden volver al 0
// estado 4 tras terminar vuelve al 0

// ESTADOS
// 0_CALMAO: sensor ultrasonico
// 1_PEDIR_AMOR: sensor de presion
// 2_PATALETA_LEVE: mp3
// 3_PATALETA_BRIGIDA: servo columna, mp3
// 4_AUTODESTRUCCION: servo rotacion, servo columna, mp3, motorDC

// parte en estado 0
int estadoActual = 0;
int estadoAnterior = 0;

int tiempoActual;
int tiempoTranscurrido;

int intervaloE2 = 8000;
int intervaloE3 = 10000;
int intervaloE4 = 20000;

unsigned long momentoCambioEstado;

void setup() {
  n3p.configurar();
  depresion.configurarDePresion();
  motoMoto.Setear();
  hedgehog.configurarSonic();
  Serial.begin(115200);
}

void loop() {
  // guardar estadoAnterior
  estadoAnterior = estadoActual;
  // actualizar lecturas de sensores
  // o detectar si es hora de volver a estado 0
  // if (millis() - momentoCambioEstado) > tiempoQueDuraEstado4,
  // entonces estadoActual = 0
  // definir estado actual
  // detectar si hubo cambio de estado
  if (estadoActual != estadoAnterior) {

    if (estadoActual == 0) {
      Serial.println("ESTADO: 0_CALMAO");
      depresion.funcionaDePresion();
      if (depresion.watitaRascada == true) {
        motoMoto.abrazar();
      }
      // si ultrasonico detecta presencia
      // paso al estado 1
      hedgehog.funcionaSonic();
      if (hedgehog.carinoPotencial) {
        estadoActual = 1;
      }
    } else if (estadoActual == 1) {
      Serial.println("ESTADO: 1_PEDIR_AMOR");

      // emitir audio del estado 1
      n3p.emitirAlarma(estadoActual);
      // si sensor de presion detecta presion, abrazar = true
      depresion.funcionaDePresion();
      if (depresion.watitaRascada == true) {
        motoMoto.abrazar();
        estadoActual = 0;
      }

      // si sensor de presion pasa de PRESION A NO PRESION
      // abrazar = false
      // paso a estado = 2


    } else if (estadoActual == 2) {
      if (tiempoActual - tiempoTranscurrido >= intervaloE2) {
      Serial.println("ESTADO: 2_PATALETA_LEVE");

        // emitir audio del estado 2
        n3p.emitirAlarma(estadoActual);
        // cuando pasa cierto tiempo asociado a estado 2
        // pasa al estado 3
        // pero si sensa presion vuelve al estado 0
        depresion.funcionaDePresion();
        if (depresion.watitaRascada == true) {
          motoMoto.abrazar();
          estadoActual = 0;
        }
      } else {
        estadoActual = 3;
      }
    } else if (estadoActual == 3) {
      if (tiempoActual - tiempoTranscurrido >= intervaloE3) {
      Serial.println("ESTADO: 3_PATALETA_BRIGIDA");

        // emitir audio del estado 3
        n3p.emitirAlarma(estadoActual);

        // simultaneamente mueve el motor DC
        // despues de cierto tiempo asociado a estado 3
        // pasa al estado 4
        // pero si sensa presion vuelve al estado 0
        depresion.funcionaDePresion();
        if (depresion.watitaRascada == true) {
          motoMoto.abrazar();
          estadoActual = 0;

        } else {
          estadoActual = 4;
        }
      } else if (estadoActual == 4) {
        tiempoActual = 0;
        tiempoTranscurrido = millis();
        if (tiempoActual - tiempoTranscurrido >= intervaloE4) {
      Serial.println("ESTADO: AUTODESTRUCCION");

          // emitir audio del estado 4
          n3p.emitirAlarma(estadoActual);
          // mientras suena
          // simultaneamente mueve el motor servo de rotacion
          sielvoRotor.SielvoRotar();
          // simultaneamente abrazo = true
          motoMoto.abrazar();
          // cuando termina la rotacion del motor servo
          // se mueve el servo lumbar
          sielvoLumbar.SielvoAflijir();
          // tras terminar servo lumbar
          // despues de cierto tiempo asociado a estado 4
          // pasa al estado 0

          // pasa al estado 0 inmediatamente
          // si sensa presion en cualquier momento
        } else {
          estadoActual = 0;
        }
      }
    }
  }
}
