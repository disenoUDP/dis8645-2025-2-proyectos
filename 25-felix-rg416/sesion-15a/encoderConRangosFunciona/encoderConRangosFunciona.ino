// Entradas del encoder rotatorio
#define CLK 2
#define DT 3
#define SW 4
int step = 0;
int currentStateCLK;
int lastStateCLK;
int vueltas;
int rango;
String currentDir = "";
unsigned long lastButtonPress = 0;

void setup() {

	// ajusta los pines del encoder como entradas
	pinMode(CLK, INPUT);
	pinMode(DT, INPUT);
	pinMode(SW, INPUT_PULLUP);

	// ajusta el Monitor Serial
	Serial.begin(9600);

	// lee el estado inicial del CLK
	lastStateCLK = digitalRead(CLK);
}

void loop() {

// --- CALCULO DE VUELTAS ---
	// Lee el estado actual del CLK
	currentStateCLK = digitalRead(CLK);
	// si los ultimos estado actuales del CLK son diferentes entonces ocurrió un pulso
	// Reacciona solo a 1 cambio de estado para evitar un doble conteo

	if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

		// si el estado DT es diferente al estado del CLK
		// entonces el encoder de rotación tiene un CCW y esto significa que
		//está en sentido antihorario CCW es decir Esta decrementando
		if (digitalRead(DT) != currentStateCLK) {
			step++;
			currentDir = "CW";
		} else {
			// } CW sentido Horario así que incrementa
			step--;
			currentDir = "CCW";
		}

		if (step % 20 == 0) {
			vueltas++;
		}

// --- CALCULO DE RANGOS ---
		if (vueltas >= 0 && vueltas <= 1) {
			rango = 0;
		} else if (vueltas >= 2 && vueltas <= 8) {
			rango = 1;
		} else if (vueltas >= 9 && vueltas <= 16) {
			rango = 2;
		} else if (vueltas >= 17 && vueltas <= 24) {
			rango = 3;
		} else if (vueltas >= 25 && vueltas <= 29) {
			rango = 4;
		} else if (vueltas >= 30) {
			rango = 5;
		}

		Serial.print("Direction: ");
		Serial.println(currentDir);
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
}