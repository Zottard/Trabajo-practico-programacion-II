#include <iostream>
#include <cstdio>
#include <cstring>
#include "ServiceVenta.h"
#include "ServiceProducto.h"

using namespace std;

ServiceVenta::ServiceVenta()
{
    strcpy(_nombreArchivo, "Ventas.dat");
}

bool ServiceVenta::guardarVenta(Venta ven)
{
    FILE* archivoVenta = fopen(_nombreArchivo, "ab");
    if(archivoVenta != nullptr)
    {
        fwrite(&ven, sizeof(Venta), 1, archivoVenta);
        fclose(archivoVenta);
        return true;
    }
    else
    {
        return false;
    }
}

bool ServiceVenta::modificarVenta(int pos, Venta ven)
{
    FILE* archivoVenta = fopen(_nombreArchivo, "rb+");
    if(archivoVenta != nullptr)
    {
        fseek(archivoVenta, sizeof(Venta) * pos, SEEK_SET);
        fwrite(&ven, sizeof(Venta), 1, archivoVenta);
        fclose(archivoVenta);
        return true;
    }
    return false;
}

Venta ServiceVenta::leerVenta(int pos)
{
    Venta registro;
    FILE* archivoVenta = fopen(_nombreArchivo, "rb");

    if(archivoVenta != nullptr)
    {
        fseek(archivoVenta, sizeof(Venta) * pos, SEEK_SET);
        fread(&registro, sizeof(Venta), 1, archivoVenta);
        fclose(archivoVenta);
    }

    return registro;
}

int ServiceVenta::getCantidadRegistros()
{
    FILE* archivoVenta = fopen(_nombreArchivo, "rb");

    if(archivoVenta != nullptr)
    {
        fseek(archivoVenta, 0, SEEK_END);
        int bytes = ftell(archivoVenta);
        fclose(archivoVenta);

        return bytes / sizeof(Venta);
    }
    else
    {
        return 0;
    }
}

int ServiceVenta::buscarPorIdVenta(int idVenta)
{
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        Venta obj = leerVenta(i);

        if (obj.getIdVenta() == idVenta)
        {
            return i;
        }
    }
    return -1;
}

float ServiceVenta::recaudacionTotal()
{
    float total = 0.0f;
    int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        Venta ven = leerVenta(i);

        if (ven.getActivo() == true)
        {
            total += ven.getMontoTotal();
        }
    }

    return total;
}



int ServiceVenta::buscarPorFecha(Fecha f, int posInicial)
{
    int cantidad = getCantidadRegistros();
    for (int i = posInicial; i < cantidad; i++)
    {
        Venta obj = leerVenta(i);

        if (obj.getActivo() == true)
        {
            Fecha fVenta = obj.getFechaVenta();
            if (fVenta.getAnio() == f.getAnio() && fVenta.getMes() == f.getMes() && fVenta.getDia() == f.getDia())
            {
                return i;
            }
        }
    }
    return -1;
}

int ServiceVenta::buscarPorCliente(int idCliente, int posInicial)
{
    int cantidad = getCantidadRegistros();
    for (int i = posInicial; i < cantidad; i++)
    {
        Venta obj = leerVenta(i);

        if (obj.getActivo() == true && obj.getIdCliente() == idCliente)
        {
            return i;
        }
    }
    return -1;
}

int ServiceVenta::buscarPorProducto(int idProducto, int posInicial)
{
    int cantidad = getCantidadRegistros();
    for (int i = posInicial; i < cantidad; i++)
    {
        Venta obj = leerVenta(i);

        if (obj.getActivo() == true && obj.getIdProducto() == idProducto)
        {
            return i;
        }
    }
    return -1;
}


float ServiceVenta::recaudacionAnual(int anio)
{
    float total = 0.0f;
    int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        Venta ven = leerVenta(i);

        if (ven.getActivo() == true && ven.getFechaVenta().getAnio() == anio)
        {
            total += ven.getMontoTotal();
        }
    }

    return total;
}

float ServiceVenta::recaudacionMensual(int mes, int anio)
{
    float total = 0.0f;
    int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        Venta ven = leerVenta(i);

        if (ven.getActivo() == true && ven.getFechaVenta().getAnio() == anio && ven.getFechaVenta().getMes() == mes)
        {
            total += ven.getMontoTotal();
        }
    }

    return total;
}




