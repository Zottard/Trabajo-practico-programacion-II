#pragma once
#include "Cliente.h"

class ServiceCliente
{
    public:
        ServiceCliente();

        bool guardarCliente(Cliente cli);
        Cliente leerCliente(int pos);
        int buscarPorDNI(const char* dni);
        int getCantidadRegistros();

    private:
        char _nombreArchivo[30];
};
