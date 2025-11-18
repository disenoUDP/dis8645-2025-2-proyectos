# 🌷 sesion-15a
Martes 18 de noviembre 

## Apuntes de clase 
Martes **25 de noviembre**
- 09:30 Metro Salvador
- 11:00 MAC Parque Forestal

## 🔮 Avance del proyecto

### ((((anotar los avances de ayer))))
- agregar nuevo diagrama de flujo
- explicacion proyecto

## Conexión Arduino con P5.js
Primero vi estos videos para entender la conexión.
(https://www.youtube.com/watch?v=MtO1nDoM41Y)

Primero probaremos la conexión serial. Pero antes de esto hay que descargar un programa intermediario que hace que pueda leer el puerto serial desde una página web, que por motivos de seguridad están bloqueados. **Este es el link de descarga**: (https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2).

### P5.serialcontrol
Esta aplicación ejecuta p5.serialserver, que permite la conectividad entre dispositivos serie locales y aplicaciones web mediante la biblioteca p5.serialport de p5.js.

Probando, me di cuenta de que esta aplicación no funcionaba como corresponde, no encontraba el puerto serial y no lograba hacer la conexión, es por eso que le pedimos ayuda a Aarón, y nos guió con la biblioteca para poder usar el arduino con p5.

### p5.webserial.js de Gohai
(https://github.com/gohai/p5.webserial?tab=readme-ov-file#getting-started)

Esta es una biblioteca para p5 que añade compatbilidad para interactuar con dispositivos serie mediante la API Web Serial, que actualmente está compatible con Chrome y Edge.

### Para comenzar la conexión
Primero hay que descargar este archivo: (https://github.com/gohai/p5.webserial/blob/main/libraries/p5.webserial.js) e incluirlo en head del html, debajo de la línea que carga p5. <script src="https://unpkg.com/@gohai/p5.webserial@^1/libraries/p5.webserial.js"></script>

Segundo, crear una variable globar y asignarle una nueva puerto de serie dentro de la configuración.











