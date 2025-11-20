# sesion-13a
04/11/25

## Teloneo

- Michael Myers: es un personaje de ficción creado por John Carpenter y Debra Hill, y es el antagonista principal de la serie de películas Halloween, del género slasher. ¿Por qué no habla?, Es un mal tartamudo, tiene un impedimento del habla y es demasiado inseguro al respecto.

- Qualcomm: corporación multinacional estadounidense. Crea semiconductores, software y servicios relacionados con la tecnología inalámbrica.

Arduino Uno no se ha convertido en un producto de Qualcomm, sino que Qualcomm ha adquirido Arduino. Esta adquisición permitirá que los usuarios de Arduino tengan acceso a las tecnologías de Qualcomm, como la inteligencia artificial y el procesamiento, mientras que Arduino mantendrá su enfoque en código abierto y su comunidad.

- ml5.js busca hacer que el aprendizaje automático sea accesible para un público amplio de artistas, programadores creativos y estudiantes. La biblioteca proporciona acceso a algoritmos y modelos de aprendizaje automático en el navegador, basándose en TensorFlow.js sin dependencias externas adicionales. https://ml5js.org/
- El mil es la mínima unidad de longitud en el sistema inglés de medidas, es la milésima parte de una pulgada. Equivale a 0,0254 milímetros.
- ¿Qué es la difusión estable? : Es un modelo de inteligencia artificial generativa (IA generativa) que produce imágenes fotorrealistas únicas a partir de mensajes de texto e imagen.
- Captcha: Sistema de desafío-respuesta utilizado en informática para determinar si el usuario es una persona o un bot (programa automático).
- GPU: Es un circuito electrónico especializado en acelerar la creación de imágenes y vídeos.

Mateo nos mostró su proceso para crear letras con una ia generativa que está entrenando. Revisar su repo https://github.com/matbutom

_ época: enseñarle a una ia a través de ejemplos existentes, son ejemplos para que la ia aprenda, para que esto resulte (que aprenda), necesita miles de épocas.
- Espacio latente: es un recorrido aleatorio de una misma imagen. Representación matemática de baja dimensión de datos complejos que captura sus características y patrones esenciales. Es un espacio abstracto donde los puntos de datos similares están agrupados, lo que permite a los modelos de aprendizaje automático procesar y entender información de manera más eficiente, y es utilizado en aplicaciones como la generación de imágenes y el procesamiento de texto. 

revisar mas a fondo el trabajo de Anna Ridler https://annaridler.com/

Cierre telón

## Apuntes
- Ahora hay un segundo repositorio en donde se trabajará el proyecto 3. Empezar a usar este, para anotar todos los apuntes.
- Terminar de tomar apuntes en el repositorio anterior y a ordenar algunas cosas que falten.
- Aprender sobre homebrew e instalar github. Lo que hace es instalar cosas que tu dispositivo no hace.
- Explayarse mas con la explicación del proyecto, escoger una idea e idealmente hacer un guion sobre el funcionamiento y especificaciones.

### `¿Cómo funciona la IA, la inteligencia artificial?`

La inteligencia Artificial (IA) funciona procesando grandes cantidades de datos a través de algoritmos para identificar patrones y tomar decisiones. El proceso clave es el aprendizaje automático, donde los sistemas aprenden y mejoran su rendimiento de forma autónoma a medida que reciben más datos, en lugar de ser programados para cada tarea. Técnicas como el aprendizaje profundo, que utiliza redes neuronales inspiradas en el cerebro humano, permiten abordar problemas complejos como el reconocimiento de imágenes o de voz. 

- las imágenes funcionan bajo una matriz de números.
- le entrega valores númericos, que se modifican según como entrenamos esta imágen.
- `¿Cómo ocurre con las palabras?` también genera una matriz de números, el cual busca en distintas partes la compatibilidad de la palabbra. El cual, es formado por una cadena de números.

`NOSOTROS ENTRENAMOS A LA IA, CON LA CONFIRMACIÓN.`

- el uso del captcha para asociar palabras a imagenes.
- `TPU` Tensor Processing Unit: es un chip especial creado por Google para que las inteligencias artificiales aprendan y trabajen más rápido. Muchos de los macbook actuales vienen con tpu.
- `CPU` el cerebro normal del computador, hace de todo, pero más lento en tareas de IA.
- `GPU` muy buena para cálculos en paralelo, como los de videojuegos o redes neuronales.
- `TPU` una “GPU especializada” diseñada exclusivamente para IA.
- RNN Red Nuronal Recurrente: es un tipo de inteligencia artificial que sirve para trabajar con información que viene en secuencia. Como trabaja con datos, siempre se puede equivocar ya que juega con probabilidades.

`Google Colaboratory`

Servicio en la nube gratuito que permite escribir y ejecutar código Python directamente en un navegador web, sin necesidad de instalar ningún software.

Google Colaboratory, te prestan un servidor de Google de cualquier parte del mundo para usar un computador. Cada usuario con una cuenta de google puede acceder esto. Tiene TPU y GPU. Este entorno es muy usando en este tiempo para usar Inteligencia Artificial. Puedes usar la TPU de ese computador si es que el propio no cuenta con ese elemento.

`Homebrew`

- Como poder instalarlo
  -  a. Se debe ir a la página: (https://brew.sh/).
  -  b. copiar el link que aparece en la página.
  -  c. abrir la terminal del computador.
  -  d. pegar lo copiado.
  -  e. hacer enter y seguir los pasos.
  
Revisar los videos para instalar correctamente el programa.

Con esto tendremos github para poder usarla en la consola. De esta manera es mucho más fácil rebobinar commits cuando nos equivocamos. Tambien entramos en VS Code, sin importar que el servisor de github en la nube se caiga. Las carpetas se alojan en el computador por lo que se pueden programar directamente desde vs code. Usar copilot de github para completar tareas como códigos, párrafos, etc.

### Ideas para el Proyecto N°3 (grupo 4)

Una maquina que reacciona cuando le aplicas una fuerza ¿cuál es la reacción? ¿qué hace cuando le aplicas mucha fuerza? ¿qué hace cuando le aplicas una menor fuerza?

- Punching bag, le pegas y se calma.
- Sensores de fuerza.
- Fluido no newtoniano.
- Reacción de fluidos con la presión.
- Cómo medir el impacto/velocidad de la fuerza.
- Sensores FSR de presión. Resistencia que cambia de valor cuando se le aplica la fuerza. Sensor muy sensible, ya que es poco preciso.
- Ver temas contingentes. que para acceder a este vivienda tengas que tener x horas de trabajo o x horas de algo.
- Materialidad, basándose en la naturaleza de la materia. Liquidps, etc.
