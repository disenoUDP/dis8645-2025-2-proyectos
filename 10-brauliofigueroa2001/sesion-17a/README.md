# sesion-17a
## jueves 4 de diciembre

### observaciones código

código miercolestodobien

- reproduce leds audios y motor bien, de momento está desconectado el humidificador pero ayer lo activaba
- los audios aún se cortan, anotar cuáles fases dan errores


código miercolesaaron

- reproduce medianamente bien los audios
- los audios de fase 4 y fase 5 se suelen cortar, a veces se corta el audio de fase 2
- los audios que mejor suenan son en fase 1 y en fase 3, no sé por qué
- en el monitor serial de audio en modo prueba, muestra las fases 1,2,3,4,5,6 en orden
- mientras está en una fase, sólo arroja que está en fase 1 una vez y suena un audio
- si seguimos girando encoder, llega a fase 2 y suena audio 2, no muestra nada más


 #### ESTADÍSTICAS DE FALLOS DEL CÓDIGO, CUÁLES FALLAN, CUÁLES FUNCIONAN BIEN EN AUDIO

- ronda 1: audio fase 1 bien, audio fase 2 se corta, audio fase 3 bien, audio fase 4 se corta, audio fase 5 se corta, audio fase 6 bien
  
- pequeña observación, al girar mientras dice REINICIO, hay un pequeño periodo de tiempo en que no suma aunque gire
  
- ronda 2: audio fase 1 bien, audio fase 2 se corta, audio fase 3 bien, audio fase 4 no sonó, audio fase 5 se cortó, audio fase 6 se cortó al final

- ronda 3: audio fase 1 se cortó, audio fase 2 se cortó, audio fase 3 bien, audio fase 4 no sonó, audio fase 5 se cortó, audio fase 6 bien

- ronda 4: audio fase 1 bien, audio fase 2 se cortó, audio fase 3 bien, audio fase 4 se cortó, audio fase 5 se cortó, audio fase 6 bien

- ronda 5: audio fase 1 bien, audio fase 2 no sonó, audio fase 3 no sonó, audio fase 4 no sonó, audio fase 5 no sonó, audio 6 no sonó
- creo que en esta ronda se desconectó algún cable

- ronda 6: audio fase 1 no sonó, audio fase 2 no sonó, audio fase 3 no sonó, audio fase 4 no sonó, audio fase 5 no sonó, audio fase 6 no sonó

- ronda 7: audio fase 1 no sonó, audio fase 2 no sonó, audio fase 3 no sonó, audio fase 4 no sonó, audio fase 5 no sonó, audio fase 6 no sonó

 ( conecté y desconecté el arduino)

- ronda 8: audio fase 1 se cortó, audio fase 2 se cortó, audio fase 3 bien, audio fase 4 se cortó, audio fase 5 se cortó, audio fase 6 bien

- ronda 9: audio fase 1 se cortó, audio fase 2 se cortó, audio fase 3 no sonó/se cortó, audio fase 4 se cortó, audio fase 5 se cortó, audio fase 6 sonó

- ronda 10: audio fase 1 se cortó, audio fase 2 se cortó, audio fase 3 bien, audio fase 4 se cortó, audio fase 5 se cortó, audio fase 6 bien

 DE LAS 10 RONDAS, SE DIERON LOS SIGUIENTES RESULTADOS:

- audio fase 1: SONÓ BIEN 3 VECES, SE CORTÓ 3 VECES, NO SONÓ 2 VECES
- audio fase 2: NO SONÓ BIEN NINGUNA,SE CORTÓ 7 VECES, NO SONÓ 3 VECES
- audio fase 3: SONÓ BIEN 6 VECES, SE CORTÓ 1 VEZ, NO SONÓ 3 VECES
- audio fase 4: NO SONÓ BIEN NINGUNA, SE CORTÓ 5 VECES, NO SONÓ 5 VECES
- audio fase 5: NO SONÓ BIEN NINGUNA, SE CORTÓ 7 VECES, NO SONÓ 3 VECES
- audio fase 6: SONÓ BIEN 5 VECES, SE CORTÓ 1 VEZ, NO SONÓ 4 VECES

A PARTIR DE LA RONDA 5, FALLÓ TODO RONDA 5,6 Y 7, LUEGO DE REINICIARLO VOLVIÓ A FUNCIONAR MEDIANAMENTE BIEN

- preguntas, observaciones,: ¿ por qué el audio 3 es el que presenta mayor efectividad?
- el audio de la fase 1 es el mismo que el de la fase 6

ANÁLISIS CÓDIGO MIÉRCOLESTODO BIEN ESTADÍSTICAS DE AUDIOS

- ronda 1: audio fase 1: bien. fase 2: bien, fase: 3 bien. fase 4: bien. fase 5: bien. fase 6: se cortó.
  
- ronda 2: audio fase 1: bien, fase 2: bien, fase 3: bien, fase 4: se cortó,bien. fase 5: bien,bien. fase 6: bien
  
- ronda 3: audio fase 1: bien,bien,bien. fase 2: bien,bien,bien. fase 3: bien,bien,bien. fase 4: bien,bien. fase 5: bien,bien. fase6: bien

- ronda 4: audio fase 1: bien,bien. fase 2: bien,bien,bien. fase 3: bien,bien,bien. fase 4: bien,bien audio fase 5:bien,bien. fase 6: bien
 
- ronda 5: audio fase 1: bien,bien,bien. fase 2: bien,bien,bien. fase 3: bien,bien,bien. fase 4: bien,bien.fase 5: bien,bien,bien.fase 6:bien
 
- ronda 6: audio fase 1: bien,bien,bien. fase 2: bien,bien,bien. audio fase3: bien,bien,bien. audio fase 4: bien,bien. fase 5: bien. fase 6: bien
 
- ronda 7: audio fase 1: bien,bien. fase 2: bien,bien,bien. fase 3: bien,bien,bien. fase 4: bien,bien.fase 5: bien. fase 6: bien
  
- ronda 8: audio fase 1: bien,bien,bien. fase 2: bien,bien,bien. fase 3: bien,bien,bien. fase 4: bien,bien, fase 5: bien,bien, fase 6: bien
  
- ronda 9: audio fase 1: bien,bien,bien. fase 2: bien,bien,bien. fase 3: bien,bien,bien. fase 4: bien,bien,bien fase 5: bien,bien. fase 6:bien
  
- ronda 10: audio fase 1: bien,bien,bien. fase 2: bien,bien,bien.fase 3: bien,bien,bien. fase 4: bien,bien. fase 5: bien. fase 6: bien




  
