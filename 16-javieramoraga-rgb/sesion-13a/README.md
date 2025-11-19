# sesion-13a ✶⋆.˚

## Ideas iniciales

────୨ৎ────

# Máquina de la Ansiedad

### **Emociones**
Inquietud, anticipación, tensión.

### **Concepto**
La máquina vibra o se mueve de forma irregular, como si estuviera esperando algo. Reacciona a la cercanía: cuando alguien se aproxima, comienza a tiritar con más intensidad, y solo cuando la persona se aleja la vibración disminuye lentamente.  
No diferencia entre estímulos de cuidado o amenaza; cualquier presencia puede alterarla.  
Representa el cuerpo ansioso que, incluso en un estado “calmo”, siente que algo podría salir mal.

### **Materiales**
- Placa Arduino Uno + cable (ya disponible)  
- Protoboard  
- Cables  

**Actuadores**
- Motor vibrador PWM Switch DC: responsable del temblor/vibración.  
- Módulo Mosfet IRF520: permite controlar encendido y potencia del motor (PWM).

**Sensor**
- Sensor ultrasónico HC-SR04: mide distancia y detecta presencia cercana.

**Notas sobre el comportamiento**
El cuerpo de la máquina debería ser ligero y resonante para amplificar la vibración.  
Desde el inicio mantiene una vibración mínima (PWM bajo), simulando la tensión basal de la ansiedad.  
Al detectar proximidad, la vibración aumenta con picos irregulares y acelerados.  
Si la persona está muy cerca, la máquina entra en “pánico” y vibra a intensidad máxima (PWM 255).  
Al retirarse la presencia, la vibración baja **de forma lenta y prolongada**, mostrando que la tensión residual tarda en desaparecer incluso cuando el “peligro” ya pasó.

────୨ৎ────

# Máquina de la Vergüenza

### **Emociones**
Incomodidad, rechazo.

### **Concepto**
No soporta ser observada. Ante una presencia cercana, gira o se oculta rápidamente.  
Si nadie la mira, se mueve de manera tímida o emite una luz tenue, disfrutando del anonimato.  
Tiene una personalidad introspectiva: teme la exposición y prefiere pasar desapercibida.

### **Materiales**
- Placa Arduino Uno + cable (ya disponible)  
- Protoboard  
- Cables  

**Sensor**
- Sensor ultrasónico HC-SR04: detecta proximidad.

**Actuadores**
- Micro Servomotor SG90: permite movimientos sigilosos de ocultamiento y gestos tímidos.  
- Diodo LED (rojo u otro color): luz tenue controlada con PWM para simular su estado tranquilo cuando nadie la observa.  
- Resistencia de 220Ω para proteger el LED.

### **Estados de comportamiento**
**1. Anonimato (estado predeterminado)**  
- Ocurre cuando el sensor detecta mucha distancia.  
- LED encendido con brillo suave (PWM).  
- Servomotor con movimientos lentos y tímidos.

**2. Rechazo (presencia detectada)**  
- El servomotor actúa con velocidad para ocultarse.  
- El LED se apaga abruptamente.  
- El regreso al estado de Anonimato es gradual, después de un pequeño retraso, una vez que la presencia desaparece.

────୨ৎ────

# Máquina Negadora

### **Emociones**
Negación, tristeza, vulnerabilidad.

### **Concepto**
Esta máquina aparenta estar “bien” cuando alguien la observa: colores alegres, sonidos agradables y postura controlada.  
Pero cuando está sola, cambia totalmente: se apaga, se vuelve sombría o emite sonidos extraños.  
Su reacción depende de la atención: frente a otros se controla, en soledad se deja caer.

### **Materiales**
- Placa Arduino Uno + cable (ya disponible)  
- Protoboard  
- Cables  

**Sensor**
- Sensor ultrasónico HC-SR04: presencia = actuación / ausencia = desplome.

**Actuadores**
- Diodo LED RGB 5mm: muestra colores alegres en “simulación” y tonos oscuros (o apagado) en vulnerabilidad.  
- Buzzer pasivo: genera melodías alegres o sonidos disonantes usando `tone()`.  
- Micro Servomotor SG90: mantiene postura erguida o permite que el objeto “caiga”.  
- Resistencias de 220Ω para cada canal del LED RGB.

### **Estados de comportamiento**
**1. Simulación (presencia detectada)**  
- LED RGB con colores vivos.  
- Buzzer con melodías consistentes.  
- Servomotor sosteniendo la postura estable y controlada.

**2. Vulnerabilidad (sin presencia)**  
- Movimiento de desplome con el servomotor.  
- LED en tonalidades muy tenues u oscuras, o completamente apagado.  
- Sonidos disonantes o casi inaudibles en el Buzzer.

────୨ৎ────

### ✦ Reflexión final
Inspiradas en la relación entre interacción humana y emoción contenida, estas máquinas exploran la materialización de sentimientos a través de luz, vibración, sonido y movimiento.  
Funcionan como pequeños organismos emocionales que, aunque digitales, imitan formas humanas de recordar, esperar y sentir.