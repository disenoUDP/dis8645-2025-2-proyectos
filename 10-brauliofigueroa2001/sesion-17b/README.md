# sesion-17b
## viernes 5 de diciembre
### avances y cosas pendientes

- to do: probar si funciona el módulo del humidificador con el código JUEVESTODOBIEN
- si es que funciona, probar y soldar bien el mp3 y unirlo a todo, probarlo con el código JUEVESTODOBIEN
- ver cuáles componentes son necesarios en protoboard y cuáles son necesarios soldar aparte de esos 2
- soldar encoder a pcb

- pendientes que no sé aún cuando haremos
- meter todo dentro de la carcasa y ordenarlo bien

novedades 4 pm

- aún no pruebo el mp3 soldado
- probé el humidificador con el código de la cami que era high y low, en un principio soltaba poco humo o lo hacía de forma más intermitente
- cambiamos la pieza por otro repuesto que teníamos y ahora sale más humo, creo que era porque la pieza anterior quedaba suelta y perdía contacto
- ahora debo probar el mp3 soldado y que el módulo tire humo cuando corresponde
- me apareció un error en los COM y no he podido hacer funcionar nada
- se arregló el error, reinicie el pc , me apareció COM5 y pude compilar y echar andar el código

NOVEDADES 5 PM

- ACABO DE PROBAR EL MÓDULO DEL HUMO CON EL REPUESTO CAMBIADO, AL CÓDIGO PRINCIPAL Y SALE HUMO EN LA FASE 6!!!
- ahora conectaré el módulo mp3 soldado
- pin 2 y 3 son rx y tx, no se por que estaban conectados ahi, en el código están declarados en 0 y 1

novedades 6 pm

- conectamos el módulo mp3 soldado respectivamente y el encoder dejó de sumar vueltas, se paralizaron todos los sensores y actuadores

novedades 18:44 pm

- LO ÚNICO QUE SE CAMBIÓ FUE LA CONEXIÓN DEL PIN RX CONECTADO A TX Y TX CONECTADO A RX, ESTO HIZO QUE FUNCIONARAN LOS AUDIOS COMPLETOS
- EN RANGO 5 SUENA EL SONIDO QUE DEBERÍA ESTAR EN RANGO 6, APARTE DE ESO NINGÚN OTRO ERROR
- probamos 2 rondas, todos los audios sonaron por completo, necesitamos tener registro
- hay registro
- acabo de dar vuelta los audios, en donde sonaba el 5 puse el 6 y viceversa, ahora suenan todos en el orden correcto

- PINOUT ENCODER: CABLE CAFE GND, CABLE ROJO VCC, CABLE GRIS SW pin 11, CABLE AZUL DT PIN 10, CABLE MORADO PIN 9 CLOCK

- en la linea if step % 30 == 0) si cambio este 30 por un número más grande, haremos que necesite más steps para completar una vuelta, esto sirve para que al momento de girar la manivela no saltemos tan rápido de estados, ya que, la manivela es más fácil de girar y manipular que un encoder. Sería un problema que el usuario podría girar muy rápido y pasar de fases de forma que parezcan casi imperceptibles.

