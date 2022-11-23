#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Controller.h"
#include "Jugador.h"
#include "menu.h"
#include "input.h"

// ==========================================================================================================================
// ==================== 					Funciones eJugador Basicas 					==========================

eJugador* Jugador_new()
{
	eJugador* this = NULL;

	this = (eJugador*) malloc(sizeof(eJugador));

	return this;
}

eJugador* Jugador_newParametros(int id, char* nombreCompletoStr, int edad, char* posicionStr, char* nacionalidadStr, int idSeleccion)
{
	eJugador* this = NULL;

	if(!isnan(id) && nombreCompletoStr != NULL && !isnan(edad) && posicionStr != NULL && nacionalidadStr != NULL && !isnan(idSeleccion))
	{
		this = Jugador_new();

		if(this != NULL)
		{
			/*
			 * ESTADO
			 * 		SET ID			 ====================== FUNCA SUPUESTAMENTE
			 * 		SET NOMBRE		 ====================== FUNCA SUPUESTAMENTE
			 * 		SET EDAD		 ====================== FUNCA SUPUESTAMENTE
			 * 		SET POSICION	 ====================== FUNCA SUPUESTAMENTE
			 * 		SET NACIONALIDAD ====================== FUNCA SUPUESTAMENTE
			 * 		SET ID SELECCION ====================== ARREGLADO | IF > 0 - MODIFICADO A IF > -1
			 */

			if(Jugador_setId(this, id) || Jugador_setNombreCompleto(this, nombreCompletoStr) || Jugador_setEdad(this, edad) ||
			   Jugador_setPosicion(this, posicionStr) || Jugador_setNacionalidad(this, nacionalidadStr) || Jugador_setIdSeleccion(this, idSeleccion))
			{
				Jugador_delete(this);

				this = NULL;
			}
		}
	}

	return this;
}

eJugador* Jugador_newParametrosAsText(char* idStr, char* nombreCompletoStr, char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	eJugador* this = NULL;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL)
	{
		this = Jugador_new();

		if(this != NULL)
		{
			//printf("\nPASA EL THIS != NULL DE newParametros.\n");

			/*
			 * SET ID TXT 				---- 	FUNCA SUPUESTAMENTE
			 * SET NOMBRE 				---- 	FUNCA SUPUESTAMENTE
			 * SET EDAD TXT 			---- 	FUNCA SUPUESTAMENTE
			 * SET POSICION 			---- 	FUNCA SUPUESTAMENTE
			 * SET NACIONALIDAD 		---- 	FUNCA SUPUESTAMENTE
			 * SET ID SELECCION TXT 	---- 	ARREGLADO | IF > 0 - MODIFICADO A IF > -1
			 */

			if(Jugador_setIdTxt(this, idStr) || Jugador_setNombreCompleto(this, nombreCompletoStr) || Jugador_setEdadTxt(this, edadStr) ||
			   Jugador_setPosicion(this, posicionStr) || Jugador_setNacionalidad(this, nacionalidadStr) || Jugador_setIdSeleccionTxt(this, idSeleccionStr))
			{
				Jugador_delete(this);

				this = NULL;
			}
		}
	}

	return this;
}

int Jugador_delete(eJugador* this)
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
// ==================== 		Funciones eJugador | Setter y Getter ID 				========================== | INT

