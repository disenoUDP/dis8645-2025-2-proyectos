#ifndef ACELEROMETRO_H
#define ACELEROMETRO_H

#include <Adafruit_ADXL345_U.h>

class Acelerometro {
public:
  Acelerometro();

  bool iniciar();

  void imprimirDetallesSensor();
  void imprimirTasaDatos();
  void imprimirRango();
  void leer();

  float obtenerXAbsoluta() const { return xAbsoluta; }
  float obtenerYAbsoluta() const { return yAbsoluta; }
  float obtenerZAbsoluta() const { return zAbsoluta; }
  float obtenerMovimientoTotal() const { return movimientoTotal; }

  float obtenerMovimientoDinamico() const { return movimientoDinamico; }
  bool estaAgitado(float umbral = 1.5f) const { return movimientoDinamico > umbral; }

private:
  Adafruit_ADXL345_Unified acelerometro;
  
  float xCruda, yCruda, zCruda;
  float xAbsoluta, yAbsoluta, zAbsoluta;
  float movimientoTotal;

  float magnitud;
  float movimientoDinamico;
};

#endif
