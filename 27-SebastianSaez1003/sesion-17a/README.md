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

