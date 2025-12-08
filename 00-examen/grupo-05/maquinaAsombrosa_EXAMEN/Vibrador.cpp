#include "Vibrador.h"

Vibrador::Vibrador() {}

void Vibrador::prepararVibrador() {
  // hacer que esa patita sea salida
  pinMode(patitaVibrador, OUTPUT);
}

void Vibrador::usarVibrador() {
  if (intervalo == 2) {
    // acá se define qué velocidad responde (1, 2 o 3) según el rango en el que esté el intervalo
    velocidadVibrador(2000, 2000);
  } else if (intervalo == 3) {
    // si en otro caso intervalo es 1, reproduce velocidad 2
    velocidadVibrador(3000, 500);
  } else if (intervalo == 4) {
    // si en otro caso intervalo es 2, reproduce velocidad 3
    velocidadVibrador(3000, 0);
  } else if (intervalo == 5) {
    // si en otro caso intervalo es 2, reproduce velocidad 3
    velocidadVibrador(0, 100000);
    //agregar opción rango 6 que apague el motor, ahora motor se apaga en rango 5 que es fiesta leds
  }
}

void Vibrador::velocidadVibrador(int pausaHIGH, int pausaLOW) {

  // grabar en memoria cuantos milisegundos han transcurrido
  // desde que prendio el arduino
  unsigned long momentoActual = millis();
  // momento actual es igual a millis, porque millis siempre va sucediendo, al igual que momento actual,corren juntos

  // revisar si la diferencia entre momentos actual y pasado
  // es mayor que la pausa correspondiente
  if (((estado == HIGH) && (momentoActual - momentoPasado > pausaHIGH))
      //  hay algún punto en el cuál estado es HIGH y la diferencia entre momento actual y pasado es mayor a pausa high
      //  cuando esto ocurre, pasa a pausa low
      || ((estado == LOW) && (momentoActual - momentoPasado > pausaLOW))) {
    // cuando estado es LOW y momento actual y pasado son mayores a pausaLOW, vuelve a pausa HIGH
    // actualizar momento pasado
    momentoPasado = momentoActual;

    // como ya estuvo suficiente tiempo en un estado
    // lo alterno al estado contrario
    estado = !estado;
    // ! significa lo contrario, por ende, si estado es = high, lo contrario a estado high sería estado low

    digitalWrite(patitaVibrador, estado);
    // esto le escribe a la patita del arduino cuándo tiene que mandar la señal según el estado que se encuentre
  }
}
