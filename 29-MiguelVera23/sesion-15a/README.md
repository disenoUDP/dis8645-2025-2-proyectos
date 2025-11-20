# sesion-15a

## Pre solemne

En este punto lo más importante es manejar la manivela, desde ahí solo restará asociar todo a sus funciones y emparejar la nomenclatura del código. El mayor problema con el que me he encontrado es el reproductor mp3. Si bien el código está como debería, simulando la manivela pero funcional, algún problema en el cableado o el setup del DFPlayer evita que el audio se reproduzca. Para esta entrega podemos usar los otros elementos que demuestran progreso pero la verdad es que el audio es el 2do punto más importante, después del humo. Seguiré probando otras conexiones y de no lograrlo hoy lo veré con mi grupo mañana, ya que estoy seguro que es un problema muy específico del que nos reiremos cuando lo descubramos. Para el audio ya está el código y los sonidos cargados en la tarjeta sd pero necesitamos hacer el código que active todo junto. Intentaré recopilar todo y hacer funciones que llamen a los actuadores para que no quede tan atiborrado. La versión del código de audio actual es ***AudioHumo3*** y lo subiré a esta sesión. Viene con una función que deja controlar los valores sin necesidad de encoder, que podemos sacar sin que afecte al código (cortesía chatgpt).

### ENTREGA 21/11
- Documento textual de sentimiento y metáfora 
- Pseudocódigo
- Diagrama de flujo
- Bill of Materials (lista de materiales) ✅
- Instrucciones
- Contexto de uso
- Circuito del dispositivo (construcción)


### Código conjunto (básico)
Revisar venduHumoFull.ino

### Código audio
- Revisar audioHumo4. ino
En esta versión se reproduce audio

## Código mata-Arduino
En este punto el código del audio funcionó pero, en palabras de mi compañero Sebastián, mató al arduino. Está en un estado en el que mi computador apenas lo detecta y da problemas de funcionamiento fuera del código. 

### Código audio ahora si
Revisar audiohumo5.ino. Funciona con los audios cruzados pero no importa realmente. Es necesario probar con el encoder ya que las funciones estáticas no son lo mismo. Usaré el código de Felix para derivar una función booliana que se active al sumar vueltas. Esta función alternará brevemente para activar audio. La idea es que reciba un dato a la vez para que no se superpongan los audios. La lógica de los rangos funciona bien y solo es necesario traerla de un código a otro. Idealmente fusionaré el código de audio con el de encoder para mañana.

