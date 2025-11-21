// Entradas del encoder rotatorio
#define CLK 6
#define DT 7
#define SW 8

// Entradas de los leds
#define led1 1
#define led2 2
#define led3 3
#define led4 4
#define led5 5

// variables de la  manivela
int step = 0;
int currentStateCLK;
int lastStateCLK;
int vueltas;
int rango;
String currentDir = "";
unsigned long lastButtonPress = 0;

void setup() {
	Serial.begin(9600);

	// define los pines del encoder como entradas
	pinMode(CLK, INPUT);
	pinMode(DT, INPUT);
	pinMode(SW, INPUT_PULLUP);

	// definir los pines de los leds como salidas
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);
	pinMode(led5, OUTPUT);

	// lee el estado inicial del CLK
	lastStateCLK = digitalRead(CLK);
}

void loop() {

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
		}

		// --- CALCULO DE RANGOS ---
		if (vueltas >= 0 && vueltas <= 1) {
			rango = 0;
		} else if (vueltas >= 2 && vueltas <= 3) {
			rango = 1;
		} else if (vueltas >= 4 && vueltas <= 5) {
			rango = 2;
		} else if (vueltas >= 6 && vueltas <= 7) {
			rango = 3;
		} else if (vueltas >= 8 && vueltas <= 9) {
			rango = 4;
		} else if (vueltas >= 10) {
			rango = 5;
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
	// Ponga un ligero retardo para ayudar a eliminar el rebote de la //lectura
	delay(1);

	// -------------
	//  INICIO LEDS
	// -------------

	if (rango == 1) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, LOW);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}

	if (rango == 2) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}
	if (rango == 3) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}
	if (rango == 4) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, HIGH);
		digitalWrite(led5, LOW);
	}
	if (rango == 5) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, HIGH);
		digitalWrite(led5, HIGH);
	}
}