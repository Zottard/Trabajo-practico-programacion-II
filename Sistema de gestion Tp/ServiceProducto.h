#pragma once
#include "Producto.h"

class ServiceProducto
{
    public:
        ServiceProducto();

        bool guardarProducto(Producto prod);
        Producto leerProducto(int pos);
        int buscarPorCodigo(const char* codigo);
        int getCantidadRegistros();

    private:
        char _nombreArchivo[30];
};
