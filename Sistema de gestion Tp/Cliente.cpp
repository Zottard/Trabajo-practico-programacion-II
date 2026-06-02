
#include <cstring>
#include "Cliente.h"

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

