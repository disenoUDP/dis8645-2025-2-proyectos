# sesion-13a
## clase 
Hoy vimos cómo funciona la IA generativa y básicamente todo se resume en que las máquinas aprenden convirtiendo cosas en números.
Para las imágenes → cada píxel en números (tensores).
Para el texto → palabras con contexto.
Por eso existen los CAPTCHA, porque ayudan a entrenar a las IAs a reconocer objetos.

También hablamos de los chips:

CPU = hace de todo pero lento para IA

GPU = buena para cálculos en paralelo

TPU = creación de Google, turbo para IA (se usa harto en proyectos grandes)

Modelos de IA que vimos:

RNN → para cosas en secuencia (texto, música, etc.)

GAN → 2 redes que compiten entre sí (Ian Goodfellow)

Stable Diffusion → parte con ruido y va comparando hasta formar una imagen

Google Colab → Google te presta un compu con GPU/TPU gratis

Homebrew → para instalar cosas por consola (lo necesitamos para usar GitHub desde terminal)

### trabajo grupo 3 
Partimos con la idea del tamagotchi dependiente de música, que necesitaba que el usuario produjera sonido para “mantenerlo vivo”. Pero era muy difícil de justificar porque es complicado definir qué es música y qué no, así que la idea se fue afinando.
Decidimos mantener el concepto de una mascota demandante, tóxica y emocionalmente desgastante, pero sin depender específicamente de música.
→ La nueva dirección es un tamagotchi diseñado para generar culpa: si no le das atención se queja 
Cada vez que YRA se cae o se inclina demasiado, entra en un estado de angustia y sufrimiento, obligando al usuario a levantarlo inmediatamente.
O sea: si no lo mantienes erguido, “sufre” y te recuerda que fue tu culpa que se cayó.
