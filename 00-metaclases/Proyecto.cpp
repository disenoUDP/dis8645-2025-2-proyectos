#include "Proyecto.h"

Proyecto::Proyecto(int numero)
{
    Proyecto::numero = numero;
}

Proyecto::~Proyecto()
{
}

void Proyecto::agregarGrupos()
{
    Grupo nuevo;
    grupos.push_back(nuevo);
}


