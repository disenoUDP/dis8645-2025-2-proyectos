#define vibrador 2
void setup() {
pinMode(vibrador, OUTPUT);
}

void loop() {
  digitalWrite(vibrador, HIGH);
  delay(2000);
  digitalWrite(vibrador, LOW);
  delay(2000);
  digitalWrite(vibrador, HIGH);
  delay(2000);
  digitalWrite(vibrador, LOW);
  delay(2000);
  digitalWrite(vibrador, HIGH);
  delay(2000);
  digitalWrite(vibrador, LOW);
  delay(2000);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(500);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(500);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(500);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(0);
  digitalWrite(vibrador, HIGH);
  delay(3000);
  digitalWrite(vibrador, LOW);
  delay(0);
}

  

  