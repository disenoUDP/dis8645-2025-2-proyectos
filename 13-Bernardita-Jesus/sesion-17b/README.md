# Sesión-17b

## Examen

### Desarrollo de la carcasa

#### Referentes y definición formal

Primero levantamos referentes; teníamos claro que queríamos inspirarnos en la estética del Tamagotchi y más Game & Watch y Game Boy, mezclado con la lógica de un temporizador.

insertar foto de referentes*

Pero necesitábamos que fuera un objeto que pudiera caerse, y de ahí nace esta forma medio absurda: un “huevo” frágil, inestable y de forma continua, diseñado para caer. El primer modelado fue la carcasa ovoide, con la base levemente aplanada para darle un punto de apoyo.

insertar foto de modelaod de huevo*

#### Mecánica y estructura general

Luego desarrollamos el sistema mecánico para las primeras pruebas: un soporte para el motor y un módulo de contrapeso que extiende la masa hacia un costado, generando el desequilibrio característico.

adjuntar el video del mecanismo*

Después subdividimos el cuerpo en tres secciones principales, las cuales son encajables, para poder abrir la pieza y acceder a los circuitos de este “temporizador inconveniente”.

Continuamos con el diseño de los calces internos para la pantalla sin afectar la forma continua.

Adjuntar foto de las tres secciones al lado de la pantalla.

#### Integración electrónica y ajustes volumétricos

Optamos por integrar una power bank dentro de la carcasa para evitar cables externos, lo que nos obligó a reescalar el modelo varias veces para que todo cupiera bien.

Además diseñamos un sistema de plataforma para encajar el Arduino con la power bank, el sensor y la protoboard.

insertar foto de la plataforma*

Finalmente incorporamos el speaker en la parte superior y el botón en la parte frontal.

> opinion (Para mí fue todo un reto esta carcasa, ya que nunca había trabajado una forma ovoide, lo que hizo que los encajes fueran mucho más complejos. Mover los objetos y centrar cada componente se volvió un desafío, pero estoy muy feliz con el resultado.)

insertar foto del modelado final*

#### Capa externa de alginato

Como parte final del proyecto quisimos agregar una cobertura externa de alginato para amortiguar un poco el golpe y darle más dinamismo. Para esto realizamos un modelado exterior e interior, y a presión se fue incorporando el alginato.

insertar foto de los moldes con el algintano*

agregar a referentes: game boy, mgame and watch, tamagochi, video de modelado huevo, 
