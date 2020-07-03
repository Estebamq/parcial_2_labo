#include <string.h>
#include <stdlib.h>

#include "pilotos.h"

Epilotos* Piloto_new(void)
{
  Epilotos* pilotos;
  pilotos = (Epilotos*)calloc(sizeof(Epilotos),1);

  return pilotos;
}

Epilotos* Piloto_newParametros(char* idStr,char* nombreStr)

{
    Epilotos* piloto;
    piloto = Piloto_new();
    int id;
    char Nombre[50];


   if(piloto!=NULL )
    {
        id=atoi(idStr);
        strcpy(Nombre,nombreStr);

        Piloto_setId(piloto,id);
        Piloto_setNombre(piloto,Nombre);

   }

    return piloto;

}

int Piloto_setId(Epilotos* This,int id)
{
    int retorno=0;

    if(This!=NULL)
    {
        This->id=id;
        retorno = 1;
    }

    return retorno;

}
int Piloto_getId(Epilotos* This,int* id)
{
    int retorno=0;

    if(This!=NULL)
    {
        *id = This->id;
        retorno = 1;
    }

    return retorno;

}

int Piloto_setNombre(Epilotos* This,char* nombre)
{
    int retorno=0;

    if(This!=NULL && nombre!=NULL)
    {
        strcpy(This->nombre,nombre);
        retorno = 1;
    }

    return retorno;


}

int Piloto_getNombre(Epilotos* This,char* nombre)
{
    int retorno = 0;

    if(This!=NULL)
    {
        strcpy(nombre,This->nombre);
        retorno=1;
    }

    return retorno;

}
//cree para buscar piloto por id
int Piloto_buscarPilotoId(Epilotos* This, char* nombre,char* idPiloto)
{
    int retorno=0;
    char auxNombre[20];
    int auxIdPiloto;
    char auxIdP;


    if(This!=NULL){
        Piloto_getNombre(This,auxNombre);
        if(strcmpi(auxNombre,nombre)==0)
        {
            Piloto_getId(This,&auxIdPiloto);
            (itoa(auxIdP,auxIdPiloto,10));
            strcpy(idPiloto,auxIdP);
            retorno=1;
        }

    }
    return retorno;

}

int Piloto_buscarPilotoNombre(LinkedList* This, char* nombre)
{
    int retorno=0;
    char auxNombre[20];
    int auxIdPiloto,i;
    char auxIdP;

    Epilotos* pAuxPilotos;


    if(This!=NULL){
        for(i=0;i<ll_len(This);i++)
        {
                pAuxPilotos=(Epilotos*)ll_get(This,i);
                Piloto_getNombre(pAuxPilotos,auxNombre);

                if(strcmpi(auxNombre,nombre)==0)
                {
                    Piloto_getId(pAuxPilotos,&retorno);
                    printf("%d",retorno);
                    break;

                }
        }

    }


    return retorno;

}
