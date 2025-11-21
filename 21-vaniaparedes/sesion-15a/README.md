# sesion-15a 18.11.25

## Proyecto 03
trabajo en el código

Menos brillo en la pantalla porque era muy brillante
- Añadiendo esto en void setup:

```cpp
matriz.setBrightness(50);   // <<< ajuste de brillo
```

### Referente De carcasa

![IMG1](./imagenes/Referente.png)

### Ideas de canciones para juego y modo disco:

- link de donde se saco: <https://opengameart.org/content/darker-waves> Author: 
Zander Noriega - Licencia CC-BY 3.0 "puedes usar la obra libremente incluso comercialmente, SIEMPRE que des creditos al autor"

- retro arcade game music de MFCC De uso gratuito bajo la Licencia de contenido de Pixabay <https://pixabay.com/es/music/optimista-retro-arcade-game-music-297305/>

### Código trabajado en clase

Añadimos el terecer botón encargado de hacer que se desaparezcan más pixeles y que luego de 10 segundos de no tocarlo vuelve a como estaba antes (sigue la matáfora de si no haces nada se arregla)

```cpp
#include <Adafruit_NeoPixel.h>

// ===================== CONFIG ======================
#define PIN_MATRIZ 6
#define NUM_PIXELES 64

#define PIN_JOYSTICK_X A0
#define PIN_JOYSTICK_Y A1
#define PIN_JOYSTICK_BOTON 2

#define PIN_BOTON_MOV 3   // rompe un pixel al azar del cuadrado
#define PIN_BOTON_VEL 4   // velocidad música (solo trigger)
#define PIN_BOTON_EXTRA 5 // no hace nada

#define PIN_COLOR 9
#define PIN_INICIO 8

Adafruit_NeoPixel matriz = Adafruit_NeoPixel(NUM_PIXELES, PIN_MATRIZ, NEO_GRB + NEO_KHZ800);

// ===================== VARIABLES ======================
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

// TIMER DE INACTIVIDAD
unsigned long tiempoUltimaActividad = 0;
const unsigned long tiempoReparacion = 30000; // 30 segundos

// ===================== UTILES ======================
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

// ===================== DIBUJO ======================
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

  if(pixelEscapado>=0)
    matriz.setPixelColor(pixelEscapado, colorPixelEscapado);

  matriz.show();
}

// ===================== REPARAR CUADRADO ======================
void repararCuadrado(){
  for(int i=0;i<64;i++){
    formaBase[i] = formaBaseOriginal[i];
  }
  pixelBloqueado = -1;
  pixelEscapado = -1;
  dibujarMatrizNormal();
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
  pinMode(PIN_BOTON_MOV, INPUT_PULLUP);
  pinMode(PIN_BOTON_VEL, INPUT_PULLUP);
  pinMode(PIN_BOTON_EXTRA, INPUT_PULLUP);

  for(int i=0;i<64;i++){
    formaBaseOriginal[i] = formaBase[i];
  }

  tiempoUltimaActividad = millis();
  dibujarMatrizNormal();
}

// ===================== LOOP ======================
void loop(){

  // ========== REPARACIÓN POR INACTIVIDAD ==========
  if (!modoDisco && millis() - tiempoUltimaActividad > tiempoReparacion){
    repararCuadrado();
  }

  // ========== A LOS 15 SEG DESPUÉS DE USAR EL BOTÓN DEL PIN 3 ==========
  // igual que antes de iniciar un juego
  if(pixelEscapado < 0 && pixelBloqueado < 0 &&
     (millis() - tiempoUltimaActividad > 15000)) {   // 15seg

    tiempoUltimaActividad = millis(); // reinicia timer

    int lados[64];
    int total = 0;

    // mismos bordes que tu botón PIN_INICIO
    for(int i=0;i<64;i++){
      if(formaBase[i]==1)
        lados[total++] = i;
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
  }

  // ================== BOTÓN INICIO ==================
  if(pixelEscapado < 0 && digitalRead(PIN_INICIO)==LOW){

    tiempoUltimaActividad = millis();

    int lados[64];
    int total = 0;

    for(int i=0;i<64;i++){
      if(formaBase[i]==1)
        lados[total++] = i;
    }

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
    delay(250);
  }

  // ================== BOTÓN COLOR ==================
  if (pixelEscapado>=0 && digitalRead(PIN_COLOR)==LOW){
    tiempoUltimaActividad = millis();
    colorPixelEscapado = generarColorNoRojo();
    dibujarMatrizNormal();
    delay(200);
  }

  // ================== BOTÓN 3: ROMPER CUALQUIER PIXEL ==================
  if (digitalRead(PIN_BOTON_MOV)==LOW){

    tiempoUltimaActividad = millis();

    int lados[64];
    int total = 0;

    for(int i=0;i<64;i++){
      if(formaBase[i]==1)
        lados[total++] = i;
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
      delay(250);
    }
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

      if(valorX > 800 && x>0) x--;
      else if(valorX < 200 && x<7) x++;

      if(valorY > 800 && y>0) y--;
      else if(valorY < 200 && y<7) y++;

      if(x != xOriginal || y != yOriginal){
        tiempoUltimaActividad = millis();
      }

      int nueva = obtenerIndice(x,y);

      if(nueva != pixelBloqueado)
        pixelEscapado = nueva;

      dibujarMatrizNormal();
      tiempoUltimoMovimiento = millis();
    }
  }
}

```
