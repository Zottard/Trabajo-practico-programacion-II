#pragma once
#include "Venta.h"
#include "Producto.h"
#include "Empleado.h"
#include "Cliente.h"

class ServiceVenta
{
    public:
        ServiceVenta();

        bool guardarVenta(Venta ven);
        Venta leerVenta(int pos);
        int buscarPorIdVenta(int idVenta);
        int getCantidadRegistros();

    private:
        char _nombreArchivo[30];
};
