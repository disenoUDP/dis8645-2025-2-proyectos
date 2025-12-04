#include "ActuadorN3P.h"

// bool abrazo = false;

// declarar instancia de clase ActuadorN3P
ActuadorN3P n3p;

void setup() {
  n3p.configurar();
  Serial.begin(115200);
}

void loop() {

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

//ESTADOS
// 1_CALMAO: sensor ultrasonico
// 2_PEDIR_AMOR: sensor de presion
// 3_PATALETA_LEVE: mp3
// 4_PATALETA_BRIGIDA: servo columna, mp3
// 5_AUTODESTRUCCION: servo rotacion, servo columna, mp3, motorDC
}