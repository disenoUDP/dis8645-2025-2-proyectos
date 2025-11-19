# sesion-13b

07/11

Falte por operación pero mi grupo me conto lo que hicieron en clases.

## Clase

Indicaciones de los profesores
Los profesores indicaron que hay que darle misiones al usuario, como por ejemplo que tome un LED y lo conecte en alguna parte, o que el usuario mismo haga explotar un condensador.
Después de cada revisión, Aarón comentó:

- No debemos humanizar a la máquina (no atribuirle emociones humanas).
- Revisaron la descripción del proyecto y nos pidieron explorar materiales y sensores.
- No esforzar las emociones: abrir la mente (no limitarse a hacer “miau” o sonidos simples).
- Hay que ser capaces de defender la complejidad del proyecto.

### Encoder
Dispositivo que convierte movimiento rotatorio o lineal en señales eléctricas que el sistema puede leer. Es una manivela que gira sin límite y solo indica hacia dónde se giró.

### Tipos de sensores
- Sensor capacitivo TTP223
   - Detecta el toque de un dedo sin presión física.
   - Puede funcionar bajo tela o lana.
   - Ideal para reacciones suaves e inmediatas.

- Sensor piezoeléctrico
   - Detecta vibraciones, golpes o presión brusca.
   - Económico y fácil de usar.
   - Útil para respuestas de sobresalto.

- FSR (Force Sensitive Resistor)
   - Mide cuánta presión se aplica.
   - Ideal para cambiar intensidad o color de luces según fuerza del toque.

- Sensor de proximidad IR o ultrasónico
   - Detecta presencia sin contacto.
   - Permite que la máquina se “active” cuando alguien se acerca.

## Discurso del proyecto (versión modificada)
El proyecto propone la creación de una máquina sentimental, un artefacto interactivo capaz de reaccionar sensiblemente al entorno, especialmente al ruido, la voz o el tacto, y de expresar esas emociones mediante visuales luminosos y patrones en movimiento.
La máquina funciona como un organismo emocional. Su cuerpo, hecho con materiales suaves como lana o fieltro, invita al contacto humano. En su interior, un Arduino con sensores de sonido y tacto registra estímulos externos, que se traducen en luces que cambian de color, intensidad o ritmo.
La máquina no busca ser útil, sino sensible. Exagera la relación entre cuerpo y emoción, funcionando como un espejo de nuestra necesidad de conexión. Puede iluminarse suavemente ante una caricia o sobresaltarse con un ruido brusco.
El objetivo es explorar la afectividad en objetos tecnológicos y cuestionar los límites entre lo vivo y lo mecánico. La máquina sentimental genera una experiencia empática entre espectador y objeto.

Próxima entrega (martes)

- Presupuesto
- Carta Gantt macro (semana a semana)
- Bocetos físicos
- Diagramas de flujo
- Pseudocódigo



## Clase de Mateo y Janis

- Hay que revisar presupuesto y agregar precios y links en un Excel.
- Se utilizarán sensores de tacto.
- Las visuales se harán con TouchDesigner y se montarán en una página web con p5.js.
- Se visualizará en una pantalla que tendrá su propia carcasa.
- Plantear bien la materialidad.
- Trabajar con Arduino Uno R4 WiFi.
- Investigar servidor, cliente y conexiones inalámbricas.

Janis apoyará en el uso del R4 WiFi y Mateo en el mapping desde GitHub.

## Arduino Uno R4 WiFi
### Hardware

- Microcontrolador principal: Renesas RA4M1 (ARM Cortex-M4)
- Módulo secundario: ESP32-S3 para Wi-Fi y Bluetooth
- El ESP32-S3 maneja la conectividad inalámbrica.

### Librerías y ejemplos

- Arduino distribuye librerías oficiales.
- Revisar “WiFi examples” en el IDE.


### Modos Wi-Fi

- Cliente (Station)
Se conecta a un router usando WiFi.begin().
- Punto de acceso (AP)
Crea su propia red con WiFi.softAP() para alojar páginas web locales.
- Servidor vs cliente
Servidor: el Arduino escucha conexiones entrantes.
Cliente: el Arduino hace peticiones a servidores externos.

### Ejemplos mínimos
- Cliente HTTP
(Código incluido en tus apuntes originales)
- Servidor Web en modo AP
(Código incluido en tus apuntes originales)

### HTTPS y limitaciones

- Hay ejemplos oficiales para SSL.
- Requiere manejo cuidadoso de memoria y certificados.
- WPA2-Enterprise puede no ser compatible.

### Troubleshooting

- Problemas comunes con AP pueden venir del paquete de placas desactualizado.
- Revisar WiFi.status(), IPs locales, y versiones del core.


## Proyecto: Máquina Sentimental
La máquina reacciona según la intensidad del toque: pinchazos, pellizcos, caricias, presión, estiramiento. Cada gesto desencadena visuales diferentes.

### Manifiesto
La máquina sentimental es un organismo artificial que responde al tacto como si tuviera emociones. Traduce afectos en datos y convierte gestos en lenguaje digital.
Su cuerpo suave invita al acercamiento, mezclando lo orgánico y lo artificial. Ese contraste genera duda: ¿es un objeto inerte o una presencia viva?
Cada gesto del usuario activa respuestas sonoras y visuales que transforman la interacción en un paisaje emocional.

### Máquina Reactiva (Descripción general)
En reposo, la máquina está inmóvil y silenciosa. Su materialidad invita a acercarse.
Al apretar, estirar o acariciar, la máquina despierta. Cada gesto activa un ciclo distinto de gráficos y sonido.
Cuando la interacción termina, la actividad disminuye progresivamente y vuelve a su reposo inicial, lista para reiniciar el ciclo.

### Lógica de interacción

1. La máquina está en reposo.

2. El usuario se acerca.

3. Decide tocarla.

4. Acciones posibles (cada una dura 15 segundos):

- Apretar
- Estirar
- Acariciar

5. Cada acción tiene visuales y sonidos propios.

6. Si se inicia una acción nueva, la anterior se apaga.

7. Al dejar de tocarla, la actividad baja durante 5 segundos.

8. Vuelve al reposo.


### Revisión de proyectos

- Explayar y explorar.
- Investigar materiales, referentes y tipos de comunicación no verbal.
- Interesa estudiar cómo se comunican animales, personas sordociegas, personas con parálisis cerebral, etc.
- Preguntas exploratorias:
   - ¿Cómo se siente el ruido?
   - ¿Cómo perciben el mundo quienes no oyen?




