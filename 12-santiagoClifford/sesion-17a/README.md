# sesion-17a

## mas pseudo

// llamar a SonicFuncionar(sensor ultrasonico esta "buscando" una presencia a menos de 40cm)
// si hay presencia a menos de 40cm, el bool "cariñoPotencial" = true,
// if(cariñoPotencial==true){ ESTADO = 1.PEDIR_AMOR}
// ESTADO = 1. PEDIR_AMOR -> llamar a N3P::emitirAlarma

// si SensarTacto  sensa presion, bool watitaRascada=true -> llamar a MotorMarvel::abrazar
//if(watitaRascada==true){ESTADO = 0.CALMAO}

// si SensarTacto sensa 0 tacto, bool seMarcho=true
// if(seMarcho==true){ESTADO = 2. PATALETA_LEVE}
// si SensarTacto activa la bool watitaRascada -> ESTADO = 0.CALMAO
//if(watitaRascada==true){ESTADO = 0.CALMAO}

// si pasan 6 segundos desde que se activo la bool seMarcho, ESTADO = 3. PATALETA_BRIGIDA
// si SensarTacto activa la bool watitaRascada -> ESTADO = 0. CALMAO
// if(watitaRascada==true){ESTADO = 0.CALMAO}


// si pasan 6+9 segundos desde que se activo la bool seMarcho, ESTADO = 4. AUTODESTRUCCION
// si SensarTacto activa la bool watitaRascada -> ESTADO = 0. CALMAO
// if(watitaRascada==true){ESTADO = 0.CALMAO}
