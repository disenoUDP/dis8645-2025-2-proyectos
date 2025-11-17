# sesion-15a

18-11-2025

## Apuntes

---

El viernes después de clases, mandé un mensaje muy largo por nuestro grupo en discord y ocurrieron cositas con el proyecto, nos dimos cuenta que en verdad ninguna estaba satisfecha al 100% con lo que estábamos haciendo, por lo que tratamos de darle otra vuelta al proyecto. Sentíamos que estábamos forzando el porqué del uso del sensor y la materialidad con las lanas.

máquina sentimental “Atrápame si puedes”

SENTIMIENTOS:
- frustración
- dominar (tener el control)
- dirigir
- competitividad

METÁFORA:
- La máquina es una representación tecnológica del logro frustrado: esa sensación cotidiana en la que la promesa del éxito se rompe por un detalle mínimo. Al mismo tiempo, habla de la experiencia humana de perseguir algo que siempre se escapa: expectativas, logros, reconocimiento o metas personales y emocionales que parecen estar al alcance… pero nunca del todo. En ese juego constante entre deseo y evasión, la máquina encarna la relación desigual entre la intención humana y la respuesta arbitraria de un sistema. Una máquina que te hace sentir el delicado filo entre querer algo… y perderlo por un gesto mínimo.

PRESENTACIÓN TEXTUAL
- “Atrápame si puedes” es una máquina interactiva que funciona con gestos de la mano. El usuario mueve su mano frente a un sensor, y ese gesto controla un punto en una pantalla. El objetivo del juego es alcanzar un objeto que aparece en la pantalla.

Pero la máquina está diseñada para escaparse justo cuando estás a punto de atrapar el objetivo. Detecta tu cercanía y activa una especie de “glitch” o falla visual que hace que el objetivo huya. Esto provoca una mezcla de frustración y risa, porque el error no es real: la máquina te está troleando a propósito.

A veces te deja sumar puntos, otras veces te engaña, y te invita a seguir intentando con mensajes provocativos. La interacción crea una especie de competencia emocional entre el usuario y la máquina.

En resumen: es un juego que reconoce tus gestos, te hace creer que vas a ganar y luego se escapa, generando una experiencia divertida, frustrante y muy humana.

BILL OF MATERIAL
- Sensor de gestualidad PAJ 7620
- Conversor de nivel lógico I2C 5V a 3.3V
- Arduino Uno R4 Minima
- Pantalla
- Carcasa
- Plinto
- Cables

DIAGRAMA DE FLUJO

1- Pantalla prendida con algún texto (SALUDA PARA COMENZAR👋🏻)
2- Título: "Atrápame si puedes"  monito: Mosquito Abstracto (gráfica sofi)
3- Empieza el juego y el punto se estará moviendo todo el rato
4- Tratar de atrapar el punto- tiene 3 vidas -
4a- lo atrapé: 2 vidas
4b- lo atrapé: 1 vida
4c- Tratar de atraparlo por última vez, la máquina te trollea
5- Cuando te trollea aparece el glitch
6- "ingresar texto gracioso" o "imagen chistosa"
7- vuelve al inicio (saluda para comenzar)

Que pasaría si: si la persona atrapa al mosquito una vez y se va, la máquina también vuelve al inicio
