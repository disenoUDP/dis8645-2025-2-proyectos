/*hola este es un codigo masacre, para el
proyecto "Jorgito tiene Apego Ansioso"*/
// hecho por aileen d'espessailles, santiago gaete, y carla pino

//librerias
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

//estados posibles
enum Estado { CALMAO,
              PIDE_AMOR,
              PATALETA_LEVE,
              PATALETA_BRIGIDA,
              AUTODESTRUCCION };
Estado estadoActual = CALMAO;

unsigned long tiempoInicioEstado = 0;

//sonico
//Pin Trigger
int pinTrix = 8;
//Pin Echo
int pinEkeko = 9;
float duracion;
//Sustancia = Distancia
float sustancia;

//variables sensor presion
const int pinDePresion = A0;
int valorDePresion = 0;
bool hayBrazo;
int presionMinimaAceptable = 50;
//int presionDolorosa = 230;

//motor
int able = 3;
int input1 = 5;
int input2 = 6;

//configuracion de comunicación serial del modulo mp3
#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))
#include <SoftwareSerial.h>
SoftwareSerial softSerial(10, 11);
#define FPSerial softSerial
#else
#define FPSerial Serial1
#endif

//instancia mp3
DFRobotDFPlayerMini myDFPlayer;

//Servo motor que actua con la columna
Servo motoLumbar;
//Servo que acciona la rotacion
Servo motoRotor;

void setup() {
  Serial.begin(9600);
  hayBrazo = false;

  //inicialización audio
  FPSerial.begin(9600);

  //ultrasonico
  pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);

  //pin de presion
  pinMode(pinDePresion, INPUT);

  //motor
  pinMode(able, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);

  //servo
  motoLumbar.attach(4);
  motoRotor.attach(12);

  Serial.println("INICIO");
  Serial.println("(los audios se mostraran como texto en el puerto serial");
}

