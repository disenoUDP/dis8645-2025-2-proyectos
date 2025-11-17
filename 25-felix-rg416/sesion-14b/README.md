# sesion-14b

viernes 14 de noviembre

Hoy llegué súper tarde a la clase porque me quedé dormido.

Ayer estuve en Valparaíso todo el día porque mi polola necesitaba ayuda en un desfile de moda, fui como su fotógrafo y apoyo.

---

Como la clase pasada logré contar las vueltas del encoder, hoy voy a empezar a hacer la clase "Manivela" para poder encapsular lo que quiero hacer con el encoder.

Estoy usando estas clases de referencia:

- [sesión-05a](https://github.com/felix-rg416/dis8645-2025-02-procesos/tree/main/25-felix-rg416/sesion-05a)
- [Codigo Sesion-09b](https://github.com/felix-rg416/dis8645-2025-02-procesos/blob/main/25-felix-rg416/sesion-09b/grupo-06-montoyamoraga)

## Pines del encoder

![Pines del encoder](./imagenes/encoderPines.jpg)

El encoder tiene 3 pines:

- CLK (Clock) sirve para detectar los cambios de estado.
- DT (Data) sirve para detectar la dirección del giro.
- SW (Switch) sirve para detectar si se presiona el botón del encoder.

## Pseudo código

Existe un calculoVueltas(funcion que calcula las vueltas del encoder);

A partir del `calculoVueltas` se entrega `vueltas`

Existen rangos de vueltas:

- **Rango 0** = 0 a 1 vueltas (2)
- **Rango 1** = 2 a 8 vueltas (7)
- **Rango 2** = 9 a 16 vueltas (9)
- **Rango 3** = 17 a 24 vueltas (8)
- **Rango 4** = 25 a 29 vueltas (6)
- **Rango 5** = más de 30 vueltas

Si pasa de las 30 vueltas, se reinicia el conteo.

Si se retrocede en las vueltas, retroceden los rangos.

---

## Rangos

Los rangos de vueltas sirven para activar ciertos componentes paso a paso.

- En el Rango 0: led 0
- En el Rango 1: led 1 + sonido 1
- En el Rango 2: led 2 + sonido 2 + vibración
- En el Rango 3: led 3 + sonido 3 + compuerta 
- En el Rango 4: muchos leds + sonido de victoria + vibración + humificador
- En el Rango 5: Vuelve al inicio.

## Codigo

- `void configurar()`

    - `int patitaCLK`
    - `int patitaDT`
    - `int patitaSW`

- `void calculoVueltas()` incluirá la función que calcula las vueltas del encoder.
- `void rangos()` incluirá la función que define los rangos según las vueltas.

---

Me ha costado entender cómo hacer las funciones, métodos y atributos en las clases.

El martes le preguntaré a Aarón para que me ayude a solucionar mis dudas.