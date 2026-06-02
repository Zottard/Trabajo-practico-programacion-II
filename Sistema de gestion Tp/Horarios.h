#pragma once
#include "Fecha.h"

class Horarios
{

private:
    int _idTurno;
    int _idEmpleado;
    Fecha _fecha;
    int _horaEntrada;
    int _horaSalida;
    bool _asistencia;

public:

    Horarios();

    void cargarHorario();
    void mostrarHorario();

    void setIdTurno(int);
    int getIdTurno();

    void setIdEmpleado(int);
    int getidEmpleado();

    void setFecha(Fecha);
    Fecha getFecha();

    void setHoraEntrada(int);
    int getHoraEntrada();

    void setHoraSalida(int);
    int getHoraSalida();

    void setAsistencia(bool);
    bool getAsistencia();

};
