int rangoEncoder = 0;
int leerEncoder = 2;

// Declaración de pines
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

void setup() {
  // Configurar los pines como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  rangoEncoder = leerEncoder;
  
  if (rangoEncoder == 1){
    digitalWrite(led1, HIGH);
  }
  else if (rangoEncoder == 2){
    digitalWrite(led2, HIGH);
  }
  else if (rangoEncoder == 3){
    digitalWrite(led3, HIGH);
  }
  else if (rangoEncoder == 4){
    digitalWrite(led4, HIGH);
  }
  else if (rangoEncoder == 5){
    finalDeLuces(5);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  
}

void finalDeLuces(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(500);
   digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(500);
}
