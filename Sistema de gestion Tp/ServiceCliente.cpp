#include <iostream>
#include <cstdio>
#include <cstring>
#include "ServiceCliente.h"

using namespace std;

ServiceCliente::ServiceCliente()
{
    strcpy(_nombreArchivo, "Clientes.dat");
}

bool ServiceCliente::guardarCliente(Cliente cli)
{
    FILE* archivoCliente = fopen(_nombreArchivo, "ab");
    if(archivoCliente != nullptr)
    {
        fwrite(&cli, sizeof(Cliente), 1, archivoCliente);
        fclose(archivoCliente);
        return true;
    }
    else
    {
        return false;
    }
}

Cliente ServiceCliente::leerCliente(int pos)
{
    Cliente registro;
    FILE* archivoCliente = fopen(_nombreArchivo, "rb");

    if(archivoCliente != nullptr)
    {
        fseek(archivoCliente, sizeof(Cliente) * pos, SEEK_SET);
        fread(&registro, sizeof(Cliente), 1, archivoCliente);
        fclose(archivoCliente);
    }

    return registro;
}

int ServiceCliente::getCantidadRegistros()
{
    FILE* archivoCliente = fopen(_nombreArchivo, "rb");

    if(archivoCliente != nullptr)
    {
        fseek(archivoCliente, 0, SEEK_END);
        int bytes = ftell(archivoCliente);
        fclose(archivoCliente);

        return bytes / sizeof(Cliente);
    }
    else
    {
        return 0;
    }
}

int ServiceCliente::buscarPorDNI(const char* dni)
{
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        Cliente cli = leerCliente(i);

        if (strcmp(cli.getDniPersona(), dni) == 0)
        {
            return i;
        }
    }
    return -1;
}

int ServiceCliente::getCantidadActivos()
{
    int total = getCantidadRegistros();
    int activos = 0;

    for(int i = 0; i < total; i++)
    {
        Cliente cli = leerCliente(i);
        if(cli.getActivo() == true)
        {
            activos++;
        }
    }
    return activos;
}

Cliente* ServiceCliente::listarClientes()
{
    int cant = getCantidadActivos();
    if(cant == 0) return nullptr;

    Cliente* vec = new Cliente[cant];
    int total = getCantidadRegistros();
    int indice = 0;

    for(int i = 0; i < total; i++)
    {
        Cliente cli = leerCliente(i);
        if(cli.getActivo() == true)
        {
            vec[indice] = cli;
            indice++;
        }
    }
    return vec;
}

bool ServiceCliente::bajaLogica(int pos)
{
    FILE* archivo = fopen(_nombreArchivo, "rb+");
    if(archivo != nullptr)
    {
        Cliente cli;

        fseek(archivo, sizeof(Cliente) * pos, SEEK_SET);

        if(fread(&cli, sizeof(Cliente), 1, archivo) == 1)
        {

            cli.setActivo(false);


            fseek(archivo, sizeof(Cliente) * pos, SEEK_SET);
            fwrite(&cli, sizeof(Cliente), 1, archivo);
            fclose(archivo);
            return true;
        }
        fclose(archivo);
    }
    return false;
}
