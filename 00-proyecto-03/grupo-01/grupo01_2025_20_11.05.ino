#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Mensajes (cada uno dividido en dos líneas para LCD 16x2)
String linea1 = "VEN, VEN, ACERCATE…";
String linea2 = "podrias divertirte";

bool modoParpadeo = true; 
unsigned long lastBlink = 0;
unsigned long blinkInterval = 800;  // Parpadeo más natural
bool visible = true;

void setup() {
  lcd.begin(16, 2);   // Ajusta si tienes otro tamaño de LCD
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
        linea1 = "Ahora deberas";
        linea2 = "arreglarme, intentalo";
        modoParpadeo = false;
        break;

      case 'b':
        linea1 = "No debiste";
        linea2 = "hacer eso";
        modoParpadeo = false;
        break;

      case 'c':
        linea1 = "NO ES MOMENTO";
        linea2 = "DE DIVERTIRSE";
        modoParpadeo = false;
        break;

      case 'd':
        linea1 = "upps, deberias";
        linea2 = "pensarlo mejor";
        modoParpadeo = false;
        break;

      case 'e':
        linea1 = "ese botón no";
        linea2 = "parece ser el más adecu";
        // nota: segunda línea es larga; se mostrará hasta 16 chars
        modoParpadeo = false;
        break;

      case 'r': // opcional: volver al modo inicial/parpadeo
        linea1 = "VEN, VEN, ACÉRCATE…";
        linea2 = "podrías divertirte";
        modoParpadeo = true;
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
    lcd.print(linea1.substring(0, min(16, (int)linea1.length())));
    lcd.setCursor(0, 1);
    lcd.print(linea2.substring(0, min(16, (int)linea2.length())));
  }
}

void mostrarEstatico() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1.substring(0, min(16, (int)linea1.length())));
  lcd.setCursor(0, 1);
  lcd.print(linea2.substring(0, min(16, (int)linea2.length())));
  delay(150);  // evita "parpadeo" por refresco
}