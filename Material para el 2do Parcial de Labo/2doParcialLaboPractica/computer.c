/*
 * funciones.c
 *
 *  Created on: 22 nov. 2022
 *      Author: kualo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#include "Controller.h"
#include "computer.h"
//#include "menu.h"
#include "input.h"

// ==========================================================================================================================
// ==================== 					Funciones eComputer Basicas 					==========================

eComputer* Computer_new()
{
	eComputer* this = NULL;

	this = (eComputer*) malloc(sizeof(eComputer));

	return this;
}

eComputer* Computer_newParametros(int id, char* desc, float precio, int idTipo)
{
	eComputer* this = NULL;

	if(!isnan(id) && desc != NULL && !isnan(precio) && !isnan(idTipo))
	{
		this = Computer_new();

		if(this != NULL)
		{
			if(Computer_setId(this, id) || Computer_setDesc(this, desc) || Computer_setPrecio(this, precio) || Computer_setIdTipo(this, idTipo))
			{
				if(!Computer_delete(this))
				{
					this = NULL;


				}
			}
		}
	}

	return this;
}

eComputer* Computer_newParametrosAsText(char* idStr, char* desc, char* precioStr, char* idTipoStr)
{
	eComputer* this = NULL;

	if(idStr != NULL && desc != NULL && precioStr != NULL && idTipoStr != NULL)
	{
		this = Computer_new();

		if(this != NULL)
		{
			/*
			 * 		SET ID TXT	--------	TESTING... OK?...
			 * 		SET DESC	--------	TESTING... OK?...
			 * 		SET PRECIO	--------	TESTING... OK?...
			 * 		SET ID		--------	TESTING... OK?...
			 */

			if(Computer_setIdTxt(this, idStr) || Computer_setDesc(this, desc) || Computer_setPrecioTxt(this, precioStr) || Computer_setIdTipoTxt(this, idTipoStr))
			{
				Computer_delete(this);

				this = NULL;
			}
		}
	}

	return this;
}

