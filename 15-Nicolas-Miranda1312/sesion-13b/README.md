# sesion-13b

-07-11-2025

## Apuntes de clase

Hoy avanzamos en la planificación de nuestra máquina interactiva. Revisamos la **lista de materiales** y comenzamos el **seudocódigo**, definiendo la lógica principal del proyecto.

También discutimos la importancia de clarificar la **idea central**, considerando que cada vez que el usuario intente arreglar un error en la figura, este debe generar aún más desajustes, reforzando la sensación de caos.

Referencia: Pantalla LCD 20x4 con I2C.

---

### Actuadores

- **Joystick:** mueve los elementos en dirección contraria al movimiento del usuario.
- **Botón del joystick:** reinicia la figura al primer punto donde ocurrió el error.
- **Botón principal:** cambia el color del LED y envía el píxel roto a una posición aleatoria.
- **Potenciómetro:** activa el modo de autodestrucción, dispersando toda la figura.
- **Botón 2:** reinicia y carga una figura nueva.

---

#### Game Over

A simple vista parece una máquina arcade, pero tiene un propósito distinto: **está diseñada para perder**.

La máquina consiste en una **matriz LED 8x8 RGB**, un **joystick**, **dos botones** y un **potenciómetro**.  
Inicialmente muestra el mensaje *S.O.S*. Cuando el sensor ultrasónico detecta presencia, aparece una figura geométrica perfecta (triángulo, X o cuadrado).  
Pero al acercarse un poco más, un píxel se desplaza y la figura se arruina. Desde ese momento, cada intento por repararla solo produce más caos: la máquina nunca permitirá que vuelva a ser perfecta.

##### Controles

- **Joystick:** mueve los píxeles en la dirección opuesta a la deseada.  
- **Botón del joystick:** reinicia la figura al estado en que comenzó el error.  
- **Botón principal:** cambia el color del LED y mueve el píxel defectuoso a un lugar aleatorio.  
- **Potenciómetro:** activa el modo autodestrucción.  
- **Botón 2:** muestra una nueva figura.

###### Concepto

**Game Over** es una experiencia interactiva que explora la frustración y la imposibilidad de alcanzar la perfección.  
Cada intento de arreglar la figura crea nuevas fallas, convirtiendo al error en protagonista y revelando su belleza dentro del caos.

---

###### Encargo

Para el próximo martes:

- Presupuesto.  
- Carta Gantt macro (semana a semana).  
- Bocetos físicos.  
- Diagramas de flujo.  
- Seudocódigo.

---

###### Presupuesto

| Componente | Cantidad | Valor | Link | Anotaciones |
|-----------|----------|--------|------|-------------|
| Resistencias 220 Ω | x | x | x | x |
| Sensor ultrasónico | 1 | $1.500 | https://afel.cl/products/sensor-de-ultrasonico-hc-sr04 | x |
| Potenciómetro 10k | 1 | $500 | https://afel.cl/products/potenciometro-10k-ohm | |
| Matriz LED RGB 8x8 | 1 | $9.990 | https://afel.cl/products/matriz-led-rgb-neopixel-8x8-ws2812-cjmcu64 | x |
| Botones | 3 | $100 c/u | https://afel.cl/products/boton-tactil-tapa-12x12x7-3-interruptor | x |
| Joystick | 1 | $2.000 | https://afel.cl/products/joystick-palanca-de-mando | x |
| Cables macho–macho / macho–hembra | x | x | https://afel.cl/products/pack-20-cables-de-conexion-macho-macho / https://afel.cl/products/pack-20-cables-de-conexion-macho-hembra | x |
| Pantalla LCD 20x4 I2C | 1 | $2.400 | https://afel.cl/products/pantalla-lcd-verde-20x04-2004-con-i2c | x |

---

###### Pseudocódigo

```cpp
INICIO

// --- DECLARACIÓN DE COMPONENTES ---
Definir PantallaPixeles[8][8]
Definir PantallaLCD(20x4, i2c)
Definir SensorUltrasonico
Definir Joystick (X, Y, Botón)
Definir BotónPrincipal
Definir BotónSecundario
Definir Potenciómetro
Definir LED_RGB

Definir FiguraActual
Definir PixelRoto
Definir Distancia

// --- ESTADO INICIAL ---
MostrarLCD("S.O.S")
ApagarPantallaPixeles()
LED_RGB = ColorInicial

// --- BUCLE PRINCIPAL ---
Mientras (VERDADERO)
    Distancia = Leer(SensorUltrasonico)
    
    Si (Distancia < UMBRAL_DETECCIÓN)
        MostrarFiguraPerfecta()
    FinSi
    
    Si (Distancia < UMBRAL_ERROR)
        RomperFigura()
    FinSi

    LeerControles()
    
    ActualizarPantallaPixeles()
    ActualizarLCD()
FinMientras

// --- FUNCIONES PRINCIPALES ---

Función MostrarFiguraPerfecta()
    Si (FiguraActual == NULO)
        FiguraActual = GenerarFiguraAleatoria()   // Triángulo, X o Cuadrado
    FinSi
    Dibujar(FiguraActual)
    MostrarLCD("Figura detectada")
FinFunción

Función RomperFigura()
    PixelRoto = SeleccionarPixelAleatorio(FiguraActual)
    MoverPixel(PixelRoto, desplazamientoPequeño)
    MostrarLCD("Algo se rompió...")
FinFunción

Función LeerControles()
    // --- JOYSTICK ---
    Dirección = Leer(Joystick)
    Si (Dirección ≠ CENTRO)
        MoverPixel(PixelRoto, DirecciónContraria(Dirección))
    FinSi
    
    Si (BotónJoystickPresionado)
        RestaurarFiguraAlPuntoDeError()
    FinSi
    
    // --- BOTÓN PRINCIPAL ---
    Si (BotónPrincipalPresionado)
        CambiarColorLED(LED_RGB)
        PixelRoto = MoverPixelAleatoriamente(FiguraActual)
    FinSi
    
    // --- POTENCIÓMETRO ---
    Nivel = Leer(Potenciómetro)
    Si (Nivel > UMBRAL_AUTODESTRUCCIÓN)
        AutodestruirFigura()
    FinSi
    
    // --- BOTÓN SECUNDARIO ---
    Si (BotónSecundarioPresionado)
        ReiniciarTodo()
    FinSi
FinFunción

// --- FUNCIONES AUXILIARES ---

Función RestaurarFiguraAlPuntoDeError()
    Restaurar(FiguraActual, estadoConPixelRoto)
    MostrarLCD("Intento de reparación...")
FinFunción

Función AutodestruirFigura()
    DesarmarTodosLosPixeles()
    MostrarLCD("AUTODESTRUCCIÓN ACTIVADA")
FinFunción

Función ReiniciarTodo()
    FiguraActual = NULO
    PixelRoto = NULO
    MostrarLCD("S.O.S")
    ApagarPantallaPixeles()
FinFunción

*(Pendiente de completar según el avance.)*
```

---
