# sesion-17b

Después de tantas pruebas, quería comprobar que si en el tilt sensor lo que causaba que se pegara todo, pero no, era todo culpa del dfplayer, habían 2 razones posibles, 1 que era que estaba mal conectado el rt y el tx, que puede haber sido una tonteria despues de tanto tiempo que andaba probando esto, o la otra era que cambiase de utilizar softwareSerial, algo que al parecer no funciona muy bien en el arduino uno r4 Mínima, sino utilizar un estilo ya nativo que se llamaba Serial1, que utiliza los pines 0 y 1 del arduino sin siquiera necesidad de establecer pines en pinmode. probé ambos cambios simultáneamente y fue excelente, no quiero volver atrás en el tiempo como para probar cada uno individualmente, solo se que soy feliz y subire el WEBO_0_7_2.

Le pregunté a Aaron si es que era buena idea crear un archivo por separado para solo globalizar los timers que he seteado para todos los componentes así que los traspasé y por ahora se ve todo bien. 

Igual pensé que podría hacer que algunos de los parámetros estén presentes en uno de esos archivos, como por ejemplo si está caído, todo para que se vea precioso el .ino y solo están ocurriendo las cosas constantemente, en un principio pensé usarlo solo para los temporizadores pero me di cuenta que igual era conveniente para mas que solo eso como variables globales, donde puedo escribir cosas como si los motores están girando actualmente, si esta caido el WEBO y el pasar de los segundos entre otras cosas.

Aunque también puede quedar medio fome, tendré que preguntar que opinan los profes.

También me puse a hacer la pantalla de la AVA girando cuando se activa el motor a partir de switch cases con el siguiente ejemplo : 

https://docs.arduino.cc/language-reference/en/structure/control-structure/switchCase/

Para que se hagan los cambios rápidos de menos de medio segundo de cómo AVA gira en cada frame, quedó más o menos así:
