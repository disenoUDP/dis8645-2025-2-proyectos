# sesion-13b 07/11

## Apuntes clase

- Hoy debemos ver la lista de materiales que queremos utilizar y empezar el seudocódico de nuestra máquina.
- Debemos definir bien qué idea tenemos.
- que cada vez que haya algún punto que este un poco movido y a la hora de arreglarlo, se desarme más
- <https://afel.cl/products/pantalla-lcd-verde-20x04-2004-con-i2c?_pos=5&_sid=8686c6746&_ss=r>

Definir actuadores:

- Joystick: que se muevan las cosas de lugar, si va hacia arriba el LED estaria abajo.
- Botón joystick: reset de la figura, que vuelva a su 1er punto.
- Botón: que cambie de color el LED
- Potenciométro: autodestructor, que desarme todo.
- Botón 2: reset, que te lleve a otra figura.
  
## Game over

Parece una máquina arcade, pero tiene un pequeño problema: no está hecha para ganar.

Está compuesta por una pantalla de 8x8 píxeles, un joystick, dos botones y un potenciómetro.

Cuando el sensor ultrasónico detecta que alguien se acerca, deja de mostrar el mensaje S.O.S y aparece una figura perfectamente formada: un triángulo, una X o un cuadrado.

Pero al acercarte lo suficiente, algo se rompe.

Un píxel se mueve, y la figura deja de ser perfecta.

Desde ese momento, el usuario intenta repararla… aunque la máquina nunca lo permitirá.

`Controles`

Joystick: mueve los píxeles, pero en dirección contraria a la que intentas.

Botón del joystick: reinicia la figura al punto de error inicial.

Botón principal: cambia el color del LED y desplaza el píxel roto a un lugar aleatorio.

Potenciómetro: activa el modo autodestrucción, desarmando toda la figura.

Botón 2: reinicia y muestra una nueva figura.

`Concepto`

Game over es una experiencia interactiva que explora la frustración y la imposibilidad de alcanzar la perfección.
Cada intento por “arreglarla” solo genera más caos, convirtiendo el juego en una metáfora del error humano: inevitable, persistente y, de alguna forma, hermoso.
  

### Encargo

Hacer para próximo martes: presupuesto, carta gantt macro (semana a semana), bocetos físicos y diagramas de flujo, pseudocódigo.

#### Presupuesto

| Componente| Cantidad | valor| Link | Anotaciones|
|---|---|---|---|---|
|Resistencias 220|x|x|x|x|
|Sensor ultrasónico|1|$1.500|[Ultrasonico-hc](https://afel.cl/products/sensor-de-ultrasonico-hc-sr04)|x|
|Potenciómetro|1|$500|[potenciómetro](https://afel.cl/products/potenciometro-10k-ohm)|
|Matriz LED RGB 8x8|1|$9990|[matrizLEDrgbNeopixel](https://afel.cl/products/matriz-led-rgb-neopixel-8x8-ws2812-cjmcu64?_pos=2&_sid=c81d7044e&_ss=r)|x|
|Botones|3|$100|[botonTactil](https://afel.cl/products/boton-tactil-tapa-12x12x7-3-interruptor?_pos=1&_sid=433c4d5a9&_ss=r)|x|
|Joystick|x|$2000|[Joystick](https://afel.cl/products/joystick-palanca-de-mando?srsltid=AfmBOopSseOjbBU2wAQgNmAwmkg3E93k1qXa3xfHCyL3NsIaDLuQZYwu)|x|
|Clables macho macho y macho hembra|x|x|[MachoMacho](https://afel.cl/products/pack-20-cables-de-conexion-macho-macho?_pos=2&_sid=effb69b91&_ss=r) [conexionMachoHembra](https://afel.cl/products/pack-20-cables-de-conexion-macho-hembra?pr_prod_strat=jac&pr_rec_id=94b0883d2&pr_rec_pid=8381938139288&pr_ref_pid=8381849272472&pr_seq=uniform)|x|
|Pantalla LCD Azul|1|$2400|[pantallaLCDverde](https://afel.cl/products/pantalla-lcd-verde-20x04-2004-con-i2c?_pos=5&_sid=8686c6746&_ss=r)|x|
