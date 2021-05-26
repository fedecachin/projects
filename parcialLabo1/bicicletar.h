#include "tipo.h"
#include "color.h"
#ifndef BICICLETAR_H_INCLUDED
#define BICICLETAR_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;


} eBicicleta;

#endif // BICICLETAR_H_INCLUDED

/** \brief permite dar de alta una bicicleta
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipos[] eTipo
 * \param tamT int
 * \param colores[] eColor
 * \param tamC int
 * \param idBicicleta int*
 * \return int devuelve 0 si hubo un error en la carga de los parametros, 1 si se logro el alta con exito y 2 si no hay espacio disponible en el vector de bicicletas
 *
 */
int altaBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC, int* idBicicleta);

/** \brief inicia el campo isEmpty, del vector de bicicletas, en 1
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \return int devuelve 0 si hubo un error en la carga de parametros y 1 si no hubo errores
 *
 */
int inicializarBicicletas(eBicicleta lista[], int tam);

/** \brief muestra una bicicleta del vector de bicicletas
 *
 * \param unaBicicleta eBicicleta
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int devuelve 0 si hubo un error en la carga de los parametros y 1 si no hubo errores
 *
 */
int mostrarBicicleta(eBicicleta unaBicicleta, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief muestra al usuario el vector de bicicletas en su totalidad, en forma de lista
 *
 * \param unaBicicleta eBicicleta
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int devuelve 0 si hubo un error en la carga de los parametros y 1 si no hubo errores
 *
 */
int mostrarBicicletas(eBicicleta Bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief da de baja, de forma logica, una bicicleta en el vector de bicicletas
 *
 * \param Bicicletas[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int devuelve 0 si hubo un error en la carga de los parametros o si se cancela la baja y 1 si se logra la baja con exito
 *
 */
int bajaBicicletas(eBicicleta Bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief busca el lugar en el vector de bicicletas donde se encuntra la bicicleta con el id ingresado
 *
 * \param bicicletas[] eBicicleta
 * \param tam int
 * \param id int
 * \return int devuelve el indice en el vector de bicicletas donde se encuntra la solicitada
 *
 */
int buscarBicicleta(eBicicleta bicicletas[],int tam, int id);

/** \brief permite modificar los datos, que el ususario quiera, de una bicicleta en el vector de bicicletas
 *
 * \param Bicicletas[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int devuelve 0 si hubo un error en la carga de parametros, si no se encuentra la bicicleta seleccionada para modificar o si se cancelan las modificaciones y 1 si se realizo las modificaciones con exito
 *
 */
int modificarBicicleta(eBicicleta Bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

int ordenarBicicletas(eBicicleta bicicletas[], int tam);

/** \brief busca, en el vector de bicicletas, el primer lugar donde el campo isEmpty sea igual a 1
 *
 * \param lista[] eBicicleta
 * \param tam int
 * \return int devuelve el indice del primer lugar libre encontrado y -1 si no encuentra ningun lugar libre en el vector
 *
 */
int buscarLibre(eBicicleta lista[], int tam);
