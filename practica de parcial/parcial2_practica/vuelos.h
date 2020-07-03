#include "validation.h"
typedef struct
{
    int id;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horasDespegue;
    int horasLlegada;

}Evuelos;

/** \brief Crea espacio para un nuevo vuelo
 *
 * \return Employee*
 *
 */
Evuelos* vuelos_new();


/** \brief Crea espacio para un nuevo vuelo con parametros
 *
 * \param idStr char*
 * \param idAvionStr char*
 * \param idPilotoStr char*
 * \param fechaStr char*
 * \param destino char*
 * \param cantPasajeros char*
 * \param horasDespegueStr char*
 * \param horasLlegadaStr char*
 * \return Evuelos*
 *
 */
Evuelos* Vuelos_newParametros(char* idStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destino,char* cantPasajeros,char* horasDespegueStr,char* horasLlegadaStr);
/** \brief Set ID empleado
 *
 * \param This Employee*
 * \param id int
 * \return int
 *
 */
int vuelo_setId(Evuelos* This,int id);

/** \brief Get ID empleado
 *
 * \param This Employee*
 * \param id int*
 * \return int
 *
 */
int vuelo_getId(Evuelos* This,int* id);
/** \brief SET IDAVION de vuelos
 *
 * \param This Evuelos*
 * \param idAvion int
 * \return int
 *
 */
int vuelo_setIdAvion(Evuelos* This,int idAvion);
/** \brief GET IDAVION vuelos
 *
 * \param This Evuelos*
 * \param idAvion int*
 * \return int
 *
 */
int vuelo_getIdAvion(Evuelos* This,int* idAvion);
/** \brief SET ID piloto
 *
 * \param This Evuelos*
 * \param id int
 * \return int
 *
 */
int vuelo_setIdPiloto(Evuelos* This,int id);
/** \brief
 *
 * \param This Evuelos*
 * \param id int*
 * \return int
 *
 */
int vuelo_getIdPiloto(Evuelos* This,int* id);
/** \brief SET FECHA de vuelo
 *
 * \param This Evuelos*
 * \param fecha char*
 * \return int
 *
 */

int vuelo_setFecha(Evuelos* This,char* fecha);
/** \brief DA de baja un vuelo
 *
 * \param This Employee*
 * \return void
 *
 */
void vuelo_delete(Evuelos* This);
/** \brief GET FECHA de vuelo
 *
 * \param This Evuelos*
 * \param fecha char*
 * \return int
 *
 */
int vuelo_getFecha(Evuelos* This,char* fecha);
/** \brief SET DESTINO de vuelo
 *
 * \param This Evuelos*
 * \param destino char*
 * \return int
 *
 */
int vuelo_setDestino(Evuelos* This,char* destino);
/** \brief GET DESTINO de vuelo
 *
 * \param This Evuelos*
 * \param destino char*
 * \return int
 *
 */
int vuelo_getDestino(Evuelos* This,char* destino);
/** \brief SET CANT PASAJEROS del vuelo
 *
 * \param This Evuelos*
 * \param cantPasajeros int
 * \return int
 *
 */
int vuelo_setCantPasajeros(Evuelos* This,int cantPasajeros);
/** \brief GET CANT PASAJEROS del vuelo
 *
 * \param This Evuelos*
 * \param cantPasajeros int*
 * \return int
 *
 */
int vuelo_getCantPasajeros(Evuelos* This,int* cantPasajeros);

/** \brief SET HORA DESPEGUE del vuelo
 *
 * \param This Evuelos*
 * \param horasDespegue int
 * \return int
 *
 */
int vuelo_setHorasDespegue(Evuelos* This,int horasDespegue);

/** \brief GET HORA DESPEGUE de vuelo
 *
 * \param This Evuelos*
 * \param horasDespegue int*
 * \return int
 *
 */
int vuelo_getHorasDespegue(Evuelos* This,int* horasDespegue);

/** \brief SET HORAS LLEGADA de los vuelos
 *
 * \param This Evuelos*
 * \param horasLlegada int
 * \return int
 *
 */
int vuelo_setHorasLlegada(Evuelos* This,int horasLlegada);
/** \brief GET HORAS LLEGADA de los vuelos
 *
 * \param This Evuelos*
 * \param horasLlegada int*
 * \return int
 *
 */
int vuelo_getHorasLlegada(Evuelos* This,int* horasLlegada);


/** \brief Contador de cantidades de personas
 *
 * \param parametro void*
 * \return int
 *
 */
int vuelo_parametroAcontar(void* parametro);

/** \brief Filtra lista nueva de personas con destino a Irlanda
 *
 * \param destino void*
 * \return int
 *
 */
int Vuelo_filtroDestinoIrlanda(void* destino);
/** \brief filtra por Vuelos cortos
 *
 * \param horas void*
 * \return int
 *
 */
int Vuelo_filtroVuelosCortos(void* horas);
/** \brief Filtra lista nueva de personas con destino a Portugal
 *
 * \param destino void*
 * \return int
 *
 */
int Vuelo_filtroDestinoPortugal(void* destino);
/** \brief Filtra lista nueva de pilotos, sin Alex.
 *
 * \param vuelos void*
 * \return int
 *
 */
int Vuelo_filtroNombre(void* vuelos);

int Vuelo_filtroNombreCaracter(void* vuelos, char* idPilotoc);
