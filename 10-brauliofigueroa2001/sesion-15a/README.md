# sesion-15a

## taller clase martes 18 de noviembre

### último día de avance en clases antes del proyecto 3

#### módulo motor vibrador 

![modulovibrador](./imagenes/modulovibrador.jpg)

- logré hacer que vibrara mediante el uso del siguiente código que encontré en una página [caferobot](https://thecaferobot.com/learn/interfacing-a-vibration-motor-module-with-arduino/)

```cpp
    /*
  modified on Sep 8, 2020
  Modified by MohammedDamirchi from Arduino Examples
  Home<iframe class="wp-embedded-content" sandbox="allow-scripts" security="restricted" style="position: absolute; clip: rect(1px, 1px, 1px, 1px);" title="&#8220;Home&#8221; &#8212; Electropeak" src="https://electropeak.com/learn/embed/#?secret=lI8B17CnPA" data-secret="lI8B17CnPA" width="600" height="338" frameborder="0" marginwidth="0" marginheight="0" scrolling="no"></iframe>
*/


// the setup routine runs once when you press reset:
void setup() {
  pinMode(2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(1000);
 
}
```

- este código hace que el motor vibre y se apague constantemente como high y low, cada 1 segundo aprox se emite una vibración
- necesito ver si puede vibrar más fuerte o si está en su límite, desconozco esto
- debo probar un circuito pwm para ver si puedo hacer que la vibración sea más fuerte y la pueda controlar mediante un potenciómetro/encoder, la idea es que al pasar cierto umbral/parámetro de la rotación de la manivela encoder se active el motor
- después de hablar con misaaa sobre el módulo me dijo que en estos módulos no puedo hacer que la vibración sea más fuerte
- lo que tengo que hacer es una "operación" al módulo en la cuál debo cortar los cables que están direccionados al motor y soldarlos a un vibrador de joystick, este vibrador es más fuerte y lo puedo controlar con un PWM


#### jornada de avance, miércoles 19 de noviembre

- se soldó el módulo vibrador al vibrador del joystick, reemplazando el vibrador pequeño que tenía el módulo por el del joystick para tener un vibrador más potente





#### jornada de avance jueves 20 de noviembre

- en vez de establecer un rango continuo de vibración ej: (rango 1, vibración 1 continua) (rango 2, vibración continua 2), como aumentarle la velocidad con un potenciómetro cuando se hace con un circuito pwm y un motor

- en vez de que sea un aumento continuo por así decirlo, puede ser
- rango 1: motor vibra de forma intermitente, se enciende 2 segundos y se apaga 2 segundos
- rango 2: motor vibra de forma intermitente, se enciende 1 segundo y se apaga 1 segundo    
- rango 3: motor vibra de forma continua y se detiene cuando llega al último nivel que sería el clímax en el que se expulsa el humo 
- esto se puede ver en el monitor serial
