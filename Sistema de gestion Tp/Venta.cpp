
#include "Venta.h"


Venta:: Venta(){

}

void Venta::setIdVenta(int idVenta)
{
    _idVenta=idVenta;
}

int Venta::getIdVenta()
{
    return _idVenta;
}

void Venta::setIdCliente(int idCliente)
{
    _idCliente=idCliente;
}

int Venta::getIdCliente()
{
    return _idCliente;
}

void Venta::setIdEmpleado(int idEmpleado)
{
    _idEmpleado=idEmpleado;
}

int Venta::getIdEmpleado()
{
    return _idEmpleado;
}

void Venta::setIdProducto(int idProducto)
{
    _idProducto=idProducto;
}

int Venta::getIdProducto()
{
    return _idProducto;
}

void Venta::setCantidad(int cantidad)
{
    _cantidad=cantidad;
}

int Venta::getCantidad()
{
    return _cantidad;
}

void Venta::setMontoTotal(float montoTotal)
{
    _montoTotal=montoTotal;
}

float Venta::getMontoTotal()
{
    return _montoTotal;
}

void Venta::setFechaVenta(Fecha fechaVenta)
{
    _fechaVenta=fechaVenta;
}

Fecha Venta::getFechaVenta()
{
    return _fechaVenta;
}

void Venta::setActivo(bool activo)
{
    _activo=activo;
}

bool Venta::getActivo()
{
    return _activo;
}



