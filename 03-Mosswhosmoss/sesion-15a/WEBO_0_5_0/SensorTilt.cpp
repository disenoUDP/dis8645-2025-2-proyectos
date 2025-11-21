#include "SensorTilt.h"

SensorTilt::SensorTilt() {}

void SensorTilt::configuracionTilt(){
  
  //Aca definimos el pin del sensor como entrada 
  //Habilitamos el pull-up interno para el pin del sensor
  pinMode(tiltPin, INPUT);
	digitalWrite(tiltPin, HIGH);
}

void SensorTilt::funcionaTilt(){

  //Lee el estado de inclinación del sensor
	tiltState = digitalRead(tiltPin);

	//Si el sensor esta inclinado
	if (tiltState != lastTiltState) {
		//Se reestablece el temporizador de rebote
		time = millis();
	}

	if ((millis() - time) > debounceDelay) {
		//Sea cual sea la posición del interruptor, lleva ahi mucho tiempo
		// so lets settle on it!
		tiltState;
	}
	

	//Se guarda el ultimo estado de inclinacion, para mantener el recuento actualizado
	lastTiltState = tiltState;
}