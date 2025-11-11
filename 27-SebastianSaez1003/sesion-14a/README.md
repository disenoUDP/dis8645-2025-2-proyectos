# sesion-14a

Hoy llegue a corregir un poco el diagrama de flujo ya que realmente estaba suuuuuuper enredado, le pedí ayuda a Mateo y Misaa, de cómo podría crear esta acción constante, donde la máquina cada 30 segundos empezará a “girar”.

Aqui esta la 1ra version hecha en Mermaid, que también tiene errores ortograficos:

![Corrección de diagrama de flujo](./imagenes/diagramaDeFlujo1.png)


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