int Jugador_setId(eJugador* this, int id)
{
	int toReturn = -1;

	if(this != NULL && !isnan(id))
	{
		this->id = id;

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_getId(eJugador* this, int* id)
{
	int toReturn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_setIdTxt(eJugador* this, char* idStr)
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

int Jugador_getIdTxt(eJugador* this, char* idStr)
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
// ==================== 		Funciones eJugador | Setter y Getter Nombre Completo 	========================== | CHAR *

int Jugador_setNombreCompleto(eJugador* this, char* nombreCompleto)
{
	int toReturn = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strncpy(this->nombreCompleto, nombreCompleto, NAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_getNombreCompleto(eJugador* this, char* nombreCompleto)
{
	int toReturn = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strncpy(nombreCompleto, this->nombreCompleto, NAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter Posicion 			========================== | CHAR *

int Jugador_setPosicion(eJugador* this, char* posicion)
{
	int toReturn = -1;

	if(this != NULL && posicion != NULL)
	{
		strncpy(this->posicion, posicion, POSITION_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_getPosicion(eJugador* this, char* posicion)
{
	int toReturn = -1;

	if(this != NULL && posicion != NULL)
	{
		strncpy(posicion, this->posicion, POSITION_LEN);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter Nacionalidad 		========================== | CHAR *

int Jugador_setNacionalidad(eJugador* this, char* nacionalidad)
{
	int toReturn = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strncpy(this->nacionalidad, nacionalidad, NATIONALITY_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_getNacionalidad(eJugador* this, char* nacionalidad)
{
	int toReturn = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strncpy(nacionalidad, this->nacionalidad, NATIONALITY_LEN);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter Edad 				========================== | INT

int Jugador_setEdad(eJugador* this, int edad)
{
	int toReturn = -1;

	if(this != NULL && !isnan(edad))
	{
		this->edad = edad;

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_getEdad(eJugador* this, int* edad)
{
	int toReturn = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_setEdadTxt(eJugador* this, char* edadStr)
{
	int toReturn = -1;

	int auxEdad;

	if(this != NULL && edadStr != NULL && isNumInt(edadStr, BUFFER_LEN) == 1)
	{
		auxEdad = atoi(edadStr);

		if(auxEdad > 0)
		{
			this->edad = auxEdad;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_getEdadTxt(eJugador* this, char* edadStr)
{
	int toReturn = -1;

	if(this != NULL && edadStr != NULL)
	{
		snprintf(edadStr, BUFFER_LEN, "%d", this->edad);

		toReturn = 0;
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter ID Seleccion 		========================== | INT

int Jugador_setIdSeleccion(eJugador* this, int idSeleccion)
{
	int toReturn = -1;

	if(this != NULL && !isnan(idSeleccion))
	{
		if(idSeleccion > -1)
		{
			this->idSeleccion = idSeleccion;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_getIdSeleccion(eJugador* this, int* idSeleccion)
{
	int toReturn = -1;

	if(this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_setIdSeleccionTxt(eJugador* this, char* idSeleccionStr)
{
	int toReturn = -1;

	int auxIdSeleccion;

	if(this != NULL && idSeleccionStr != NULL && isNumInt(idSeleccionStr, BUFFER_LEN) == 1)
	{
		auxIdSeleccion = atoi(idSeleccionStr);

		if(auxIdSeleccion > -1)
		{
			this->idSeleccion = auxIdSeleccion;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_getIdSeleccionTxt(eJugador* this, char* idSeleccionStr)
{
	int toReturn = -1;

	if(this != NULL && idSeleccionStr != NULL)
	{
		snprintf(idSeleccionStr, BUFFER_LEN, "%d", this->idSeleccion);

		toReturn = 0;
	}

	return toReturn;
}

/// ==========================================================================================================================
/// ==========================================================================================================================

// ==================== 		Funciones eJugador | Buscar Por ID 						========================== |

int Jugador_findJugadorPorId(LinkedList* pArrayListJugador, int id, int* index)
{
	int toReturn = -1;

	int i;
	int len;
	int auxId;

	eJugador* this = NULL;

	if(pArrayListJugador != NULL && index != NULL)
	{
		len = ll_len(pArrayListJugador);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (eJugador*) ll_get(pArrayListJugador, i);

				if(this != NULL && !Jugador_getId(this, &auxId))
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

int Jugador_comparaById(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxId1;
	int auxId2;

	eJugador* pJugador1 = NULL;
	eJugador* pJugador2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pJugador1 = (eJugador*) pElement1;
		pJugador2 = (eJugador*) pElement2;

		if(!Jugador_getId(pJugador1, &auxId1) && !Jugador_getId(pJugador2, &auxId2))
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

int Jugador_comparaByNombreCompleto(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxNombreCompleto1[NAME_LEN];
	char auxNombreCompleto2[NAME_LEN];

	int auxCmp;

	eJugador* pJugador1 = NULL;
	eJugador* pJugador2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pJugador1 = (eJugador*) pElement1;
		pJugador2 = (eJugador*) pElement2;

		if(!Jugador_getNombreCompleto(pJugador1, auxNombreCompleto1) && !Jugador_getNombreCompleto(pJugador2, auxNombreCompleto2))
		{
			auxCmp = strnicmp(auxNombreCompleto1, auxNombreCompleto2, NAME_LEN);

			if(auxCmp > 0)
			{
				// EL NOMBRE 1 ES MAYOR AL NOMBRE 2
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// LOS NOMBRES SON IGUALES
				toReturn = 0;
			}
			else
			{
				// EL NOMBRE 1 ES MENOR AL NOMBRE 2
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Jugador_comparaByEdad(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxEdad1;
	int auxEdad2;

	eJugador* pJugador1 = NULL;
	eJugador* pJugador2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pJugador1 = (eJugador*) pElement1;
		pJugador2 = (eJugador*) pElement2;

		if(!Jugador_getEdad(pJugador1, &auxEdad1) && !Jugador_getEdad(pJugador2, &auxEdad2))
		{
			if(auxEdad1 > auxEdad2)
			{
				// LA EDAD 1 ES MAYOR A LA EDAD 2.
				toReturn = 1;
			}
			else if(auxEdad1 == auxEdad2)
			{
				// LA EDAD 1 ES IGUAL A LA EDAD 2.
				toReturn = 0;
			}
			else
			{
				// LA EDAD 1 ES MENOR A LA EDAD 2.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Jugador_comparaByPosicion(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxPosicion1[POSITION_LEN];
	char auxPosicion2[POSITION_LEN];

	int auxCmp;

	eJugador* pJugador1 = NULL;
	eJugador* pJugador2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pJugador1 = (eJugador*) pElement1;
		pJugador2 = (eJugador*) pElement2;

		if(!Jugador_getPosicion(pJugador1, auxPosicion1) && !Jugador_getPosicion(pJugador2, auxPosicion2))
		{
			auxCmp = strnicmp(auxPosicion1, auxPosicion2, POSITION_LEN);

			if(auxCmp > 0)
			{
				// LA POSICION 1 ES MAYOR A LA POSICION 2
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// LAS POSICIONES SON IGUALES
				toReturn = 0;
			}
			else
			{
				// LA POSICION 1 ES MENOR A LA POSICION 2
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Jugador_comparaByNacionalidad(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxNacionalidad1[NATIONALITY_LEN];
	char auxNacionalidad2[NATIONALITY_LEN];

	int auxCmp;

	eJugador* pJugador1 = NULL;
	eJugador* pJugador2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pJugador1 = (eJugador*) pElement1;
		pJugador2 = (eJugador*) pElement2;

		if(!Jugador_getNacionalidad(pJugador1, auxNacionalidad1) && !Jugador_getNacionalidad(pJugador2, auxNacionalidad2))
		{
			auxCmp = strnicmp(auxNacionalidad1, auxNacionalidad2, NATIONALITY_LEN);

			if(auxCmp > 0)
			{
				// LA NACIONALIDAD 1 ES MAYOR A LA NACIONALIDAD 2
				toReturn = 1;
			}
			else if(auxCmp == 0)
			{
				// LOS NACIONALIDADES SON IGUALES
				toReturn = 0;
			}
			else
			{
				// LA NACIONALIDAD 1 ES MENOR A LA NACIONALIDAD 2
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int Jugador_comparaByIdSeleccion(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxIdSeleccion1;
	int auxIdSeleccion2;

	eJugador* pJugador1 = NULL;
	eJugador* pJugador2 = NULL;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pJugador1 = (eJugador*) pElement1;
		pJugador2 = (eJugador*) pElement2;

		if(!Jugador_getIdSeleccion(pJugador1, &auxIdSeleccion1) && !Jugador_getIdSeleccion(pJugador2, &auxIdSeleccion2))
		{
			if(auxIdSeleccion1 > auxIdSeleccion2)
			{
				// EL ID SELECCION 1 ES MAYOR AL ID SELECCION 2.
				toReturn = 1;
			}
			else if(auxIdSeleccion1 == auxIdSeleccion2)
			{
				// EL ID SELECCION 1 ES IGUAL AL ID SELECCION 2.
				toReturn = 0;
			}
			else
			{
				// EL ID SELECCION 1 ES MENOR AL ID SELECCION 2.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | ADD - EDIT - REMOVE 				========================== |

int Jugador_add(LinkedList* pArrayListJugador, int* id)
{
	int toReturn = -1;

	char auxNombreCompleto[NAME_LEN];
	int auxEdad;
	char auxPosicion[POSITION_LEN];
	char auxNacionalidad[NATIONALITY_LEN];
	int auxIdSeleccion = 0;

	eJugador* this = NULL;

	if(pArrayListJugador != NULL && id != NULL)
	{
		if(!getString(auxNombreCompleto, "\nIngrese el nombre completo del jugador: ", "\nError, vuelva a intentarlo: ", 1, NAME_LEN) &&
		   !getInt(&auxEdad, "\nIngrese la edad del jugador: ", "Error, solo numeros del 18 al 40. Vuelva a intentarlo: ", 18, 40) &&
		   !getString(auxPosicion, "\nIngrese la posicion del jugador: ", "\nError, vuelva a intentarlo: ", 3, POSITION_LEN) &&
		   !getString(auxNacionalidad, "\nIngrese la nacionalidad del jugador: ", "\nError, vuelva a intentarlo: ", 3, NATIONALITY_LEN))
		{
			this = Jugador_newParametros(*id + 1, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);

			if(this != NULL)
			{
				(*id)++;

				ll_add(pArrayListJugador, this);

				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int Jugador_edit(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int auxId;
	int answer;
	int indexJugador;
	int indexSeleccion;

	int len;

	int auxIdSeleccion;

	int auxReturn;

	eJugador* this = NULL;
	eSeleccion* this2 = NULL;

	if(pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);

		if(!getInt(&auxId, "\nIngrese la ID del jugador a modificar: ", "\nError, vuelva a intentarlo: ", 1, len))
		{
			if(!Jugador_findJugadorPorId(pArrayListJugador, auxId, &indexJugador))
			{
				this = (eJugador*) ll_get(pArrayListJugador, indexJugador);

				Jugador_getIdSeleccion(this, &auxIdSeleccion);

				if(this != NULL)
				{
			    	if(auxIdSeleccion == 0)
			    	{
			    		Seleccion_setPais(this2, "No convocado");
			    		this2 = (eSeleccion*) ll_get(pArrayListSeleccion, auxIdSeleccion);
			    	}
			    	else
			    	{
			    		Seleccion_findSeleccionPorId(pArrayListSeleccion, auxIdSeleccion, &indexSeleccion);

			    		this2 = (eSeleccion*) ll_get(pArrayListSeleccion, auxIdSeleccion);
			    	}

				    printf("============================================================================================================================================= \n");

					printf("| %-8s |  %-40s | %-8s |  %-24s | %-20s | %-20s | \n", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "SELECCION");

					//         	 ID            NOMBRE COMPLETO              			EDAD     	 	POSICION   				NACIONALIDAD    		ID SELECCION
				    printf("|==========|===========================================|==========|===========================|======================|======================| \n");
				    Jugador_printConSeleccion(this, this2);
				    printf("|__________|___________________________________________|__________|___________________________|______________________|______________________| \n");

				    printf("\n");
				    printf("0 = NO.\n");
				    printf("1 = SI.\n");

				    if(!getInt(&answer, "\nEsta seguro de modificar a este jugador?: ", "\nError, solo 0 o 1. Vuelva a intentarlo: ", 0, 1))
				    {
				    	switch(answer)
				    	{
				    	case 0:
				    		// EL USUARIO CANCELO EL MODIFICAR
				    		toReturn = 2;
				    		break;

				    	case 1:
				    		// EL USUARIO CONTINUO CON EL MODIFICAR
				    		auxReturn = Jugador_showModMenu(pArrayListJugador, this);

							if(auxReturn == 0)
							{
								// SE REALIZO LA MODIFICACION
								toReturn = 0;
							}
							else if(auxReturn == 1)
							{
								// EL USUARIO NO MODIFICO NADA
								toReturn = 1;
							}
				    		break;
				    	}
				    }
				}
			}
		}
	}

	return toReturn;
}

int Jugador_remove(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int auxId;
	int answer;
	int indexJugador;
	int indexSeleccion;

	int len;

	int auxIdSeleccion;

	eJugador* this = NULL;
	eSeleccion* this2 = NULL;

	if(pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);

		if(!getInt(&auxId, "\nIngrese la ID del jugador a eliminar: ", "\nError, vuelva a intentarlo: ", 1, len))
		{
			if(!Jugador_findJugadorPorId(pArrayListJugador, auxId, &indexJugador))
			{
				this = (eJugador*) ll_get(pArrayListJugador, indexJugador);

				Jugador_getIdSeleccion(this, &auxIdSeleccion);

				if(this != NULL)
				{
			    	if(auxIdSeleccion == 0)
			    	{
			    		Seleccion_setPais(this2, "No convocado");
			    		this2 = (eSeleccion*) ll_get(pArrayListSeleccion, auxIdSeleccion);
			    	}
			    	else
			    	{
			    		Seleccion_findSeleccionPorId(pArrayListSeleccion, auxIdSeleccion, &indexSeleccion);

			    		this2 = (eSeleccion*) ll_get(pArrayListSeleccion, auxIdSeleccion);
			    	}

				    printf("============================================================================================================================================= \n");

					printf("| %-8s |  %-40s | %-8s |  %-24s | %-20s | %-20s | \n", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "SELECCION");

					//         	 ID            NOMBRE COMPLETO              			EDAD     	 	POSICION   				NACIONALIDAD    		ID SELECCION
				    printf("|==========|===========================================|==========|===========================|======================|======================| \n");
				    Jugador_printConSeleccion(this, this2);
				    printf("|__________|___________________________________________|__________|___________________________|______________________|______________________| \n");

				    printf("\n");
				    printf("0 = NO.\n");
				    printf("1 = SI.\n");

				    if(!getInt(&answer, "\nEsta seguro de eliminar a este jugador?: ", "\nError, solo 0 o 1. Vuelva a intentarlo: ", 0, 1))
				    {
				    	switch(answer)
				    	{
							case 0:
								// EL USUARIO CANCELO LA BAJA
								toReturn = 1;
								break;

							case 1:
								Jugador_delete(this);
								ll_remove(pArrayListJugador, indexJugador);

								if(auxIdSeleccion != 0 && !Seleccion_edit(pArrayListSeleccion, auxIdSeleccion, 2))
								{
									toReturn = 0;
								}
								else
								{
									toReturn = 0;
								}
								break;
				    	}
				    }
				}
			}
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | SORT 		 						========================== |

int Jugador_sort(LinkedList* pArrayListJugador)
{
	int toReturn = -1;

	int option;
	int orderOption;

	int order;

	int (*pFunc)(void*, void*);

	if(pArrayListJugador != NULL)
	{
		do
		{
			if(!Menu_sortJugador(&option))
			{
				switch(option)
				{
					case 1:
						// ORDENAR POR NACIONALIDAD
						pFunc = Jugador_comparaByNacionalidad;
						break;

					case 2:
						// ORDENAR POR EDAD
						pFunc = Jugador_comparaByEdad;
						break;

					case 3:
						// ORDENAR POR NOMBRE
						pFunc = Jugador_comparaByNombreCompleto;
						break;

					case 4:
						// SALIR
						printf("\nSaliendo del sub-menu de ordenamiento de jugadores.\n");

						if(toReturn != 0)
						{
							toReturn = 1;
						}
						break;

					default:
						printf("\nError, se ha ingreado un valor invalido.\n");
						break;
				}
			}
		}while(option != 1 && option != 2 && option != 3 && option != 4);

		if(option != 4)
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
							printf("\nError, se ha ingreado un valor invalido.\n");
							break;
					}
				}
			}while(orderOption != 1 && orderOption != 2);

			ll_sort(pArrayListJugador, pFunc, order);

			toReturn = 0;
		}
	}

	return toReturn;
}


// ==========================================================================================================================
// ==================== 		Funciones eJugador | PRINT - LIST 						========================== |

int Jugador_print(eJugador* this)
{
	int toReturn = -1;

	int auxId;
	char auxNombreCompleto[NAME_LEN];
	int auxEdad;
	char auxPosicion[POSITION_LEN];
	char auxNacionalidad[NATIONALITY_LEN];
	int auxIdSeleccion;

	if(this != NULL)
	{
		if(!Jugador_getId(this, &auxId) && !Jugador_getNombreCompleto(this, auxNombreCompleto) && !Jugador_getEdad(this, &auxEdad) &&
		   !Jugador_getPosicion(this, auxPosicion) && !Jugador_getNacionalidad(this, auxNacionalidad) && !Jugador_getIdSeleccion(this, &auxIdSeleccion))
		{
			printf("|  %-6d  |  %-40s | %-8d | %-24s  | %-20s | %-20d | \n", auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);

			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_printConSeleccion(eJugador* this, eSeleccion* this2)
{
	int toReturn = -1;

	int auxId;
	char auxNombreCompleto[NAME_LEN];
	int auxEdad;
	char auxPosicion[POSITION_LEN];
	char auxNacionalidad[NATIONALITY_LEN];

	char auxPais[PAIS_LEN];

	if(this != NULL)
	{
		if(!Jugador_getId(this, &auxId) && !Jugador_getNombreCompleto(this, auxNombreCompleto) && !Jugador_getEdad(this, &auxEdad) &&
		   !Jugador_getPosicion(this, auxPosicion) && !Jugador_getNacionalidad(this, auxNacionalidad) && !Seleccion_getPais(this2, auxPais))
		{
			printf("|  %-6d  |  %-40s | %-8d | %-24s  | %-20s | %-20s | \n", auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxPais);

			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_list(LinkedList* pArrayListJugador)
{
	int toReturn = -1;

	int i;
	int len;

	eJugador* this = NULL;

	if(pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);

		if(len > 0)
		{
			printf("\n");
			fflush(stdin);

		    printf("============================================================================================================================================= \n");

			printf("| %-8s |  %-40s | %-8s |  %-24s | %-20s | %-20s | \n", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "ID SELECCION");

			//         	 ID            NOMBRE COMPLETO              			EDAD     	 	POSICION   				NACIONALIDAD    		ID SELECCION
		    printf("|==========|===========================================|==========|===========================|======================|======================| \n");

		    for(i = 0; i < len; i++)
		    {
		    	this = (eJugador*) ll_get(pArrayListJugador, i);

		    	if(this != NULL)
		    	{
		    		if(Jugador_print(this))
		    		{
		    			break;
		    		}
		    	}
		    }

		    if(i == len)
		    {
		    	toReturn = 0;

		    	printf("|__________|___________________________________________|__________|___________________________|______________________|______________________| \n");
		    }
		}
	}

	return toReturn;
}

int Jugador_listConSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int i;
	int a;
	int lenJugador;
	int lenSeleccion;

	int auxIdSeleccion;

	eJugador* this = NULL;
	eSeleccion* this2 = NULL;

	if(pArrayListJugador != NULL)
	{
		lenJugador = ll_len(pArrayListJugador);
		lenSeleccion = ll_len(pArrayListSeleccion);

		if(lenJugador > 0 && lenSeleccion > 0)
		{
			printf("\n");
			fflush(stdin);

		    printf("============================================================================================================================================= \n");

			printf("| %-8s |  %-40s | %-8s |  %-24s | %-20s | %-20s | \n", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "SELECCION");

			//         	 ID            NOMBRE COMPLETO              			EDAD     	 	POSICION   				NACIONALIDAD    		ID SELECCION
		    printf("|==========|===========================================|==========|===========================|======================|======================| \n");

		    for(i = 0; i < lenJugador; i++)
		    {
		    	this = (eJugador*) ll_get(pArrayListJugador, i);

		    	Jugador_getIdSeleccion(this, &auxIdSeleccion);

			    for(a = 0; a < lenSeleccion; a++)
			    {
			    	this2 = (eSeleccion*) ll_get(pArrayListSeleccion, a);

			    	if(auxIdSeleccion == 0)
			    	{
			    		if(!Seleccion_setPais(this2, "No convocado"))
			    		{
			    			break;
			    		}
			    	}
			    	else
			    	{
			    		this2 = (eSeleccion*) ll_get(pArrayListSeleccion, auxIdSeleccion);
			    	}
			    }

				if(this != NULL && this != NULL)
				{
					if(Jugador_printConSeleccion(this, this2))
					{
						break;
					}
				}
		    }

		    if(i == lenJugador)
		    {
		    	toReturn = 0;

		    	printf("|__________|___________________________________________|__________|___________________________|______________________|______________________| \n");
		    }
		}
	}

	return toReturn;
}

int Jugador_listarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int i;
	int a;
	int lenJugador;
	int lenSeleccion;

	int auxIdSeleccion;

	eJugador* this = NULL;
	eSeleccion* this2 = NULL;

	if(pArrayListJugador != NULL)
	{
		lenJugador = ll_len(pArrayListJugador);
		lenSeleccion = ll_len(pArrayListSeleccion);

		if(lenJugador > 0 && lenSeleccion > 0)
		{
			printf("\n");
			fflush(stdin);

		    printf("============================================================================================================================================= \n");

			printf("| %-8s |  %-40s | %-8s |  %-24s | %-20s | %-20s | \n", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "SELECCION");

			//         	 ID            NOMBRE COMPLETO              			EDAD     	 	POSICION   				NACIONALIDAD    		ID SELECCION
		    printf("|==========|===========================================|==========|===========================|======================|======================| \n");

		    for(i = 0; i < lenJugador; i++)
		    {
		    	this = (eJugador*) ll_get(pArrayListJugador, i);

		    	Jugador_getIdSeleccion(this, &auxIdSeleccion);

			    for(a = 0; a < lenSeleccion; a++)
			    {
			    	this2 = (eSeleccion*) ll_get(pArrayListSeleccion, a);

			    	if(auxIdSeleccion == 0)
			    	{
			    		break;
			    	}
			    	else
			    	{
			    		this2 = (eSeleccion*) ll_get(pArrayListSeleccion, auxIdSeleccion);
			    	}

					if(this != NULL && this != NULL)
					{
						if(auxIdSeleccion == 0 || !Jugador_printConSeleccion(this, this2))
						{
							break;
						}
					}
			    }
		    }

		    if(i == lenJugador)
		    {
		    	toReturn = 0;

		    	printf("|__________|___________________________________________|__________|___________________________|______________________|______________________| \n");
		    }
		}
	}

	return toReturn;
}



// ==========================================================================================================================
// ==================== 		Funciones eJugador | CONVOCAR 							========================== |

int Jugador_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int idJugador, int idSeleccion)
{
	int toReturn = -1;

	int indexJugador;
	int indexSeleccion;

	eJugador* this = NULL;
	eSeleccion* this2 = NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		if(!Jugador_findJugadorPorId(pArrayListJugador, idJugador, &indexJugador) &&
		   !Seleccion_findSeleccionPorId(pArrayListSeleccion, idSeleccion, &indexSeleccion))
		{
			this = (eJugador*) ll_get(pArrayListJugador, indexJugador);
			this2 = (eSeleccion*) ll_get(pArrayListSeleccion, indexSeleccion);

			if(this != NULL && this2 != NULL)
			{
				if(!Jugador_setIdSeleccion(this, indexSeleccion))
				{
					toReturn = 0;
				}
			}
		}
	}

	return toReturn;
}

int Jugador_quitarConvocacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int option;

	int indexJugador;

	int auxIdSelecicon;

	eJugador* this = NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		if(!Jugador_listarConvocados(pArrayListJugador, pArrayListSeleccion))
		{
			if(!getInt(&option, "\nElija el jugador al cual se le quitara la convocatoria: ", "\nError, vuelva a intentarlo: ", 1, 1000))
			{
				if(!Jugador_findJugadorPorId(pArrayListJugador, option, &indexJugador))
				{
					this = (eJugador*) ll_get(pArrayListJugador, indexJugador);

					if(this != NULL)
					{
						if(!Jugador_getIdSeleccion(this, &auxIdSelecicon))
						{
							if(!Jugador_setIdSeleccion(this, 0) && !Seleccion_edit(pArrayListSeleccion, auxIdSelecicon, 2))
							{
								toReturn = 0;
							}
						}
					}
				}
			}
			else
			{
				// NO SE ENCONTRO AL ID INGRESADO
				toReturn = -2;
			}
		}
	}

	return toReturn;
}

// ==========================================================================================================================
// ==================== 		Funciones eJugador | MENUS 						========================== |

int Jugador_showModMenu(LinkedList* pArrayListJugador, eJugador* this)
{
	int toReturn = -1;

	char auxNombreCompleto[NAME_LEN];
	int auxEdad;
	char auxPosicion[POSITION_LEN];
	char auxNacionalidad[NATIONALITY_LEN];

	int option;

	int flag = FALSE;

	if(pArrayListJugador != NULL && this != NULL)
	{
		do
		{
			if(!Menu_modMenu(&option))
			{
				switch(option)
				{
					case 1:
						// MODIFICAR NOMBRE
						if(!getString(auxNombreCompleto, "\nIngrese el nuevo nombre completo: ", "\nError, vuelva a intentarlo", 3, NAME_LEN) &&
						   !Jugador_setNombreCompleto(this, auxNombreCompleto))
						{
							flag = TRUE;
						}
						break;

					case 2:
						// MODIFICAR EDAD
						if(!getInt(&auxEdad, "\nIngrese la nueva edad del jugador: ", "\nError, solo numeros del 18 al 40. Vuelva a intentarlo", 18, 40) &&
						   !Jugador_setEdad(this, auxEdad))
						{
							flag = TRUE;
						}
						break;

					case 3:
						// MODIFICAR POSICION
						if(!getString(auxPosicion, "\nIngrese la nueva posicion del jugador: ", "\nError, vuelva a intentarlo: ", 3, POSITION_LEN) &&
						   !Jugador_setPosicion(this, auxPosicion))
						{
							flag = TRUE;
						}
						break;

					case 4:
						// MODIFICAR NACIONALIDAD
						if(!getString(auxNacionalidad, "\nIngrese la nueva nacionalidad del jugador: ", "\nError, vuelva a intentarlo: ", 3, NATIONALITY_LEN) &&
						   !Jugador_setNacionalidad(this, auxNacionalidad))
						{
							flag = TRUE;
						}
						break;

					case 5:
						// SALIR
						printf("\nSaliendo del sub-menu de modificacion.\n");
						if(!flag)
						{
							toReturn = 1;
						}
						break;

					default:
						// ERROR
						printf("\nError, se ha ingresado un valor invalido.\n");
						break;
				}
			}
    		printf("\n");
    		//clearScreen();

    		system("pause");
    		system("cls");
		}while(option != 5);

		if(flag != FALSE)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_showListMenu(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int option;
	int optionSeleccion;

	do
	{
		if(!Menu_listadosMenu(&option))
		{
			switch(option)
			{
				case 1:
					// TODOS LOS JUGADORES
					if(!Jugador_listConSeleccion(pArrayListJugador, pArrayListSeleccion))
					{
						toReturn = 0;
					}
					break;

				case 2:
					// TODOS LAS SELECCIONES
					printf("\nDesea mostrar la lista de selecciones ordenada por id? (SI = 1) (NO = 0).\n");
					getInt(&optionSeleccion, "\nTenga en cuenta que esto sobreescibe cualquier otro ordenamiento realizado con anterioridad: ", "\nError, solo 0 o 1. Vuelva a intentarlo: ", 0, 1);
					if(!Seleccion_list(pArrayListSeleccion, optionSeleccion))
					{
						toReturn = 0;
					}
					break;

				case 3:
					// CONVOCADOS
					if(Jugador_listarConvocados(pArrayListJugador, pArrayListSeleccion))
					{
						toReturn = 0;
					}
					break;

				case 4:
					// SALIR
					printf("\nSaliendo del sub-menu listar...\n");

					if(toReturn != 0)
					{
						toReturn = 1;
					}
					break;

				default:
					// ERROR
					printf("\nError, se ha ingresado un valor invalido.\n");
					break;
			}
		}
		printf("\n");
		//clearScreen();

		system("pause");
		system("cls");
	}while(option != 4);

	return toReturn;
}

int Jugador_showSortMenu(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int option;

	int auxReturn;

	do
	{
		if(!Menu_sortMenuPrincipal(&option))
		{
			switch(option)
			{
				case 1:
					// ORDENAMIENTOS DE JUGADORES
					auxReturn = Jugador_sort(pArrayListJugador);

					Jugador_listConSeleccion(pArrayListJugador, pArrayListSeleccion);

					switch(auxReturn)
					{
						case -1:
							toReturn = -1;
							break;

						case 0:
							toReturn = 0;
							break;

						case 1:
							toReturn = 1;
							break;

						default:
							// ERROR
							printf("\nError, se ha ingresado un valor invalido.\n");
							break;
					}
					break;

				case 2:
					// ORDENAR SELECCIONES POR CONFEDERACION
					if(!Seleccion_sort(pArrayListSeleccion) && !Seleccion_list(pArrayListSeleccion, 0))
					{
						toReturn = 0;
					}
					break;

				case 3:
					// SALIR
					printf("\nSaliendo del sub-menu de ordenamientos.\n");
					if(toReturn != 0)
					{
						toReturn = 1;
					}
					break;

				default:
					// ERROR
					printf("\nError, se ha ingresado un valor invalido.\n");
					break;
			}
		}
		printf("\n");
		//clearScreen();

		system("pause");
		system("cls");
	}while(option != 3);


	return toReturn;
}

int Jugador_showConvocarMenu(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int option;
	int optionSeleccion;

	int idJugador;
	int idSeleccion;

	int lenJugador;
	int lenSeleccion;

	do
	{
		lenJugador = ll_len(pArrayListJugador);
		lenSeleccion = ll_len(pArrayListSeleccion);

		if(!Menu_convocarMenu(&option))
		{
			switch(option)
			{
				case 1:
					// CONVOCAR
					if(!Jugador_listConSeleccion(pArrayListJugador, pArrayListSeleccion) &&
					   !getInt(&idJugador, "\nElija al jugador a convocar: ", "\nError, vuelva a intentarlo: ", 1, lenJugador))
					{
						printf("\nDesea mostrar la lista de selecciones ordenada por id? (SI = 1) (NO = 0).\n");
						getInt(&optionSeleccion, "\nTenga en cuenta que esto sobreescibe cualquier otro ordenamiento realizado con anterioridad: ", "\nError, solo 0 o 1. Vuelva a intentarlo: ", 0, 1);

						if(!Seleccion_list(pArrayListSeleccion, optionSeleccion) &&
						   !getInt(&idSeleccion, "\nElija la seleccion que convoca al jugador: ", "\nError, vuelva a intentarlo: ", 1, lenSeleccion))
						{
							if(!Jugador_convocar(pArrayListJugador, pArrayListSeleccion, idJugador, idSeleccion))
							{
								toReturn = 0;
							}
						}
					}
					break;

				case 2:
					// QUITAR CONVOCATORIA
					if(!Jugador_quitarConvocacion(pArrayListJugador, pArrayListSeleccion))
					{
						toReturn = 0;
					}
					break;

				case 3:
					// SALIR
					printf("\nSaliendo del sub-menu de convocar jugadores...\n");
					if(toReturn != 0)
					{
						toReturn = 1;
					}
					break;

				default:
					// ERROR
					printf("\nError, se ha ingresado un valor invalido.\n");
					break;
			}
		}
		printf("\n");
		//clearScreen();

		system("pause");
		system("cls");
	}while(option != 3);

	return toReturn;
}

