# sesion-13b

##Pseudocódigo
Los componentes definidos para nuestra máquina (por ahora) son los siguientes:
- Parlante
- mp3
- LEDs
- vibrador
- servomotor
- bomba de agua
- encoder rotatorio

### Manivela/encoder
1. Definir valores que indiquen que se dió una vuelta.
2. Vueltas de manivela alimentan un contador.
3. Vueltas horarias suman y antihorarias restan.
4. Establecer hitos (cantidad de vueltas) que activan actuadores e indican progreso.
5. Cantidad suficiente de vueltas de la manivela activan el humo.
6. Ejemplo: 15%, 30%, 60%, 80%, 100%. Porcentaje de avance de giros necesarios para llegar a climax.


### Parlante
1. Ligar a número de vueltas de la palanca.
2. Asociar volumen o audio variable según cantidad de vueltas.
3. Establecer audio cuando se complete la interacción. Enuncia salida del humo.
4. Establecer instancia en la que suena cada audio. En este caso cuando se pasa por el punto superior de la manivela suena el audio (0,5 seg).
5. Audio cambia dependiendo del paso en el que se encuantra
6. Al llegar al climax se reproduce audio distinto
7. Se reinicia

### Luces LED
1. Instalar todas las led en fuente de energía
2. Establecer cuando se enciende cada led y cuánto se
mantiene encendida
3. Establecer pasos según valores de manivela
4. Se prende una luz al alcanzar el paso siguiente
5. Interacción inicia con una luz prendida
6. Vuelve a una luz prendida al completar interacción


### Bomba de agua
1. Asociar a último paso (100%)
2. Definir cantidad de vapor/tiempo de activación
3. Suelta vapor
4. Se reinicia


### Vibrador
1. Asociar a valores de pasos determinados alcanzados por manivela
2. En un punto medio de progreso (60%) se activa y aumenta su intensidad a medida que avanza
3. Se desactiva nuevamente al completar la interacción
4. Se reinicia

### Servomotor
1. Asociar a bomba de agua y completar los giros de manivela.
2. Abre una compuerta para dejar salir el humo
3. Queda abierta brevemente y se vuelve a cerrar
4. Se resetea






 





