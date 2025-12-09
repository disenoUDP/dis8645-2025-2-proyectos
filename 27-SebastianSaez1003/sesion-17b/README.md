# sesion-17b

Después de tantas pruebas, quería comprobar que si en el tilt sensor lo que causaba que se pegara todo, pero no, era todo culpa del dfplayer, habían 2 razones posibles, 1 que era que estaba mal conectado el rt y el tx, que puede haber sido una tonteria despues de tanto tiempo que andaba probando esto, o la otra era que cambiase de utilizar softwareSerial, algo que al parecer no funciona muy bien en el arduino uno r4 Mínima, sino utilizar un estilo ya nativo que se llamaba Serial1, que utiliza los pines 0 y 1 del arduino sin siquiera necesidad de establecer pines en pinmode. probé ambos cambios simultáneamente y fue excelente, no quiero volver atrás en el tiempo como para probar cada uno individualmente, solo se que soy feliz y subire el WEBO_0_7_2.

Le pregunté a Aaron si es que era buena idea crear un archivo por separado para solo globalizar los timers que he seteado para todos los componentes así que los traspasé y por ahora se ve todo bien. 

Igual pensé que podría hacer que algunos de los parámetros estén presentes en uno de esos archivos, como por ejemplo si está caído, todo para que se vea precioso el .ino y solo están ocurriendo las cosas constantemente, en un principio pensé usarlo solo para los temporizadores pero me di cuenta que igual era conveniente para mas que solo eso como variables globales, donde puedo escribir cosas como si los motores están girando actualmente, si esta caido el WEBO y el pasar de los segundos entre otras cosas.

Aunque también puede quedar medio fome, tendré que preguntar que opinan los profes.

También me puse a hacer la pantalla de la AVA girando cuando se activa el motor a partir de switch cases con el siguiente ejemplo : 

https://docs.arduino.cc/language-reference/en/structure/control-structure/switchCase/

Para que se hagan los cambios rápidos de menos de medio segundo de cómo AVA gira en cada frame, quedó más o menos así:


```cpp

void ActuadorDisplay::girandoDisplay() {
	// si es que el temporizador tiene mas que 0 segundos y el motor esta prendido
	if (segundosTiempo > 0 && !motorPrendido) {
		// cambiar rapidamente los frames del giro de la AVA
		switch (posicionDeGiro) {
			case 0:
				if (tiempoActualDisplay - tiempoDeGiro0 >= cambioGiro) {
					display.setTextSize(2);

					Serial.println("Estoy hablando");
					// colocar la posición: x, y, establecer cuál es el bitmap que será utilizado, ancho del bitmap, alto del bitmap, color del bitmap
					// limpia la pantalla
					display.clearDisplay();

					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);

					display.display();
					// establecer las coordenadas de el siguiente texto
					posicionDeGiro = 1;
					tiempoDeGiro1 = tiempoActualDisplay;
				}
				break;

			case 1:
				if (tiempoActualDisplay - tiempoDeGiro1 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					// colocar la posicion: x, y, establecer cual es el bitmap que sera utilizado, ancho del bitmap, alto del bitmap, color del bitmap
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_TRESCUARTOSIZQ, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// establecer las coordenadas de el siguiente texto
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					posicionDeGiro = 2;
					tiempoDeGiro2 = tiempoActualDisplay;
				}
				break;

			case 2:
				if (tiempoActualDisplay - tiempoDeGiro2 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_PERFILIZQ, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					posicionDeGiro = 3;
					tiempoDeGiro3 = tiempoActualDisplay;
				}
				break;

			case 3:
				if (tiempoActualDisplay - tiempoDeGiro3 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_ESPALDA, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					posicionDeGiro = 4;
					tiempoDeGiro4 = tiempoActualDisplay;
				}
				break;

			case 4:
				if (tiempoActualDisplay - tiempoDeGiro4 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_PERFILDER, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					// esto permite que el giro sea un loop
					posicionDeGiro = 5;
					tiempoDeGiro5 = tiempoActualDisplay;
				}
				break;

				case 5:
				if (tiempoActualDisplay - tiempoDeGiro5 >= cambioGiro) {
					Serial.println("No estoy hablando");
					// limpia la pantalla
					display.clearDisplay();
					display.setCursor(56, 16);
					// poner cual de todos los giros de AVA es actualmente
					display.drawBitmap(0, 0, bitmap_AVA_TRESCUARTOSDER, 48, 48, BLACK);

					// el texto corresponda al int "segundosTiempo"
					display.print(segundosTiempo);
					// hacer que estos datos previos se carguen al display
					display.display();
					//Guardar el tiempo de inicio del display
					// esto permite que el giro sea un loop
					posicionDeGiro = 0;
					tiempoDeGiro0 = tiempoActualDisplay;
				}
				break;
		}
	}
}

```
