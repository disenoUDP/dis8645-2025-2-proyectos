# sesion-16b

Este dia partio con una convivencia en celebracion del cumpleaños de Camila y Braulio, que estuvo entrete, hable con una buena cantidad de gente del taller que me cae bien, comi mucho tambien.

Luego nos pusimos un poco mas serios para hablar respecto al examen, nos debemos organizar con google calendar para no mal gastar el timepo, se nos presento nuestra comision donde sali un poco retado respecto a no tener prejuicios porque no conocia a uno de los profesores los que nos iba a evaluar.

Los dias de motaje son el sabado 6, el domingo 7 y el lunes 8, pero deberiamos tener todo escrito en el github para el sabado 6 en la tarde, miedo.

Tambien cada uno de los grupos podemos ver la manera en la que vamos a presentar, ya que el examen sera en el LID si que tambien hay que ponernos de acuerdo para que Bernardita no lo haga todo.

Para realmente empezar a trabajar en nuestro proyecto y mejorar al WEBO, primero quise ver cual era el gran problema respecto a que se nos pegaba siempre que el tilt era activado, donde observe que en realidad no era el sensor tilt en especifico el problema, sino que el reproductor mp3 es lo que estaba bloqueando todo.

En la manera que lo pude confirmar fue desconectandolo, de esa manera funcionaba perfecto, o semi perfecto igual habia un poco de problemas derrepente, pero no al punto de congelar la maquina completa.

Tambien veia que cuando nuestro motor se activaba todos los otros componentes se apagaban por una pequeña fraccion de segundo, la cual no me gustaba ver porque podia causar un problema para el futuro.

Asi que mi gran manera de solucionarlo fue cambiar exclusivamente el reproductor mp3 a una linea de alimentacion distinta que en este caso seria de 5V, todo el proyecto estaba en la misma linea para mayor conveniencia que era 3.3V debido a que el display solo podia funcionar con ese voltaje directamente al Arduino.

De esta manera funciono super bien, aun se demoraba un poco en reaccionar pero era mas que todo por los delays, pero el hecho que no se bloqueara era magnifico.


