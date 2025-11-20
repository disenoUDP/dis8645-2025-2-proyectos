# sesion-15a

Llegando el día de hoy quise asesorar los componentes que aún no nos estaban funcionando, uno era el display, que eran malas noticias, ya que Morgan estuvo probándolo todo el fin de semana.

Una de las cosas que encontré curioso con el display era la forma en la que Morgan había soldado los pines, ya que habían 3 conecciones entre pines que no corresponden, ya que probablemente causaban o un cortocircuito o una transmisión incorrecta de datos. 

Así que separé el estaño con un cautín, quedaron medio charchas las soldaduras, así que Misaa me ayudó y dejó el display de manera fina fina fina.

Volví a conectar todos los pines desde cero para asegurarme que todo esté bien conectado, sin duda alguna, para de ahí cargarle el ejemplo de la biblioteca de Adafruit:

https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library/blob/master/examples/pcdtest/pcdtest.ino

Y ahi funciono de una, o era ese problema con la soldadura o con el cableado, lo importante
es que ya quedó solucionado ese tema.

Ahora, el 2do componente que no está funcionando es el reproductor de archivos de sonido, que en realidad, no se si es que está funcionando o no, la Jose y la Angie van a intentar usar el código que utilizaron para el proyecto 2.

No les funciono, asi que les di apoyó, primero probamos viendo el cableado, no era el problema, al menos a simple vista porque estaba igual que para el proyecto 02 de las chiquillas.

Después intentamos formatear la tarjeta SD, que no causó ningún cambio visible tampoco.

Probamos múltiples distintos códigos, de distintas bibliotecas, el problema es que el mismo error se repetía en todas, el módulo no funcionaba, o mejor dicho, no era identificado en el código.

Le pedí al grupo 3 sus componentes, ya que podría haber ocurrido un error con los nuestros de alguna manera. 

Pero pasó lo mismo, probé su tarjeta Sd, nada, su módulo, nada, su cableado, nada, su arduino, nada nada nada nadaaaaaaaaaaaaa.

Así que me rendí por el día de hoy, pero como referencia si es que queremos hacer un ruido al menos tengo referencias del semestre pasado, donde ocupamos resistencias para cambiar el pitch de un sonido reproducido.

Durante la tarde en el LID, Morgan me comunicó que no entendía bien cómo hacer el temporizador, me envió varios links pero el mas mas mas simple según mi entendimiento era este:

https://forum.arduino.cc/t/simple-countdown-timer/662809/4

Esta persona estaba buscando ayuda con un temporizador para sus hijos, pero la parte importante es que deja una manera simple de como hacer el temporizador, con 3 datos importantes:

``` cpp

// un “int” que definirá la cantidad de tiempo
// en este caso pondré 40
int segundos = 40;

// en el void loop
// que los segundos disminuyen en 1 de la siguiente manera
segundos -=1;

// para que esto no ocurriese cada milisegundo
//estaba acompañado de un delay de 1 segundo
delay(1000);

```

Para este punto, Morgan ya tenía una nueva versión de WEBO, con pruebas de bitmaps en el display funcionando, como ya estaba trabajando con esto del temporizador quise integrarlo directamente al WEBO.

Como en realidad esa parte va a funcionar dependiendo del botón según lo que hemos acordado, siendo esta la manera en la que el usuario aumente el tiempo que quiere en su temporizador, lo intente aplicar en el archivo del botón, siguiendo el siguiente ejemplo:

https://docs.arduino.cc/built-in-examples/digital/Button/

Esto me hizo saber que era buena práctica el poner una resistencia al botón, lo demás fue relativamente simple, era establecer el pin en el que iba a enviar la señal del botón, investigando en internet igual me di cuenta que puedo conectarlo al lado de los pins analógicos pero eso es solo si es que necesitaramos mas pines digitales, que por ahora no parece ser una problema. 

