#include <iostream>
#include <cstdio>
#include <cstring>
#include "ServiceVenta.h"

using namespace std;

ServiceVenta::ServiceVenta()
{
    strcpy(_nombreArchivo, "Ventas.dat");
}

bool ServiceVenta::guardarVenta(Venta ven)
{
    FILE* archivoVenta = fopen(_nombreArchivo, "ab");
    if(archivoVenta != nullptr)
    {
        fwrite(&ven, sizeof(Venta), 1, archivoVenta);
        fclose(archivoVenta);
        return true;
    }
    else
    {
        return false;
    }
}

Venta ServiceVenta::leerVenta(int pos)
{
    Venta registro;
    FILE* archivoVenta = fopen(_nombreArchivo, "rb");

    if(archivoVenta != nullptr)
    {
        fseek(archivoVenta, sizeof(Venta) * pos, SEEK_SET);
        fread(&registro, sizeof(Venta), 1, archivoVenta);
        fclose(archivoVenta);
    }

    return registro;
}

int ServiceVenta::getCantidadRegistros()
{
    FILE* archivoVenta = fopen(_nombreArchivo, "rb");

    if(archivoVenta != nullptr)
    {
        fseek(archivoVenta, 0, SEEK_END);
        int bytes = ftell(archivoVenta);
        fclose(archivoVenta);

        return bytes / sizeof(Venta);
    }
    else
    {
        return 0;
    }
}

int ServiceVenta::buscarPorIdVenta(int idVenta)
{
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        Venta ven = leerVenta(i);

        if (ven.getIdVenta() == idVenta)
        {
            return i;
        }
    }
    return -1;
}
