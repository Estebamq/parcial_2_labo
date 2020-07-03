#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************
    getString
    getName
    getUnsignedInt
    getNumeroConDecimales

**************************/

/** \brief Solicita el ingreso de un string y valida su tamaño
* \param msg char* Mensaje a mostrar
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño minimo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
//-------------------------------------------------------------------------------------------------
/** \brief Solicita el ingreso de un string y valida su tamaño y su contenido (solo letras)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
int isValidName(char* stringRecibido);
//-----------------------------------------------------------------------------------------------
/** \brief Solicita el ingreso de un numero y valida su tamaño y su contenido (numero sin signo)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input int* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input);
int isValidNumber(char* stringRecibido);
//-----------------------------------------------------------------------------------------------
/** \brief Solicita el ingreso de un numero y valida su tamaño y su contenido (numero con decimales)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input float* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int getFloat(char* msg, char* msgError, int minSize, int maxSize, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);

//-----------------------------------------------------------------------------------------------

/** \brief VALIDO la opcion de salida
 *
 * \param
 * \param
 * \return
 *
 */
void validOpcion (int* opcion);
