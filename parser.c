#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
int parser_peliculaDesdeTexto(FILE *pFile, LinkedList *listaPeliculas)
{
    int validado = 0;
    ePelicula *pPelicula;
    char data[4][100];

    if (pFile != NULL && listaPeliculas != NULL)
    {

        fgets(data[0], 2500, pFile);
        while (!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", data[0],
                   data[1], data[2], data[3]);
            pPelicula = peli_newParametros(data[0], data[1], data[2], data[3]);
            ll_add(listaPeliculas, pPelicula);
        }

    }
    validado = 1;
    return validado;
}
int parser_peliculaATexto(FILE *f,LinkedList *auxLista)
{

    int validado = 0;
    int id;
    char titulo[100];
    char genero[100];
    float duracion;

    if (f != NULL && auxLista != NULL)
    {
        fprintf(f,"%s,%s,%s,%s\n","Id","Genero","Titulo","Rating");
        int cantidadPelis=ll_len(auxLista);
        for(int i=0; i<cantidadPelis; i++)
        {
            ePelicula *aux=ll_get(auxLista,i);
            peli_getGenero(aux,genero);
            peli_getId(aux,&id);
            peli_getDuracion(aux,&duracion);
            peli_getTitulo(aux,titulo);
            fprintf(f,"%d,%s,%s,%f\n",id,titulo,genero,duracion);
        }
        printf("Archivo creado exitosamente\n");
        validado=1;
    }
    else
    {
        printf("Ocurrio un error\n");
    }
    return validado;
}
