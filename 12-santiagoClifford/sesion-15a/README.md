# sesion-15a

## 2025-11-18

componentes:

- 3 servo
- ultraS
- módulo mp3
- parlante
- sensor de presión

```cpp
//mono está calmao
//el sensor ultrasónico está sensando
//si no se detecta presencia, se mantiene calmao
//si una persona está a menos de 20cm del mono, pide amor
//pide amor: audio, una voz que dice "dame un abrazo"
//si se detecta un objeto a menos de 10cm, los brazos se cierran(moviendo servo01 90°)
//si no se detecta un objeto comienza la pataletaLeve
//pataletaLeve: audio llorar
//si el sensor ultrasónico detecta un objeto a menos de 5cm se interrumpe la pataleta(en teoría este objeto es un brazo)
//si pasan 10 segundos de pataletaLeve, sin que el ultrasónico detecte algo a menos de 5cm, comienza la pataleta brígida
//pataletaBrigida: audio, servo01 y servo02 se giran 20° y -20° repetidamente
//si se detecta un objeto a menos de 5cm se interrumpe la pataleta
//si pasan 10 segundos de pataletaBrigida, sin que el ultrasónico detecte un objeto a menos de 5cm, comienza la autodestrucción
//autodestrucción: reproducción de audio, el servo02 gira 120°, el servo03 gira 90 grados lentamente. Luego el servo02 vuelve a 0° lentamente, y luego a 120° velozmente.
//si el ultrasónico detecta un objeto a menos de 5cm se interrumpe la autoDestrucción. Toda esta secuencia dura en total 15 segundos, luego el servo02 se queda en 120° durante 20segundos y luevo vuelve a 0°
```

## sensor de presión

<https://www.youtube.com/watch?v=pEbdN-JzKDA>

![video del sensor de presión funcionando](./imagenes/presion.gif)
