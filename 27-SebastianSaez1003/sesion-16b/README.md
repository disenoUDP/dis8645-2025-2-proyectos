# sesion-16b

Este dia partio con una convivencia en celebracion del cumpleaños de Camila y Braulio, que estuvo entrete, hable con una buena cantidad de gente del taller que me cae bien, comi mucho tambien.

Luego nos pusimos un poco mas serios para hablar respecto al examen, nos debemos organizar con google calendar para no mal gastar el timepo, se nos presento nuestra comision donde sali un poco retado respecto a no tener prejuicios porque no conocia a uno de los profesores los que nos iba a evaluar.

Los dias de motaje son el sabado 6, el domingo 7 y el lunes 8, pero deberiamos tener todo escrito en el github para el sabado 6 en la tarde, miedo.

Tambien cada uno de los grupos podemos ver la manera en la que vamos a presentar, ya que el examen sera en el LID si que tambien hay que ponernos de acuerdo para que Bernardita no lo haga todo.

Para realmente empezar a trabajar en nuestro proyecto y mejorar al WEBO, primero quise ver cual era el gran problema respecto a que se nos pegaba siempre que el tilt era activado, donde observe que en realidad no era el sensor tilt en especifico el problema, sino que el reproductor mp3 es lo que estaba bloqueando todo.

En la manera que lo pude confirmar fue desconectandolo, de esa manera funcionaba perfecto, o semi perfecto igual habia un poco de problemas derrepente, pero no al punto de congelar la maquina completa.

Tambien veia que cuando nuestro motor se activaba todos los otros componentes se apagaban por una pequeña fraccion de segundo, la cual no me gustaba ver porque podia causar un problema para el futuro.

Asi que mi gran manera de solucionarlo fue cambiar exclusivamente el reproductor mp3 a una linea de alimentacion distinta que en este caso seria de 5V, todo el proyecto estaba en la misma linea para mayor conveniencia que era 3.3V debido a que el display solo podia funcionar con ese voltaje directamente al Arduino.

De esta manera funciono super bien, aun se demoraba un poco en reaccionar pero era mas que todo por los delays, pero el hecho que no se bloqueara era magnifico.

## Dia 1 de Diciembre en el LID

Hoy fui al Lid par trabajar productivamente, donde lo primero que hice fue ayudar al grupo 5 ya que me habian pedido ayuda con escrbir su codigo a clases donde Miguel Vera me mostro lo que llevaban avazado hasta el momento, y para no repetirlo que ha documentado que fue muchisimas locuras y batallas, sobretodo con el infame dfplayer mini, se puede encontrar todo en el siguiente link de su repositorio: https://github.com/disenoUdp/dis8645-2025-2-proyectos/tree/main/29-MiguelVera23/sesion-16b 

Despues nos pusimos a hablar con Morgan y la Bernardita del proyecto, donde Morgan se puso a hacer locuras de como desasernos de los delays lo cual logro, eso es bueo, aunque es una tremenda lata tener que escribir tantos distintos valores para los delays, pero bueno.

Yo despues de terminar mi monento de ayuda con el grupo 5 me puse a empezar a crear los nuevos voids que van a ser ocupados para el display primero partiendo por ese que deberia estar para comenzar la interaccion donde AVA estaria dormida y para comerzar todo se requiera presionar el boton. 

Solo acabe agregando a la AVA dormida, debido a lo que del botón solo tendría sentido que lo agregara si es que funciona para empezar, me parece que es debido a los múltiples delays que no permiten que se registre el presionado del botón.

Como Morgan se acabó volviendo loco integrar los millis yo tomaré el relevo e intentaré aplicarlos.

Me guíe a partir del siguiente link:  

https://forum.arduino.cc/t/using-millis-for-timing-a-beginners-guide/483573

Intentando aplicarlos al temporizador presente en el archivo del botón creando un intervalo de 1000 milisegundos, para poder contar los segundos que pasaban donde llegue a lo siguiente :

``` cpp
// si es que hay más de 0 segundos en el temporizador 
  // el tiempo actual del temporizador menos el nuevo tiempo del temporizador
  // equivale a un número menor al intervalo segundo, osea a menos de 1000
  if (segundos > 0 && tiempoActualTemporizador - tiempoNuevoTemporizador >= intervaloSegundo){
  // los segundos disminuyen en 1
  segundos -= 1;
  // enviar al monitor Serial la cantidad de segundos actuales
  Serial.println(segundos);
  // enviar al monitor Serial si es que el botón está siendo presionado
  Serial.println(estadoBoton);
  // se actualiza el temporizador para poder realizar la comparación con el intervalo de segundos
  tiempoNuevoTemporizador = tiempoActualTemporizador;
  }
```
Esto funcionó joya, destrabar el problema que presentaba el botón en si, que le costaba mucho el aumentar los segundos, pero como no existen delays, el feedback que se recibe al interactuar con el botón se siente casi instantáneo.

Otro problema que pude identificar en las pruebas que hizo Morgan con el intentar integrar los millis en el archivo del display, que dijo que no se mostraba bien los números correspondientes al timer, le faltaba solo una linea para poder limpiar la pantalla, como se puede observar en este extracto:

``` cpp

// IMAGEN
	// colocar la posición: x, y, establecer cuál es el bitmap que será utilizado, ancho del bitmap, alto del bitmap, color del bitmap
	// en este caso el estado neutral de Ava
	display.clearDisplay(); ←- ESTE DE AQUÍ
	display.drawBitmap(0, 0,bitmap_AVA, 48, 48, BLACK);
	// establecer las coordenadas de el siguiente texto
	display.setCursor(56, 16);
	// el texto corresponda al int "waoses"
	display.print(waoses);
	// hacer que estos datos previos se carguen al display
	display.display();

```

Con estos cambios, oficialmente pasamos a la version del WEBO_0_6_5
