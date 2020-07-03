#include "validation.h"
#include "LinkedList.h"
#include <string.h>
typedef struct
{
    int id;
    char nombre[50];

}Epilotos;

/** \brief Crea un espacio para Piloto
 *
 * \return Epilotos*
 *
 */
Epilotos* piloto_new(void);
/** \brief Crea un espacio para piloto con parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \return Epilotos*
 *
 */
Epilotos* Piloto_newParametros(char* idStr,char* nombreStr);
/** \brief SET ID piloto
 *
 * \param This Epilotos*
 * \param id int
 * \return int
 *
 */
int Piloto_setId(Epilotos* This,int id);
/** \brief GET ID piloto
 *
 * \param This Epilotos*
 * \param id int*
 * \return int
 *
 */
int Piloto_getId(Epilotos* This,int* id);
/** \brief SET NOMBRE piloto
 *
 * \param This Epilotos*
 * \param nombre char*
 * \return int
 *
 */
int Piloto_setNombre(Epilotos* This,char* nombre);
/** \brief GET NOMBRE piloto
 *
 * \param This Epilotos*
 * \param nombre char*
 * \return int
 *
 */
int Piloto_getNombre(Epilotos* This,char* nombre);

int Piloto_buscarPilotoId(Epilotos* This, char* nombre,char* idPiloto);
int Piloto_buscarPilotoNombre(LinkedList* This, char* nombre);

