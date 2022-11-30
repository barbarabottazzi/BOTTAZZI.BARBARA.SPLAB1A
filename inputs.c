#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "outputs.h"
#include "input.h"

#ifndef INPUTS_C_
#define INPUTS_C_

int validaciones_ingresoRangoInt(int *pResultado, char *mensaje,
		char *mensajeError, int minimo, int maximo)
{

	int validado = 0;
	int num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo)
	{
		fflush(stdin);
		getInt(&num, mensaje, mensajeError);
		while (num < minimo || num > maximo)
		{
			fflush(stdin);
			getInt(&num, mensajeError, mensajeError);
		}
		validado = 1;
		*pResultado = num;

	}
	return validado;

}
int getInt(int *pVariableAInt, char mensaje[], char mensajeError[])
{
	int validado = 0;
	int resultado;
	int auxResultado;
	if (pVariableAInt != NULL)
	{
		printf(mensaje);
		resultado = scanf("%d", &auxResultado);
		while (resultado != 1)
		{
			fflush(stdin);
			printf(mensajeError);
			resultado = scanf("%d", &auxResultado);
		}
		*pVariableAInt = auxResultado;
		validado = 1;
	}

	return validado;
}

char getChar(char mensaje[])
{
	char auxiliar;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &auxiliar);
	return auxiliar;
}
void getString(char mensaje[], char input[])
{

	puts(mensaje);
	fflush(stdin);
	gets(input);

}
;

void getFullName(char nombreCompleto[], int maxNombre, int maxApellido)
{
	char nombre[maxNombre];
	char apellido[maxApellido];
	char auxNombreCompleto[maxApellido + maxNombre + 5];

	printf("Ingrese nombre...\n");
	fflush(stdin);
	gets(nombre);
	while (!validaciones_letras(nombre)
			|| !validaciones_tamanioString(nombre, maxNombre))
	{
		if (!validaciones_letras(nombre))
		{
			printf("Error,ingrese Nombre valido...\n");
		}
		else
		{
			printf("Nombre muy largo.. ingrese un nombre valido");
		}

		fflush(stdin);
		gets(nombre);
	}
	stringLower(nombre);
	nombre[0] = toupper(nombre[0]);
	printf("Ingrese Apellido...\n");
	fflush(stdin);
	gets(apellido);
	while (!validaciones_letras(apellido)
			|| !validaciones_tamanioString(apellido, maxApellido))
	{
		if (!validaciones_letras(apellido))
		{
			printf("Error,ingrese Apellido valido...\n");
		}
		else
		{
			printf("Apellido muy largo.. ingrese un apellido valido");
		}

		fflush(stdin);
		gets(apellido);
	}
	stringLower(apellido);
	apellido[0] = toupper(apellido[0]);
	strcpy(auxNombreCompleto, nombre);
	strcat(auxNombreCompleto, " ");
	strcat(auxNombreCompleto, apellido);
	auxNombreCompleto[0] = toupper(auxNombreCompleto[0]);
	strcpy(nombreCompleto, auxNombreCompleto);
}
;
int validaciones_confirma(char *pVariable, char *mensaje, char confirma,
		char noConfirma)
{
	int todoOk = 0;
	char rta;
	if (pVariable != NULL)
	{

		printf(mensaje);
		fflush(stdin);
		rta = tolower(getchar());

		if (rta == 's')
		{
			*pVariable = confirma;
		}
		else
		{

			*pVariable = noConfirma;
		}
		todoOk = 1;

	}
	return todoOk;
}
int validaciones_letras(char str[])
{
	int validado = 1;
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ')
				|| (((str[i] < 'a') || (str[i] > 'z'))
						&& ((str[i] < 'A') || (str[i] > 'Z'))))
		{
			validado = 0;
			break;

		}
		i++;
	}
	if (strlen(str) == 0)
	{
		validado = 0;
	}
	return validado;

}
int validaciones_tamanioString(char string[], int maxLenString)
{
	int validado = 1;
	int lengString;
	lengString = strlen(string);
	if (lengString > maxLenString)
	{
		validado = 0;
	}

	return validado;

}

#endif /* INPUTS_C_ */
