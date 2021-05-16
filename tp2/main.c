#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 1000

int menu();



int main()
{
    char salir = 'n';
    Employee nomina[TAM];
    Employee auxiliarEmpleado;
    int idEmpleado = 1;
    int idEmpleadoBaja;
    int altaExitosa;
    int orden;
    int banderaAlta = 0;

    initEmployees(nomina, TAM);

    do
    {
        switch(menu())
        {
        case 1:

            printf("ingrese nombre: ");
            fflush(stdin);
            gets(auxiliarEmpleado.name);
            while(arrayLetras(auxiliarEmpleado.name)==0)
            {
                printf("error, ingrese nombre: ");
                fflush(stdin);
                gets(auxiliarEmpleado.name);
            }

            printf("ingrese apellido: ");
            fflush(stdin);
            gets(auxiliarEmpleado.lastName);
            while(arrayLetras(auxiliarEmpleado.lastName)==0)
            {
                printf("error, ingrese apellido: ");
                fflush(stdin);
                gets(auxiliarEmpleado.lastName);
            }


            printf("ingrese sueldo: ");
            scanf("%f", &auxiliarEmpleado.salary);
            while(auxiliarEmpleado.salary <= 0)
            {
                printf("ingrese sueldo: ");
                scanf("%f", &auxiliarEmpleado.salary);
            }

            printf("ingrese el id del sector: ");
            scanf("%d", &auxiliarEmpleado.sector);
            while(auxiliarEmpleado.sector < 0 || auxiliarEmpleado.sector > 1000)
            {
                printf("error, ingrese el id del sector: ");
                scanf("%d", &auxiliarEmpleado.sector);
            }

            altaExitosa = addEmployee(nomina, TAM, &idEmpleado, auxiliarEmpleado.name, auxiliarEmpleado.lastName, auxiliarEmpleado.salary, auxiliarEmpleado.sector);

            if(altaExitosa == -1)
            {
                printf("se produjo un error o no hay espacio libre\n");
            }
            else
            {
                printf("empleado dado de alta con exito\n");
            }

            banderaAlta = 1;

            break;
        case 2:
            if(banderaAlta == 1)
            {

                if(modificarEmpleado(nomina, TAM))
                {
                    printf("\nmodificaciones exitosas\n");
                }
                else
                {
                    printf("\nno se realizo ninguna modificacion\n");
                }
            }
            else
            {
                printf("no se ingreso ningun empleado");
            }
            break;

            break;
        case 3:
            if(banderaAlta == 1)
            {
                system("cls");
                printEmployees(nomina, TAM);
                printf("\ningrese el id del empleado a dar de baja: ");
                scanf("%d", &idEmpleadoBaja);
                if(removeEmployee(nomina, TAM, idEmpleadoBaja) == -1)
                {
                    printf("se produjo un error, no se encontro al empleado\n");
                }
                else
                {
                    printf("baja dada con exito\n");
                }
            }
            else
            {
                printf("no se ingreso ningun empleado");
            }

            break;
        case 4:
            printf("desea mostrar los empleados de forma:\n");
            printf("1. descendente\n");
            printf("2. ascendente\n");
            printf("ingrese una opcion: ");
            scanf("%d", &orden);
            while(orden <1 || orden > 2)
            {
                printf("error, opcion no valida, ingrese una opcion valida: ");
                scanf("%d", &orden);
            }

            sortEmployees(nomina, TAM, orden);

            printEmployees(nomina, TAM);

            break;

        case 5:
            salir = 's';
            break;
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("  ****ABM empleados****\n\n");
    printf("1. altas\n");
    printf("2. modificar\n");
    printf("3. baja\n");
    printf("4. informar\n");
    printf("5. salir\n\n");
    printf("ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


