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

## Sentimiento y metáfora
Vender humo se refiere a ofrecer un objeto de nulo o escaso valor con mala fé. En este proyecto buscamos vender humo para evocar *decepción*, por lo que la venta debe ser muy convincente. La *decepción* viene al traicionar la *expectativa* por lo que no podemos tener una sin la otra. El primer paso para decepcionar al usuario es hacer que espere algo de la máquina ya que si no le importa el resultado no será efectiva. Debemos hacer que sienta que se le debe algo para pagar el esfuerzo invertido en activarla, en este caso girar la manivela. Para complementar esta "deuda" añadiremos de manera indirecta indicadores de progreso que dosifiquen la entrega de recompensas a medida que se progresa. Mostraremos que a corto plazo sus acciones tienen efectos en la máquina y daremos pistas de un gran climax al completar la secuencia:
1. Usuario aprenderá que al girar la manivela se activan solidos y se prenden luces
2. Las luces aumentarán a medida que progresa y al ser limitadas indica que hay un final
3. Se añadirán elementos al alcanzar *milestones* de progreso como vibración, compuertas que se abren o sonidos cambiantes.
4. Al completar la cantidad de vueltas las luces indicarán una sorpresa inminente
5. El esfuerzo del usuario se verá traducido en un poco de humo y un sonido patético
6. La máquina te vendió humo

Obviamente la decepción no será devastadora y es muy dificíl hacer que no tenga un tono cómico ya que la estructura de la interacción se asemeja a la de un chiste. Nuestra misión se habrá cumplido si el usuario llega al final de la interacción ya que significa que logramos hacer que compre humo de una máquina estática, sin leyenda y demandante. Vale mencionar que la máquina debe ser llamativa para que el usuario se acerque y empiece todo. Queremos aprovechar rasgos de las personas como la curiosidad o las ganas de no desperdiciar el esfuerzo/tiempo ya invertido. Estos aspectos serán el principal motor que hará funcionar nuestra máquina y contamos con ellos para que se generen interacciones.




