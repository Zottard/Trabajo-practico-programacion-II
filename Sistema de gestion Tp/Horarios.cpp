
#include "Horarios.h"


Horarios:: Horarios(){

}

void Horarios::setIdTurno(int idTurno)
{
    _idTurno=idTurno;
}

int Horarios::getIdTurno()
{
    return _idTurno;
}

void Horarios::setIdEmpleado(int idEmpleado)
{
    _idEmpleado=idEmpleado;
}

int Horarios::getIdEmpleado()
{
    return _idEmpleado;
}

void Horarios::setFecha(Fecha fecha)
{
    _fecha=fecha;
}

Fecha Horarios::getFecha()
{
    return _fecha;
}

void Horarios::setHoraEntrada(int horaEntrada)
{
    _horaEntrada=horaEntrada;
}

int Horarios::getHoraEntrada()
{
    return _horaEntrada;
}

void Horarios::setHoraSalida(int horaSalida)
{
    _horaSalida=horaSalida;
}

int Horarios::getHoraSalida()
{
    return _horaSalida;
}

void Horarios::setAsistencia(bool asistencia)
{
    _asistencia=asistencia;
}

bool Horarios::getAsistencia()
{
    return _asistencia;
}


