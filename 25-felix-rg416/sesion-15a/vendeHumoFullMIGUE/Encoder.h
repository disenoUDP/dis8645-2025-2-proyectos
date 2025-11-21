#include "Arduino.h"

// ===============================
//     DEFINICIONES DEL ENCODER
// ===============================

#define CLK 2
#define DT 3
#define SW 4

// ===============================
//     VARIABLES DEL MÓDULO
// ===============================

extern int step;
extern int currentStateCLK;
extern int lastStateCLK;
extern int vueltas;
extern int rango;
extern String currentDir;
extern unsigned long lastButtonPress;

// ===============================
//     FUNCIONES PRINCIPALES
// ===============================

void prepEncoder();
void actuarEncoder();
