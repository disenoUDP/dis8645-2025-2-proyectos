#include "Encoder.h"

// constructor
Encoder::Encoder() {}

void Encoder::preparar(bool modo) {

  Encoder::emitirSerial = modo;

	// prender el puerto serial
	Serial.begin(9600);

	// define los pines del encoder como entradas
	pinMode(patitaCLK, INPUT);
	pinMode(patitaDT, INPUT);
	pinMode(patitaSW, INPUT_PULLUP);

	// lee el estado inicial del CLK
	estadoAnteriorClock = digitalRead(patitaCLK);
}


void Encoder::leer() {
	// -----------------
	//  INICIO MANIVELA
	// -----------------

	// --- CALCULO DE VUELTAS ---

	// Lee el estado actual del CLK
	estadoActualClock = digitalRead(patitaCLK);

	// si los ultimos estado actuales del CLK son diferentes entonces ocurrió un pulso
	// reacciona solo a 1 cambio de estado para evitar un doble conteo
	if (estadoActualClock != estadoAnteriorClock && estadoActualClock == 1) {

		// lee el estado del DT para determinar la direccion
		// dependiendo de si es si va en sentido horario o antihorario
		if (digitalRead(patitaDT) != estadoActualClock) {
			paso++;
			direccionActual = "CW";
		} else {
			paso--;
			direccionActual = "CCW";
		}

		if (paso % 20 == 0) {
			vueltas++;
			// al completar una vuelta se alimenta la función vuelta actual
			// al aumentar se reproduce audio
			vueltaActual++;
		}

		// --- CALCULO DE RANGOS ---
		if (vueltas >= 0 && vueltas <= 1) {
			rango = 0;
		} else if (vueltas >= 2 && vueltas <= 4) {
			rango = 1;
		} else if (vueltas >= 5 && vueltas <= 7) {
			rango = 2;
		} else if (vueltas >= 8 && vueltas <= 10) {
			rango = 3;
		} else if (vueltas >= 11 && vueltas <= 12) {
			rango = 4;
		} else if (vueltas >= 13 && vueltas <= 14) {
			rango = 5;
		} else if (vueltas >= 15) {
			rango = 6;
			//if (tiempoActualEncoder - tiempoNuevoEncoder >= cantidadDeTiempo){
			// Serial.println("PERAME PORFAVOR");

			//tiempoNuevoEncoder = tiempoActualEncoder;
		}

		// --- IMPRESION EN EL MONITOR SERIAL ---
		if (emitirSerial) {
			Serial.print(" | paso: ");
			Serial.println(paso);
			Serial.print(" | Vueltas ");
			Serial.println(vueltas);
			Serial.print(" | Rango ");
			Serial.println(rango);
		}
	}

	// guardar el ultimo estado de CLK
	estadoAnteriorClock = estadoActualClock;
	// lee el estado del boton
	int btnState = digitalRead(patitaSW);

	//si nosotros detectamos una senal baja, presionamos el boton
	if (btnState == LOW) {
		//si han pasado 50ms desde la ultimo pulso bajo,
		//significa que el botón ha sido presionado,suéltelo y presione otra //vez
		if (millis() - lastButtonPress > 50) {
			Serial.println("Button pressed!");
		}
		// guarda el ultimo evento de pulsación del boton
		lastButtonPress = millis();
	}

	// función que reinicia la cuenta de
	// todos los valores del encoder al pasar por el rango 6
	if (vueltas > 15) {
		//if (tiempoActualEncoder - tiempoNuevoEncoder >= cantidadDeTiempo){
		paso = reiniciarTodo;
		rango = reiniciarTodo;
		vueltas = reiniciarTodo;
		//	tiempoNuevoEncoder = tiempoActualEncoder;
		//}
	}


	// Ponga un ligero delay para ayudar a eliminar el rebote de la //lectura
	delay(1);
}