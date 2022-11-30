#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "outputs.h"
ePelicula* peli_new()
{
    ePelicula *auxpelicula = NULL;
    auxpelicula = (ePelicula*) malloc(sizeof(ePelicula));
    return auxpelicula;
}

ePelicula* peli_newParametros(char *idStr, char *nombreCompletoStr, char *generoStr,
                             char *duracionStr)
{
    ePelicula *auxpelicula;
    auxpelicula = peli_new();
    if (auxpelicula != NULL && idStr != NULL && nombreCompletoStr != NULL
            && generoStr != NULL && duracionStr != NULL)
    {
        if (!(peli_setId(auxpelicula,atoi(idStr))&& peli_setGenero(auxpelicula,generoStr)&& peli_setDuracion(auxpelicula,atof(duracionStr))&& peli_setTitulo(auxpelicula,nombreCompletoStr)))
        {
            puts("Hubo un problema al crear la pelicula");
            free(auxpelicula);
            auxpelicula = NULL;
            system("pause");
        }

    }
    return auxpelicula;
}

int peli_setId(ePelicula *this,int id)
{
    int validado=0;
    if(this!= NULL && id>0)
    {
        this->id_peli=id;
        validado=1;
    }
    return validado;
}
int peli_getId(ePelicula *this,int *id)
{
    int validado=0;
    if(this!= NULL && id!= NULL && id!= NULL)
    {
        *id=this->id_peli;
        validado=1;
    }
    return validado;
}
int peli_setTitulo(ePelicula *this,char *titulo)
{
    int validado=0;
    if(this!= NULL && titulo!= NULL )
    {
        strcpy(this->titulo,titulo);
        validado=1;
    }
    return validado;
}
int peli_getTitulo(ePelicula *this,char *titulo)
{
    int validado=0;
    if(this!= NULL && titulo!= NULL)
    {
        strcpy(titulo,this->titulo);
        validado=1;
    }
    return validado;
}

int peli_setGenero(ePelicula *this,char *genero)
{
    int validado=0;
    if(this!= NULL && genero!= NULL)
    {
        strcpy( this->genero,genero);
        validado=1;
    }
    return validado;
}
int peli_getGenero(ePelicula *this,char *genero)
{
    int validado=0;
    if(this!= NULL && genero!= NULL)
    {
        strcpy(genero,this->genero);
        validado=1;
    }
    return validado;
}


int peli_setDuracion(ePelicula *this,float duracion)
{
    int validado=0;
    if(this!= NULL )
    {
        this->duracion=duracion;
        validado=1;
    }
    return validado;
}
int peli_getDuracion(ePelicula *this,float *duracion)
{
    int validado=0;
    if(this!= NULL && duracion!= NULL)
    {
        *duracion=this->duracion;
        validado=1;
    }
    return validado;
}
int peli_mostrarPelicula(ePelicula *peli)
{
    char titulo[100];
    char genero[100];
    float duracion;
    int id;
    int validado=0;
    if(peli!= NULL)
    {
        peli_getGenero(peli,genero);
        peli_getId(peli,&id);
        peli_getDuracion(peli,&duracion);
        peli_getTitulo(peli,titulo);
        printf("%-5d %-50s %-15s %.2f\n",id,titulo,genero,duracion);
        validado=1;
    }
    return validado;
}
int peli_destruirPelicula(ePelicula *peliculaInd)
{
    int validado = 0;
    if (peliculaInd != NULL)
    {
        free(peliculaInd);
        validado = 1;
    }
    return validado;
}
int peli_ordenarPeliculasGenero(void *unaPeli, void *otraPeli)
{
    char auxPrimerPelicula[30];
    char auxSegundaPelicula[30];
    int compara = -2;
    if (unaPeli != NULL && otraPeli != NULL)
    {
        peli_getGenero(unaPeli, auxPrimerPelicula);
        peli_getGenero(otraPeli, auxSegundaPelicula);
        stringLower(auxPrimerPelicula);
        stringLower(auxSegundaPelicula);
        compara = strcmp(auxPrimerPelicula, auxSegundaPelicula);

    }
     return compara;
}


int peli_ordenarPorDuracion(void *unaPeli, void *otraPeli)
{
    char generoPrimerPelicula[30];
    char generoSegundaPelicula[30];
    float primeraDuracion;
    float segundaDuracion;
    int compara = -2;
    if (unaPeli != NULL && otraPeli != NULL)
    {
        peli_getGenero((ePelicula*)unaPeli, generoPrimerPelicula);
        peli_getGenero((ePelicula*)otraPeli, generoSegundaPelicula);
        stringLower(generoPrimerPelicula);
        stringLower(generoSegundaPelicula);
        peli_getDuracion((ePelicula*)unaPeli,&primeraDuracion);
        peli_getDuracion((ePelicula*)otraPeli,&segundaDuracion);

        if( strcmp(generoPrimerPelicula, generoSegundaPelicula)==0)
        {

            if(primeraDuracion>segundaDuracion)
            {
                compara=1;
            }
            else
            {
                if(primeraDuracion<segundaDuracion)
                {
                    compara=-1;
                }
                else
                {
                    compara=0;
                }
            }
        }

    }
            return compara;
}
