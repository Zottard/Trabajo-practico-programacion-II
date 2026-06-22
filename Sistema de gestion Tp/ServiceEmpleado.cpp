#include <iostream>
#include <cstdio>
#include <cstring>
#include "ServiceEmpleado.h"

using namespace std;

ServiceEmpleado::ServiceEmpleado()
{
    strcpy(_nombreArchivo, "Empleados.dat");
}

bool ServiceEmpleado::guardarEmpleado(Empleado emp)
{
    FILE* archivoEmpleado = fopen(_nombreArchivo, "ab");
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
    FILE* archivoEmpleado = fopen(_nombreArchivo, "rb");

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
    FILE* archivoEmpleado = fopen(_nombreArchivo, "rb");

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
int ServiceEmpleado::getCantidadActivos()
{
    int total = getCantidadRegistros();
    int activos = 0;

    for(int i = 0; i < total; i++)
    {
        Empleado emp = leerEmpleado(i);
        if(emp.getActivo() == true)
        {
            activos++;
        }
    }
    return activos;
}

Empleado* ServiceEmpleado::listarEmpleados()
{
    int cant = getCantidadActivos();
    if(cant == 0) return nullptr;

    Empleado* vec = new Empleado[cant];
    int total = getCantidadRegistros();
    int indice = 0;

    for(int i = 0; i < total; i++)
    {
        Empleado emp = leerEmpleado(i);
        if(emp.getActivo() == true)
        {
            vec[indice] = emp;
            indice++;
        }
    }
    return vec;
}
