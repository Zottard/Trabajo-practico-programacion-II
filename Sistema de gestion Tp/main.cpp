#include <iostream>
#include "Manager.h"
#include "Validaciones.h"

using namespace std;

int main()
{
    Manager manager;
    int opPrincipal;

    do
    {
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
            case 1: // =========================================================
            {       // M�DULO VENTAS
                int opVentas;
                do
                {
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
                        case 1:
                            manager.registrarVenta();
                            break;
                        case 2:
                            manager.consultarVentas();
                            break;
                        case 3:
                            manager.modificarVenta();
                            break;
                        case 4:
                            manager.eliminarVenta();
                            break;
                        case 5:
                            manager.altaVenta();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\n[!] Opcion incorrecta.\n";
                            break;
                    }
                }
                while (opVentas != 0);
                break;
            }

            case 2: // =========================================================
            {       // M�DULO PRODUCTOS
                int opProd;
                do
                {
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
                        case 1:
                            manager.cargarProducto();
                            break;
                        case 2:
                            manager.listarProductos();
                            break;
                        case 3:
                            manager.eliminarProducto();
                            break;
                        case 4:
                            manager.modificarProducto();
                            break;
                        case 5:
                            manager.altaProducto();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\n[!] Opcion incorrecta.\n";
                            break;
                    }
                }
                while (opProd != 0);
                break;
            }

            case 3: // =========================================================
            {       // M�DULO CLIENTES
                int opCli;
                do
                {
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
                        case 1:
                            manager.cargarCliente();
                            break;
                        case 2:
                            manager.listarClientes();
                            break;
                        case 3:
                            manager.eliminarCliente();
                            break;
                        case 4:
                            manager.modificarCliente();
                            break;
                        case 5:
                            manager.altaCliente();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\n[!] Opcion incorrecta.\n";
                            break;
                    }
                }
                while (opCli != 0);
                break;
            }

            case 4: // =========================================================
            {       // M�DULO EMPLEADOS
                int opEmp;
                do
                {
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
                        case 1:
                            manager.cargarEmpleado();
                            break;
                        case 2:
                            manager.listarEmpleados();
                            break;
                        case 3:
                            manager.eliminarEmpleado();
                            break;
                        case 4:
                            manager.modificarEmpleado();
                            break;
                        case 5:
                            manager.altaEmpleado();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\n[!] Opcion incorrecta.\n";
                            break;
                    }
                }
                while (opEmp != 0);
                break;
            }

            case 5: // =========================================================
            {       // M�DULO HORARIOS
                int opHor;
                do
                {
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
                        case 1:
                            manager.registrarHorario();
                            break;
                        case 2:
                            manager.consultarHorasTrabajadas();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\n[!] Opcion incorrecta.\n";
                            break;
                    }
                }
                while (opHor != 0);
                break;
            }

            case 6: // =========================================================
            {       // M�DULO REPORTES
                int opRep;
                do
                {
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
                        case 1:
                            manager.reporteRecaudacionTotal();
                            break;
                        case 2:
                            manager.reporteRecaudacionAnual();
                            break;
                        case 3:
                            manager.reporteRecaudacionMensual();
                            break;
                        case 4:
                            manager.reporteRecaudacionPorEmpleado();
                            break;
                        case 5:
                            manager.reporteCantidadPorCategoria();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\n[!] Opcion incorrecta.\n";
                            break;
                    }
                }
                while (opRep != 0);
                break;
            }

            case 0:
                cout << "\n[ Cerrando el software de la Tienda... ]\n" << endl;
                break;

            default:
                cout << "\n[!] Modulo inexistente. Intente de nuevo.\n" << endl;
                break;
        }
    }
    while (opPrincipal != 0);

    return 0;
}
