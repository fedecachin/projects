#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief valida que la cadena ingresada sea solo de caracteres
 *
 * \param array[] char
 * \return int devuleve 0 si no es solo de caracteres y 1 si es solo de caracteres
 *
 */
int arrayValidacionLetras(char array[]);

/** \brief valida que el id del tipo ingresado sea valido
 *
 * \param tipo int
 * \return int devuelve 0 sino conincide y 1 s si lo hace
 *
 */
int validarTipo(int tipo);

/** \brief valida que el id del tipo ingresado sea valido
 *
 * \param color int
 * \return int devuelve 0 sino conincide y 1 s si lo hace
 *
 */
int validarColor(int color);

/** \brief valida que el numero del rodado ingresado sea valido
 *
 * \param rodado float
 * \return int devuelve 0 sino conincide y 1 s si lo hace
 *
 */
int validarRodado(float rodado);
