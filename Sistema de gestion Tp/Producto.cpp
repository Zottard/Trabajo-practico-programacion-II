
#include <iostream>
#include <cstring>
#include "Producto.h"
using namespace std;

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
    strcpy(_nombre,nombre);
    _nombre[49]='\0';
}

const char* Producto::getNombre()
{
    return _nombre;
}

void Producto::setCodigo(const char *codigo)
{
    strcpy(_codigo,codigo);
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

void Producto::cargarProducto()
{
    cout<<"Ingrese ID del producto: "<<endl;
    cin>>_idProducto;

    cout<<"Ingrese nombre del articulo: "<<endl;
    cin>>_nombre;

    cout <<"Ingrese codigo identificador (SKU): "<<endl;
    cin >> _codigo;

    cout << "Ingrese numero de categoria: "<<endl;
    cin >> _categoria;

    cout << "Ingrese precio de venta: $"<<endl;
    cin >> _precio;

    cout << "Ingrese stock inicial disponible: "<<endl;
    cin >> _stock;

    _activo = true;
}

void Producto::mostrarProducto()
{
    if(_activo){
        cout<<"ID PRODUCTO : "<<_idProducto<<endl;
        cout<<"NOMBRE      : "<<_nombre<<endl;
        cout<<"CODIGO      : "<<_codigo<<endl;
        cout<<"CATEGORIA   : "<<_categoria<<endl;
        cout<<"PRECIO      : $"<<_precio<<endl;
        cout<<"STOCK       : "<<_stock<<" unidades"<<endl;
    }
}