int Computer_delete(eComputer* this)
{
	int toReturn = -1;

	if(this != NULL)
	{
		free(this);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter ID 					========================== | INT

int Computer_setId(eComputer* this, int id)
{
	int toReturn = -1;

	if(this != NULL && !isnan(id))
	{
		this->id = id;

		toReturn = 0;
	}

	return toReturn;
}

int Computer_getId(eComputer* this, int* id)
{
	int toReturn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;

		toReturn = 0;
	}

	return toReturn;
}

int Computer_setIdTxt(eComputer* this, char* idStr)
{
	int toReturn = -1;

	int auxId;

	if(this != NULL && idStr != NULL && isNumInt(idStr, BUFFER_LEN) == 1)
	{
		auxId = atoi(idStr);

		if(auxId > 0)
		{
			this->id = auxId;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Computer_getIdTxt(eComputer* this, char* idStr)
{
	int toReturn = -1;

	if(this != NULL && idStr != NULL)
	{
		snprintf(idStr, BUFFER_LEN, "%d", this->id);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter Desc 					========================== | CHAR *

int Computer_setDesc(eComputer* this, char* desc)
{
	int toReturn = -1;

	if(this != NULL && desc != NULL)
	{
		strncpy(this->descripcion, desc, DESC_LEN);

		toReturn = 0;
	}

	return toReturn;
}
int Computer_getDesc(eComputer* this, char* desc)
{
	int toReturn = -1;

	if(this != NULL && desc != NULL)
	{
		strncpy(desc, this->descripcion, DESC_LEN);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter Precio 				========================== | FLOAT

int Computer_setPrecio(eComputer* this, float precio)
{
	int toReturn = -1;

	if(this != NULL && !isnan(precio))
	{
		this->precio = precio;

		toReturn = 0;
	}

	return toReturn;
}

int Computer_getPrecio(eComputer* this, float* precio)
{
	int toReturn = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;

		toReturn = 0;
	}

	return toReturn;
}

int Computer_setPrecioTxt(eComputer* this, char* precioStr)
{
	int toReturn = -1;

	int auxPrecio;

	if(this != NULL && precioStr != NULL && isNumInt(precioStr, BUFFER_LEN) == 1)
	{
		auxPrecio = atoi(precioStr);

		if(auxPrecio > 0)
		{
			this->precio = auxPrecio;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Computer_getPrecioTxt(eComputer* this, char* precioStr)
{
	int toReturn = -1;

	if(this != NULL && precioStr != NULL)
	{
		snprintf(precioStr, BUFFER_LEN, "%f", this->precio);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter ID Tipo 				========================== | INT

int Computer_setIdTipo(eComputer* this, int idTipo)
{
	int toReturn = -1;

	if(this != NULL && !isnan(idTipo))
	{
		if(idTipo > -1)
		{
			this->idTipo = idTipo;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Computer_getIdTipo(eComputer* this, int* idTipo)
{
	int toReturn = -1;

	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;

		toReturn = 0;
	}

	return toReturn;
}

int Computer_setIdTipoTxt(eComputer* this, char* idTipoStr)
{
	int toReturn = -1;

	int auxIdTipo;

	if(this != NULL && idTipoStr != NULL && isNumInt(idTipoStr, BUFFER_LEN) == 1)
	{
		auxIdTipo = atoi(idTipoStr);

		if(auxIdTipo > -1)
		{
			this->idTipo = auxIdTipo;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Computer_getIdTipoTxt(eComputer* this, char* idTipoStr)
{
	int toReturn = -1;

	if(this != NULL && idTipoStr != NULL)
	{
		snprintf(idTipoStr, BUFFER_LEN, "%d", this->idTipo);

		toReturn = 0;
	}

	return toReturn;
}

/// ==========================================================================================================================
/// ==========================================================================================================================

// ==================== 		Funciones eJugador | Buscar Por ID 						========================== |

int Computer_findJugadorPorId(LinkedList* pArrayList, int id, int* index)
{
	int toReturn = -1;

	int i;
	int len;
	int auxId;

	eComputer*  this = NULL;

	if(pArrayList != NULL && !isnan(id) && index != NULL)
	{
		len = ll_len(pArrayList);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (eComputer*) ll_get(pArrayList, i);

				if(this != NULL && !Computer_getId(this, &auxId))
				{
					if(auxId == id)
					{
						*index = i;

						toReturn = 0;
						break;
					}
				}
			}
		}
	}

	return toReturn;
}

int Computer_comparaByIdSeleccion(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxIdTipo1;
	int auxIdTipo2;

	eComputer* pComputer1 = NULL;
	eComputer* pComputer2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pComputer1 = (eComputer*) pElement1;
		pComputer2 = (eComputer*) pElement2;

		if(!Computer_getIdTipo(pComputer1, &auxIdTipo1) && !Computer_getIdTipo(pComputer2, &auxIdTipo2))
		{
			if(auxIdTipo1 > auxIdTipo2)
			{
				// EL ID TIPO 1 ES MAYOR AL ID TIPO 2.
				toReturn = 1;
			}
			else if(auxIdTipo1 == auxIdTipo2)
			{
				// EL ID TIPO 1 ES IGUAL AL ID TIPO 2.
				toReturn = 0;
			}
			else
			{
				// EL ID TIPO 1 ES MENOR AL ID TIPO 2.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | SORT  								========================== |

int Computer_sort(LinkedList* pArrayList)
{
	int toReturn = -1;

	int (*pFunc)(void*, void*);

	if(pArrayList != NULL)
	{
		pFunc = Computer_comparaByIdSeleccion;

		if(!ll_sort(pArrayList, pFunc, 0))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | PRINT - LIST				========================== |

int Computer_print(eComputer* this)
{
	int toReturn = -1;

	int auxId;
	char auxDesc[DESC_LEN];
	float auxPrecio;
	int auxIdTipo;

	char auxDescTipo[BUFFER_LEN];

	if(this != NULL)
	{
		if(!Computer_getId(this, &auxId) && !Computer_getDesc(this, auxDesc) && !Computer_getPrecio(this, &auxPrecio) && !Computer_getIdTipo(this, &auxIdTipo))
		{
			if(auxIdTipo == 1)
			{
				strncpy(auxDescTipo, "Desktop", BUFFER_LEN);
			}
			else
			{
				strncpy(auxDescTipo, "Laptop", BUFFER_LEN);
			}

			printf("|  %-2d  |  %-110s | %-10.2f | %-10s  | \n", auxId, auxDesc, auxPrecio, auxDescTipo);

			toReturn = 0;
		}
	}

	return toReturn;
}

int Computer_list(LinkedList* pArrayList)
{
	int toReturn = -1;

	int i;
	int len;

	eComputer* this = NULL;

	if(pArrayList != NULL)
	{
		len = ll_len(pArrayList);

		if(len > 0)
		{
			printf("\n");
			fflush(stdin);

		    printf("===================================================================================================================================================== \n");

			printf("| %-4s |  %-110s | %-10s |  %-10s | \n", "ID", "DESCRIPCION", "PRECIO", "ID TIPO");

			//         ID            	DESCRIPCION              			  																	PRECIO        	ID TIPO
		    printf("|======|=================================================================================================================|============|=============| \n");

		    for(i = 0; i < len; i++)
		    {
		    	this = (eComputer*) ll_get(pArrayList, i);

		    	if(this != NULL)
		    	{
		    		if(Computer_print(this))
		    		{
		    			break;
		    		}
		    	}
		    }

		    if(i == len)
		    {
		    	toReturn = 0;

		    	printf("|______|_________________________________________________________________________________________________________________|____________|_____________| \n");
		    }
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | MAP					========================== |

int Computer_aumentoToDesktop(void* pElement)
{
	int toReturn = -1;

	float auxPrecio;
	float aumento;

	int auxIdTipo;

	eComputer* pComputer = NULL;

	if(pElement != NULL)
	{
		pComputer = (eComputer*) pElement;

		if(!Computer_getIdTipo(pComputer, &auxIdTipo) && auxIdTipo == 1 && !Computer_getPrecio(pComputer, &auxPrecio))
		{
			aumento = auxPrecio * 10 / 100;

			auxPrecio = auxPrecio + aumento;

			if(!Computer_setPrecio(pComputer, auxPrecio))
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int Computer_aumentoToLaptop(void* pElement)
{
	int toReturn = -1;

	float auxPrecio;
	float aumento;

	int auxIdTipo;

	eComputer* pComputer = NULL;

	if(pElement != NULL)
	{
		pComputer = (eComputer*) pElement;

		if(!Computer_getIdTipo(pComputer, &auxIdTipo) && auxIdTipo == 2 && !Computer_getPrecio(pComputer, &auxPrecio))
		{
			aumento = auxPrecio * 20 / 100;

			auxPrecio = auxPrecio + aumento;

			if(!Computer_setPrecio(pComputer, auxPrecio))
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

