#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pelicula.h"
#include "parser.h"
#include <string.h>
#include "outputs.h"
#include "input.h"
#include "controller.h"

int controller_cargarArchivos( LinkedList *listaPeliculas)
{
    int validado = 0;
    FILE *pArch;
    char path[50];
    if (listaPeliculas != NULL)
    {
        printf("Ingrese nombre del archivo\n");
        fflush(stdin);
        gets(path);

        pArch = fopen(strcat(path,".csv"), "r");
        if(pArch!= NULL)
        {
            parser_peliculaDesdeTexto(pArch, listaPeliculas);
            printf("Archivo cargado con exitosamente!\n");
            fclose(pArch);
            validado = 1;
        }
        else
        {
            printf("Ha ocurrido un error al abrir el archivo\n");
            system("pause");
        }

    }



    return validado;
};

int controller_listarPeliculas(LinkedList *pListaPeliculas)
{
    int validado=0;
    int tamPeliculas=ll_len(pListaPeliculas);
    if(pListaPeliculas!= NULL)
    {
        printf("%-5s %-50s %-15s %-10s\n","Id","Titulo","Genero","Rating");
        printf("********************************************************************************\n");
        for(int i=0; i<tamPeliculas; i++)
        {
            peli_mostrarPelicula((ePelicula*)ll_get(pListaPeliculas,i));
        }
        validado=1;
    }
    else
    {
        printf("No hay peliculas agregadas\n");
    }
    return validado;
}


void* controller_tiempoAleatorio(void *peli)
{
    ePelicula *nuevaPelicula=NULL;
    nuevaPelicula=peli_new();
    ePelicula* peliculaOriginal =(ePelicula*)peli;
    float duracionAleatoria;

    if(peli!= NULL)
    {
        //(240-100+1)+100
        //(ranD()%(MAX-MIN+1))+MIN
        duracionAleatoria=(rand())%140+100;
        *nuevaPelicula=*peliculaOriginal;
        peli_setDuracion(nuevaPelicula,duracionAleatoria);
    }
    return (void*)nuevaPelicula;
}

int controller_asignarTiempos(LinkedList **listaPeliculas)
{
    int validado=0;
    if(*listaPeliculas!=NULL)
    {
        LinkedList *listaResultado;
        listaResultado=ll_map(*listaPeliculas,controller_tiempoAleatorio);
        controller_destruirPeliculas(*listaPeliculas);
        ll_deleteLinkedList(*listaPeliculas);
        *listaPeliculas=listaResultado;
        validado=1;
    }
    return validado;
}

int controller_esHorror(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"horror")==0)
    {
        ok=1;
    }
    return ok;
}
int controller_esAccion(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"action")==0)
    {
        ok=1;
    }
    return ok;
}

int controller_esDrama(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"drama")==0)
    {
        ok=1;
    }
    return ok;
}
int controller_esMusical(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"musical")==0)
    {
        ok=1;
    }
    return ok;
}


int controller_esAventura(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"adventure")==0)
    {
        ok=1;
    }
    return ok;
}
int controller_esComedia(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"comedy")==0)
    {
        ok=1;
    }
    return ok;
}
int controller_esRomance(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"romance")==0)
    {
        ok=1;
    }
    return ok;
}
int controller_esDocumental(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"documentary")==0)
    {
        ok=1;
    }
    return ok;
}
int controller_esWestern(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"western")==0)
    {
        ok=1;
    }
    return ok;
}
int controller_esThriller(void *peli)
{
    int ok=0;
    ePelicula*unaPeli=NULL;
    char generoOriginal[100];
    unaPeli=(ePelicula*)peli;
    // devuelvo 1 si cumple la condic
    peli_getGenero(unaPeli,generoOriginal);
    stringLower(generoOriginal);
    if(strcmp(generoOriginal,"thriller")==0)
    {
        ok=1;
    }
    return ok;
}

