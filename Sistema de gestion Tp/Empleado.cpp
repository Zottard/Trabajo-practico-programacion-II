#include <iostream>
#include "Empleado.h"
using namespace std;

Empleado:: Empleado(){

}

void Empleado::setlegajo(int legajo)
{
    _legajo = legajo;
}

int Empleado::getlegajo()
{
    return _legajo;
}

void Empleado::setesAdmin(bool esAdmin)
{
    _esAdmin = esAdmin;
}

bool Empleado::getesAdmin()
{
    return _esAdmin;
}

void Empleado::cargarEmpleado()
{

    cargarPersona();

    cout<<"Ingrese legajo: "<<endl;
    cin>>_legajo;


    int opcionAdmin;
    cout <<"Es administrador? (1 - Si / 0 - No): "<<endl;
    cin >> opcionAdmin;

    if(opcionAdmin == 1){
        _esAdmin = true;
    } else {
        _esAdmin = false;
    }
}

void Empleado::mostrarEmpleado()
{

    if(getactivo()){

        mostrarPersona();


        cout<<"LEGAJO: "<<_legajo<<endl;

        if(_esAdmin){
            cout<<"PERMISOS: Administrador"<<endl;
        } else {
            cout<<"PERMISOS: Empleado estandar"<<endl;
        }
    }
}
