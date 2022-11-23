#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int toReturn = -1;

    if(this != NULL)
    {
    	toReturn = this->size;
    }

    return toReturn;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	int i;
	int len;

	// VERIFICA THIS SEA DISTINTO A NULL
	// Y QUE EL INDEX SEA MAYOR O IGUAL A 0
	if(this != NULL && nodeIndex >= 0)
	{
		len = ll_len(this);

		// EL INDEX NODE TIENE QUE SER MENOR AL LEN
		if(nodeIndex < len)
		{
			// pNode es IGUAL al 1er. Node
			pNode = this->pFirstNode;

			// SE BUSCA HASTA EL NODE OBJETIVO
			for(i = 0; i < nodeIndex; i++)
			{
				pNode = pNode->pNextNode;
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
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
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
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int toReturn = -1;

    int len;

    Node* pNewNode;
    Node* pLastNode;

	// VERIFICA THIS SEA DISTINTO A NULL
	// Y QUE EL INDEX SEA MAYOR O IGUAL A 0
    if(this != NULL && nodeIndex >= 0)
    {
    	len = ll_len(this);

    	// EL NODE TIENE QUE SER MENOR O IGUAL AL TAMAÑO DE LA LISTA
    	if(nodeIndex <= len)
    	{
    		// SE CREA EL NUEVO NODO
    		pNewNode = (Node*) malloc(sizeof(Node));

    		// SE VERIFICA QUE SEA DISTINTO A NULL
    		if(pNewNode != NULL)
    		{
    			// SE IGUALA EL pElement AL pElement DEL NODE
    			pNewNode->pElement = pElement;

    			if(nodeIndex == 0)
    			{
    				// SI EL NODE ES EL PRIMERO NODO
    				// SE IGUALA SUS DATOS
    				pNewNode->pNextNode = this->pFirstNode;
    				this->pFirstNode = pNewNode;
    			}
    			else
    			{
    				// SI NO ES EL PRIMER NODO
    				// SE OBTIENE LOS DATOS DEL ULTIMO NODE MENOS EL QUE SE ESTA CREANDO
    				pLastNode = getNode(this, nodeIndex - 1);

    				if(pLastNode != NULL)
    				{
    					// SI ES DISTINTO A NULL
    					// SE CAMBIAN LOS DATOS
    					pNewNode->pNextNode = pLastNode->pNextNode;
    					pLastNode->pNextNode = pNewNode;
    				}
    			}
    			this->size++;
    			// SE AUMENTA EL TAMAÑO
    			toReturn = 0;
    		}
    	}
    }

    return toReturn;
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
int ll_add(LinkedList* this, void* pElement)
{
    int toReturn = -1;

    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	toReturn = addNode(this, len, pElement);
    }

    return toReturn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* toReturn = NULL;

    int len;

    Node* pNode;

	// VERIFICA THIS SEA DISTINTO A NULL
	// Y QUE EL INDEX SEA MAYOR O IGUAL A 0
    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	// VERIFICA QUE EL LEN SEA
    	// MENOR AL INDEX & MAYOR A 0
    	if(len > 0 && index < len)
    	{
    		pNode = getNode(this, index);

    		// VERIFICA QUE pNode SEA DISTINTO A NULL
    		if(pNode != NULL)
    		{
    			toReturn = pNode->pElement;
    		}
    	}
    }

    return toReturn;
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
int ll_set(LinkedList* this, int index, void* pElement)
{
    int toReturn = -1;

    int len;

    Node* pNode;

	// VERIFICA THIS SEA DISTINTO A NULL
	// Y QUE EL INDEX SEA MAYOR O IGUAL A 0
    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	// VERIFICA QUE EL LEN SEA
    	// MENOR AL INDEX & MAYOR A 0
    	if(len > 0 && index < len)
    	{
    		pNode = getNode(this, index);

    		if(pNode != NULL)
    		{
    			// SI pNode ES DISTINTO A NULL
    			// SE SETEA AL ELEMENTO DE pNode
    			// CON EL NUEVO pElement
    			pNode->pElement = pElement;

    			toReturn = 0;
    		}
    	}
    }

    return toReturn;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int toReturn = -1;

    int len;

    Node* pNode;
    Node* pAuxNode;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(len > 0 && index < len)
    	{
    		pNode = getNode(this, index);

    		if(pNode != NULL)
    		{
    			if(index == 0)
    			{
    				this->pFirstNode = pNode->pNextNode;
    			}
    			else
    			{
    				pAuxNode = getNode(this, index - 1);

    				pAuxNode->pNextNode = pNode->pNextNode;
    			}

    			free(pNode);
    			this->size--;

    			toReturn = 0;
    		}
    	}
    }

    return toReturn;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int toReturn = -1;

    int i;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len > 0)
    	{
    		for(i = len - 1; i >= 0; i--)
			{
				if(ll_remove(this, i))
				{
					break;
				}
			}

			if(i == -1)
			{
				this->pFirstNode = NULL;
				this->size = 0;

				toReturn = 0;
			}
    	}
    }

    return toReturn;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int toReturn = -1;

    if(this != NULL && !ll_clear(this))
    {
    	free(this);

    	toReturn = 0;
    }

    return toReturn;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int toReturn = -1;

    int i;
    int len;

    void* pAux;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len > 0)
    	{
    		for(i = 0; i < len; i++)
			{
				pAux = ll_get(this, i);

				if(pAux == pElement)
				{
					toReturn = i;
					break;
				}
			}
    	}
    }

    return toReturn;
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
    int toReturn = -1;

    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len == 0)
    	{
    		toReturn = 1;
    	}
    	else
    	{
    		toReturn = 0;
    	}
    }

    return toReturn;
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int toReturn = -1;

    int len;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(index <= len)
    	{
    		toReturn = addNode(this, index, pElement);
    	}
    }

    return toReturn;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* toReturn = NULL;

    int len;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(len > 0 && index < len)
    	{
    		toReturn = ll_get(this, index);

    		if(toReturn != NULL && ll_remove(this, index))
    		{
    			toReturn = NULL;
    		}
    	}
    }

    return toReturn;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int toReturn = -1;

    int index;

    if(this != NULL)
    {
    	index = ll_indexOf(this, pElement);

    	if(index > -1)
    	{
    		toReturn = 1;
    	}
    	else
    	{
    		toReturn = 0;
    	}
    }

    return toReturn;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int toReturn = -1;

    int i;
    int len;

    void* pElement;

    if (this != NULL && this2 != NULL)
    {
		toReturn = 1;

		len = ll_len(this2);

		for(i = 0; i < len; i++)
		{
			pElement = ll_get(this2, i);

			if(!ll_contains(this, pElement))
			{
				toReturn = 0;
				break;
			}
		}
	}

    return toReturn;
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    int i;
    int len;

    void* pElement;

    if(this != NULL && from >= 0 && from < to)
    {
    	len = ll_len(this);

    	if(from <= len && to <= len)
    	{
    		cloneArray = ll_newLinkedList();

    		if(cloneArray != NULL)
    		{
    			for(i = from; i < to; i++)
    			{
    				pElement = ll_get(this, i);

    				if(ll_add(cloneArray, pElement))
    				{
    					free(cloneArray);
    					cloneArray = NULL;
    					break;
    				}
    			}
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
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	cloneArray = ll_subList(this, 0, len);
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int toReturn = -1;

    int i;
    int len;
    int flagSwap;
    int pFuncReturn;

    void* pElement1;
    void* pElement2;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	len = ll_len(this);

    	do
    	{
    		flagSwap = 0;

    		for(i = 0; i < len - 1; i++)
    		{
    			pElement1 = ll_get(this, i);
    			pElement2 = ll_get(this, i + 1);

    			pFuncReturn = pFunc(pElement1, pElement2);

    			if((order == 1 && pFuncReturn == 1) || (order == 0 && pFuncReturn == -1))
    			{
    				flagSwap = 1;

    				ll_set(this, i, pElement2);
    				ll_set(this, i + 1, pElement1);

    			}
    		}
    		len--;


    	}while(flagSwap);

    	toReturn = 0;
    }

    return toReturn;
}

