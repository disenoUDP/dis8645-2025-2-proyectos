# sesion-14a

## Máquinas computacionales: 11/11

Nota de clase: Empezamos trabajando cada grupo en su entrega del proyecto 03, cada uno muy concentrados algunos se fueron al LAB a trabajar :).

## Máquina sentimental: Proyecto 03

La máquina sentimental es un organismo artificial que responde al tacto humano como si tuviera emociones propias. Representa el intento de traducir afectos en datos; de convertir gestos en lenguaje digital.

Su cuerpo, hecho de una materialidad blanda y orgánica, invita al acercamiento, pero también despierta la curiosidad por lo desconocido que habita en lo artificial.

Esa mezcla de suavidad y extrañeza genera un momento de duda: el usuario no sabe si enfrentarse a un objeto inerte o a una presencia viva. En ese instante, la tecnología deja de ser solo herramienta y se vuelve territorio sensible, un espacio de descubrimiento donde lo mecánico parece respirar.

La máquina no busca imitar lo humano, sino evocar emociones a través de la interacción.

Cada gesto (apretar, estirar o acariciar) es un lenguaje que el cuerpo humano ofrece y la máquina interpreta, devolviendo una respuesta sonora y visual que traduce ese impulso en un paisaje emocional.

## Conexión del sensor de fuerza

<https://www.youtube.com/watch?v=U-N7nR5EEHs&t=245s>
<https://drive.google.com/file/d/1E8LE9cpVo9UqIRcnHb8q6f4_a5mTzZzc/view>

Código base utilizado

```cpp

const int Sensor_Fuerza = A0;  // Pin del sensor de fuerza 

void setup() {
    Serial.begin(9600);
    pinMode(Sensor_Fuerza, INPUT);
}

void loop() {
    int valorFuerza = analogRead(Sensor_Fuerza);  // Leer el valor del sensor
    Serial.print("Sensor de Fuerza: ");
    Serial.println(valorFuerza);
    
    delay(500);  
}

```
1. Definición del sensor

```cpp
const int Sensor_Fuerza = A0;
```
Acá simplemente le digo al Arduino: “oye, el sensor FSR está conectado al pin A0”. Como es un sensor analógico, necesita un pin que pueda leer cambios de voltaje.

2. Configuración inicial

```cpp
Serial.begin(9600);
pinMode(Sensor_Fuerza, INPUT);
```

Serial.begin(9600): abre el canal de comunicación para poder ver los datos en la pantalla del computador (Serial Monitor).

pinMode: le indico al Arduino que este pin será para recibir información, no para enviarla.

3. Lectura del sensor
   
```cpp
int valorFuerza = analogRead(Sensor_Fuerza);
```

Aquí el Arduino mide cuánta fuerza estoy aplicando al FSR. La lectura siempre va entre 0 y 1023, dependiendo de cuánta presión haya.
Mientras más aplaste el sensor → más alto el número.

4. Mostrar lo que está pasando
   
```cpp
Serial.print("Sensor de Fuerza: ");
Serial.println(valorFuerza);
```
Esto sirve para ver si el sensor está vivo o no. En el Serial Monitor aparece algo como:
Sensor de Fuerza: 438
y ese número cambia según lo que presione.

5. Pausa para no saturar

```cpp
delay(500);
```
Le doy medio segundo de descanso al Arduino antes de la siguiente lectura.
Sin esto, los datos pasarían tan rápido que ni se verían.

