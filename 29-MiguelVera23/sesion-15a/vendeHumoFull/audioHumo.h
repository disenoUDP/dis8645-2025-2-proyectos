#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

// ===============================
//   SIMULACIÓN DESDE SERIAL
// ===============================

// Variables internas para simular las vueltas
extern int vueltasSim;   
extern int rangoSim;

// Devuelve TRUE si desde el monitor serial se pidió una nueva vuelta
extern bool simNuevaVuelta;

// Declaraciones de funciones de simulación
void simularDesdeSerial();
int simularRango();
bool simularEventoEncoder();
int simularPuntoEncoder();

// Variables del módulo
extern SoftwareSerial mySoftwareSerial;
extern DFRobotDFPlayerMini myDFPlayer;
extern int leerRango;
extern int rangoEncoder;
extern int leerEncoder;
extern int puntoEncoder;
extern bool reproducirAudio;

// Declaraciones de funciones principales
void prepAudio();
void actuarAudio();
void reproducirAudioPorRango();