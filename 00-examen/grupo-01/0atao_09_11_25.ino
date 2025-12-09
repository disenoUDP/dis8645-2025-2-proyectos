#include <Adafruit_NeoPixel.h>   // Librería para controlar la matriz LED NeoPixel
#include <LiquidCrystal.h>       // Librería para manejar el display LCD

// ===================== CONFIG NEOPIXEL ======================
// Pin donde está conectada la matriz LED
#define PIN_MATRIZ 13
// Cantidad total de LEDs (8x8 = 64)
#define NUM_PIXELES 64

// Pines del joystick: ejes X/Y y su botón
#define PIN_JOYSTICK_X A0
#define PIN_JOYSTICK_Y A1
#define PIN_JOYSTICK_BOTON 8

// Pines de botones externos
#define PIN_BOTON_COMELON 9   // Botón que rompe parte de la figura
#define PIN_BOTON_CAOS 10     // Botón que mezcla/desordena la figura
#define PIN_COLOR 7           // Cambia color del pixel escapado
#define PIN_INICIO 6          // Inicia el juego

// Pin para enviar un pulso al Arduino esclavo (música)
#define PIN_TRIGGER_MP3 A3      

// Objeto NeoPixel que controla la matriz completa
Adafruit_NeoPixel matriz = Adafruit_NeoPixel(NUM_PIXELES, PIN_MATRIZ, NEO_GRB + NEO_KHZ800);

// ===================== VARIABLES PRINCIPALES ======================
// Figura inicial: un cuadrado 8x8 con un hueco interior
// 1 = LED encendido (forma parte del cuadrado)
// 0 = LED apagado
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

bool formaBaseOriginal[64];   // Copia del cuadrado perfecto para restaurarlo mas adelante
int pixelBloqueado = -1;      // LED interno removido (de dode se escapa uno)
int pixelEscapado = -1;       // LED que “escapa” y se mueve por la matriz
uint32_t colorPixelEscapado = 0xFF0000;  // Color del pixel escapado (inicialmente rojo)
bool modoDisco = false;       // Para activar el modo disco

// Tiempos para animación del pixel escapado
unsigned long tiempoUltimoMovimiento = 0;       // Último avance del pixel
const unsigned long retrasoMovimiento = 200;    // Velocidad de movimiento normal
const unsigned long retrasoDisco = 80;          // Velocidad más rápida del modo disco

// Control de destrucción de la figura
int pixelesRotos = 0;                // Cuántos pixel se han roto
const int maxPixelesRotos = 9;       // Máximo 9 comidos antes de reinicio

// Control de actividad para autoreinicio
unsigned long tiempoUltimaActividad = 0;   // Última vez que se tocó algo
bool juegoIniciado = false;                // Para evitar reinicios antes de empezar

// ===================== CONFIG LCD ======================
// Objeto LCD 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define PIN_BACKLIGHT 5   // luz de fondo de la pantallita lcd

// Líneas a mostrar en la pantalla
String linea1 = "V3N, ACERC4T3";
String linea2 = "Y JuEG4";

// Control del parpadeo del texto
bool modoParpadeo = false;     // True = texto parpadea
unsigned long lastBlink = 0;   // Último cambio de visibilidad
unsigned long blinkInterval = 300;  // Velocidad del parpadeo
bool visible = true;           // Determina si el texto se muestra o no

// ===================== FUNCIONES UTILES ======================
// Obtienen coordenadas dentro de la matriz NeoPixel (8x8)

// % entrega el resto de dividir i por 8: indica la columna
int obtenerX(int i){ return i % 8; }          

// División entera de i entre 8: indica la fila 
int obtenerY(int i){ return i / 8; }          

// Convierte coordenadas (x,y) en índice lineal: fila*8 + columna
int obtenerIndice(int x,int y){ return y * 8 + x; }


