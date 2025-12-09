
int pinDePresion; 
int valorDePresion;
bool watitaRascada;
int presionMinimaAceptable;

void setup() {
  // put your setup code here, to run once:
  pinDePresion = A0;
  valorDePresion = 0;
  watitaRascada = false;
  //hay q calibrar la presion/revisar cableado
  int presionMinimaAceptable = 200;
  pinMode(pinDePresion, INPUT);   
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 valorDePresion = analogRead(pinDePresion);
 Serial.println(valorDePresion);
}
