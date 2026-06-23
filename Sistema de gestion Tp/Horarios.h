#pragma once
#include "Fecha.h"

class Horarios
{

private:
    int _idTurno;
    int _idEmpleado;
    Fecha _fecha;
    int _horaEntrada;
    int _minutoEntrada;
    int _horaSalida;
    int _minutoSalida;
    bool _asistencia;
    bool _activo;

public:

    Horarios();


    void setIdTurno(int);
    int getIdTurno();

    void setIdEmpleado(int);
    int getIdEmpleado();

    void setFecha(Fecha);
    Fecha getFecha();

    void setHoraEntrada(int);
    int getHoraEntrada();

    void setMinutoEntrada(int);
    int getMinutoEntrada();

    void setHoraSalida(int);
    int getHoraSalida();

    void setMinutoSalida(int);
    int getMinutoSalida();

    void setAsistencia(bool);
    bool getAsistencia();

    void setActivo(bool);
    bool getActivo();

};
