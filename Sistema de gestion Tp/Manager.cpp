#include <iostream>
#include <cstring>
#include <iomanip>
#include "Manager.h"
using namespace std;

                        // VENTAS

void Manager::registrarVenta()
{
    cout << "\n>> REGISTRAR NUEVA VENTA <<" << endl;
    char dniCliente[20];
    char codigoProd[30];
    int legajoEmp, cantidad, dia, mes, anio;
    bool entradaValida;

    limpiarBuffer();


    int posCliente = -1;
    do
    {
        cout << " Ingrese DNI del Cliente: ";
        cin >> setw(20) >> dniCliente;
        posCliente = _srvCliente.buscarPorDNI(dniCliente);
        if(posCliente == -1)
        {
            cout << "   [!] Error: Cliente no encontrado en la base de datos." << endl;
        }
    } while(posCliente == -1);

    Cliente cli = _srvCliente.leerCliente(posCliente);


    int posEmp = -1;
    do
    {
        cout << " Ingrese Legajo del Vendedor: ";
        cin >> legajoEmp;
        if(cin.fail()) { cin.clear(); limpiarBuffer(); legajoEmp = -1; }

        posEmp = _srvEmpleado.buscarPorLegajo(legajoEmp);
        if(posEmp == -1) cout << "   [!] Error: Vendedor no encontrado." << endl;
    } while(posEmp == -1);

    Empleado emp = _srvEmpleado.leerEmpleado(posEmp);


    int posProd = -1;
    do
    {
        cout << " Ingrese Codigo del Producto: ";
        cin >> setw(30) >> codigoProd;
        posProd = _srvProducto.buscarPorCodigo(codigoProd);
        if(posProd == -1) cout << "   [!] Error: El articulo no existe o fue dado de baja." << endl;
    } while(posProd == -1);

    Producto prod = _srvProducto.leerProducto(posProd);

    do
    {
        cout << " Cantidad a faturar (Stock disponible: " << prod.getStock() << "): ";
        cin >> cantidad;
        if(cin.fail() || cantidad <= 0 || cantidad > prod.getStock())
        {
            cout << "   [!] Error: Cantidad no valida o stock insuficiente." << endl;
            cin.clear();
            limpiarBuffer();
            entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);


    do
    {
        cout << " Ingrese Dia, Mes y Anio (Ejemplo: 24 5 2026): ";
        cin >> dia >> mes >> anio;
        if(cin.fail() || !validaFecha(dia, mes, anio))
        {
            cout << "   [!] Error: Fecha ingresada no es valida." << endl;
            cin.clear();
            limpiarBuffer();
            entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);

    Fecha fVenta;
    fVenta.setDia(dia);
    fVenta.setMes(mes);
    fVenta.setAnio(anio);

    float montoTotal = cantidad * prod.getPrecio();


    Venta nueva;
    int idVenta = _srvVenta.getCantidadRegistros() + 1;

    nueva.setIdVenta(idVenta);
    nueva.setIdCliente(cli.getIdPersona());
    nueva.setIdEmpleado(emp.getIdPersona());
    nueva.setIdProducto(prod.getIdProducto());
    nueva.setCantidad(cantidad);
    nueva.setMontoTotal(montoTotal);
    nueva.setFechaVenta(fVenta);
    nueva.setActivo(true);

    if(_srvVenta.guardarVenta(nueva))
    {
        _srvProducto.actualizarStock(prod.getIdProducto(), -cantidad);
        cout << "\n[OK] �Venta N� " << idVenta << " confirmada! Monto Total: $" << montoTotal << endl;
    }
    else
    {
        cout << "\n[!] Error al intentar registrar la venta." << endl;
    }
}

void Manager::consultarVentas()
{
    int total = _srvVenta.getCantidadRegistros();
    if(total == 0)
    {
        cout << "\n[!] No hay transacciones registradas en el archivo." << endl;
        return;
    }

    cout << "\n=====================================================================" << endl;
    cout << " ID VENTA\tFECHA\t\tCANTIDAD\tMONTO TOTAL" << endl;
    cout << "=====================================================================" << endl;

    for(int i = 0; i < total; i++)
    {
        Venta ven = _srvVenta.leerVenta(i);
        if(ven.getActivo() == true)
        {
            Fecha f = ven.getFechaVenta();
            cout << " " << ven.getIdVenta() << "\t\t"
                 << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << "\t"
                 << ven.getCantidad() << " un.\t\t$"
                 << ven.getMontoTotal() << endl;
        }
    }
    cout << "---------------------------------------------------------------------" << endl;
}

                //EMPLEADOS

void Manager::cargarEmpleado()
{
    cout << "\n>> ALTA DE NUEVO EMPLEADO <<" << endl;
    char nombre[50];
    char apellido[50];
    char dni[20];
    int tipoAdmin;
    bool entradaValida;

    limpiarBuffer();

    do
    {
        cout << " Ingrese Nombres: ";
        cin.getline(nombre, 50);
        entradaValida = validarTexto(nombre) && strlen(nombre) > 0;
        if(!entradaValida) cout << "   [!] Error: Texto invalido." << endl;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese Apellidos: ";
        cin.getline(apellido, 50);
        entradaValida = validarTexto(apellido) && strlen(apellido) > 0;
        if(!entradaValida) cout << "   [!] Error: Texto invalido." << endl;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese DNI: ";
        cin >> setw(20) >> dni;
        if(!validarNumeros(dni))
        {
            cout << "   [!] Error: El DNI solo debe contener numeros." << endl;
            entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);

    do
    {
        cout << " Es Administrador? (1 = SI / 0 = NO): ";
        cin >> tipoAdmin;
        if(cin.fail() || (tipoAdmin < 0 || tipoAdmin > 1))
        {
            cout << "   [!] Error: Seleccione 1 o 0." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);

    Empleado emp;
    int nuevoId = _srvEmpleado.getCantidadRegistros() + 1;
    int nuevoLegajo = generacionLegajo();

    emp.setIdPersona(nuevoId);
    emp.setNombre(nombre);
    emp.setApellido(apellido);
    emp.setDniPersona(dni);
    emp.setLegajo(nuevoLegajo);
    emp.setesAdmin(tipoAdmin == 1);
    emp.setActivo(true);

    bool ok = _srvEmpleado.guardarEmpleado(emp);
    resultadoAccion(ok);
}

void Manager::listarEmpleados()
{
    int cant = _srvEmpleado.getCantidadActivos();
    if(cant == 0)
    {
        cout << "\n[!] No hay empleados activos en el sistema." << endl;
        return;
    }

    Empleado* lista = _srvEmpleado.listarEmpleados();
    if(lista != nullptr)
    {
        cout << "\n=====================================================================" << endl;
        cout << " LEGAJO\tDNI\t\tADMIN\tAPELLIDO Y NOMBRE" << endl;
        cout << "=====================================================================" << endl;
        for(int i = 0; i < cant; i++)
        {
            cout << " " << lista[i].getLegajo() << "\t"
                 << lista[i].getDniPersona() << "\t"
                 << (lista[i].getesAdmin() ? "SI" : "NO") << "\t"
                 << lista[i].getApellido() << ", " << lista[i].getNombre() << endl;
        }
        cout << "---------------------------------------------------------------------" << endl;
        delete[] lista; //
    }
}

void Manager::eliminarEmpleado()
{
    int legajoBuscado;
    cout << "\n>> BAJA DE EMPLEADO <<" << endl;
    cout << " Ingrese el LEGAJO del empleado a despedir/dar de baja: ";
    cin >> legajoBuscado;

    int pos = _srvEmpleado.buscarPorLegajo(legajoBuscado);
    if(pos == -1)
    {
        cout << "\n[!] No se encontro ningun empleado activo con ese legajo." << endl;
        return;
    }

    Empleado emp = _srvEmpleado.leerEmpleado(pos);
    cout << "\n Personal encontrado: " << emp.getApellido() << ", " << emp.getNombre() << endl;
    cout << " Confirmar baja? (1 = SI / 0 = NO): ";
    int conf;
    cin >> conf;
    if(conf == 1)
    {
        bool ok = _srvEmpleado.bajaLogica(pos);
        resultadoAccion(ok);
    }
}


        // CLIENTES

void Manager::cargarCliente()
{
    cout << "\n>> ALTA DE NUEVO CLIENTE <<" << endl;
    char nombre[50];
    char apellido[50];
    char dni[20];
    char email[50];
    bool entradaValida;

    limpiarBuffer();

    do
    {
        cout << " Ingrese Nombres: ";
        cin.getline(nombre, 50);
        entradaValida = validarTexto(nombre) && strlen(nombre) > 0;
        if(!entradaValida) cout << "   [!] Error: Texto invalido." << endl;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese Apellidos: ";
        cin.getline(apellido, 50);
        entradaValida = validarTexto(apellido) && strlen(apellido) > 0;
        if(!entradaValida) cout << "   [!] Error: Texto invalido." << endl;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese DNI: ";
        cin >> setw(20) >> dni;
        if(!validarNumeros(dni) || _srvCliente.buscarPorDNI(dni) != -1)
        {
            cout << "   [!] Error: DNI invalido o ya registrado." << endl;
            entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese Correo Electronico (Email): ";
        cin >> setw(50) >> email;
        entradaValida = validarEmail(email);
        if(!entradaValida) cout << "   [!] Error: Email invalido." << endl;
    } while(!entradaValida);

    Cliente cli;
    int nuevoId = generacionId(1);

    cli.setIdPersona(nuevoId);
    cli.setNombre(nombre);
    cli.setApellido(apellido);
    cli.setDniPersona(dni);
    cli.setEmail(email);
    cli.setActivo(true);

    bool ok = _srvCliente.guardarCliente(cli);
    resultadoAccion(ok);
}

void Manager::listarClientes()
{
    int cant = _srvCliente.getCantidadActivos();
    if(cant == 0)
    {
        cout << "\n[!] No hay clientes registrados." << endl;
        return;
    }

    Cliente* lista = _srvCliente.listarClientes();
    if(lista != nullptr)
    {
        cout << "\n=====================================================================" << endl;
        cout << " DNI\t\tEMAIL\t\t\tAPELLIDO Y NOMBRE" << endl;
        cout << "=====================================================================" << endl;
        for(int i = 0; i < cant; i++)
        {
            cout << " " << lista[i].getDniPersona() << "\t"
                 << lista[i].getEmail() << "\t\t"
                 << lista[i].getApellido() << ", " << lista[i].getNombre() << endl;
        }
        cout << "---------------------------------------------------------------------" << endl;
        delete[] lista;
    }
}

void Manager::eliminarCliente()
{
    char dniBuscado[20];
    cout << "\n>> BAJA DE CLIENTE <<" << endl;
    cout << " Ingrese el DNI del cliente a eliminar: ";
    cin >> setw(20) >> dniBuscado;

    int pos = _srvCliente.buscarPorDNI(dniBuscado);
    if(pos == -1)
    {
        cout << "\n[!] Cliente no encontrado." << endl;
        return;
    }

    Cliente cli = _srvCliente.leerCliente(pos);
    cout << "\n Cliente: " << cli.getApellido() << ", " << cli.getNombre() << endl;
    cout << " Confirmar eliminacion? (1 = SI / 0 = NO): ";
    int conf;
    cin >> conf;
    if(conf == 1)
    {
        bool ok = _srvCliente.bajaLogica(pos);
        resultadoAccion(ok);
    }
}

                //HORARIOS

void Manager::registrarHorario()
{
    cout << "\n>> REGISTRAR FICHADA DE TURNO <<" << endl;
    int legajo, dia, mes, anio, hEnt, mEnt, hSal, mSal;
    bool valida;


    int posEmp = -1;
    do
    {
        cout << " Ingrese Legajo del Empleado: ";
        cin >> legajo;
        posEmp = _srvEmpleado.buscarPorLegajo(legajo);
        if(posEmp == -1) cout << "   [!] Empleado inexistente." << endl;
    } while(posEmp == -1);

    Empleado emp = _srvEmpleado.leerEmpleado(posEmp);


    do
    {
        cout << " Fecha del turno (Dia Mes Anio): ";
        cin >> dia >> mes >> anio;
        valida = validaFecha(dia, mes, anio);
        if(!valida) cout << "   [!] Fecha incorrecta." << endl;
    } while(!valida);

    Fecha fTurno;
    fTurno.setDia(dia); fTurno.setMes(mes); fTurno.setAnio(anio);


    do
    {
        cout << " Hora de ENTRADA (Hora Minuto): ";
        cin >> hEnt >> mEnt;
        valida = validarHora(hEnt, mEnt);
        if(!valida) cout << "   [!] Formato de hora invalido." << endl;
    } while(!valida);

    do
    {
        cout << " Hora de SALIDA (Hora Minuto): ";
        cin >> hSal >> mSal;
        valida = validarHora(hSal, mSal) && (hSal * 60 + mSal) > (hEnt * 60 + mEnt);
        if(!valida) cout << "   [!] La hora de salida debe ser posterior a la de entrada." << endl;
    } while(!valida);

    Horarios hor;
    int nuevoId = _srvHorarios.getCantidadRegistros() + 1;

    hor.setIdTurno(nuevoId);
    hor.setIdEmpleado(emp.getIdPersona());
    hor.setFecha(fTurno);
    hor.setHoraEntrada(hEnt);
    hor.setMinutoEntrada(mEnt);
    hor.setHoraSalida(hSal);
    hor.setMinutoSalida(mSal);
    hor.setAsistencia(true);
    hor.setActivo(true);

    bool ok = _srvHorarios.guardarHorario(hor);
    resultadoAccion(ok);
}

void Manager::consultarHorasTrabajadas()
{
    int legajoBuscado;
    cout << "\n>> CONSULTA DE HORAS POR EMPLEADO <<" << endl;
    cout << " Ingrese el Legajo: ";
    cin >> legajoBuscado;

    int pos = _srvEmpleado.buscarPorLegajo(legajoBuscado);
    if(pos == -1)
    {
        cout << "\n[!] Empleado no encontrado." << endl;
        return;
    }

    Empleado emp = _srvEmpleado.leerEmpleado(pos);
    int totalRegistros = _srvHorarios.getCantidadRegistros();
    int minutosAcumulados = 0;

    for(int i = 0; i < totalRegistros; i++)
    {
        Horarios h = _srvHorarios.leerHorario(i);
        if(h.getActivo() == true && h.getIdEmpleado() == emp.getIdPersona())
        {
            int entrada = h.getHoraEntrada() * 60 + h.getMinutoEntrada();
            int salida = h.getHoraSalida() * 60 + h.getMinutoSalida();
            int duracion = salida - entrada;
            if(duracion > 0) minutosAcumulados += duracion;
        }
    }

    cout << "\n El empleado " << emp.getApellido() << " ha trabajado un total de "
         << (minutosAcumulados / 60) << " horas y " << (minutosAcumulados % 60)
         << " minutos registrados." << endl;
}


                // REPORTES


void Manager::reporteRecaudacionTotal()
{
    limpiarBuffer();

    cout << "\n=================================================" << endl;
    cout << "        REPORTE: RECAUDACION HISTORICA TOTAL     " << endl;
    cout << "=================================================" << endl;

    float total = _srvVenta.recaudacionTotal();

    cout << " >> El total neto facturado por la tienda es: $" << total << endl;
    cout << "=================================================" << endl;
}

void Manager::reporteRecaudacionAnual()
{
    limpiarBuffer();

    cout << "\n=================================================" << endl;
    cout << "            REPORTE: RECAUDACION ANUAL           " << endl;
    cout << "=================================================" << endl;

    int anio;
    bool entradaValida;

    do
    {
        cout << " Ingrese el anio a evaluar (Ej: 2026): ";
        cin >> anio;

        if (cin.fail() || anio < 2000 || anio > 2100)
        {
            cout << "   [!] Error: Ingrese un anio valido." << endl;
            cin.clear();
            limpiarBuffer();
            entradaValida = false;
        }
        else
        {
            entradaValida = true;
        }
    } while (!entradaValida);

    float total = _srvVenta.recaudacionAnual(anio);

    cout << "\n >> Recaudacion total del anio " << anio << ": $" << total << endl;
    cout << "=================================================" << endl;
}

void Manager::reporteRecaudacionMensual()
{
    limpiarBuffer();

    cout << "\n=================================================" << endl;
    cout << "           REPORTE: RECAUDACION MENSUAL          " << endl;
    cout << "=================================================" << endl;

    int mes, anio;
    bool entradaValida;

    do
    {
        cout << " Ingrese el anio (Ej: 2026): ";
        cin >> anio;
        if (cin.fail() || anio < 2000 || anio > 2100)
        {
            cout << "   [!] Error: Anio invalido." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
            continue;
        }

        cout << " Ingrese el numero de mes (1-12): ";
        cin >> mes;
        if (cin.fail() || mes < 1 || mes > 12)
        {
            cout << "   [!] Error: El mes debe estar entre 1 y 12." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else
        {
            entradaValida = true;
        }
    } while (!entradaValida);

    float total = _srvVenta.recaudacionMensual(mes, anio);

    cout << "\n >> Recaudacion del periodo " << mes << "/" << anio << ": $" << total << endl;
    cout << "=================================================" << endl;
}

void Manager::reporteRecaudacionPorEmpleado()
{
    limpiarBuffer();

    cout << "\n=================================================" << endl;
    cout << "        REPORTE: RECAUDACION POR EMPLEADO        " << endl;
    cout << "=================================================" << endl;

    int legajo;
    int dIni, mIni, aIni, dFin, mFin, aFin;
    bool entradaValida;


    int posEmp = -1;
    do
    {
        cout << " Ingrese el Legajo del Empleado: ";
        cin >> legajo;
        if (cin.fail()) { cin.clear(); limpiarBuffer(); legajo = -1; }

        posEmp = _srvEmpleado.buscarPorLegajo(legajo);
        if (posEmp == -1)
        {
            cout << "   [!] Error: No existe un empleado activo con ese legajo." << endl;
        }
    } while (posEmp == -1);

    Empleado emp = _srvEmpleado.leerEmpleado(posEmp);


    do
    {
        cout << " Fecha INICIO del rango (Dia Mes Anio): ";
        cin >> dIni >> mIni >> aIni;
        if (cin.fail() || !validaFecha(dIni, mIni, aIni))
        {
            cout << "   [!] Error: Fecha de inicio invalida." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
            continue;
        }

        cout << " Fecha FIN del rango (Dia Mes Anio): ";
        cin >> dFin >> mFin >> aFin;
        if (cin.fail() || !validaFecha(dFin, mFin, aFin))
        {
            cout << "   [!] Error: Fecha de fin invalida." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else
        {
            entradaValida = true;
        }
    } while (!entradaValida);

    Fecha fInicio, fFin;
    fInicio.setDia(dIni); fInicio.setMes(mIni); fInicio.setAnio(aIni);
    fFin.setDia(dFin); fFin.setMes(mFin); fFin.setAnio(aFin);

    float total = _srvVenta.recaudacionPorEmpleado(emp.getIdPersona(), fInicio, fFin);

    cout << "\n >> Empleado: " << emp.getApellido() << ", " << emp.getNombre() << endl;
    cout << " >> Total recaudado en el rango: $" << total << endl;
    cout << "=================================================" << endl;
}

void Manager::reporteCantidadPorCategoria()
{
    limpiarBuffer();

    cout << "\n=================================================" << endl;
    cout << "       REPORTE: UNIDADES VENDIDAS POR RUBRO      " << endl;
    cout << "=================================================" << endl;

    int categoria;
    int dIni, mIni, aIni, dFin, mFin, aFin;
    bool entradaValida;


    do
    {
        cout << " Seleccione Categoria (1: Calzado | 2: Indumentaria | 3: Accesorios): ";
        cin >> categoria;
        if (cin.fail() || categoria < 1 || categoria > 3)
        {
            cout << "   [!] Error: Rubro incorrecto." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else
        {
            entradaValida = true;
        }
    } while (!entradaValida);


    do
    {
        cout << " Fecha INICIO del rango (Dia Mes Anio): ";
        cin >> dIni >> mIni >> aIni;
        if (cin.fail() || !validaFecha(dIni, mIni, aIni))
        {
            cout << "   [!] Error: Fecha de inicio invalida." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
            continue;
        }

        cout << " Fecha FIN del rango (Dia Mes Anio): ";
        cin >> dFin >> mFin >> aFin;
        if (cin.fail() || !validaFecha(dFin, mFin, aFin))
        {
            cout << "   [!] Error: Fecha de fin invalida." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else
        {
            entradaValida = true;
        }
    } while (!entradaValida);

    Fecha fInicio, fFin;
    fInicio.setDia(dIni); fInicio.setMes(mIni); fInicio.setAnio(aIni);
    fFin.setDia(dFin); fFin.setMes(mFin); fFin.setAnio(aFin);

    int unidades = _srvVenta.cantidadVendidaPorCategoria(categoria, fInicio, fFin);

    cout << "\n >> Total de unidades comercializadas de este rubro: " << unidades << " un." << endl;
    cout << "=================================================" << endl;
}

                //PRODUCTOS

void Manager::cargarProducto()
{
    cout << "\n>> ALTA DE NUEVO PRODUCTO <<" << endl;
    char nombre[50];
    char codigo[30];
    int categoria, stock;
    float precio;
    bool entradaValida;

    limpiarBuffer();

    do
    {
        cout << " Ingrese Nombre del Producto: ";
        cin.getline(nombre, 50);
        entradaValida = validarTexto(nombre) && strlen(nombre) > 0;
        if(!entradaValida) cout << "   [!] Error: Texto invalido." << endl;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese Codigo del Producto: ";
        cin >> setw(30) >> codigo;
        entradaValida = strlen(codigo) > 0 && _srvProducto.buscarPorCodigo(codigo) == -1;
        if(!entradaValida) cout << "   [!] Error: Codigo invalido o ya registrado." << endl;
    } while(!entradaValida);

    do
    {
        cout << " Seleccione Categoria (1: Calzado | 2: Indumentaria | 3: Accesorios): ";
        cin >> categoria;
        if(cin.fail() || categoria < 1 || categoria > 3)
        {
            cout << "   [!] Error: Categoria invalida." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese Precio: ";
        cin >> precio;
        if(cin.fail() || precio <= 0)
        {
            cout << "   [!] Error: El precio debe ser mayor a 0." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);

    do
    {
        cout << " Ingrese Stock inicial: ";
        cin >> stock;
        if(cin.fail() || stock < 0)
        {
            cout << "   [!] Error: El stock no puede ser negativo." << endl;
            cin.clear(); limpiarBuffer(); entradaValida = false;
        }
        else entradaValida = true;
    } while(!entradaValida);

    Producto prod;
    int nuevoId = generacionId(3);

    prod.setIdProducto(nuevoId);
    prod.setNombre(nombre);
    prod.setCodigo(codigo);
    prod.setCategoria(categoria);
    prod.setPrecio(precio);
    prod.setStock(stock);
    prod.setActivo(true);

    bool ok = _srvProducto.guardarProducto(prod);
    resultadoAccion(ok);
}

void Manager::listarProductos()
{
    int cant = _srvProducto.getCantidadActivos();
    if(cant == 0)
    {
        cout << "\n[!] No hay productos cargados en el catalogo." << endl;
        return;
    }

    Producto* lista = _srvProducto.listarPorPrecio();
    if(lista != nullptr)
    {
        cout << "\n=====================================================================" << endl;
        cout << " CODIGO\t\tNOMBRE\t\tPRECIO\t\tSTOCK" << endl;
        cout << "=====================================================================" << endl;
        for(int i = 0; i < cant; i++)
        {
            cout << " " << lista[i].getCodigo() << "\t\t"
                 << lista[i].getNombre() << "\t\t$"
                 << lista[i].getPrecio() << "\t\t"
                 << lista[i].getStock() << endl;
        }
        cout << "---------------------------------------------------------------------" << endl;
        delete[] lista;
    }
}

void Manager::eliminarProducto()
{
    char codigoBuscado[30];
    cout << "\n>> BAJA DE PRODUCTO <<" << endl;
    cout << " Ingrese el Codigo del producto a eliminar: ";
    cin >> setw(30) >> codigoBuscado;

    int pos = _srvProducto.buscarPorCodigo(codigoBuscado);
    if(pos == -1)
    {
        cout << "\n[!] Producto no encontrado." << endl;
        return;
    }

    Producto prod = _srvProducto.leerProducto(pos);
    cout << "\n Producto encontrado: " << prod.getNombre() << endl;
    cout << " Confirmar baja? (1 = SI / 0 = NO): ";
    int conf;
    cin >> conf;
    if(conf == 1)
    {
        bool ok = _srvProducto.bajaLogica(pos);
        resultadoAccion(ok);
    }
}
