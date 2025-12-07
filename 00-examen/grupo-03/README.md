# grupo-03

## GEE: Grupo Emocionalmente Estable - Integrantes

- [Aileen D’Espessailles Rojas](https://github.com/aileendespessailles-design)
- [Santiago Gaete Fernández](https://github.com/santiagoClifford)
- [José Morales Berríos](https://github.com/jotamorales-romulus)
- [Carla Pino Barrios](https://github.com/Coff4)
- [Francisco Stephens González](https://github.com/FranUDP)
  
---

### Presentación textual

Jorgito es un muñeco con forma de mono que pide un abrazo. Al inicio se muestra amistoso, casi tierno. Pero una vez que el usuario lo toma, se aferra con fuerza y no se suelta. Su abrazo cálido en apariencia, rígido en su estructura revela un apego ansioso que se intensifica con cada interacción.

Cuando se le deja sobre la mesa, Jorgito llora, suplica y llega a amenazar con hacerse daño, obligando al usuario a retomar el contacto. Se establece un ciclo incómodo del que no es fácil salir. La relación deja de ser afectiva para transformarse en una dependencia emocional opresiva.

Su comportamiento contrapone sensaciones: suavidad y dureza, ternura y angustia, contención y presión. Esa fricción define la experiencia y expone cómo un gesto afectivo puede derivar en un vínculo tenso y desgastante.

---

### ¿Qué es un abrazo? 

Un abrazo parece un gesto simple, pero contiene una carga emocional profunda. No se trata solo de unir dos cuerpos: implica contención, cuidado, comunicación silenciosa y una forma de empatía física.
Tomamos el abrazo como base del proyecto para explorar cómo esta acción cotidiana puede transformarse cuando deja el cuerpo humano y pasa a una entidad no viva.

Desde esta idea surge Jorgito, un muñeco con forma de primate diseñado para abrazar… pero también para exigir ese abrazo. A través de él indagamos qué ocurre cuando un gesto afectivo se vuelve dependiente, invasivo o contradictorio.

Con este proyecto buscamos evidenciar qué ocurre cuando un gesto afectivo pierde equilibrio y deja de ser voluntario. Nos interesa que el usuario experimente la incomodidad de un cariño que se vuelve exigencia, mostrando cómo un vínculo puede transformarse en dependencia cuando una de las partes no puede regularlo.

--- 

### ¿Por qué Jorgito es un mono? — Primates, maternidad y contacto

La elección de un primate se debe a que su biología emocional se sostiene radicalmente en el contacto físico, especialmente entre madre y cría. En estos animales, el abrazo no es simbólico: es una necesidad vital ligada a la regulación del estrés, la seguridad y la formación del apego.

Cuando ese vínculo se interrumpe, muchos primates desarrollan ansiedad, apego excesivo o dependencia. Esa fragilidad inspiró el comportamiento de Jorgito: un muñeco que vive la separación como abandono y reacciona buscando desesperadamente recuperar el contacto.

También lo diseñamos con una apariencia tierna, para invitar naturalmente al gesto de acariciarlo o abrazarlo. Ese contraste hace que el usuario se acerque sin sospecha, y que el vínculo se active a través del contacto de sus propios brazos.

La elección del mono, entonces, no es estética sino conceptual: permite trasladar al objeto un modo de apego intenso y vulnerable, amplificando la tensión entre cuidado, dependencia y control.

[![Referente bebé gibón](https://img.youtube.com/vi/wLni152HI04/maxresdefault.jpg)](https://www.youtube.com/watch?v=wLni152HI04&t=237s)

---

### La Dualidad del Cariño

En lo cotidiano solemos buscar en los animales una fuente constante de afecto, pero ese cariño, cuando no tiene límites, puede convertirse en una carga. Esa tensión entre cuidado y agobio guía el proyecto. En Jorgito conviven sensaciones opuestas: su abrazo consuela pero incomoda, pide cercanía pero teme perderla. Esa contradicción define la experiencia y vuelve el vínculo inestable. Lo que inicia como un gesto tierno termina mostrando cómo el afecto puede transformarse en dependencia y desgaste emocional.

![Tensión emocional](./imagenes/jorgito-llorando.jpg)

---

### Contexto de uso

Esta maquina esta pensada para generar incomodidad en el usuario a traves de estimulos programados para exponer una problematica.

---

### Bill of Materials
| Componente          | Cantidad | Valores    | Links                                                                                                                  | Valor   |
|---------------------|----------|------------|-------------------------------------------------------------------------------------------------------------------------|---------|
| Parlante            | 1        | 3w         | <https://afel.cl/products/mini-parlante-altavoz-de-3w?_pos=1&_sid=2792063ab&_ss=r>                                     | $3.000  |
| Servo motor         | 3        | SG90       | <https://afel.cl/products/micro-servomotor-sg90?_pos=2&_sid=fe0b59026&_ss=r>                                           | $1.900  |
| Sensor ultrasónico  | 1        | 5V         | <https://afel.cl/products/sensor-de-ultrasonico-hc-sr04>                                                               | $1.500  |
| Módulo MP3          | 1        | 3.2 a 5V   | <https://afel.cl/products/modulo-reproductor-mp3-dfplayer-mini?_pos=1&_sid=c29ea442a&_ss=r>                           | $2.990  |
| Sensor de presión   | 1        | FSR402     | <https://afel.cl/products/sensor-de-fuerza-presion-fsr402?_pos=1&_sid=3e7f88f5f&_ss=r>                                 | $7.500  |
| Motor DC            | 1        | 5V         | <https://afel.cl/products/3v-0-2a-12000rpm-65gcm-mini-micro-dc-motor-for>                                              | $500    |
| Mosfet              | 1        | BS170      | <https://a.aliexpress.com/_mt52yRB>                                                                                    | $694    |
| Chips L293D         | 1        | 4.5V a 7V  | <https://afel.cl/products/chips-l293d-driver-motor-puente-h?srsltid=AfmBOopdSCMb-AMaT28x0tp5BXOpQuGbm55ZteJTH9JsrzJ8gspTNZpy> | $1.000  |
| Arduino Nano        | 1        | 5V         | <https://arduino.cl/arduino-nano/?srsltid=AfmBOorHZo7Nva6AUTWR6cWlQYivHoumROEyDap5uDlN5kRZbERvFyOl>                    | $3.500  |

--- 

### Mapa de flujo

```mermaid
flowchart TB
    A["stand BY"] --> B["usuarie detectade"]
    B --> C["jorgito pide amor"]
    C -- usuarie abraza --> F(["jorgito feliz"])
    F --> K(["abraza devuelta"])
    K --> L(["abraza fuerte devuelta y no suelta"])
    L --> C
    C -- usuarie NO abraza --> G(["jorgito triste"])
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

---


### Inputs y outputs



Inputs y outputs


--- 

### Código


---

### Bocetos

![bocetos de jorge](./imagen/Ilustracion.jpg)



---

### Prototipado

Para el prototipo realizamos el prototipado de la columna y los brazos, probando cómo podrían moverse y sostenerse. También hicimos pruebas de impresión 3D para revisar las piezas y sus uniones. Además, armamos un primer prototipo del sistema de la espalda y los brazos para evaluar su funcionamiento general. Finalmente, realizamos el molde para la tela del forro, aplicando cinta sobre la forma para obtener las piezas base del patrón.


![foto de la vértebra](./imagen/vertebra.png)

![gif de la probeta 1](./imagen/vertebra-probeta1.gif) ![gif probeta 1 otra prueba](./imagen/vertebra-probeta1b.gif)

![vértebra v2](./imagen/vertebra-v2.png)

![probeta de la vertebra-v2](./imagen/vertebra-v2-ver.gif)

![brazos](./imagen/piezasbrazo.png)

![funcionamiento brazo](./imagen/mecanismobrazo.gif)

![molde](./imagen/patronaje.png)

![patronaje](./imagen/patrones.png)

![patronaje](./imagen/patrones.png)

![patronaje](./imagenes/jorge.jpg)

--- 



---

### Bibliografía 
