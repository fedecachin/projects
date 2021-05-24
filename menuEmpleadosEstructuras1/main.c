#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"

#define TAM 10
#define TAMSEC 5
#define TAMC 5
#define TAMA 10

int main()
{
    int nextLegajo = 20000;
    int nextIdAlmuerzo = 50000;

    eEmpleado nomina[TAM];

    eSector sectores[TAMSEC] =
    {
        {500, "sistemas"},
        {501, "legales"},
        {502, "RRHH"},
        {503, "contable"},
        {504, "ventas"},
    };

    eComida comidas[TAMC] =
    {
        {1000, "milanesa", 150},
        {1001, "ensalada", 190},
        {1002, "fideos", 140},
        {1003, "pizza", 120},
        {1004, "sopa", 110},
    };

    eAlmuerzo almuerzos[TAMA];

    int opcion;
    char salir = 'n';

    inicializarEmpleados(nomina, TAM);

    hardcodearEmpleados(nomina, TAM, 10, &nextLegajo);

    do
    {
        system("cls");
        printf("  ****ABM empleados****\n\n");
        printf("1. alta empleado\n");
        printf("2. baja empleado\n");
        printf("3. modificar empleado\n");
        printf("4. lista empleados\n");
        printf("5. ordenar empleados\n");
        printf("6. listar sectores\n");
        printf("7. listar comidas\n");
        printf("8. listar almuerzos\n");
        printf("9. alta almuerzo\n");
        printf("10. -----------------\n");
        printf("11. informes\n");
        printf("12. filtrar empleados sector\n");
        printf("13. mostrar empleados de todos los sectores\n");
        printf("14. total sueldo de un sector\n");
        printf("15. total a depositar\n");
        printf("16. sectores que mas cuestan\n");
        printf("20. salir\n");
        printf("ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(altaEmpleado(nomina, TAM, sectores, TAMSEC, &nextLegajo))
            {
                printf("alta empleado exitosa!");
            }
            else
            {
                printf("hubo un problema al realizar la alta");
            }
            break;
        case 2:
            if(bajaEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("baja exitosa");
            }
            else
            {
                printf("no se realizo la baja");
            }

            break;
        case 3:
            if(modificarEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("\nmodificaciones exitosas");
            }
            else
            {
                printf("\nno se realizo ninguna modificacion\n");
            }
            break;
        case 4:
            system("cls");
            mostrarEmpleados(nomina, TAM, sectores, TAMSEC);
            break;
        case 5:
            system("cls");
            printf("ordenar empleados\n");
            break;
        case 6:
            mostrarSectores(sectores, TAMSEC);
            break;
        case 7:
            mostrarComidas(comidas, TAMC);
            break;
        case 11:
            printf("informes\n");
            break;
        case 12:
            listarEmpleadosSector(nomina, TAM, sectores, TAMSEC);
            break;
        case 13:
            listarEmpleadosAllSectors(nomina, TAM, sectores, TAMSEC);
            break;
        case 14:
            totalSueldosSector(nomina, TAM, sectores, TAMSEC);
            break;
        case 15:
            totalADepositar(nomina, TAM, sectores, TAMSEC);
            break;
        case 16:
            sectorMasCaro(nomina, TAM, sectores, TAMSEC);
            break;
        case 20:
            salir='s';
            break;
        }
        system("pause");
    }
    while(salir=='n');
    return 0;
}









