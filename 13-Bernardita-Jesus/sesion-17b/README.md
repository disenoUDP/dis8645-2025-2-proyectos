# Sesión-17b

## Examen

### Desarrollo de la carcasa

#### Referentes y definición formal

Primero levantamos referentes; teníamos claro que queríamos inspirarnos en la estética del Tamagotchi y más Game & Watch y Game Boy, mezclado con la lógica de un temporizador.

![fotos-referentes](https://github.com/user-attachments/assets/51f0a886-b769-408e-baa0-4fcd91c94465)
> foto de referentes

Pero necesitábamos que fuera un objeto que pudiera caerse, y de ahí nace esta forma medio absurda: un “huevo” frágil, inestable y de forma continua, diseñado para caer. El primer modelado fue la carcasa ovoide, con la base levemente aplanada para darle un punto de apoyo.

<img width="1253" height="299" alt="Captura de pantalla 2025-12-07 142648" src="https://github.com/user-attachments/assets/ba706ad7-1876-4db0-bc32-b8e9c34dd4ba" />

> foto de modelaod de huevo

#### Mecánica y estructura general

Luego desarrollamos el sistema mecánico para las primeras pruebas: un soporte para el motor y un módulo de contrapeso que extiende la masa hacia un costado, generando el desequilibrio característico.

adjuntar el video del mecanismo*

Después subdividimos el cuerpo en tres secciones principales, las cuales son encajables, para poder abrir la pieza y acceder a los circuitos de este “temporizador inconveniente”.

Continuamos con el diseño de los calces internos para la pantalla sin afectar la forma continua.

<img width="1202" height="749" alt="Captura de pantalla 2025-12-07 142400" src="https://github.com/user-attachments/assets/4af1e046-506b-4e57-a785-6e9c3667d755" />

<img width="1107" height="733" alt="Captura de pantalla 2025-12-07 142925" src="https://github.com/user-attachments/assets/68d2e721-2656-4437-bb45-c5fe14e1fbf4" />
> foto de las tres secciones al lado de la pantalla.

#### Integración electrónica y ajustes volumétricos

Optamos por integrar una power bank dentro de la carcasa para evitar cables externos, lo que nos obligó a reescalar el modelo varias veces para que todo cupiera bien.

Además diseñamos un sistema de plataforma para encajar el Arduino con la power bank, el sensor y la protoboard.

<img width="1524" height="491" alt="modelado-escalado" src="https://github.com/user-attachments/assets/1c56afb0-d9aa-4f1b-8e5d-b390d497b794" />
> foto de escalar
 
insertar foto de la plataforma*

Finalmente incorporamos el speaker en la parte superior y el botón en la parte frontal.

> opinion (Para mí fue todo un reto esta carcasa, ya que nunca había trabajado una forma ovoide, lo que hizo que los encajes fueran mucho más complejos. Mover los objetos y centrar cada componente se volvió un desafío, pero estoy muy feliz con el resultado.)

insertar foto del modelado final*

#### Capa externa de alginato

Como parte final del proyecto quisimos agregar una cobertura externa de alginato para amortiguar un poco el golpe y darle más dinamismo. Para esto realizamos un modelado exterior e interior, y a presión se fue incorporando el alginato.

insertar foto de los moldes con el algintano*

agregar a referentes: game boy, mgame and watch, tamagochi, video de modelado huevo, 

https://es.wikipedia.org/wiki/Game_Boy

https://es.wikipedia.org/wiki/Game_%26_Watch

https://es.wikipedia.org/wiki/Tamagotchi
