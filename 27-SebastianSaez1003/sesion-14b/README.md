# sesion-14b

Todos los computadores tienen una dirección MAC, que es única.

La dirección ip puede cambiar, la MAC no.

En el lenguaje de programación bash, que sirve para controlar terminales, para terminar un if statement tienes que poner fi, ya que no se ocupan murciélagos.

En Raspberrypi 5 se hacían las gráficas con x11 hace un tiempo.

Es posible establecer que te instalen una biblioteca de código específico, para que al pasar el tiempo se pueda ocupar de manera funcional según el momento que fue escrito el código, ya que las bibliotecas cambian con el pasar del tiempo, y en el futuro podría no funcionar una versión nueva.

Hoy durante la clase me puse a ver como controlar un motor, ya que no estaba seguro de qué manera tendría que conectar el motor a un arduino, sin causarle daño a ninguno de los dos.

Lo primero que hice fue buscar un video que ocupará un pwm, ya que le había hablado a Misaa, y iba a ser necesario para el uso correcto, acabe encontrando el siguiente video:

https://www.youtube.com/watch?v=XrJ_zLWFGFw

En este video enseñaba un ejemplo de manejo del motor a partir de un botón, donde mostraba el cableado y un código super simple, al punto que lo escribí de manera manual.

Pero como en nuestro proyecto ese motor no iba a ser activado mediante a un la interacción con un componente físico, quise darle una vuelta y integrarlo para que empezara a girar cada 2 segundos, que seria lo siguiente:

``` cpp

// pin al que será conectado el motor para ser controlado
int motorPin = 9;

void setup() {
  //establecer que el pin que va a mandar una señal
  // será el que fue declarado antes
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // manda una señal de encendido
  digitalWrite(motorPin, HIGH);  
  // cada 2 segundos
  delay(2000);                   

  //apaga la señal
  digitalWrite(motorPin, LOW);  
  // cada 2 segundos 
  delay(2000);                   
}

```

Funciono perfecto, asi que ahi esta confirmado el uso de otro componente, aún no lo voy a el código principal porque MOrgan estaba haciendo nuevas versiones del código con intentos de uso del display nokia, esperare a ver si puede solucionar esa parte para poner este uso del motor como también el del sensor de inclinación que hice la semana pasada.

A continuación hice una propuesta de descripción del proyecto:

“Weona Entidad de Balance Ovoide”

WEBO es un temporizador inconveniente.

WEBO funciona gracias a Ava, la gallina bailarina en su interior, ella se encargará de recordar el tiempo en el que debería sonar la alarma que es manejada por el temporizador.

Pero, Ava se aburre simplemente realizando la cuenta regresiva del temporizador, así que cada cierto tiempo, se pondrá a bailar, haciendo piruetas de una manera tan intensa que…

WEBO se puede caer de lado, esto es muy malo, porque Ava detesta estar en esa posición, por lo que hará sonar una alarma de alto volumen, para avisarle al usuario que algo malo ocurrió.

Empecé a utilizar una Biblioteca para utilizar los famosos millis, pero en realidad es más que todo para poder establecer todos los temporizadores que va a tener nuestra máquina, que realmente creo que va a ser complicado, pero ya me puse la idea, así que a darlo todo o morir en el intento.

La biblioteca que voy a intentar usar es “Scheduler” de Arduino https://github.com/arduino-libraries/Scheduler

Me voy a guiar y intentar empezar a ocupar los temporizadores según el ejemplo que se puede encontrar en https://docs.arduino.cc/tutorials/generic/multiple-blinks/

Lo primero que había que hacer, obviamente era instalar e incluir la biblioteca en nuestro código, pero si es que la voy a usar repetidas veces, porque no mejor crear un archivo header, que incluya en los archivos cpp de cada sensor y actuador, que es precisamente lo que hice.

En este punto me di cuenta que el mismo Arduino IDE me advirtió que esta biblioteca probablemente no era compatible con mi Arduino R4 mínima, así que me puse a buscar una alternativa.

Encontre una biblioteca que tiene de nombre “TaskScheduler” donde a partir de un ejemplo en su página de github https://github.com/arkhipenko/TaskScheduler/blob/master/examples/Scheduler_example01/Scheduler_example01.ino empece a intentar implementar las partes que podrian ser necesarias para su utilizacion.

Pero, realmente al ver los ejemplos me di cuenta que no era precisamente lo que necesitaba, ya que quería liberarme completamente de los delays, pero todos los ejemplos que vi los ocupabas, esto sería contradictorio.

Bueno, después de su hora tratando de leer documentaciones, me indigné y le pregunté a chat GPT cual seria mi mejor orden de ataque, y me dijo algo como “deja de darte tantas vueltas y ocupa millis de manera manual”.

Así que eso tendré que intentar organizar.
