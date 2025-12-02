# sesion-17a

## Lunes 01-12

Me voy a encargar de **intentar** cambiar de delay a millis en almenos uno de los archivos que estamos actualmente usando

Parti buscando documentación del funcionamiento de millis en cpp

### Links 

https://docs.arduino.cc/language-reference/en/functions/time/millis/

https://programarfacil.com/blog/arduino-blog/millis-micros-arduino/#La_funcion_millis_con_Arduino

https://docs.particle.io/reference/device-os/api/time/millis/

### Lo que entendi de millis 

Al final lo que logre comprender de esta función es que se utiliza para leer el tiempo exacto desde que la placa de arduino empieza a correr el código

Según su Syntax en la pagina de documentación en arduino dice que 

"Utilice la siguiente función para obtener el tiempo exacto que la placa ha estado ejecutando el programa actual en milisegundos:
```cpp
millis();
```

Millis tambien puede devolver el valor usando la función: 

```cpp
unsigned long;
```

### Más investigación de documentación

Luego de comprender como poder hacer funcionar millis(); empece a buscar documentación más especifica para poder realizar correctamente la funcion de **W.E.B.O**

Este [forum de arduino](https://forum.arduino.cc/t/using-millis-for-timing-a-beginners-guide/483573) que me recomendo seba, explica muy detalladamente como posiblemente se puede desarrollar un temporizador con millis

Este [wokwi](https://wokwi.com/projects/389461436500036609) explica como hacer parpadear el LED interno de arduino utilizando millis() cada 1 segundo.

Y esta pregunta de [stackoverflow](https://stackoverflow.com/questions/65632178/converting-code-written-with-delay-to-millis-instead), que con una de las respuestas podemos ver como cambiar de delay() a millis()

### Explicación de código

Primero empece a intentar integrar millis en display, el delay que se encuentra presente en este es tanto para el cambio de pantalla cada medio segundo o 500 millis, y para el funcionamiento del temporizador.

La versión 0_6_2 Fallo debido a que no comprendia correctamente como especificar los parametros para hacer funcionar correctamente millis

En el archivo .h defini las variables 

```cpp
   //millis
     //Memoriza el estado 
     bool memorizaEstadoDisplay = false;

     //El valor de los milisegundos
     int tiempoInicio = 500;

     //Memoriza el tiempo transcurrido para el cambio de imagen
     unsigned long tiempoTranscurrido = 0;
```

Para llamarlo en el archivo .cpp

```cpp
	  //Ejecuta si el tiempo transcurrido desde el ultimo cambio
    if(millis()-tiempoTranscurrido> tiempoInicio)

    
    {
      //Si el estado pasa de imagen o no
      memorizaEstadoDisplay =! memorizaEstadoDisplay;
   
      //Actúa sobre el display
      //digitalWrite( memorizaEstadoDisplay);
   
      //Memoriza el tiempo que transcurre desde el cambio de estado
      tiempoTranscurrido=millis();
    }
	// limpia la pantalla
	display.clearDisplay();
	// colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
	// en este caso el estado en el que Ava tiene la boca abierta
	// haciendo como si esta diciendo los segundos restantes
	display.drawBitmap(0, 0,bitmap_AVA_HABLA, 48, 48, BLACK);
	// establecer las coordenadas de el siguiente texto
	display.setCursor(56, 16);
	// el texto corresponda al int "waoses"
	// esto se vuelve a establecer debido a que se limpio la pantalla
	display.print(waoses);
	// hacer que estos datos previos se carguen al display
	display.display();
	  
		//Millis
		//Ejecuta si el tiempo transcurrido desde el ultimo cambio
    if(millis()-tiempoTranscurrido> tiempoInicio)

    
    {
      //Si el estado pasa de imagen o no
      memorizaEstadoDisplay =! memorizaEstadoDisplay;
   
      //Actúa sobre el display
 //     digitalWrite( memorizaEstadoDisplay);
   
      //Memoriza el tiempo que transcurre desde el cambio de estado
      tiempoTranscurrido=millis();
    }
```
Esto no resulto debido a que no coloque los parametros que funcionarian dentro de millis() 

En la version 0_6_3 donde en el archivo .h cambie los valores a unos que comprendiera mejor 
```cpp
   //millis
   //definir la duracion del display
   //Enum es una variable de valores incambiables
   int duracionDisplay = 500;
   
   // Definir el nombre de la variable del inicio de tiempo
   unsigned long tiempoInicio;
   // Definir el nombre de la variable del tiempo actual
   unsigned long tiempoActual;

   //definir el estado donde iniciara el tiempo
   int estado = 0;
```

En el archivo .cpp coloque los parametros de funcionamiento dentro de millis y ahi ya comenzo a funcionar 
```cpp
	unsigned long tiempoActual = millis();
	switch (estado) {
		if (tiempoActual - tiempoInicio >= duracionDisplay) {

	// limpia la pantalla
	display.clearDisplay();
	// colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
	// en este caso el estado en el que Ava tiene la boca abierta
	// haciendo como si esta diciendo los segundos restantes
	display.drawBitmap(0, 0,bitmap_AVA_HABLA, 48, 48, BLACK);
	// establecer las coordenadas de el siguiente texto
	display.setCursor(56, 16);
	// el texto corresponda al int "waoses"
	// esto se vuelve a establecer debido a que se limpio la pantalla
	display.print(waoses);
	// hacer que estos datos previos se carguen al display
	display.display();
	  
		//Millis
		}
	}	
```
Pero en la version con delay la cual seria la 0_6_1, esta funcion tiene **dos** delays, asi que en la version 0_6_4 termine por agregar el cierre del millis()
```cpp
  //millis
	unsigned long tiempoActual = millis();
	switch (estado) {
		if (tiempoActual - tiempoInicio >= duracionDisplay) {

	  // limpia la pantalla
	  display.clearDisplay();
	  // colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
	  // en este caso el estado en el que Ava tiene la boca abierta
	  // haciendo como si esta diciendo los segundos restantes
	  display.drawBitmap(0, 0,bitmap_AVA_HABLA, 48, 48, BLACK);
	  // establecer las coordenadas de el siguiente texto
	  display.setCursor(56, 16);
	  // el texto corresponda al int "waoses"
	  // esto se vuelve a establecer debido a que se limpio la pantalla
	  display.print(waoses);
	  // hacer que estos datos previos se carguen al display
	  display.display();
	  
		//Guardar el tiempo de inicio del display
	  tiempoInicio = tiempoActual;
		}
	}	
```
Lo que ocurre actualmente es que la pantalla no se esta recargando cada vez que cambia de número el temporizador.
