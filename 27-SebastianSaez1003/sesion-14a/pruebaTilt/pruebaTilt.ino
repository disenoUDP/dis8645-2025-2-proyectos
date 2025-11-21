// establecer el pin que sera conectado 
// el sensor para obtener su dato
int pinSensor = 8;
// crear una variable booleana para establecer 
// si hay inclinacion o no presente
bool parado;

// lo que es necesario para los funcionamientos en void loop
void setup() 
{
// establecer que el pin llamado pinSensor va a ser un input
  pinMode(pinSensor,INPUT);
// comenzar la comunicacion serial
  Serial.begin(9600);
}

// aqui ocurre todos los funcionamientos del codigo
void loop() 
{
  // si se recibe una señal desde el pinSensor
  if(digitalRead(pinSensor))
  {
    // significa que esta de lado
    parado = false;
     }
      else {
      // sino significa que esta parado
      parado = true;
       }

// si es que esta parado
if (parado){
  Serial.println("estoy hacia arriba");
  Serial.println(parado);
  delay(1000);
}
// si es que no esta parado
else if (!parado){
  Serial.println("estoy de lado");
  Serial.println(parado);
  delay(1000);
  }
}