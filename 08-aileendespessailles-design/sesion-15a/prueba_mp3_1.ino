#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h> 

// --- 📌 CONFIGURACIÓN DE COMUNICACIÓN (Hardware) ---
// La comunicación serial usa el orden: SoftwareSerial(RX_Pin, TX_Pin)
//
// Conexiones:
// 1. DFPlayer TX Pin --> Arduino D10 (RX del SoftwareSerial)
// 2. DFPlayer RX Pin <-- Resistor de 1K ohm <-- Arduino D11 (TX del SoftwareSerial)
SoftwareSerial softSerial(10, 11); 
#define FPSerial softSerial

// Instancia global del módulo MP3
DFRobotDFPlayerMini myDFPlayer;

// --- CONFIGURACIÓN DE AUDIO ---
// Ubicación del archivo en la SD: 
const int CARPETA_NUMERO = 2; // Carpeta llamada "02"
const int ARCHIVO_NUMERO = 1; // Archivo llamado "001.mp3"

// --- SETUP (Se ejecuta una sola vez al encender) ---
void setup() {
    // 1. Inicialización Serial para Debugging
    Serial.begin(115200);
    
    // 2. Inicialización Serial para DFPlayer
    FPSerial.begin(9600); 

    Serial.print("Iniciando DFPlayer Mini...");
    
    // 3. Intento de inicialización del módulo
    // Parámetros: (Puerto, Modo de Espera, Debugging)
    if (!myDFPlayer.begin(FPSerial, true, false)) {
        Serial.println("❌ ERROR: Revisar conexion y tarjeta SD.");
        while (true) delay(0); // Detiene la ejecución en caso de fallo
    }
    Serial.println(" ✅ OK.");
    
    // 4. Ajustes Iniciales
    myDFPlayer.setTimeOut(500);  // Tiempo de espera para respuestas del módulo
    myDFPlayer.volume(25);      // Volumen establecido a 25 (de 0 a 30)

    // 5. Reproducción Única
    // Reproduce el archivo '001.mp3' de la carpeta '02'
    myDFPlayer.playFolder(02, 001); 
    Serial.println("Reproducción iniciada: 02/001.mp3");
}

// --- LOOP (Bucle Inactivo) ---
void loop() {
    // Opcional: Manejar eventos del módulo
    if (myDFPlayer.available()) {
        if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            Serial.println("🎶 Reproducción de audio terminada.");
            // Si quieres que el Arduino no haga absolutamente nada más:
            // myDFPlayer.sleep(); 
        }
    }
    
    // El programa se mantiene aquí, esperando a que termine la reproducción
    // y revisando si ha terminado.
    delay(10);
}