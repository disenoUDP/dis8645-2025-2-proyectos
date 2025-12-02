#include "SensorTilt.h"

SensorTilt::SensorTilt() {}

void SensorTilt::configuracionTilt(){
  
  //Aca definimos el pin del sensor como entrada 
  //Habilitamos el pull-up interno para el pin del sensor
  pinMode(tiltPin, INPUT);
	digitalWrite(tiltPin, HIGH);
}

void SensorTilt::funcionaTilt(){
	 // si se recibe una señal desde el pinSensor
	if(digitalRead(tiltPin)){
		// significa que esta de lado
    caido = true;
	}
 else  {
	// debido a que esta parado, confirmarlo con un mensaje en el monitor serial
	Serial.println("esta parado");

	caido = false;
 }

}