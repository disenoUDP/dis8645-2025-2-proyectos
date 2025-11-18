# sesion-15a

## taller clase martes 18 de noviembre

### último día de avance en clases antes del proyecto 3

#### módulo motor vibrador 

- logré hacer que vibrara mediante el uso del siguiente código que encontré en una página [caferobot](https://thecaferobot.com/learn/interfacing-a-vibration-motor-module-with-arduino/)

````cpp
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

- este código hace que el motor vibre y se apague constantemente como high y low, cada 1 segundo aprox se emite una vibración
- necesito ver si puede vibrar más fuerte o si está en su límite, desconozco esto
- debo probar un circuito pwm para ver si puedo hacer que la vibración sea más fuerte y la pueda controlar mediante un potenciómetro/encoder, la idea es que al pasar cierto umbral/parámetro de la rotación de la manivela encoder se active el motor
- después de hablar con misaaa sobre el módulo me dijo que en estos módulos no puedo hacer que la vibración sea más fuerte
- lo que tengo que hacer es una "operación" al módulo en la cuál debo cortar los cables que están direccionados al motor y soldarlos a un vibrador de joystick, este vibrador es más fuerte y lo puedo controlar con un PWM
