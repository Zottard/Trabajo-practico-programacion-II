#include <iostream>
#include <cstdio>
#include "ServiceEmpleado.h"

using namespace std;

ServiceEmpleado::ServiceEmpleado()
{
}

bool ServiceEmpleado::guardarEmpleado(Empleado emp)
{
    FILE* archivoEmpleado = fopen("Empleados.dat", "ab");
    if(archivoEmpleado != nullptr)
    {
        fwrite(&emp, sizeof(Empleado), 1, archivoEmpleado);
        fclose(archivoEmpleado);
        return true;
    }
    else
    {
        return false;
    }
}

Empleado ServiceEmpleado::leerEmpleado(int pos)
{
    Empleado registro;
    FILE* archivoEmpleado = fopen("Empleados.dat", "rb");

    if(archivoEmpleado != nullptr)
    {
        fseek(archivoEmpleado, sizeof(Empleado) * pos, SEEK_SET);
        fread(&registro, sizeof(Empleado), 1, archivoEmpleado);
        fclose(archivoEmpleado);
    }

    return registro;
}

int ServiceEmpleado::getCantidadRegistros()
{
    FILE* archivoEmpleado = fopen("Empleados.dat", "rb");

    if(archivoEmpleado != nullptr)
    {
        fseek(archivoEmpleado, 0, SEEK_END);
        int bytes = ftell(archivoEmpleado);
        fclose(archivoEmpleado);

        return bytes / sizeof(Empleado);
    }
    else
    {
        return 0;
    }
}

int ServiceEmpleado::buscarPorLegajo(int legajo)
{
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        Empleado emp = leerEmpleado(i);

        if (emp.getlegajo() == legajo)
        {
            return i;
        }
    }
    return -1;
}
