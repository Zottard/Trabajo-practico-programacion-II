#pragma once

class Persona
{
    protected:
    int _idPersona;
    char _dni[10];
    char _nombre[50];
    char _apellido[50];
    bool _activo;

    public:
        Persona();

        void setIdPersona(int);
        int getIdPersona();

        void setDniPersona(const char*);
        const char* getDniPersona ();

        void setNombre (const char*);
        const char* getNombre();

        void setApellido(const char*);
        const char* getApellido ();

        void setActivo(bool);
        bool getActivo();


    private:
};


