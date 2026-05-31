#pragma once

class Producto
{

private:
    int _idProducto;
    char _nombre[50];
    char _codigo[30];
    int _categoria;
    float _precio;
    int _stock;
    bool _activo;

public:

    Producto();

    void cargarProducto();
    void mostrarProducto();

    void setidProducto(int);
    int getidProducto();

    void setnombre(const char *);
    const char* getnombre();

    void setcodigo(const char *);
    const char* getcodigo();

    void setcategoria(int);
    int getcategoria();

    void setprecio(float);
    float getprecio();

    void setstock(int);
    int getstock();

    void setactivo(bool);
    bool getactivo();

};
