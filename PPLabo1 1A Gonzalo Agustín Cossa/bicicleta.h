#include "color.h"
#include "tipo.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material; // 'c' || 'a'
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

//INICIALIZAR
/** \brief Cambia el isempty a 1
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int Tamaño del vector de bicicletas
 * \return int 1 todoOk 0 !todoOk
 *
 */
int inicializarBicicletas(eBicicleta bicicletas[], int tamB);

/** \brief Se encarga de cargar datos predeterminados a un vector de bicicletas
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int Tamaño del vector de bicicletas
 * \param cantidad int cantidad de bicicletas que desea hardcodear
 * \param pId int* puntero al al id autoincremental de las bicicletas
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int hardcodearBicicletas(eBicicleta bicicletas[], int tamB, int cantidad, int* pId);


/** \brief Ordena un vector de eBicicletas dependiendo del tipo y el material
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int Tamaño del vector de bicicletas
 * \param tipos[] eTipo vector de los distintos tipos disponibles de bicicletas
 * \param tamT int tamaño del vector de los tipos
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int ordenarBiciletasPorTipoYMaterial(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT);

// BUSQUEDA DE BICICLETAS

/** \brief Buscar en un vector, una bicicleta con isEmpty = 1
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int Tamaño del vector de bicicletas
 * \param pIndice int* Puntero al indice del vector de bicicletas donde se encuentra un espacio libre
* \return int retorna 1 todoOk 0 !todoOk
 *
 */
int buscarBicicletaLibre(eBicicleta bicicletas[], int tamB, int* pIndice);

/** \brief Muestra una lista con las bicicletas en el sistema
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int Tamaño del vector de bicicletas
 * \param colores[] eColor vector de los distintos colores
 * \param tamC int tamaño del vector de los colores
 * \param tipos[] eTipo vector de los distintos tipos disponibles de bicicletas
 * \param tamT int tamaño del vector de los tipos
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int listarBicicletas(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief Muestra los datos de una unica bicicleta en el sistema
 *
 * \param bicicleta eBicicleta Una sola bicicleta
* \param colores[] eColor vector de los distintos colores
 * \param tamC int tamaño del vector de los colores
 * \param tipos[] eTipo vector de los distintos tipos disponibles de bicicletas
 * \param tamT int tamaño del vector de los tipos
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int mostrarBicicleta(eBicicleta bicicleta, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief Se encarga de buscar una bicicleta con su ID dentro de un vector de bicicletas
 *
 * \param bicicletas[] eBicicleta vector de bicicletas
 * \param tamB int tamaño de del vector de bicicletas
 * \param id int id de la bicicleta que se busca
 * \param pIndice int* puntero al indice deonde se encuentra la bicicleta en el vector
 * \return int
 *
 */
int buscarBicicleta(eBicicleta bicicletas[],int tamB,int id,int* pIndice);

//ABM

/** \brief realiza un alta de un dato eBicicleta en el vector de bicicletas pidiendo y mostrando los datos necesarios al usuario con sus respectivas validaciones
 *
 * \param bicicletas[] eBicicleta vector de bicicletas
 * \param tamB int tamaño de del vector de bicicletas
 * \param colores[] eColor vector de los distintos colores
 * \param tamC int tamaño del vector de los colores
 * \param tipos[] eTipo vector de los distintos tipos disponibles de bicicletas
 * \param tamT int tamaño del vector de los tipos
 * \param pId int* puntero al al id autoincremental de las bicicletas
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int altaBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT, int* pId);

/** \brief realiza la modificacion de un dato eBicicleta en el vector de bicicletas pidiendo y mostrando los datos necesarios al usuario con sus respectivas validaciones
 *
 * \param bicicletas[] eBicicleta vector de bicicletas
 * \param tamB int tamaño de del vector de bicicletas
 * \param colores[] eColor vector de los distintos colores
 * \param tamC int tamaño del vector de los colores
 * \param tipos[] eTipo vector de los distintos tipos disponibles de bicicletas
 * \param tamT int tamaño del vector de los tipos
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int modificarBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);
/** \brief Realiza la baja de una bicicleta ya ingresada al sistema
 *
 * \param bicicletas[] eBicicleta vector de bicicletas
 * \param tamB int tamaño de del vector de bicicletas
 * \param colores[] eColor vector de los distintos colores
 * \param tamC int tamaño del vector de los colores
 * \param tipos[] eTipo vector de los distintos tipos disponibles de bicicletas
 * \param tamT int tamaño del vector de los tipos
 * \return int retorna 1 todoOk 0 !todoOk
 *
 */
int bajaBicicleta(eBicicleta bicicletas[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

