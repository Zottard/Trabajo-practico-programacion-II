#pragma once
#include "Fecha.h"

class Venta
{

private:
    int _idVenta;
    int _idCliente;
    int _idEmpleado;
    int _idProducto;
    int _cantidad;
    float _montoTotal;
    Fecha _fechaVenta;
    bool _activo;

public:

    Venta();


    void setIdVenta(int);
    int getIdVenta();

    void setIdCliente(int);
    int getIdCliente();

    void setIdEmpleado(int);
    int getIdEmpleado();

    void setIdProducto(int);
    int getIdProducto();

    void setCantidad(int);
    int getCantidad();

    void setMontoTotal(float);
    float getMontoTotal();

    void setFechaVenta(Fecha);
    Fecha getFechaVenta();

    void setActivo(bool);
    bool getActivo();

};
