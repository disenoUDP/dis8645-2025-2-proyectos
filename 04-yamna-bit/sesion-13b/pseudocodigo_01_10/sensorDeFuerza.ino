// Aqui se configura el sensor de fuerza y se define sus variables

//https://afel.cl/products/sensor-de-fuerza-presion-fsr402

// Sensor FSR402 conectado a 5V, GND y al pin analógico A0

// Pin donde se lee el sensor

#define PIN_SENSOR A0 

// Rangos de interacción min y max 
int apretarMin = x;     
int apretarMax = x;  

int estirarMin = x;    
int estirarMax = x;    

int acariciarMin = x;  
int acariciarMax = x;  

// Inicia comunicación serial para ver valores en el monitor
void setup() {
  Serial.begin(9600);   
}

void loop() {
  int valor = analogRead(PIN_SENSOR);  // Lee el valor actual del sensor
  Serial.println(valor);               // Muestra el valor del sensor en pantalla

// Si el valor está dentro del rango de "apretar", ejecuta esta acción
  if (valor >= apretarMin && valor <= apretarMax) {

  // Muestra la acción
    Serial.println("Apretar");  

  // Pausa por 15 segundos     
    delay(15000);                      
  }

  // Si el valor está dentro del rango de "estirar", ejecuta esta acción
  if (valor >= estirarMin && valor <= estirarMax) {

  // Muestra la acción
    Serial.println("Estirar");

  // Pausa por 15 segundos  
    delay(15000);
  }

  // Si el valor está dentro del rango de "acariciar", ejecuta esta acción
  if (valor >= acariciarMin && valor <= acariciarMax) {

  // Muestra la acción
    Serial.println("Acariciar");

  // Pausa por 15 segundos  
    delay(15000);
  }

  // Pausa antes de la siguiente lectura del sensor
  delay(500);
}

