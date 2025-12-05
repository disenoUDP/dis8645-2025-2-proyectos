# sesion-17a

El día de hoy llegue al LID tipo mediodía, donde  me propuse esta vez sí llegar a hacer la famosa pantalla de Inicio.

La pantalla de inicio debería tener a la AVA durmiendo, texto encima de la AVA, y que solo aparezca al principio una vez, osea que solo si se prende la maquina de cero, lo logre haciendo que los voids de la AVA contando solo se mostrará cuando los segundos fueran mayor a 0, mientras que la AVA durmiendo solo aparecerá cuando los segundos sean menores a 1.

Esto funciona por ahora, se bloquea al llegar a 0 y dejarlo sin usar por unos segundos, pero el botón, los cambios de segundos están todo bien que es bacan.

Todos estos últimos cambios fueron realizados con el motor //comentado, ya que sus delays eran bien fuertes, pero ahora los intentare cambiar.

Me hice caleta de distintos problemas, porque por incluso intentando el pasar el motor a 2 distintos void, uno para que se apagara y uno para que se prendiera, solo uno se activaba directamente, no dejaba pasar ni un milisegundo y el siguiente ya estaría activado, osea que se quedaba apagado constantemente en este caso puro porque estaba segundo en orden de la siguiente manera:

``` cpp

void ActuadorMotor::funcionaMotor() {

  tiempoActualTemporizadorPrendido = millis();
  tiempoActualTemporizadorApagado = millis();

  if (motorPrendido && tiempoActualTemporizadorPrendido - tiempoNuevoTemporizadorPrendido >= intervaloMotorPrendido) {
    // manda una señal de encendido al pin establecido previamente
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor se prendio");
    // cada medio segundo
    tiempoNuevoTemporizadorPrendido = tiempoActualTemporizadorPrendido;
    motorPrendido = false;
  }

  if (!motorPrendido && tiempoActualTemporizadorApagado - tiempoNuevoTemporizadorApagado >= intervaloMotorApagado) {
    // manda una señal de encendido al pin establecido previamente
    digitalWrite(motorPin, LOW);
    Serial.println("Motor se apago");
    // cada medio segundo
    tiempoNuevoTemporizadorApagado = tiempoActualTemporizadorApagado;
    motorPrendido = true;
  }
}

```
Y realmente no entendía en qué manera debía poner un tiempo intermedio para que no se activen simultáneamente, al punto de tener que preguntarle a don CHATGPT donde me dio una solucion que seria la siguiente: 

``` cpp

void ActuadorMotor::funcionaMotor() {
  tiempoActual = millis();
  if (motorPrendido) {
    if (tiempoActual - tiempoNuevoTemporizadorPrendido >= intervaloMotorPrendido) {
      digitalWrite(motorPin, LOW);  // apagar motor
      Serial.println("Motor se apago");
      motorPrendido = false;                          // cambiamos de estado
      tiempoNuevoTemporizadorApagado = tiempoActual;  // iniciamos el temporizador de apagado
    }
  } else {  // motor está apagado
    if (tiempoActual - tiempoNuevoTemporizadorApagado >= intervaloMotorApagado) {
      digitalWrite(motorPin, HIGH);  // encender motor
      Serial.println("Motor se prendio");
      motorPrendido = true;                            // nuevo estado
      tiempoNuevoTemporizadorPrendido = tiempoActual;  // iniciamos el temporizador de encendido
    }
  }
}

```

Que básicamente es un interruptor para cambiar entre estos 2 estados, donde me explicó que en el código que yo intente escribir no había necesidad de una función distinta para los tiempos actuales, el hecho que existiesen esas 2 distintas hacían que se pudiesen actualizar automáticamente cuando ambas se cumplian.

También debía hacer que el nuevo tiempo del temporizador de un estado, actualizará el del siguiente, de esa manera podían funcionar de la manera que tenía pensada tal cual.

Con este funcionamiento del los motores con millis se cambio la version del WEBO al WEBO_0_7_0.

Lo siguiente que intente fue el pasar la mayor cantidad de los componentes a su uso con los millis correctos, donde pude realizar el traspaso del display, específicamente donde AVA estaría “hablando” durante la cuenta regresiva eso salio bien despues de unos cuantos intentos, pero cuando intente hacer lo mismo con el reproductor de audio este trababa todo el proyecto, estoy bastante seguro que el reproductor con los millis es el problema porque varias versiones anteriores no se trababan, esto lo voy a tratar de resolver, pero por ahora subire la version del WEBO_0_7_1.

Ahora quiero que se detecte mi sensor tilt solamente cuando esté en inclinado por una cantidad de tiempo que yo quiero establecer, ya que el sensor puede cambiar de estado con un movimiento muy pequeño, y no quiero esto, solo si esta caido por digamos que más de 1 segundo es que debería empezar a reclamar, sino seria terrible el solo agarrarlo y que empiece a chillar.

