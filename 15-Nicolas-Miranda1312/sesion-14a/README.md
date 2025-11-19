# sesion-14a

-12-11-2025

## Avance proyecto 03

Game Over es una experiencia interactiva que explora la frustración y la imposibilidad de controlar lo imperfecto. El juego parece invitar a reparar una figura simple, pero rápidamente demuestra que cada intento de arreglarla solo la desordena más.

El dispositivo utiliza una matriz de 8×8 píxeles, un joystick y cinco botones. La pantalla LCD muestra “Acércate y juega”, mientras que la matriz neopixel presenta un cuadrado perfectamente formado. Al iniciar el juego, un píxel se desplaza y la figura pierde su estabilidad. Desde ahí, cada acción del usuario que busca corregir el error genera nuevas distorsiones.

Lo interesante es que, cuando el jugador deja de intervenir, la figura vuelve lentamente a su estado perfecto. Esta dinámica refuerza la metáfora del proyecto: cuanto más intentamos controlar y corregir, más se desordena todo; pero al soltar y dejar de forzar la perfección, el equilibrio reaparece por sí solo.

---

### Bocetos 

**Descripción de actuadores**

![Boceto](./imagenes/definicion.jpg)

**Idea de figura en matriz LED 8x8**

![pixel](./imagenes/pixel.jpg)

---

#### Diagrama de Flujo — Proyecto Game Over

Este diagrama representa el comportamiento completo del sistema interactivo:  
pantalla LCD, pantalla neopixel, joystick, botones y estados.

---

```mermaid
---
config:
  theme: default
  look: classic
  layout: fixed
---

flowchart TB

%% --- INICIO ---
    A(["Pantalla LCD"]) --> n2["Mensaje inicial:<br>“Interactúa para comenzar”"]
    n2 --> n3["Botón de inicio"]

%% --- APARICIÓN DE LA FIGURA ---
    n3 --> n4(["Pantalla Neopixel"])
    n4 --> n5["Aparece un cuadrado perfecto"]
    n5 --> n6["Un píxel se escapa del cuadrado"]
    n6 --> n17["Opciones de interacción"]

%% --- INTERACCIONES ---
    n17 --> Njoystick["Joystick"]
    n17 --> Nbotones["4 Botones"]

%% --- JOYSTICK ---
    Njoystick --> j1["Arriba = abajo"]
    Njoystick --> j2["Abajo = arriba"]
    Njoystick --> j3["Derecha = izquierda"]
    Njoystick --> j4["Izquierda = derecha"]
    Njoystick --> j5["Botón del joystick = desarma toda la figura"]
    Njoystick --> n35

%% --- BOTONES ---
    Nbotones --> b1["Botón 1: inútil (no hace nada)"]
    Nbotones --> b2["Botón 2: cambia colores"]
    Nbotones --> b3["Botón 3: hace escapar más píxeles"]
    Nbotones --> b4["Botón 4: activa música"]
    Nbotones --> n35

%% --- COLOR ---
    b2 --> n29["Puede usarse 5 veces"]
    n29 --> n30["Al 6° uso: se reinicia y aparece otra figura"]

%% --- MÚSICA ---
    b4 --> n34["Cada clic sube la velocidad del audio<br>(máximo 3 niveles)"]

%% --- AFK / MORAL ---
    n35["1 minuto sin interacción:<br>la figura vuelve a ser un cuadrado perfecto"]
    n35 --> n41["Moraleja:<br>‘A veces intentar arreglarlo todo solo lo empeora.’"]

%% --- ESTILOS ---
    A:::Ash
    n2:::Rose
    n4:::Ash
    n5:::Rose
    Njoystick:::Ash
    Nbotones:::Ash
    n35:::Rose
    n41:::Aqua

    classDef Sky stroke-width:1px, stroke:#374D7C, fill:#E2EBFF, color:#374D7C
    classDef Rose stroke-width:1px, stroke:#FF5978, fill:#FFDFE5, color:#8E2236
    classDef Ash stroke-width:1px, stroke:#999999, fill:#EEEEEE, color:#000000
    classDef Aqua stroke-width:1px, stroke:#46EDC8, fill:#DEFFF8, color:#378E7A

    style n41 stroke:#BBDEFB
