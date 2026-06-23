
#include <cstring>
#include "Persona.h"


Persona:: Persona(){

}

void Persona::setIdPersona(int idPersona)
{
    _idPersona=idPersona;
}

int Persona::getIdPersona()
{
    return _idPersona;
}

void Persona::setDniPersona(const char *dniPersona)
{
    strncpy(_dni,dniPersona,9);
    _dni[9]='\0';
}

const char* Persona::getDniPersona()
{
    return _dni;
}

void Persona::setNombre(const char *nombre)
{
    strncpy(_nombre,nombre,49);
    _nombre[49]='\0';
}

const char* Persona::getNombre()
{
    return _nombre;
}

void Persona::setApellido(const char *apellido)
{
    strncpy(_apellido,apellido,49);
    _apellido[49]='\0';
}

const char* Persona::getApellido()
{
    return _apellido;
}

void Persona::setActivo(bool activo)
{
    _activo=activo;
}

bool Persona::getActivo()
{
    return _activo;
}

