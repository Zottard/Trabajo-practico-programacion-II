#pragma once
class Fecha
{
    public:
        Fecha();
        void fechaActual();

        void mostrarFecha();
        void mostrarHora();
        void cargarFecha();

        void setAnio(int);
        void setMes(int);
        void setDia(int);
        void setHora(int);
        void setMinuto(int);

        int getAnio();
        int getMes();
        int getDia();
        int getHora();
        int getMinuto();

    private:
        int _hora,_minuto;
        int _dia, _mes;
        int _anio;
};

