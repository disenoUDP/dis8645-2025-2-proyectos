#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Mensajes divididos en dos líneas (máx 16 caracteres)
String linea1 = "VEN VEN, ACERCATE";
String linea2 = "PODRIAS DIVERTIRTE";

bool modoParpadeo = true; 
unsigned long lastBlink = 0;
unsigned long blinkInterval = 800;  // Parpadeo más natural
bool visible = true;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  leerSerial();

  if (modoParpadeo) {
    parpadearSuave();
  } else {
    mostrarEstatico();
  }
}

void leerSerial() {
  if (Serial.available() > 0) {
    char entrada = Serial.read();

    switch (entrada) {
      case 'a':
        linea1 = "... O NO";
        linea2 = "";
        modoParpadeo = false;
        break;

      case 'b':
        linea1 = "NO DEBISTE";
        linea2 = "HACER ESO";
        modoParpadeo = false;
        break;

      case 'c':
        linea1 = "NO ES MOMENTO";
        linea2 = "DE DIVERTIRSE";
        modoParpadeo = false;
        break;

      case 'd':
        linea1 = "UPPS, DEBERIAS";
        linea2 = "PENSARLO MEJOR";
        modoParpadeo = false;
        break;

      case 'e':
        linea1 = "ESE BOTON NO";
        linea2 = "ES ADECUADO";
        modoParpadeo = false;
        break;
    }
  }
}

void parpadearSuave() {
  if (millis() - lastBlink >= blinkInterval) {
    lastBlink = millis();
    visible = !visible;
  }

  lcd.clear();
  lcd.setCursor(0, 0);

  if (visible) {
    lcd.print(linea1.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print(linea2.substring(0, 16));
  }
}

void mostrarEstatico() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1.substring(0, 16));
  lcd.setCursor(0, 1);
  lcd.print(linea2.substring(0, 16));
  delay(150);  // evita "parpadeo" por refresco
}
:beverage_box:
Haz clic para reaccionar
:zap:
Haz clic para reaccionar
:open_mouth:
Haz clic para reaccionar
Añadir reacción
Editar
Reenviar
Más
[12:20]viernes, 14 de noviembre de 2025 12:20
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String mensaje = "VEN VEN, ACERCATE... PODRIAS DIVERTIRTE";
bool estadoInicial = true;   // true = parpadeo, false = mensaje estático
unsigned long lastBlink = 0;
unsigned long blinkSpeed = 600;
bool visible = true;

void setup() {
  lcd.begin(20, 4);
  Serial.begin(9600);
}

void loop() {
  leerSerial();

  if (estadoInicial) {
    parpadearMensaje();
  } else {
    mostrarEstatico();
  }
}

void leerSerial() {
  if (Serial.available() > 0) {
    char entrada = Serial.read();

    switch (entrada) {
      case 'a':
        mensaje = "... O NO";
        estadoInicial = false;
        break;
      case 'b':
        mensaje = "NO DEBISTE HACER ESO";
        estadoInicial = false;
        break;
      case 'c':
        mensaje = "NO ES MOMENTO DE DIVERTIRSE";
        estadoInicial = false;
        break;
      case 'd':
        mensaje = "UPPS, DEBERIAS PENSARLO MEJOR";
        estadoInicial = false;
        break;
      case 'e':
        mensaje = "ESE BOTON NO PARECE SER EL MAS ADECUADO";
        estadoInicial = false;
        break;
    }
  }
}

void parpadearMensaje() {
  if (millis() - lastBlink >= blinkSpeed) {
    lastBlink = millis();
    visible = !visible;
  }

  lcd.clear();
  lcd.setCursor(0, 0);

  if (visible) {
    lcd.print(mensaje);
  }
}

void mostrarEstatico() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(mensaje);
  delay(200);  // para evitar parpadeo por refresco
}