// Genera un color aleatorio que NO sea rojo puro (para estresar más)
uint32_t generarColorNoRojo(){
  while(true){
    int r=random(0,256);
    int g=random(0,256);
    int b=random(0,256);
    // Se descarta si es rojo
    if(!(r>200 && g<80 && b<80)) return matriz.Color(r,g,b);
  }
}

// ===================== DIBUJO NEOPIXEL ======================
// Dibuja la figura normal + el pixel bloqueado + pixel escapado
void dibujarMatrizNormal(){
  matriz.clear();  // Limpia todos los LEDs

  // Pinta el cuadrado con rojo
  for(int i=0;i<64;i++){
    if(formaBase[i]==1) matriz.setPixelColor(i, matriz.Color(255,0,0));
  }

  // Borra el pixel bloqueado (así no tiene color y queda como agujero)
  if(pixelBloqueado>=0) matriz.setPixelColor(pixelBloqueado, 0);

  // Pinta el pixel escapado con su color asignado
  if(pixelEscapado>=0) matriz.setPixelColor(pixelEscapado, colorPixelEscapado);

  matriz.show();  // Refresca la matriz
}

// Dibujo en modo disco: todos los LEDs son colores random que pestañean
void dibujarMatrizDisco(){
  for(int i=0;i<64;i++){
    matriz.setPixelColor(i, generarColorNoRojo());
  }

  // Pixel escapado mantiene su color original
  if(pixelEscapado>=0) matriz.setPixelColor(pixelEscapado, colorPixelEscapado);

  matriz.show(); //pantallita pantallea
}

// ===================== REPARAR CUADRADO ======================
// Restaura todo el estado a su versión inicial
void repararCuadrado(){
  for(int i=0;i<64;i++){
    formaBase[i] = formaBaseOriginal[i];  // Restaurar figura original (cuadrado perfecto)
  }
  pixelBloqueado = -1;
  pixelEscapado = -1;
  pixelesRotos = 0;
  juegoIniciado = false;

  dibujarMatrizNormal();
}

// ===================== FUNCIONES LCD ======================
// Actualiza el contenido mostrado y si parpadea o no
void actualizarLCD(String msg1, String msg2, bool parpadeo=false){
  linea1 = msg1;
  linea2 = msg2;
  modoParpadeo = parpadeo;
  lcd.clear();
}

// Muestra texto normal o parpadeando
// Render del LCD (con parpadeo opcional)
void mostrarLCD(){
  if(modoParpadeo){
    // Control de parpadeo
    if(millis() - lastBlink >= blinkInterval){
      lastBlink = millis();
      visible = !visible;
    }

    lcd.clear();
    
    if(visible){
      // Imprime respetando el límite de 16 caracteres
      lcd.setCursor(0,0);
      lcd.print(linea1.substring(0, min(16, (int)linea1.length())));
      lcd.setCursor(0,1);
      lcd.print(linea2.substring(0, min(16, (int)linea2.length())));
    }
  } else {
    // Modo estático
    lcd.setCursor(0,0);
    lcd.print(linea1.substring(0, min(16, (int)linea1.length())));
    lcd.setCursor(0,1);
    lcd.print(linea2.substring(0, min(16, (int)linea2.length())));
  }
}

// ===================== SETUP ======================
void setup(){

  Serial.begin(9600);
    Serial.print("hola");

  matriz.begin();            // Inicializa la matriz NeoPixel 
  matriz.setBrightness(40);  // Ajusta el brillo. (máx 255). 40 = brillo medio
  matriz.show();             // pantallea
  randomSeed(analogRead(A3)); // Genera una semilla aleatoria, para que los números aleatorios no se repitan siempre

  // Configuración de botones y entradas
  pinMode(PIN_JOYSTICK_BOTON, INPUT_PULLUP);
  pinMode(PIN_INICIO, INPUT_PULLUP);
  pinMode(PIN_COLOR, INPUT_PULLUP);
  pinMode(PIN_BOTON_COMELON, INPUT_PULLUP);
  pinMode(PIN_BOTON_CAOS, INPUT_PULLUP);
  pinMode(PIN_BACKLIGHT, OUTPUT);

  // Señal del MP3 (apagado por defecto)
  pinMode(PIN_TRIGGER_MP3, OUTPUT);
  digitalWrite(PIN_TRIGGER_MP3, LOW);

  // Encender luz del LCD al máximo
  analogWrite(PIN_BACKLIGHT, 255);

  // Copia de respaldo de la figura original
  for(int i=0;i<64;i++){
    formaBaseOriginal[i] = formaBase[i];
  }

  dibujarMatrizNormal();

  // Configuración del LCD
  lcd.begin(16,2);

  // Mensaje inicial del juego
  actualizarLCD("VEN, ACéRCATE…", "poDRIas diVertirte", false);
  mostrarLCD();
}

