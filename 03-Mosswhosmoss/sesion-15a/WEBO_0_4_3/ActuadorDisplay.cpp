#include "ActuadorDisplay.h"
#include "bitmapsDisplay.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Arduino.h>


ActuadorDisplay::ActuadorDisplay() {}

void ActuadorDisplay::configuracionDisplay() {

  Serial.begin(9600);

	//se inicia el display de la pantalla
	display.begin();

	// El contraste se puede cambiar para que se note mejor el diseño mostrado en la pantalla
	display.setContrast(57);

	// se limpia la pantalla
	display.clearDisplay();
}

void ActuadorDisplay::funcionaDisplay() {

  // IMAGEN

	display.drawBitmap(0, 0, epd_bitmap_prueba, 48, 49, BLACK);

	display.display();
}



