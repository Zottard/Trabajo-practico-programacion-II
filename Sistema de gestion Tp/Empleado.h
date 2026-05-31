#pragma once
#include "Persona.h"
class Empleado : public Persona
{

private:
    int _legajo;
    bool _esAdmin;

public:

    Empleado();

    void cargarEmpleado();
    void mostrarEmpleado();

    void setlegajo(int);
    int getlegajo();

    void setesAdmin(bool);
    bool getesAdmin();

};
