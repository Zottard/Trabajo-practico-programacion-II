#pragma once
#include "Cliente.h"

class ServiceCliente
{
    public:
        ServiceCliente();

        bool guardar(Cliente cli);
        Cliente leer(int pos);
        int buscarPorDNI(const char* dni);
        int getCantidadRegistros();
};