int controller_filtrarGenero(LinkedList **listaPeliculas)
{
    int validado=0;
    if(*listaPeliculas!=NULL)
    {
        printf("Ingrese un genero a filtrar...\n");
        LinkedList *auxLista;
        char generoAFiltrar[100];
        char confirma;
        char generos[10][100]=
        {"adventure","drama","comedy","romance","documentary","horror","musical","western","thriller","accion"};

        switch(menuGeneros())
        {
        case 0:
            strcpy(generoAFiltrar,generos[0]);
            auxLista=ll_filter(*listaPeliculas,controller_esAventura);
            break;
        case 1:
            strcpy(generoAFiltrar,generos[1]);
            auxLista=ll_filter(*listaPeliculas,controller_esDrama);
            break;
        case 2:
            strcpy(generoAFiltrar,generos[2]);
            auxLista= ll_filter(*listaPeliculas,controller_esComedia);
            break;
        case 3:
            strcpy(generoAFiltrar,generos[3]);
            auxLista=ll_filter(*listaPeliculas,controller_esRomance);
            break;
        case 4:
            strcpy(generoAFiltrar,generos[4]);
            auxLista=ll_filter(*listaPeliculas,controller_esDocumental);
            break;
        case 5:
            strcpy(generoAFiltrar,generos[5]);
            auxLista=ll_filter(*listaPeliculas,controller_esHorror);
            break;
        case 6:
            strcpy(generoAFiltrar,generos[6]);
            auxLista=ll_filter(*listaPeliculas,controller_esMusical);
            break;
        case 7:
            strcpy(generoAFiltrar,generos[7]);
            auxLista=ll_filter(*listaPeliculas,controller_esWestern);
            break;
        case 8:
            strcpy(generoAFiltrar,generos[8]);
            auxLista=ll_filter(*listaPeliculas,controller_esThriller);
            break;
        case 9:
            strcpy(generoAFiltrar,generos[9]);
            auxLista=ll_filter(*listaPeliculas,controller_esAccion);
            break;
        case 10:
            validaciones_confirma(&confirma, "confirma salida?\n",'s','n');
            break;


        }
        if(auxLista!= NULL)
        {
            *listaPeliculas=auxLista;
        }


        validado=1;
    }
    else
    {
        printf("Ocurrio un error al filtrar la lista \n");
    }
    return validado;
}




int controller_destruirPeliculas(LinkedList *this)
{
    int validado = 0;
    int cant = ll_len(this);
    if (this != NULL)
    {
        for (int i = 0; i < cant; i++)
        {
            peli_destruirPelicula((ePelicula*) ll_get(this, i));
        }
        validado = 1;
    }
    return validado;
}

int controller_ordenar(LinkedList *listadoPeliculas)
{
    int validado=0;
    if(listadoPeliculas!= NULL)
    {
        int orden;
        validaciones_ingresoRangoInt(&orden,
                                     "Ingrese 1 para ordenar ascendente, 0 para ordenar descendente",
                                     "Error, eliga 0 o 1", 0, 1);
        ll_sort(listadoPeliculas, peli_ordenarPeliculasGenero, orden);
        ll_sort(listadoPeliculas,peli_ordenarPorDuracion,0);
        validado=1;
    }
    return validado;
}
int controller_guardarPeliculas(LinkedList *listaPeliculas)
{
    int validado=0;
    char path[100];
    char confirma;
    if(listaPeliculas!= NULL)
    {
        FILE *f;
        printf("Ingrese nombre donde guardar el archivo");
        fflush(stdin);
        gets(path);
        f=fopen(path,"r");
        if(f!=NULL)
        {
            fflush(stdin);
            validaciones_confirma(&confirma, "El archivo ya existe, se va a sobreescribir, confirma?",'s','n');

        }
        if(confirma == 's' || f==NULL)
        {
            f=fopen(path,"w");
            parser_peliculaATexto(f,listaPeliculas);
            fclose(f);
        }
        else
        {
            printf("Creacion de archivo cancelada por el usaurio\n");
        }
        fclose(f);

        validado=1;
    }
    return validado;
}
