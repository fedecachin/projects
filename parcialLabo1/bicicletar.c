#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicletar.h"
#include "tipo.h"
#include "color.h"
#include "validaciones.h"

int inicializarBicicletas(eBicicleta lista[], int tam)
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

int buscarLibre(eBicicleta lista[], int tam)
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

int altaBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC, int* idBicicleta)
{
    int todoOk = 0;
    int indice;
    eBicicleta auxBicicleta;

    if(bicicletas != NULL && tamB > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && idBicicleta != NULL)
    {
        indice = buscarLibre(bicicletas, tamB);

        if(indice == -1)
        {
            todoOk = 2;
        }
        else
        {
            printf("ingrese marca: ");
            fflush(stdin);
            gets(auxBicicleta.marca);
            while(!arrayValidacionLetras(auxBicicleta.marca))
            {
                printf("invalido, ingrese marca: ");
                fflush(stdin);
                gets(auxBicicleta.marca);
            }

            mostrarTipos(tipos,tamT);

            printf("\n ingrese el id del tipo: ");
            scanf("%d", &auxBicicleta.idTipo);
            while(!validarTipo(auxBicicleta.idTipo))
            {
                printf("\n invalido,ingrese el id del tipo: ");
                scanf("%d", &auxBicicleta.idTipo);
            }

            mostrarColores(colores, tamC);

            printf("\n ingrese el id del color: ");
            scanf("%d", &auxBicicleta.idColor);
            while(!validarColor(auxBicicleta.idColor))
            {
                printf("\n invalido,ingrese el id del color: ");
                scanf("%d", &auxBicicleta.idColor);
            }

            printf("\n ingrese el rodado: ");
            scanf("%f", &auxBicicleta.rodado);
            while(!validarRodado(auxBicicleta.rodado))
            {
                printf("\n invalido, ingrese el rodado: ");
                scanf("%f", &auxBicicleta.rodado);
            }

            auxBicicleta.isEmpty = 0;

            auxBicicleta.id = *idBicicleta;
            *idBicicleta=*idBicicleta+1;

            bicicletas[indice] = auxBicicleta;

            todoOk = 1;

        }
    }

    return todoOk;

}

