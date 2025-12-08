#include "Humo.h"

Humo::Humo() {}

void Humo::prepararHumo(){
  Serial.begin(9600);
pinMode(humo, OUTPUT);
}

void Humo::usarHumo(){
  //si no se ha activado el humo y van en el punto/rango 6 se activa el humo
  if (tiraHumo == false && punto == 6) {
  //se activa el humo, espera 3 segundos y se desactiva
  digitalWrite(humo, HIGH);
  delay(3000);
  digitalWrite(humo, LOW);
  //el bool tiraHumo cambia y no se puede activar de nuevo
  tiraHumo = true;
}
//al llegar al punto/rango 1 el bool tiraHumo se recarga
if (punto == 1){
  tiraHumo = false;
}
}


