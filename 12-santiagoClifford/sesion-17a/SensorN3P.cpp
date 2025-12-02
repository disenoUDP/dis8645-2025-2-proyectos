#include "SensorN3P.h"
#include <Arduino.h>

SensorN3P::SensorN3P(){}

void SensorN3P::seteoN3P() {
  Serial.begin(115200);
  dfSerial.begin(9600);
}

void SensorN3P::alarma1() {
  player.volume(20);
  player.play(int audiosFase1[random(0,3)]);
  delay(500);
  Serial.println("rascame la watita xfis :p");
}