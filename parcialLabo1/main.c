#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "bicicletar.h"
#include "servicio.h"
#include "trabajo.h"
#include "menu.h"
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMB 5
#define TAMTR 5


int main()
{
    eTipo tipos[TAMT] = {{1000, "rutera"}, {1001, "carrera"}, {1002, "mountaint"}, {1003, "bmx"} };
    eColor colores[TAMC] = {{5000, "gris"}, {5001, "negro"}, {5002, "blanco"}, {5003, "azul"}, {5004, "rojo"} };
    eServicio servicios[TAMS] = {{20000, "limpieza", 250}, {20001, "parche", 300}, {20002, "centrado", 400}, {20003, "cadena", 350} };
    eBicicleta listaB[TAMB];
    eTrabajo trabajos[TAMTR];

    char salir = 'n';
    int NextIdBicicleta = 50000;
    int nextIdTrabajo = 100;
    int altaBici;
    int altaTra;
    int contadorBicis = 0;
    int contadorTrabajos = 0;

    inicializarBicicletas(listaB, TAMB);
    inicializarTrabajos(trabajos, TAMTR);

    do
    {
        switch(menu())
        {
        case 1:
            altaBici = altaBicicleta(listaB, TAMB, tipos, TAMT, colores, TAMC, &NextIdBicicleta);
            if(altaBici==1)
            {
                printf("alta dada con exito\n");
                contadorBicis++;
            }
            else if(altaBici == 0)
            {
                printf("se produjo un error\n");
            }
            else if (altaBici == 2)
            {
                printf("no hay lugar disponible\n");
            }
            break;
        case 2:
            if(modificarBicicleta(listaB, TAMB, colores, TAMC, tipos, TAMT))
            {
                printf("modificacion efectuada con exito");
            }
            else
            {
                printf("no se efectuo la modificacion");
            }
            break;
        case 3:
            if(contadorBicis > 0)
            {
                if(bajaBicicletas(listaB, TAMB, colores, TAMC, tipos, TAMT))
                {
                    printf("baja exitosa\n");
                    contadorBicis--;
                }
                else
                {
                    printf("baja no efectuada\n");
                }
            }
            break;
        case 4:
            if(contadorBicis > 0)
            {
                ordenarBicicletas(listaB, TAMB);
                mostrarBicicletas(listaB, TAMB, colores, TAMC, tipos, TAMT);
            }
            break;
        case 5:
            mostrarTipos(tipos, TAMT);
            break;
        case 6:
            mostrarColores(colores, TAMC);
            break;
        case 7:
            mostrarServicios(servicios, TAMS);
            break;
        case 8:
            altaTra = altaTrabajo(trabajos, TAMTR, listaB, TAMB, colores, TAMC, tipos, TAMT, servicios, TAMS, &nextIdTrabajo);
            if(altaTra == 1)
            {
                printf("alta exitosa\n");
                contadorTrabajos++;
            }
            else if(altaTra == 0)
            {
                printf("se produjo un error en el alta\n");
            }
            else if(altaTra == 2)
            {
                printf("no hay lugar disponible\n");
            }
            break;
        case 9:
            if(contadorTrabajos>0)
            {
                mostrarTrabajos(trabajos, TAMTR, servicios, TAMS);
            }

            break;
        case 10:
            salir = 's';
            break;
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}
