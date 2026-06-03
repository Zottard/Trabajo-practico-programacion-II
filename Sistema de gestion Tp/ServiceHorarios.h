#pragma once
#include "Horarios.h"

class ServiceHorarios
{
    public:
        ServiceHorarios();

        bool guardarHorario(Horarios hor);
        Horarios leerHorario(int pos);
        int buscarPorIdTurno(int idTurno);
        int getCantidadRegistros();

    private:
        char _nombreArchivo[30];
};
