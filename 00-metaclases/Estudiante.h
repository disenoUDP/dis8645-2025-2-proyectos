#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante
{
public:
    Estudiante(std::string &nombre, int numeroLista);
    void mostrarInformacion();

private:
    std::string nombre;
    int numeroLista;
};

#endif // ESTUDIANTE_H
