#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void mostrarServicio(eServicio unServicio)
{
    printf("%d   %10s   %.2f\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}

int mostrarServicios(eServicio servicios[], int tam)
{
    int todoOk = 0;

    if(servicios != NULL && tam > 0)
    {
    printf("********lista de servicios*******\n");
    printf("id      descripcion  precio\n");
        for(int i = 0; i < tam; i++)
        {
            mostrarServicio(servicios[i]);
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarServicio(eServicio servicios[],int tam, int id)
{
    int indice = -1;

    if(servicios != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                indice=i;

                break;

            }
        }

    }
    return indice;
}

int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[])
{
    int todoOk = 0;

    if(id>= 20000 && id <= 20003 && servicios != NULL && tam > 0 && desc != NULL){
    for(int i = 0; i < tam; i++)
    {
        if(servicios[i].id == id )
        {
            strcpy(desc, servicios[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
