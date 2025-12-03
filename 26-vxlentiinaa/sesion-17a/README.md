# sesion-17a

02-12-2025

## Apuntes

- Compramos el acelerómotero 345 de 3 ejes, con el fin de darle un término al juego.
- Tenemos pensado que con el acelerómetro hagas un gesto de "atrapar el hada" en el eje Z, es decir, arriba/abajo para terminar el juego con el gesto de atrapar

### Acelerómetro ADXL 345 / Sensor Acelerómetro GY-291 ADXL345 - 3 ejes

Datasheet: [datasheet acelerómetro](https://www.alldatasheet.com/datasheet-pdf/download/254714/AD/ADXL345.html)

- Sensor de aceleración digital de 3 ejes de bajo consumo.
- Medición de 3 ejes: Mide la aceleración en los ejes X, Y y Z.
- El módulo acelerómetro GY-291, basado en el chip ADXL345, es un sensor digital de 3 ejes diseñado para medir con precisión la aceleración estática (gravedad) y dinámica (movimiento). Gracias a su bajo consumo de energía y diseño compacto, es ideal para aplicaciones portátiles y alimentadas por batería. Ofrece interfaces de comunicación digital I2C y SPI, facilitando su integración con microcontroladores como Arduino, ESP32 o Raspberry Pi. Su alta resolución y rangos de sensibilidad seleccionables (hasta ±16g) permiten detectar desde pequeños cambios de inclinación hasta movimientos bruscos.

`Características:`

- Chip Integrado: Analog Devices ADXL345
- Voltaje de Alimentación: 3.3V a 5V DC (regulador integrado)
- Interfaces de Comunicación: I2C y SPI (3 o 4 hilos)
- Ejes de Medición: 3 ejes (X, Y, Z)
- Rango Seleccionable: ±2g, ±4g, ±8g, ±16g
- Alta Resolución: Hasta 13 bits, con una sensibilidad de 4 mg/LSB
- Bajo Consumo: Aproximadamente 140 µA en modo de medición

---

### Código de prueba de p5.js modificado por Mateo

```
//este sketch fue hecho con ayuda de la librería de Gohai
//conexión de datos de arduino hacia p5 utilizando sensores de fuerza
//sensorX: izquierda-derecha, sensorY: arriba-abajo
//proyecto examen taller vertical noviembre-diciembre 2025

// -------------------------
// configuración arduino - p5
// -------------------------
const BAUDRATE = 9600; //velocidad del puerto
let port = null;       //variable del puerto
let connectBtn;        //botón de conexión

let sensorX = 0;       //izquierda-derecha
let sensorY = 0;       //arriba-abajo
let prevSensorY = 0;   //para detectar el click con FSR
const UMBRAL_CLICK = 600; //presión fuerte en Y = click
let lecturaEstado = 0; // 0 = siguiente dato es X, 1 = siguiente dato es Y

// modo de control
// usarMouse = true → control con mouse (simulación)
// usarMouse = false → control con sensores FSR
let usarMouse = true;
let prevMousePressed = false;

// estados del juego
let estado = "inicio";            // "inicio", "seleccion", "juego"
let personajeSeleccionado = null; //0...3
let juegoIniciado = false;        //para inicializar cosas una sola vez al entrar al juego

// imágenes de fondo y red
let atrapaPNG;     //red (PNG)
let inicioBG;      //fondo inicio (primer frame de inicio.gif)
let fondoBG;       //fondo selección + juego (primer frame de fondo.gif)

// gifs de personajes
let persSelectGIF = []; //gifs de selección (4)
let persGameGIF  = [];  //gifs en juego (4)

// variables para gifs en juego, posición y velocidad
let charX = 0;
let charY = 0;
let charVX = 4;
let charVY = 3;

// -------------------------
// PRELOAD: carga PNG/JPG/GIF como imagen fija
// -------------------------
function preload() {
  atrapaPNG = loadImage("atrapar.png");   //la red que se mueve
  inicioBG  = loadImage("inicio.gif");    //fondo inicio (no animado, primer frame)
  fondoBG   = loadImage("fondo.gif");     //fondo selección + juego
}

// -------------------------
// SETUP
// -------------------------
function setup() {
  createCanvas(1920, 1080); //tamaño del lienzo
  background(0);

  // gifs de personajes a seleccionar (miniaturas)
  persSelectGIF[0] = createImg("pers1_sel.gif", "p1_sel");
  persSelectGIF[1] = createImg("pers2_sel.gif", "p2_sel");
  persSelectGIF[2] = createImg("pers3_sel.gif", "p3_sel");
  persSelectGIF[3] = createImg("pers4_sel.gif", "p4_sel");

  for (let i = 0; i < 4; i++) {
    persSelectGIF[i].style("pointer-events", "none");
    persSelectGIF[i].size(220, 220); // tamaño en pantalla de selección
    persSelectGIF[i].hide();
  }

  // gifs de juego en acción (se mueven en la pantalla de juego)
  persGameGIF[0] = createImg("pers1_game.gif", "p1_game");
  persGameGIF[1] = createImg("pers2_game.gif", "p2_game");
  persGameGIF[2] = createImg("pers3_game.gif", "p3_game");
  persGameGIF[3] = createImg("pers4_game.gif", "p4_game");

  for (let i = 0; i < 4; i++) {
    persGameGIF[i].style("pointer-events", "none");
    persGameGIF[i].size(260, 260);
    persGameGIF[i].hide();
  }

  // puerto serie (solo si la librería existe)
  if (typeof createSerial === "function") {
    port = createSerial();
    port.bufferSize(1024);
  } else {
    console.warn("p5.webserial NO cargado, solo se usará el mouse.");
    port = null;
    usarMouse = true; // nos aseguramos de estar en modo mouse
  }

  // botón para conectar/desconectar arduino
  connectBtn = createButton("Conectar");
  connectBtn.addClass("connect-btn");
  connectBtn.mousePressed(connectBtnClick);
}

// -------------------------
// DRAW
// -------------------------
function draw() {
  // fondo según la pantalla
  if (estado === "inicio") {
    imageMode(CORNER);
    image(inicioBG, 0, 0, width, height);
  } else {
    imageMode(CORNER);
    image(fondoBG, 0, 0, width, height);
  }

  // actualizar sensores desde Arduino (si está conectado y no estamos en modo mouse)
  leerSerial();

  // si estamos en modo mouse, simulamos valores de sensor
  if (usarMouse) {
    sensorX = map(mouseX, 0, width, 0, 1023);
    sensorY = map(mouseY, 0, height, 1023, 0); //invertido para mantener lógica
  }

  const click = hayClick(); // click puede venir de mouse o de FSR

  // máquina de estados para las pantallas
  if (estado === "inicio") {
    dibujarPantallaInicio(click);
  } else if (estado === "seleccion") {
    dibujarPantallaSeleccion(click);
  } else if (estado === "juego") {
    dibujarPantallaJuego();
  }
}

// -------------------------
// LECTURA SERIAL (NUEVO SISTEMA)
// -------------------------
function leerSerial() {
  if (!port || usarMouse) return;
  if (!port.opened()) return;

  let line = port.readUntil("\n");

  while (line && line.length > 0) {
    line = trim(line);

    // Esperamos que Arduino mande "X,Y"
    if (line.includes(",")) {
      let partes = line.split(",");
      if (partes.length === 2) {
        let x = int(partes[0]);
        let y = int(partes[1]);

        // Validación simple (0–1023)
        if (!isNaN(x) && x >= 0 && x <= 1023) {
          sensorX = x;
        }
        if (!isNaN(y) && y >= 0 && y <= 1023) {
          sensorY = y;
        }
      }
    }

    // leer siguiente línea del puerto
    line = port.readUntil("\n");
  }
}

// -------------------------
// DETECCIÓN DE "CLICK"
// -------------------------
function hayClick() {
  let click = false;

  if (usarMouse) {
    // click simulado con mouse: flanco ascendente
    click = mouseIsPressed && !prevMousePressed;
    prevMousePressed = mouseIsPressed;
  } else {
    // click real con FSR en eje Y
    click = sensorY > UMBRAL_CLICK && prevSensorY <= UMBRAL_CLICK;
    prevSensorY = sensorY;
  }

  return click;
}

// -------------------------
// PANTALLA DE INICIO
// -------------------------
function dibujarPantallaInicio(click) {
  // ocultar gifs de selección y juego
  for (let g of persSelectGIF) g.hide();
  for (let g of persGameGIF) g.hide();

  // red controlada por sensorX / mouse
  let cursorX = map(sensorX, 0, 1023, width * 0.1, width * 0.9);
  let cursorY = height * 0.65;

  imageMode(CENTER);
  image(atrapaPNG, cursorX, cursorY, 120, 120);

  // si hay "click" (mouse o sensor), pasar a selección
  if (click) {
    estado = "seleccion";
    personajeSeleccionado = null;
    juegoIniciado = false;
  }
}

// -------------------------
// PANTALLA DE SELECCIÓN
// -------------------------
function dibujarPantallaSeleccion(click) {
  // Layout: 4 personajes en fila horizontal, centrados en Y
  const yFila = height * 0.5;
  const anchoGif = 220;
  const espacio = 100; // espacio entre personajes

  const totalWidth = 4 * anchoGif + 3 * espacio;
  const startX = width / 2 - totalWidth / 2;

  const posiciones = [
    { x: startX + (anchoGif / 2) + 0 * (anchoGif + espacio), y: yFila },
    { x: startX + (anchoGif / 2) + 1 * (anchoGif + espacio), y: yFila },
    { x: startX + (anchoGif / 2) + 2 * (anchoGif + espacio), y: yFila },
    { x: startX + (anchoGif / 2) + 3 * (anchoGif + espacio), y: yFila }
  ];

  // Mostrar personajes de selección en fila
  for (let i = 0; i < 4; i++) {
    persSelectGIF[i].show();
    // createImg se posiciona por la esquina superior izquierda
    persSelectGIF[i].position(
      posiciones[i].x - anchoGif / 2,
      posiciones[i].y - anchoGif / 2
    );
  }

  // Cursor controlado por sensor o mouse (puntero = atrapar.png)
  let cursorX = map(sensorX, 0, 1023, 0, width);
  let cursorY = map(sensorY, 0, 1023, height, 0);

  imageMode(CENTER);
  image(atrapaPNG, cursorX, cursorY, 120, 120);

  // Elegir personaje más cercano al cursor
  let seleccionado = 0;
  let mejorDist = Infinity;

  for (let i = 0; i < 4; i++) {
    let dx = cursorX - posiciones[i].x;
    let dy = cursorY - posiciones[i].y;
    let d2 = dx * dx + dy * dy;
    if (d2 < mejorDist) {
      mejorDist = d2;
      seleccionado = i;
    }
  }

  // Resaltar personaje seleccionado con un círculo
  noFill();
  stroke(255);
  strokeWeight(4);
  for (let i = 0; i < 4; i++) {
    if (i === seleccionado) {
      ellipse(posiciones[i].x, posiciones[i].y, anchoGif + 40, anchoGif + 40);
    }
  }

  // Click (mouse o sensor) → guardar selección y pasar a juego
  if (click && seleccionado !== null) {
    personajeSeleccionado = seleccionado;
    estado = "juego";
    juegoIniciado = false;
  }
}

// -------------------------
// PANTALLA DE JUEGO
// -------------------------
function dibujarPantallaJuego() {
  // ocultar gifs de selección
  for (let g of persSelectGIF) g.hide();

  // inicializar solo una vez al entrar al juego
  if (!juegoIniciado) {
    juegoIniciado = true;

    for (let g of persGameGIF) g.hide();

    if (personajeSeleccionado === null) personajeSeleccionado = 0;
    persGameGIF[personajeSeleccionado].show();

    // posición inicial del personaje (centro)
    charX = width / 2;
    charY = height / 2;

    // velocidad inicial random (ajusta estos valores si quieres más velocidad)
    charVX = random(-10, 10);
    charVY = random(-8, 8);
    if (abs(charVX) < 2) charVX = 4;
    if (abs(charVY) < 2) charVY = 3;
  }

  // actualizar posición
  charX += charVX;
  charY += charVY;

  // rebotar en los bordes
  const margen = 130;
  if (charX < margen || charX > width - margen) charVX *= -1;
  if (charY < margen || charY > height - margen) charVY *= -1;

  // posicionar el gif del personaje en juego
  let gifJuego = persGameGIF[personajeSeleccionado];
  gifJuego.position(charX - 130, charY - 130);

  // red para atrapar controlada por sensores/mouse
  let netX = map(sensorX, 0, 1023, 0, width);
  let netY = map(sensorY, 0, 1023, height, 0);

  imageMode(CENTER);
  image(atrapaPNG, netX, netY, 220, 220);
}

// -------------------------
// BOTÓN CONECTAR ARDUINO
// -------------------------
function connectBtnClick() {
  if (!port) {
    alert("p5.webserial no está cargado. Solo se usará el mouse 🙂");
    return;
  }

  if (!port.opened()) {
    port.open(BAUDRATE);
    connectBtn.html("Conectando...");
    setTimeout(() => {
      connectBtn.hide();
      usarMouse = false;   //ahora el control viene de los sensores
    }, 500);
  } else {
    port.close();
    connectBtn.show();
    connectBtn.html("Conectar");
    usarMouse = true;      //volvemos a modo mouse
  }
}
```
