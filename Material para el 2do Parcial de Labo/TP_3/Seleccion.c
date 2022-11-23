#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "input.h"
#include "menu.h"
#include "Seleccion.h"

// ==========================================================================================================================
// ==================== 					Funciones eSeleccion Basicas 					==========================

eSeleccion* Seleccion_new()
{
	eSeleccion* this;

	this = (eSeleccion*) malloc(sizeof(eSeleccion));

	return this;
}

eSeleccion* Seleccion_newParametros(int id, char* paisStr, char* confederacionStr, int convocados)
{
	eSeleccion* this = NULL;

	if(!isnan(id) && paisStr != NULL && confederacionStr != NULL && !isnan(convocados))
	{
		this = Seleccion_new();

		if(this != NULL)
		{
			if(Seleccion_setId(this, id) || Seleccion_setPais(this, paisStr) ||
			   Seleccion_setConfederacion(this, confederacionStr) || Seleccion_setConvocados(this, convocados))
			{
				Seleccion_delete(this);

				this = NULL;
			}
		}
	}

	return this;
}

eSeleccion* Seleccion_newParametrosAsText(char* idStr, char* paisStr,char* confederacionStr, char* convocadosStr)
{
	eSeleccion* this = NULL;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
		this = Seleccion_new();

		if(this != NULL)
		{
			if(Seleccion_setIdTxt(this, idStr) || Seleccion_setPais(this, paisStr) || Seleccion_setConfederacion(this, confederacionStr) || Seleccion_setConvocadosTxt(this, convocadosStr))
			{
				Seleccion_delete(this);

				this = NULL;
			}
		}
	}

	return this;
}

int Seleccion_delete(eSeleccion* this)
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
// ==================== 		Funciones eSeleccion | Setter y Getter ID 					========================== | INT

