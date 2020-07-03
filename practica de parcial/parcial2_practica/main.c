#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "vuelos.h"




int main()
{
    int opcion;
    int flag1 = 0;
    int flag2 = 0;
    LinkedList* listaDeVuelos = ll_newLinkedList();
    LinkedList* listaDePilotos = ll_newLinkedList();

    do
    {
        menu(&opcion);

        switch(opcion)
        {
        case 1:
            if(flag1 == 0 && flag2 ==0)
            {
                flag1 = controller_Quiroz_loadFromTextVuelo("vuelo.csv",listaDeVuelos);

                flag2 = controller_Quiroz_loadFromTextPiloto("piloto.csv",listaDePilotos);

            }
            else
            {
                printf("Error. Ya se cargaron los datos.\n");
            }
            system("pause");
            break;
        case 2:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_Quiroz_ListVuelos(listaDeVuelos,listaDePilotos);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;

        case 3:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_Quiroz_cantidadDePasajeros(listaDeVuelos);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;
        case 4:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_Quiroz_filtrarDestinoIrlanda(listaDeVuelos,listaDePilotos);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;
        case 5:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_Quiroz_vuelosCortos(listaDeVuelos,listaDePilotos);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;
        case 6:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_Quiroz_filtrarDestinoPortugal(listaDeVuelos,listaDePilotos);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;

        case 7:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_Quiroz_filtrarNombre(listaDeVuelos,listaDePilotos);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;

             case 8:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_Quiroz_filtrarNombrePilotoParametros(listaDeVuelos,listaDePilotos);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;

        case 10:

            validOpcion(&opcion);
            if(opcion==1)
            {
                ll_deleteLinkedList(listaDePilotos);
                ll_deleteLinkedList(listaDeVuelos);

                opcion=10;
            }
            break;

        default:
            printf("Opcion invalida\n");

        }
        system("cls");
    }
    while(opcion != 10);

    return 0;
}
