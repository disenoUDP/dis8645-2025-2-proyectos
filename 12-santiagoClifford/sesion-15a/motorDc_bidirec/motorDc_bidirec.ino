// Conexiones del driver L293D para un motor DC
int able = 3;
int input1 = 6;
int input2 = 7;

void setup() {
  // Colocando los pines en modo salida
  pinMode(able, OUTPUT); 
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT); 
}

void loop() {
  // Iniciamos con el motor detenido
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  delay(2000);
  
  // Máxima velocidad del motor 
  analogWrite(able, 255);
  
  // Encendemos el motor
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW); 
  delay(2000);
  
  // Invertimos el sentido del giro del motor
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);  
  delay(2000);
  
  // Apagamos el motor
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  delay(2000);
  
  // // Turn on motors
  // digitalWrite(input1, HIGH);
  // digitalWrite(input2, LOW);
    
  // // Aumenta la velocidad de cero a máximo
  // for (int i = 0; i < 256; i=i+1) {
  //   analogWrite(able, i);    
  //   delay(50);
  // }
  
  // // Disminuye la velocidad de máximo a cero
  // for (int i = 255; i >= 0; i=i-1) {
  //   analogWrite(able, i);  
  //   delay(50);
  // }
  
}
