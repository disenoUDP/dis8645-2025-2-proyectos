#include "SensorN3P.h"

const int f1a0 = 0;
const int f1a1 = 1;
const int f1a2 = 2;

const int f2a0 = 0;
const int f2a1 = 1;
const int f2a2 = 2;


int audiosFase1[] = {f1a1, f1a2, f1a3};
int audiosFase2[] = {f2a0, f2a1, f1a3};


 SensorN3P sensorN3p;

 void setup(){
  sensorN3p.seteoN3P();
 }

 void loop(){
    sensorN3p.alarma1();
 }