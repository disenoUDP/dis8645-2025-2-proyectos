#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

// ===================== CONFIG NEOPIXEL ======================
#define PIN_MATRIZ 13
#define NUM_PIXELES 64

#define PIN_JOYSTICK_X A0
#define PIN_JOYSTICK_Y A1
#define PIN_JOYSTICK_BOTON 8

#define PIN_BOTON_COMELON 9
#define PIN_BOTON_VEL 10
#define PIN_COLOR 7
#define PIN_INICIO 6

#define PIN_TRIGGER_MP3 A3 // Pin que envía pulso al Arduino receptor

Adafruit_NeoPixel matriz = Adafruit_NeoPixel(NUM_PIXELES, PIN_MATRIZ, NEO_GRB + NEO_KHZ800);

// ===================== VARIABLES PRINCIPALES ======================
bool formaBase[64] = {
 0,0,0,0,0,0,0,0,
 0,1,1,1,1,1,1,0,
 0,1,0,0,0,0,1,0,
 0,1,0,0,0,0,1,0,
 0,1,0,0,0,0,1,0,
 0,1,0,0,0,0,1,0,
 0,1,1,1,1,1,1,0,
 0,0,0,0,0,0,0,0
};

bool formaBaseOriginal[64];
int pixelBloqueado = -1;
int pixelEscapado = -1;
uint32_t colorPixelEscapado = 0x00FFFF;
bool modoDisco = false;

unsigned long tiempoUltimoMovimiento = 0;
const unsigned long retrasoMovimiento = 200;
const unsigned long retrasoDisco = 80;

int pixelesRotos = 0;
const int maxPixelesRotos = 9;
unsigned long tiempoUltimaActividad = 0;
bool juegoIniciado = false;

// ===================== CONFIG LCD ======================
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define PIN_BACKLIGHT 5

// Mensajes LCD
String linea1 = "VEN, ACERCATE";
String linea2 = "Y JUEGA";

// Parpadeo solo para otros mensajes
bool modoParpadeo = false; 
unsigned long lastBlink = 0;
unsigned long blinkInterval = 300;
bool visible = true;

// ===================== FUNCIONES UTILES ======================
int obtenerX(int i){ return i % 8; }
int obtenerY(int i){ return i / 8; }
int obtenerIndice(int x,int y){ return y * 8 + x; }

uint32_t generarColorNoRojo(){
  while(true){
    int r=random(0,256);
    int g=random(0,256);
    int b=random(0,256);
    if(!(r>200 && g<80 && b<80)) return matriz.Color(r,g,b);
  }
}

// ===================== DIBUJO NEOPIXEL ======================
void dibujarMatrizNormal(){
  matriz.clear();
  for(int i=0;i<64;i++){
    if(formaBase[i]==1) matriz.setPixelColor(i, matriz.Color(255,0,0));
  }
  if(pixelBloqueado>=0) matriz.setPixelColor(pixelBloqueado, 0);
  if(pixelEscapado>=0) matriz.setPixelColor(pixelEscapado, colorPixelEscapado);
  matriz.show();
}

void dibujarMatrizDisco(){
  for(int i=0;i<64;i++){
    matriz.setPixelColor(i, generarColorNoRojo());
  }
  if(pixelEscapado>=0) matriz.setPixelColor(pixelEscapado, colorPixelEscapado);
  matriz.show();
}

// ===================== REPARAR CUADRADO ======================
void repararCuadrado(){
  for(int i=0;i<64;i++){
    formaBase[i] = formaBaseOriginal[i];
  }
  pixelBloqueado = -1;
  pixelEscapado = -1;
  pixelesRotos = 0;
  juegoIniciado = false;
  dibujarMatrizNormal();
}

// ===================== FUNCIONES LCD ======================
void actualizarLCD(String msg1, String msg2, bool parpadeo=false){
  linea1 = msg1;
  linea2 = msg2;
  modoParpadeo = parpadeo;
  lcd.clear();
}

