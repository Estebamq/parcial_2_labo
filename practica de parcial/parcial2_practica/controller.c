#include "parser.h"
#include "vuelos.h"
#include "pilotos.h"


int controller_Quiroz_loadFromTextVuelo(char* path, LinkedList* pArrayListVuelos)
{
    int retorno=0;
    FILE *pArchivo;

    if((pArchivo = fopen(path, "r"))!=NULL)
    {
        parser_VuelosFromText(pArchivo, pArrayListVuelos);
        retorno= 1;
    }
    else
    {

        printf("Error: no se puedo leer\n");

    }

    fclose(pArchivo);

    return retorno;
}

int controller_Quiroz_loadFromTextPiloto(char* path, LinkedList* pArrayListPilotos)
{
    int retorno=0;
    FILE *pArchivo;

    if((pArchivo = fopen(path, "r"))!=NULL)
    {
        parser_PilotosFromText(pArchivo, pArrayListPilotos);
        retorno= 1;
    }
    else
    {

        printf("Error: no se puedo leer\n");

    }

    fclose(pArchivo);
    return retorno;
}





int controller_Quiroz_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    Evuelos* pAuxVuelos;
    Epilotos* pAuxPilotos;
    int retorno = 0;

    int auxId;
    int auxIdAvion;
    int auxIdPiloto;
    int auxIdPilot;
    char auxNombre[50];
    char auxFecha[50];
    char auxDestino[50];
    int auxCantPasajero;
    int auxHsDespegue;
    int auxHsLlegada;
    int lenListVuelo = ll_len(pArrayListVuelos);
    int lenListPiloto = ll_len(pArrayListPilotos);
    int i,j;
    if(pArrayListVuelos!=NULL && pArrayListPilotos!=NULL)
    {
        if(lenListVuelo>0)
        {
            printf("IdVuelo  Id Avion\t   Piloto\t    Fecha\t     Destino     Cant de pasajeros\tHs de despegue\tHs Llegada\n");

            for(i = 0; i < lenListVuelo; i++)
            {
                pAuxVuelos = (Evuelos*)ll_get(pArrayListVuelos, i);
                vuelo_getId(pAuxVuelos, &auxId);
                vuelo_getIdAvion(pAuxVuelos, &auxIdAvion);
                vuelo_getIdPiloto(pAuxVuelos, &auxIdPiloto);
                for(j=0; j<lenListPiloto; j++)
                {
                    pAuxPilotos = (Epilotos*)ll_get(pArrayListPilotos,j);
                    Piloto_getId(pAuxPilotos,&auxIdPilot);
                    if(auxIdPiloto==auxIdPilot)
                    {
                        Piloto_getNombre(pAuxPilotos,auxNombre);
                    }

                }
                vuelo_getFecha(pAuxVuelos,auxFecha);
                vuelo_getDestino(pAuxVuelos,auxDestino);
                vuelo_getCantPasajeros(pAuxVuelos,&auxCantPasajero);
                vuelo_getHorasDespegue(pAuxVuelos,&auxHsDespegue);
                vuelo_getHorasLlegada(pAuxVuelos,&auxHsLlegada);

                printf("%5d %10d %18s %18s %12s %14d %15d  %15d\n",auxId,auxIdAvion,auxNombre,auxFecha,auxDestino,auxCantPasajero,auxHsDespegue,auxHsLlegada);
            }

            retorno = 1;

        }
        else
        {
            printf("No se cargaron los datos.\n");
        }
    }
    return retorno;
}

int controller_Quiroz_cantidadDePasajeros(LinkedList* pArrayListVuelo)
{
    int cantidadPasajeros;
    int retorno=0;
    if(pArrayListVuelo!=NULL)
    {
        cantidadPasajeros = ll_count(pArrayListVuelo,vuelo_parametroAcontar);
        retorno=1;
        printf("la cantidad de pasajeros es:%d\n",cantidadPasajeros);
    }

    return retorno;
}


 int controller_Quiroz_filtrarDestinoIrlanda(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto)
{
    int retorno=0;
    LinkedList* auxFiltro=ll_newLinkedList();


    if(pArrayListVuelo!=NULL)
    {
        auxFiltro = ll_filter(pArrayListVuelo,Vuelo_filtroDestinoIrlanda);
        controller_Quiroz_ListVuelos(auxFiltro,pArrayListPiloto);
        controller_Quiroz_cantidadDePasajeros(auxFiltro);
    }

    return retorno;
}

