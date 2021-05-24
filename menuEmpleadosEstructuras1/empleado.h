#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sector.h"
#include "fecha.h"



typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    eFecha fIngreso;
    int idSector;
    int isEmpty;

} eEmpleado;

#endif // EMPLEADO_H_INCLUDED

void ordenarEmpleados(eEmpleado lista[], int tam);

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec);

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam);

void inicializarEmpleados(eEmpleado lista[], int tam);

int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo);

int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec, int* pLegajo);

int buscarLibre(eEmpleado lista[], int tam);

int buscarEmpleado(eEmpleado lista[], int tam, int legajo);

int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec);

int modificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec);

int cargarNombreEmpleado(int legajo, eEmpleado lista[], int tam, char desc[]);



