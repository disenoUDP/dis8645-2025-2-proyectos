#include "Leds.h"

Leds::Leds() {}

void Leds::preparar() {
	Serial.begin(9600);
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);
	pinMode(led5, OUTPUT);
}

void Leds::usar() {
	if (nivelLuz == 1) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, LOW);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}

	if (nivelLuz == 2) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}
	if (nivelLuz == 3) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}
	if (nivelLuz == 4) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, HIGH);
		digitalWrite(led5, LOW);
	}
	//if (nivelLuz == 5) {
	//	digitalWrite(led1, HIGH);
	//digitalWrite(led2, HIGH);
	//digitalWrite(led3, HIGH);
	//digitalWrite(led4, HIGH);
	//digitalWrite(led5, HIGH);
	//}
	if (nivelLuz == 5) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, HIGH);
		digitalWrite(led3, HIGH);
		digitalWrite(led4, HIGH);
		digitalWrite(led5, HIGH);
		//delay(300);
		//digitalWrite(led1, LOW);
		//digitalWrite(led2, HIGH);
		//digitalWrite(led3, LOW);
		//digitalWrite(led4, HIGH);
		//digitalWrite(led5, LOW);
		//delay(300);
	}


	if (nivelLuz == 6) {
		digitalWrite(led1, LOW);
		digitalWrite(led2, LOW);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}
}
//if (nivelLuz == 5){
//digitalWrite(led1, HIGH);
//digitalWrite(led2, LOW);
//digitalWrite(led3, HIGH);
//digitalWrite(led4, LOW);
//digitalWrite(led5, HIGH);
//delay(300);
//digitalWrite(led1, LOW);
//digitalWrite(led2, HIGH);
//digitalWrite(led3, LOW);
//digitalWrite(led4, HIGH);
//digitalWrite(led5, LOW);
//delay(300);
//}
