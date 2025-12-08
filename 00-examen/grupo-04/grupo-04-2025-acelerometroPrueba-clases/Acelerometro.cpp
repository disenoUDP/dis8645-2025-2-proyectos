#include "Acelerometro.h"

Acelerometro::Acelerometro() {} // constructor

Acelerometro::~Acelerometro() {} // destructor

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// mide los valores x,y,z en un valor crudo
float xRaw = 0;
float yRaw = 0;
float zRaw = 0;

float xAbs = 0;
float yAbs = 0;
float zAbs = 0;

float totalMovement = 0;

void Acelerometro::actualizar() {
  sensors_event_t event;
  accel.getEvent(&event);

  xRaw = event.acceleration.x;
  yRaw = event.acceleration.y;
  zRaw = event.acceleration.z;

  xAbs = abs(xRaw);
  yAbs = abs(yRaw);
  zAbs = abs(zRaw);

  totalMovement = xAbs + yAbs + zAbs;
}

void Acelerometro::imprimirDatos() {
  Serial.print("X: "); Serial.print(xAbs); Serial.print(" ");
  Serial.print("Y: "); Serial.print(yAbs); Serial.print(" ");
  Serial.print("Z: "); Serial.print(zAbs); Serial.print(" m/s^2\n");

  Serial.print("Total: "); Serial.println(totalMovement);
}


void Acelerometro::displayDataRate() {
  Serial.print("Data Rate:    "); 

  switch(accel.getDataRate()) {
    case ADXL345_DATARATE_3200_HZ: Serial.print("3200"); break;
    case ADXL345_DATARATE_1600_HZ: Serial.print("1600"); break;
    case ADXL345_DATARATE_800_HZ:  Serial.print("800");  break;
    case ADXL345_DATARATE_400_HZ:  Serial.print("400");  break;
    case ADXL345_DATARATE_200_HZ:  Serial.print("200");  break;
    case ADXL345_DATARATE_100_HZ:  Serial.print("100");  break;
    case ADXL345_DATARATE_50_HZ:   Serial.print("50");   break;
    case ADXL345_DATARATE_25_HZ:   Serial.print("25");   break;
    case ADXL345_DATARATE_12_5_HZ: Serial.print("12.5"); break;
    case ADXL345_DATARATE_6_25HZ:  Serial.print("6.25"); break;
    case ADXL345_DATARATE_3_13_HZ: Serial.print("3.13"); break;
    case ADXL345_DATARATE_1_56_HZ: Serial.print("1.56"); break;
    case ADXL345_DATARATE_0_78_HZ: Serial.print("0.78"); break;
    case ADXL345_DATARATE_0_39_HZ: Serial.print("0.39"); break;
    case ADXL345_DATARATE_0_20_HZ: Serial.print("0.20"); break;
    case ADXL345_DATARATE_0_10_HZ: Serial.print("0.10"); break;
    default: Serial.print("????"); break;
  }

  Serial.println(" Hz");
}

void Acelerometro::displayRange() {
  Serial.print("Range:     +/- ");

  switch(accel.getRange()) {
    case ADXL345_RANGE_16_G: Serial.print("16"); break;
    case ADXL345_RANGE_8_G:  Serial.print("8"); break;
    case ADXL345_RANGE_4_G:  Serial.print("4"); break;
    case ADXL345_RANGE_2_G:  Serial.print("2"); break;
    default: Serial.print("??"); break;
  }

  Serial.println(" g");
}
