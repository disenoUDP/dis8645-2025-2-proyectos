#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mp3Serial(2, 3);
DFRobotDFPlayerMini mp3;

#define PIN_TRIGGER A5   // Señal desde el Arduino maestro

void setup() {
  Serial.begin(9600);
  mp3Serial.begin(9600);

  pinMode(PIN_TRIGGER, INPUT);  // Señal que activa la música

  Serial.println("Inicializando DFPlayer...");

  if (!mp3.begin(mp3Serial)) {
    Serial.println("DFPlayer no detectado");
    while (true);
  }

  Serial.println("DFPlayer OK!");

  mp3.volume(25);
  mp3.EQ(DFPLAYER_EQ_NORMAL);
}

void loop() {
  int senal = digitalRead(PIN_TRIGGER);
  Serial.println("apreta el boton");

  if (senal == HIGH) {
    Serial.println("Señal recibida → Reproduciendo");
    //mp3.play(1);   // Reproduce la canción 1
    mp3.loop(1);
      //delay(500);    // Evita que se repita inmediatamente
    }
  }