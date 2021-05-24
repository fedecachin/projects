#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"

int cargarDescripcionSector(int id, eSector sectores[], int tam, char desc[])
{
    int todoOk = 0;

    if(id>= 500 && id <= 504 && sectores != NULL && tam > 0 && desc != NULL){
    for(int i = 0; i < tam; i++)
    {
        if(sectores[i].id == id )
        {
            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}

void mostrarSector(eSector sector)
{
    printf("%d   %s\n", sector.id, sector.descripcion);
}

void mostrarSectores(eSector sectores[], int tam)
{
    printf("      lista de sectores\n");
    printf("id    sector\n");
    for(int i = 0; i < tam; i++)
    {
       mostrarSector(sectores[i]);
    }
}

int validarIdSector(int id, eSector sectores[], int tam)
{
    int esta = 0;

    for(int i = 0; i < tam; i++)
    {
        if(sectores[i].id == id);
        esta = 1;
        break;
    }

    return esta;
}
