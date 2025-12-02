#include "ActuadorDisplay.h"
#include "bitmapsDisplay.h"


ActuadorDisplay::ActuadorDisplay() {}

void ActuadorDisplay::configuracionDisplay() {

  Serial.begin(9600);

	//se inicia el display de la pantalla
	display.begin();

	// El contraste se puede cambiar para que se note mejor el diseño mostrado en la pantalla
	display.setContrast(57);

	// se limpia la pantalla
	display.clearDisplay();

	// establecer el tamaño del texto 
	display.setTextSize(2);
}

	// el estado del display en el que se hara una cuenta regresiva del temporizador
void ActuadorDisplay::cuentaDisplay() {
  // IMAGEN
	// colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
	// en este caso el estado neutral de Ava
	display.drawBitmap(0, 0,bitmap_AVA, 48, 48, BLACK);
	// establecer las coordenadas de el siguiente texto
	display.setCursor(56, 16);
	// el texto corresponda al int "waoses"
	display.print(waoses);
	// hacer que estos datos previos se cargen al display
	display.display();
	// cada medio segundo
	//para que se mantenga la cara por medio segundo
	delay(500);
	// limpia la pantalla
	display.clearDisplay();
	// colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
	// en este caso el estado en el que Ava tiene la boca abierta
	// haciendo como si esta diciendo los segundos restantes
	display.drawBitmap(0, 0,bitmap_AVA_HABLA, 48, 48, BLACK);
	// establecer las coordenadas de el siguiente texto
	display.setCursor(56, 16);
	// el texto corresponda al int "waoses"
	// esto se vuelve a establecer debido a que se limpio la pantalla
	display.print(waoses);
	// hacer que estos datos previos se carguen al display
	display.display();
	// cada medio segundo
	delay(500);
}

// hay que escribir otros voids para los distintos estados de funcionamiento


