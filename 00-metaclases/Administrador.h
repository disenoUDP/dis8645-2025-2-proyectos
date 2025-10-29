#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>
#include "Estudiante.h"
#include "Encargo.h"
#include "ListaEstudiantes.h"

class Administrador
{
public:
    Administrador();
    ~Administrador();
    ListaEstudiantes lista;


private:
    std::vector<Estudiante> estudiantes;
    std::vector<Encargo> encargos;
};

#endif
