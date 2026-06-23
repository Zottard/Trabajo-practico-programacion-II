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
    FILE* archivo = fopen(_nombreArchivo, "ab");
    if(archivo != nullptr)
    {
        fwrite(&prod, sizeof(Producto), 1, archivo);
        fclose(archivo);
        return true;
    }
    return false;
}

Producto ServiceProducto::leerProducto(int pos)
{
    Producto registro;
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo != nullptr)
    {
        fseek(archivo, sizeof(Producto) * pos, SEEK_SET);
        fread(&registro, sizeof(Producto), 1, archivo);
        fclose(archivo);
    }
    return registro;
}

int ServiceProducto::getCantidadRegistros()
{
    FILE* archivo = fopen(_nombreArchivo, "rb");
    if(archivo != nullptr)
    {
        fseek(archivo, 0, SEEK_END);
        int bytes = ftell(archivo);
        fclose(archivo);
        return bytes / sizeof(Producto);
    }
    return 0;
}

int ServiceProducto::buscarPorCodigo(const char* codigo)
{
    int cantidad = getCantidadRegistros();
    for(int i = 0; i < cantidad; i++)
    {
        Producto prod = leerProducto(i);
        if(prod.getActivo() == true && strcmp(prod.getCodigo(), codigo) == 0)
        {
            return i;
        }
    }
    return -1;
}

bool ServiceProducto::actualizarStock(int idProducto, int cantidad)
{
    FILE* archivo = fopen(_nombreArchivo, "rb+");
    if(archivo != nullptr)
    {
        Producto prod;
        int pos = 0;
        while(fread(&prod, sizeof(Producto), 1, archivo) == 1)
        {
            if(prod.getIdProducto() == idProducto && prod.getActivo() == true)
            {
                int stockActual = prod.getStock();
                int nuevoStock = stockActual + cantidad;
                if(nuevoStock < 0) nuevoStock = 0;
                prod.setStock(nuevoStock);

                fseek(archivo, sizeof(Producto) * pos, SEEK_SET);
                fwrite(&prod, sizeof(Producto), 1, archivo);
                fclose(archivo);
                return true;
            }
            pos++;
        }
        fclose(archivo);
    }
    return false;
}



int ServiceProducto::getCantidadActivos()
{
    int total = getCantidadRegistros();
    int activos = 0;
    for(int i = 0; i < total; i++)
    {
        Producto prod = leerProducto(i);
        if(prod.getActivo() == true)
        {
            activos++;
        }
    }
    return activos;
}

int ServiceProducto::getCantidadDisponibles()
{
    int total = getCantidadRegistros();
    int disponibles = 0;
    for(int i = 0; i < total; i++)
    {
        Producto prod = leerProducto(i);

        if(prod.getActivo() == true && prod.getStock() > 0)
        {
            disponibles++;
        }
    }
    return disponibles;
}

Producto* ServiceProducto::listarPorNombre()
{
    int cant = getCantidadActivos();
    if(cant == 0) return nullptr;

    Producto* vec = new Producto[cant];
    int total = getCantidadRegistros();
    int indice = 0;


    for(int i = 0; i < total; i++)
    {
        Producto prod = leerProducto(i);
        if(prod.getActivo() == true)
        {
            vec[indice] = prod;
            indice++;
        }
    }


    for(int i = 0; i < cant - 1; i++)
    {
        for(int j = 0; j < cant - 1 - i; j++)
        {
            if(strcmp(vec[j].getNombre(), vec[j+1].getNombre()) > 0)
            {
                Producto aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
    return vec;
}

Producto* ServiceProducto::listarPorPrecio()
{
    int cant = getCantidadActivos();
    if(cant == 0) return nullptr;

    Producto* vec = new Producto[cant];
    int total = getCantidadRegistros();
    int indice = 0;

    for(int i = 0; i < total; i++)
    {
        Producto prod = leerProducto(i);
        if(prod.getActivo() == true)
        {
            vec[indice] = prod;
            indice++;
        }
    }


    for(int i = 0; i < cant - 1; i++)
    {
        for(int j = 0; j < cant - 1 - i; j++)
        {
            if(vec[j].getPrecio() > vec[j+1].getPrecio())
            {
                Producto aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
    return vec;
}

Producto* ServiceProducto::listarPorStock()
{
    int cant = getCantidadActivos();
    if(cant == 0) return nullptr;

    Producto* vec = new Producto[cant];
    int total = getCantidadRegistros();
    int indice = 0;

    for(int i = 0; i < total; i++)
    {
        Producto prod = leerProducto(i);
        if(prod.getActivo() == true)
        {
            vec[indice] = prod;
            indice++;
        }
    }


    for(int i = 0; i < cant - 1; i++)
    {
        for(int j = 0; j < cant - 1 - i; j++)
        {
            if(vec[j].getStock() < vec[j+1].getStock())
            {
                Producto aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
    return vec;
}

Producto* ServiceProducto::listarDisponibles()
{
    int cant = getCantidadDisponibles();
    if(cant == 0) return nullptr;

    Producto* vec = new Producto[cant];
    int total = getCantidadRegistros();
    int indice = 0;


    for(int i = 0; i < total; i++)
    {
        Producto prod = leerProducto(i);
        if(prod.getActivo() == true && prod.getStock() > 0)
        {
            vec[indice] = prod;
            indice++;
        }
    }
    return vec;
}

bool ServiceProducto::bajaLogica(int pos)
{
    FILE* archivo = fopen(_nombreArchivo, "rb+");
    if(archivo != nullptr)
    {
        Producto prod;
        fseek(archivo, sizeof(Producto) * pos, SEEK_SET);

        if(fread(&prod, sizeof(Producto), 1, archivo) == 1)
        {
            prod.setActivo(false);

            fseek(archivo, sizeof(Producto) * pos, SEEK_SET);
            fwrite(&prod, sizeof(Producto), 1, archivo);
            fclose(archivo);
            return true;
        }
        fclose(archivo);
    }
    return false;
}