int Seleccion_setId(eSeleccion* this, int id)
{
	int toReturn = -1;

	if(this != NULL && !isnan(id))
	{
		if(id > 0)
		{
			this->id = id;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Seleccion_getId(eSeleccion* this, int* id)
{
	int toReturn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;

		toReturn = 0;
	}


	return toReturn;
}

int Seleccion_setIdTxt(eSeleccion* this, char* idStr)
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

int Seleccion_getIdTxt(eSeleccion* this, char* idStr)
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
// ==================== 		Funciones eSeleccion | Setter y Getter Pais 				========================== | CHAR *

int Seleccion_setPais(eSeleccion* this, char* pais)
{
	int toReturn = -1;

	if(this != NULL && pais != NULL && isStringAlphabetical(pais, PAIS_LEN))
	{
		strncpy(this->pais, pais, PAIS_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Seleccion_getPais(eSeleccion* this, char* pais)
{
	int toReturn = -1;

	if(this != NULL && pais != NULL)
	{
		strncpy(pais, this->pais, PAIS_LEN);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | Setter y Getter Confederacion 		========================== | CHAR *

int Seleccion_setConfederacion(eSeleccion* this, char* confederacion)
{
	int toReturn = -1;

	if(this != NULL && confederacion != NULL && isStringAlphabetical(confederacion, CONFEDERACION_LEN))
	{
		strncpy(this->confederacion, confederacion, CONFEDERACION_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Seleccion_getConfederacion(eSeleccion* this, char* confederacion)
{
	int toReturn = -1;

	if(this != NULL && confederacion != NULL)
	{
		strncpy(confederacion, this->confederacion, CONFEDERACION_LEN);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | Setter y Getter Convocados 			========================== | INT

int Seleccion_setConvocados(eSeleccion* this, int convocados)
{
	int toReturn = -1;

	if(this != NULL && !isnan(convocados))
	{
		if(convocados > -1)
		{
			this->convocados = convocados;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Seleccion_getConvocados(eSeleccion* this, int* convocados)
{
	int toReturn = -1;

	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;

		toReturn = 0;
	}

	return toReturn;
}

int Seleccion_setConvocadosTxt(eSeleccion* this, char* convocados)
{
	int toReturn = -1;

	int auxConvocados;

	if(this != NULL && convocados != NULL && isNumInt(convocados, BUFFER_LEN) == 1)
	{
		auxConvocados = atoi(convocados);

		if(auxConvocados > -1)
		{
			this->convocados = auxConvocados;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Seleccion_getConvocadosTxt(eSeleccion* this, char* convocados)
{
	int toReturn = -1;

	if(this != NULL && convocados != NULL)
	{
		snprintf(convocados, BUFFER_LEN, "%d", this->convocados);

		toReturn = 0;
	}

	return toReturn;
}

/// ==========================================================================================================================
/// ==========================================================================================================================

// ==================== 		Funciones eSeleccion | Buscar Por ID 						========================== |

int Seleccion_findSeleccionPorId(LinkedList* pArrayListSeleccion, int id, int* index)
{
	int toReturn = -1;

	int i;
	int len;
	int auxId;

	eSeleccion* this = NULL;

	if(pArrayListSeleccion != NULL)
	{
		len = ll_len(pArrayListSeleccion);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (eSeleccion*) ll_get(pArrayListSeleccion, i);

				if(this != NULL && !Seleccion_getId(this, &auxId))
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

int Seleccion_comparaById(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxId1;
	int auxId2;

	eSeleccion* pSeleccion1 = NULL;
	eSeleccion* pSeleccion2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pSeleccion1 = (eSeleccion*) pElement1;
		pSeleccion2 = (eSeleccion*) pElement2;

		if(!Seleccion_getId(pSeleccion1, &auxId1) && !Seleccion_getId(pSeleccion2, &auxId2))
		{
			if(auxId1 > auxId2)
			{
				// EL ID 1 ES MAYOR AL ID 2.
				toReturn = 1;
			}
			else if(auxId1 == auxId2)
			{
				// EL ID 1 ES IGUAL AL ID 2.
				toReturn = 0;
			}
			else
			{
				// EL ID 1 ES MENOR AL ID 2.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Seleccion_comparaByPais(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxPais1[PAIS_LEN];
	char auxPais2[PAIS_LEN];

	int auxCmp;

	eSeleccion* pSeleccion1 = NULL;
	eSeleccion* pSeleccion2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pSeleccion1 = (eSeleccion*) pElement1;
		pSeleccion2 = (eSeleccion*) pElement2;

		if(!Seleccion_getPais(pSeleccion1, auxPais1) && !Seleccion_getPais(pSeleccion2, auxPais2))
		{
			auxCmp = strncmp(auxPais1, auxPais2, PAIS_LEN);

			if(auxCmp > 0)
			{
				// EL PAIS 1 ES MAYOR AL PAIS 2
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// LOS PAISES SON IGUALES
				toReturn = 0;
			}
			else
			{
				// EL PAIS 1 ES MENOR AL PAIS 2
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Seleccion_comparaByConfederacion(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxConfederacion1[CONFEDERACION_LEN];
	char auxConfederacion2[CONFEDERACION_LEN];

	int auxCmp;

	eSeleccion* pSeleccion1 = NULL;
	eSeleccion* pSeleccion2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pSeleccion1 = (eSeleccion*) pElement1;
		pSeleccion2 = (eSeleccion*) pElement2;

		if(!Seleccion_getConfederacion(pSeleccion1, auxConfederacion1) && !Seleccion_getConfederacion(pSeleccion2, auxConfederacion2))
		{
			auxCmp = strncmp(auxConfederacion1, auxConfederacion2, CONFEDERACION_LEN);

			if(auxCmp > 0)
			{
				// LA CONFEDERACION 1 ES MAYOR A LA CONFEDERACION 2
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// LAS CONFEDERACIONES SON IGUALES
				toReturn = 0;
			}
			else
			{
				// LA CONFEDERACION  1 ES MENOR A LA CONFEDERACION  2
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Seleccion_comparaByConvocados(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxConvocados1;
	int auxConvocados2;

	eSeleccion* pSeleccion1 = NULL;
	eSeleccion* pSeleccion2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pSeleccion1 = (eSeleccion*) pElement1;
		pSeleccion2 = (eSeleccion*) pElement2;

		if(!Seleccion_getConvocados(pSeleccion1, &auxConvocados1) && !Seleccion_getConvocados(pSeleccion2, &auxConvocados2))
		{
			if(auxConvocados1 > auxConvocados2)
			{
				// EL CONVOCADO 1 ES MAYOR AL CONVOCADO 2.
				toReturn = 1;
			}
			else if(auxConvocados1 == auxConvocados2)
			{
				// EL CONVOCADO 1 ES IGUAL AL CONVOCADO 2.
				toReturn = 0;
			}
			else
			{
				// EL CONVOCADO 1 ES MENOR AL CONVOCADO 2.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | EDIT  								========================== |

int Seleccion_edit(LinkedList* pArrayListSeleccion, int id, int option)
{
	int toReturn = -1;

	int index;
	int auxConvocados;

	eSeleccion* this = NULL;

	if(pArrayListSeleccion != NULL)
	{
		if(!Seleccion_findSeleccionPorId(pArrayListSeleccion, id, &index))
		{
			this = (eSeleccion*) ll_get(pArrayListSeleccion, id);

			if(this != NULL)
			{
				if(!Seleccion_getConvocados(this, &auxConvocados))
				{
			    	switch(option)
			    	{
			    		case 1:
			    			// SUMAR UNO A LOS CONVOCADOS DE LA SELECCION
			    			// MAXIMO 22!
			    			if(auxConvocados >= 0 && auxConvocados <= 21)
			    			{
			    				auxConvocados++;

			    				if(!Seleccion_setConvocados(this, auxConvocados))
			    				{
			    					toReturn = 0;
			    				}
			    			}
			    			else
			    			{
			    				// SE LLEGO AL LIMITE
			    				toReturn = 1;
			    			}
			    			break;

			    		case 2:
			    			// RESTO UNO A LOS CONVOCADOS DE LA SELECCION
			    			// MINIMO 0!

			    			if(auxConvocados > 0 && auxConvocados <= 22)
			    			{
			    				auxConvocados--;

			    				if(auxConvocados < 0)
			    				{
			    					auxConvocados = 0;
			    				}

		    					if(!Seleccion_setConvocados(this, auxConvocados))
		    					{
			    					toReturn = 0;
		    					}
			    			}
			    			else
			    			{
			    				// SE LLEGO AL LIMITE
			    				toReturn = 1;
			    			}
			    			break;

			    		default:
			    			// ERROR
			    			printf("\nError, se ha ingresado un valor invalido.\n");
			    			break;
			    	}
				}
			}
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | SORT  								========================== |

int Seleccion_sort(LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int orderOption;

	int order;

	int (*pFunc)(void*, void*);

	if(pArrayListSeleccion != NULL)
	{
		do
		{
			if(!Menu_sortOrderMenu(&orderOption))
			{
				switch(orderOption)
				{
					case 1:
						order = 0;
						break;

					case 2:
						order = 1;
						break;

					default:
						printf("\nError, se ha ingresado un valor invalido.\n");
						break;
				}
			}

		}while(orderOption != 1 && orderOption != 2);

		pFunc = Seleccion_comparaByConfederacion;

		ll_sort(pArrayListSeleccion, pFunc, order);

		toReturn = 0;
	}

	return toReturn;
}

int Seleccion_sortById(LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int order;
	int (*pFunc)(void*, void*);

	if(pArrayListSeleccion != NULL)
	{
		order = 1;

		pFunc = Seleccion_comparaById;

		ll_sort(pArrayListSeleccion, pFunc, order);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | PRINT - LIST 						========================== |

int Seleccion_print(eSeleccion* this)
{
	int toReturn = -1;

	int auxId;
	char auxPais[PAIS_LEN];
	char auxConfederacion[CONFEDERACION_LEN];
	int auxConvocados;

	if(this != NULL)
	{
		if(!Seleccion_getId(this, &auxId) && !Seleccion_getPais(this, auxPais) && !Seleccion_getConfederacion(this, auxConfederacion) && !Seleccion_getConvocados(this, &auxConvocados))
		{
			printf("|  %-4d  |  %-30s | %-30s | %-20d  | \n", auxId, auxPais, auxConfederacion, auxConvocados);

			toReturn = 0;
		}
	}

	return toReturn;
}

int Seleccion_list(LinkedList* pArrayListSeleccion, int option)
{
	int toReturn = -1;

	int i;
	int len;

	eSeleccion* this = NULL;

	if(pArrayListSeleccion != NULL)
	{
		len = ll_len(pArrayListSeleccion);

		if(len > 0)
		{
			if(option == 1)
			{
				Seleccion_sortById(pArrayListSeleccion);
			}

			printf("\n");
			fflush(stdin);

		    printf("===================================================================================================== \n");

			printf("| %-6s |  %-30s | %-30s |  %-20s | \n", "ID", "PAIS", "CONFEDERACION", "CONVOCADOS");

			//         	 ID            		PAIS              			CONFEDERACION   				CONVOCADOS
		    printf("|========|=================================|================================|=======================| \n");

		    for(i = 0; i < len; i++)
		    {
		    	this = (eSeleccion*) ll_get(pArrayListSeleccion, i);

		    	if(this != NULL)
		    	{
		    		if(Seleccion_print(this))
		    		{
		    			break;
		    		}
		    	}
		    }

		    if(i == len)
		    {
		    	toReturn = 0;

		    	printf("|________|_________________________________|________________________________|_______________________| \n");
		    }
		}
	}

	return toReturn;
}
