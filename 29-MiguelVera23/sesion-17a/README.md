# sesion-17a

## Versión funcional de código
Este código (máquinaAsombrosa_sinFinalNiHumo.ino) hace todo como debe, las cosas funcionan en paralelo y tiene una manera rudimentaria de reiniciarse al llegar al final. Al llegar al rango 6 ocurre todo lo que debe y hace que el valor de vuelta sea 0. Así se reinicia el contador y los rangos, efectivamente desactivando todo (como corresponde en el rango 0). El problema es que en el "final de luces" del rango 6 tenemos delay que entorpece este reseteo y hace que sea manual. Las luces no se detienen como deberían ya que no tienen un fuinal delimitado. En este punto debe ocurrir el final de luces, soltar el humo y volver a rango 0. Para esto se nos ocurre una solución que usamos en otro lado: millis. Para controlar el motor los usamos y en este caso reducirían la activación de estos actuadores a un tiempo determinado para que se apaguen y reinicien. Con Braulio (y posiblemente Sebastián) dedicaremos este día para dejar lo más resuelto este aspecto y el código en general.

### Pendientes actuales (martes)
- Resolver código del humidificador.
- Que suene el último audio y que se desactive la manivela mientras se reproduce.
- Resolver leds que quedan encendidos al resetear cuenta. Podría ayudar el correr algunas interacciones entre rango dejando fiesta en el rango 5 y leds apagadas en el rango 6.
- Producir carcasa y ordenar componentes de manera real.
- Solucionar velocidad de la manivela. Por ahora el usuario tiene la opción de girar la manivela muy rápido, quitándole tiempo al audio para reproducirse.
- Añadir vueltas (12 a 30). LISTO

### Reiniciar los rangos
Para poder darle término a la interacción necesitamos una función que reinicie los rangos (y por consecuencia los componentes) para que quede disponible de nuevo. Lo difícil es hacer que se reinicie exactamente cuando queramos: después del último audio y la activación del humo. Para esto lo asociamos a la vuelta siguiente al rango 6, un teórico rango 7. De esta manera se puede reiniciar manualmente de manera separada al final. Lo que nos queda por hacer es que el audio y el humo puedan ocurrir sin que se interrumpa por este reinicio. Una opción es usar un delay (para no añadir mas millis) y ordenar las líneas para que la jerarquía nos juegue a favor.

### Tema de audio
Por ahora suenan los archivos mp3 que corresponden en cada fase pero no completos. El 1,4 y 6 se cortan antes de lo debido la mayoría del tiempo. Si mal no recuerdo el 1 y el 4 son un poco más largos que el 2 y el 3. El 6 es evidentemente más largo ya que es el último y acompaña al humo pero no es ideal que se interrumpan por el encoder (asumo).

Un cable. La razón por la que no se reproducían los audios es porque el cable de energía estaba malo. Ahora que lo cambiamos se escuchan enteros y hasta más fuerte. Lo descubrimos al hacer varias pruebas sin cambiar el código y tener resultados distintos. Lo único que resta ahora que estabilizamos el audio es hacer que el del rango 6 se reproduzca como es debido y ajustar algunos que se cambiaron.

### Humo 
Para el humidificador hicimos un código muy sencillo y lo añadimos a las clases. En este punto tenemos todos los componentes unidos y funcionando como deben pero hacen falta límites. Para el humo haremos una función que limite la activación/desactivación para que ocurra una vez. Para esto podríamos asociarlo a una vuelta específica en vez de un rango y limitarlo con millis. 

## Gráfica de la máquina
- Elementos brillantes
- Colores llamativos
- Estética de casino (elegante pero de mal gusto)
- Simbología de suerte/fortuna
- Tematicas específicas
Podríamos usar aluminio calentado con pistola de calor

## Iteración del código más avanzada
En la versión maquinaAsombrosa_MIERCOLEStodoBien.ino está todo correcto y funcionando. Al llegar al rango 6 se reproduce un audio y se suelta el humo **una vez**. Después de eso se resetea el contador y todo puede ocurrir de nuevo. Ahora solo queda afinar cosas como que el audio sea el correcto y que los cables no se suelten (VCC).

### Número/audio actual
1. Piso viejo
2. Pistón
3. Aldeano
4. Corneta
5. Ak 47
6. Cadena
