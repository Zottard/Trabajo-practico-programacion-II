#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>
#include "MisFunciones.h"

#include "Cliente.h"
#include "ServiceCliente.h"
#include "Empleado.h"
#include "ServiceEmpleado.h"
#include "Producto.h"
#include "ServiceProducto.h"

using namespace std;

void resultadoAccion(bool respuesta)
{
    cout << endl << "----------------------------------------" << endl;
    if(respuesta)
    {
        cout << " >> EXITOSO: Se guardo correctamente." << endl;
    }
    else
    {
        cout << " >> ERROR: No se ha podido guardar, intente nuevamente." << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "Presione ENTER para continuar...";
    cin.get();
}

void limpiarBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/// Genera ID a partir del ultimo del archivo
int generacionId(int tipo){
    int cantidad;

    if(tipo==1) /// Cliente
    {
        ServiceCliente servicli;
        cantidad = servicli.getCantidadRegistros();

        if(cantidad == 0) return 1;

        Cliente cli = servicli.leerCliente(cantidad - 1);
        return cli.getidPersona() + 1;
    }
    else if (tipo==2) /// Empleado
    {
        ServiceEmpleado serviEmple;
        cantidad = serviEmple.getCantidadRegistros();

        if(cantidad == 0) return 1;

        Empleado emple = serviEmple.leerEmpleado(cantidad - 1);
        return emple.getidPersona() + 1;
    }
    else if(tipo==3) /// Producto
    {
        ServiceProducto serviprod;
        cantidad = serviprod.getCantidadRegistros();

        if(cantidad == 0) return 1;

        Producto prod = serviprod.leerProducto(cantidad - 1);
        return prod.getidProducto() + 1;
    }
    else if(tipo==4)
    {
        ServiceVenta serviVen;
        cantidad = serviVen.getCantidadRegistros();
        if(cantidad == 0) return 1;
        Venta ven = serviVen.leerVenta(cantidad - 1);
        return ven.GetIdVenta() + 1;
    }


    return -1;
}

/// generacion de legajo
int generacionLegajo(){
    ServiceEmpleado serviEmple;
    int cantidad = serviEmple.getCantidadRegistros();

    if(cantidad == 0){
        return 1501;
    }

    Empleado emple = serviEmple.leerEmpleado(cantidad - 1);
    return emple.getlegajo() + 1;
}

/// validador de numeros
bool validarNumeros(const char* numero) {
    int len = strlen(numero);
    if (len == 0) return false;

    for (int i = 0; i < len; i++) {
        if (!isdigit(numero[i])) return false;
    }
    return true;
}

/// validar texto
bool validarTexto(const char* texto) {
    int len = strlen(texto);
    if (len == 0) return false;

    for (int i = 0; i < len; i++) {
        char c = texto[i];
        if (c == ' ') continue;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            continue;
        }
        return false;
    }
    return true;
}

/// validar fecha
bool validaFecha(int dia, int mes, int anio ){
    if(anio < 1900 || anio > 2100) return false;

    int diaMes=0;

    switch (mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
           diaMes = 31;
        break;
        case 4: case 6: case 9: case 11:
            diaMes = 30;
        break;
        case 2:
            diaMes = 28;
        break;
        default:
           return false;
        break;
    }

    if(dia < 1 || dia > diaMes) return false;

    return true;
}

/// validar hora
bool validarHora(int hora, int minuto){
    if(hora >= 0 && hora < 24){
        if(minuto >= 0 && minuto < 60){
            return true;
        }
    }
    return false;
}
