#include <Adafruit_NeoPixel.h>

// ===================== CONFIG ======================
// Pines y cantidad de LEDs de la matriz
#define PIN_MATRIZ 5
#define NUM_PIXELES 64

// Pines del joystick
#define PIN_JOYSTICK_X A0
#define PIN_JOYSTICK_Y A1
#define PIN_JOYSTICK_BOTON 2

// Pines de los botones
#define PIN_BOTON_MOV 3   // rompe un pixel al azar del cuadrado
#define PIN_BOTON_VEL 4   // velocidad música (solo trigger)
#define PIN_COLOR 7       // cambia color del pixel escapado
#define PIN_INICIO 6      // inicia el "rompe pixel"

Adafruit_NeoPixel matriz = Adafruit_NeoPixel(NUM_PIXELES, PIN_MATRIZ, NEO_GRB + NEO_KHZ800);

// ===================== VARIABLES ======================
// Forma base del cuadrado: 1 = LED encendido, 0 = apagado
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

bool formaBaseOriginal[64]; // guardamos el estado inicial del cuadrado

int pixelBloqueado = -1;     // pixel roto que no se puede mover
int pixelEscapado = -1;      // pixel que se puede mover con el joystick

uint32_t colorPixelEscapado = 0x00FFFF; // color del pixel escapado
bool modoDisco = false;                  // modo colores random

unsigned long tiempoUltimoMovimiento = 0;
const unsigned long retrasoMovimiento = 200; // velocidad de movimiento del pixel escapado
const unsigned long retrasoDisco = 80;       // velocidad del modo disco

// Contador de pixeles rotos
int pixelesRotos = 0;
const int maxPixelesRotos = 9;

// Timer de inactividad
unsigned long tiempoUltimaActividad = 0;

// ===================== FUNCIONES UTILES ======================
// Convertir índice 0-63 a coordenadas X y Y
int obtenerX(int i){ return i % 8; }
int obtenerY(int i){ return i / 8; }
// Convertir coordenadas X,Y a índice 0-63
int obtenerIndice(int x,int y){ return y * 8 + x; }

// Genera un color random que NO sea rojo fuerte
uint32_t generarColorNoRojo(){
  while(true){
    int r=random(0,256);
    int g=random(0,256);
    int b=random(0,256);
    if(!(r>200 && g<80 && b<80)) return matriz.Color(r,g,b);
  }
}

// ===================== DIBUJO ======================
// Dibuja la matriz en su estado normal
void dibujarMatrizNormal(){
  matriz.clear(); // apaga todo

  for(int i=0;i<64;i++){
    if(formaBase[i]==1) matriz.setPixelColor(i, matriz.Color(255,0,0)); // dibuja los pixeles del cuadrado
  }

  // dibuja pixel roto
  if(pixelBloqueado>=0) matriz.setPixelColor(pixelBloqueado, 0);
  // dibuja pixel escapado
  if(pixelEscapado>=0) matriz.setPixelColor(pixelEscapado, colorPixelEscapado);

  matriz.show(); // actualiza la matriz
}

// Dibuja la matriz en modo disco (colores random)
void dibujarMatrizDisco(){
  for(int i=0;i<64;i++){
    matriz.setPixelColor(i, generarColorNoRojo());
  }
  if(pixelEscapado>=0)
    matriz.setPixelColor(pixelEscapado, colorPixelEscapado);

  matriz.show();
}

// ===================== REPARAR CUADRADO ======================
// Devuelve el cuadrado a su estado inicial
void repararCuadrado(){
  for(int i=0;i<64;i++){
    formaBase[i] = formaBaseOriginal[i];
  }
  pixelBloqueado = -1;
  pixelEscapado = -1;
  pixelesRotos = 0;
  dibujarMatrizNormal();
}

// ===================== SETUP ======================
void setup(){
  matriz.begin();
  matriz.setBrightness(50);
  matriz.show();
  randomSeed(analogRead(A3)); // inicializa random

  // Configura botones y joystick
  pinMode(PIN_JOYSTICK_BOTON, INPUT_PULLUP);
  pinMode(PIN_INICIO, INPUT_PULLUP);
  pinMode(PIN_COLOR, INPUT_PULLUP);
  pinMode(PIN_BOTON_MOV, INPUT_PULLUP);
  pinMode(PIN_BOTON_VEL, INPUT_PULLUP);

  // Guarda estado inicial
  for(int i=0;i<64;i++){
    formaBaseOriginal[i] = formaBase[i];
  }

  tiempoUltimaActividad = millis(); // inicializa el timer de inactividad
  dibujarMatrizNormal();
}

