# Sesión-15a

Martes 18 de noviembre, 2025

## Trabajo en clase

### Cosas que hablamos en la mañana

- Prácticamente comenzamos a trabajar al tiro en el proyecto-03. Hablamos de lo que nos iban a pedir para el viernes, cuando se muestra el proyecto-03. En el fondo, quieren que fundamentemos súper bien nuestros proyectos para que queden listos en teoría para el examen de taller con las comisiones, y que solo nos quede seguir desarrollando carcasas y discurso.

- Además, hablamos un poco de los eventos que va a tener la universidad, como una exposición de textil y una charla de Mateo para el otro miércoles.

---

## Proyecto-03

### Revisión de avances del proyecto

Conversamos un poco de lo que llevábamos listo. Le conté a Angie mejor la idea que teníamos sobre el ave del paraíso, ya que ella tenía que hacer la ilustración en pixel art.

Mientras tanto, Seba avanzaba con lo de los millis. Moss estuvo revisando el funcionamiento de la pantalla, porque en la clase anterior pensamos que se había quemado y no funcionaba ni con un código de prueba.

Luego Seba se dio cuenta de que algunos pines estaban soldados juntos, los desoldaron y se resolvió.

![foto pantalla funcionando](./imagenes/pantalla.jpeg)

### Carcasa

Jose trajo unas pruebas de alginato para la parte inferior de la carcasa, ya que va a recibir constantemente golpes y este material ayudaría al rebote. Podría decirse que esa, por ahora, es nuestra primera opción, si no funciona, vamos a probar con silicona, porque yo logré conseguir silicona para hacer testeos.

Cami estuvo modelando un molde base para volver a probar con alginato.

Yo estuve ordenando los componentes para que queden bien distribuidos y funcionen según sus movimientos y requerimientos, porque hay que almacenar muchas cosas dentro de una forma más orgánica, y la verdad me complicó un poco solo imaginar cómo distribuir todo. En eso fue en lo que más avancé hoy.

**Dentro hay que almacenar:**

- Batería portátil

- Arduino

- Motor

- Sensor

- Protoboard

- Espacio para los cables

**Y dejar expuesto:**

- Speaker

- Pantalla display

- Botones

### Investigacion botones

**Millis**

¿Por qué usar millis para el temporizador?

Con delay, el Arduino se detiene por completo. Se congelan los sensores, la pantalla, los motores y nada avanza, porque el flujo queda en pausa esperando.

En cambio, con millis, el sistema funciona de manera asíncrona. Permite ejecutar múltiples acciones al mismo tiempo y seguir actualizando la pantalla, los motores y los sensores sin bloquear el resto del comportamiento.

**Que el temporizador se detenga cuando el valor de segundos llegue a 0**

Teníamos la variable de segundos definida en el setup.

En el loop estábamos descontando con la línea segundos -= 1, y el delay(1000) hacía que ese ciclo corriera cada segundo.

Para que el temporizador no siguiera bajando a valores negativos, necesitamos agregar una condición que evalúe si segundos > 0.

Solo mientras quede tiempo se ejecuta el descuento; cuando llega a 0, el decremento se detiene y el temporizador queda fijo.

Esa verificación es lo que evita que el conteo siga corriendo en negativo.

```cpp

if (segundos > 0) {
  segundos -= 1
  delay(1000)
}
```

Vi este video  [Arduino desde cero en Español - Capítulo 77 - Timer Interrupts ](https://youtu.be/kI-jT-y1SKQ?si=ZphJria6euax7LPc) pero me confundí más

Vi este otro video [¿Qué temporizador es mejor en Arduino? ¿Delay o Millis?](https://youtu.be/TVYFfhDKLK8?si=F9Vvom811NlrsgsQ) y ya no me queda claro si con lo de delay está bien detener el conteo, porque delay detiene otras funciones, y por eso se utilizan millis.

**Según ChatGPT, si ocupo millis debería hacer esto:**

millis() va contando el tiempo sin detener el programa.

Cada 1000 ms hacemos la validación.

El if (segundos > 0) asegura que el contador se detenga exactamente en 0.

```cpp
unsigned long tiempoAnterior = 0;
int intervalo = 1000;  
int segundos = 30;     // el valor inicial que definimos

void loop() {
  unsigned long tiempoActual = millis();

  // revisamos si pasó 1 segundo
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;

    // solo descontamos si aún quedan segundos
    if (segundos > 0) {
      segundos -= 1;
    }
  }
}
```

**Ver que si se mantiene presionado, no sume infinitamente 5 s**

Me imagino que, para evitar que sume infinitamente, el botón tiene que sumar solo cuando pasa de no estar presionado a estar presionado. O sea, agrega 5 s en el primer contacto y no vuelve a sumar hasta que se suelte y se presione nuevamente.

Se agregan 5 s cuando el botón se presiona por primera vez

No vuelve a sumar hasta que el botón se suelte y se presione nuevamente

**Según ChatGPT, el código deberíamos hacerlo así:**

```cpp
int boton = 2;
int segundos = 0;

bool estadoActual = LOW;
bool estadoAnterior = LOW;

void setup() {
  pinMode(boton, INPUT_PULLUP); 
}

void loop() {
  estadoActual = digitalRead(boton);

  // Detección de flanco: pasa de HIGH a LOW (botón presionado)
  if (estadoActual == LOW && estadoAnterior == HIGH) {
    segundos += 5;        // Suma 5 s UNA sola vez
  }

  estadoAnterior = estadoActual; 
}
```

**Ver soldar y/o hacerle una base**

### Palabras importantes

[Alginato](https://es.wikipedia.org/wiki/Alginato): El alginato es un polímero glicosídico constituido por los monosacáridos D-manurónico y L-gulurónico y es extraído de las algas pardas pertenecientes a la clase filogénica Phaeophyceae. En odontología, forma parte de la masa utilizada para obtener impresiones de los dientes y de los tejidos blandos adyacentes. Esta masa está compuesta de alginato y sales de calcio que, tras su preparación, ofrece un tiempo de trabajo entre 3 a 6 minutos. 
