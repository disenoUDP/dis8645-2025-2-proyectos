#ifndef ACTUADOR_DISPLAY_H
#define ACTUADOR_DISPLAY_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Arduino.h>

// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
  class ActuadorDisplay {
  public:
  ActuadorDisplay();



   // especificar todos los voids que seran utilizados en el archivo.cpp
      void configuracionDisplay();
     
      void funcionaDisplay();


   // si es que se necesitas especificar variables, deberian ir aqui
   // ya sean bool int, ect.

   
  // Declarar objeto "LCD" para el software SPI
     Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

  // Definir la variable de "rotatetext" en "1" que hace que la pantalla muestre el texto en un angulo de 90° a la derecha 
     int rotatetext = 1;



  };

#endif