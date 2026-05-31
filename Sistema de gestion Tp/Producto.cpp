#include <iostream>
#include <cstring>
#include "Producto.h"
using namespace std;

Producto:: Producto(){

}

void Producto::setidProducto(int idProducto)
{
    _idProducto=idProducto;
}

int Producto::getidProducto()
{
    return _idProducto;
}

void Producto::setnombre(const char *nombre)
{
    strcpy(_nombre,nombre);
    _nombre[49]='\0';
}

const char* Producto::getnombre()
{
    return _nombre;
}

void Producto::setcodigo(const char *codigo)
{
    strcpy(_codigo,codigo);
    _codigo[29]='\0';
}

const char* Producto::getcodigo()
{
    return _codigo;
}

void Producto::setcategoria(int categoria)
{
    _categoria=categoria;
}

int Producto::getcategoria()
{
    return _categoria;
}

void Producto::setprecio(float precio)
{
    _precio=precio;
}

float Producto::getprecio()
{
    return _precio;
}

void Producto::setstock(int stock)
{
    _stock=stock;
}

int Producto::getstock()
{
    return _stock;
}

void Producto::setactivo(bool activo)
{
    _activo=activo;
}

bool Producto::getactivo()
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
