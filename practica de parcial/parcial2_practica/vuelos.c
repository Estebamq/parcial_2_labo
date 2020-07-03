#include <stdlib.h>
#include "vuelos.h"
#include "pilotos.h"
#include <string.h>


Evuelos* vuelos_new()
{
  Evuelos* vuelos;
  vuelos = (Evuelos*)calloc(sizeof(Evuelos),1);

  return vuelos;
}

Evuelos* Vuelos_newParametros(char* idStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horasDespegueStr,char* horasLlegadaStr)

{
    Evuelos* vuelos;
    vuelos = vuelos_new();
    int id;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horasDespegue;
    int horasLlegada;

   if(vuelos!=NULL )
    {
        id=atoi(idStr);
        idAvion=atoi(idAvionStr);
        idPiloto=atoi(idPilotoStr);
        strcpy(fecha,fechaStr);
        strcpy(destino,destinoStr);
        cantPasajeros = atoi(cantPasajerosStr);
        horasDespegue = atoi(horasDespegueStr);
        horasLlegada = atoi(horasLlegadaStr);

        vuelo_setId(vuelos,id);
        vuelo_setIdAvion(vuelos, idAvion);
        vuelo_setIdPiloto(vuelos,idPiloto);
        vuelo_setFecha(vuelos,fecha);
        vuelo_setDestino(vuelos,destino);
        vuelo_setCantPasajeros(vuelos,cantPasajeros);
        vuelo_setHorasDespegue(vuelos,horasDespegue);
        vuelo_setHorasLlegada(vuelos, horasLlegada);


   }

    return vuelos;

}

int vuelo_setId(Evuelos* This,int id)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->id=id;
        retorno = 1;
    }

    return retorno;

}
int vuelo_getId(Evuelos* This,int* id)
{
    int retorno=0;

    if(This!=NULL)
    {
        *id = This->id;
        retorno = 1;
    }

    return retorno;

}

int vuelo_setIdAvion(Evuelos* This,int idAvion)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->idAvion=idAvion;
        retorno = 1;
    }

    return retorno;

}
int vuelo_getIdAvion(Evuelos* This,int* idAvion)
{
    int retorno=0;

    if(This!=NULL)
    {
        *idAvion = This->idAvion;
        retorno = 1;
    }

    return retorno;

}
int vuelo_setIdPiloto(Evuelos* This,int id)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->idPiloto=id;
        retorno = 1;
    }

    return retorno;

}
int vuelo_getIdPiloto(Evuelos* This,int* id)
{
    int retorno=0;

    if(This!=NULL)
    {
        *id = This->idPiloto;
        retorno = 1;
    }

    return retorno;

}


void vuelo_delete(Evuelos* This)
{
    if(This!=NULL)
        free(This);
}

int vuelo_setFecha(Evuelos* This,char* fecha)
{
    int retorno=0;

    if(This!=NULL && fecha!=NULL)
    {
        strcpy(This->fecha,fecha);
        retorno = 1;
    }

    return retorno;


}

int vuelo_getFecha(Evuelos* This,char* fecha)
{
    int retorno = 0;

    if(This!=NULL)
    {
        strcpy(fecha,This->fecha);

        retorno=1;
    }

    return retorno;

}
int vuelo_setDestino(Evuelos* This,char* destino)
{
    int retorno=0;

    if(This!=NULL && destino!=NULL)
    {
        strcpy(This->destino,destino);
        retorno = 1;
    }

    return retorno;


}

int vuelo_getDestino(Evuelos* This,char* destino)
{
    int retorno = 0;

    if(This!=NULL)
    {
        strcpy(destino,This->destino);
        retorno=1;
    }

    return retorno;

}

int vuelo_setCantPasajeros(Evuelos* This,int cantPasajeros)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->cantPasajeros=cantPasajeros;
        retorno = 1;
    }

    return retorno;

}
int vuelo_getCantPasajeros(Evuelos* This,int* cantPasajeros)
{
    int retorno=0;

    if(This!=NULL)
    {
        *cantPasajeros = This->cantPasajeros;
        retorno = 1;
    }

    return retorno;

}


int vuelo_setHorasDespegue(Evuelos* This,int horasDespegue)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->horasDespegue=horasDespegue;
        retorno = 1;
    }

    return retorno;

}
int vuelo_getHorasDespegue(Evuelos* This,int* horasDespegue)
{
    int retorno=0;

    if(This!=NULL)
    {
        *horasDespegue = This->horasDespegue;
        retorno = 1;
    }

    return retorno;

}

int vuelo_setHorasLlegada(Evuelos* This,int horasLlegada)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->horasLlegada=horasLlegada;
        retorno = 1;
    }

    return retorno;

}
int vuelo_getHorasLlegada(Evuelos* This,int* horasLlegada)
{
    int retorno=0;

    if(This!=NULL)
    {
        *horasLlegada = This->horasLlegada;
        retorno = 1;
    }

    return retorno;

}





int vuelo_parametroAcontar(void* parametro)
{
    int retorno=0;

    if((parametro != NULL))
    {
        vuelo_getCantPasajeros(parametro,&retorno);
    }
    return retorno;
}

int Vuelo_filtroDestinoIrlanda(void* destino)
{
    int retorno=0;
    char auxDestino [25];

    if(destino!=NULL)
    {
        vuelo_getDestino(destino,auxDestino);
        if(stricmp(auxDestino,"irlanda")==0)
        {
            retorno=1;
        }

    }
    return retorno;
}

int Vuelo_filtroVuelosCortos(void* horas)
{
    int retorno=0;
    int auxMenor;
    int auxHsDespegue;
    int auxHsLlegada;

    if(horas!=NULL)
    {
        vuelo_getHorasDespegue(horas,&auxHsDespegue);
        vuelo_getHorasLlegada(horas,&auxHsLlegada);
        auxMenor = auxHsLlegada-auxHsDespegue;
        if(auxMenor>0 && auxMenor<3)
        {
            retorno=1;
        }

    }
    return retorno;
}

int Vuelo_filtroDestinoPortugal(void* destino)
{
    int retorno=0;
    char auxDestino [25];

    if(destino!=NULL)
    {
        vuelo_getDestino(destino,auxDestino);
        if(stricmp(auxDestino,"portugal")==0)
        {
            retorno=1;
        }

    }
    return retorno;
}

int Vuelo_filtroNombre(void* vuelos)
{
    int retorno=1;
    int auxID;

    if(vuelos!=NULL)
    {
        vuelo_getIdPiloto(vuelos,&auxID);

        if(auxID==1)
        {

            retorno=0;
        }

    }
    return retorno;
}

//incompleto
int Vuelo_filtroNombreCaracter(void* vuelos, char* idPilotoc)
{
    int retorno=0;
    int auxID;
    int auxIdChar;

    if(vuelos!=NULL)
    {
        vuelo_getIdPiloto(vuelos,&auxID);
        auxIdChar=atoi(idPilotoc);

        if(auxID==auxIdChar)
        {
            retorno=1;
        }

    }
    return retorno;
}


