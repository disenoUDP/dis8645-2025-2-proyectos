# sesion-14b

Para esta clase preparé el código del sonido y de las led para la máquina vendedora de humo. Como detallo anteriormente me basé en el código de ***Gustavo*** y añadí elementos de otro código de chat gpt. La última versión (audioHumo3) compila y tiene una estructura que funcionó en otra ocasión. La diferencia más grande es que depende de 2 variables: Rango para saber qué reproducir y ubicación del encoder para saber cuando reproducir. 

Para las luces led hice una función que recibe constantemente señales de la manivela para saber en que Rango(%) se encuentra. Cada vez que se progresa y el rango cambia se añade una luz prendida. Al llegar al Rango 5 se activa una función 5 veces que prende y apaga las luces. Después de 5 segundos se apaga todo y vuelve al rango 1. Es necesario hacer que esto también ocurra en la manivela y que al llegar al rango 5 se reinicie y vuelva al rango 0.

A continuación está el código para el audio completado:

```cpp
//valor del Rango 1 - 5 que activa las funciones
int rangoEncoder = 0;
//función del encoder que alimenta la función anterior
//cada rango está definido por la cantidad de vueltas que lleva
//con respecto al total necesario para completar la interacción
int leerRango = 5;

// Declaración de pines
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

void setup() {
  // Configurar los pines como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  rangoEncoder = leerRango;
}

void loop() {
  //lee en que rango está


  //todas las luces empiezan apagadas
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  //si está en el rango 1 solo 1 led está prendido
  if (rangoEncoder == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

  }
  //si está en el rango 2, 2 led están prendidas
  else if (rangoEncoder == 2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  //si está en el rango 3, 3 led están prendidas
  else if (rangoEncoder == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  //si está en el rango 4, 4 led están prendidas
  else if (rangoEncoder == 4) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
  }
  //en el rango 5 se activa la función finalLuces que prende y apaga leds 2 veces por segundo
  //esto se repite 5 veces
  else if (rangoEncoder == 5) {
    for (int i = 0; i < 7; i++) {
      finalLuces();
      Serial.println(i);
    }
    //al terminar vuelve al rango 1
    rangoEncoder = 1;
  }
}

void finalLuces() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(300);
}

```