int controller_Quiroz_vuelosCortos(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto)
{
    int retorno=0;
    Evuelos* pAuxVuelo;
    FILE* pArchivo = fopen("vueloCorto.csv", "w");
    int listLen;
    int i;


    LinkedList* auxFiltro=ll_newLinkedList();


    if(pArrayListVuelo!=NULL)
    {
        auxFiltro = ll_filter(pArrayListVuelo,Vuelo_filtroVuelosCortos);
        controller_Quiroz_ListVuelos(auxFiltro,pArrayListPiloto);
        controller_Quiroz_cantidadDePasajeros(auxFiltro);
    }

    listLen=ll_len(auxFiltro);

    if(pArchivo != NULL)
    {

        fprintf(pArchivo, "IdVuelo,Id Avion,Piloto,Fecha,Destino,Cant de pasajeros,Hs de despegue,Hs Llegada\n");

        if(auxFiltro!=NULL)
        {
            for(i = 0; i < listLen; i++)
            {
                pAuxVuelo = (Evuelos*)ll_get(auxFiltro, i);
                fprintf(pArchivo, "%d,%d,%d,%s,%s,%d,%d,%d\n", pAuxVuelo->id, pAuxVuelo->idAvion, pAuxVuelo->idPiloto, pAuxVuelo->fecha,pAuxVuelo->destino,pAuxVuelo->cantPasajeros,pAuxVuelo->horasDespegue,pAuxVuelo->horasLlegada);
            }
            printf("Archivo guardado con exito\n");
            retorno= 1;
            fclose(pArchivo);

        }


    }

    return retorno;

}

int controller_Quiroz_filtrarDestinoPortugal(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto)
{
    int retorno=0;
    LinkedList* auxFiltro=ll_newLinkedList();


    if(pArrayListVuelo!=NULL)
    {
        auxFiltro = ll_filter(pArrayListVuelo,Vuelo_filtroDestinoPortugal);
        controller_Quiroz_ListVuelos(auxFiltro,pArrayListPiloto);
        controller_Quiroz_cantidadDePasajeros(auxFiltro);
    }

    return retorno;
}

int controller_Quiroz_filtrarNombre(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto)
{
    int retorno=0;
    LinkedList* auxFiltro=ll_newLinkedList();


    if(pArrayListVuelo!=NULL)
    {
        auxFiltro = ll_filter(pArrayListVuelo,Vuelo_filtroNombre);
        controller_Quiroz_ListVuelos(auxFiltro,pArrayListPiloto);
        controller_Quiroz_cantidadDePasajeros(auxFiltro);
    }

    return retorno;
}
//por ll_filterParametros incompleto
int controller_Quiroz_filtrarNombrePilotoParametros(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto)
{
    int retorno=0;
    char auxNombre[50];//="Alex Lifeson";
    int auxIdInt;
    char auxid[20];
    LinkedList* auxFiltro=ll_newLinkedList();




        printf("ingrese nombre del piloto que desea la lista de vuelo: ");
        gets(auxNombre);
       // getName("ingrese nombre del piloto que desea la lista de vuelo: ","Erros",4,25,3,auxNombre);


        auxIdInt=Piloto_buscarPilotoNombre(pArrayListPiloto,auxNombre);
        printf("%d",auxIdInt);

        if(auxIdInt>0)
        {
        (itoa(auxIdInt,auxid,10));

        auxFiltro = ll_filter_parametro(pArrayListVuelo,Vuelo_filtroNombreCaracter,auxid);
        controller_Quiroz_ListVuelos(auxFiltro,pArrayListPiloto);
        controller_Quiroz_cantidadDePasajeros(auxFiltro);
        }




    return retorno;
}


void menu(int* opcion)
{
    getUnsignedInt("**********PARCIAL VUELO PRACTICA LINKEDLIST***************\n Menu:\n 1. Cargar los datos de los Vuelo con choferes desde el archivo vuelo.csv & piloto.csv (modo texto).\n 2. Listar Vuelos con Pilotos.\n 3. Cantidad de Pasajeros:\n 4. Cantidad de Pasajeros a Irlanda.\n 5. Vuelos menores a 3HS.\n 6. Vuelos a Portugal.\n 7. Filtrar por piloto Alex Lifeson.\n 8. filtrar por nombre piloto\n 10. Salir\n Opcion: ","Error\n",1,3,4,opcion);
}
