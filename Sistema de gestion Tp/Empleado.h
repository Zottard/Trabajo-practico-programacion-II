#pragma once
#include "Persona.h"
class Empleado : public Persona
{

private:
    int _legajo;
    bool _esAdmin;

public:

    Empleado();

    void setLegajo(int);
    int getLegajo();

    void setesAdmin(bool);
    bool getesAdmin();

};
