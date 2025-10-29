#ifndef GRUPOH_H
#define GRUPOH_H

#include <string>
#include <vector>

#include "Estudiante.h"

class Grupo
{

public:
    Grupo();
    void agregarEstudiante(Estudiante agregade);

private:
    std::vector<Estudiante> estudiantes;
};

#endif
