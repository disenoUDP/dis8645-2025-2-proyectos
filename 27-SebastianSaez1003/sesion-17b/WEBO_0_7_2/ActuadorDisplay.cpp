#include "ActuadorDisplay.h"
#include "bitmapsDisplay.h"


ActuadorDisplay::ActuadorDisplay() {}

void ActuadorDisplay::configuracionDisplay() {

	Serial.begin(9600);

	//se inicia el display de la pantalla
	display.begin();

	// El contraste se puede cambiar para que se note mejor el diseño mostrado en la pantalla
	display.setContrast(60);

	// se limpia la pantalla
	display.clearDisplay();

	// establecer el tamaño del texto
	display.setTextSize(2);

	//Se define el estado
	estado = 0;

	if (waoses < 1) {
		comenzarTemporizador = true;
	} else {
		comenzarTemporizador = false;
	}
}


// el estado del display en el que se hara una cuenta regresiva del temporizador
void ActuadorDisplay::cuentaDisplay() {
	if (waoses <= 0) return;
	tiempoActualDisplay = millis();
	if (avaHablando) {
		if (tiempoActualDisplay - tiempoDisplayHablando >= tiempoDeHabla) {
			Serial.println("Estoy hablando");
			display.setTextSize(2);
			// colocar la posición: x, y, establecer cuál es el bitmap que será utilizado, ancho del bitmap, alto del bitmap, color del bitmap
			// en este caso el estado neutral de Ava
			display.clearDisplay();
			display.drawBitmap(0, 0, bitmap_AVA_HABLA, 48, 48, BLACK);
			// establecer las coordenadas de el siguiente texto
			display.setCursor(56, 16);
			// el texto corresponda al int "waoses"
			display.print(waoses);
			// hacer que estos datos previos se carguen al display
			display.display();
			avaHablando = false;
			tiempoDisplayNoHabla = tiempoActualDisplay;
		}
	} else {
		if (tiempoActualDisplay - tiempoDisplayNoHabla >= tiempoDeHabla) {
			Serial.println("No estoy hablando");
			display.setTextSize(2);
			// limpia la pantalla
			display.clearDisplay();
			// colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
			// en este caso el estado en el que Ava tiene la boca abierta
			// haciendo como si esta diciendo los segundos restantes
			display.drawBitmap(0, 0, bitmap_AVA, 48, 48, BLACK);
			// establecer las coordenadas de el siguiente texto
			display.setCursor(56, 16);
			// el texto corresponda al int "waoses"
			// esto se vuelve a establecer debido a que se limpio la pantalla
			display.print(waoses);
			// hacer que estos datos previos se carguen al display
			display.display();
			//Guardar el tiempo de inicio del display
			avaHablando = true;
			tiempoDisplayHablando = tiempoActualDisplay;
		}
	}
}



// hay que escribir otros voids para los distintos estados de funcionamiento

void ActuadorDisplay::duermeDisplay() {
	if (!comenzarTemporizador && waoses < 1) {
		display.clearDisplay();

		display.setTextSize(0.5);

		// AVA durmiendo en la parte izquierda del display
		display.drawBitmap(0, 0, bitmap_AVA_DUERME, 48, 48, BLACK);

		display.setCursor(56, 16);
		// el texto corresponda al int "waoses"
		// esto se vuelve a establecer debido a que se limpio la pantalla
		display.print(pantallaDeInicio);

		display.display();

		Serial.println("Estoy durmiendo");
	}
}
