#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include "outputs.h"
#include <ctype.h>
int menuPrincipal()
{
    int opcion;
    printf(
        "                                                     MENU PRINCIPAL         \n");
    puts(
        "------------------------------------------------------------------------------------------------------------");
    printf("1-CARGA DE ARCHIVOS  \n");
    printf("2-IMPRIMIR LISTA\n");
    printf("3-ASIGNAR TIEMPOS \n");
    printf("4-FILTRAR POR TIPO \n");
    printf("5-ORDENAR Y MOSTRAR \n");
    printf("6-GUARDAR PELICULAS \n");
    printf("7-SALIR \n");

    validaciones_ingresoRangoInt(&opcion, "Ingrese una opcion: \n",
                                 "Error,ingrese un numero entre 1 y 7", 1, 7);
    return opcion;
}
;
int menuGeneros()
{
    int opcion;
    printf(
        "                                                     Generos        \n");
    puts(
        "------------------------------------------------------------------------------------------------------------");
    printf("0-Aventura \n");
    printf("1-Drama\n");
    printf("2-Comedia \n");
    printf("3-Romance \n");
    printf("4-Documental \n");
    printf("5-Horror \n");
    printf("6-Musical \n");
    printf("7-Western \n");
    printf("8-Thriller \n");
    printf("9-Accion \n");
    printf("10-SALIR \n");

    validaciones_ingresoRangoInt(&opcion, "Ingrese una opcion: \n",
                                 "Error,ingrese un numero entre 0 y 10", 0, 10);
    return opcion;
}
;
int stringLower(char str[])
{
    int validado = 0;
    if (str != NULL)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = tolower(str[i]);
        }
        validado = 1;

    }
    return validado;
}
