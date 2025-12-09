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

  // la pantalla en la que se comienza el proyecto, donde Ava se encuentra durmiendo
  void duermeDisplay();

  // la pantalla en la que el display estara haciendo la cuenta regresiva
  void cuentaDisplay();

  // la pantalla que sera observada cuando se encuentre inclinado el WEBO
  void caidaDisplay();

  // si es que se necesita especificar variables, deberian ir aqui
  // ya sean bool int, ect.

  //millis
  //definir la duracion del display
  //Enum es una variable de valores incambiables
  int duracionDisplay = 500;

  // Definir el nombre de la variable del inicio de tiempo
  unsigned long tiempoInicio;
  // Definir el nombre de la variable del tiempo actual
  unsigned long tiempoActual;

  //definir el estado donde iniciara el tiempo
  int estado = 0;


  // Declarar objeto "LCD" para el software SPI
  Adafruit_PCD8544 display = Adafruit_PCD8544(8, 7, 6, 5, 4);

  // Definir la variable de "rotatetext" en "1" que hace que la pantalla muestre el texto en un angulo de 90° a la derecha
  int rotatetext = 1;

  // escribir que existira una dato numerico entero representado por "waoses"
  // que despues sera linkeado a los segundos que interactuan con el boton
  int waoses = 1;

  String pantallaDeInicio = "Presiona el boton\npara empezar\nel temporizador";

  bool comenzarTemporizador = false;

  bool avaHablando;

  int tiempoDeHabla = 500;

  int tiempoDisplayHablando = 0;

  int tiempoDisplayNoHabla = 0;

  int tiempoActualDisplay = 0;

};

#endif