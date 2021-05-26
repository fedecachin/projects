#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

#endif // TIPO_H_INCLUDED


/** \brief mustra el vector de tipos en su totalidad en forma de lista
 *
 * \param tipos[] eTipo
 * \param tam int
 * \return int deveulve 0 si hubo un error en la carga de los parametros y 1 si no hubo error
 *
 */
int mostrarTipos(eTipo tipos[], int tam);

/** \brief muestra una estructura de tipo tipo
 *
 * \param Untipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo Untipo);

/** \brief busca la descipcion del tipo por medio del id y lo carga en un vector de caracteres
 *
 * \param id int
 * \param tipos[] eTipo
 * \param tam int
 * \param desc[] char
 * \return int devuelve 0 si hubo un error en la carga de los parametros y 1 si no hubo erros
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]);
