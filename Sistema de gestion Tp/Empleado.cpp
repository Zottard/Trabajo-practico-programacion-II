
#include "Empleado.h"


Empleado:: Empleado(){

}

void Empleado::setlegajo(int legajo)
{
    _legajo = legajo;
}

int Empleado::getlegajo()
{
    return _legajo;
}

void Empleado::setesAdmin(bool esAdmin)
{
    _esAdmin = esAdmin;
}

bool Empleado::getesAdmin()
{
    return _esAdmin;
}

