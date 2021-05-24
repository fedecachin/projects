#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"

void mostrarComidas(eComida comidas[], int tam)
{
    printf("      lista de comidas\n");
    printf("id    descripcion        precio\n");
    for(int i = 0; i < tam; i++)
    {
       mostrarComida(comidas[i]);
    }
}

void mostrarComida(eComida unaComida)
{
    printf("%d    %10s         %.2f\n", unaComida.id, unaComida.descripcion, unaComida.precio);
}

int cargarDescripcionComida(int id, eComida comidas[], int tam, char desc[])
{
    int todoOk = 0;

    if(id>= 1000 && id <= 1004 && comidas!= NULL && tam > 0 && desc != NULL){
    for(int i = 0; i < tam; i++)
    {
        if(comidas[i].id == id )
        {
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
