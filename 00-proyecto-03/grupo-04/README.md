# grupo-04 - Cachureos

INTEGRANTES
- Yamna Carrión / [yamna-bit](https://github.com/yamna-bit)
- Valentina Chávez / [valechavezalb](https://github.com/valechavezalb)
- Antonia Fuentealba / [AntFuentealba](https://github.com/AntFuentealba)
- Millaray Millar / [mmillar95](https://github.com/mmillar95)
- Sofía Pérez / [sofia-perezm](https://github.com/sofia-perezm)
- Valentina Ruz / [vxlentiinaa](https://github.com/vxlentiinaa)

---

## Presentación Textual

## Metáfora

## Inputs y Outputs

---

## Planificación

Como grupo planificamos que haremos en cada semana del trabajo mediante una carta gantt, vimos el presupuesto de los materiales que necesitabamos (algunos ya estaban, pero decidimos dejarlos) y por último, hicimos un diagrama de flujo del proyecto en [mermaid](https://mermaid.js.org/)

### Carta Gantt

### Diagrama de Flujo

```mermaid
flowchart TB
    n1["Pantalla prendida con algún texto (presionar para empezar)"] --> n2["Título: *Atrápame si puedes* y personajes en la parte de abajo"]
    n2 --> n3["Empieza el juego y aparecen los personajes"]
    n3 --> n4["seleccionar el personaje (instrucción de controles o personaje en aleatorio)"]
    n4 --> n12["en un tiempo de 1 min 30s se debe atrapar el personaje 3 veces"]
    n12 --> n14["lo atrapaste?"]
    n14 --> n15["si"] & n16["no"]
    n15 --> n17["ganaste"]
    n16 --> n18["perdiste"]
    n17 --> n19@{ label: "<span style=\"color:\">Vuelve al inicio (*presiona para comenzar*)</span>" }
    n18 --> n19

    n19@{ shape: rect}
     n1:::Rose
     n2:::Aqua
     n3:::Lime
     n4:::Sunset
     n12:::Rose
     n14:::Lime
     n15:::YellowSoft
     n16:::Rose
     n17:::Lime
     n18:::Lavender
     n19:::Aqua
    classDef Sunset stroke-width:1px, stroke-dasharray:none, stroke:#FF7A00, fill:#FFEBD6, color:#A94500
    classDef Rose stroke-width:1px, stroke-dasharray:none, stroke:#FF5978, fill:#FFDFE5, color:#8E2236
    classDef Aqua stroke-width:1px, stroke-dasharray:none, stroke:#46EDC8, fill:#DEFFF8, color:#378E7A
    classDef Sky stroke-width:1px, stroke-dasharray:none, stroke:#374D7C, fill:#E2EBFF, color:#374D7C
    classDef Lime stroke-width:1px, stroke-dasharray:none, stroke:#A8E400, fill:#F5FFD9, color:#5A7A00
    classDef YellowSoft stroke-width:1px, stroke-dasharray:none, stroke:#E6C84C, fill:#FFF8D9, color:#7A6720
    classDef Lavender stroke-width:1px, stroke-dasharray:none, stroke:#7C5CFF, fill:#EFEAFF, color:#3D2D7A
```

### Presupuesto

![Presupuesto](./imagenes/presupuesto.png)

---

## Proceso y bocetos

- Primero, teníamos esta idea de máquina sentimental, donde decidimos como grupo cambiar la propuesta ya que no nos llamaba la atención y no estabamos satisfechas con el proyecto
  - El proyecto consiste en un objeto inerte que responde al contacto directo mediante las manos, dependiendo de la intensidad de fuerza, la acción con la cual se manipule el objeto, como respuesta de este tacto, en la pantalla que esta en frente de la persona, la grafica que se proyecta (describir la gráfica) cambia justo con sonidos (describir sonidos), los cuales en conjunto generan un momento en el cual el usuario queda inmerso en el proyecto por un momento (definir cuanto tiempo).

### Ideas nuevas para proyecto

- Segundo, trabajamos el fin de semana para llegar con nuevas propuestas el día domingo 16 y definir con cual nos quedaremos.

`PROPUESTAS:`

- **Marea:** es una máquina sentimental creada para ir en contra del ritmo con el que el mundo insiste en arrastrarnos. Vivimos dentro de un movimiento constante: ruido, velocidad, exigencias que no dan espacio para sentir nada con honestidad. Esta máquina nace justamente para suspender ese flujo, para ofrecer un minuto seguro donde la persona pueda bajar la intensidad, respirar y encontrarse consigo misma sin presión.
- **La** **Máquina** **que** **Se** **Ofende** **Fácilmente:** una máquina cuyo “carácter” es extremadamente sensible. Si te acercas demasiado o la tocas con brusquedad, se “ofende”, apaga sus luces y muestra mensajes pasivo-agresivos del estilo “Ah, ok… veo que no te importo”.
  - Lejos: te “mira” con curiosidad (luces suaves, postura tranquila).
  - Normal: si te acercas con calma, la máquina se anima (cambia color, vibra levemente).
  - Ofendida: si detecta un movimiento brusco o toque fuerte, se cierra emocionalmente (luces apagadas, pantalla mostrando mensajes dramáticos). Luego de unos segundos, vuelve lentamente a su estado normal.
- **La** **Máquina** **sentimental** **que** **no** **quiere** **jugar** **contigo:** es un personaje que invita entusiastamente a jugar, pero cuando tomas su “control” activa un error intencional y se retracta. Utiliza un sensor ultrasónico para detectar cercanía y un sensor FSR en el control para identificar cuándo alguien lo toma y así gatillar la broma. Cuando la persona se aleja, el personaje vuelve a su actitud amistosa y reinicia el ciclo.

`PROPUESTA ELEGIDA`

"BOCETOS FÍSICOS" ✅

---

## Etapas del código

## Etapas de prototipo

## Fotografías del proyecto terminado

## Roles de equipo

## Bibliografía
