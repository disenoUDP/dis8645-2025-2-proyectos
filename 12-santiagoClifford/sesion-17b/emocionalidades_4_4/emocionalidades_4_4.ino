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

// declarar instancias de cada clase
ActuadorN3P n3p;
SensorDePresion depresion;
MotorMarvel motoMoto;
ActuadorSielvo sielvoLumbar;
ActuadorSielvo sielvoRotor;
SensorSonic hedgehog;

int estadoActual = 0;
int estadoAnterior = -1;

// bool estadoAct0;
// bool estadoAct1;
// bool estadoAct1;
// bool estadoAct1;

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

unsigned long inicioEstado1 = 0;
unsigned long duracionEstado1 = 10000;
unsigned long inicioEstado2 = 0;
unsigned long duracionEstado2 = 20000;
unsigned long inicioEstado3 = 0;
unsigned long duracionEstado3 = 30000;
unsigned long inicioEstado4 = 0;
unsigned long duracionEstado4 = 40000;

unsigned long momentoCambioEstado = 0;

void setup() {
  n3p.configurar();
  depresion.configurarDePresion();
  motoMoto.Setear();
  hedgehog.configurarSonic();
  Serial.begin(9600);
}

void loop() {
  // guardar estadoAnterior
  // si sensor de presion detecta presion, abrazar = true
  depresion.funcionaDePresion();
  hedgehog.funcionaSonic();

  //estadoAnterior = estadoActual;
  // actualizar lecturas de sensores
  // o detectar si es hora de volver a estado 0
  // if (millis() - momentoCambioEstado) > tiempoQueDuraEstado4,
  // entonces estadoActual = 0
  // definir estado actual
  // detectar si hubo cambio de estado

  //   if (estadoActual != estadoAnterior) {
  //  estadoAnterior = estadoActual;
  if (estadoActual == 0) {

    Serial.println("ESTADO: 0_CALMAO");
    // si ultrasonico detecta presencia
    // paso al estado 1
    if (hedgehog.carinoPotencial) {
      estadoAnterior = estadoActual;
      estadoActual = 1;
      // enEstado1 = true;
      inicioEstado1 = millis();
      hedgehog.carinoPotencial = false;
      Serial.println("transicion -> estado 1_PEDIR_AMOR");
    }
  } else if (estadoActual != estadoAnterior && estadoActual == 1) {
    Serial.println(depresion.valorDePresion);
    Serial.println("ESTADO: 1_PEDIR_AMOR");

    if (millis() - inicioEstado1 >= duracionEstado1) {
      estadoActual = 2;
    } else {
      // // emitir audio del estado 1
      n3p.emitirAlarmaEstado1();
      // modulito.volume(2);

      // Serial.println(depresion.valorDePresion);
      if (depresion.watitaRascada == true) {
        Serial.print("WATOM");
        motoMoto.abrazar();

        Serial.println("transicion -> estado 0_CALMAO (por presion)");
        // hedgehog.carinoPotencial=false;
        // estadoAnterior = estadoActual;
        estadoActual = 0;
        // enEstado1 = false;
      }
    }
  } else if (estadoActual != estadoAnterior && estadoActual == 2) {
    Serial.println("ESTADO: 2_PATALETA_LEVE");
    inicioEstado2 = millis();

    if (millis() - inicioEstado2 >= duracionEstado2) {

      estadoActual = 3;
    } else {

      // emitir audio del estado 2
      // emitir audio del estado 1
      n3p.emitirAlarmaEstado2();
      if (depresion.watitaRascada == true) {
        Serial.print("WATOM");
        motoMoto.abrazar();

        Serial.println("transicion -> estado 0_CALMAO (por presion)");
        // hedgehog.carinoPotencial=false;
        // estadoAnterior = estadoActual;
        estadoActual = 0;
        // enEstado1 = false;
      }
    }
  } else if (estadoActual != estadoAnterior && estadoActual == 3) {
    Serial.println("ESTADO: 3_PATALETA_BRIGIDA");
    inicioEstado3 = millis();
    if (millis() - inicioEstado3 >= duracionEstado3) {

      estadoActual = 4;
    } else {

      // emitir audio del estado 2
      // emitir audio del estado 1
      n3p.emitirAlarmaEstado3();
      if (depresion.watitaRascada == true) {
        motoMoto.abrazar();
        Serial.print("WATOM");
        

        Serial.println("transicion -> estado 0_CALMAO (por presion)");
        // hedgehog.carinoPotencial=false;
        // estadoAnterior = estadoActual;
        estadoActual = 0;
        // enEstado1 = false;
      }
    }
  } else if (estadoActual != estadoAnterior && estadoActual == 4) {
    Serial.println("ESTADO: 4_AUTODESTRUCCION");
    inicioEstado4 = millis();

    if (millis() - inicioEstado4 >= duracionEstado4) {

      estadoActual = 0;
    } else {

      // emitir audio del estado 2
      // emitir audio del estado 1
      n3p.emitirAlarmaEstado4();
      if (depresion.watitaRascada == true) {
        Serial.print("WATOM");
        motoMoto.abrazar();

        Serial.println("transicion -> estado 0_CALMAO (por presion)");
        // hedgehog.carinoPotencial=false;
        // estadoAnterior = estadoActual;
        estadoActual = 0;
        // enEstado1 = false;
      }
    }
  }
}

