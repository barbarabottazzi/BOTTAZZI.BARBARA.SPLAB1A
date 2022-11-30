#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
typedef struct
{
    int id_peli;
    char titulo[100];
    char genero[60];
    float duracion;
} ePelicula;


/** \brief crea una nueva pelicula seteando sus valores
 *
 * \param
 * \param
 * \return la nueva pelicula
 *
 */
ePelicula* peli_newParametros(char *idStr, char *nombreCompletoStr, char *generoStr,
                                 char *ratingStr);
/** \brief asigna una nueva direccion de memoria de tipo pelicula
 *
 * \return ePelicula* la nueva direccion de memoria
 *
 */
ePelicula* peli_new();
/** \brief devuelve el id a una pelicula
 *
 * \param ePelicula*this
 * \param id int
 * \return int 1 si se pudo realizar la funcion 0 si no
 *
 */
int peli_setId(ePelicula*this,int id);
/** \brief
 *
 * \param ePelicula*this
 * \param id int*
 * \return int 1 si se pudo realizar la funcion 0 si no
 *
 */
int peli_getId(ePelicula*this,int *id);
int peli_getDuracion(ePelicula*this,float *duracion);
int peli_setDuracion(ePelicula *this,float duracion);
int peli_mostrarPelicula(ePelicula *peli);
int peli_getTitulo(ePelicula *this,char *titulo);
int peli_setTitulo(ePelicula *this,char *titulo);
int peli_setGenero(ePelicula *this,char *genero);
int peli_getGenero(ePelicula *this,char *genero);
int peli_destruirPelicula(ePelicula *peliculaInd);
int peli_ordenarPeliculasGenero(void *unaPeli, void *otraPeli);
int peli_ordenarPorDuracion(void *unaPeli, void *otraPeli);

#endif // PELICULA_H_INCLUDED
