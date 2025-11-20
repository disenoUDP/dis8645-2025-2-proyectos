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

- Profundizar.
- 
### carta gantt 

| Tareas / Sesión                                       | 14a | 14b | 15a | 15b | 16a | 16b | 17a | 17b |
|---------------------------------------------------------|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| Definir Proyecto                                        |     |     |     |     |     |     |     |     |
| Redacción narrativa proyecto                            |     |     |     |     |     |     |     |     |
| Mapa de comportamiento (flowchart emocional)            |     |     |     |     |     |     |     |     |
| Investigación de sensores y actuadores necesarios       |     |     |     |     |     |     |     |     |
| Pruebas de sensores (ultrasonido / presión)             |     |     |     |     |     |     |     |     |
| Pruebas de motores/servos                               |     |     |     |     |     |     |     |     |
| Módulo MP3 y audios                                     |     |     |     |     |     |     |     |     |
| Definición de interacciones físicas (cómo abraza / fuerza) |  |     |     |     |     |     |     |     |
| Diseño de prototipo (bocetos + ergonomía)              |     |     |     |     |     |     |     |     |
| Elección y compra de materiales (felpa, relleno)    |     |     |     |     |     |     |     |     |
| Prototipado para distribución interna  | |     |     |     |     |     |     |     |
| Integración de sensores con arduino                 |     |     |     |     |     |     |     |     |
| Modelado 3D – esqueleto y funcionamiento interno        |     |     |     |     |     |     |     |     |
| Modelado 3D para molde / forma exterior de la tela      |     |     |     |     |     |     |     |     |
| Programación base del comportamiento  | | | | | | | | |
| Desarrollo adicional de código / ajustes                |     |     |     |     |     |     |     |     |
| Montaje interno versión 1 (cables, servos, sensor)      |     |     |     |     |     |     |     |     |
| Prototipado parte exterior (forro de Jorge)             |     |     |     |     |     |     |     |     |
| Costura / carcasa                             |     |     |     |     |     |     |     |     |
| Pruebas de interacción real con usuario                 |     |     |     |     |     |     |     |     |
| Ajustes de comportamiento (tolerancia, intensidad, frases) | | | | | | | | |
| Confección prototipo final         |     |     |     |     |     |     |     |     |
| Montaje final completo                                  |     |     |     |     |     |     |     |     |
| Documentación Proyecto                                   |     |     |     |     |     |     |     |     |
| Redacción README                                         |     |     |     |     |     |     |     |     |


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

agregar fotos, procesos, etc.
