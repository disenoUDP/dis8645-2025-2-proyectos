const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
 
bool presenciaUsuario = false;
bool brazoAmor = false;
 
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}


void loop() {
  digitalWrite(Trigger, HIGH);
delayMicroseconds(10);          //Enviamos un pulso de 10us
digitalWrite(Trigger, LOW);
 long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
 
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(100);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(1000); 
  
if (d < 20) { 
    presenciaUsuario = true;
  } else {
    presenciaUsuario = false;
  }
  
  // Lógica para brazoAmor (activación a menos de 5 cm)
  if (d < 10) { 
    brazoAmor = true;
  } else {
    brazoAmor = false;
  }

  if (presenciaUsuario) {
    Serial.println("presenciaUsuario se ha prendido.");
  }

  if (brazoAmor == true) {
    Serial.println("brazoAmor se ha prendido.");
  }

  Serial.println();
  delay(100); // Pausa de 100ms
}

