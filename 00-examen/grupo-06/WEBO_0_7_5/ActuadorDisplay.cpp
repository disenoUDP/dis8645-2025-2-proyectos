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

	intervaloCelebracion = millis() + 8 * segundoNumero;
}


// el estado del display en el que se hara una cuenta regresiva del temporizador
void ActuadorDisplay::cuentaDisplay() {
	tiempoActualDisplay = millis();
	if (segundosTiempo > 0 && motorPrendido) {
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
				// el texto corresponda al int "segundosTiempo"
				display.print(segundosTiempo);
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
				// el texto corresponda al int "segundosTiempo"
				// esto se vuelve a establecer debido a que se limpio la pantalla
				display.print(segundosTiempo);
				// hacer que estos datos previos se carguen al display
				display.display();
				//Guardar el tiempo de inicio del display
				avaHablando = true;
				tiempoDisplayHablando = tiempoActualDisplay;
			}
		}
	}
}


// hay que escribir otros voids para los distintos estados de funcionamiento

void ActuadorDisplay::duermeDisplay() {
	// si es que el temporizador es menor a 1
	// y esta en el estado de comienzoInteraccion
	// && comienzoInteraccion
	// este comienzoInteraccion que empiece en true cuando se carga el codigo
	// pase a false cuando se presione el boton
	// y que haya un void de AVA celebra, que sea solamente cuando
	// el temporizador es menor a 1 y comienzoInteraccion es false
	// AVA se pondra a celebrar por 5-8 segundos
	// despues de eso se volvera a quedar dormida, reiniciando toda la interaccion
	if (segundosTiempo < 1 && estadoDurmiendo) {

		display.clearDisplay();

		display.setTextSize(1);

		// AVA durmiendo en la parte izquierda del display
		display.drawBitmap(0, 0, bitmap_AVA_DUERME, 48, 48, BLACK);

		display.setCursor(56, 16);
		// el texto corresponda al int "segundosTiempo"
		// esto se vuelve a establecer debido a que se limpio la pantalla
		display.print(pantallaDeInicio);

		display.display();
	}
}


void ActuadorDisplay::girandoDisplay() {
	// si es que el temporizador tiene mas que 0 segundos y el motor esta prendido
	if (segundosTiempo > 0 && !motorPrendido) {
		// cambiar rapidamente los frames del giro de la AVA
		switch (posicionDeGiro) {
			case 0:
				if (tiempoActualDisplay - tiempoDeGiro0 >= cambioGiro) {
					display.setTextSize(2);

					Serial.println("Estoy hablando");
					// colocar la posición: x, y, establecer cuál es el bitmap que será utilizado, ancho del bitmap, alto del bitmap, color del bitmap
					// limpia la pantalla
					display.clearDisplay();

					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);

					display.display();
					// establecer las coordenadas de el siguiente texto
					posicionDeGiro = 1;
					tiempoDeGiro1 = tiempoActualDisplay;
				}
				break;

			case 1:
				if (tiempoActualDisplay - tiempoDeGiro1 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					// colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_TRESCUARTOSIZQ, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// establecer las coordenadas de el siguiente texto
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					posicionDeGiro = 2;
					tiempoDeGiro2 = tiempoActualDisplay;
				}
				break;

			case 2:
				if (tiempoActualDisplay - tiempoDeGiro2 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_PERFILIZQ, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					posicionDeGiro = 3;
					tiempoDeGiro3 = tiempoActualDisplay;
				}
				break;

			case 3:
				if (tiempoActualDisplay - tiempoDeGiro3 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_ESPALDA, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					posicionDeGiro = 4;
					tiempoDeGiro4 = tiempoActualDisplay;
				}
				break;

			case 4:
				if (tiempoActualDisplay - tiempoDeGiro4 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_PERFILDER, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					// esto permite que el giro sea un loop
					posicionDeGiro = 5;
					tiempoDeGiro5 = tiempoActualDisplay;
				}
				break;

			case 5:
				if (tiempoActualDisplay - tiempoDeGiro5 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_TRESCUARTOSDER, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					// esto permite que el giro sea un loop
					posicionDeGiro = 0;
					tiempoDeGiro0 = tiempoActualDisplay;
				}
				break;
		}
	}
}


void ActuadorDisplay::caidaDisplay() {

		display.clearDisplay();
		display.drawBitmap(18, 0, bitmap_AVA_ENOJADA, 48, 48, BLACK);
		// hacer que estos datos previos se carguen al display
		display.display();

	// ESCRIBIR A LA AVA CAYENDOSE
}

void ActuadorDisplay::celebracionDisplay() {
	if (!estadoDurmiendo && segundosTiempo == 0) {
		//setear el tiempo del intervaloCelebracion
		// y también poner que el tiempoNuevoCelebracion sea 0 en un principio
		Serial.print("estoy modo fiesta");
		display.clearDisplay();
		display.drawBitmap(18, 0, bitmap_AVA_SALTO, 48, 48, BLACK);
		// hacer que estos datos previos se carguen al display
		display.display();
		delay(5000);
		estadoDurmiendo = true;
	}
}
