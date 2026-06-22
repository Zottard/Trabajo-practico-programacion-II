#include <iostream>
#include <cstdio>
#include <cstring>
#include "ServiceHorarios.h"

using namespace std;

ServiceHorarios::ServiceHorarios()
{
    strcpy(_nombreArchivo, "Horarios.dat");
}

bool ServiceHorarios::guardarHorario(Horarios hor)
{
    FILE* archivoHorario = fopen(_nombreArchivo, "ab");
    if(archivoHorario != nullptr)
    {
        fwrite(&hor, sizeof(Horarios), 1, archivoHorario);
        fclose(archivoHorario);
        return true;
    }
    else
    {
        return false;
    }
}

Horarios ServiceHorarios::leerHorario(int pos)
{
    Horarios registro;
    FILE* archivoHorario = fopen(_nombreArchivo, "rb");

    if(archivoHorario != nullptr)
    {
        fseek(archivoHorario, sizeof(Horarios) * pos, SEEK_SET);
        fread(&registro, sizeof(Horarios), 1, archivoHorario);
        fclose(archivoHorario);
    }

    return registro;
}

int ServiceHorarios::getCantidadRegistros()
{
    FILE* archivoHorario = fopen(_nombreArchivo, "rb");

    if(archivoHorario != nullptr)
    {
        fseek(archivoHorario, 0, SEEK_END);
        int bytes = ftell(archivoHorario);
        fclose(archivoHorario);

        return bytes / sizeof(Horarios);
    }
    else
    {
        return 0;
    }
}

int ServiceHorarios::buscarPorIdTurno(int idTurno)
{
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        Horarios obj = leerHorario(i);

        if (obj.getIdTurno() == idTurno)
        {
            return i;
        }
    }
    return -1;
}

int ServiceHorarios::calcularHorasTrabajadas(int idEmpleado, int mes)
{
    int totalHoras = 0;
    int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        Horarios obj = leerHorario(i);


        if (obj.getIdEmpleado() == idEmpleado && obj.getAsistencia() == true)
        {

            if (obj.getFecha().getMes() == mes)
            {
                int horasTurno = obj.getHoraSalida() - obj.getHoraEntrada();
                if (horasTurno > 0)
                {
                    totalHoras += horasTurno;
                }
            }
        }
    }

    return totalHoras;
}
