#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

} eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief muestra una estructura de tipo servicio
 *
 * \param unServicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio unServicio);

/** \brief mustra el vector de servicios en su totalidad en forma de lista
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return int deveulve 0 si hubo un error en la carga de los parametros y 1 si no hubo error
 *
 */
int mostrarServicios(eServicio servicios[], int tam);

/** \brief busca un servicio por su id en el vectro de servicios
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \return int devuelve el indice de la estructura de tipo servicio, en el vector de servicios, en el cual coincide el id cargado y -1 si no la encuentra
 *
 */
int buscarServicio(eServicio servicios[],int tam, int id);

/** \brief busca la descipcion del tipo por medio del id y lo carga en un vector de caracteres
 *
 * \param id int
 * \param servicios[] eServicio
 * \param tam int
 * \param desc[] char
 * \return int devuelve 0 si hubo un error en la carga de los parametros y 1 si no hubo erros
 *
 */
int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[]);
