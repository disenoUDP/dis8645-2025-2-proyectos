# sesion-14a

## taller martes 11 de noviembre

primera parte: trabajo grupal

- definir forma del objeto, ¿tódo irá orientado hacia la salida del vapor? esto dicho para crear una especie de expectativa hacia el lugar más "importante de la máquina"
- una especie de arco con luces que indiquen que por arriba saldrá el vapor, algún referente puede ser una especie de rockola por la forma a seguir y la exagerada ornamentación que poseen
- la idea de esta ornamentación es que tenga coherencia y se vea detallado y pro, no que sea poner cosas por todos lados y que se vea desordenado
- definir la forma en la que se resetea la máquina y cada uno de sus actuadores
- las luces se detienen de forma gradual pero el resto de la máquina no? quizá esto podría generar una especie de incongruencia
- sonidos: sonidos cambian tonos a medida que te acercas al clímax? estos sonidos también vendrían acompañados con un aumento de volumen? establecer si poner más indicadores de que te acercas a la meta harán que el usuario se sienta más cautivado/motivado a llegar a la meta

### motor vibrador

- me encargaré de hacer funcionar el motor vibrador, será de un vibrador de un joystick de xbox 360 o un módulo pwm dependiendo de cuál es más fácil de utilizar
- se necesita establecer que después de un número de vueltas se active la vibración, en este caso debiese ser cuando llega a la mitad del progreso de la máquina mediante el uso de la manivela
- se mantiene en esta vibración hasta que se alcance otro nivel más alto en el progreso de la manivela
- el semestre pasado utilicé un potenciómetro con un pwm, a medida que lo giraba en sentido horario el motor giraba más rápido, la diferencia con este proyecto sería que al dar cierto número de vueltas, aumentaría velocidad, es decir, depende de que se cumpla una condición. En el proyecto del semestre pasado este aumento de velocidad era constante, no existían más condiciones más allá de girar en sentido horario para que aumentara la velocidad
- conseguirme un encoder si es que hay o ver esa clase en la que establecían ciertos valores a los potenciómetros
