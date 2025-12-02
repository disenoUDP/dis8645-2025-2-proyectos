# sesion-16a
## martes 2 de diciembre avances
### cansado


- logramos integrar el módulo del motor a las vueltas del encoder
- de momento funciona el encoder, leds, sonidos y motor



#### ERRORES A CONSIDERAR Y VER CON SEBA

- en algún punto del día, más en la tarde, el encoder dejó de sumar
- llegaba a rango 5 y en vez de sumar comenzaba a restar
- luego de restar llegaba a rango 6, en rango 6 se supone que se apaga todo y se reinicia
- tenemos la hipótesis de que el arduino y encoder al estar tanto tiempo funcionando, esto pudiera afectar el funcionamiento del encoder y la lectura de rangos
- otros factores a considerar: quizá comprar otro encoder por si se dañó el actual o algo similar
- traspasar el circuito a otra proto para tenerlo todo unificado
- antes de traspasar el circuito a otra proto, probaría mañana a ver si influye el paso del tiempo
