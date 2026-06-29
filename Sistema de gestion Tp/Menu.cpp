#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "Validaciones.h"

using namespace std;

Menu::Menu() {}

void Menu::menuPrincipal()
{
    int opPrincipal;

    do
    {
        system("cls");
        cout << "\n=================================================" << endl;
        cout << "     TIENDA DE ARTICULOS DEPORTIVOS - MAIN       " << endl;
        cout << "=================================================" << endl;
        cout << " [ 1 ] . Modulo de Ventas y Facturacion" << endl;
        cout << " [ 2 ] . Modulo de Productos (Inventario)" << endl;
        cout << " [ 3 ] . Modulo de Clientes" << endl;
        cout << " [ 4 ] . Modulo de Empleados" << endl;
        cout << " [ 5 ] . Modulo de Horarios (Asistencia)" << endl;
        cout << " [ 6 ] . Panel de Reportes e Estadisticas" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << " [ 0 ] . Salir del Software" << endl;
        cout << "=================================================" << endl;
        cout << " Seleccione un modulo: ";
        cin >> opPrincipal;

        if (cin.fail())
        {
            cin.clear();
            limpiarBuffer();
            opPrincipal = -1;
        }

        switch (opPrincipal)
        {
            case 1: menuVentas();    break;
            case 2: menuProductos(); break;
            case 3: menuClientes();  break;
            case 4: menuEmpleados(); break;
            case 5: menuHorarios();  break;
            case 6: menuReportes();  break;
            case 0:
                cout << "\n[ Cerrando el software de la Tienda... ]\n" << endl;
                break;
            default:
                cout << "\n[!] Modulo inexistente. Intente de nuevo.\n" << endl;
                break;
        }
    }
    while (opPrincipal != 0);
}

void Menu::menuVentas()
{
    int opVentas;
    do
    {
        system("cls");
        cout << "\n--- MODULO: GESTION DE VENTAS ---" << endl;
        cout << " [ 1 ] . Registrar Nueva Venta" << endl;
        cout << " [ 2 ] . Consultar Historial de Facturacion" << endl;
        cout << " [ 3 ] . Modificar Venta" << endl;
        cout << " [ 4 ] . Anular Venta (Baja Logica)" << endl;
        cout << " [ 5 ] . Reactivar Venta (Alta Logica)" << endl;
        cout << "------------------------------------------" << endl;
        cout << " [ 0 ] . Volver al Menu Principal" << endl;
        cout << " Opcion: ";
        cin >> opVentas;

        if (cin.fail())
        {
            cin.clear();
            limpiarBuffer();
            opVentas = -1;
        }

        switch (opVentas)
        {
            case 1: _manager.registrarVenta();   break;
            case 2: _manager.consultarVentas();  break;
            case 3: _manager.modificarVenta();   break;
            case 4: _manager.eliminarVenta();    break;
            case 5: _manager.altaVenta();        break;
            case 0: break;
            default:
                cout << "\n[!] Opcion incorrecta.\n";
                break;
        }
    }
    while (opVentas != 0);
}

void Menu::menuProductos()
{
    int opProd;
    do
    {
        system("cls");
        cout << "\n--- MODULO: INVENTARIO Y CATALOGO ---" << endl;
        cout << " [ 1 ] . Cargar Nuevo Producto" << endl;
        cout << " [ 2 ] . Listar Catalogo de Productos (Por Precio)" << endl;
        cout << " [ 3 ] . Eliminar Producto (Baja Logica)" << endl;
        cout << " [ 4 ] . Modificar Producto" << endl;
        cout << " [ 5 ] . Reactivar Producto (Alta Logica)" << endl;
        cout << "---------------------------------------" << endl;
        cout << " [ 0 ] . Volver al Menu Principal" << endl;
        cout << " Opcion: ";
        cin >> opProd;

        if (cin.fail())
        {
            cin.clear();
            limpiarBuffer();
            opProd = -1;
        }

        switch (opProd)
        {
            case 1: _manager.cargarProducto();   break;
            case 2: _manager.listarProductos();  break;
            case 3: _manager.eliminarProducto(); break;
            case 4: _manager.modificarProducto();break;
            case 5: _manager.altaProducto();     break;
            case 0: break;
            default:
                cout << "\n[!] Opcion incorrecta.\n";
                break;
        }
    }
    while (opProd != 0);
}

