# sesion-14a

## Avance proyecto

- Revisamos bien qué cosas estaríamos necesitando y cuáles no
- El motor vibrador ya tiene integrado un módulo mosfet por lo que se descartó comprar el mosfet por separado
- Organización de cableado y pines a utilizar:

### Cableado maquinita ansiedad:

- // Sensor ultrasónico tiene 4 patitas

  - // VCC va en 5V

  - // Trig (disparador) va en pin 2

  - // se utiliza para disparar pulsos de sonido ultrasónico

  - // Echo va en pin 3

  - // GND a GND

- // Motor vibrador tiene 3 patitas

  - // GND a GND

  - // VCC a 5V

  - // In va a pin a definir (5)

- // LED RGB tiene 4 patitas

  - // la patita más larga si es cátodo común va a GND

  - // si es ánodo común va a 5V

  - // R + resistencia a ~9

  - // G + resistencia a ~10

  - // B + resistencia a ~11

### Cableado maquinita vergüenza:

- // Sensor ultrasónico tiene 4 patitas

   - // VCC va en 5V

   - // Trig (disparador) va en pin 2

   - // se utiliza para disparar pulsos de sonido ultrasónico

   - // Echo va en pin 3

   - // GND a GND

- // Micro servo motor tiene 3 cables hembra

  - // GND a GND (café)

  - // VCC a 5V (rojo)

  - // Señal PWM a pin a definir (~6) (naranjo)

- // LED RGB tiene 4 patitas

  - // la patita más larga si es cátodo común va a GND

  - // si es ánodo común va a 5V (nuestro LED es ánodo)

  - // R + resistencia a ~9

  - // G + resistencia a ~10

  - // B + resistencia a ~11
 
### Avance del pseudocódigo de ambas máquinas definiendo la lógica base a:

– Lectura de distancia

– Estados de calma/alerta

– Variación del PWM en el motor

– Comportamiento emocional general

### Idea montaje físico

- Son 2 gatitos que estan en una caja la cuál contendría todas las piezas dentro ocultas, y que el ultrasónico sean los ojos de los gatitos