void mostrarLCD(){
  if(modoParpadeo){
    if(millis() - lastBlink >= blinkInterval){
      lastBlink = millis();
      visible = !visible;
    }
    lcd.clear();
    if(visible){
      lcd.setCursor(0,0);
      lcd.print(linea1.substring(0, min(16, (int)linea1.length())));
      lcd.setCursor(0,1);
      lcd.print(linea2.substring(0, min(16, (int)linea2.length())));
    }
  } else {
    lcd.setCursor(0,0);
    lcd.print(linea1.substring(0, min(16, (int)linea1.length())));
    lcd.setCursor(0,1);
    lcd.print(linea2.substring(0, min(16, (int)linea2.length())));
  }
}

// ===================== SETUP ======================
void setup(){
  matriz.begin();
  matriz.setBrightness(50);
  matriz.show();
  randomSeed(analogRead(A3));

  pinMode(PIN_JOYSTICK_BOTON, INPUT_PULLUP);
  pinMode(PIN_INICIO, INPUT_PULLUP);
  pinMode(PIN_COLOR, INPUT_PULLUP);
  pinMode(PIN_BOTON_COMELON, INPUT_PULLUP);
  pinMode(PIN_BOTON_VEL, INPUT_PULLUP);
  pinMode(PIN_BACKLIGHT, OUTPUT);

  pinMode(PIN_TRIGGER_MP3, OUTPUT);
  digitalWrite(PIN_TRIGGER_MP3, LOW); // Inicialmente LOW

  analogWrite(PIN_BACKLIGHT, 255);

  for(int i=0;i<64;i++){
    formaBaseOriginal[i] = formaBase[i];
  }

  tiempoUltimaActividad = millis();
  dibujarMatrizNormal();
  
  // Config LCD
  lcd.begin(16,2);
  
  // MOSTRAR MENSAJE ESTATICO DE BIENVENIDA
  actualizarLCD("VEN, ACERCATE…", "podrias divertirte", false); // <- mensaje estático
  mostrarLCD(); // Se muestra inmediatamente
}

