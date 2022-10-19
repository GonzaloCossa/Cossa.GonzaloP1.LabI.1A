#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id; // comienza en 5000
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED


/** \brief la funcion muestra los colores que existen en el sistema
 *
 * \param colores[] eColor Vector con los colores disponibles
 * \param tamC int Tamaño del vector de colores
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int listarColores(eColor colores[], int tamC);

/** \brief Valida que el id de un color ingresado exista
 *
 * \param colores[] eColor Vector con los colores disponibles
 * \param tamC int Tamaño del vector de colores
 * \param id int id del color ingresado
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int validarColor(eColor colores[], int tamC, int id);

/** \brief Se encarga de buscar en un vector de colores, el color desaado a traves de su id
 *
 * \param colores[] eColor Vector con los colores disponibles
 * \param tamC int Tamaño del vector de colores
 * \param id int id del color ingresado
 * \param pIndice int* Puntero a entero que devuelve el indice donde se encuentra el color ingresado
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int buscarColor(eColor colores[], int tamC, int id, int* pIndice);

/** \brief Se encagarga de mostras el nombre del color al momento de mostrar una o muchas bicicles, lee el id y muestra el nombre del color
 *
 * \param colores[] eColor Vector con los colores disponibles
 * \param tamC int Tamaño del vector de colores
 * \param id int id del color ingresado
 * \param descripcion[] char Vector de char donde se guarda el nombre del color obtenido
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int cargarDescripcionColor(eColor colores[], int tamC, int id, char descripcion[]);
