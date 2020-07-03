#include <stdio.h>
#include <stdlib.h>
#include "vuelos.h"
#include "parser.h"
#include "pilotos.h"


int parser_VuelosFromText(FILE* pFile, LinkedList* pArrayListVuelos)
{
    Evuelos* auxVuelo = vuelos_new();
    int retorno = 0;
    int rd ;
    char auxId[20];
    char auxIdAvion[20];
    char auxIdPiloto[20];
    char auxFecha[20];
    char auxDestino[20];
    char auxCantPasajero[20];
    char auxHsDespegue[20];
    char auxHsLlegada[20];

    // Leo la primera fila que tiene las descripciones de los tipos de datos para que no se cargue en la estructura
    rd = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdAvion,auxIdPiloto,auxFecha,auxDestino,auxCantPasajero,auxHsDespegue,auxHsLlegada);

    while(!feof(pFile))
    {
         rd = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdAvion,auxIdPiloto,auxFecha,auxDestino,auxCantPasajero,auxHsDespegue,auxHsLlegada);
            if(rd==8)
            {
                auxVuelo = Vuelos_newParametros(auxId,auxIdAvion,auxIdPiloto,auxFecha,auxDestino,auxCantPasajero,auxHsDespegue,auxHsLlegada);
                ll_add(pArrayListVuelos, auxVuelo);
                retorno++;
            }
     }
        printf("%d Datos de vuelo fueron cargados a la lista en modo texto\n", retorno);

        return retorno;

}

int parser_PilotosFromText(FILE* pFile, LinkedList* pArrayListPilotos)
{
    Epilotos* auxPiloto = Piloto_new();
    int retorno = 0;
    int rd ;
    char auxId[20];
    char auxNombre[50];


    // Leo la primera fila que tiene las descripciones de los tipos de datos para que no se cargue en la estructura
    rd = fscanf(pFile,"%[^,],%[^\n]\n",auxId,auxNombre);

    while(!feof(pFile))
    {
         rd = fscanf(pFile,"%[^,],%[^\n]\n",auxId,auxNombre);

            if(rd==2)
            {
                auxPiloto = Piloto_newParametros(auxId,auxNombre);
                ll_add(pArrayListPilotos, auxPiloto);
                retorno++;
            }
     }
        printf("%d Datos de los pilotos fueron cargados a la lista en modo texto\n", retorno);

        return retorno;

}

