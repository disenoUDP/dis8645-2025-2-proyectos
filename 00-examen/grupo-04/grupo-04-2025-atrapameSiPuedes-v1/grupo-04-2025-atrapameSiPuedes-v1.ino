// incluye las clases acelerometro, sensor fuerza y joystick
#include "Acelerometro.h"
#include "SensorFuerza.h"
#include "Joystick.h"

// declaracion adelantada de acelerometro
void escribirRegistroADXL(byte reg, byte valor);

// instancias
Acelerometro acel;
SensorFuerza sensorX;
SensorFuerza sensorY;
Joystick joystick;

// pines FSR
const int PIN_FSR_X = A0;
const int PIN_FSR_Y = A1;

// pines Joystick
const int PIN_VRX = A3;
const int PIN_VRY = A2;
const int PIN_SW  = 7;

const int UMBRAL_PRESION = 300;
bool acelerometroActivo = false;

void setup() {
  Serial.begin(115200);

// configuramos los pines del sensor
  sensorX.configurar(PIN_FSR_X);
  sensorY.configurar(PIN_FSR_Y);

// configuramos los pines del joystick
  joystick.configurar(PIN_VRX, PIN_VRY, PIN_SW);

// iniciamos acelerometro
  acel.iniciar();
  escribirRegistroADXL(0x2D, 0x00);  // standby
  acelerometroActivo = false;
}

void loop() {

  // lee sensores FSR
  sensorX.leer();
  sensorY.leer();

  int valorX = sensorX.valorCrudo;
  int valorY = sensorY.valorCrudo;

  // lee Joystick
  joystick.leer();

  // activacion del acelerometro basada en FSR
  if (!acelerometroActivo && (valorX > UMBRAL_PRESION || valorY > UMBRAL_PRESION)) {
    escribirRegistroADXL(0x2D, 0x08);
    acelerometroActivo = true;
  }

  if (acelerometroActivo && (valorX <= UMBRAL_PRESION && valorY <= UMBRAL_PRESION)) {
    escribirRegistroADXL(0x2D, 0x00);
    acelerometroActivo = false;
  }

  // ENVÍO FINAL A P5.JS
  Serial.print(valorX); Serial.print(",");
  Serial.print(valorY); Serial.print(",");
  Serial.print(joystick.valorX); Serial.print(",");
  Serial.print(joystick.valorY); Serial.print(",");
  Serial.println(joystick.boton);

  delay(20);
}
