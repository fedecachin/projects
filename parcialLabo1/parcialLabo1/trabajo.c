#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"


int altaTrabajo(eTrabajo trabajos[], int tamTr, eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamS, int* idTrabajo)
{
    int altaExitosa = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(bicicletas != NULL && tamB > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && idTrabajo != NULL && trabajos != NULL && tamTr > 0 && servicios != NULL && tamS > 0)
    {
        indice = buscarTrabajoLibre(trabajos, tamTr);

        if(indice == -1)
        {
            altaExitosa = 2;
        }
        else
        {
            mostrarBicicletas(bicicletas, tamB, colores, tamC, tipos, tamT);
            printf("ingrese el id de la bicicleta: ");
            scanf("%d", &auxTrabajo.idBicicleta);
            while(buscarBicicleta(bicicletas, tamB, auxTrabajo.idBicicleta)== -1)
            {
                printf("error, ingrese el id de la bicicleta: ");
                scanf("%d", &auxTrabajo.idBicicleta);
            }

            mostrarServicios(servicios, tamS);
            printf("ingrese el id del servicio: ");
            scanf("%d", &auxTrabajo.idServicio);
            while(buscarServicio(servicios, tamS, auxTrabajo.idServicio)== -1)
            {
                printf("error, ingrese el id del servicio: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            printf("ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

            auxTrabajo.isEmpty = 0;

            auxTrabajo.id = *idTrabajo;
            *idTrabajo=*idTrabajo+1;

            trabajos[indice] = auxTrabajo;

            altaExitosa = 1;
        }
    }
    return altaExitosa;
}

int buscarTrabajoLibre(eTrabajo lista[], int tam)
{
    int lLibre=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            lLibre=i;
            break;
        }
    }
    return lLibre;
}

int mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamS)
{
    int todoOk = 0;
    char nombreServicio[25];

    if(servicios != NULL && tamS > 0)
    {
        if(cargarDescripcionServicio(unTrabajo.idServicio, servicios, tamS, nombreServicio))
        {
            printf("%d    %d              %10s        %d/%d/%d", unTrabajo.id, unTrabajo.idBicicleta, nombreServicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    int bandera = 1;
    int todoOk = 0;

    if(trabajos!=NULL && servicios!= NULL && tamS > 0 && tamT > 0)
    {
        printf("**************lista trabajos***************");
        printf("id    id bicicleta    servicio    fecha");
        for(int i = 0; i < tamT; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], servicios, tamS);
                bandera = 0;
            }

        }
        if(bandera)
        {
            printf("\nno hay trabajos que mostrar\n\n");
            bandera = 0;
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarTrabajos(eTrabajo lista[], int tam)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}
