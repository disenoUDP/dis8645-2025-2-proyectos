# grupo-03

## GEE: Grupo Emocionalmente Estable - Integrantes

- [Aileen D’Espessailles Rojas](https://github.com/aileendespessailles-design) 
- [Santiago Gaete Fernández](https://github.com/santiagoClifford)
- [José Morales Berríos](https://github.com/jotamorales-romulus)
- [Carla Pino Barrios](https://github.com/Coff4)
- [Francisco Stephens González](https://github.com/FranUDP) 

--- 
### Presentacion textual

El dispositivo, un muñeco con forma de mono, solicita un abrazo y se muestra amable al inicio. Una vez que abraza al usuario, se niega a soltarlo y se aferra fuertemente, haciendo que el mono desarrolle un apego ansioso. Al ser dejado en la mesa, el muñeco comienza a gritar y amenaza con autolesionarse, lo que obliga al usuario a tomarlo de nuevo. Esto genera una sensación de incomodidad al crear un bucle interminable. El concepto expone la dependencia patológica que desarrollan los animales salvajes cuando los humanos los domestican. Toda la situación se habría evitado si el usuario nunca lo hubiese tomado.

### Metafora

La Responsabilidad, La libertad humana (de intervenir o abandonar) queda atrapada y anulada por la respuesta mecánica e inmutable (el bucle de apego) que esa misma libertad puso en marcha.

En este proyecto queremos transmitir como la responsabilidad humana puede ponerse en disposicion de una respuesta mecanica, generando pena y culpa, ante lo que seria la recreacion de un mono que imita ser uno verdadero. Esta respuesta mecanica deja a la persona en un bucle de apego constante que terminara siempre en tragedia.

En varios casos, cuando se genera un vinculo afectivo con un animal, la union emocional es tan fuerte, que cuando hay un cambio en esta relacion, por ejemplo: estar fuera unos meses alejados de la mascota, provocamos una dependencia emocional en donde una de las 2 partes llega a sufrir mas, en este caso jorge. 

### carta gantt 

| Tareas / Sesión                                       | 14a | 14b | 15a | 15b | 16a | 16b | 17a | 17b |
|---------------------------------------------------------|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| Definir Proyecto                                        |  x  |  x  |     |     |     |     |     |     |
| Redacción narrativa proyecto                            |  x  |     |     |     |     |     |     |     |
| Mapa de comportamiento (flowchart emocional)            |  x  |     |     |     |     |     |     |     |
| Pruebas de sensores (ultrasonido / presión)             |     |     |  x  |  x  |     |     |     |     |
| Pruebas de motores/servos                               |     |     |  x  |  x  |     |     |     |     |
| Módulo MP3 y audios                                     |     |     |  x  |  x  |     |     |     |     |
| Definición de interacciones físicas (cómo abraza / fuerza) | x | x  |     |     |     |     |     |     |
| Diseño de prototipo (bocetos + ergonomía)              |  x  |  x  |  x   |     |     |     |     |     |
| Prototipado para distribución interna                  |     |     |  x  |  x  |     |     |     |     |
| Integración de sensores con arduino                     |    |     |  x  |  x  |     |     |     |     |
| Modelado 3D                                             |     |  x  |  x  |  x  |  x  |  x  |  x  |     |
| Pseudocódigo                                            |  x  |  x  |     |     |     |     |     |     |
| Desarrollo de código                                    |     |  x  |  x  |  x  |  x  |  x  |  x  |  x  |
| Montaje interno versión 1 (cables, servos, sensor)      |     |     |  x  |  x  |     |     |     |     |
| Prototipado parte exterior (patrones de Jorge)          |     |     |  x  |  x  |  x  |  x  |     |     |
| Elección y compra de materiales (felpa, relleno)        |     |     |     |     |  x  |  x  |     |     |
| Costura / carcasa                                       |     |     |     |  x  |  x  |  x  |  x  |  x  |
| Pruebas de interacción real con usuario                 |     |     |     |  x  |  x  |  x  |  x  |  x  |
| Ajustes de comportamiento (tolerancia, intensidad, frases) |     |     |  x  |  x  |  x   |  x  |  x  |  x  |
| Confección prototipo final                              |     |     |     |     |  x  |  x  |  x  |  x  |
| Montaje final                                           |     |     |     |     |     |     |     |     |
| Documentación Proyecto                                  |  x  |  x  |  x  |  x  |  x  |  x  |  x  |  x  |
| Redacción README                                        |  x  |  x  |  x  |  x  |  x  |  x  |  x  |  x  |


### Bill of Materials 

| Componente            | Cantidad |
|-----------------------|----------|
| Parlante              | 1        | 
| Cable H-H             | varios   | 
| Servo motor           | 2        | 
| Sensor ultrasónico    | 1        |
| Módulo MP3            | 1        | 
| Botón de arcade falso | 1        |
| Sensor de presión     | 1        | 
| Motor DC              | 1        | 
| Mosfet                | 1        | 

---

### Mapa de flujo:

```mermaid
flowchart TB
    A["stand BY"] --> B["usuarie detectade"]
    B --> C["jorge pide amor"]
    C -- usuarie abraza --> F(["jorge feliz"])
    F --> K(["abraza devuelta"])
    K --> L(["abraza fuerte devuelta y no suelta"])
    L --> C
    C -- usuarie NO abraza --> G(["jorge triste"])
    G --> D(["entra en crisis, llora y se queja"])
    D --> E(["30 segundos sin amor"])
    E --> H(["amenaza con apagarse"])
    H --> I(["le da tiempo para que lo abraces de nuevo"])
    I --> C

    A@{ shape: rounded}
    B@{ shape: rounded}
    C@{ shape: diam}
     A:::Peach
     B:::Peach
     C:::Ash
     F:::Rose
     K:::Rose
     L:::Rose
     G:::Aqua
     D:::Aqua
     E:::Aqua
     H:::Aqua
     I:::Aqua
    classDef Peach stroke-width:1px, stroke-dasharray:none, stroke:#FBB35A, fill:#FFEFDB, color:#8F632D
    classDef Rose stroke-width:1px, stroke-dasharray:none, stroke:#FF5978, fill:#FFDFE5, color:#8E2236
    classDef Aqua stroke-width:1px, stroke-dasharray:none, stroke:#46EDC8, fill:#DEFFF8, color:#378E7A
    classDef Ash stroke-width:1px, stroke-dasharray:none, stroke:#999999, fill:#EEEEEE, color:#000000
```

Jorge es un robot cuya único sentido en la "vida" es ser amado. Al ser un robot, no entiende sobre sentimientos, por lo que la única forma en que es capaz de entender el amor es a través del contacto físico. Jorge pide amor amablemente, pero tiene una tolerancia a la frustración tan leve, que prefiere dejar de existir antes que asumir que dejará de ser amado. Cuando dejas de entregarle amor, jorge entrará en crisis. En primer lugar, comenzará a llorar y quejarse, cada vez más intensamente. Pasado 30 segundos sin recibir amor, se activa la alarma de seguridad que cuida a jorge del dolor por falta de amor. Se emite una alarma y una voz proclama: el mecanismo de autodestrucción se ha activado, por favor dale amor a jorge para evitar su muerte".

### Pseudocódigo

### Código

### Prototipado

![planimetría de la vértebra](./imagenes/planim.png)

![foto de la vértebra](./imagenes/vertebra.png)

![gif de la probeta 1](./imagenes/vertebra-probeta1.gif)

![gif probeta 1 otra prueba](./imagenes/vertebra-probeta1b.gif)

![vértebra v2](./imagenes/vertebra-v2.png)

![probeta de la vertebra-v2](./imagenes/vertebra-v2-ver.gif)



