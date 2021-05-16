#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    int todoOk = -1;

    for(int i = 0; i < len; i++)
    {
        list[i].isEmpty = 1;
        todoOk = 0;
    }

    return todoOk;
}

int addEmployee(Employee* list, int len, int* id, char name[],char
                lastName[],float salary,int sector)
{
    int indice;
    int todoOk = -1;

    if(list != NULL && len > 0 && id != NULL && name != NULL && lastName != NULL && salary > 0 && sector > 0)
    {

        indice = buscarLibre(list, len);


        if(indice != -1)
        {

            strcpy(list[indice].name, name);

            strcpy(list[indice].lastName, lastName);

            list[indice].salary = salary;

            list[indice].sector = sector;

            list[indice].isEmpty = 0;

            list[indice].id = *id;

            (*id)++;

            todoOk=0;
        }
        else
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int buscarLibre(Employee list[], int len)
{
    int lLibre=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            lLibre=i;
            break;
        }
    }
    return lLibre;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int indice = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && (list[i].isEmpty == 0))
            {
                indice=i;

                break;

            }
        }

    }
    return indice;
}

int removeEmployee(Employee* list, int len, int id)
{
    int lugarEmpleado;
    int bajaExitosa = -1;
    char confirmar;

    if(list != NULL && len > 0 && id > 0)
    {

        lugarEmpleado = findEmployeeById(list, len,id);

        if(lugarEmpleado != -1)
        {
            printf("el empleado seleccionado es:\n");
            printEmployee(list[lugarEmpleado]);
            printf("confirmar baja? s/n: ");
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
                list[lugarEmpleado].isEmpty = 1;
                bajaExitosa = 0;

            }
        }
    }
    return bajaExitosa;

}

int printEmployees(Employee* list, int length)
{
    int bandera = 1;

    printf("      lista de empleados\n");
    printf("id       name      last name      salary          sector\n\n");
    for(int i = 0; i < length; i++)
    {
        if(!list[i].isEmpty)
        {
            printEmployee(list[i]);
            bandera = 0;
        }

    }

    if(bandera)
    {
        printf("no hay empleados que mostrar\n\n");
    }
    return 0;
}

void printEmployee(Employee empleado)
{
    printf("%d    %10s  %10s       %9.2f        %d\n\n",empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);

}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleado;
    int todoOk = -1;

    if(list != NULL && len > 0 && order > 0)
    {
        if(order == 1)
        {
            for(int i=0; i<len-1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(list[i].sector > list[j].sector||(list[i].sector == list[j].sector &&strcasecmp(list[i].lastName, list[j].lastName)>0))
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }

            }
        }
        else
        {
            for(int i=0; i<len; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(list[i].sector< list[j].sector||(list[i].sector == list[j].sector &&strcasecmp(list[i].lastName, list[j].lastName)<0))
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }

            }
        }
        todoOk = 0;
    }
    return todoOk;
}

int modificarEmpleado(Employee lista[], int tam)
{
    int legajo;
    int lugarEmpleado;
    char confirmar;
    int modificacionExitosa = 0;
    char guardar = 'n';
    char opcion;
    Employee auxEmpleado;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("       modificar empleado\n\n");
        printEmployees(lista, tam);
        printf("\ningrese el id del empleado a modificar: ");
        scanf("%d", &legajo);
        printf("\n");

        lugarEmpleado = findEmployeeById(lista, tam, legajo);

        if(lugarEmpleado == -1)
        {
            printf("el empleado solicitado no existe\n");
        }
        else
        {
            printf("el empleado seleccionado es:\n");
            printEmployee(lista[lugarEmpleado]);
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
                    printf("2. modificar apellido\n");
                    printf("3. modificar sueldo\n");
                    printf("4. modificar sector\n");
                    printf("5. guardar y salir\n");
                    printf("6. cancelar cambios y salir\n");
                    printf("ingrese una opcion: ");
                    fflush(stdin);
                    scanf("%c", &opcion);

                    switch(opcion)
                    {
                    case '1':
                        printf("ingrese nombre: ");
                        fflush(stdin);
                        gets(auxEmpleado.name);
                        while(arrayLetras(auxEmpleado.name)==0)
                        {
                            printf("error, ingrese nombre: ");
                            fflush(stdin);
                            gets(auxEmpleado.name);
                        }

                        break;
                    case '2':
                        printf("ingrese apellido: ");
                        fflush(stdin);
                        gets(auxEmpleado.lastName);
                        while(arrayLetras(auxEmpleado.lastName)==0)
                        {
                            printf("error, ingrese apellido: ");
                            fflush(stdin);
                            gets(auxEmpleado.lastName);
                        }
                        break;
                    case '3':
                        printf("ingrese sueldo: ");
                        scanf("%f", &auxEmpleado.salary);
                        while(auxEmpleado.salary <= 0)
                        {
                            printf("ingrese sueldo: ");
                            scanf("%f", &auxEmpleado.salary);
                        }


                        break;
                    case '4':
                        printf("ingrese el id del sector: ");
                        scanf("%d", &auxEmpleado.sector);
                        while(auxEmpleado.sector < 0 || auxEmpleado.sector > 1000)
                        {
                            printf("error, ingrese el id del sector: ");
                            scanf("%d", &auxEmpleado.sector);
                        }
                        break;

                    case '5':

                        lista[lugarEmpleado] = auxEmpleado;

                        modificacionExitosa = 1;

                        guardar='s';
                        break;
                    case '6':
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

int arrayLetras(char array[])
{
    for(int i = 0; array[i] != '\0'; i++)
    {
        if((array[i] != ' ') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
        {
            return 0;
        }
    }
    return 1;
}

