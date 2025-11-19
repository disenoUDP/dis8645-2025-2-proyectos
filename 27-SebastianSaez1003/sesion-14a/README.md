# sesion-14a

Hoy llegue a corregir un poco el diagrama de flujo ya que realmente estaba suuuuuuper enredado, le pedí ayuda a Mateo y Misaa, de cómo podría crear esta acción constante, donde la máquina cada 30 segundos empezará a “girar”.

Aquí está la 1ra versión hecha en Mermaid, que realmente es difícil de seguir ya que no tiene un punto de inicio claro.

![Corrección de diagrama de flujo](./imagenes/diagramaDeFlujo1.png)

Luego de ver esto, Janis me hizo la recomendación de copiar el código de mermaid directamente al Markdown, que realmente se ve mucho mejor.

También me puse a hacer prueba con mis compañeros de grupo, para que gracias a sus comentarios y su verdadero entendimiento de cómo iría a funcionar esta máquina, llegamos a un diagrama de flujo mucho más claro.

El 2do diagrama de flujo sería el siguiente:

``` mermaid
---
config:
  theme: redux
  layout: dagre
  look: neo
---
flowchart TD
    A["La maquina esta prendida"] ==> B{"¿La maquina esta inclinada?"}
    B ==> D["Si"] & C["No"]
    D ==> F["Asistente virtual representa su estado de caida"]
    F ==> G["Parlante reproduce una sirena de gran volumen en loop"]
    G ==> H["LEDs parpadean constantemente para señalizar el problema en el que se encuentra la maquina"]
    H ==> I["¿Sigue inclinado?"]
    I ==> C & D
    C ==> E["Display muestra que el temporizador puede ser configurado"]
    E ==> r["El asistente virtual aparece para AYUDAR"]
    r ==> L["Presiona el boton para añadir 5 segundos a tu temporizador por cada vez presionada"]
    L ==> S["No añadas tiempo al temporizador por 5 segundos"] & l["¿Han pasado 35 segundos desde ultimo giro?"]
    S ==> a["El temporizador empieza a hacer una cuenta regresiva segun el tiempo especificado"] & l
    a ==> b["El tiempo del temporizador se acaba y llega al final"] & l
    b ==> c["El parlante reproduce un archivo de sonido de volumen regular, ya que no quisiera ser molesta para el usuario"]
    d["Luces parpadean suavemente, cada 2 segundos para no ser inconveniente"] ==> c & t["Presionar boton para apagar alarma"]
    c ==> d & t
    t ==> E
    Z["El asistente virtual querra dar muchas vueltas"] ==> X["¿Estas vueltas causaron la inclinacion del dispositivo?"]
    X ==> D & n1["NO"]
    l ==> n1 & n2["SI"]
    n1 ==> a & S & L
    n2 ==> Z
    I@{ shape: diam}
    E@{ shape: rounded}
    c@{ shape: rect}
    n1@{ shape: rect}
    n2@{ shape: rect}
    linkStyle 13 stroke:#D50000,fill:none
    linkStyle 15 stroke:#00C853,fill:none
    linkStyle 17 stroke:#2962FF,fill:none

    linkStyle 29 stroke:#2962FF,fill:none
    linkStyle 30 stroke:#00C853,fill:none
    linkStyle 31 stroke:#D50000,fill:none

```

También me puse a hacer prueba con mis compañeros de grupo, para que gracias a sus comentarios y su verdadero entendimiento de cómo iría a funcionar esta máquina, llegamos a un diagrama de flujo mucho más claro.

El 2do diagrama de flujo sería el siguiente:

(diagrama hecho con el código de mermaid)

Por mi parte me puse a probar 2 de los componentes más esenciales para nuestro proyecto, siendo el sensor tilt SW-520D y el motor.

Primero busque código de ejemplo del módulo SW-520D, encontrando uno que dejaba bastante claro su funcionamiento para mi a primera vista que puede ser encontrado aquí:

https://acortes.co/proyecto-21-sensor-de-inclinacion-sw-520d/

https://acortes.co/proyecto-21-sensor-de-inclinacion-sw-520d/

En realidad el sensor es relativamente fácil de usar, ya que no es dependiente de una biblioteca para su funcionamiento, simplemente hay que establecer su pin para que el arduino reciba una señal, y de esta manera, tomando el código de ejemplo que estaba en esa página web que es el siguiente:

```cpp
int pinSensor = 8;
int pinLed = 13;

void setup() 
{
  pinMode(pinSensor,INPUT);
  pinMode(pinLed,OUTPUT);
}

void loop() 
{
  if(digitalRead(pinSensor))
  {
    digitalWrite(pinLed,HIGH);
    delay(1000);
    digitalWrite(pinLed,LOW);
    delay(1000);
   }
   else
     digitalWrite(pinLed,LOW);
}

```
Lo modifique un poco para poder saber cual es la posición en la que se encuentra el sensor tilt con un mensaje en el monitor serial.

El código con mis modificaciones sería el siguiente:

``` cpp

// establecer el pin que sera conectado 
// el sensor para obtener su dato
int pinSensor = 8;
// crear una variable booleana para establecer 
// si hay inclinacion o no presente
bool parado;

// lo que es necesario para los funcionamientos en void loop
void setup() 
{
// establecer que el pin llamado pinSensor va a ser un input
  pinMode(pinSensor,INPUT);
// comenzar la comunicacion serial
  Serial.begin(9600);
}

// aqui ocurre todos los funcionamientos del codigo
void loop() 
{
  // si se recibe una señal desde el pinSensor
  if(digitalRead(pinSensor))
  {
    // significa que esta de lado
    parado = false;
     }
      else {
      // sino significa que esta parado
      parado = true;
       }

// si es que esta parado
if (parado){
  Serial.println("estoy hacia arriba");
  Serial.println(parado);
  delay(1000);
}
// si es que no esta parado
else if (!parado){
  Serial.println("estoy de lado");
  Serial.println(parado);
  delay(1000);
  }
}

```

Que en realidad, está sobre complejizado, la parte de la booleana que cree no era necesaria en absoluto, pero bueno, me entiendo y eso es lo importante.
