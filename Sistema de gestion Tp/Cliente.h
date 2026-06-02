#pragma once
#include "Persona.h"

class Cliente : public Persona
{

private:
    char _email[50];
    char _telefono[15];

public:

    Cliente();


    void setEmail(const char *);
    const char* getEmail();

    void setTelefono(const char *);
    const char* getTelefono();

};
