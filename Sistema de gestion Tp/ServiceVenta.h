#pragma once
#include "Venta.h"
#include "Fecha.h"

class ServiceVenta
{
    public:
        ServiceVenta();


        bool guardarVenta(Venta ven);
        Venta leerVenta(int pos);
        int buscarPorIdVenta(int idVenta);
        int getCantidadRegistros();
        float recaudacionTotal();


        int buscarPorFecha(Fecha f, int posInicial);
        int buscarPorCliente(int idCliente, int posInicial);
        int buscarPorProducto(int idProducto, int posInicial);

        float recaudacionAnual(int anio);
        float recaudacionMensual(int mes, int anio);
        float recaudacionPorEmpleado(int idEmpleado, Fecha inicio, Fecha fin);
        int cantidadVendidaPorCategoria(int categoriaBuscada, Fecha inicio, Fecha fin);

    private:
        char _nombreArchivo[30];
};
