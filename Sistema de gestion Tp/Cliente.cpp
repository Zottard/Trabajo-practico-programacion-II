#include <iostream>
#include <cstring>
#include "Cliente.h"
using namespace std;

Cliente:: Cliente(){

}

void Cliente::setEmail(const char *email)
{
    strcpy(_email,email);
    _email[49]='\0';
}

const char* Cliente::getEmail()
{
    return _email;
}

void Cliente::setTelefono(const char *telefono)
{
    strcpy(_telefono,telefono);
    _telefono[14]='\0';
}

const char* Cliente::getTelefono()
{
    return _telefono;
}

void Cliente::cargarCliente()
{
    cargarPersona();

    cout<<"Ingrese email: "<<endl;
    cin>>_email;
    cout <<"Ingrese telefono: "<<endl;
    cin >> _telefono;
}

void Cliente::mostrarCliente()
{
    if(getActivo()){
        mostrarPersona();

        cout<<"EMAIL: "<<_email<<endl;
        cout<<"TELEFONO: "<<_telefono<<endl;
    }
}
