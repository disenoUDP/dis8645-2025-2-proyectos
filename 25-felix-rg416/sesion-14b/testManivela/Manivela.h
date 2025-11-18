#ifndef MANIVELA_H
#define MANIVELA_H

class Manivela {
    public:

    Manivela();

    ~Manivela();

    void configurar();

    void calculoVueltas();

    void rangos();
    void rango0();
    void rango1();  
    void rango2();
    void rango3();
    void rango4();
    void rango5();
    
    // patitas del encoder
    int patitaCLK = 2;
    int patitaDT = 3;
    int patitaSW = 4;

    int estadoActualCLK;
    int ultimoEstadoCLK;

    // int para el cálculo de vueltas
    int paso = 0;
    int vueltas = 0;
    int getVueltas();
    int rango;

    String direccionActual = "";
    unsigned long ultimaPresionBoton = 0;
};
#endif