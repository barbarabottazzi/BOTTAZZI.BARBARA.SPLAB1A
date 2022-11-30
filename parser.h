#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
/** \brief  realiza la conversion de un formato de texto recibido desde un archivo
 *
 * \param FILE
 * \param LINKEDLIST
 * \return 1 si se realizo bien la funcion, 0 si no
 *
 */

int parser_peliculaDesdeTexto(FILE *pArch, LinkedList *listaPeliculas);


 /** \brief  realiza la conversion de un formato para ser subido a un archivo de texto
  *
  * \param f FILE*
  * \param auxLista LinkedList*
  * \return int 1 si se realizo bien la funcion, 0 si no
  *
  */
 int parser_peliculaATexto(FILE *f,LinkedList *auxLista);

#endif // PARSER_H_INCLUDED
