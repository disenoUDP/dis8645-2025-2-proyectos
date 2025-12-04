#ifndef ACTUADOR_N3P_H
#define ACTUADOR_N3P_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// estados
// 0 - calmao
// 1 - pideAmor
// 2 - pataletaLeve
// 3 - pataletaBrigida
// 4 - autodestruccion

// archivos de audio
// 0 - no hay
// 1 - hay 3
// 2 - hay 3
// 3 - hay 3
// 4 - hay 1, es largo

// const int f1a0 = 0;
// const int f1a1 = 1;
// const int f1a2 = 2;

// const int f2a0 = 0;
// const int f2a1 = 1;
// const int f2a2 = 2;

// int audiosFase1[] = { f1a0, f1a1, f1a2 };
// int audiosFase2[] = { f2a0, f2a1, f1a3 };

class ActuadorN3P {
public:
  // constructor
  ActuadorN3P();
  
  
  void configurar();

  void emitirAlarma(int estado, int distancia);

      SoftwareSerial mp3Serial = SoftwareSerial(10, 11); 
  DFRobotDFPlayerMini modulito;

  // bool debug = false;
};

#endif
