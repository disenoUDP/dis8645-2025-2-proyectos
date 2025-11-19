# sesion-13a

Martes 04 de Noviembre, 2025

Nota del día: desde hoy se tiene que subir los apuntes a este nuevo repositorio. 

## Referentes

- **Aleister Crowley** (fue un influyente ocultista, místico, alquimista, escritor, poeta, pintor, alpinista y mago ceremonial británico, que fundó la filosofía religiosa de Thelema.)
- **Felipe Rivas San Martin** (artista visual chileno, ensayista y activista sexo-disidente. Doctor en Arte por la Universitat Politècnica de València (UPV), actualmente se desempeña como investigador postdoctoral de la USACH. <http://www.feliperivas.com/>)
- **Rafael Lozano Hemmer** (artista electrónico que trabaja con disciplinas entremezcladas entre la arquitectura, teatro tecnológico y la performance. Vive y trabaja en Montreal, Canadá. <https://www.lozano-hemmer.com/>)
- **La insoportable levedad del ser** (novela del escritor checo Milan Kundera, publicada en 1984. Ambientada en Praga durante 1968, La insoportable levedad del ser trata de un hombre y sus dudas existenciales en torno a la vida en pareja, convertidas en conflictos sexuales y afectivos.)
- **El arte de los ruidos** (manifiesto futurista escrito por Luigi Russolo en 1913, quien propuso que el ruido, el sonido de la vida moderna y la industria, debía ser integrado a la música para expandir la sensibilidad auditiva y crear nuevos placeres acústicos. Este manifiesto sentó las bases del futurismo musical y abogó por la destrucción de la tradición musical y la creación de nuevas herramientas para generar y controlar el ruido, como los intonarumori.)
- **Anna Ridler** (Anna Ridler es una artista e investigadora que vive y trabaja en Londres. Opera con colecciones de información o datos, particularmente conjuntos de datos autogenerados, para crear narrativas nuevas e inusuales en una variedad de medios. - Mateo la utilizo como referente para su proyecto <https://annaridler.com/> <https://annaridler.com/mosaic-virus>)
- **Qualcomm** (corporación multinacional estadounidense que diseña semiconductores, software y servicios para tecnología inalámbrica - hace poco se relacionó con arduino (lo compró) y a travez de este vínculo es que lanzaron al mercado una nueva tarjeta con un microprocesador, el "Arduino UNO Q")
- **ml5js** (Aprendizaje automático amigable para la web - Un enfoque cercano para crear y explorar la inteligencia artificial en el navegador - *"ml5.js busca hacer que el aprendizaje automático sea accesible para un público amplio de artistas, programadores creativos y estudiantes. La biblioteca proporciona acceso a algoritmos y modelos de aprendizaje automático en el navegador, basándose en TensorFlow.js sin dependencias externas adicionales"*. <https://ml5js.org/>)

## Qué aprendí hoy

### Instalar Windows PowerShell

PowerShell es un shell de línea de comandos y un lenguaje de scripting multiplataforma para la automatización de tareas y la administración de sistemas. Se utiliza para gestionar la configuración del sistema, la infraestructura en la nube y las redes, y se basa en el framework .NET, lo que le permite trabajar con objetos en lugar de texto. 

PowerShell puede interactuar con GitHub de varias maneras, principalmente a través de la interfaz de línea de comandos de Git (Git CLI) y la Interfaz de Línea de Comandos de GitHub (GitHub CLI). Esto permite gestionar repositorios, automatizar tareas y scriptar flujos de trabajo de desarrollo directamente desde el shell (es decir, es como tener instalados github directo en el compu y de ahí se puede editar todo, incluyendo el agregar o quitar archivos del repositorio)

(no anote mucho del proceso de como se instala porque estaba intentando prestar atención y así entender bien que se hacía, de momento aquí hay una explicación de como se hace hecha por gemini:)

#### Gestión de Repositorios con Git y PowerShell:

Clonación y Navegación:

- **Instalar Git:** Primero, asegúrate de tener Git instalado en tu sistema.
- **Clonar un Repositorio:** Usa el comando git clone dentro de PowerShell:

```PowerShell
git clone https://github.com/usuario/nombre-repositorio.git
```

- **Navegar:** Usa el comando de PowerShell Set-Location (o su alias cd) para entrar al repositorio:

```PowerShell
cd .\nombre-repositorio\
```

Flujo de Trabajo Básico (Commit, Push, Pull): Puedes usar los comandos estándar de Git para interactuar con tu repositorio remoto de GitHub:

- **Verificar estado:** git status
- **Añadir cambios:** git add .
- **Confirmar cambios (Commit):** git commit -m "Mensaje descriptivo"
- **Subir a GitHub (Push):** git push
- **Descargar cambios (Pull):** git pull

#### Uso de GitHub CLI (Recomendado):

La GitHub CLI (gh) es una herramienta oficial que simplifica las interacciones con GitHub, permitiéndote gestionar pull requests, issues y más, sin salir de la terminal de PowerShell.

Instalación y Autenticación:

- **Instalar gh:** Instala la GitHub CLI siguiendo las instrucciones oficiales (disponible a través de winget en Windows o directamente desde GitHub).
- **Iniciar Sesión:** Ejecuta el comando de autenticación en PowerShell:

```PowerShell
gh auth login
```

Esto te guiará a través de la autenticación en tu cuenta de GitHub, generalmente abriendo una ventana del navegador.

Comandos Comunes en PowerShell - Una vez autenticado, puedes realizar operaciones avanzadas:

- Crear un Pull Request:

```PowerShell
gh pr create --title "Título del PR" --body "Descripción detallada"
```

- Verificar Pull Requests:

```PowerShell
gh pr list
```

- Crear un Repositorio Nuevo:

```PowerShell
gh repo create mi-nuevo-repo --public
```

- Gestionar Issues:

```PowerShell
gh issue list
gh issue create --title "Bug encontrado"
```

- Automatización con PowerShell:

PowerShell es ideal para scripting y automatización, lo que permite crear tareas complejas relacionadas con GitHub:

- **Clonar Múltiples Repositorios:** Puedes usar un loop de PowerShell para clonar una lista de repositorios automáticamente.
- **Integración en CI/CD:** Scripts de PowerShell se utilizan comúnmente en herramientas de Integración Continua/Despliegue Continuo (CI/CD) como GitHub Actions para configurar entornos, ejecutar pruebas y desplegar aplicaciones.

Apuntes extra: 

- Abrir la carpeta github `cd .\github\`
- *Para la mayoría de comandos se debe estar dentro de la carpeta que se quiere modificar*
- Abrir la carpeta dis8645-2025-2-proyectos dentro de github `cd .\dis8645-2025-2-proyectos\`
- *el `.\` significa "aquí mismo" es en vez de escribir toda la dirección de nuevo*
- Agregar cambios a la app de GitHub `git add .`
- *El punto `.` es como decir "todo esto" en vez de escribir toda la dirección de nuevo*
- Hacer commit de los cambios con el mensaje "ideas proyectos" `git commit -m "ideas proyectos"` *siempre va el mensaje*
- Subir los cambios a GitHub `git push`
- Crear una carpeta `md "nombreDeCarpeta"`
- Crear un nuevo archivo o item `ni "nombre.tipo"` (yo creé un README.md así: `ni "README.md"`)
- Eliminar un item `ri direccion\de\la\carpeta`
- Abrir un archivo `ii direccion\del\archivo`
- Hacer Sync `git pull origin`
- Abrir una carpeta en VsCode `code .`

Sacar más información y comandos: <https://learn.microsoft.com/es-es/powershell/module/microsoft.powershell.management/>

### IA generativa 

¿Cómo funciona la IA generativa?

funciona entrenando modelos de aprendizaje automático con grandes conjuntos de datos para que aprendan patrones y estructuras, los cuales luego utilizan para crear contenido nuevo y original como texto, imágenes o código. Este proceso incluye la recopilación de datos, la formación del modelo para que reconozca los patrones y la generación de contenido nuevo que es una síntesis de lo aprendido. Un método común es el aprendizaje supervisado, donde el modelo aprende a crear contenido similar al que se le presenta junto con sus etiquetas.  

Proceso:

1. **Recopilación de datos:** Se reúne un conjunto masivo de datos para entrenar el modelo. Por ejemplo, para generar texto se utilizan libros y artículos, y para generar imágenes, se usan millones de imágenes. 
2. **Formación del modelo:** El modelo de IA utiliza redes neuronales para analizar los datos de entrenamiento y aprender los patrones, estructuras y relaciones subyacentes. Modelos populares como los de la serie GPT aprenden a generar texto coherente, mientras que otros, como las Redes Adversarias Generativas (GANs), se utilizan para crear imágenes y videos. 
3. **Generación de contenido:** Una vez entrenado, el modelo puede generar nuevo contenido que es una mezcla y síntesis de lo que aprendió. Por ejemplo, puede escribir un poema, crear una imagen o programar código que no existía antes. 
4. **Refinamiento y mejora:** El contenido generado puede ser perfeccionado con un posprocesamiento adicional para mejorar su calidad o para que cumpla con requisitos específicos. Se pueden usar técnicas como la "Generación Aumentada por Recuperación" (RAG) que conecta al modelo con fuentes externas para aumentar la precisión y confiabilidad de la información. 

El uso del captcha para asociar palabras a imagenes; tiene doble Propósito:

- **Verificación:** Algunas de las imágenes en la cuadrícula son de las que el sistema ya conoce la respuesta correcta. Si un usuario humano selecciona correctamente estas imágenes "conocidas", demuestra su capacidad de reconocimiento visual, algo que los bots tienen dificultad para hacer con exactitud en imágenes variadas y del mundo real.
- **Entrenamiento (o Crowdsourcing):** Otras imágenes son datos que el sistema necesita que los humanos identifiquen para entrenar sus propios modelos de Inteligencia Artificial (por ejemplo, para mejorar la detección de objetos en Google Street View). El sistema asume que la respuesta que la mayoría de los usuarios humanos da para estas imágenes "desconocidas" es la correcta.

El sistema no solo verifica la selección de imágenes, sino también otros factores como: el movimiento del cursor del ratón antes de hacer la selección, el tiempo que tarda el usuario en resolver el desafío o el historial de navegación y las cookies del navegador.

- **TPU (Tensor Processing Unit):** es un chip especial creado por Google para que las inteligencias artificiales aprendan y trabajen más rápido. Muchos de los macbook actuales vienen con tpu.
- **CPU:** el cerebro normal del computador, hace de todo, pero más lento en tareas de IA.
- **GPU:** muy buena para cálculos en paralelo, como los de videojuegos o redes neuronales.
- **TPU:** una “GPU especializada” diseñada exclusivamente para IA.
- **RNN (Red Nuronal Recurrente):** es un tipo de inteligencia artificial que sirve para trabajar con información que viene en secuencia. Como trabaja con datos, siempre se puede equivocar ya que juega con probabilidades.
- **Google Colaboratory**: te prestan un servidor de Google de cualquier parte del mundo para usar un computador. Cada usuario con una cuenta de google puede acceder esto. Tiene TPU y GPU. Este entorno es muy usando en este tiempo para usar Inteligencia Artificial. Puedes usar la TPU de ese computador si es que el propio no cuenta con ese elemento.

## Qué hice hoy

Se hizo un repaso general de las ideas para el proyecto 03 de cada grupo, por tiempo no alcanzamos a ver las propuestas de mi grupo (grupo 01) pero son las mismas anotadas la clase anterior: 

### Ideas generales de máquinas sentimentales:

- máquina que esta dándote la espalda y cuando recibe un piropo se da la vuelta “ofendida” y te revela su real aspecto que da miedo.
- máquina con forma de tetera que cuando siente temperaturas altas (como si estuviera hirviendo) ronronea/vibra para avisar y se tiene que acariciar para apagarse.
- máquina reforzada en legos que se debe pisar y al pisarse se activa un sonido de ronroneo y su vibración, demostrando ironía en el sentimiento que provoca pisar un lego.
- máquina que da piropos cuando te ve pasar y te hace sentir incómodo.
- objeto con forma de cubo rubik pero realmente esta hecho de legos por lo tanto para armarse realmente se tiene que desarmar en vez de moverse en si mismo.

### Ideas de máquinas sentimentales:

La Máquina del Error

- Sensaciones: Hipnótica, frustrante, brillante, complicada, lógica, desordenada.
- Pantallita de LEDs que intenta mostrar patrones perfectos pero siempre falla en un punto.
- Si el usuario trata de corregirla (botones o potenciómetros), se equivoca más.
- No soporta la perfección por lo tanto se sabotea para mantener su caos.

El Halagador que Miente

- Sensaciones: incomodar, desconcierto
- Qué hace: Cada vez que pasas, te suelta un halago breve, pero justo después te dice algo feo (tono burlón).
- Si detecta sonido (te defiendes), responde con un bufido y se silencia 30s.

La Ofendida

- Sensaciones: invasivo, intimidante, agresivo
- Qué hace: está de espaldas, pero cuando alguien le habla o intenta llamar su atención, se da la vuelta bruscamente mostrando una cara o forma perturbadora.

La Máquina Egocéntrica

- Sensaciones: piropo ofensivo, arrogante, insistente.
- Qué hace: cada vez que te acercas, te lanza cumplidos… pero todos son sobre sí misma. “¿Has visto mi estructura?”, “soy tan brillante hoy”, “todos me miran cuando paso”.

La Máquina del Eco

- Sensaciones: hipnótica, decepcionante, Sorprendente.
- Qué hace: Repite con retraso cualquier palabra que digas, pero cada repetición pierde una sílaba hasta convertirse en nada.
