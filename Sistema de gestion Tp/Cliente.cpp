
#include <cstring>
#include "Cliente.h"

Cliente:: Cliente(){

}

void Cliente::setEmail(const char *email)
{
    strncpy(_email,email,49);
    _email[49]='\0';
}

const char* Cliente::getEmail()
{
    return _email;
}

void Cliente::setTelefono(const char *telefono)
{
    strncpy(_telefono,telefono,14);
    _telefono[14]='\0';
}

const char* Cliente::getTelefono()
{
    return _telefono;
}

