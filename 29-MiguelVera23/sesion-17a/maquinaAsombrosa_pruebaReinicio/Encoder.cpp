#include "Encoder.h"

Encoder::Encoder() {}

void Encoder::prepararEncoder() {
	Serial.begin(9600);

	// define los pines del encoder como entradas
	pinMode(CLK, INPUT);
	pinMode(DT, INPUT);
	pinMode(SW, INPUT_PULLUP);

	// lee el estado inicial del CLK
	lastStateCLK = digitalRead(CLK);
}


void Encoder::usarEncoder() {
	// -----------------
	//  INICIO MANIVELA
	// -----------------

	// --- CALCULO DE VUELTAS ---

	// Lee el estado actual del CLK
	currentStateCLK = digitalRead(CLK);

	// si los ultimos estado actuales del CLK son diferentes entonces ocurrió un pulso
	// reacciona solo a 1 cambio de estado para evitar un doble conteo
	if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

		// lee el estado del DT para determinar la direccion
		// dependiendo de si es si va en sentido horario o antihorario
		if (digitalRead(DT) != currentStateCLK) {
			step++;
			currentDir = "CW";
		} else {
			step--;
			currentDir = "CCW";
		}

		if (step % 20 == 0) {
			vueltas++;
			//al completar una vuelta se alimenta la función vuelta actual
			//al aumentar se reproduce audio
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
			Serial.println("PERAME PORFAVOR");
			//step = 0;	
			//tiempoNuevoEncoder = tiempoActualEncoder;


			
			
		}

		// --- IMPRESION EN EL MONITOR SERIAL ---
		Serial.print(" | Step: ");
		Serial.println(step);
		Serial.print(" | Vueltas ");
		Serial.println(vueltas);
		Serial.print(" | Rango ");
		Serial.println(rango);
	}

	// guardar el ultimo estado de CLK
	lastStateCLK = currentStateCLK;
	// lee el estado del boton
	int btnState = digitalRead(SW);

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

//función que reinicia la cuenta de todos los valores del encoder al pasar por el rango 6
if (rango > 1){
	//if (tiempoActualEncoder - tiempoNuevoEncoder >= cantidadDeTiempo){
    step = reiniciarTodo;
    rango = reiniciarTodo;
		vueltas = reiniciarTodo;
	//	tiempoNuevoEncoder = tiempoActualEncoder;
  //}
}


	// Ponga un ligero retardo para ayudar a eliminar el rebote de la //lectura
	delay(1);
}