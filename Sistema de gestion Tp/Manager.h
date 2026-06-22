#pragma once
#include "ServiceCliente.h"
#include "ServiceEmpleado.h"
#include "ServiceProducto.h"
#include "ServiceVenta.h"
#include "ServiceHorarios.h"

class Manager
{
    public:
        Manager();

        void menuPrincipal();
        void menuVentas();
        void menuInventario();
        void menuPersonal();
        void generarInformes();

    private:
        ServiceCliente _srvCliente;
        ServiceEmpleado _srvEmpleado;
        ServiceProducto _srvProducto;
        ServiceVenta _srvVenta;
        ServiceHorarios _srvHorarios;
};
