#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* This, int nodeIndex);
static int addNode(LinkedList* This, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* This;

    This = (LinkedList*) malloc(sizeof(LinkedList));
    if(This!=NULL)
    {
        This->size = 0;
        This->pFirstNode = NULL;
    }

    return This;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* This)
{
    int returnAux = -1;
    if(This!=NULL)
    {
        returnAux = This->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* This, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(This != NULL )
    {
        if (nodeIndex >-1 && nodeIndex <ll_len(This))
        {
            pNode = This ->pFirstNode;
            if(nodeIndex>0)
            {
                for(i=0; i<nodeIndex; i++)
                {
                    pNode = pNode-> pNextNode;

                }
            }
        }
    }

    return pNode;
}





/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* This, int nodeIndex)
{


    return getNode(This, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

static int addNode(LinkedList* This, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* nuevoNodo;

    if(This != NULL && nodeIndex>-1 && nodeIndex<=ll_len(This))
    {
        nuevoNodo=(Node*)malloc(sizeof(Node));
        if(ll_len(This)==0)//PRIMER NODO
        {

            if(nuevoNodo!=NULL)
            {
                This->pFirstNode=nuevoNodo;
                This->size++;
                nuevoNodo->pElement=pElement;
                nuevoNodo->pNextNode=NULL;
                returnAux=0;
            }

        }
        else if(ll_len(This)==nodeIndex) //ULTIMO NODO
        {

            if(nuevoNodo!=NULL)
            {
                prev=getNode(This,nodeIndex-1);
                prev->pNextNode=nuevoNodo;
                nuevoNodo->pNextNode=NULL;
                nuevoNodo->pElement=pElement;
                This->size++;
                returnAux=0;
            }

        }
        else  //AGREGA UN NODO EN UNA POSICION QUE SEA EN EL MEDIO DE PRIMERO Y EL ULTIMO
        {


            if(nuevoNodo!=NULL)
            {
                prev=getNode(This,nodeIndex-1);
                nuevoNodo->pNextNode=prev->pNextNode;
                prev->pNextNode=nuevoNodo;
                nuevoNodo->pElement=pElement;
                This->size++;
                returnAux=0;
            }


        }

    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* This, void* pElement)
{
    int returnAux = -1;
    int indice = 0;

    if(This!=NULL)
    {
        indice= ll_len(This);
        returnAux=addNode(This,indice,pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* This, int index)
{
    void* returnAux = NULL;
    Node* nuevoNodo=NULL;

    if(This!=NULL )
    {
        nuevoNodo=getNode(This,index);
        if(nuevoNodo!=NULL)
        {
            returnAux= nuevoNodo->pElement;

        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* This, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;


    if(This!=NULL )
    {
        actual=getNode(This,index);
        if(actual!=NULL)
        {
            actual->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* This,int index)
{
    int returnAux = -1;
    Node* actual;
    Node* next;
    Node* nuevoNodo;


    if(This != NULL && index>-1 && index<=ll_len(This))
    {
        if(index==0 )
        {
            This->pFirstNode=NULL;
            This->size=0;
            returnAux=0;
        }

        actual=getNode(This,index);
        if(actual!=NULL && index !=0)
        {
            if(ll_len(This)==1 && index==1 )//PRIMER NODO
            {

                This->pFirstNode=NULL;
                actual->pElement=NULL;
                free(actual);
                This->size--;
                returnAux=0;


            }
            else if(ll_len(This)==index) //ULTIMO NODO
            {
                actual->pElement=NULL;
                nuevoNodo=getNode(This,index-1);
                nuevoNodo->pNextNode=NULL;
                free(actual);
                This->size--;
                returnAux=0;
            }
            else  //AGREGA UN NODO EN UNA POSICION QUE SEA EN EL MEDIO DE PRIMERO Y EL ULTIMO
            {


                next=actual->pNextNode;
                actual->pElement=NULL;
                nuevoNodo=getNode(This,index-1);
                nuevoNodo->pNextNode=next;
                free(actual);
                This->size--;
                returnAux=0;

            }
        }
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* This)
{
    int returnAux = -1;
    Node* nuevoNodo;
    Node* actual;
    int cantidad=ll_len(This);

    if(This!=NULL && ll_len(This)>-1)
    {

        if(ll_len(This)==0 )//PRIMER NODO
        {
            This->pFirstNode=NULL;
            returnAux=0;
        }

        if(ll_len(This)!=0)
        {

            while(cantidad>0)
            {


                actual=getNode(This,cantidad);
                nuevoNodo=getNode(This,cantidad-1);
                nuevoNodo->pNextNode=NULL;
                free(actual);
                This->size--;
                cantidad--;
                returnAux=0;
            }
        }
    }




    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* This)
{
    int returnAux = -1;
    int cantidadL;
    if(This!=NULL)
    {
        cantidadL=ll_clear(This);

        if(cantidadL==0)
        {
            This->size=0;
            free(This);
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* This, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;

    if(This!=NULL)
    {

        for(i=0; i<ll_len(This); i++)
        {
            nodo = getNode(This,i);
            if(nodo->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if( ll_len(this)!=0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* This, int index, void* pElement)
{
    int returnAux = -1;

    returnAux=addNode(This,index,pElement);

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_pop(LinkedList* This,int index)
{
    void* returnAux = NULL;

    if(This != NULL)
    {
        if(index>-1 && index<=ll_len(This))
        {

            returnAux = ll_get(This,index);
            ll_remove(This,index);
        }
    }


    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* This, void* pElement)
{
    int returnAux = -1;

    if(This!=NULL)
    {
        if(ll_indexOf(This,pElement)!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* This,LinkedList* This2)
{
    int returnAux = -1;
    int i;
    int contiene=0;



    if(This!=NULL && This2!=NULL)
    {
        if(ll_len(This)>-1 && ll_len(This2)>-1)
        {

            for(i=0; i<ll_len(This2); i++)
            {

                if(ll_contains(This,ll_get(This2,i)))
                {
                    contiene++;
                }

            }

            if(contiene==ll_len(This2))
            {
                returnAux=1;
            }
            else
            {
                returnAux=0;
            }

        }

    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* This,int from,int to)
{
    LinkedList* cloneArray = NULL;
    LinkedList* newList=ll_newLinkedList();
    int i;
    void* pElement;

    if(This!=NULL && newList!=NULL)
    {
        if( to<=ll_len(This)&& from<ll_len(This))
        {
            if(from<=to && from>-1)
            {
                for(i=from; i<to; i++)
                {
                    pElement=ll_get(This,i);
                    ll_add(newList,pElement);

                }
                cloneArray=newList;

            }

        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* This)
{
    LinkedList* cloneArray = NULL;
    if(This!=NULL)
    {
        cloneArray=ll_subList(This,0,ll_len(This));

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* This, int (*pFunc)(void*,void* ), int order)
{
    int returnAux = -1;
    int i, j;
    void* aux;
    if(This != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i = 0; i<(ll_len(This)-1); i++)
        {
            for(j = i+1; j<ll_len(This); j++ )
            {
                if(order == 1 && pFunc(ll_get(This, i), ll_get(This, j)) > 0)
                {
                    aux = ll_get(This,i);
                    ll_set(This,i,ll_get(This,j));
                    ll_set(This,j,aux);
                    returnAux = 0;

                }
                else if(order == 0 && pFunc(ll_get(This,i), ll_get(This,j)) < 0)
                {
                    aux = ll_get(This,i);
                    ll_set(This,i,ll_get(This,j));
                    ll_set(This,j,aux);
                }

                if(order == 1 && pFunc(ll_get(This, i), ll_get(This, j)) > 0)
                {
                    aux = ll_get(This,i);
                    ll_set(This,i,ll_get(This,j));
                    ll_set(This,j,aux);

                }
                else if(order == 0 && pFunc(ll_get(This,i), ll_get(This,j)) < 0)
                {
                    aux = ll_get(This,i);
                    ll_set(This,i,ll_get(This,j));
                    ll_set(This,j,aux);
                }

                returnAux = 0;
            }

        }
    }

    return returnAux;
}


//ll_count

/** \brief CONTADOR, acumulador con puntero a funcion
 *
 * \param element void*
 * \return int ll_count(LinkedList* This, int
 *
 */
int ll_count(LinkedList* This, int (*fn)(void* element))
{
    int retorno=0;
    int i;
    if(This!=NULL && fn!=NULL)
    {
        for(i=0; i<ll_len(This); i++)
        {
            retorno+=fn(ll_get(This,i));
        }

    }

    return retorno;

}

/** \brief FILTRA POR PARAMETROS con una puntero a funcion
 *
 * \param element void*
 * \return LinkedList* ll_filter(LinkedList* This, int
 *
 */
LinkedList* ll_filter(LinkedList* This, int (*fn)(void* element))
{
    LinkedList* filterList =ll_newLinkedList();

    void* pElement;
    int respuesta,i;

    if(This!=NULL && fn!=NULL && filterList!=NULL)
    {
        for(i=0; i<ll_len(This);i++)
        {
            respuesta = fn(ll_get(This,i));
            if(respuesta==1)
            {
                pElement=ll_get(This,i);
                ll_add(filterList,pElement);
            }
        }
    }
    return filterList;
}

LinkedList* ll_filter_parametro(LinkedList* This, int (*fn)(void* element,char*elemento),char* caracter)
{
    LinkedList* filterList =ll_newLinkedList();

    void* pElement;
    int respuesta,i;

    if(This!=NULL && fn!=NULL && filterList!=NULL)
    {
        for(i=0; i<ll_len(This);i++)
        {
            respuesta = fn(ll_get(This,i),caracter);
            if(respuesta==1)
            {
                pElement=ll_get(This,i);
                ll_add(filterList,pElement);
            }
        }
    }
    return filterList;
}

