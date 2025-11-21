# sesion-14b

## Máquinas Computacionales: 14/11

Nota de clase: Empezamos en la busqueda de materialidad utilización de los sensores de fuerza y desarrollo de la propuesta

## Trabajo en clase

Durante el inicio de la clase estuvimos revisando qué dirección tomar con el proyecto. Cada una estaba mirando opciones de gráficas, posibles modos de uso del sensor y escribiendo versiones textuales para definir mejor la propuesta. Queríamos que fuera una experiencia inmersiva basada en el tacto, específicamente mediante sensores de fuerza. Pero para eso necesitábamos dejar claro el medio, el por qué, el para qué y el contexto de uso. La verdad es que estábamos un poco perdidas.

La semana pasada habíamos comprado hilo conductor, pero resultó ser inútil porque no entregaba ninguna señal. La Vale había traído unas lanas tejidas para probar variaciones, pero sin funcionamiento del hilo conductor no servía de base para nada. Esto nos frustró bastante, así que decidimos preguntarle a Aarón. Él nos dijo que debíamos especificar mucho más el proyecto, trabajar el contexto, el modo de uso y escribir todo de forma más explícita y detallada. Eso nos llevó a reescribir casi todo lo que llevábamos.

Mientras tanto, las chicas estaban probando las gráficas en TouchDesigner, aunque creo que todas estábamos pasando por un proceso extraño con el proyecto, como si nada terminara de calzar. Terminamos la clase con una sensación rara: aunque habíamos bajado la idea a un nivel más específico, no nos terminaba de convencer.

Después, conversé con la Vale y hablamos con las chicas para saber cómo se sentían. Era arriesgado plantear la posibilidad de cambiar el proyecto, pero lo conversamos con más personas y, tomando los mismos sensores y dándoles otra intención, empezamos a sentir un poco más de claridad. Aun así, decidimos que lo mejor sería que cada una volviera a subir sus ideas desde cero para elegir una que realmente nos convenciera como grupo.

## Trabajo fin de semana

El viernes llegamos, conversamos un rato y nos dimos cuenta de que todas compartíamos la misma sensación: estábamos forzando demasiado la propuesta. Así que decidimos volver al inicio y replantear lo que realmente queríamos hacer. Mientras dábamos vueltas a distintas ideas, acordamos que lo mejor era que cada una llegara al día siguiente sábado con propuestas más claras para poder compararlas.

El sábado tuvimos la reunión y cada una presentó su idea. Finalmente, la que más sentido nos hizo fue desarrollar un juego basado en gráficas, utilizando un sensor de gestualidad, enfocado en generar un sentimiento de frustración, como intentar atrapar algo que nunca se deja atrapar. Nos quedamos con esa propuesta.

Al día siguiente la escribimos de forma textual y comenzamos a desarrollarla. Redactamos la metáfora del proyecto, armamos el diagrama de flujo y dejamos todo listo para juntarnos el lunes y avanzar ya de manera más direccionada en esta idea.

## Ideas vistas 

1. Máquina sentimental que no quiere jugar contigo 

Es una máquina que invita al usuario a jugar, pero justo cuando este intenta participar, el sistema provoca un “error” intencional. Usa un sensor ultrasónico para detectar la distancia y mostrarse entusiasta cuando la persona está lejos, y un sensor de fuerza que activa el fallo justo al tomar el control. Esta interacción genera una frustración cómica: la máquina finge querer jugar, pero siempre se escapa.

2. Máquina Atrápame si puedes

El dispositivo crea un juego donde el usuario intenta atrapar un objeto en pantalla usando gestos detectados por el sensor PAJ7620. Cuando está a punto de lograrlo, la máquina provoca un glitch y reinicia, generando una sensación de pérdida artificial y reconocible. El sistema alterna entre estados de invitación, competencia y error, construyendo una experiencia donde el usuario quiere “hacerlo bien” pero la máquina sabotea el momento justo antes de ganar.

3. La Máquina que Se Ofende Fácilmente

Esta máquina tiene un carácter exageradamente sensible cuando la persona se acerca con calma, responde con luces suaves, pero si detecta brusquedad o un toque fuerte, se “ofende”, apaga sus luces y muestra mensajes pasivo-agresivos. Utiliza sensores de distancia, vibración y toque suave para modular sus estados emocionales, creando una interacción absurda donde el usuario siente una mezcla de incomodidad, culpa ligera y humor social.

4. Marea Máquina sentimental de pausa y calma

Marea es una máquina diseñada para suspender el ritmo acelerado del entorno y ofrecer un instante de reposo emocional. En reposo permanece en un azul profundo, esperando sin exigir interacción; cuando la persona mueve la mano sobre ella, un sensor gestual despierta ondas lentas y sensibles que responden al movimiento. La máquina acompaña al usuario durante unos segundos de calma y vuelve a su estado inicial cuando la mano se retira, como una marea que se repliega suavemente.

5. Ecosistema Aéreo  Máquina que se activa al “tocar el aire”

Este proyecto transforma el movimiento de las manos en visuales y sonidos sin necesidad de contacto físico. Sensores de proximidad tipo theremin miden distancia, velocidad y dirección, enviando los datos a TouchDesigner para generar gráficas fluidas, colores reactivos y capas sonoras envolventes. La experiencia guía al usuario desde la curiosidad inicial hasta un estado contemplativo, creando la sensación de que el aire mismo es un medio sensible que responde a cada gesto.


## Proyecto 03

Es una máquina interactiva que se controla con gestos de la mano. El usuario mueve su mano frente a un sensor, y ese movimiento controla un punto en la pantalla. El objetivo parece sencillo: mover ese punto y atrapar un objeto que aparece frente a ti.

Pero la máquina está programada para escaparse justo cuando estás por ganar. Cuando detecta que estás demasiado cerca, activa un “glitch”, mueve el objetivo rápidamente y te deja con las ganas. Lo hace una y otra vez, de una forma que parece casi personal, como si te estuviera leyendo y respondiendo a tu intención.
