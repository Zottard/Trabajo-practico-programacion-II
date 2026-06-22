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
        int calcularHorasTrabajadas(int idEmpleado, int mes);

    private:
        char _nombreArchivo[30];
};
