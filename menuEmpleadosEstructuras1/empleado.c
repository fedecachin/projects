#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "datawarehouse.h"
#include "sector.h"



void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int bandera = 1;
    printf("      lista de empleados\n");
    printf("legajo nombre edad sexo   sueldo     f.ingreso    sector\n");
    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarEmpleado(lista[i], sectores, tamSec);
            bandera = 0;
        }
        if(bandera)
        {
            printf("no hay empleados que mostrar");
        }
    }

}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam)
{
    char descripcion[20];
    if(cargarDescripcionSector(unEmpleado.idSector, sectores, tam, descripcion))
    {

        printf("%d  %10s  %d  %c  %9.2f  %02d/%02d/%d  %s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.edad, unEmpleado.sexo, unEmpleado.sueldo, unEmpleado.fIngreso.dia, unEmpleado.fIngreso.mes, unEmpleado.fIngreso.anio, descripcion);
    }
}



void ordenarEmpleados(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(lista[i].sexo < lista[j].sexo || (lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre, lista[j].nombre)> 0))
            {
                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo)
{
    int cantidad = 0;

    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pLegajo != NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i].legajo = *pLegajo;
            *pLegajo = *pLegajo + 1;

            strcpy(lista[i].nombre, nombres[i]);
            lista[i].edad = edades[i];
            lista[i].sueldo = sueldos[i];
            lista[i].sexo = sexos[i];
            lista[i].fIngreso = fechas[i];
            lista[i].idSector = idSectores[i];
            lista[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}

int buscarLibre(eEmpleado lista[], int tam)
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

int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    eEmpleado auxEmpleado;

    if(lista != NULL && tam > 0 && pLegajo != NULL)
    {
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("no hay lugar disponible");
        }
        else
        {
            printf("ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.nombre);

            printf("ingrese edad: ");
            scanf("%d", &auxEmpleado.edad);
            while(auxEmpleado.edad<18)
            {
                printf("error, ingrese edad: ");
                scanf("%d", &auxEmpleado.edad);
            }

            printf("ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &auxEmpleado.sexo);
            while(auxEmpleado.sexo != 'm' && auxEmpleado.sexo != 'f')
            {
                printf("error, ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &auxEmpleado.sexo);
            }

            printf("ingrese sueldo: ");
            scanf("%f", &auxEmpleado.sueldo);

            printf("ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxEmpleado.fIngreso.dia, &auxEmpleado.fIngreso.mes, &auxEmpleado.fIngreso.anio);
            while((auxEmpleado.fIngreso.dia < 1 || auxEmpleado.fIngreso.dia > 31) && (auxEmpleado.fIngreso.mes < 1 || auxEmpleado.fIngreso.mes > 12) && (auxEmpleado.fIngreso.anio < 1970 || auxEmpleado.fIngreso.anio > 2021))
            {
                printf("ingrese fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &auxEmpleado.fIngreso.dia, &auxEmpleado.fIngreso.mes, &auxEmpleado.fIngreso.anio);
            }

            mostrarSectores(sectores, tamSec);

            printf("ingrese el id del sector: ");
            scanf("%d", &auxEmpleado.idSector);

            auxEmpleado.isEmpty = 0;

            auxEmpleado.legajo = *pLegajo;
            *pLegajo=*pLegajo+1;

            lista[indice] = auxEmpleado;

            todoOk = 1;
        }

    }
    return todoOk;

}

int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int indice = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].legajo == legajo && (lista[i].isEmpty == 0))
            {
                indice=i;

                break;

            }
        }

    }
    return indice;
}

int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int legajo;
    int lugarEmpleado;
    char confirmar;
    int bajaExitosa = 0;

    system("cls");
    printf("       baja empleado\n\n");
    mostrarEmpleados(lista, tam, sectores, tamSec);
    printf("\ningrese el legajo del empleado a dar de baja: ");
    scanf("%d", &legajo);
    printf("\n");

    lugarEmpleado = buscarEmpleado(lista, tam, legajo);

    if(lugarEmpleado == -1)
    {
        printf("el empleado solicitado no existe\n");
    }
    else
    {
        printf("el empleado seleccionado es:\n");
        mostrarEmpleado(lista[lugarEmpleado], sectores, tamSec);
        printf("quiere dar de baja a este empleado? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmar);
        while(confirmar != 's' && confirmar != 'n')
        {
            printf("opcion invalida, quiere dar de baja a este empleado? s/n: ");
            fflush(stdin);
            scanf("%c", &confirmar);
        }

        if(confirmar == 's')
        {
            lista[lugarEmpleado].isEmpty = 1;
            bajaExitosa = 1;

        }
        else
        {
            printf("baja cancelada");
        }

    }
    return bajaExitosa;

}

int modificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int legajo;
    int lugarEmpleado;
    char confirmar;
    int modificacionExitosa = 0;
    char guardar = 'n';
    char opcion;
    eEmpleado auxEmpleado;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("       modificar empleado\n\n");
        mostrarEmpleados(lista, tam, sectores, tamSec);
        printf("\ningrese el legajo del empleado a modificar: ");
        scanf("%d", &legajo);
        printf("\n");

        lugarEmpleado = buscarEmpleado(lista, tam, legajo);

        if(lugarEmpleado == -1)
        {
            printf("el empleado solicitado no existe\n");
        }
        else
        {
            printf("el empleado seleccionado es:\n");
            mostrarEmpleado(lista[lugarEmpleado], sectores, tamSec);
            printf("quiere modificar a este empleado? s/n: ");
            fflush(stdin);
            scanf("%c", &confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                printf("opcion invalida, quiere modificar a este empleado? s/n: ");
                fflush(stdin);
                scanf("%c", &confirmar);
            }

            auxEmpleado = lista[lugarEmpleado];

            if(confirmar == 's')
            {
                do
                {
                    system("cls");
                    printf("  ****MODIFICACION EMPLEADO****\n\n");
                    printf("1. modificar nombre\n");
                    printf("2. modificar edad\n");
                    printf("3. modificar sexo\n");
                    printf("4. modificar sueldo\n");
                    printf("5. modificar fecha de engreso\n");
                    printf("6. guardar y salir\n");
                    printf("7. cancelar cambios y salir\n");
                    printf("ingrese una opcion: ");
                    fflush(stdin);
                    scanf("%c", &opcion);

                    switch(opcion)
                    {
                    case '1':
                        printf("ingrese nombre: ");
                        fflush(stdin);
                        gets(auxEmpleado.nombre);

                        break;
                    case '2':
                        printf("ingrese edad: ");
                        scanf("%d", &auxEmpleado.edad);
                        while(auxEmpleado.edad<18)
                        {
                            printf("error, ingrese edad: ");
                            scanf("%d", &auxEmpleado.edad);
                        }
                        break;
                    case '3':
                        printf("ingrese sexo: ");
                        fflush(stdin);
                        scanf("%c", &auxEmpleado.sexo);
                        while(auxEmpleado.sexo != 'm' && auxEmpleado.sexo != 'f')
                        {
                            printf("error, ingrese sexo: ");
                            fflush(stdin);
                            scanf("%c", &auxEmpleado.sexo);
                        }

                        break;
                    case '4':
                        printf("ingrese sueldo: ");
                        scanf("%f", &auxEmpleado.sueldo);
                        break;
                    case '5':
                        printf("ingrese fecha dd/mm/aaaa: ");
                        scanf("%d/%d/%d", &auxEmpleado.fIngreso.dia, &auxEmpleado.fIngreso.mes, &auxEmpleado.fIngreso.anio);
                        while((auxEmpleado.fIngreso.dia < 1 || auxEmpleado.fIngreso.dia > 31) && (auxEmpleado.fIngreso.mes < 1 || auxEmpleado.fIngreso.mes > 12) && (auxEmpleado.fIngreso.anio < 1970 || auxEmpleado.fIngreso.anio > 2021))
                        {
                            printf("ingrese fecha dd/mm/aaaa: ");
                            scanf("%d/%d/%d", &auxEmpleado.fIngreso.dia, &auxEmpleado.fIngreso.mes, &auxEmpleado.fIngreso.anio);
                        }
                        break;
                    case '6':

                        lista[lugarEmpleado] = auxEmpleado;

                        modificacionExitosa = 1;

                        guardar='s';
                        break;
                    case '7':
                        guardar='s';
                        break;
                    }
                }
                while(guardar=='n');
            }
            else
            {
                printf("modificacion cancelada");
            }

        }
    }
    return modificacionExitosa;
}

int cargarNombreEmpleado(int legajo, eEmpleado lista[], int tam, char nombre[])
{
    int todoOk = 0;
    int indice;

    if( lista != NULL && tam > 0 && nombre != NULL)
    {
        indice = buscarEmpleado(lista, tam, legajo);
        if(indice != -1)
        {
            strcpy(nombre, lista[indice].nombre);
            todoOk = 1;
        }

    }
    return todoOk;
}

