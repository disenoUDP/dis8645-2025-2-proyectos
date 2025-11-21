# sesion-15a

## 2025-11-18

componentes:

- motor dc: brazos
- 2 servo:
  - servo01: columna
  - servo02: rotación
- ultrasónico
- módulo mp3
- parlante
- sensor de presión

```cpp
//mono está calmao
//el sensor ultrasónico está sensando
//si no se detecta presencia, se mantiene calmao
//si una persona está a menos de 20cm del mono, pide amor
//pide amor: audio, una voz que dice "dame un abrazo"
//si se detecta un objeto a menos de 10cm, los brazos se cierran(moviendo servo01 90°)
//si no se detecta un objeto comienza la pataletaLeve
//pataletaLeve: audio llorar
//si el sensor ultrasónico detecta un objeto a menos de 5cm se interrumpe la pataleta(en teoría este objeto es un brazo)
//si pasan 10 segundos de pataletaLeve, sin que el ultrasónico detecte algo a menos de 5cm, comienza la pataleta brígida
//pataletaBrigida: audio, servo01 y servo02 se giran 20° y -20° repetidamente
//si se detecta un objeto a menos de 5cm se interrumpe la pataleta
//si pasan 10 segundos de pataletaBrigida, sin que el ultrasónico detecte un objeto a menos de 5cm, comienza la autodestrucción
//autodestrucción: reproducción de audio, el servo02 gira 120°, el servo03 gira 90 grados lentamente. Luego el servo02 vuelve a 0° lentamente, y luego a 120° velozmente.
//si el ultrasónico detecta un objeto a menos de 5cm se interrumpe la autoDestrucción. Toda esta secuencia dura en total 15 segundos, luego el servo02 se queda en 120° durante 20segundos y luevo vuelve a 0°
```

## sensor de presión

[tutorial del sensor de presión](https://www.youtube.com/watch?v=pEbdN-JzKDA)

![video del sensor de presión funcionando](./imagenes/presion.gif)

### encargos pendientes

hoy, 19 de noviembre, me pongo al día.

#### encargo 17 - sesión-11b

Claudia González Godoy es una artista nacida en 1983. Ha tenido varias de sus obras expuestas en diferentes museos y exhibiciones, como la galería Gabriela Mistral, o el museo de la Solidaridad Salvador Allende.

##### investigación sobre ríos

- <https://es.wikipedia.org/wiki/Río>
¿qué es un río?

según wikipedia, un río es una corriente de agua que fluye con continuidad por un cauce.

el proyecto más antiguo que pude encontrar relacionado a la fluidez de un líquido por un cauce es [water resistenace](https://www.claudiagonzalez.cl/projects/water-resistance).

"es un proyecto de investigación artística que busca establecer una reflexión sobre los medios y los dispositivos electrónicos a partir del agua como punto de tensión en el desarrollo tecnológico. Comprende además una exploración sobre las materialidades o interfaces de interacción y cómo a partir de sus interconexiones con los soportes puede provocarse una tensión entre dos elementos de suma relevancia para la vida: el agua y la electricidad."

considero este como el punto inicial donde Claudia se interesa en las propiedades del agua con fines artísticos. A partir de entonces Claudia creó múltiples proyectos referentes al agua, y la fluidez de esta misma.

A partir de este interés por la fluidez, el paso más esperable a seguir es el fenómeno de los ríos, siendo una especie de "magnificación" de lo que ya venía trabajando. Por ejemplo, el proyecto [hidroscopía mapocho](https://www.claudiagonzalez.cl/projects/hidroscopia-mapocho) estudia y reflexiona sobre el estado y percepción que tenemos sobre los ríos metidos en espacios urbanos, y cómo se van mezclando los cauces naturales con los artificiales.

Me parece un fenómeno muy interesante de abordar. Además , el agua como material me llama mucho la atención, ya que como diseñador industrial, me siento acostumbrado y cómodo trabajando con materiales sólidos, y los líquidos presentan una complejidad y espontáneidad muy interesante.

Claudia ha participado en múltiples eventos nacionales e internacionales, entre ellos: "LIWOLI (Austria), SOL (España), EEII (Croacia),FILE (Brasil), Sudex (Argentina), Tsonami (Chile) y la BVAM (Chile), Festival de la Imagen de Manizales (Colombia), entre otros."

cita de <https://15.bienaldeartesmediales.cl/participantes/claudia-gonzalez>

en lo personal, entiendo la obra de Claudia(entendiendo al artista como una obra en sí) como una intersección entre el arte, la naturaleza y la electrónica. Y el entender como se relacionan estos fenómenos, y a su vez, ver como estos mismos son afectados entre sí. Estudiar la obra de Claudia "CGG" me inspira a valorar la naturaleza(específicamente la de Chile), y a intentar encontrar dimensiones dignas de ser exploradas y estudiadas dentro de esta. Lo puedo comparar con ese tatuaje que te hiciste en la media, cuyo significado era inexistente hasta que empezó a ser parte de tu vida, y ahora sientes que te lo tatuaste por esas razones, que no existían en el momento cuando te hiciste el tatuaje. Estudiar la naturaleza es hermoso porque siempre estuvo ahi, quizás de no ser por ella no estarías aquí, pero no le das importancia hasta que decides ponerle antención, y preguntarte sobre su existencia y función.

### avance lindo

![circuito motor dc unidireccional](./imagenes/circuito-unidireccion.jpg)

para controlar el motor DC, se necesita un proceso más simple que solo conectarlo al arduino. En caso de hacer eso, puede estropear el microcontrolador.

con el circuito de la imagen puedo controlar el prendido y apagado del motor. Pero solo en una dirección.

![circuito motor dc bidireccional](./imagenes/circuito-bidireccion.jpg)

con este nuevo circuito, puedo controlar tanto la aceleración como la dirección del motor.

ambos códigos y cirucitos fueron sacados de [este tutorial](https://programarfacil.com/electronica/motor-dc)

### sensor presión

[tutorial](https://www.instructables.com/FSR-Tutorial)

## pseudocódigo v3

//mono está calmao
//el sensor ultrasónico está sensando
//si no se detecta presencia, se mantiene calmao
//si una persona está a menos de 20cm del mono, pide amor
//pide amor: audio, una voz que dice "rascame la watita"
//si el sensor de presión sensa algo(moviendo el motor dc por 4 segundos)
//si no se detecta un objeto comienza la pataletaLeve
//pataletaLeve: audio llorar
//si el sensor de presión sensa algo, se detiene la pataleta, y se gira el motor dc por 4 segundos
//si pasan 10 segundos de pataletaLeve, sin que se detecte presión, comienza la pataleta brígida
//pataletaBrigida: audio, servo01 se giran 20° y -20° repetidamente
//si el sensor de presión sensa algo, se detiene la pataleta, y se gira el motor dc por 4 segundos
//si pasan 10 segundos de pataletaBrigida, sin que sense presión comienza la autodestrucción
//autodestrucción: reproducción de audio, el servo02 gira 120°, el servo gira 90 grados lentamente. Luego el servo02 vuelve a 0° lentamente, y luego a 120° velozmente.
//si se sensa presión, se interrumpe la autoDestrucción. Toda esta secuencia dura en total 15 segundos, luego el servo02 se queda en 120° durante 20segundos y luevo vuelve a 0°