# 🌷 sesion-14b
Viernes 14 de noviembre de 2025 

## 🪩 Apuntes de la clase 
- Lenguajes que se usan en las terminales se llama bash

## Avance del proyecto 3

### Manifiesto




## Conexión con el sensor de fuerza 

### Conexión datos de Arduino con Touchdesigner 
Primero se debe elegir el protocolo de comunicación adecuado, este puede ser:
- **Comunicación serial:** para comunicaciones DAT seriales de TD.
- **OSC (Open Sound Control):** ideal para arte generativo en tiempo real. Baja latencia.
- **MIDI:** ideal para proyectos con música o sonidos.
- **Websocket:** protocolo de comunicación bidireccional, ideal para proyectos conectados a internet como una página web.

Una vez elegido, en este caso usaré OSC ya que es especial para animaciones generativas y arduino.

### Código de Arduino para el sensor de fuerza
Este código fue sacado del siguiente video, donde explicaban paso a paso el funcionamiento y programación del sensor (https://www.youtube.com/watch?v=U-N7nR5EEHs)

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

### Conectando datos entre arduino y TD
1. crear un nodo DAT Serial - Serial1_Callbacks.
2. active: on.
3. port: usbmodem... que es el nombre del Arduino que está conecatdo a nuestro computador.
4. baud rate: 9600 este debe coincidir con el puerto serial que configuramos en arduino.

(insertar foto de los nodos de td)

### Asignación de entradas de Arduino a elementos visuales de Touchdesigner 
1. configurar DAT serial, mencionado y explicado en el apartado anterior.
2. crear un DAT in CHOP para convertir los datos en canales y poder crear las animaciones.
3. agregar un CHOP Math para escalar los datos a un rango utilizable. En este caso el sensor de fuerza va de 0 a 1000.
4. conectar la salida del Math a una Sphere para que controle parámetros como radio, posición o color con los datos del sensor de fuerza.
