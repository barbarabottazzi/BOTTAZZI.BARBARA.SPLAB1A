#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "outputs.h"
#include <time.h>
#include "controller.h"
#include "input.h"

int main()
{
    srand(time(NULL));
    char confirma='n';
    int cambios=0;
    LinkedList *listaPeliculas=ll_newLinkedList();
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            controller_cargarArchivos(listaPeliculas);
            break;
        case 2:
            if(!ll_isEmpty(listaPeliculas))
            {
                controller_listarPeliculas(listaPeliculas);
            }
            else
            {
                printf("primero debe cargar un archivo\n");
            }

            break;
        case 3:
            if(!ll_isEmpty(listaPeliculas))
            {
                controller_asignarTiempos(&listaPeliculas);
                controller_listarPeliculas(listaPeliculas);
                cambios=1;
            }
                else
                {
                    printf("primero debe cargar un archivo\n");
                }

                break;
            case 4:
                if(!ll_isEmpty(listaPeliculas))
                {
                    controller_filtrarGenero(&listaPeliculas);
                    controller_listarPeliculas(listaPeliculas);
                    cambios=1;
                }
                else
                {
                    printf("primero debe cargar un archivo\n");
                }
                break;
            case 5:
                if(!ll_isEmpty(listaPeliculas))
                {
                    controller_ordenar(listaPeliculas);
                    controller_listarPeliculas(listaPeliculas);
                    cambios=1;

                }
                else
                {
                    printf("primero debe cargar un archivo\n");
                }

                break;
            case 6:
                if(!ll_isEmpty(listaPeliculas))
                {
                    controller_guardarPeliculas(listaPeliculas);
                    cambios=0;
                }
                else
                {
                    printf("primero debe cargar un archivo\n");

                }
                break;
            case 7:
                if(cambios)
                {
                    validaciones_confirma(&confirma, "Hay cambios realizado, si no los guarda se perderan...Confirma salida?",'s','n');
                }
                else
                {
                    validaciones_confirma(&confirma, "Confirma salida?",'s','n');
                }

                break;

            }
        }
        while(confirma!= 's');
        controller_destruirPeliculas(listaPeliculas);
        ll_deleteLinkedList(listaPeliculas);
        return 0;
    }
