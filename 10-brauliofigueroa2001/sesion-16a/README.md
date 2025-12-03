# sesion-16a
## martes 2 de diciembre avances
### cansado


- logramos integrar el módulo del motor a las vueltas del encoder
- de momento funciona el encoder, leds, sonidos y motor



cosas para ver con seba

- en algún punto del día, más en la tarde, el encoder dejó de sumar
- llegaba a rango 5 y en vez de sumar comenzaba a restar
- luego de restar llegaba a rango 6, en rango 6 se supone que se apaga todo y se reinicia
- tenemos la hipótesis de que el arduino y encoder al estar tanto tiempo funcionando, esto pudiera afectar el funcionamiento del encoder y la lectura de rangos
- otros factores a considerar: quizá comprar otro encoder por si se dañó el actual o algo similar
- traspasar el circuito a otra proto para tenerlo todo unificado
- antes de traspasar el circuito a otra proto, probaría mañana a ver si influye el paso del tiempo-
- probé a las 19:45 aprox si funcionaba otra vez el arduino y el encoder, ahora funciona y suma hasta el rango 5, al llegar al 5 deja de sumar y no llega al 6, al menos ahora suma, hace un rato no sumaba ni en el rango 2
- tengo la teoría de que el delay bugea el sonido y la lectura de vueltas del encoder


 #### ERRORES para mateo y aarón

- la suma de los rangos de 1 a 5 funciona bien
- los sonidos del mp3 a veces se interrumpen, no sabemos bien por qué
- cuando llega al rango 5 girando el encoder, se encienden los leds de forma alternada
- el problema es que si seguimos girando el encoder estando en rango 5, comienza a restar en vez de sumar
- después de esto debería proceder el rango 6, en este se apaga todo y se reinicia, vuelve a vuelta 0 de encoder, esto significa partir el giro del encoder desde 0

  ```cpp
  if (nivelLuz == 5){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(300);
}
```
- tenemos la teoría de que este delay irrumpe en el funcionamiento del encoder y de la reproducción de sonido en el rango 6, por eso se debe bugear todo
- no sé si el utilizar millis tal como fue utilizado en vibrador.h y vibrador.cpp podría arreglar este problema



#### miércoles 3 diciembre


- el código del humo y el high low de la celebración de luces tienen delay
- cómo traspasar a millis estas 2 secciones y probar
- ambos utilizan high y low en intervalos cortos, sólo encendido y apagado, varían en los tiempos que está encendido y apagado cada uno pero no es como en el motor en donde teníamos 3 velocidades distintas para cada high y low


