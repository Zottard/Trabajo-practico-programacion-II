#pragma once
#include "ServiceCliente.h"
#include "ServiceEmpleado.h"
#include "ServiceProducto.h"
#include "ServiceVenta.h"
#include "ServiceHorarios.h"
#include "Validaciones.h"

class Manager
{
    public:
        Manager();

        //VENTAS
        void registrarVenta();
        void consultarVentas();
        void modificarVenta();
        void eliminarVenta();
        void altaVenta();

        // PRODUCTOS
        void cargarProducto();
        void listarProductos();
        void eliminarProducto();
        void modificarProducto();
        void altaProducto();

        //  EMPLEADOS
        void cargarEmpleado();
        void listarEmpleados();
        void eliminarEmpleado();
        void modificarEmpleado();
        void altaEmpleado();

        //  CLIENTES
        void cargarCliente();
        void listarClientes();
        void eliminarCliente();
        void modificarCliente();
        void altaCliente();

        //  HORARIOS
        void registrarHorario();
        void consultarHorasTrabajadas();

        // REPORTES
        void reporteRecaudacionTotal();
        void reporteRecaudacionAnual();
        void reporteRecaudacionMensual();
        void reporteRecaudacionPorEmpleado();
        void reporteCantidadPorCategoria();

    private:
        ServiceCliente _srvCliente;
        ServiceEmpleado _srvEmpleado;
        ServiceProducto _srvProducto;
        ServiceVenta _srvVenta;
        ServiceHorarios _srvHorarios;
};
