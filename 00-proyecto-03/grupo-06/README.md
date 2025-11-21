# Grupo-06 Waos

## Proyecto-03

**Integrantes**

- Bernardita Jesús / [Bernardita-Jesus](https://github.com/Bernardita-Jesus)

- Sebastian Saez / [SebastianSaez1003](https://github.com/SebastianSaez1003)

- Morgan Aravena / [Mosswhosmoss](https://github.com/Mosswhosmoss)

- Angela O'Ryan / [Hiinalia](https://github.com/Hiinalia)

- Camila Delgado / [Notcaamila](https://github.com/notcaamila)

- Josefa Quape / [Joquape](https://github.com/Joquape)

## Presentación textual

AGREGAR SENTIMIENTO Y METÁFORA

AGREGAR CONTEXTO DE USO, TEMPORIZADOR DE LAS DE 5 SEGUNDOS

### Descripción general

“Weona Entidad de Balance Ovoide”

WEBO es un temporizador inconveniente.

Está pensado para una persona que necesita temporizar intervalos cortos o variables, desde 5 segundos en adelante, según la demanda de su actividad.

WEBO funciona gracias a Ava, el ave del paraíso en su interior, ella se encargará de recordar el tiempo en el que debería sonar la alarma que es manejada por el temporizador.

Pero, Ava se aburre simplemente realizando la cuenta regresiva del temporizador, así que cada cierto tiempo, se pondrá a bailar, haciendo piruetas de una manera tan intensa que… WEBO se puede caer de lado, esto es muy malo, porque Ava detesta estar en esa posición, por lo que hará sonar una alarma de alto volumen, para avisarle al usuario que algo malo ocurrió.

### Sentimiento

El sentimiento central del proyecto es la frustración.

Esto se evidencia durante toda la interacción que tenga el usuario con WEBO, porque desde el momento que se enciende, no sólo activa un temporizador, lo hace responsable de Ava, lo que implica estar pendiente, observando y ansioso de que se pueda caer.

En cambio en un temporizador común, el usuario activa el conteo y confía en no tener que estar pendiente del paso del tiempo ya que le avisará a uno en el momento justo.

Con WEBO esa lógica no funciona porque también pone en juego la capacidad de estar atento. Hace que el usuario esté consciente del tiempo al punto de la frustración.

Esto surge porque la alarma se convierte en una acusación de que el usuario falló , ya no se trata de que pasen los 5 segundos, sino que no ocurra otra caída.

WEBO transforma una acción simple en una experiencia molesta, mostrando cómo la frustración puede hacer que un objeto útil se vuelva una carga.

## Inputs y Outputs

### Inputs

- Sensor de inclinación tilt
- Botón

### Outputs

- Display LCD Nokia 5110
- Mini parlante altavoz
- Mini motor DC alta velocidad
- Modulo reproductor mp3
- Luces LED

## Carta Gantt

| Objetivo / Sesión                          | 14a - 11nov | 14b - 14 nov | 15a - 18 nov | 15b - 21 nov | 16a - 25 nov | 16b - 28 nov | 17a - 02 dic | 17b - 05 dic |
|--------------------------------------------|:-----------:|:------------:|:------------:|:------------:|:------------:|:------------:|:------------:|:------------:|
| Conceptualización clara y escrita          |      ✅️      |              |              |              |              |              |              |              |
| Diagrama de flujo usuario                  |      ✅️      |       ✅️      |              |              |              |              |              |              |
| Investigación de uso de componentes        |      ✅️      |       ✅️      |              |              |              |              |              |              |
| Estudio referentes gráficos                |      ✅️      |       ✅️      |              |              |              |              |              |              |
| Comprobar funcionalidad componentes        |             |       ✅️      |              |              |              |              |              |              |
| Definición y boceteado de Pantallas        |             |       ✅️      |       ✅️      |              |              |              |              |              |
| Investigación materialidad carcasa         |             |       ✅️      |       ✅️      |              |              |              |              |              |
| Medir componentes para diagramar           |             |       ✅️      |       ✅️      |              |              |              |              |              |
| Maqueteo de la propuesta de carcasa        |             |       ✅️      |       ✅️      |       ✅️      |              |              |              |              |
| Integración componentes a código           |             |       ✅️      |       ✅️      |       ✅️      |              |              |              |              |
| Correcciones ortográficas comentarios      |             |              |       ✅️      |       ✅️      |              |              |       ✅️      |       ✅️      |
| Discurso Proyecto 03                       |             |              |       ✅️      |       ✅️      |              |              |              |              |
| Exploración material                       |             |              |       ✅️      |       ✅️      |       ✅️      |              |              |              |
| Programación de uso simultáneo componentes |             |              |       ✅️      |       ✅️      |       ✅️      |              |              |              |
| Prototipado Carcasa                        |             |              |       ✅️      |       ✅️      |       ✅️      |              |              |              |
| 30% de gráficas en estado final            |             |              |              |       ✅️      |       ✅️      |              |              |              |
| Implementación de Millis                   |             |              |              |       ✅️      |       ✅️      |       ✅️      |       ✅️      |              |
| 60% de gráficas en estado final            |             |              |              |              |       ✅️      |       ✅️      |              |              |
| 90% de gráficas en estado final            |             |              |              |              |              |              |       ✅️      |              |
| 100% de gráficas en estado final           |             |              |              |              |              |              |              |       ✅️      |
| Fabricación de las carcasa Final           |             |              |              |              |              |              |       ✅️      |       ✅️      |
| Discurso Examen                            |             |              |              |              |              |              |       ✅️      |       ✅️      |
| Entrega proyecto 03                        |             |              |              |       ✅️      |              |              |              |              |
| Documentación fotográfica y audiovisual    |      ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |
| Documentación en GitHub                    |      ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |       ✅️      |


## Diagrama de Flujo

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

## Presupuesto

| Componente                        | Cantidad | Precio | Proveedor                                                               |
|-----------------------------------|----------|--------|-------------------------------------------------------------------------|
| Módulo sensor de inclinación tilt | 1        | $1496  | https://altronics.cl/switch-inclinacion-sw520                           |
| Módulo reproductor MP3            | 1        | $2990  | https://afel.cl/products/modulo-reproductor-mp3-dfplayer-mini           |
| Pantalla display LCD Nokia 5110   | 1        | $5000  | https://afel.cl/products/pantalla-display-lcd-nokia-5110                |
| Mini parlante altavoz 3w          | 1        | $3000  | https://afel.cl/products/mini-parlante-altavoz-de-3w                    |
| Botón táctil 12x12x7.3            | 1        | $100   | https://afel.cl/products/boton-tactil-tapa-12x12x7-3-interruptor        |
| Motor DC alta velocidad           | 1        | $500   | https://afel.cl/products/3v-0-2a-12000rpm-65gcm-mini-micro-dc-motor-for |
| Cables dupont                     |          | $2500  | https://afel.cl/products/pack-60-cables-de-conexion                     |
| Cables dupont entrada salida      |          | $1000  | https://afel.cl/products/pack-20-cables-de-conexion-macho-hembra        |
| Resistencia 10k                   | 7        | $4990  | https://afel.cl/products/kit-600-resistencias-1-4w-30-valores           |
| Diodo Rectificador 1N4007         | 1        | $100   | https://www.electroardu.cl/diodo-rectificador-1n4007                    |
| MOSFET BS170 tipo N TO92          | 1        | $200   | https://depaquete.cl/index.php                                          |

**Presupuesto estimado total – 21.876**

Gasto real del equipo – 6.400

## Código

## Prototipo

## Bibliografía
