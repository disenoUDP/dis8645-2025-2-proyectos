# sesion-15b
## 1 de diciembre de 2025
### sesiones de trabajo libres, se acabaron los exámenes


- trabajando en el módulo del motor
- el código anterior establecía un loop en el cuál se mostraban 3 velocidades diferentes
- lo malo de este código es que estaba sobrecargado de líneas y la función de delay paraliza todo el arduino por lo cuál no nos sirve
- (agregar código anterior para mostrar ejemplo)

```cpp
#define vibrador 2
void setup() {
pinMode(vibrador, OUTPUT);
}
// VELOCIDAD 1
void loop() {
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
  
// velocidad 2
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
  // lo mismo con la velocidad 2, CATEGORÍA VELOCIDAD 2 y poder nombrarlo, entonces cuando quiera "invocarlo" sea solo escribiendo la categoría

  //velocidad 3
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(0);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(0);
  
}
```

- le pedí ayuda a aarón para poder hacer lo mismo pero sin utilizar delay, en este caso utilizamos millis
- millis permite hacer lo mismo que delay pero sin pausar el arduino
- el código que se hizo fue el siguiente

```cpp
// definir constante
const int patitaVibrador = 2;

unsigned long momentoPasado = 0; // unsigned long significa que parte desde el 0 hacia el positivo, no usamos negativos

bool estado = HIGH;

int encoder = 0;  // aquí cambiamos el valor el encoder

void setup() {
  // hacer que esa patita sea salida
  pinMode(patitaVibrador, OUTPUT);
}

void loop() {

  if (encoder == 0) {  // acá se define qué velocidad responde (1, 2 o 3) según el rango en el que esté el encoder
    velocidad(2000, 2000);
  } else if (encoder == 1) { // si en otro caso encoder es 1, reproduce velocidad 2
    velocidad(3000, 500);
  } else if (encoder == 2) { // si en otro caso encoder es 2, reproduce velocidad 3
    velocidad(3000, 0);
  }
}


void velocidad(int pausaHIGH, int pausaLOW) {

  // grabar en memoria cuantos milisegundos han transcurrido
  // desde que prendio el arduino
  unsigned long momentoActual = millis();
  // momento actual es igual a millis, porque millis siempre va sucediendo, al igual que momento actual,corren juntos

  // revisar si la diferencia entre momentos actual y pasado
  // es mayor que la pausa correspondiente
  if (((estado == HIGH) && (momentoActual - momentoPasado > pausaHIGH)) // 
  //  hay algún punto en el cuál estado es HIGH y la diferencia entre momento actual y pasado es mayor a pausa high
  //  cuando esto ocurre, pasa a pausa low
    || ((estado == LOW) && (momentoActual - momentoPasado > pausaLOW))) {
  // cuando estado es LOW y momento actual y pasado son mayores a pausaLOW, vuelve a pausa HIGH
      // actualizar momento pasado
      momentoPasado = momentoActual;

      // como ya estuvo suficiente tiempo en un estado
      // lo alterno al estado contrario
      estado = !estado; // ! significa lo contrario, por ende, si estado es = high, lo contrario a estado high sería estado low

      digitalWrite(patitaVibrador, estado); // esto le escribe a la patita del arduino cuándo tiene que mandar la señal según el estado que se encuentre
    }
}
```

- pudimos establecer las 3 velocidades las cuáles son reproducidas según el valor que tenga el encoder
- la activación del motor alterna entre HIGH y LOW
- no olvidar cambiar el pin IN al 12 o 13 del arduino porque el pin 2 está ocupado por los otros componentes

#### explicación de lo que pudimos resolver cambiando de delay a millis en el motor, hallazgos, errores

- primero lo que hicimos fue definir un int hacia una patita del vibrador
- definimos unsigned long momentoPasado= 0, esto define que el momento pasado parte desde 0 y nunca será números negativos, parte desde positivo, por eso es unsigned
- luego definimos un bool de estado HIGH, esto define un estado de inicio del módulo, en este caso parte en HIGH
- 
