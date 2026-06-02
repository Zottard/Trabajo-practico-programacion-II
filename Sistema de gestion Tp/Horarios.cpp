#include <iostream>
#include "Horarios.h"
using namespace std;

Horarios:: Horarios(){

}

void Horarios::setidTurno(int idTurno)
{
    _idTurno=idTurno;
}

int Horarios::getidTurno()
{
    return _idTurno;
}

void Horarios::setidEmpleado(int idEmpleado)
{
    _idEmpleado=idEmpleado;
}

int Horarios::getidEmpleado()
{
    return _idEmpleado;
}

void Horarios::setfecha(Fecha fecha)
{
    _fecha=fecha;
}

Fecha Horarios::getfecha()
{
    return _fecha;
}

void Horarios::sethoraEntrada(int horaEntrada)
{
    _horaEntrada=horaEntrada;
}

int Horarios::gethoraEntrada()
{
    return _horaEntrada;
}

void Horarios::sethoraSalida(int horaSalida)
{
    _horaSalida=horaSalida;
}

int Horarios::gethoraSalida()
{
    return _horaSalida;
}

void Horarios::setasistencia(bool asistencia)
{
    _asistencia=asistencia;
}

bool Horarios::getasistencia()
{
    return _asistencia;
}

void Horarios::cargarHorario()
{
    cout<<"Ingrese ID del turno: "<<endl;
    cin>>_idTurno;

    cout<<"Ingrese ID del empleado: "<<endl;
    cin>>_idEmpleado;

    cout <<"Ingrese la fecha del turno: "<<endl;
    // Asumo que a tu clase Fecha le pusiste cargarFecha() o cargar().
    // Si se llama diferente, cambialo en esta linea:
    _fecha.cargarFecha();

    cout << "Ingrese hora de entrada (formato 0-23): "<<endl;
    cin >> _horaEntrada;

    cout << "Ingrese hora de salida (formato 0-23): "<<endl;
    cin >> _horaSalida;

    int opcionAsistencia;
    cout <<"Asistio el empleado? (1 - Si / 0 - No): "<<endl;
    cin >> opcionAsistencia;

    if(opcionAsistencia == 1){
        _asistencia = true;
    } else {
        _asistencia = false;
    }
}

void Horarios::mostrarHorario()
{
    cout<<"ID TURNO     : "<<_idTurno<<endl;
    cout<<"ID EMPLEADO  : "<<_idEmpleado<<endl;
    cout<<"FECHA        : ";

    // Al igual que en la carga, llamamos al mostrar de tu clase Fecha
    _fecha.mostrarFecha();
    cout<<endl;

    cout<<"ENTRADA      : "<<_horaEntrada<<" hs"<<endl;
    cout<<"SALIDA       : "<<_horaSalida<<" hs"<<endl;

    if(_asistencia){
        cout<<"ASISTENCIA   : Presente"<<endl;
    } else {
        cout<<"ASISTENCIA   : Ausente"<<endl;
    }
}
