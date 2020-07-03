#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/** \brief PARSER VUELOS
 *
 * \param pFile FILE*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int parser_VuelosFromText(FILE* pFile , LinkedList* pArrayListVuelos);
/** \brief PARSER PILOTOS
 *
 * \param pFile FILE*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int parser_PilotosFromText(FILE* pFile , LinkedList* pArrayListPilotos);
