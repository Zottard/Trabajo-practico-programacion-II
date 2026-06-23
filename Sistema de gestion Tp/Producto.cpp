
#include <cstring>
#include "Producto.h"

Producto:: Producto(){

}

void Producto::setIdProducto(int idProducto)
{
    _idProducto=idProducto;
}

int Producto::getIdProducto()
{
    return _idProducto;
}

void Producto::setNombre(const char *nombre)
{
    strncpy(_nombre,nombre,49);
    _nombre[49]='\0';
}

const char* Producto::getNombre()
{
    return _nombre;
}

void Producto::setCodigo(const char *codigo)
{
    strncpy(_codigo,codigo,29);
    _codigo[29]='\0';
}

const char* Producto::getCodigo()
{
    return _codigo;
}

void Producto::setCategoria(int categoria)
{
    _categoria=categoria;
}

int Producto::getCategoria()
{
    return _categoria;
}

void Producto::setPrecio(float precio)
{
    _precio=precio;
}

float Producto::getPrecio()
{
    return _precio;
}

void Producto::setStock(int stock)
{
    _stock=stock;
}

int Producto::getStock()
{
    return _stock;
}

void Producto::setActivo(bool activo)
{
    _activo=activo;
}

bool Producto::getActivo()
{
    return _activo;
}
