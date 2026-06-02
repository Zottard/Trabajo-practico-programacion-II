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


    void setIdProducto(int);
    int getIdProducto();

    void setNombre(const char *);
    const char* getNombre();

    void setCodigo(const char *);
    const char* getCodigo();

    void setCategoria(int);
    int getCategoria();

    void setPrecio(float);
    float getPrecio();

    void setStock(int);
    int getStock();

    void setActivo(bool);
    bool getActivo();

};
