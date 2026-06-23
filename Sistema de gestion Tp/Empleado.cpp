
#include "Empleado.h"


Empleado:: Empleado(){

}

void Empleado::setLegajo(int legajo)
{
    _legajo = legajo;
}

int Empleado::getLegajo()
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

