# sesion-13a 04/11

## Apuntes clase

### ¿Cómo funciona la inteligencia artificial?

- las imágenes funcionan bajo una matriz de números
- le entrega valores númericos, que se modifican según como entrenamos esta imágen

### ¿Cómo ocurre con las palabras?

también genera una matriz de números, el cual busca en distintas oartes la compatibilidad de la palabbra. El cual, es formado por una cadena de números.

`nosotros entrenamos a la ia, con la confirmación.`

### ¿Cómo funciona la IA generativa?

- el uso del captcha para asociar palabras a imágenes.
- **TPU** (Tensor Processing Unit): es un chip especial creado por Google para que las inteligencias artificiales aprendan y trabajen más rápido. Muchos de los macbook actuales vienen con tpu.
- **CPU**: el cerebro normal del computador, hace de todo, pero más lento en tareas de IA.
- **GPU**: muy buena para cálculos en paralelo, como los de videojuegos o redes neuronales.
- **TPU**: una “GPU especializada” diseñada exclusivamente para IA.
- **RNN** (Red Nuronal Recurrente): es un tipo de inteligencia artificial que sirve para trabajar con información que viene en secuencia. Como trabaja con datos, siempre se puede equivocar ya que juega con probabilidades.

### Google Colaboratory

Google Colaboratory, te prestan un servidor de Google de cualquier parte del mundo para usar un computador. Cada usuario con una cuenta de google puede acceder esto. Tiene TPU y GPU. Este entorno es muy usando en este tiempo para usar Inteligencia Artificial. Puedes usar la TPU de ese computador si es que el propio no cuenta con ese elemento.

### Homebrew

Es un programa que te permite instalar fácilmente software en el computador, especialmente en macOS. Usaremos esto para poder escribir en github pero desde la terminal del computador.

`Para poder instalarlo:`
1. se debe ir a la página: (https://brew.sh/).
2. copiar el link que aparece en la página.
3. abrir la terminal del computador.
4. pegar lo copiado.
5. hacer enter y seguir los pasos.

- Revisar `los videos para instalar` correctamente el programa.

Con esto tendremos github para poder usarla en la consola. De esta manera es mucho más fácil rebobinar commits cuando nos equivocamos. 

También entramos en VS Code, sin importar que el servisor de github en la nube se caiga. Las carpetas se alojan en el computador por lo que se pueden programar directamente desde vs code.

- epoca: es lo que le entrenas para que sepa que es lo que necesitamos, hace un check de muchas para saber qué es.
por ejemplo: si ve 4 sillas ve cada una de ellas para sabe que es una silla. si ve mil sillas ya tiene una idea de que es la silla.

#### Ideas Grupo 01:

Objetos:

**Tetera hirviendo:** Suena, Caliente, Metalica, Molesta, Almacenadora, Contenedora, Peligrosa, científica, ruidosa, Térmica, Transportable, Dolorosa, Dañina, Tradicional, Humeante, Estresante, Húmeda

**Ronroneo de gato:** Tierno, Relajante, Feliz, Ruidoso, Silencioso, vibrante, Hipnótico, Calentito, Apaciguante, Constante, Cariñoso, Suave, Curativo, Melódico, Acompañante, Sutil, Reconfortante, Adictivo, Emotivo.

**Cubo Rubik:** Colorido, Movible, transportable, Complicado, 6 caras, Geométrico, Lógico, Desesperante, Enigmático, Brillante, Plástico, Deslizante, Didáctico, Preciso, Mecánico, Frustrante, Ordenable, Hipnótico, Retador.

**Dolor de pisar un lego:** Doloroso, Dañino, Incomodo, Enoja, Brutal, Sorpresivo, Instantáneo, Traicionero, Despiadado, Punzante, Intenso, Recordable, Agudo, Maldito, Injusto, Doméstico, Despertador.

**Piropo ofensivo:** Invasivo, Incómodo, Grosero, Ruido social, Vulgar, Violento, Intimidante, Desubicado, Irrespetuoso, Perturbador, Machista, Desagradable, Sorprendente, Desigual, Innecesario, Sexista, Agresivo, Impulsivo, Hostil, Arrogante, Insistente, Repulsivo.

`Ideas generales de máquinas sentimentales clase pasada:`

máquina que esta dándote la espalda y cuando recibe un piropo se da la vuelta “ofendida” y te revela su real aspecto que da miedo.
máquina con forma de tetera que cuando siente temperaturas altas (como si estuviera hirviendo) ronronea/vibra para avisar y se tiene que acariciar para apagarse.

máquina reforzada en legos que se debe pisar y al pisarse se activa un sonido de ronroneo y su vibración, demostrando ironía en el sentimiento que provoca pisar un lego.,
máquina que da piropos cuando te ve pasar y te hace sentir incómodo

objeto con forma de cubo rubik pero realmente esta hecho de legos por lo tanto para armarse realmente se tiene que desarmar en vez de moverse en si mismo.

`Ideas de máquinas sentimentales:`

### La Máquina del Error

Sensaciones: Hipnótica, frustrante, brillante, complicada, lógica, desordenada.
Pantallita de LEDs que intenta mostrar patrones perfectos.

Pero siempre falla en un punto.

Si el usuario trata de corregirla (botones o potenciómetros), se equivoca más.
No soporta la perfección, que se sabotea para mantener su caos.

### El Halagador que Miente

incomodar, desconcierto

Qué hace: Cada vez que pasas, te suelta un halago breve, pero justo después te dice algo feo (tono burlón).

Si detecta sonido (te defiendes), responde con un bufido y se silencia 30s.

### La Ofendida

invasivo, intimidante, agresivo

Qué hace: está de espaldas, pero cuando alguien le habla o intenta llamar su atención, se da la vuelta bruscamente mostrando una cara o forma perturbadora.

### La Máquina Egocéntrica

piropo ofensivo, arrogante, insistente.

Qué hace: cada vez que te acercas, te lanza cumplidos… pero todos son sobre sí misma. “¿Has visto mi estructura?”, “soy tan brillante hoy”, “todos me miran cuando paso”.

### La Máquina del Eco

hipnótica, decepcionante, Sorprendente.

Qué hace: Repite con retraso cualquier palabra que digas, pero cada repetición pierde una sílaba hasta convertirse en nada.
  
