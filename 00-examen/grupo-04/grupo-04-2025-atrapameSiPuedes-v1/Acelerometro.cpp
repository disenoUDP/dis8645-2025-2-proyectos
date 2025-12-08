#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Acelerometro.h"

// Escribir directamente un registro al ADXL345 usando I2C
void escribirRegistroADXL(byte reg, byte valor) {
  Wire.beginTransmission(0x53); // dirección I2C del ADXL345
  Wire.write(reg);
  Wire.write(valor);
  Wire.endTransmission();
}

Acelerometro::Acelerometro()
  : acelerometro(Adafruit_ADXL345_Unified(12345)),
    xCruda(0), yCruda(0), zCruda(0),
    xAbsoluta(0), yAbsoluta(0), zAbsoluta(0),
    movimientoTotal(0),
    magnitud(0),
    movimientoDinamico(0) {}

bool Acelerometro::iniciar() {
  if (!acelerometro.begin()) {
    return false;
  }

  // DESACTIVAR AUTO-SLEEP Y ACTIVAR MODO MEASURE SIEMPRE
  escribirRegistroADXL(0x2D, 0x08); // POWER_CTL — modo MEASURE
  escribirRegistroADXL(0x25, 0x00); // THRESH_INACT — sin inactividad
  escribirRegistroADXL(0x26, 0x00); // TIME_INACT — sin tiempo inactivo
  escribirRegistroADXL(0x27, 0x00); // ACT_INACT_CTL — desactivar detección

  // Opcional: configuramos rango
  acelerometro.setRange(ADXL345_RANGE_16_G);

  imprimirDetallesSensor();
  return true;
}

void Acelerometro::imprimirDetallesSensor() {
  sensor_t sensor;
  acelerometro.getSensor(&sensor);

  Serial.println("------------------------------------");
  Serial.print("Sensor:       "); Serial.println(sensor.name);
  Serial.print("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
  Serial.print("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
  Serial.print("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(50);
}

void Acelerometro::imprimirTasaDatos() {
  Serial.print("Tasa de datos: ");
  switch (acelerometro.getDataRate()) {
    case ADXL345_DATARATE_100_HZ: Serial.println("100 Hz"); break;
    default: Serial.println("otro"); break;
  }
}

void Acelerometro::imprimirRango() {
  Serial.print("Rango: +/- ");
  switch (acelerometro.getRange()) {
    case ADXL345_RANGE_16_G: Serial.println("16 g"); break;
    default: Serial.println("?"); break;
  }
}

void Acelerometro::leer() {
  sensors_event_t evento;
  acelerometro.getEvent(&evento);

  xCruda = evento.acceleration.x;
  yCruda = evento.acceleration.y;
  zCruda = evento.acceleration.z;

  xAbsoluta = fabs(xCruda);
  yAbsoluta = fabs(yCruda);
  zAbsoluta = fabs(zCruda);

  movimientoTotal = xAbsoluta + yAbsoluta + zAbsoluta;

  magnitud = sqrt(xCruda*xCruda + yCruda*yCruda + zCruda*zCruda);

  const float G = 9.81f;
  movimientoDinamico = fabs(magnitud - G);
}