Hice que el botón causará que se agregaran 5 segundos al temporizador, aquí hay un pequeño problema, que es que se podría mantener presionado el botón para aumentar constantemente los segundos, que le quitaria un poco la inconveniencia de tener que presionar múltiples veces el botón, pero esto será un problema para el seba del futuro, solo se que tendre que tener en cuenta lo del cambio de estado, escribiendo algo para tener en cuenta el cambio.

Pero con esto, en código de WEBO llegó a una nueva versión con el botón funcional y el display funcional, tal vez a la noche agregue esos otros componentes que tenía probados de las sesiones anteriores.

En la noche, Aileen del grupo 3 GEE (Grupo emocionalmente estable) me mando un modo de formatear la tarjeta sd que a ellos si les funciono, lo hice pero no me seguía detectando la tarjeta, así que en desesperación le pedí a chat gpt un paso a paso del cableado y código de ejemplo más simple posible para el funcionamiento de ese módulo, como también de la manera en la que debería ser establecido el nombre de los archivos.

Y si, funciono, como en cambios memorables fue que la alimentación la cambia a 3.3V, que no debería de hacer mucho problema según el datasheet debido a que soporta 5V tambien pero bueno, el otro cambio fue poner una resistencia para el pin RX que estaría conectado al arduino mediante el pin 3 y funciono, no se que cambio pero no lo voy a querer cambiar como para arruinar algo, wuju.

El código que ocupe para la prueba fue el siguiente :

``` cpp

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial dfSerial(2, 3); // RX, TX
DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(115200);
  dfSerial.begin(9600);

  Serial.println("Initializing DFPlayer...");

  if (!player.begin(dfSerial)) {
    Serial.println("Unable to begin. Check:");
    Serial.println("1. Wiring");
    Serial.println("2. SD card FAT32");
    Serial.println("3. Voltage divider on RX");
    while (true);
  }

  Serial.println("DFPlayer online!");
  player.volume(3);
}

void loop() {
player.play(1);
delay(4000);

}

```

A, también cambie el nombre del archivo a exactamente 0001.mp3 que puede haber ayudado.

De esta manera quedó el WEBO_0_4_0 que estará subido en el repositorio, que fue actualizado desde la última versión que me había pasado el Morgan que seria el WEBO_0_3_5.

Bueno, como para dejar cerrado el dia de trabajo en el LID con Camila, Morgan y Josefa de mi grupo nos pusimos a declarar que es lo que podría estar faltando respecto a los componentes para el viernes, quedamos con la siguiente lista:

Display:
1. Confirmar que la mascota virtual y un texto puedan coexistir, sino lloramos.
2. Confirmar que el temporizador puede ser traído desde el archivo del botón, para usarlo como un texto que salga en el display
3. Confirmar que no nos está usando toda la ram los bitmaps

LED:
1. Confirmar que los leds no pierden potencia por estar el mismo pin, sino vamos a tener que usar varios pines

Motor:
1. Definir el peso que va a ser puesto al motor
2. Acordarse que solo se active cuando hayan pasado 30 segundos aprox

Botón:
1. Ver soldar y/o hacerle una base
2. Millis (Examen)
3. Hacer que el temporizador para cuando llegue a 0
4. Ver que si se mantiene presionado, que no sume infinitamente 5s.

Sensor SD:
1. Hacer que unas variables si funcionen en el .h en vez del cpp

Sensor Tilt
1. Pasar codigo que funcionaba e integrarlo a las clases
2. Hacer que en el .ino este sea un IF de todo lo demás, si no esta inclinado, recién podría ocurrir todo lo demás

Bitmaps
1. Pasarlos a bitmaps, asegurarse que sean chicos, pa que no ocupen a pantalla entera

Y también establecimos algunas de las interacciones definitivas para seguir el chiste de nuestra máquina, entre ellos se encuentran:
 
- El movimiento del motor debería ser aleatorio, esto es inconveniente, refiriéndonos a que el momento en el que se active el motor debería ser dentro de algún rango de tiempo que el usuario no conoce, para que no pueda estar absolutamente preparado para que ocurra, como idea vamos a hacer un funcionamiento random desde 10 hasta 45 segundos desde la última activación del motor para que se pueda volver a activar.

