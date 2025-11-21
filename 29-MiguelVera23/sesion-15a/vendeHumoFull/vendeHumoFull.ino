#include <Arduino.h>
#include "audioHumo.h"
#include "encoder.h"
#include "leds.h"



void setup(){
 prepEncoder();
 prepAudio();
 prepLuces();
}

void loop(){
 actuarEncoder();
 actuarAudio();
 actuarLuces();
}