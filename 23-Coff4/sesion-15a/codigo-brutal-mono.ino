/*hola este es un codigo masacre, para el
proyecto "Jorgito tiene Apego Ansioso"*/
// hecho por aileen d'espessailles, santiago gaete, y carla pino

//cosas de audio
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SPI.h>
#include <MFRC522.h>


//sonico
int pinTrix = 7;
int pinEkeko = 8;
//motor dc
byte motorDc = 3;

float duracion;
float sustancia;

//variablesMp3
int abrazo=1;
int acercate=2;
int carino=3;
int venga[] = {abrazo, acercate, carino};

//variables sensor presion
const int pinDePresion = A0;  
int valorDePresion = 0; 
bool hayBrazo;  
int presionMinimaAceptable=50;   
int presionDolorosa=230; 

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

void setup() {
  // put your setup code here, to run once:
  pinMode(pinTrix, OUTPUT);
  pinMode(pinEkeko, INPUT);

  hayBrazo = false;

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

// reproduce un audio
 if(sustancia<35){
 int valorAleatorio  = random(0,2);
 myDFPlayer.play(venga[valorAleatorio]);
 }

// behave
 if(hayBrazo==true){
  //<https:programarfacil.com/electronica/motor-dc>
    digitalWrite(motorDc, HIGH);
  delay(2000); 
 }else if (hayBrazo==false){
    digitalWrite(motorDc, LOW);
  delay(2000); 
 }
}

void sonic(){
 digitalWrite(pinTrix, LOW);
 delayMicroseconds(2);
 digitalWrite(pinTrix, HIGH);
 delayMicroseconds(10);
 digitalWrite(pinTrix, LOW);

// <https://docs.arduino.cc/language-reference/en/functions/advanced-io/pulseIn>
 duracion = pulseIn(pinEkeko, HIGH);
 sustancia = (duracion*.0343)/2;
  delay(90);
}

void dePresion(){
valorDePresion = analogRead(pinDePresion);
Serial.print("lecturaDePresion= ");
  Serial.println(valorDePresion);         // Print the reading to the Serial Monitor
  delay(1000);
  if(valorDePresion>presionMinimaAceptable){
hayBrazo=true;
  }     
}
