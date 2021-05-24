#include "fecha.h"
#include "empleado.h"
#include "comida.h"
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct
{
    int id;
    int idComida;
    int legEmpleado;
    eFecha fecha;
    int isEmpty;

}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

int altaAlmuerzo(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado empleados[], int tame, eSector sectores[], int tams, int* pNextId);

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado empleados[], int tame);

void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamc, eEmpleado empleados[], int tame);

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam);