float ServiceVenta::recaudacionPorEmpleado(int idEmpleado, Fecha inicio, Fecha fin)
{
    float total = 0.0f;
    int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        Venta ven = leerVenta(i);

        if (ven.getActivo() == true && ven.getIdEmpleado() == idEmpleado)
        {
            Fecha f = ven.getFechaVenta();

            bool okInicio = (f.getAnio() > inicio.getAnio()) ||
                            (f.getAnio() == inicio.getAnio() && f.getMes() > inicio.getMes()) ||
                            (f.getAnio() == inicio.getAnio() && f.getMes() == inicio.getMes() && f.getDia() >= inicio.getDia());

            bool okFin    = (f.getAnio() < fin.getAnio()) ||
                            (f.getAnio() == fin.getAnio() && f.getMes() < fin.getMes()) ||
                            (f.getAnio() == fin.getAnio() && f.getMes() == fin.getMes() && f.getDia() <= fin.getDia());

            if (okInicio && okFin)
            {
                total += ven.getMontoTotal();
            }
        }
    }
    return total;
}

int ServiceVenta::cantidadVendidaPorCategoria(int categoriaBuscada, Fecha inicio, Fecha fin)
{
    int totalUnidades = 0;
    int cantVentas = getCantidadRegistros();

    ServiceProducto srvProducto;
    int cantProductos = srvProducto.getCantidadRegistros();

    for (int i = 0; i < cantVentas; i++)
    {
        Venta ven = leerVenta(i);

        if (ven.getActivo() == true)
        {
            Fecha f = ven.getFechaVenta();

            bool okInicio = (f.getAnio() > inicio.getAnio()) ||
                            (f.getAnio() == inicio.getAnio() && f.getMes() > inicio.getMes()) ||
                            (f.getAnio() == inicio.getAnio() && f.getMes() == inicio.getMes() && f.getDia() >= inicio.getDia());

            bool okFin    = (f.getAnio() < fin.getAnio()) ||
                            (f.getAnio() == fin.getAnio() && f.getMes() < fin.getMes()) ||
                            (f.getAnio() == fin.getAnio() && f.getMes() == fin.getMes() && f.getDia() <= fin.getDia());

            if (okInicio && okFin)
            {
                int idProdVendido = ven.getIdProducto();

                for (int p = 0; p < cantProductos; p++)
                {
                    Producto prod = srvProducto.leerProducto(p);

                    if (prod.getIdProducto() == idProdVendido)
                    {
                        if (prod.getCategoria() == categoriaBuscada)
                        {
                            totalUnidades += ven.getCantidad();
                        }
                        break;
                    }
                }
            }
        }
    }
    return totalUnidades;
}
bool ServiceVenta::anularVenta(int idVenta)
{
    FILE* archivo = fopen(_nombreArchivo, "rb+");
    if(archivo != nullptr)
    {
        Venta ven;
        int pos = 0;

        while(fread(&ven, sizeof(Venta), 1, archivo) == 1)
        {

            if(ven.getIdVenta() == idVenta && ven.getActivo() == true)
            {

                ven.setActivo(false);


                fseek(archivo, sizeof(Venta) * pos, SEEK_SET);
                fwrite(&ven, sizeof(Venta), 1, archivo);
                fclose(archivo);


                ServiceProducto srvProducto;
                srvProducto.actualizarStock(ven.getIdProducto(), ven.getCantidad());

                return true;
            }
            pos++;
        }
        fclose(archivo);
    }
    return false;
}

bool ServiceVenta::reactivarVenta(int idVenta)
{
    FILE* archivo = fopen(_nombreArchivo, "rb+");
    if(archivo != nullptr)
    {
        Venta ven;
        int pos = 0;

        while(fread(&ven, sizeof(Venta), 1, archivo) == 1)
        {
            if(ven.getIdVenta() == idVenta && ven.getActivo() == false)
            {
                ven.setActivo(true);

                fseek(archivo, sizeof(Venta) * pos, SEEK_SET);
                fwrite(&ven, sizeof(Venta), 1, archivo);
                fclose(archivo);

                ServiceProducto srvProducto;
                srvProducto.actualizarStock(ven.getIdProducto(), -ven.getCantidad());

                return true;
            }
            pos++;
        }
        fclose(archivo);
    }
    return false;
}
