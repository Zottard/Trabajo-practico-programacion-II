#include <iostream>
#include "Manager.h"

using namespace std;

Manager::Manager()
{
}

void Manager::menuPrincipal()
{
    int opcion;
    do
    {
        cout << "=======================================" << endl;
        cout << "       TIENDA DE DEPORTES - MAIN       " << endl;
        cout << "=======================================" << endl;
        cout << "[ 1 ] - Modulo de Ventas" << endl;
        cout << "[ 2 ] - Modulo de Inventario (Stock)" << endl;
        cout << "[ 3 ] - Modulo de Personal e Ingresos" << endl;
        cout << "[ 4 ] - Generacion de Informes" << endl;
        cout << "---------------------------------------" << endl;
        cout << "[ 0 ] - Salir del Sistema" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                menuVentas();
                break;
            case 2:
                menuInventario();
                break;
            case 3:
                menuPersonal();
                break;
            case 4:
                generarInformes();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion incorrecta. Intente nuevamente." << endl;
                break;
        }
    } while(opcion != 0);
}

void Manager::menuVentas()
{
    cout << "\n[ Entrando al Menu de Ventas... ]\n" << endl;
}

void Manager::menuInventario()
{
    cout << "\n[ Entrando al Menu de Inventario... ]\n" << endl;

}

void Manager::menuPersonal()
{
    cout << "\n[ Entrando al Menu de Personal... ]\n" << endl;

}

void Manager::generarInformes()
{
    cout << "\n[ Entrando a Generacion de Informes... ]\n" << endl;

}
