#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

void listarEmpleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int sectorElejido;
    int bandera;

    mostrarSectores(sectores, tamSec);
    printf("elija id del sector a mostrar: ");
    scanf("%d", &sectorElejido);
    while(!validarIdSector(sectorElejido,sectores,tamSec))
    {
        printf("error, elija id del sector a mostrar: ");
        scanf("%d", &sectorElejido);
    }

    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0 && sectorElejido == lista[i].idSector)
        {
            mostrarEmpleado(lista[i], sectores, tamSec);
            bandera = 1;
        }
        if(bandera == 0)
        {
            printf("no se encotro a ningun empleado en el sector");
        }
    }
}

void listarEmpleadosAllSectors(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int idSector;
    char sectorDescripcion[20];
    int bandera;

    if(lista != NULL && tam > 0 && sectores != NULL && tamSec > 0)
    {
        system("cls");

        for(int i = 0; i < tamSec; i++)
        {

            idSector = sectores[i].id;
            strcpy(sectorDescripcion, sectores[i].descripcion);
            printf("\n******************* sector %s ************************\n", sectorDescripcion);
            bandera = 1;

            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idSector == idSector)
                {
                    mostrarEmpleado(lista[j], sectores, tamSec);
                    bandera = 0;
                }
            }
            if(bandera)
            {
                printf("no hay empleados en este sector\n");
            }
        }
    }
}

void totalSueldosSector(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
        int sectorElejido;
        float totalSueldos = 0;


    if(lista != NULL && tam > 0 && sectores != NULL && tamSec > 0)
    {
        system("cls");
        printf("     total sueldo sector\n");
        mostrarSectores(sectores, tamSec);
        printf("elija id del sector a mostrar: ");
        scanf("%d", &sectorElejido);
        while(!validarIdSector(sectorElejido,sectores,tamSec))
        {
            printf("error, elija id del sector a mostrar: ");
            scanf("%d", &sectorElejido);
        }

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && sectorElejido == lista[i].idSector)
            {
                totalSueldos += lista[i].sueldo;
            }
        }

        printf("total sueldo: $ %.2f\n\n", totalSueldos);


    }
}

void totalADepositar(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    float totalSector = 0;
    float totalGeneral = 0;

    if(lista != NULL && tam > 0 && sectores != NULL && tamSec > 0)
    {
        system("cls");

        for(int i = 0; i < tamSec; i++)
        {
            printf("\n******************* sector %s ************************\n", sectores[i].descripcion);

            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idSector == sectores[i].id)
                {
                    totalSector += lista[j].sueldo;
                }
            }
            totalGeneral += totalSector;
            printf("total sueldo: $ %.2f\n\n", totalSector);
        }
        printf("--------------------------------------------------\n");
        printf("total a depositar: $ %.2f\n\n", totalGeneral);
    }
}

void sectorMasCaro(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    float totalSector = 0;
    float totales[tamSec];
    float mayor;
    int bandera = 0;

    if(lista != NULL && tam > 0 && sectores != NULL && tamSec > 0)
    {
        system("cls");

        printf("********sectores que mas cuestan**********\n");

        for(int i = 0; i < tamSec; i++)
        {

            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idSector == sectores[i].id)
                {
                    totalSector += lista[j].sueldo;
                }
            }
            totales[i] = totalSector;
        }
        for (int i = 0; i < tamSec; i++)
        {
            if(bandera == 0 || totales[i] > mayor)
            {
                mayor = totales[i];
                bandera = 1;
            }
        }

        for(int i = 0; i < tamSec; i++)
        {
            if(mayor == totales[i])
            {
                printf("%s\n\n", sectores[i].descripcion);
            }
        }

    }
}