// ===================== LOOP ======================
void loop(){
  if(millis() - tiempoUltimaActividad > 15000){
    repararCuadrado();
    tiempoUltimaActividad = millis();
  }

  // ================== BOTÓN INICIO ==================
  if(digitalRead(PIN_INICIO)==LOW && !juegoIniciado){
    tiempoUltimaActividad = millis(); 
    juegoIniciado = true;
    actualizarLCD("Ahora intenta","arreglarme", false);

    int lados[64], total=0;
    for(int i=0;i<64;i++) if(formaBase[i]==1) lados[total++] = i;
    if(total>0){
      int elegido=lados[random(total)];
      pixelBloqueado=elegido;
      formaBase[pixelBloqueado]=0;
      int x=obtenerX(elegido), y=obtenerY(elegido);
      if(x<7) pixelEscapado=obtenerIndice(x+1,y);
      else if(x>0) pixelEscapado=obtenerIndice(x-1,y);
      else if(y<7) pixelEscapado=obtenerIndice(x,y+1);
      else pixelEscapado=obtenerIndice(x,y-1);
      dibujarMatrizNormal();
    }

    // ================== PULSO AL MP3 ==================
    digitalWrite(PIN_TRIGGER_MP3, HIGH);
    delay(100);   // 100 ms
    digitalWrite(PIN_TRIGGER_MP3, LOW);

    delay(250);
  }

  // ================== BOTÓN COMELON ==================
  if(digitalRead(PIN_BOTON_COMELON)==LOW){
    tiempoUltimaActividad = millis();
    int opcion = random(3);
    if(opcion==0) actualizarLCD("No debiste","hacer eso", false);
    else if(opcion==1) actualizarLCD("upps, deberias","pensarlo mejor", false);
    else actualizarLCD("ese boton no","es el mejor", false);

    int lados[64], total=0;
    for(int i=0;i<64;i++) if(formaBase[i]==1) lados[total++] = i;

    if(pixelesRotos < maxPixelesRotos && total>0){
      int elegido = lados[random(total)];
      pixelBloqueado = elegido;
      formaBase[pixelBloqueado] = 0;
      int x=obtenerX(elegido), y=obtenerY(elegido);
      if(x<7) pixelEscapado=obtenerIndice(x+1,y);
      else if(x>0) pixelEscapado=obtenerIndice(x-1,y);
      else if(y<7) pixelEscapado=obtenerIndice(x,y+1);
      else if(y>0) pixelEscapado=obtenerIndice(x,y-1);
      pixelesRotos++;
    } else if(pixelesRotos>=maxPixelesRotos){
      for(int i=0;i<64;i++) formaBase[i]=formaBaseOriginal[i];
      int elegido=random(64);
      while(formaBase[elegido]==0) elegido=random(64);
      pixelBloqueado=elegido;
      formaBase[pixelBloqueado]=0;
      int x=obtenerX(elegido), y=obtenerY(elegido);
      if(x<7) pixelEscapado=obtenerIndice(x+1,y);
      else if(x>0) pixelEscapado=obtenerIndice(x-1,y);
      else if(y<7) pixelEscapado=obtenerIndice(x,y+1);
      else if(y>0) pixelEscapado=obtenerIndice(x,y-1);
      pixelesRotos=1;
    }
    dibujarMatrizNormal();
    delay(250);
  }

  // ================== BOTÓN COLOR ==================
  if(pixelEscapado>=0 && digitalRead(PIN_COLOR)==LOW){
    tiempoUltimaActividad = millis();
    colorPixelEscapado=generarColorNoRojo();
    actualizarLCD("No debiste","hacer eso", false);
    dibujarMatrizNormal();
    delay(200);
  }

  // ================== BOTÓN VEL ==================
  if(digitalRead(PIN_BOTON_VEL)==LOW){
    tiempoUltimaActividad = millis();
    int opcion=random(3);
    if(opcion==0) actualizarLCD("No debiste","hacer eso", false);
    else if(opcion==1) actualizarLCD("upps, deberias","pensarlo mejor", false);
    else actualizarLCD("ese boton no","es el mejor", false);
    delay(200);
  }

  // ================== MODO DISCO ==================
  static int ultimo=HIGH;
  int ahora = digitalRead(PIN_JOYSTICK_BOTON);
  if(ultimo==HIGH && ahora==LOW){
    modoDisco=!modoDisco;
    tiempoUltimaActividad=millis();
    if(modoDisco) actualizarLCD("NO ES MOMENTO","DE DIVERTIRSE", false);
    delay(200);
  }
  ultimo=ahora;

  if(modoDisco){
    tiempoUltimaActividad=millis();
    dibujarMatrizDisco();
    mostrarLCD();
    delay(retrasoDisco);
    return;
  }

  // ================== MOVER PIXEL ESCAPADO ==================
  if(pixelEscapado>=0){
    int valorX=analogRead(PIN_JOYSTICK_X);
    int valorY=analogRead(PIN_JOYSTICK_Y);

    if(millis()-tiempoUltimoMovimiento>=retrasoMovimiento){
      int x=obtenerX(pixelEscapado), y=obtenerY(pixelEscapado);
      int xOriginal=x, yOriginal=y;

      if(valorX>800 && x>0) x--;
      else if(valorX<200 && x<7) x++;
      if(valorY>800 && y>0) y--;
      else if(valorY<200 && y<7) y++;

      if(x!=xOriginal || y!=yOriginal) tiempoUltimaActividad=millis();
      int nueva=obtenerIndice(x,y);
      if(nueva!=pixelBloqueado) pixelEscapado=nueva;

      dibujarMatrizNormal();
      tiempoUltimoMovimiento=millis();
    }
  }

  mostrarLCD();
}
