#include "Vibrador.h"

Vibrador::Vibrador(){}

void Vibrador::prepararVibrador(){
  pinMode(vibrador, OUTPUT);
}

void Vibrador::despacioVibrador(){

digitalWrite(vibrador, HIGH);
  delay(2000);
  digitalWrite(vibrador, LOW);
  delay(2000);
  digitalWrite(vibrador, HIGH);
  delay(2000);
  digitalWrite(vibrador, LOW);
  delay(2000);
  digitalWrite(vibrador, HIGH);
  delay(2000);
  digitalWrite(vibrador, LOW);
  delay(2000);
}

void Vibrador::medianoVibrador(){
   // debería definir con algún parámetro el fin de la velocidad 1, una categoría VELOCIDAD 1 que pueda ser utilizado sólo nombrándolo
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(500);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(500);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(500);
}

void Vibrador::fuerteVibrador(){
  // lo mismo con la velocidad 2, CATEGORÍA VELOCIDAD 2 y poder nombrarlo, entonces cuando quiera "invocarlo" sea solo escribiendo la categoría
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(0);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(0);
  // lo mismo con la tercera velocidad , un parámetro que la establezca y la ponga al final 
}
