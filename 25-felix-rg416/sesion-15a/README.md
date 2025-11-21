# sesion-15a

martes 18 de noviembre

Aarón me ayudó con el código.

Lo actualizamos y ahora es el [manivelaFinal](./manivelaFinal/)

Habían hartos errores en el código original.

Cambiamos la forma de hacer lo de los rangos, en vez de poner nombre a cada uno, hicimos que con el `int rango;` se vaya definiendo los rangos con un if,
así:

```cpp
  if (Manivela::vueltas >= 0 && Manivela::vueltas <= 1) {
    Manivela::rango = 0;
```

Todo esto dentro del void `void Manivela::calcularRango() {`

También me faltó poner `Manivela::` en varias partes del código, pero ya se resolvió.

Los `String` son complejos, por lo tanto, Aarón me recomendó usar `bool` para "direccionActual"

---

Por otro lado, Misa nos mostró que nuestros componentes consumen casi el máximo ed miliamperios que puede entregar el Arduino Uno R4 Minima conectado a USB C.

Nos recomendó usar si o sí el USBC como funete de poder.

![explicación en ppizarra de Misa](./imagenes/pizarraMisa.jpg)

---

Ahora voy a empezar a hacer el código para el humificador.

Para empezar, se debe definir el pin y el nombre `humo`, también definir que debe estar en `HIGH` y que cuando lo queramos usar estará en `LOW`.

```cpp
const int humo = 7;
...
// dentro del setup
pinMode(humo, HIGH);
```

Para llamarlo con el rangoN sería algo así:

```cpp
if (rango == 5) {
  digitalWrite(humo, LOW);
}
```

---

Estuve tratrando de hacer el código de los rangos en clases, pero no funcionó.

[Codigo de rangos en clases](./manivelaFinalMentira/)

No identifica los pasos cuando corresponde, no identifica el rango ni las vueltas.

Modifiqué el código de MCIelectronics para que funcione con rangos.

[Encoder con rangos sin clases](./encoderConRangos/)

En ese código, entrega todo lo que le pido (pasos, vueltas y rangos).

Funciona perfecto, pero no está en clases. No sé si eso realmente importa, pero me gustaría que estuviera en clases para que sea un poco más ordenado.

Tal vez no aporte ni quite.

Traté de poner notas para que se entienda mejor.

## Carcasa

---

Volviendo al código.

Con Migue estamos viendo cómo hacer que cuando se sume una vuelta suene un sonido sólo una vez, y no se repita el sonido mientras siga girando.

Creo que sería más o menos así:

```cpp
Si se suma una vuelta {
    sonido suena una vez;
    sonido no seuena;
}
```

---

La meta es hacer que los leds se prendan secuencialmente según el rango en el que estemos.

Por ejemplo, si estamos en el rango 3, se prenden los leds 1, 2 y 3.

LO LOGRÉ

Usé el código [encoderConRangosFunciona](./encoderConRangosFunciona/encoderConRangosFunciona.ino) y le agregué lo que hizo Migue con los leds en el código[vendeHumoFullMIGUE](./vendeHumoFullMIGUE/) en el archivo [Leds.cpp](./vendeHumoFullMIGUE/Leds.cpp)

Lamentablemente no pude hacer que funcione en clases, así que lo hice en el archivo .ino.

En en un momento me quedé pegado porque el código no tiraba error, pero las luces no se prendían en ningún momento.
Era un pequeño detalle: me equivoqué en la parte que activa los leds sólo por poner `pinMode` 
en vez de `digitalWrite`.

> HAY  QUE ESTAR ATENTOS A ESOS DETALLES.

Ahora los leds se prenden según el rango en el que esté la manivela.

El código final es [ledsXmanivela](./ledsXmanivela/)

![gif de leds según rango](./imagenes/gifledsXmanivela.gif)

## Codigo

Para el código queremos hacer que la manivela controle cada componente dependiendo del rango en el que esté.

El encoder funciona por pasos, para definir los rangos primero hay que definir cuántos pasos hay por vuelta y luego cuantas vueltas por cada rango.

Usamos un código de MCIelectronics como base y a partir de éste fuimos haciendo las modificaciones necesarias para encender los leds como nosotros quisiéramos.

### Primera parte

En primer lugar, para contar los pasos y las vueltas, usamos este código:

```cpp
// lee el estado actual del CLK
	currentStateCLK = digitalRead(CLK);

// si los ultimos estado actuales del CLK son diferentes entonces ocurrió un pulso
// reacciona solo a 1 cambio de estado para evitar un doble conteo
	if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

// si el estado DT es diferente al estado del CLK
// entonces el encoder de rotación tiene un CCW y esto significa que
// está en sentido antihorario CCW es decir esta disminuyendo el valor
		if (digitalRead(DT) != currentStateCLK) {
			step++;
			currentDir = "CW";
    } else {
      step--;
			currentDir = "CCW";
		}

    // cada 20 pasos es una vuelta completa
		// esto nos servirá para definir los rangos
    if (step % 20 == 0) {
			vueltas++;
		}
```

### Segunda parte

Para fenidir los rangos según las vueltas, usamos este código:

`if (vueltas >= 0 && vueltas <= 1) {` = Si el valor de vueltas es mayor o igual a 0, Y al mismo tiempo, es menor o igual a 1

Por lo tanto, `rango = 0;` = el rango será igual a 0.

Así sucesivamente con cada rango.

```cpp
		if (vueltas >= 0 && vueltas <= 1) {
			rango = 0;
		}
    else if (vueltas >= 2 && vueltas <= 3) {
			rango = 1;
		}
    else if (vueltas >= 4 && vueltas <= 5) {
			rango = 2;
		}
    else if (vueltas >= 6 && vueltas <= 7) {
			rango = 3;
		}
    else if (vueltas >= 8 && vueltas <= 9) {
			rango = 4;
		}
    else if (vueltas >= 10) {
			rango = 5;
		}
```

### Tercera parte

Para prender los leds según el rango, usamos este código:

`if (rango == 1)` = Si el rango es igual a 1.

`digitalWrite(led1, HIGH);` = Prende el led1.

`digitalWrite(led2, LOW);` = Apaga el led2.

```cpp
	if (rango == 1) {
		digitalWrite(led1, HIGH);
		digitalWrite(led2, LOW);
		digitalWrite(led3, LOW);
		digitalWrite(led4, LOW);
		digitalWrite(led5, LOW);
	}
```

En cada rango se le va agregando un led más.