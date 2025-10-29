#include "Administrador.h"

Administrador::Administrador()
{
    // constructor
    for (int i = 0; i < Administrador::lista.lista.size(); i++)
    {
        Estudiante nuevoEstudiante(Administrador::lista.lista[i], i);
        Administrador::estudiantes.push_back(nuevoEstudiante);
    }
}

Administrador::~Administrador()
{
    // destructor
}
