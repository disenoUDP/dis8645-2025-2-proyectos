# sesion-13a

-04-11-2025

## Apuntes de Clase — Inteligencia Artificial & Máquinas Sentimentales

¿Cómo funciona la inteligencia artificial?

**Procesamiento de imágenes**
Las imágenes son convertidas en **matrices de números**.  
Cada pixel se transforma en valores que cambian según el entrenamiento del modelo.

**Procesamiento de palabras**
Las palabras también se representan como **matrices numéricas**, lo que permite que la IA compare, asocie y encuentre coincidencias dentro del lenguaje.  
Todo se basa en cadenas numéricas que representan significado.

La IA aprende a partir de **nuestras correcciones**, reforzando o descartando patrones.

---

### IA generativa

Un ejemplo de entrenamiento básico es el **captcha**, donde relacionamos imágenes con palabras, entregando datos para entrenar modelos.

**Tipos de procesadores para IA**
- **CPU:** procesador general; sirve para todo pero es más lento en IA.  
- **GPU:** muy rápida para cálculos paralelos, ideal para videojuegos y redes neuronales.  
- **TPU (Tensor Processing Unit):** creada por Google; especializada en IA. Varios Mac actuales la integran.  

**RNN (Red Neuronal Recurrente)**
Modelo diseñado para trabajar con información secuencial.  
Funciona por probabilidades, por eso puede equivocarse, pero es muy útil con texto o audio.

---

#### Google Colaboratory

**Google Colab** permite usar un computador alojado en servidores de Google.  
Cada usuario con una cuenta de Google puede acceder a GPUs y TPUs sin tenerlas físicamente.  
Es uno de los entornos más usados para pruebas con inteligencia artificial.

---

##### Homebrew

Herramienta que facilita instalar software, especialmente en macOS.  
Se usará para manejar **GitHub desde la terminal**.

**Instalación**
1. Entrar a https://brew.sh/  
2. Copiar el comando de instalación.  
3. Abrir la terminal.  
4. Pegar el comando.  
5. Presionar Enter y seguir los pasos.  
6. Revisar el video de instalación si es necesario.

Con esto es posible usar GitHub de forma directa, facilitando revertir commits y manejar versiones.

VS Code también puede usarse localmente, incluso si GitHub falla, ya que los archivos están guardados en el computador.

---

###### Nuevas ideas de máquinas sentimentales

**La Máquina del Error**  
Pantalla LED que intenta generar patrones perfectos, pero siempre falla en un punto.  
Si el usuario intenta corregirla, comete aún más errores, como si rechazara la perfección.

**El Halagador Engañoso**  
Cada vez que alguien pasa, suelta un halago y luego un comentario desagradable.  
Si la persona responde, el objeto produce un bufido y se silencia por 30 segundos.

**La Ofendida**  
Permanece de espaldas y se gira violentamente si alguien intenta interactuar, revelando una figura inquietante.

**La Máquina Narcisista**  
Al acercarse, emite frases presumiendo de sí misma: “Soy increíble hoy”, “mírame qué brillante estoy”.

**La Máquina del Eco Decreciente**  
Repite lo que dices, pero cada repetición pierde una sílaba hasta desaparecer.

---
