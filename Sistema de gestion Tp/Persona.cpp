
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
    strcpy(_dni,dniPersona);
    _dni[9]='\0';
}

const char* Persona::getDniPersona()
{
    return _dni;
}

void Persona::setNombre(const char *nombre)
{
    strcpy(_nombre,nombre);
    _nombre[49]='\0';
}

const char* Persona::getNombre()
{
    return _nombre;
}

void Persona::setApellido(const char *apellido)
{
    strcpy(_apellido,apellido);
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

