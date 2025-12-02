#ifndef ACTUADOR_DISPLAY_H
#define ACTUADOR_DISPLAY_H

// INCLUIR BIBLIOTECAS DE USO PARA SENSOR/ACTUADOR

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Arduino.h>
#include "SensorBoton.h"

// CREAR LA CLASE DE NUESTRO SENSOR/ACTUADOR
  class ActuadorDisplay {
  public:
  ActuadorDisplay();

   // especificar todos los voids que seran utilizados en el archivo.cpp
      void configuracionDisplay();
     
   // la pantalla en la que el display estara haciendo la cuenta regresiva  
      void cuentaDisplay();

   // la pantalla que sera observada cuando se encuentre inclinado el WEBO
      void caidaDisplay();

   // si es que se necesita especificar variables, deberian ir aqui
   // ya sean bool int, ect.
     
   //millis
     //Memoriza el estado 
     bool memorizaEstadoDisplay = false;

     //El valor de los milisegundos
     int tiempoInicio = 500;

     //Memoriza el tiempo transcurrido para el cambio de imagen
     unsigned long tiempoTranscurrido = 0;

   
  // Declarar objeto "LCD" para el software SPI
     Adafruit_PCD8544 display = Adafruit_PCD8544(8, 7, 6, 5, 4);

  // Definir la variable de "rotatetext" en "1" que hace que la pantalla muestre el texto en un angulo de 90° a la derecha 
     int rotatetext = 1;

   // escribir que existira una dato numerico entero representado por "waoses"
   // que despues sera linkeado a los segundos que interactuan con el boton
   int waoses = 1;

  };

#endif