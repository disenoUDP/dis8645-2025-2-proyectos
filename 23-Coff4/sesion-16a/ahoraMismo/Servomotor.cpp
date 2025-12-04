#include "Servomotor.h"

Servo motoLumbar;
Servo motoRotor;

ActuadorServomotor::ActuadorServomotor(){} 

// establecer codigo necesario para funcionamiento
// del servomotor

void ActuadorServomotor::configurar() {
  // configurar en que pin conectar el servo
  // que en este caso sera el pin 9
  motoLumbar.attach(4);
  motoRotor.attach(12);;
}

// establecer las acciones que se realizaran
// al llamar a moverBrazo
void ActuadorServo::moverBrazo() {    
    }
   // vuelve a posicion inicial el brazo
   actBrazo.write(saludoNeu);

   case PATALETA_BRIGIDA:
    //esta caso, corresponde a cuando el mono comienza a desesperarse por obtener lo que quiere
      Serial.println("ESTADO: PATALETA_BRIGIDA");

      {
        int angulo = 20 * sin(millis() / 200.0);
        motoLumbar.write(90 + angulo);
        Serial.println("chillidos y quejas");

        if (hayBrazo) {
          Serial.println("ke ricooo gracias");
          Serial.println("-el mono se ha calmado-");

          motoMoto();
          motoLumbar.write(90);
          estadoActual = CALMAO;
          Serial.println("😊 TRANSICIÓN: PATALETA_BRIGIDA → CALMAO");
        }

        if (!hayBrazo && millis() - tiempoInicioEstado > 10000) {
          estadoActual = AUTODESTRUCCION;
          tiempoInicioEstado = millis();
          //emular audio
          Serial.println("chillidos y gritos desesperados");
        }
      }
      break;

    case AUTODESTRUCCION:
    //este caso, corresponde a cuando, por el bien del mono, un ente externo acabará con su existencia
      {
        Serial.println("ESTADO: AUTODESTRUCCION");
        unsigned long tiempoAutodestruccion = millis() - tiempoInicioEstado;
       
        if (hayBrazo) {
          Serial.println("ke ricooo grax");
          Serial.println("-el mono se ha calmado-");

          motoMoto();
          motoRotor.write(0);
          motoLumbar.write(90);
          estadoActual = CALMAO;
          Serial.println("ESTADO: CALMAO");
          break;
        }

        //secuencia autodestrucción
        if (tiempoAutodestruccion < 5000) {
          motoLumbar.write(90);
          Serial.println("posición aflijido");
        } else if (tiempoAutodestruccion < 10000) {
          motoRotor.write(120);
          Serial.println("motor de rotacion gira lentamente");
        } else if (tiempoAutodestruccion < 15000) {
}