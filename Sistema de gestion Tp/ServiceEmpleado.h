#pragma once
#include "Empleado.h"

class ServiceEmpleado
{
    public:
        ServiceEmpleado();

        bool guardarEmpleado(Empleado emp);
        Empleado leerEmpleado(int pos);
        int buscarPorLegajo(int legajo);
        int getCantidadRegistros();
};