void Menu::menuClientes()
{
    int opCli;
    do
    {
        system("cls");
        cout << "\n--- MODULO: GESTION DE CLIENTES ---" << endl;
        cout << " [ 1 ] . Cargar Nuevo Cliente" << endl;
        cout << " [ 2 ] . Listar Clientes Activos" << endl;
        cout << " [ 3 ] . Eliminar Cliente" << endl;
        cout << " [ 4 ] . Modificar Cliente" << endl;
        cout << " [ 5 ] . Reactivar Cliente (Alta Logica)" << endl;
        cout << "----------------------------------" << endl;
        cout << " [ 0 ] . Volver al Menu Principal" << endl;
        cout << " Opcion: ";
        cin >> opCli;

        if (cin.fail())
        {
            cin.clear();
            limpiarBuffer();
            opCli = -1;
        }

        switch (opCli)
        {
            case 1: _manager.cargarCliente();   break;
            case 2: _manager.listarClientes();  break;
            case 3: _manager.eliminarCliente(); break;
            case 4: _manager.modificarCliente();break;
            case 5: _manager.altaCliente();     break;
            case 0: break;
            default:
                cout << "\n[!] Opcion incorrecta.\n";
                break;
        }
    }
    while (opCli != 0);
}

void Menu::menuEmpleados()
{
    int opEmp;
    do
    {
        system("cls");
        cout << "\n--- MODULO: GESTION DE EMPLEADOS ---" << endl;
        cout << " [ 1 ] . Cargar Nuevo Empleado" << endl;
        cout << " [ 2 ] . Listar Personal de la Tienda" << endl;
        cout << " [ 3 ] . Eliminar Empleado" << endl;
        cout << " [ 4 ] . Modificar Empleado" << endl;
        cout << " [ 5 ] . Reactivar Empleado (Alta Logica)" << endl;
        cout << "-----------------------------------" << endl;
        cout << " [ 0 ] . Volver al Menu Principal" << endl;
        cout << " Opcion: ";
        cin >> opEmp;

        if (cin.fail())
        {
            cin.clear();
            limpiarBuffer();
            opEmp = -1;
        }

        switch (opEmp)
        {
            case 1: _manager.cargarEmpleado();   break;
            case 2: _manager.listarEmpleados();  break;
            case 3: _manager.eliminarEmpleado(); break;
            case 4: _manager.modificarEmpleado();break;
            case 5: _manager.altaEmpleado();     break;
            case 0: break;
            default:
                cout << "\n[!] Opcion incorrecta.\n";
                break;
        }
    }
    while (opEmp != 0);
}

void Menu::menuHorarios()
{
    int opHor;
    do
    {
        system("cls");
        cout << "\n--- MODULO: HORARIOS Y ASISTENCIA ---" << endl;
        cout << " [ 1 ] . Registrar Fichada de Turno (Entrada/Salida)" << endl;
        cout << " [ 2 ] . Consultar Horas Trabajadas" << endl;
        cout << "------------------------------------" << endl;
        cout << " [ 0 ] . Volver al Menu Principal" << endl;
        cout << " Opcion: ";
        cin >> opHor;

        if (cin.fail())
        {
            cin.clear();
            limpiarBuffer();
            opHor = -1;
        }

        switch (opHor)
        {
            case 1: _manager.registrarHorario();        break;
            case 2: _manager.consultarHorasTrabajadas();break;
            case 0: break;
            default:
                cout << "\n[!] Opcion incorrecta.\n";
                break;
        }
    }
    while (opHor != 0);
}

void Menu::menuReportes()
{
    int opRep;
    do
    {
        system("cls");
        cout << "\n--- PANEL DE REPORTES E INFORMES ---" << endl;
        cout << " [ 1 ] . Ver Recaudacion Historica Total" << endl;
        cout << " [ 2 ] . Balance de Recaudacion Anual" << endl;
        cout << " [ 3 ] . Balance de Recaudacion Mensual" << endl;
        cout << " [ 4 ] . Total Recaudado por Empleado Vendedor" << endl;
        cout << " [ 5 ] . Unidades Vendidas por Categoria de Producto" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << " [ 0 ] . Volver al Menu Principal" << endl;
        cout << " Opcion: ";
        cin >> opRep;

        if (cin.fail())
        {
            cin.clear();
            limpiarBuffer();
            opRep = -1;
        }

        switch (opRep)
        {
            case 1: _manager.reporteRecaudacionTotal();        break;
            case 2: _manager.reporteRecaudacionAnual();        break;
            case 3: _manager.reporteRecaudacionMensual();      break;
            case 4: _manager.reporteRecaudacionPorEmpleado();  break;
            case 5: _manager.reporteCantidadPorCategoria();    break;
            case 0: break;
            default:
                cout << "\n[!] Opcion incorrecta.\n";
                break;
        }
    }
    while (opRep != 0);
}
