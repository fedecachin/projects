#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

#endif // COLOR_H_INCLUDED

/** \brief muestra una sola estructura color
 *
 * \param UnColor eColor
 * \return void
 *
 */
void mostrarColor(eColor UnColor);

/** \brief muestra la totalidad de las estructuras color en el vector de colores
 *
 * \param colores[] eColor
 * \param tam int
 * \return int devuelve 0 si hubo un error en la carga de parametros y 1 si no hubo errores
 *
 */
int mostrarColores(eColor colores[], int tam);

/** \brief busca la descipcion del color por medio del id y lo carga en un vector de caracteres
 *
 * \param id int
 * \param colores[] eColor
 * \param tam int
 * \param desc[] char
 * \return int devuelve 0 si hubo un error en la carga de parametros y 1 si no hubo error
 *
 */
int cargarNombreColor(int id, eColor colores[], int tam, char desc[]);
