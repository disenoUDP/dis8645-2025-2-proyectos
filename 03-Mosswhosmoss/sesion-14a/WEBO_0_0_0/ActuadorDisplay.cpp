#include "ActuadorDisplay.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Arduino.h>

// Declarar objeto "LCD" para el software SPI
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

// Definir la variable de "rotatetext" en "1" que hace que la pantalla muestre el texto en un angulo de 90° a la derecha   
int rotatetext = 1;

ActuadorDisplay::ActuadorDisplay() {}

void ActuadorDisplay::configuracionDisplay() {}



void ActuadorDisplay::funcionaDisplay() {}
// Declarar objeto "LCD" para el software SPI
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

// Definir la variable de "rotatetext" en "1" que hace que la pantalla muestre el texto en un angulo de 90° a la derecha   
int rotatetext = 1;

ActuadorDisplay::ActuadorDisplay() {}

void ActuadorDisplay::configuracionDisplay() {

	Serial.begin(9600);

	//Initialize Display
	display.begin();

	// you can change the contrast around to adapt the display for the best viewing!
	display.setContrast(57);

	// Clear the buffer.
	display.clearDisplay();
  
}



void ActuadorDisplay::funcionaDisplay() {

	// Display Text
	display.setTextSize(1);
	display.setTextColor(BLACK);
	display.setCursor(0,0);
	display.println("Hello world!");
	display.display();
	delay(2000);
	display.clearDisplay();

}