int mostrarBicicleta(eBicicleta unaBicicleta, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    char descripcionTipo[20];
    char nombreColor[20];
    int todoOk = 0;
    if(cargarDescripcionTipo(unaBicicleta.idTipo, tipos, tamT, descripcionTipo) && cargarNombreColor(unaBicicleta.idColor, colores, tamC, nombreColor))
    {

        printf("%d  %10s  %10s  %10s  %.2f\n", unaBicicleta.id, unaBicicleta.marca, descripcionTipo, nombreColor, unaBicicleta.rodado);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarBicicletas(eBicicleta Bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int bandera = 1;
    int todoOk = 0;

    if(Bicicletas!=NULL&& colores!= NULL&& tipos != NULL&& tamB > 0 && tamC > 0 && tamT > 0)
    {
        printf("      lista de bicicletas\n");
        printf("  id   marca  tipo  color  rodado\n");
        for(int i = 0; i < tamB; i++)
        {
            if(!Bicicletas[i].isEmpty)
            {
                mostrarBicicleta(Bicicletas[i], colores, tamC, tipos, tamT);
                bandera = 0;
            }
            if(bandera)
            {
                printf("no hay almuerzos que mostrar\n");
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaBicicletas(eBicicleta Bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int id;
    int lugarBicicleta;
    char confirmar;
    int bajaExitosa = 0;
    if(Bicicletas != NULL && tamB > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        printf("       baja bicicleta\n\n");
        mostrarBicicletas(Bicicletas, tamB, colores, tamC, tipos, tamT);
        printf("\ningrese el id de la bicicleta a dar de baja: ");
        scanf("%d", &id);
        printf("\n");

        lugarBicicleta = buscarBicicleta(Bicicletas, tamB, id);

        if(lugarBicicleta == -1)
        {
            printf("la bicicleta solicitada no esta en sistema\n");
        }
        else
        {
            printf("la bicicleta seleccionada es:\n");
            mostrarBicicleta(Bicicletas[lugarBicicleta],colores, tamC, tipos, tamT);
            printf("quiere dar de baja esta bicicleta? s/n: ");
            fflush(stdin);
            scanf("%c", &confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                printf("opcion invalida, quiere dar de baja a esta bicicleta? s/n: ");
                fflush(stdin);
                scanf("%c", &confirmar);
            }

            if(confirmar == 's')
            {
                Bicicletas[lugarBicicleta].isEmpty = 1;
                bajaExitosa = 1;

            }
        }
    }
    return bajaExitosa;
}

int buscarBicicleta(eBicicleta bicicletas[],int tam, int id)
{
    int indice = -1;

    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].id == id && (bicicletas[i].isEmpty == 0))
            {
                indice=i;

                break;

            }
        }

    }
    return indice;
}

int modificarBicicleta(eBicicleta Bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int id;
    int lugarBicicleta;
    char confirmar;
    int modificacionExitosa = 0;
    char guardar = 'n';
    char opcion;
    eBicicleta auxBicicleta;

    if(Bicicletas != NULL && tamB > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
    {

        system("cls");
        printf("       modificar bicicleta\n\n");
        mostrarBicicletas(Bicicletas, tamB, colores, tamC, tipos, tamT);
        printf("\ningrese el id de la bicicleta a modificar: ");
        scanf("%d", &id);
        printf("\n");

        lugarBicicleta = buscarBicicleta(Bicicletas, tamB, id);

        if(lugarBicicleta == -1)
        {
            printf("la bicicleta solicitada no se encuentra en sistema\n");
        }
        else
        {
            printf("la bicicleta seleccionada es:\n");
            mostrarBicicleta(Bicicletas[lugarBicicleta], colores, tamC, tipos, tamT);
            printf("quiere modificar esta bicicleta? s/n: ");
            fflush(stdin);
            scanf("%c", &confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                printf("opcion invalida, quiere modificar esta bicicleta? s/n: ");
                fflush(stdin);
                scanf("%c", &confirmar);
            }

            auxBicicleta = Bicicletas[lugarBicicleta];

            if(confirmar == 's')
            {
                do
                {
                    system("cls");
                    printf("  ****MODIFICACION BICICLETA****\n\n");
                    printf("1. modificar marca\n");
                    printf("2. modificar id tipo\n");
                    printf("3. modificar id color\n");
                    printf("4. modificar rodado\n");
                    printf("5. guardar y salir\n");
                    printf("6. cancelar cambios y salir\n");
                    printf("ingrese una opcion: ");
                    fflush(stdin);
                    scanf("%c", &opcion);

                    switch(opcion)
                    {
                    case '1':
                        printf("ingrese marca: ");
                        fflush(stdin);
                        gets(auxBicicleta.marca);
                        while(!arrayValidacionLetras(auxBicicleta.marca))
                        {
                            printf("invalido, ingrese marca: ");
                            fflush(stdin);
                            gets(auxBicicleta.marca);
                        }
                        break;
                    case '2':
                        mostrarTipos(tipos,tamT);

                        printf("\n ingrese el id del tipo: ");
                        scanf("%d", &auxBicicleta.idTipo);
                        while(!validarTipo(auxBicicleta.idTipo))
                        {
                            printf("\n invalido,ingrese el id del tipo: ");
                            scanf("%d", &auxBicicleta.idTipo);
                        }

                        break;
                    case '3':
                        mostrarColores(colores, tamC);

                        printf("\n ingrese el id del color: ");
                        scanf("%d", &auxBicicleta.idColor);
                        while(!validarColor(auxBicicleta.idColor))
                        {
                            printf("\n invalido,ingrese el id del color: ");
                            scanf("%d", &auxBicicleta.idColor);
                        }

                        break;
                    case '4':
                        printf("\n ingrese el rodado: ");
                        scanf("%f", &auxBicicleta.rodado);
                        while(!validarRodado(auxBicicleta.rodado))
                        {
                            printf("\n invalido, ingrese el rodado: ");
                            scanf("%f", &auxBicicleta.rodado);
                        }
                        break;

                    case '5':

                            Bicicletas[lugarBicicleta] = auxBicicleta;

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
        }
    }
    return modificacionExitosa;
}
