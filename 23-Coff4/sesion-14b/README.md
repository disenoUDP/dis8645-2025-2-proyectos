# sesion-14b

Por esta clase se intentara ver un pseudocodigo para a continuacion ver como deben de funcionar las cosas

- Mono comienza en un estado "inactivo"
- En todo momento el sensor ultrasonico "sensara" el alrededor
- Cuando se detecte a una persona en una distancia aproximada de 20 cm se emitiran diferentes frases
- A esta etapa se le conoce como "buscando amor"
- Se reproduciran 3 pistas de audio diferentes de manera aleatoria para llamar la atención de la persona
- Una vez se acerque el brazo de la persona en un rango de 10 a 5 cm los brazos se accionaran. Esta etapa es: Amor recibido
- Pero si no se acerca el brazo en un intervalo de 30 segundos, se activara la primera fase de "Pataleta"
- Pataleta leve: Se reproduce uno de 3 audios diferentes y con ello un sonido fijo de monos "sufriendo" por la falta de cariño
- Si pasan 20 segundos más (aproximadamente) se comenzara con la fase 2
- Pataleta media/brigida: Los brazos se mueven de manera erratica dando la sensacion de temblores, se reproducen audios más impactantes y con ello un segundo audio random
- Al pasar por ambas fases y con 10 segundos de inactividad más, se activara la ultima fase
- Modo autodestrucción: El mono gira su torso hasta llegar a su "espalda" en donde se encontrara un botón (en donde se dirá "Autodestrucción" para hacerlo dramatico) para acto seguido presionarlo con la cabeza
- El mono se quedara de manera estatica en una simulación de que esté muerto por los siguientes 15 a 20 segundos
- Con todo ocurrido, volvera a su estado inicial


1. ¿Hay alguien cerca?

Si detecta una "Presencia": El Monkey inicia su fase de "Pedir Amor".

- Si NO detecta una "Presencia": El BR se queda "En Espera" (standBy).

2. Pidiendo Amor
3. 
Una vez que el Monito está pidiendo amor, tiene dos resultados posibles:

Si recibe el "Amor":

El Monito se "Agarra" (da el abrazo).

Si NO recibe el "Amor":

El pequeño inicia una "Pataleta". 

Esto consta de 3 fases.


---
```cpp

int tiempoTranscurrido;
bool presenciaDetectada;
bool amorRecibido;

presenciaDetectada = true;
amorRecibido = false;

if (presenciaDetectada) {
    // Si hay alguien, iniciamos la "Petición de Amor"
    printf("¡Presencia detectada! Pidiendo amor..."); + Reproduccion de audio (RandomSeed)

if (amorRecibido) {
        // Accion: agarrarBrazo()
        printf("Amor Recibido. Sistema APEGADO y con cariño!");
        tiempoTranscurrido = 0; // Reiniciamos el tiempo
    } else {
        // Si no hay amor, iniciamos la "Pataleta"
           print(ACASO NO TE AGRADO?!) + Audio

if (tiempoTranscurrido > 45 seg) {
            // Accion: autoDestruccion()
            printf(Sistema de autodestrucción activada"); + Audio + Movimiento del motor hacia el botón
        
    }
// esta variable deberia cambiarse para cada pataleta

// en estos casos creo que ddeberia de hacerlo con "else"

if (tiempoTranscurrido > 25 seg) {
            // Accion: pataletaMedia()
            printf("Gritos de mono"); + Audio + movimiento del motor (para simular vibración)

if (tiempoTranscurrido > 10 seg) {
            // Accion: pataletaLeve()
            printf("vamos acercate por favor"); + Audio

```

![alt text](http://url/to/img.png)

![alt text](http://url/to/img.png)

![alt text](http://url/to/img.png)

![alt text](http://url/to/img.png)


  
