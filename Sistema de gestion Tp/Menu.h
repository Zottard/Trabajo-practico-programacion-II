#pragma once
#include "Manager.h"

class Menu
{
    public:
        Menu();

        void menuPrincipal();

    private:
        Manager _manager;

        void menuVentas();
        void menuProductos();
        void menuClientes();
        void menuEmpleados();
        void menuHorarios();
        void menuReportes();
};
