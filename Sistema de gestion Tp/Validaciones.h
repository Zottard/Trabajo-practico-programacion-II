#pragma once
#include <string>

void resultadoAccion(bool respuesta);
void limpiarBuffer();
bool reintentarOVolver();

int generacionId(int tipo);
int generacionLegajo();

bool validarNumeros(const char* numero);
bool validarTexto(const char* texto);
bool validarEmail(const char* email);
bool validaFecha(int dia, int mes, int anio);
bool validarHora(int hora, int minuto);
