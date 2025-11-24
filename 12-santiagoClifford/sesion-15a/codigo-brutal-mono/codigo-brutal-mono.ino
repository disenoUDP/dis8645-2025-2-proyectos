/*hola este es un codigo masacre, para el
proyecto "Jorgito tiene Apego Ansioso"*/
// hecho por aileen d'espessailles, santiago gaete, y carla pino

//pseudocodigo//
//mono está calmao
//el sensor ultrasónico está sensando
//si no se detecta presencia, se mantiene calmao
//si una persona está a menos de 20cm del mono, pide amor
//pide amor: audio, una voz que dice "rascame la watita"
//si el sensor de presión sensa algo(moviendo el motor dc por 4 segundos)
//si no se detecta un objeto comienza la pataletaLeve
//pataletaLeve: audio llorar
//si el sensor de presión sensa algo, se detiene la pataleta, y se gira el motor dc por 4 segundos
//si pasan 10 segundos de pataletaLeve, sin que se detecte presión, comienza la pataleta brígida
//pataletaBrigida: audio, servo01 se giran 20° y -20° repetidamente
//si el sensor de presión sensa algo, se detiene la pataleta, y se gira el motor dc por 4 segundos
//si pasan 10 segundos de pataletaBrigida, sin que sense presión comienza la autodestrucción
//autodestrucción: reproducción de audio, el servo02 gira 120°, el servo gira 90 grados lentamente. Luego el servo02 vuelve a 0° lentamente, y luego a 120° velozmente.
//si se sensa presión, se interrumpe la autoDestrucción. Toda esta secuencia dura en total 15 segundos, luego el servo02 se queda en 120° durante 20segundos y luevo vuelve a 0°
///////////////

//cosas de audio
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

//estados
enum Estado { CALMAO,
              PIDE_AMOR,
              PATALETA_LEVE,
              PATALETA_BRIGIDA,
              AUTODESTRUCCION };
Estado estadoActual = CALMAO;

unsigned long tiempoInicioEstado = 0;

//sonico
int pinTrix = 10;
int pinEkeko =11;
//motor dc
//int motorDc = 3;

float duracion;
float sustancia;

//variables sensor presion
const int pinDePresion = A0;
int valorDePresion = 0;
bool hayBrazo;
int presionMinimaAceptable = 50;
int presionDolorosa = 230;

//motor
int able = 3;
int input1 =5;
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

Servo motoLumbar;
Servo motoRotor;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);

  //pin de presion
  pinMode(pinDePresion, INPUT);

  //motor
  pinMode(able, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);

  hayBrazo = false;

  //servo
  motoLumbar.attach(4);  // attaches the servo on pin 9 to the servo object
  motoRotor.attach(12);

  //inicialización audio
  FPSerial.begin(9600);

  Serial.begin(9600);

  if (!myDFPlayer.begin(FPSerial, true, true)) {
    Serial.println("Error: Revisar conexion y tarjeta SD");
    while (true) delay(0);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sonic();
  dePresion();

  switch (estadoActual) {

    case CALMAO:
      // aquí pondrás la lógica de calma
      if (sustancia < 20 && estadoActual == CALMAO) {
        estadoActual = PIDE_AMOR;
        tiempoInicioEstado = millis();
        myDFPlayer.playFolder(2, 1);  // tu audio para “rascame la guatita”
      }
      break;

    case PIDE_AMOR:
      // aquí pondrás lo que hace cuando pide amor
      if (hayBrazo) {
        motoMoto();
        estadoActual = CALMAO;
      }

      if (!hayBrazo && millis() - tiempoInicioEstado > 3000) {
        estadoActual = PATALETA_LEVE;
        tiempoInicioEstado = millis();
        myDFPlayer.playFolder(2, 2);  // audio llorar leve
      }
      break;

    case PATALETA_LEVE:
      // aquí pondrás lo que hace en pataleta leve
      if (hayBrazo) {
        motoMoto();
        estadoActual = CALMAO;
      }
      if (!hayBrazo && millis() - tiempoInicioEstado > 10000) {
        estadoActual = PATALETA_BRIGIDA;
        tiempoInicioEstado = millis();
        myDFPlayer.playFolder(2, 3);  // audio llorar fuerte
      }
      break;

    case PATALETA_BRIGIDA:
    {  // ← ABRE LLAVES
        int angulo = 20 * sin(millis() / 200.0);
        motoLumbar.write(90 + angulo);
        
        if (hayBrazo) {
            motoMoto();
            motoLumbar.write(90); // reinicia posición
            estadoActual = CALMAO;
        }
        
        if (!hayBrazo && millis() - tiempoInicioEstado > 10000) {
            estadoActual = AUTODESTRUCCION;
            tiempoInicioEstado = millis();
            myDFPlayer.playFolder(2, 4);
        }
    }  // ← CIERRA LLAVES
    break;

   case AUTODESTRUCCION:
    {  // ← ABRE LLAVES
        unsigned long tiempoAutodestruccion = millis() - tiempoInicioEstado;
        
        if (hayBrazo) {
            motoMoto();
            motoRotor.write(0);
            estadoActual = CALMAO;
            break;
        }
        
        // ... resto del código
    }  // ← CIERRA LLAVES
    break;
  }
}

void sonic() {
  digitalWrite(pinTrix, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrix, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrix, LOW);

  // <https://docs.arduino.cc/language-reference/en/functions/advanced-io/pulseIn>
  duracion = pulseIn(pinEkeko, HIGH);
  sustancia = (duracion * .0343) / 2;
  delay(90);
}

void dePresion(){
    valorDePresion = analogRead(pinDePresion);
    // ELIMINA esta línea: hayBrazo=true;
    hayBrazo = (valorDePresion > presionMinimaAceptable);
}

void motoMoto() {
  analogWrite(able, 100);
  // Encendemos el motor
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(2000);
  // Apagamos el motor
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  delay(2000);
}

void motoMotoLumbar() {
  motoLumbar.write(110);  // sets the servo position according to the scaled value
  delay(15);
}
void motoMotoRoto() {
  motoRotor.write(110);  // sets the servo position according to the scaled value
  delay(15);
}
