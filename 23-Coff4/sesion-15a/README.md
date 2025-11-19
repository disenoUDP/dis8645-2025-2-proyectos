# sesion-15a

Clase de avance!

Ok, este dia han pasado diferentes cosas en las cuales me he involucrado

En primer lugar la Aileen paso diferentes links con los cuales probar el parlante para la reproduccion de audio
Lo unico malo de esto es que solo tenemos uno para comprobar. por lo tanto las pruebas en terreno son muy acortadas. Tengo unas fotos junto al codigo en donde se muestran los intentos que logre hacer. en donde convertí un audio de 4 segundos en el formato requerido y con un conventor pude pasarlo a codigo y meterlo en el programa.

![alt text](http://url/to/img.png)

Dejare la carpeta con el codigo y un link adicional de wokwi:

https://wokwi.com/projects/447971725908102145


Por otro lado iba a hacer diferentes pruebas en un programa loquendo en una carpeta. pero se opto por usar audios de un niño pequeño que simule el de un mono

Por otro lado intentare buscar por mi cuenta, alguna otra manera de procesar el audio y dar diferentes audios 

Frases de "Jorge" (Aka sin nombre)

- Al detectar una persona:

1- Dame un abrazo
2- Acercate para que te abrace
3- Ven a darme cariño!

- Al notar que una persona no le esta dando afecto (primera pataleta):

1- ¿Por que te quedas parado?
2- ¿No quieres abrazarme?
3- ¿Acaso no me quieres?

- Segundo nivel (Segunda pataleta)

1- POR FAVOR ¿TAN DIFICIL ES?
2- SOLO ACERCATE
3- NO ME AMAS, NO ME AMAS!

- Tercer nivel

Ya no hay nada por lo que seguir existiendo...adios 

---

La idea ahora es buscar codigo para el sensor ultrasonico, posiblemente reutilizare el codigo de nuestro anterior proyecto (obviamente dando sus respectivos creditos)
Ese es otro de los archivos que debo subir

Trabajo proximo: 2 booleanas 
1 presencia de usuario
2 brazo amor
cada una de las boleanas necesitan imprimir en el puerto serial que se prendieran.
En una de las boleanas debe ir un if (nombre de la boleana) (); 

---

De aquí  se saco el inicio de todo el codigo y después se usó gemini 

https://naylampmechatronics.com/blog/10_tutorial-de-arduino-y-sensor-ultrasonico-hc-sr04.html

```cpp

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
 
bool presenciaUsuario = false;
bool brazoAmor = false;
 
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}


void loop() {
  digitalWrite(Trigger, HIGH);
delayMicroseconds(10);          //Enviamos un pulso de 10us
digitalWrite(Trigger, LOW);
 long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
 
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(100);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(1000); 
  
if (d < 20) { 
    presenciaUsuario = true;
  } else {
    presenciaUsuario = false;
  }
  
  // Lógica para brazoAmor (activación a menos de 5 cm)
  if (d < 10) { 
    brazoAmor = true;
  } else {
    brazoAmor = false;
  }

  if (presenciaUsuario) {
    Serial.println("presenciaUsuario se ha prendido.");
  }

  if (brazoAmor == true) {
    Serial.println("brazoAmor se ha prendido.");
  }

  Serial.println();
  delay(100); // Pausa de 100ms
}
```

---

Ok...Por razones de fuerza mayor terminamos juntandonos después de clases para seguir con el proyecto en llamadas de discord

En la primera vimos orden y resolvimos unas cuantas dudas y en la segunda nos pusimos de lleno a hacer el .ino

Adjunto pruebas de los sucesos


