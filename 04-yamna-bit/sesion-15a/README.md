# sesion-15a

## Máquinas Computacionales:18/11

Nota de clase: Llegué tarde porque tuve que pedir un Uber lo peor fue no me lo quería tomar :c. Venía cargando mi examen de cerámica, el computador y el bloque que me sobró, así que fue un poco caótico llegar.

## Un día antes 

Junto con mi grupo, después de pasar por varias propuestas que no terminaban de convencernos, finalmente llegamos a un proyecto más claro el día anterior. Pasamos prácticamente todo el día en el LAB, desde las 10 de la mañana, tomando decisiones y afinando ideas. En ese punto ya teníamos el cerebro colapsado, así que fuimos consultándole a Mateo cada duda que surgía. Él nos ayudó a cuestionar varias cosas que habíamos decidido el día anterior, especialmente porque habíamos comprado un sensor de gestualidad que queríamos integrar, pero se estaba volviendo demasiado complejo conectarlo.

La conclusión a la que llegamos es que, si nuestra intención era crear un juego proyectado que generara una sensación de logro frustrado, lo que realmente nos faltaba no era más tecnología, sino una visualización clara del objeto y del modo de interacción. Fue ahí cuando descartamos la idea de hacer una máquina controlada estrictamente por gestos y empezamos a considerar algo que se pudiera manipular directamente con las manos.

En ese momento les propuse volver al inicio y preguntarnos

>¿Qué pasaría si, en vez de botones, joysticks u otros controles precisos, usáramos sensores de fuerza como el medio principal de interacción?

Eso abría una posibilidad distinta un control menos rígido y más fluido, donde la persona tuviera que regular la fuerza entre sus dedos para lograr avanzar en el juego. Un sistema más amplio en rango, menos predecible y, por lo mismo, más desafiante. Y además, salía un poco de las directrices tradicionales del control tradicional.

Desde ese punto empezaron a aparecer muchas más ideas. Comenzamos a pensar en la gráfica del juego, en su tono visual y en el tipo de experiencia que queríamos construir. A todas nos hacía sentido incorporar una estética más retro, influenciada en parte porque todas somos jugadoras de **Minecraft** y nos atrae ese tipo de visual.

También vinculamos la estética con el sentimiento que buscábamos generar. El contexto narrativo fue tomando forma un mosquito que debes atrapar para ganar, pero que no se deja tan fácilmente, reforzando esta idea de logro frustrado. Terminamos el día con la decisión de que la gráfica tendría hadas, y que el puntero para atrapar sería una red, diseño que la Sofe y la Anto empezaron hacer en una web llamada **piskelapp**.

LINKS
- <https://www.piskelapp.com/> -> Creación de la gráfica.
- <https://editor.p5js.org/valentina.chavez1/sketches/_DhKZKhwd> -> Conexión con Arduino y P5js.
- <https://www.youtube.com/watch?v=U-N7nR5EEHs&t=245s> -> Conexión de prueba del sensor de fuerza.

## Durante la clase

Comenzamos el día  de trabajo con la tarea principal: **conectar P5.js con Arduino** y probar ambos sensores de fuerza funcionando simultáneamente. Individualmente ya respondían bien, pero necesitábamos integrarlos para controlar el movimiento en eje X e Y para luego integrarlo dentro del juego.

En la búsqueda de referencias encontramos un repositorio de Aarón con un ejemplo, pero él mismo nos recomendó no usarlo porque estaba desactualizado. Nos indicó otro repo más reciente, así que continuamos desde ahí. El problema fue que justo mientras intentábamos entender la estructura del código y cómo trabajar la comunicación serial, varias páginas se cayeron y perdimos visualización en P5, quedándonos solo con las lecturas en el monitor serial.

En medio de eso, la Vale R. tuvo que salir por cosas de su examen, así que con la Vale C. nos quedamos revisando el pseudocódigo para ordenar las ideas. Todavía no lo habíamos separado por funciones o etapas. Para sumar a la confusión, **se cortó la luz y el internet en la U**, lo que frenó aún más el avance.

Decidimos preguntarle directamente a Aarón porque nuestro objetivo era claro: **conectar dos sensores de fuerza al mismo Arduino**, asignándoles puertos distintos A0 y A1 para que cada uno activara respuestas diferentes. Después de pasar las conexiones en un solo Arduino, logramos que la pelotita se moviera en la pantalla de prueba, lo que nos indicó que la lectura simultánea estaba funcionando. Sin embargo, ambos sensores ejecutaban la misma acción, lo que no era nuestra intención. :(

Cuando Aarón revisó el código, detectó varios problemas: faltaban comentarios, había partes innecesarias, algunas variables tenían nombres confusos y la lógica estaba sobrecargada. Su observación clave fue que habíamos acumulado demasiadas instrucciones en Arduino, cuando en realidad lo único que debía hacer era **enviar los valores de lectura**. La interpretación y las acciones correspondían totalmente a P5.js.

Con la mete más clara volvimos al LAB. La Vale R. agregó comentarios, limpiamos el psudocódigo, eliminamos elementos que no aportaban (como la pantallita). La Vale Chávez investigó cómo hacer la conexión serial desde P5.js, y ahí descubrimos dos cosas importantes

1. El **puerto serial de Arduino debe estar cerrado** para que P5 pueda tomarlo.
2. Las imágenes que usamos para la prueba debían ser **PNG**, así que las convertí para evitar errores.

Después de calibrar todo, notamos que cada sensor tenía un inicio de lectura distinto, así que establecimos un **rango base de 20** para normalizar ambos valores y fijar un “0” más estable.

Con la conexión ya funcionando, empezamos a pensar en el montaje final. Vamos a usar la pantalla de Mateo para mostrar el juego sin depender del computador, y probablemente imprimiremos una carcasa para ocultar los paneles de herramienta de P5. Paralelamente, las chicas comenzaron a trabajar en las gráficas GIF y seguimos puliendo detalles.

A pesar del caos del inicio de semana, hoy sentimos que todo avanzó por fin. El trabajo colaborativo fue clave cada una aportó algo distinto. Terminamos el trabajo en LAB como a las cinco, más tranquilas y con la sensación de que el proyecto, por fin, empezó a tomar forma.
