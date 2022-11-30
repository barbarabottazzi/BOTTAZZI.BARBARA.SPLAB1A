#ifndef INPUT_H_
#define INPUT_H_

/** \brief Pregunta un numero al usuario y valida si un numero entero,pertenece a un rango.
 *
 * \param pResultado int* direccion de memoria donde se guarda el numero a validar
 * \param mensaje char* mensaje a mostrar al usuario
 * \param mensajeError char* mensaje en caso de error, a mostrar al usuario
 * \param minimo int rango minimo a validar
 * \param maximo int rango maximo a validar
 * \return int devuelve 0 si haye error en la validacion, 1 si no hay error
 *
 */
int validaciones_ingresoRangoInt(int *pResultado, char *mensaje,
		char *mensajeError, int minimo, int maximo);
/** \brief pide al usuario un numero entero y lo valida
 *
 * \param pVariableAInt int* direccion de memoria a guardar el valor del numero validado
 * \param mensaje[] char mensaje a mostrar al usuario
 * \param mensajeError[] char mensaje de error a mostrar al usuario
 * \return devuelve 0 si hay un error en la validacion y 1 si se resuelve bien
 *
 */
int getInt(int *pVariableAInt, char mensaje[], char mensajeError[]);
/**
 * @brief pide nombre y apellido al usuario y lo valida segun rango de longitud
 *
 * @param nombreCompleto direccion de memoria donde se guarda el nombre
 * @param maxNombre largo maximo del nombre
 * @param maxApellido largo maximo del apellido
 */
void getFullName(char nombreCompleto[], int maxNombre, int maxApellido);

/** \brief pide al usuario un dato tipo char
 *
 * \param mensaje[] char mensaje a mostrar al usario
 * \return char retorna el char que inrgeso el usuario
 *
 */
char getChar(char mensaje[]);
/**
 * @brief pide al usuario un string
 *
 * @param mensaje mensaje a mostrar al usuario
 * @param input donde se guarda el string ingresado por el usuario
 */
void getString(char mensaje[], char input[]);
/**
 * @brief valida si un string cumple con una longitud
 *
 * @param string string a evaluar
 * @param lenString largo maximo
 * @return 1 si cumple con la condicion , 0 si no cumple
 */
int validaciones_tamanioString(char string[], int maxLenString);
/**
 * @brief confirma si el usuario quiere continuar ejecutando el programa o no
 *
 * @param p direccion de memoria de la variable donde se va a guardar la respuesta del usuario.
 * @param confirma el valor de confirmacion por ej 's'
 * @param Noconfirma el valor de confirmacion por ej 'n'
 * @return devuelve 0 para no, 1 para si
 */
int validaciones_confirma(char *pVariable, char *mensaje, char confirma,
		char noConfirma);
/** \brief devuelve si un array de strings contiene o no letras unicamente
 *
 * \param str[] char string a evaluar
 * \return int devuelve 0 si tiene al menos un caracter que no sea letras validas y 1 si tiene letras
 *
 */
int validaciones_letras(char str[]);
#endif /* INPUT_H_ */
