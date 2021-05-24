#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "comida.h"
#include "empleado.h"

int altaAlmuerzo(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams, int* pNextId)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int idComida;
    eAlmuerzo nuevoAlmuerzo;

    if(almuerzos != NULL && comidas != NULL && lista != NULL && sectores != NULL && pNextId != NULL && tama > 0 && tamc >0 && tame >0 && tams>0)
    {
        printf("     Alta almuerzos\n");
        indice= buscarLibreAlmuerzo(almuerzos, tama);
        if(indice==-1)
        {
            printf("No hay lugar para mas almuerzos\n\n");
        }
        else
        {
            mostrarEmpleados(lista, tame, sectores, tams);
            printf("Ingrese legajo empleado: ");
            scanf("%d", &legajo);

            while(buscarEmpleado(lista, tame, legajo)==-1)
            {
                printf("No existe un empleado con ese legajo. Reingrese legajo: ");
                scanf("%d", &legajo);
            }
            nuevoAlmuerzo.legEmpleado=legajo;

            mostrarComidas(comidas, tamc);
            printf("Ingrese ID comida: ");
            scanf("%d", &idComida);

            nuevoAlmuerzo.idComida= idComida;
            printf("Ingrese fecha dd/mm/aaaa:");
            scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);

            nuevoAlmuerzo.id = *pNextId;
            (*pNextId)++;
            nuevoAlmuerzo.isEmpty=0;
            almuerzos[indice]= nuevoAlmuerzo;
            todoOk=1;
        }
    }




    return todoOk;
}

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado empleados[], int tame)
{
    int bandera = 1;
    printf("      lista de almuerzos\n");
    printf("  id   legajo  nombre  comida  fecha\n");
    for(int i = 0; i < tama; i++)
    {
        if(!almuerzos[i].isEmpty)
        {
            mostrarAlmuerzo(almuerzos[i], comidas, tamc, empleados, tame);
            bandera = 0;
        }
        if(bandera)
        {
            printf("no hay almuerzos que mostrar");
        }
    }
}

void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamc, eEmpleado empleados[], int tame)
{
    char nombreEmpleado[20];
    char descComida[20];

    if(cargarNombreEmpleado(almuerzo.legEmpleado, empleados, tame, nombreEmpleado) && cargarDescripcionComida(almuerzo.idComida, comidas, tamc, descComida))
    {

        printf("  %d   %d   %10s    %10s    %02d/%02d/%d", almuerzo.id, almuerzo.legEmpleado, nombreEmpleado, descComida, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);
    }
}

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam)
{
    int lLibre=-1;

    for(int i=0; i<tam; i++)
    {
        if(almuerzos[i].isEmpty)
        {
            lLibre=i;
            break;
        }
    }
    return lLibre;
}
