#include "ActuadorN3P.h"
#include "SensorDePresion.h"
#include "MotorMarvel.h"

// bool abrazo = false;

// declarar instancias de cada clase
ActuadorN3P n3p;
SensorDePresion depresion;
MotorMarvel motoMoto;


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

unsigned long momentoCambioEstado;



void setup() {
  n3p.configurar();
  depresion.configurarDePresion();
  motoMoto.Setear();
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
      depresion.funcionaDePresion();
      if (depresion.watitaRascada == true) {
        motoMoto.abrazar();
      }
      // si ultrasonico detecta presencia
      // paso al estado 1

    } else if (estadoActual == 1) {

      // emitir audio del estado 1
      n3p.emitirAlarma(estadoActual);
      // si sensor de presion detecta presion
      // abrazar = true
      depresion.funcionaDePresion();
      if (depresion.watitaRascada == true) {
        motoMoto.abrazar();
      }

      // si sensor de presion pasa de PRESION A NO PRESION
      // abrazar = false
      // paso a estado = 2


    } else if (estadoActual == 2) {

      // emitir audio del estado 2
      n3p.emitirAlarma(estadoActual);
      // cuando pasa cierto tiempo asociado a estado 2
      // pasa al estado 3
      // pero si sensa presion vuelve al estado 0
      depresion.funcionaDePresion();
      if (depresion.watitaRascada == true) {
        motoMoto.abrazar();
      }
    } else if (estadoActual == 3) {

      // emitir audio del estado 3
      n3p.emitirAlarma(estadoActual);

      // simultaneamente mueve el motor DC
      // despues de cierto tiempo asociado a estado 3
      // pasa al estado 4
      // pero si sensa presion vuelve al estado 0
      depresion.funcionaDePresion();
      if (depresion.watitaRascada == true) {
        motoMoto.abrazar();
      }
    } else if (estadoActual == 4) {

      // emitir audio del estado 4
      n3p.emitirAlarma(estadoActual);
      // mientras suena
      // simultaneamente mueve el motor servo de rotacion
      // simultaneamente abrazo = true
      // cuando termina la rotacion del motor servo
      // se mueve el servo lumbar
      // tras terminar servo lumbar
      // despues de cierto tiempo asociado a estado 4
      // pasa al estado 0

      // pasa al estado 0 inmediatamente
      // si sensa presion en cualquier momento
    }
  }
}


  // llamar a SonicFuncionar(sensor ultrasonico esta "buscando" una presencia a menos de 40cm)
  // si hay presencia a menos de 40cm, el bool "cariñoPotencial" = true,
  // if(cariñoPotencial==true){ ESTADO = 1.PEDIR_AMOR}
  // ESTADO = 1. PEDIR_AMOR -> llamar a N3P::emitirAlarma

  // si SensarTacto  sensa presion, bool watitaRascada=true -> llamar a MotorMarvel::abrazar
  //if(watitaRascada==true){ESTADO = 0.CALMAO}

  // si SensarTacto sensa 0 tacto, bool seMarcho=true
  // if(seMarcho==true){ESTADO = 2. PATALETA_LEVE}
  // si SensarTacto activa la bool watitaRascada -> ESTADO = 0.CALMAO
  //if(watitaRascada==true){ESTADO = 0.CALMAO}


  // si pasan 6 segundos desde que se activo la bool seMarcho, ESTADO = 3. PATALETA_BRIGIDA
  // si SensarTacto activa la bool watitaRascada -> ESTADO = 0. CALMAO
  // if(watitaRascada==true){ESTADO = 0.CALMAO}


  // si pasan 6+9 segundos desde que se activo la bool seMarcho, ESTADO = 4. AUTODESTRUCCION
  // si SensarTacto activa la bool watitaRascada -> ESTADO = 0. CALMAO
  // if(watitaRascada==true){ESTADO = 0.CALMAO}
