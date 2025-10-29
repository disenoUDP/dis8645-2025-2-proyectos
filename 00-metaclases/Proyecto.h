#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>
#include <vector>

#include "Grupo.h"

class Proyecto
{

public:
    // constructor
    Proyecto(int numero);

    void agregarGrupos();

private:
    // destructor
    ~Proyecto();

    // vector de Grupo
    std::vector<Grupo> grupos;

    // numero de grupo
    int numero;
};

#endif
