// código grupo-03 GEE: Grupo Emocionalmente Estable
// integrantes: Aileen D'Espessailles, Santiago Gaete, Jose Morales, Carla Pino, Francisco Stephens

// jorgito tiene apego emocional
// jorgito es un robot que busca ser amado. Las formas en las que se ha relacionado 
// con la gente a lo largo de su corta vida, han moldeado su comportamiento y 
// forma de enfrentarse a distintas situaciones. 

// esto lo ha llevado a buscar el amor que tanto necesita de manera poco ortodoxas.
// jorgito se muestra dócil y cariñoso, pero una vez consigue tu atención y amor, 
// no quiere dejarte ir. Ahora eres lo mas importante para jorgito. jorgito te ama,
// por favor no lo decepciones.

// este codigo funciona en base a 5 estados, del 0-4

// parte en estado 0
// estados 0, 1, 2, 3 pueden avanzar al siguiente
// estados 2, 3, 4 pueden volver al 0
// estado 4 tras terminar vuelve al 0

// ESTADOS
// 0_CALMAO: sensor ultrasonico
// 1_PEDIR_AMOR: sensor de presion
// 2_PATALETA_LEVE: mp3
// 3_PATALETA_BRIGIDA: servo columna, mp3
// 4_AUTODESTRUCCION: servo rotacion, servo columna, mp3, motorDC

// archivos de audio por estado
// 0 - no hay
// 1 - hay 3 opciones
// 2 - hay 3 opciones
// 3 - hay 3 opciones
// 4 - hay 1, es largo

// sintaxis

// sensor ultrasonico "sonic"
// referencia a sonic the hedgehog
// trix = trigger
// ekeko = echo

// modulo mp3 "ActuadorN3P"
// referencia a michael scott

// sensor de presion "SensorDePresion"

// motor DC "motorMarvel"
// referencia a marvel y dc comics

// servo motor "ActuadorSielvo"
// juego de palabras


// agradecimientos

// agradecemos enormente al equipo docente y nuestres compañeres por
// el grato ambiente y la actitud positiva. Especialmente a sebastian saez,
// mateo arce, aaron montoya, morgan aravena, camila parada y braulio figueroa.