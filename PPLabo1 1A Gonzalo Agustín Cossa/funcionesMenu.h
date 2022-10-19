#ifndef FUNCIONESMENU_H_INCLUDED
#define FUNCIONESMENU_H_INCLUDED

/** \brief Se encarga de mostrar el menu principal
 *
 * \return int retorna la opcion ingresada
 *
 */
int menu();

/** \brief Se encarga de preguntar si se desea salir del programa
 *
 * \param pVariable char* puntero a la variable de control principal del menu del programa
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int confirmarSalir(char* pVariable);

/** \brief se encarga de mostrar el menu de modificar bicicleta
 *
 * \return char retorna la opcion elegida por el usuario
 *
 */
char menuModificar();

#endif // FUNCIONESMENU_H_INCLUDED
