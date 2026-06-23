#pragma once
#include "Cliente.h"

class ServiceCliente
{
    public:
        ServiceCliente();

        bool guardarCliente(Cliente cli);
        Cliente leerCliente(int pos);
        int buscarPorDNI(const char* dni);
        bool bajaLogica(int pos);
        int getCantidadRegistros();
        int getCantidadActivos();
        Cliente* listarClientes();

    private:
        char _nombreArchivo[30];
};
