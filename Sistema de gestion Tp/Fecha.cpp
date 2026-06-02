#include "Fecha.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

Fecha::Fecha()
{
    _dia=0;
    _mes=0;
    _anio=0;
    _hora=0;
    _minuto=0;
}
void Fecha::fechaActual(){
time_t timeptr = time(nullptr);
    tm*tiempo = localtime( &timeptr );

    _dia = tiempo->tm_mday;
    _mes = tiempo->tm_mon+1;
    _anio = tiempo->tm_year + 1900;
    _hora = tiempo->tm_hour;
    _minuto = tiempo->tm_min;

}

void Fecha::setDia(int dia){
    _dia= dia;
}
void Fecha::setMes(int mes){
    _mes= mes;
}

void Fecha::setAnio(int anio){
    _anio= anio;
}

void Fecha::setHora(int hora){
    _hora= hora;
}
void Fecha::setMinuto(int minuto){
    _minuto= minuto;
}

int Fecha::getDia(){
 return _dia;
}

int Fecha::getMes(){
 return _mes;
}

int Fecha::getAnio(){
 return _anio;
}

int Fecha::getHora(){
 return _hora;
}

int Fecha::getMinuto(){
 return _minuto;
}

void Fecha::mostrarFecha(){
cout << setw(2) << setfill('0') << _dia << "/"
     << setw(2) << setfill('0') << _mes << "/"
     <<_anio;
}

void Fecha::mostrarHora(){
    cout << setw(2) << setfill('0') << _hora << ":"
         << setw(2) << setfill('0') << _minuto;
}

void Fecha::cargarFecha()
{
    int opcion;
    cout << "Desea utilizar la fecha y hora actual del sistema? (1 - Si / 0 - Carga manual): " << endl;
    cin >> opcion;

    if (opcion == 1)
    {
        fechaActual();
        cout << ">> Fecha registrada automaticamente: ";
        mostrarFecha();
        cout << " ";
        mostrarHora();
        cout << endl;
    }
    else
    {
        cout << "Ingrese dia (1-31): " << endl;
        cin >> _dia;

        cout << "Ingrese mes (1-12): " << endl;
        cin >> _mes;

        cout << "Ingrese anio: " << endl;
        cin >> _anio;

        cout << "Ingrese hora (0-23): " << endl;
        cin >> _hora;

        cout << "Ingrese minuto (0-59): " << endl;
        cin >> _minuto;
    }
}