void loop() {
  sonic();
  dePresion();

  Serial.print("distancia: ");
  Serial.print(sustancia);
  Serial.print("cm ");
  Serial.print(" - brazo(?): ");
  Serial.println(hayBrazo ? "SI" : "NO");

  switch (estadoActual) {

    case CALMAO:
      Serial.println("ESTADO: CALMAO");
      //Rango de la distancia minima y maxima del estado "Calmao"
      if (sustancia < 20 && sustancia > 0) {

        //emular audio
        Serial.println("rascame la watita xfis :p");

        estadoActual = PIDE_AMOR;
        tiempoInicioEstado = millis();
      }
      break;

    case PIDE_AMOR:
      Serial.println("ESTADO: PIDE_AMOR");

      if (hayBrazo) {
        Serial.println("ke ricooo");
        Serial.println("-el mono se ha calmado-");

        motoMoto();
        estadoActual = CALMAO;
        Serial.println("ESTADO: CALMAO");
      }
      //Si detecta una persona y pasan mas de 9 segundos se iniciara el estado "Pataleta leve"
      if (!hayBrazo && millis() - tiempoInicioEstado > 9000) {
        estadoActual = PATALETA_LEVE;
        tiempoInicioEstado = millis();
        //emular audio
        Serial.println("llora en silencio");
      }
      break;

    case PATALETA_LEVE:
      Serial.println("ESTADO: PATALETA_LEVE");

      if (hayBrazo) {
        Serial.println("ke ricooo gracias");
        Serial.println("-el mono se ha calmado-");

        motoMoto();
        estadoActual = CALMAO;
        Serial.println("ESTADO: CALMAO");
      }
      if (!hayBrazo && millis() - tiempoInicioEstado > 10000) {
        estadoActual = PATALETA_BRIGIDA;
        tiempoInicioEstado = millis();
        //emular audio
        Serial.println("llora brigido");
      }
      break;

    case PATALETA_BRIGIDA:
      Serial.println("ESTADO: PATALETA_BRIGIDA");

      {
        int angulo = 20 * sin(millis() / 200.0);
        motoLumbar.write(90 + angulo);
        Serial.println("chillidos y quejas");

        if (hayBrazo) {
          Serial.println("ke ricooo gracias");
          Serial.println("-el mono se ha calmado-");

          motoMoto();
          motoLumbar.write(90);
          estadoActual = CALMAO;
          Serial.println("😊 TRANSICIÓN: PATALETA_BRIGIDA → CALMAO");
        }

        if (!hayBrazo && millis() - tiempoInicioEstado > 10000) {
          estadoActual = AUTODESTRUCCION;
          tiempoInicioEstado = millis();
          //emular audio
          Serial.println("chillidos y gritos desesperados");
        }
      }
      break;

    case AUTODESTRUCCION:
      {
        Serial.println("ESTADO: AUTODESTRUCCION");
        unsigned long tiempoAutodestruccion = millis() - tiempoInicioEstado;

        if (hayBrazo) {
          Serial.println("ke ricooo grax");
          Serial.println("-el mono se ha calmado-");

          motoMoto();
          motoRotor.write(0);
          motoLumbar.write(90);
          estadoActual = CALMAO;
          Serial.println("ESTADO: CALMAO");
          break;
        }

        // SECUENCIA DE AUTODESTRUCCIÓN
        if (tiempoAutodestruccion < 5000) {
          motoLumbar.write(90);
          Serial.println("posición aflijido");
        } else if (tiempoAutodestruccion < 10000) {
          motoRotor.write(120);
          Serial.println("motor de rotacion gira lentamente");
        } else if (tiempoAutodestruccion < 15000) {
          //secuencia autodestruccion
          Serial.println("chillidos y gritos desesperados");
          //linea de texto que no aparece en la secuencia
          Serial.println("PORFAVOR, RASCALE LA WATITA AL MONO");
          Serial.println("...");
          Serial.println("...");
          Serial.println("...");
          Serial.println("INICIANDO PROTOCOLO DE AUTODESTRUCCION");
          Serial.println("10");
          Serial.println("9");
          Serial.println("8");
          Serial.println("7");
          Serial.println("6");
          Serial.println("5");
          Serial.println("4");
          Serial.println("3");
          Serial.println("2");
          Serial.println("1");
          Serial.println("0");
          Serial.println("/////////////////////////////////");
          Serial.println("/////ESTO NO ES UN SIMULACRO/////");
          Serial.println("///////EL MONO HA FALLECIDO///////");
          Serial.println("/////////////////////////////////");
          motoLumbar.write(0);
          Serial.println("vuelve a posicion erguida lentamente");
          motoLumbar.write(120);
          Serial.println("*le pega un cabezazo al botón de autodestruccion*");
        }

        if (tiempoAutodestruccion > 35000) {
          motoRotor.write(0);
          estadoActual = CALMAO;
        }
      }
      break;
  }

  delay(500);  // Pequeña pausa para no saturar el Serial
}

void dePresion() {
  //asignar el valor del pin del sensor de presion, a la variable valorDePresion
  valorDePresion = analogRead(pinDePresion);
  //si valorDePresion es mayor a presionMinimaAceptable, hayBrazo es true
  hayBrazo = (valorDePresion > presionMinimaAceptable);
}

//motor dc
void motoMoto() {
  //asignar velocidad
  analogWrite(able, 100);
  //prender direccion1, apagar direccion2
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(5000);
  //apagar ambas direcciones
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
}

//sensor ultrasonico
void sonic() {
  digitalWrite(pinTrix, LOW);
  delayMicroseconds(2);
  //enviar un pulso ultrasonico
  digitalWrite(pinTrix, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrix, LOW);

  duracion = pulseIn(pinEkeko, HIGH, 30000);

//pasar el valor del pin a cm
  if (duracion == 0) {
    sustancia = 400;
  } else {
    sustancia = (duracion * 0.0343) / 2;
  }

  //rango sensor ultrasonico, si esta fuera de rango, se toma como 400
  if (sustancia > 400 || sustancia <= 0) {
    sustancia = 400;
  }

  delay(50);
}