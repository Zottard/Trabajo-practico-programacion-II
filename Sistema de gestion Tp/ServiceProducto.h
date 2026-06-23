#pragma once
#include "Producto.h"

class ServiceProducto
{
    public:
        ServiceProducto();

        bool guardarProducto(Producto prod);
        bool modificarProducto(int pos, Producto prod);
        Producto leerProducto(int pos);
        int buscarPorCodigo(const char* codigo);
        int getCantidadRegistros();
        bool bajaLogica(int pos);
        bool actualizarStock(int idProducto, int cantidad);

        int getCantidadActivos();
        int getCantidadDisponibles();

        Producto* listarPorNombre();
        Producto* listarPorPrecio();
        Producto* listarPorStock();
        Producto* listarDisponibles();

    private:
        char _nombreArchivo[30];
};
