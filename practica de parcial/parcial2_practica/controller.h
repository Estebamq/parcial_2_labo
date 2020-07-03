/** \brief Carga  los datos desde el archivo "vuelo.csv"
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_Quiroz_loadFromTextVuelo(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos desde el archivo "piloto.csv"
 *
 * \param path char*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_Quiroz_loadFromTextPiloto(char* path, LinkedList* pArrayListPilotos);



/** \brief Muestra la LISTA de Vuelos
 *
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int controller_Quiroz_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);


/** \brief MENU usuario elije opciones
 *
 * \param opcion int*
 * \return void
 *
 */
void menu(int* opcion);
/** \brief muestra la cantidad total de pasajeros
 *
 * \param
 * \param
 * \return
 *
 */

int controller_Quiroz_cantidadDePasajeros(LinkedList* pArrayListVuelo);
/** \brief Filtra y muestra una nueva lista de Vuelo con destino a Irlanda
 *
 * \param pArrayListVuelo LinkedList*
 * \param pArrayListPiloto LinkedList*
 * \return int
 *
 */
int controller_Quiroz_filtrarDestinoIrlanda(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto);
/** \brief Muestra y crea una nueva lista con vuelos menores a 3 hs.
 *
 * \param pArrayListVuelo LinkedList*
 * \param pArrayListPiloto LinkedList*
 * \return int
 *
 */
int controller_Quiroz_vuelosCortos(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto);
/** \brief Filtra y muestra una nueva lista de Vuelo con destino a Portugal
 *
 * \param pArrayListVuelo LinkedList*
 * \param pArrayListPiloto LinkedList*
 * \return int
 *
 */
int controller_Quiroz_filtrarDestinoPortugal(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto);
/** \brief Filtra y muestra un lista sin el piloto Alex
 *
 * \param pArrayListVuelo LinkedList*
 * \param pArrayListPiloto LinkedList*
 * \return int
 *
 */
int controller_Quiroz_filtrarNombre(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto);
int controller_Quiroz_filtrarNombrePilotoParametros(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto);