// ===================== LOOP ======================
void loop(){

  // ================= REPARACIÓN AUTOMÁTICA POR INACTIVIDAD =================
  // Si pasan 15s sin tocar nada, se regenera el cuadrado
  if(millis() - tiempoUltimaActividad > 15000){
    repararCuadrado();
    tiempoUltimaActividad = millis(); // reinicia timer
  }

  // ================== BOTÓN INICIO ==================
  if(digitalRead(PIN_INICIO)==LOW){
    tiempoUltimaActividad = millis(); // actualiza timer de actividad

    int lados[64];
    int total = 0;
    for(int i=0;i<64;i++){
      if(formaBase[i]==1) lados[total++] = i;
    }

    if(total > 0){
      int elegido = lados[random(total)];
      pixelBloqueado = elegido;
      formaBase[pixelBloqueado] = 0;

      int x = obtenerX(elegido);
      int y = obtenerY(elegido);

      if(x < 7) pixelEscapado = obtenerIndice(x+1,y);
      else if(x > 0) pixelEscapado = obtenerIndice(x-1,y);
      else if(y < 7) pixelEscapado = obtenerIndice(x,y+1);
      else pixelEscapado = obtenerIndice(x,y-1);

      dibujarMatrizNormal();
    }
    delay(250); // evita que el botón se lea varias veces
  }

  // ================== BOTÓN COLOR ==================
  if (pixelEscapado>=0 && digitalRead(PIN_COLOR)==LOW){
    tiempoUltimaActividad = millis();
    colorPixelEscapado = generarColorNoRojo();
    dibujarMatrizNormal();
    delay(200);
  }

  // ================== BOTÓN 3: ROMPER PIXELES ==================
  if (digitalRead(PIN_BOTON_MOV) == LOW) {
    tiempoUltimaActividad = millis(); // actualizar timer

    int lados[64];
    int total = 0;
    for(int i=0;i<64;i++){
      if(formaBase[i]==1) lados[total++] = i;
    }

    if(pixelesRotos < maxPixelesRotos && total > 0){
      // rompe un pixel normal
      int elegido = lados[random(total)];
      pixelBloqueado = elegido;
      formaBase[pixelBloqueado] = 0;

      int x = obtenerX(elegido);
      int y = obtenerY(elegido);

      if(x < 7) pixelEscapado = obtenerIndice(x+1,y);
      else if(x > 0) pixelEscapado = obtenerIndice(x-1,y);
      else if(y < 7) pixelEscapado = obtenerIndice(x,y+1);
      else pixelEscapado = obtenerIndice(x,y-1);

      pixelesRotos++;
    }
    else if(pixelesRotos >= maxPixelesRotos){
      // reinicia cuadrado completo pero deja 1 pixel roto
      for(int i=0;i<64;i++){
        formaBase[i] = formaBaseOriginal[i];
      }

      int elegido = random(64);
      while(formaBase[elegido]==0) elegido = random(64);
      pixelBloqueado = elegido;
      formaBase[pixelBloqueado] = 0;

      int x = obtenerX(elegido);
      int y = obtenerY(elegido);

      if(x < 7) pixelEscapado = obtenerIndice(x+1,y);
      else if(x > 0) pixelEscapado = obtenerIndice(x-1,y);
      else if(y < 7) pixelEscapado = obtenerIndice(x,y+1);
      else pixelEscapado = obtenerIndice(x,y-1);

      pixelesRotos = 1; // reinicia contador
    }

    dibujarMatrizNormal();
    delay(250);
  }

  // ================== BOTÓN 4 (velocidad música) ==================
  if(digitalRead(PIN_BOTON_VEL)==LOW){
    tiempoUltimaActividad = millis();
    delay(200);
  }

  // ================== MODO DISCO ==================
  static int ultimo = HIGH;
  int ahora = digitalRead(PIN_JOYSTICK_BOTON);

  if(ultimo==HIGH && ahora==LOW){
    modoDisco = !modoDisco;
    tiempoUltimaActividad = millis();
    delay(200);
  }
  ultimo = ahora;

  if(modoDisco){
    tiempoUltimaActividad = millis();
    dibujarMatrizDisco();
    delay(retrasoDisco);
    return;
  }

  // ================== MOVER PIXEL ESCAPADO ==================
  if(pixelEscapado >= 0){

    int valorX = analogRead(PIN_JOYSTICK_X);
    int valorY = analogRead(PIN_JOYSTICK_Y);

    if(millis() - tiempoUltimoMovimiento >= retrasoMovimiento){

      int x = obtenerX(pixelEscapado);
      int y = obtenerY(pixelEscapado);
      int xOriginal = x;
      int yOriginal = y;

      // movimiento con joystick
      if(valorX > 800 && x>0) x--;
      else if(valorX < 200 && x<7) x++;

      if(valorY > 800 && y>0) y--;
      else if(valorY < 200 && y<7) y++;

      if(x != xOriginal || y != yOriginal){
        tiempoUltimaActividad = millis(); // actualiza timer si se mueve
      }

      int nueva = obtenerIndice(x,y);
      if(nueva != pixelBloqueado) pixelEscapado = nueva;

      dibujarMatrizNormal();
      tiempoUltimoMovimiento = millis();
    }
  }
}