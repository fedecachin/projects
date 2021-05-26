#include "fecha.h"
#include "bicicletar.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief  busca, en el vector de trabajos, el primer lugar donde el campo isEmpty sea igual a 1
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \return int devuelve el indice del primer lugar libre encontrado y -1 si no encuentra ningun lugar libre en el vector
 *
 */
int buscarTrabajoLibre(eTrabajo lista[], int tam);

/** \brief permite dar de alta a un trabajo
 *
 * \param trabajos[] eTrabajo
 * \param tamTr int
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \param idTrabajo int*
 * \return int devuelve 0 si hubo un error en la carga de los parametros, 1 si se logro el alta con exito y 2 si no hay espacio disponible en el vector de trabajos
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamTr, eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT, eServicio servicios[], int tamS, int* idTrabajo);

/** \brief muestra un trabajo del vector de trabajos
 *
 * \param unTrabajo eTrabajo
 * \param servicios[] eServicio
 * \param tamS int
 * \return int devuelve 0 si hubo un error en la carga de los parametros y 1 si no hubo errores
 *
 */
int mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamS);

/** \brief muestra al usuario el vector de trabajos en su totalidad, en forma de lista
 *
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return int devuelve 0 si hubo un error en la carga de los parametros y 1 si no hubo errores
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);

/** \brief inicia el campo isEmpty, del vector de trabajos, en 1
 *
 * \param lista[] eTrabajo
 * \param tam int
 * \return int devuelve 0 si hubo un error en la carga de parametros y 1 si no hubo errores
 *
 */
int inicializarTrabajos(eTrabajo lista[], int tam);
