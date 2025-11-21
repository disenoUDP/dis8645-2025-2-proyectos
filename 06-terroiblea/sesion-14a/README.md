# sesion-14a

Martes 11 de Noviembre, 2025 

Nota del día: 

## Qué hice hoy 

Anotación sobre la entrega del 21/11:

- La entrega formal de ese día es un prototipo, que funcione a nivel "básico" (más que básico no es necesario que, por ejemplo, esté la carcasa, sino más bien es importante esta entrega para defender la idea y ver cómo vamos avanzando; por lo tanto, interacción y el relato son los aspectos importantes para la evaluación, que sea coherente, no preocuparse tanto de la carcasa por ahora); para el examen, bajarlo y maquillarlo para que quede lindo y funcional (ahí si debe estar completo).

Interacción y el relato, que sea coherente; no preocuparse tanto de la carcasa por ahora. 

Nota general del día: La verdad hoy como grupo no pudimos avanzar mucho en temas de códigos o aspectos parecidos ya que no contamos todavía con los componentes que vamos a utilizar. De todas formas, la clase nos sirvió para especificar más el funcionamiento de la máquina, qué es lo que queremos lograr y ver que aspectos realmente nos sirven y cuáles no son tan necesarios de utilizar. 

### Explicación del proyecto: 

Game over es una experiencia interactiva que explora la frustración y la imposibilidad de alcanzar la perfección. Cada intento por “arreglarla” solo genera más caos - No está hecha para ganar.

Está compuesta por una pantalla de 8x8 píxeles, una pantalla LDC, un joystick, 5 botones + 1 reproductor mp3.

Componentes generales:

- **Pantalla LCD:** Al principio muestra un mensaje como "Acércate y juega". Es lo que invita a la persona a interactuar con la máquina. 
- **Pantalla LED 8x8 pixeles:** Al principio muestra una figura perfectamente formada: Un cuadrado. Al apretar el botón de inicio un píxel se mueve, y la figura deja de ser perfecta. La idea general del juego es volver a posicionar el píxel que se movió en el espacio que iba (aunque la máquina nunca lo permitirá). 
- **Reproductor mp3:** Reproduce música tipica de juegos arcade para darle más ambientación mientras la persona juega. 

Controles:

- **Joystick:** Mueve el píxel corrido, pero en dirección contraria a la que intentas. (ariba es abajo, izquierda es derecha, etc)
- **Botón del joystick:** Desarma todo, se reparten los pixeles por toda la pantalla (se vuelve loquito durante unos segundos y después vuelve a la normalidad).
- **Botón de inicio:** Le da inicio al juego moviendo un pixel de su lugar cuando la figura está perfecta.
- **Botón 1:** Inútil, no hace nada (distracción).
- **Botón 2:** Cambia el color del LED que no está en su lugar hasta 5 veces, a la 6ta vez la pantalla se invierten los colores (la figura queda sin color y el fondo con color)
- **Botón 3:** Música, cada click aumenta la velocidad del audio (hasta 3 veces).
- **Botón 4:** Desplaza 2 pixeles de su lugar a uno aleatorio.

Los botones (del 1 al 4) no tienen especificaciones; por lo tanto, cada uno será una sorpresa para la persona que interactúe con ellos. 

Concepto: 

La máquina es una experiencia interactiva que explora la frustración y la imposibilidad de alcanzar la perfección. Cada intento por “arreglarla” solo genera más caos. La enseñanza es que haciendo nada las cosas se solucionan; ya que cuando uno deja de apretar los botones y el joystick (es decir deja de interactuar con la máquina - deja de arruinar más el problema, generar más caos) por 30 segundos volverá a reproducirse la figura perfecta.  

### Diagrama

```mermaid
---
config:
  theme: default
  look: classic
  layout: fixed
---
flowchart TB
    A(["pantalla LCD"]) --> n2["Llama al usuario a interactuar mediante un mensaje"]
    n2 --> n3["apretar botón de inicio"]
    n4(["pantalla neopixel"]) --> n5["se muestra cuadrado perfecto"]
    n3 --> n6["un pixel se de la figura perfecta de mueve"]
    n6 --> n17["posibles interacciones:"]
    n17 --> n18(["joystick"]) & n19(["4 botones:"])
    n19 --> n20>"inútil (no hace nada)"] & n21>"cambio color"] & n22>"corre más pixeles"] & n23>"música"] & n35["si no hay interacción por 1 min. vuelve a su estado inicial (cuadrado perfecto)"]
    n18 --> n24>"arriba= abajo"] & n25>"abajo=arriba"] & n26>"derecha=izquierda"] & n27>"izquierda=derecha"] & n28>"botón= desarma todo"] & n35
    n21 --> n29["hasta 5 veces"]
    n29 --> n30["a la n° 6 reset y te muestra otra fig."]
    n23 --> n34["cada click aumenta la velocidad del audio (hasta 3 niveles)"]
    n36[" "] --> n37[" "]
    n39[" "] --> n40[" "]
    n35 --> n41["La moraleja es: que algunas veces tratar hacer todo no soluciona nada."]
    n35@{ shape: rect}
    n36@{ shape: anchor}
    n37@{ shape: anchor}
    n39@{ shape: anchor}
    n40@{ shape: anchor}
    n41@{ shape: dbl-circ}
     A:::Ash
     n2:::Rose
     n4:::Ash
     n5:::Rose
     n18:::Ash
     n19:::Ash
     n35:::Rose
     n41:::Aqua
    classDef Sky stroke-width:1px, stroke-dasharray:none, stroke:#374D7C, fill:#E2EBFF, color:#374D7C
    classDef Rose stroke-width:1px, stroke-dasharray:none, stroke:#FF5978, fill:#FFDFE5, color:#8E2236
    classDef Ash stroke-width:1px, stroke-dasharray:none, stroke:#999999, fill:#EEEEEE, color:#000000
    classDef Aqua stroke-width:1px, stroke-dasharray:none, stroke:#46EDC8, fill:#DEFFF8, color:#378E7A
    style n41 stroke:#BBDEFB
```

### Bosquejos y referentes de forma 

![Boceto](./imagenes/Boceto02.jpg)
![Boceto](./imagenes/Boceto03.jpg)
![Boceto](./imagenes/Boceto01.jpg)
![Boceto](./imagenes/Boceto04.jpg)
![arcade](./imagenes/arcade.png)