Buscando por internet como se llamaria lo que quería hacer me encontré con un **debounce** para un botón:  

https://docs.arduino.cc/built-in-examples/digital/Debounce/  

Que es algo que permite percibir el cambio de estado en un botón, para que por ejemplo si se mantiene presionado no se registren continuamente nuevas presiones del botón.

Quiero dejar claro que esto si lo quiero aplicar al sensor de inclinación pero NO al botón, porque siento que la interacción va a ser un poco más amable si es que el usuario se le permite mantener presionado el botón para poder aumentar el tiempo del temporizador.

Bueno con todo eso mas o menos comprendido lo intente implementar por mi cuenta al codigo principal, fallando brutalmente, bueno no brutalmente pero ya me empecé a enredar con muchas cosas, también por el hecho de haber intentado ayudar a tantos grupos ya estoy medio fundido, así que le explique directamente a don chatGPT, con lo que me ayudó a llegar a lo siguiente.

``` cpp

#include "SensorTilt.h"

SensorTilt::SensorTilt() {}

void SensorTilt::configuracionTilt() {
	//Aca definimos el pin del sensor como entrada
	//Habilitamos el pull-up interno para el pin del sensor
	pinMode(tiltPin, INPUT);
	digitalWrite(tiltPin, HIGH);
}

void SensorTilt::funcionaTilt() {
    // Read the tilt sensor.
    // With pull-up enabled:
    // - LOW  = sensor CLOSED  → tilted
    // - HIGH = sensor OPEN    → upright
    int lecturaActual = digitalRead(tiltPin);

    // ----------------------------
    // CASE 1: SENSOR IS TILTED NOW
    // ----------------------------
    if (lecturaActual == HIGH) {

        // If this is the *first* moment we detect tilt,
        // record the time when tilt began.
        if (!enProcesoDeCaida) {
            enProcesoDeCaida = true;
            tiempoInicioCaida = millis();
        }

        // Check how long it has been tilted.
        if (millis() - tiempoInicioCaida >= tiempoNecesarioCaido) {
            // It remained tilted long enough → confirm "caido"
            if (!caido) {
                Serial.println("esta caido");
            }
            caido = true;
        }
    }

    // --------------------------------
    // CASE 2: SENSOR IS NOT TILTED NOW
    // --------------------------------
    else {
        // Reset the “fall in progress” flag every time sensor goes upright
        enProcesoDeCaida = false;

        // Immediately mark as upright
        if (caido) {
            Serial.println("esta parado");
        }
        caido = false;
    }
}

```

Lo cual funciono, pero no me gusto como quedo estructurado así que lo cambie y lo comente a lo siguiente:

``` cpp
#include "SensorSD.h"

// eliminamos SoftwareSerial porque ahora usamos el UART hardware Serial1
DFRobotDFPlayerMini player;

SensorSD::SensorSD() {}

void SensorSD::configuracionSD() {
  // comienza la comunicacion serial general
  // esta comunicacion es entre arduino y el computador/laptop al que se encuentre conectado
  Serial.begin(115200);

  // comienza la comunicacion serial del reproductor MP3
  // ahora usamos Serial1 porque es el UART de hardware del Arduino R4
  Serial1.begin(9600);

  pinMode(pinBusy, INPUT);

  // esta funcion if esta para verificar en el monitor serial si el reproductor funciona o no
  if (!player.begin(Serial1)) {
    // si NO funciona correctamente saldra este mensaje
    Serial.println("DFPlayer ERROR: no se pudo inicializar");
  } else {
    // si funciona correctamente saldra este mensaje
    Serial.println("DFPlayer online!");
  }
}

void SensorSD::funcionaSDAlarmaFuerte() {
  busy = digitalRead(pinBusy);

  // DFPlayer NO esta reproduciendo
  if (busy == HIGH) {
    // Esta variable es para manejar el volumen del archivo que sera reproducido
    // En este este caso tiene que ser fuerte
    player.volume(30);

    // Se define el archivo .mp3 que se encuentra en la tarjeta SD
    player.play(2);

    // notificar por el monitor Serial que fue reproducida la alarma fuerte
    Serial.println("Reproduciendo alarma fuerte");

    delay(200);  // prevent double-trigger
  } else {
    Serial.println("Alarma fuerte ya está sonando...");
  }
}

void SensorSD::funcionaSDAlarmaDebil() {
  int busy = digitalRead(pinBusy);

  // DFPlayer NO esta reproduciendo
  if (busy == HIGH) {
    // Esta variable es para manejar el volumen del archivo que sera reproducido
    // En este este caso tiene que ser despacio
    player.volume(5);

    // Se define el archivo .mp3 que se encuentra en la tarjeta SD
    player.play(1);

    // notificar por el monitor Serial que fue reproducida la alarma debil
    Serial.println("Reproduciendo alarma débil");

    delay(200);  // prevent double-trigger
  } else {
    Serial.println("Alarma débil ya está sonando...");
  }
}

```
