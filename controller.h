#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "pelicula.h"
#include "LinkedList.h"
/** \brief carga archivos de texto en la linkedlist
 *
 * \param listaPeliculas LinkedList*
 * \return int 1 si pudo realizar la funcion , 0 si no
 *
 */
int controller_cargarArchivos( LinkedList* listaPeliculas);
/** \brief filtra las peliculas por genero elegido por el usuario y las guarda en la linkedlist
 *
 * \param listaPeliculas LinkedList**
 * \return int 1 si pudo realizar la funcion , 0 si no
 *
 */
int controller_filtrarGenero(LinkedList **listaPeliculas);
/** \brief muestra las peliculas de la linkedlist
 *
 * \param pListaPeliculas LinkedList*
 * \return int 1 si pudo realizar la funcion , 0 si no
 *
 */
int controller_listarPeliculas(LinkedList *pListaPeliculas);
/** \brief elimina todas las direcciones de memoria de las peliculas
 *
 * \param this LinkedList*
 * \return int 1 si pudo realizar la funcion , 0 si no
 *
 */
int controller_destruirPeliculas(LinkedList *this);
/** \brief guarda las peliculas cargadas en la linkedlist en un archivo csv
 *
 * \param listaPeliculas LinkedList*
 * \return int 1 si pudo realizar la funcion , 0 si no
 *
 */
int controller_guardarPeliculas(LinkedList *listaPeliculas);
/** \brief ordena la linkedlist segun genero y duracion
 *
 * \param listadoPeliculas LinkedList*
 * \return int 1 si pudo realizar la funcion , 0 si no
 *
 */
int controller_ordenar(LinkedList *listadoPeliculas);
/** \brief asigna un tiempo aleatorio a una pelicula
 *
 * \param peli void*
 * \return void* devuelva la pelicula modificada con el tiempo
 *
 */
void* controller_tiempoAleatorio(void *peli);
/** \brief hace un map de la lista de peliculas el cual retorna una nueva lista que es reemplaza por la linkedlist existente.
 *
 * \param listaPeliculas LinkedList**
 * \return int 1 si pudo realizar la funcion , 0 si no
 *
 */
int controller_asignarTiempos(LinkedList **listaPeliculas);
/** \brief comprueba si una pelicula es del genero thriller
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esThriller(void *peli);
/** \brief comprueba si una pelicula es del genero aventura
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esAventura(void *peli);
/** \brief comprueba si una pelicula es del genero accion
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esAccion(void *peli);
/** \brief comprueba si una pelicula es del genero comedia
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esComedia(void *peli);
/** \brief comprueba si una pelicula es del genero documental
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esDocumental(void *peli);
/** \brief comprueba si una pelicula es del genero drama
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esDrama(void *peli);
/** \brief comprueba si una pelicula es del genero western
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esWestern(void *peli);
/** \brief comprueba si una pelicula es del genero horron
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esHorror(void *peli);
/** \brief comprueba si una pelicula es del genero musical
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esMusical(void *peli);
/** \brief comprueba si una pelicula es del genero romance
 *
 * \param peli void*
 * \return 1 si cumple condicion , 0 si no
 *
 */
int controller_esRomance(void *peli);
#endif // CONTROLLER_H_INCLUDED