// si sensor de presion pasa de PRESION A NO PRESION
// abrazar = false
// paso a estado = 2

//   } else if (estadoActual == 2) {
//     // n3p.audioYaSonoEstado1 = false;
//     //  if (tiempoActual - tiempoTranscurrido >= intervaloE2) {
//     Serial.println("ESTADO: 2_PATALETA_LEVE");

//     // emitir audio del estado 2
//     n3p.emitirAlarmaEstado2();
//     // cuando pasa cierto tiempo asociado a estado 2
//     // pasa al estado 3
//     // pero si sensa presion vuelve al estado 0
//     depresion.funcionaDePresion();
//     if (depresion.watitaRascada == true) {
//       motoMoto.abrazar();
//       estadoActual = 0;
//     }
//     // } else {
//     estadoActual = 3;

//   } else if (estadoActual == 3) {
//     // if (tiempoActual - tiempoTranscurrido >= intervaloE3) {
//     Serial.println("ESTADO: 3_PATALETA_BRIGIDA");

//     // emitir audio del estado 3
//     // n3p.emitirAlarma(estadoActual);

//     // simultaneamente mueve el motor DC
//     // despues de cierto tiempo asociado a estado 3
//     // pasa al estado 4
//     // pero si sensa presion vuelve al estado 0
//     depresion.funcionaDePresion();
//     if (depresion.watitaRascada == true) {
//       motoMoto.abrazar();
//       estadoActual = 0;

//       // } else {
//       estadoActual = 4;
//     }
//   } else if (estadoActual == 4) {
//     // tiempoActual = 0;
//     // tiempoTranscurrido = millis();
//     // if (tiempoActual - tiempoTranscurrido >= intervaloE4) {
//     Serial.println("ESTADO: AUTODESTRUCCION");

//     // emitir audio del estado 4
//     // n3p.emitirAlarma(estadoActual);
//     // mientras suena
//     // simultaneamente mueve el motor servo de rotacion
//     sielvoRotor.SielvoRotar();
//     // simultaneamente abrazo = true
//     motoMoto.abrazar();
//     // cuando termina la rotacion del motor servo
//     // se mueve el servo lumbar
//     sielvoLumbar.SielvoAflijir();
//     // tras terminar servo lumbar
//     // despues de cierto tiempo asociado a estado 4
//     // pasa al estado 0

//     // pasa al estado 0 inmediatamente
//     // si sensa presion en cualquier momento
//     // } else {
//     // estadoActual = 0;
//   }
//    estadoAnterior = estadoActual;
// }


// }