// ===================== LOOP PRINCIPAL ======================
void loop(){
 
  // Si pasan 15 segundos sin tocar nada → todo vuelve a su estado inicial
// ================== AUTO-RESET POR INACTIVIDAD ==================


  // ================== BOTÓN INICIO ==================
  // Primer paso del juego: romper un pixel y liberar el escapado
  if(digitalRead(PIN_INICIO)==LOW && !juegoIniciado){
    juegoIniciado = true;

    actualizarLCD("AH0ra Intent!","arregLxrm3", false);
    mostrarLCD();


    // Obtiene todos los píxeles encendidos para elegir uno al azar
    int lados[64], total=0;
    for(int i=0;i<64;i++) if(formaBase[i]==1) lados[total++] = i;

    // Selección aleatoria de pixel a romper
    if(total>0){
      int elegido=lados[random(total)];
      pixelBloqueado=elegido;
      formaBase[pixelBloqueado]=0;

      // Genera pixel escapado en un vecino 
      int x=obtenerX(elegido), y=obtenerY(elegido);
      if(x<7) pixelEscapado=obtenerIndice(x+1,y);
      else if(x>0) pixelEscapado=obtenerIndice(x-1,y);
      else if(y<7) pixelEscapado=obtenerIndice(x,y+1);
      else pixelEscapado=obtenerIndice(x,y-1);

      dibujarMatrizNormal();
    }

    // Pulso al otro arduino para activar la música
    digitalWrite(PIN_TRIGGER_MP3, HIGH);
    delay(100);
    digitalWrite(PIN_TRIGGER_MP3, LOW);

    delay(250);
  }

  // ================== BOTÓN COMELON ==================
  // Rota y destruye píxeles del cuadrado de forma adicional
  if(digitalRead(PIN_BOTON_COMELON)==LOW){
    tiempoUltimaActividad = millis();

    // Frases aleatorias para el LCD
    int opcion = random(3);
    if(opcion==0) actualizarLCD("N0 deB1st3","hacer es0", false);
    else if(opcion==1) actualizarLCD("uppss, deberí4s","p3nsarl0 mej0r", false);
    else actualizarLCD("es3 botón n0","3s el mej0r", false);
    mostrarLCD();

    // Encuentra los píxeles activos actuales
    int lados[64], total=0;
    for(int i=0;i<64;i++) if(formaBase[i]==1) lados[total++] = i;

    // Si aún no llega al límite de destrucción y existen píxeles
   if(pixelesRotos < maxPixelesRotos && total > 0){

   // Elige un píxel aleatorio
   int elegido = lados[random(total)];

   pixelBloqueado = elegido;          // Guarda cuál píxel será roto
   formaBase[pixelBloqueado] = 0;     // Lo elimina de la forma (lo apaga)

   // Obtiene coordenadas del píxel elegido
   int x = obtenerX(elegido), y = obtenerY(elegido);

   // Define un píxel vecino para "escapar" según hacia dónde pueda moverse
   if(x < 7) 
    pixelEscapado = obtenerIndice(x + 1, y);      // Escapa a la derecha
   else if(x > 0) 
    pixelEscapado = obtenerIndice(x - 1, y);      // Escapa a la izquierda
   else if(y < 7) 
    pixelEscapado = obtenerIndice(x, y + 1);      // Escapa hacia abajo
   else if(y > 0) 
    pixelEscapado = obtenerIndice(x, y - 1);      // Escapa hacia arriba

   pixelesRotos++;   // Aumenta el conteo de píxeles destruidos
   }

    // Reinicio después de romper demasiado
    } else if(pixelesRotos>=maxPixelesRotos){

      // Reconstruye figura
      for(int i=0;i<64;i++) formaBase[i]=formaBaseOriginal[i];

      // Selecciona un nuevo pixel para romper
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
  // ================== BOTÓN COLOR ==================
  // Cambia color del pixel escapado y lo mueve a un lugar random
  if(pixelEscapado>=0 && digitalRead(PIN_COLOR)==LOW){

    colorPixelEscapado = generarColorNoRojo();  // Nuevo color aleatorio

    // Frases aleatorias
    int opc = random(3);
    if(opc==0) actualizarLCD("pa d0nd3 v4s?", "jajajaja", false);
    else if(opc==1) actualizarLCD("uy si c4si", "m3ntiraaa", false);
    mostrarLCD();

    // Nuevo movimiento aleatorio total
    int nuevoLugar = pixelEscapado;
    while(nuevoLugar == pixelEscapado){
      nuevoLugar = random(64);
    }
    pixelEscapado = nuevoLugar;

    dibujarMatrizNormal();
    delay(220);
  }

   // ================== BOTÓN CAOS ==================
   // Contador que registra cuántas veces se ha presionado el botón CAOS.
   // Es 'static' para que NO se reinicie en cada loop, solo cuando lo reseteamos.
   static int contadorCaos = 0;

   if(digitalRead(PIN_BOTON_CAOS)==LOW){
   // Marca actividad para evitar reinicio automático
    contadorCaos++;                     // Cuenta un nuevo click del botón CAOS


    // Frases LCD
    int opcion=random(3);
    if(opcion==0) actualizarLCD("N0 deb1st3","hacer es0", false);
    else if(opcion==1) actualizarLCD("uppss, deberí4s","p3nsarl0 mej0r", false);
    else actualizarLCD("es3 botón n0","3s el mej0r", false);
    mostrarLCD();

    // Mezcla por 4 clics
    if(contadorCaos < 5){
      bool nuevosPixeles[64];
      for(int i=0;i<64;i++) nuevosPixeles[i]=0;

      int listaActivos[64], total=0;
      for(int i=0;i<64;i++){
        if(formaBase[i]==1) listaActivos[total++]=i;
      }

      // Reubicar píxeles activos al azar sin repetir posiciones
      for(int i=0;i<total;i++){
        int destino = random(64);
        while(nuevosPixeles[destino]==1) destino = random(64);
        nuevosPixeles[destino]=1;
      }

      for(int i=0;i<64;i++) formaBase[i]=nuevosPixeles[i];

      dibujarMatrizNormal();
    }

    // Si es la 5ta vez, volver al estado normal con pixel escapado como antes
    else {
      contadorCaos = 0; // reset del contador
      for(int i=0;i<64;i++) formaBase[i]=formaBaseOriginal[i];
   // Mantener pixel bloqueado original
      formaBase[pixelBloqueado] = 0;

      dibujarMatrizNormal();
    }

    delay(300);
  }


  // ================== MODO DISCO (botón del joystick) ==================

static int ultimo = HIGH;                         
int ahora = digitalRead(PIN_JOYSTICK_BOTON);    
 // Detecta si pasó de no presionado (HIGH) a presionado (LOW)
 // evita múltiples activaciones en un mismo apretón
 if (ultimo == HIGH && ahora == LOW) {
    modoDisco = !modoDisco;      // Cambia el estado del modo disco
 

    if (modoDisco) 
        actualizarLCD("N0 ES M0M3NT0", "D3 DIV3RTIRS3", false); // Mensaje al activarse

    mostrarLCD();
    delay(200);  // Antirebote del botón
}

   // Si está en modo Disco, la matriz se vuelve fiesta y no se mueve el pixel escapado
   if (modoDisco) {
    dibujarMatrizDisco();  // Colores aleatorios
    mostrarLCD();
    delay(retrasoDisco);
}
// ================== MOVIMIENTO DEL PIXEL ESCAPADO ==================

   if(pixelEscapado >= 0){                     // Si hay un pixel activo que debe moverse
    int x = obtenerX(pixelEscapado),        // Convierte el índice actual del pixel a su coordenada X
        y = obtenerY(pixelEscapado);        // Convierte el índice actual del pixel a su coordenada Y

    int nueva = x, nuevaY = y;              // Copias iniciales donde se guardará la posición nueva

    int vX = analogRead(PIN_JOYSTICK_X);    // Lectura del eje X del joystick
    int vY = analogRead(PIN_JOYSTICK_Y);    // Lectura del eje Y del joystick
    
// Detecta movimiento REAL del joystick (deadzone ampliado)
if( abs(vX - 512) > 80 || abs(vY - 512) > 80 ){
  tiempoUltimaActividad = millis();
}


    // Para evitar movimientos demasiado rápidos, solo permite mover después de cierto tiempo
    if(millis() - tiempoUltimoMovimiento >= retrasoMovimiento){

        // ----- Movimiento horizontal -----
        // Si el joystick está hacia la izquierda y queda espacio, mueve a la izquierda
        if(vX > 800 && x > 0) nueva = x - 1;
        // Si está hacia la derecha y queda espacio, mueve a la derecha
        else if(vX < 200 && x < 7) nueva = x + 1;

        // ----- Movimiento vertical -----
        // Si el joystick está hacia arriba y queda espacio, sube
        if(vY > 800 && y > 0) nuevaY = y - 1;
        // Si está hacia abajo y queda espacio, baja
        else if(vY < 200 && y < 7) nuevaY = y + 1;

        // Calcula el índice del pixel en su nueva posición
        int indiceNuevo = obtenerIndice(nueva, nuevaY);

        // ----- LÓGICA DE REBOTE -----
        // Si el pixel intenta moverse hacia el Pixel Bloqueado
           if(indiceNuevo == pixelBloqueado){
            pixelEscapado = pixelBloqueado;   // Lo deja caer al agujero momentáneamente
            dibujarMatrizNormal();            // Redibuja
            delay(90);                      

            // Prepara una lista de vecinos posibles para rebotar
            int vecinos[4], cnt = 0;

            if(x < 7) vecinos[cnt++] = obtenerIndice(x + 1, y); // vecino derecha
            if(x > 0) vecinos[cnt++] = obtenerIndice(x - 1, y); // vecino izquierda
            if(y < 7) vecinos[cnt++] = obtenerIndice(x, y + 1); // vecino abajo
            if(y > 0) vecinos[cnt++] = obtenerIndice(x, y - 1); // vecino arriba

            // Escoge uno al azar y lo manda ahí (rebote)
            pixelEscapado = vecinos[random(cnt)];
        } else {
            // Movimiento normal: el pixel se cambia a la nueva posición
            pixelEscapado = indiceNuevo;
        
        }
        dibujarMatrizNormal();                // Redibuja la matriz con el movimiento final
        tiempoUltimoMovimiento = millis();    // Actualiza el tiempo del último movimiento
    }
  }
if(millis() - tiempoUltimaActividad > 27000){
// si no interactuas con el joystick por 27 segundos
    Serial.println(">> Se ejecutó repararCuadrado() por INACTIVIDAD <<");

    actualizarLCD("VEN, ACERCATE…", "podrías divertirte", false); //(muestra el mensaje de bienvenida de nuevo)
    mostrarLCD(); //pantallea
    juegoIniciado = false;
    repararCuadrado(); //muestra el cuadrado perfecto

    tiempoUltimaActividad = millis();
}
}

message.txt