#include <iostream>
#include <cstdio>
#include <cstring>
#include "ServiceProducto.h"

using namespace std;

ServiceProducto::ServiceProducto()
{
    strcpy(_nombreArchivo, "Productos.dat");
}

bool ServiceProducto::guardarProducto(Producto prod)
{
    FILE* archivoProducto = fopen(_nombreArchivo, "ab");
    if(archivoProducto != nullptr)
    {
        fwrite(&prod, sizeof(Producto), 1, archivoProducto);
        fclose(archivoProducto);
        return true;
    }
    else
    {
        return false;
    }
}

Producto ServiceProducto::leerProducto(int pos)
{
    Producto registro;
    FILE* archivoProducto = fopen(_nombreArchivo, "rb");

    if(archivoProducto != nullptr)
    {
        fseek(archivoProducto, sizeof(Producto) * pos, SEEK_SET);
        fread(&registro, sizeof(Producto), 1, archivoProducto);
        fclose(archivoProducto);
    }

    return registro;
}

int ServiceProducto::getCantidadRegistros()
{
    FILE* archivoProducto = fopen(_nombreArchivo, "rb");

    if(archivoProducto != nullptr)
    {
        fseek(archivoProducto, 0, SEEK_END);
        int bytes = ftell(archivoProducto);
        fclose(archivoProducto);

        return bytes / sizeof(Producto);
    }
    else
    {
        return 0;
    }
}

int ServiceProducto::buscarPorCodigo(const char* codigo)
{
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        Producto prod = leerProducto(i);

        if (strcmp(prod.getCodigo(), codigo) == 0)
        {
            return i;
        }
    }
    return -1;
}
