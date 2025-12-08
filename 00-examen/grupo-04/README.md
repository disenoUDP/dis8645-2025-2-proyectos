# grupo-04 - Cachureos

INTEGRANTES
- Yamna Carrión / [yamna-bit](https://github.com/yamna-bit)
- Valentina Chávez / [valechavezalb](https://github.com/valechavezalb)
- Antonia Fuentealba / [AntFuentealba](https://github.com/AntFuentealba)
- Millaray Millar / [mmillar95](https://github.com/mmillar95)
- Sofía Pérez / [sofia-perezm](https://github.com/sofia-perezm)
- Valentina Ruz / [vxlentiinaa](https://github.com/vxlentiinaa)

---

## Presentación textual

<!-- QUÉ -->

`Atrápame si puedes` es un juego interactivo diseñado para frustrar al usuario. El controlador del juego es contraintuitivo, no tiene un manual claro ni lineal, y requiere mucha destreza de parte del usuario para lograr tareas que parecen simples. Esto llega a hacerle dudar si vale la pena seguir intentando ganar. Los personajes del juego consisten en el equipo docente de este curso, funcionando como una parodia de la poca proporcionalidad que existe en la academia entre esfuerzo y resultados.

<!-- PARA QUIÉN / DÓNDE / CUÁNDO -->

Este es un juego para 1 persona a la vez, dura 30 segundos la interacción, y es una instalación tipo tótem. Existen dos tipos de interacción: la del usuario y la del espectador, y la relación entre ambas estructura la experiencia. Aquí aparece la metáfora central del proyecto, inspirada en figuras como el mito de Sísifo y el castigo de Tántalo: el jugador vive un “casi logro” constante, donde cada intento parece acercarlo, pero nunca del todo; mientras que la audiencia observa este esfuerzo repetitivo que roza lo absurdo, generando una mezcla de tensión y humor. Esta doble lectura sostiene el sentido del juego, donde lo frustrante se vuelve cómico cuando es compartido.

<!-- HISTORIA DEL JUEGO -->

El juego consiste en una pantalla con animaciones que muestran el estado actual del sistema, y dos controladores que deben usarse simultáneamente. El objetivo es atrapar hadas, lo que se dificulta por los controles: el jugador descubre progresivamente cómo usar sus manos dentro del juego, y esa torpeza inicial genera una frustración cómica para los espectadores, haciendo que el jugador, en vez de controlar, genere caos. Cuando por fin atrapa un hada, aparece un mensaje de felicitación, pero también un recordatorio frustrante: después de todo el esfuerzo de atrapar una, aún quedan unas 444 hadas por atrapar para lograr un minúsculo bono en la nota de un examen.

<!-- INSTRUCCIONES DE USO -->

El jugador presiona los sensores para controlar una red atrapahadas y capturar a las hadas, que representan a los docentes. Para concretar la captura, debe aplicar la presión adecuada con ambas manos y, al alcanzar el objetivo, mover el mando arriba y abajo con un gesto rápido que activa el acelerómetro. Esta secuencia de acciones contribuye a la sensación de “casi” y esfuerzo repetitivo que estructura toda la experiencia.

<!-- POR QUÉ HICIMOS ESTO  -->

Diseñamos a partir de lo cómico, ver cómo podíamos convertir en parodia situacional de la vida lo que para muchas personas podría ser algo frustrante. Para nosotros es un símbolo de humor, frustración y esfuerzo. El juego muestra cómo pequeños detalles pueden complicar incluso las metas más simples, y aun así seguimos intentando. Y eso no tiene nada de malo: frustrarse, ¿para qué?, si se puede pasar bien incluso en esas situaciones. No queremos confundir al usuario de manera errónea; solo buscamos generar un sentimiento ridículo, no tomarse las cosas tan personales cuando a veces simplemente buscamos pasar el tiempo y ver que no son tan trágicas como parecen. La forma en que entendemos este proyecto se basa en mirar el esfuerzo y el fracaso como algo ligero, exagerado y humorístico, donde la experiencia pertenece totalmente a quien la vive y no pretende ser más que eso un juego que hace visible lo absurdo.

Contexto de uso

 -Àtrápame Si puedes`es un juego interactivo, donde las personas deben tomar los mandos y ejercer una presión con los dedos para atrapar el hada. La única manera de terminar el juego, es que no pudiste atrapar el hada en el tiempo establecido y otra manera es hacer la acción de "atrapar" con el mando. Está pensado para espacios de exhibición de juegos experimentales, donde se juega con la tensión y paciencia del usuario

---

## Inputs y Outputs

`Inputs (entradas)`

- Inicio del usuario: Presionar para comenzar
- Selección: Elegir un personaje (hada) con el mando
- Interacción física: Aplicar presión en los sensores
- Movimiento: Activar el acelerómetro moviéndose
- Intento: Acción de atrapar durante el tiempo límite


`Outputs (salidas)`

- Pantalla inicial: Nombre del juego
- Pantalla de selección: Opciones de hadas
- Inicio del juego: Instrucciones y activación del tiempo
- Feedback del resultado:
- Si atrapa: mensaje de éxito
- Si no atrapa: mensaje de derrota

---

### Bill of materials

|Componenetes|Cantidad|Unidad|OBS|Valor|
|---|---|---|---|---|
|Sensor de fuerza|2|FSR402|Conexión a pin A0 / A1|$7.500|
|Sensor Acelerómetro|1|GY-291 ADXL345 - 3 ejes|Conexión SCL a A5 / Conexión SDA a A4|$3.800|
|Arduino Uno|1|R4 minima|Conexión directa a corriente|$24.990|
|Resistencias|2|120 Ohms|Conexión para sensores|estaban en el lab|
|Mini Protoboard|2|85 puntos|Conexión VCC GND directa al arduino|$1.990|
|Pantalla|1|14 pulgadas|Conexión a computador|$139.990|
|Carcasa|3|Filamento:PLA|Impresión 3D|Impresión en el Lab|
|Plinto|1|Filamento:PLA|Impresión 3D|Impresión en el Lab|
|Cables|20 aprox.|macho-macho|-|$1.000|

## Específicaciones de sensores

- 

---

## Planificación

Como grupo planificamos que haremos en cada semana del trabajo mediante una carta gantt, vimos el presupuesto de los materiales que necesitabamos (algunos ya estaban, pero decidimos dejarlos) y por último, hicimos un diagrama de flujo del proyecto en [mermaid](https://mermaid.js.org/)

### Carta Gantt

<img src="./imagenes/cartaGantt.png" alt="carta gantt" width="900">
<!-- ![carta gantt](./imagenes/cartaGantt.png)-->

### Presupuesto

<img src="./imagenes/presupuesto.png" alt="presupuesto" width="900">
<!-- ![Presupuesto](./imagenes/presupuesto.png)-->

### Diagrama de Flujo

```mermaid
---
config:
  layout: dagre
---
flowchart TB
    A(["Pantalla prendida con nombre del juego:
Atrápame si puedes"]) --> B["Presionar"]
    B --> C["La pantalla proyecta la selección de personaje (hada)"]
    C --> D["selección (Elegir con mando X  seleccionar mando Y)"]
    D --> E(["Inicio del juego:objetivo atrapar el hada para obtener una recompensa"])
    E --> F["Corre el tiempo límite 30 segundos"]
    F --> G["¿Lo atrapaste?"]
    G --> H["Si"] & I["No"]
    H --> J["Aparece en pantalla: ***Atrapaste 1 de 444 hadas***"]
    J --> K["Delay: 5 segundos"]
    K --> L["Aparecen volando las 444 hadas"]
    L --> M["Finaliza la interración con el acelerómetro"]
    I --> N["Aparece en pantalla: ***Oh No! el tiempo voló más rápido que tú***"]
    N --> O["Presiona para volver a intentar"]
    O --> P["Aparece la pantalla de juego"]
    P --> Q["¿Lo atrapaste?"]
    Q --> A
    M --> R["REINICIO ***Pantalla prendida con nombre del juego:
Atrápame si puedes***"]


    C@{ shape: rect}
    D@{ shape: diam}
     A:::Sunset
     B:::Lime
     C:::Sky
     D:::YellowSoft
     E:::Rose
     F:::Aqua
     G:::Sunset
     H:::Lime
     I:::Sky
     J:::Rose
     K:::Aqua
     L:::YellowSoft
     M:::Sunset
     N:::Lime
     O:::Sky
     P:::Sunset
     Q:::YellowSoft
     R:::Lime
    classDef Sunset stroke-width:1px, stroke-dasharray:none, stroke:#FF7A00, fill:#FFEBD6, color:#A94500
    classDef Sky stroke-width:1px, stroke-dasharray:none, stroke:#374D7C, fill:#E2EBFF, color:#374D7C
    classDef YellowSoft stroke-width:1px, stroke-dasharray:none, stroke:#E6C84C, fill:#FFF9D9, color:#7A6720
    classDef Rose stroke-width:1px, stroke-dasharray:none, stroke:#FF5978, fill:#FFDFE5, color:#8E2236
    classDef Lime stroke-width:1px, stroke-dasharray:none, stroke:#A8E400, fill:#F5FFD9, color:#5A7A00
    classDef Aqua stroke-width:1px, stroke-dasharray:none, stroke:#46EDC8, fill:#DEFFF8, color:#378E7A                        
```

LINK MERMAID (porque no se ve completo y no sabemos porqué): [MERMAID DIAGRAMA DE FLUJO](https://www.mermaidchart.com/play?utm_source=mermaid_live_editor&utm_medium=toggle#pako:eNqlVMluG0cQ_ZUKDQSyIAK0xE1zcDKcRaJEkVp8sGHm0Jopki3NdI97mrIVwx_jD8hJN18MhD-W6iZnIWMYUAJeWNt79aqq53MjkjE2nEaz2ZyKSIoZnztTAZCwR7nUDsRsrnAqbHiWyI_RgikNbwYmB8Ddez9tXDKhWZIwyBSKmMcMCAeETG8VQowJ3C1xLgnV1Wr1NWMpQs4hW2KM-bTxx0toNl_DwAApzLkUTJF3jT-wMY9iI4KveOQjRppRk5BjglHEV0-CqCBDlRPAHcLegsXsZQnkWSCfgGoFe0GCc65suykTsYS3UACaNjbOdxWMb2ECo3ooOGXV9MnbO9T8QQLTimVUTRHTBPWtGMhbjQIVLAUDhZFMMxQ5M_LXyIFFDgnYk4rmRsWaY5pJSFZ_pVwjHLWot_mSOsrLfkJbdUJVf38fFcy5xt_KjBObcUoZN5yc8CsM6f9YlgmnNuGMnC41ihFRi3LUDuzv77sFKrwyM26321ZXTqES5cyinBOKj3Q6DnT-3ey5zRlVTAIeZGJHnLC8wi0LRrbgggpCLljC_7Qb50KjUmy9QrM6GhWLaGtq9ZSiVpW0oa0f_0TaZAFj-Utt2NTQ6gnS1dcczK1y6u3DEkGvvtXVji3wpHay6yVT9QPteN0j0VSHPLEVl7VWktpB01TtDZXplzb96id7vbIZ7tq4sMY1pV8Hw_HQG06MuP_zLgu15mffz--fIV-wDB1zvfrL5jlU3pizdOMF13Gcm6XIUW8cA3KMeIob0zPx-8eN5ZP1DhP6ttzIWVERkPNa5kVFSKb7Yck25skuwek2wXCL4Gwb63wba_Qj-otdgvE2wWSL4HI3--pHmNdbEBGdfO7jDNaFkNPh3mPzI4_1wnmVfTooPPQg6JOr6E0JKbBwOy_CsOe2Wgcw40lirGDgdw9ow4lUzgv3uN1ptXaZ7h-fT3PUa_s9r6AJDoNBGJY06-AOTSX8-WxB1-u3vUpUeOwfl2w9t9s73BVlFvtfhtc57vUrHj8MOiVPPzg8POru8JjNPZ_H7Qft2pI6xFTp6bhmgzs85jKfz9PuBr5X6vEDmly_tqV-0HMbX_4B_NGFGQ)

---

### `PROPUESTA ELEGIDA`

- Máquina sentimental "Atrápame si puedes"

`PROPUESTA VISUAL`

- Para la gráfica decidimos usar pixel art. Utilizamos la aplicación web [Piskel](https://www.piskelapp.com/)
- Paleta de colores: tonos de celestes, verdes, azules, rosados, etcétera
- Tipografía: pixel-retro
- Máquina física: control retro hecho con impresión 3D
- Cursor: red atrapa hadas hecho con pixel art
- Hadas: inspiradas en los profes y ayudantes, hechos con pixel art

![Hadas](./imagenes/haditas.gif)

![choose aaron](./imagenes/chooseAaron.gif)

![choose misaa](./imagenes/chooseMisa.gif)

![choose mateo](./imagenes/chooseMateo.gif)

![choose janis](./imagenes/chooseJanis.gif)

|Hada|Volando|Estático|
|---|---|---|
|![aaron](./imagenes/aaron.png)|![aaron](./imagenes/aaronVolando.gif)|![aaron](./imagenes/aaronEstatico.gif)|
|![misa](./imagenes/misa.png)|![misa](./imagenes/misaVolando.gif)|![misa](./imagenes/misaEstatico.gif)|
|![mateo](./imagenes/mateo.png)|![mateo](./imagenes/mateoVolando.gif)|![mateo](./imagenes/mateoEstatico.gif)|
|![janis](./imagenes/janis.png)|![janis](./imagenes/janisVolando.gif)|![janis](./imagenes/janisEstatica.gif)|

|Paisaje|Inicio|
|---|---|
|![bosque1](./imagenes/bosque.gif)|![inicio](./imagenes/inicio1.gif)|
|![bosque2](./imagenes/bosque2.jpeg)|![inicio](./imagenes/inicio2.gif)|
|![bosque2](./imagenes/bosque3.gif)|![inicio](./imagenes/inicio3.gif)|
|![red 1](./imagenes/redAtrapaHadas.png)|![red 2](./imagenes/redAtrapaHadas2.png)|

## Procesos y bocetos

`Dificultades y desafíos`

-fhf

- Máquina sentimental "Atrápame si puedes"

`PROPUESTA VISUAL`

- Para la gráfica decidimos usar pixel art. Utilizamos la aplicación web [Piskel](https://www.piskelapp.com/)
- Paleta de colores: tonos de celestes, verdes, azules, rosados, etcétera
- Tipografía: pixel-retro
- Máquina física: control retro hecho con impresión 3D
- Cursor: red atrapa hadas hecho con pixel art
- Hadas: inspiradas en los profes y ayudantes, hechos con pixel



### Proceso y diseño de carcasa 


### Código y pseudocódigo

`PSEUDOCÓDIGO`

Comenzamos realizando un pseudocódigo para crear un puente entre la idea y el código real.

```cpp
INICIAR variables:
    estado = "espera"
    puntaje = 0
    objetivo = posición_inicial

MIENTRAS el sistema esté encendido:

    lee presión y los ejes x, y, z de los mandos en interacción

    SI estado == "espera" Y el usuario se acerca:
        mostrar_mensaje("atrapame si puedes")
        estado = "invitación"

    SI estado == "invitación" Y el usuario toma los mandos:
        calibrar_controles()
        estado = "jugando"

    SI estado == "jugando":
        mover_cursor_según_Fuerza()
        mover_para_atrapar_mover_rapidamente()

    SI el jugador atrapa el objetivo:
            SI aparece un mensaje de supuesto logro porque aún falta 443 más:
              Opciones: salir o reintentar()

    Si se acabo el tiempo se perdió
                Mostrar mensaje de juego perdido()
                Esperar inactividad por 10 seg.()
                Vuelve a la pantalla principal
```

- Luego hicimos el código real, donde separamos el archivo principal (.ino) en clases (.cpp / .h)

`ARCHIVO PRINCIPAL`

`.CPP`

`.H`

## Fotografías del proyecto terminado

## Roles de equipo

- Yamna Carrión: Aporte principal haciendo, revisando y probando código. Ayudó también a ordenar Github.
- Valentina Chavéz: Aporte principal haciendo, revisando y probando código.
- Antonia Fuentealba: Aporte principal en diseño de gráficas y gifs.
- Sofía Peréz: Aporte principal en diseño de gráficas y gifs.
- Millaray Millar: Aporte principal como diseñadora y reina del modelado de nuestro prototipo. 
- Valentina Ruz: Aporte principal haciendo, revisando y probando código. Ayudó también a ordenar Github.

## Bibliografía

- Afel. (2025). Sensor acelerómetro GY-291 ADXL345 — 3 ejes. <https://afel.cl/products/sensor-acelerometro-gy-291-adxl345-3-ejes?_pos=1&_sid=bb8703111&_ss=r>
- Afel. (s. f.). Sensor de fuerza / presión FSR402 [Producto]. <https://afel.cl/products/sensor-de-fuerza-presion-fsr402>
- Arduino.cl. (s. f.). Arduino UNO R4 Mínima. <https://arduino.cl/producto/arduino-uno-r4-minima/?srsltid=AfmBOoqBSLqpGT9CRKFQ4IaCLlnrIhTwcVLylGSazEoFdSGtGAhj6uXa>
- YouTube. (s. f.). Título del video [Video]. YouTube. <https://www.youtube.com/watch?v=E2_42DkFT4s>
- Pablo Eduardo J.C. (2025,08.06). Tutorial ADXL345 Sensor [Carpeta compartida]. Google Drive. <https://drive.google.com/drive/folders/1cRIQMYCmu9xg-Co9eqxS3qml1jfeBnEv>
- Pixilart Inc. (2025). Pixilart – free online drawing editor and social platform for everyone. <https://www.pixilart.com/>
- Gohai. (n.d.). p5.webserial.js: A library for p5.js which adds support for interacting with Serial devices, using the Web Serial API [Source code]. GitHub. <https://github.com/gohai/p5.webserial>
- p5.webserial.js. (n.d.). p5.webserial.js — A library for p5.js that adds support for interacting with Serial devices using the Web Serial API [Source code]. GitHub. <https://github.com/gohai/p5.webserial?tab=readme-ov-file#getting-started>
- Whimsical. (n.d.). Workspace board [Carpeta en línea]. <https://whimsical.com/Ca7qiC4VpqiA7dYewVCkAC>
- p5.js. (n.d.). p5.js – friendly tool for learning to code and make art. <https://p5js.org/>
- Epidemic Sound. (s. f.). Royalty-free music for video games [Página web]. Recuperado de <https://www.epidemicsound.com/game-development/music-for-video-games/>
- Ye Yuan, I. (2018, November 6). Tutorial: Serial communication with Arduino and p5.js [Blog post]. Medium. <https://medium.com/@yyyyyyyuan/tutorial-serial-communication-with-arduino-and-p5-js-cd39b3ac10ce>
- YouTube. (n.d.). Connecting p5 & Arduino through the serial port [Video]. YouTube. <https://www.youtube.com/watch?v=MtO1nDoM41Y>
- Ridler, A. (2019). Bloemenveiling [Trabajo artístico]. <https://annaridler.com/bloemenveiling>
- YouTube. (s. f.). [p5.js and Arduino serial communication - Send a digital sensor to a p5.js sketch] [Video]. YouTube. <https://www.youtube.com/watch?v=feL_-clJQMs>
`Referentes`
- Minecraft. (n.d.). Minecraft official site [Sitio web]. <https://www.minecraft.net/es-es>
- Inspiración en juegos 8-bits
  
