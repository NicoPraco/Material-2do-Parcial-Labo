/*
 * confederacion.c
 *
 *  Created on: 18 oct. 2022
 *      Author: kualo
 */

#include "confederacion.h"

// ==========================================================================================================================
// ==================== Funciones eConfederacion Basicas ==========================

int Confederacion_inicializarConfederacion(eConfederacion* list, int len)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		toReturn = 0;
	}

	return toReturn;
}

int Confederacion_hardcode(eConfederacion* list, int len, int* id)
{
	int toReturn = -1;

	int i;
	int cant;
	int index;

	int flag = FALSE;

	eConfederacion auxConfederacion[] =
	{
			{0, "CONMEBOL", "Sudamerica", 				1916, FALSE},
			{0, "UEFA", 	"Europa", 					1954, FALSE},
			{0, "AFC", 		"Asia", 					1954, FALSE},
			{0, "CAF", 		"Africa", 					1957, FALSE},
			{0, "CONCACAF", "Norte y Centro America", 	1961, FALSE},
			{0, "OFC", 		"Oceania", 					1966, FALSE}
	};

	if(list != NULL && len > 0 && id != NULL)
	{
		cant = sizeof(auxConfederacion) / sizeof(eConfederacion);

		if(cant <= len)
		{
			for(i = 0; i < cant; i++)
			{
				if(!Confederacion_buscarLibre(list, len, &index))
				{
					list[index] = auxConfederacion[i];
					list[index].id = *id;

					(*id)++;

					flag = TRUE;
				}
			}

			if(flag)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int Confederacion_buscarPorId(eConfederacion* list, int len, int id)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && id > 0 && id < len)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				toReturn = i;
				break;
			}
		}
	}

	return toReturn;
}

int Confederacion_buscarLibre(eConfederacion* list, int len, int* index)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && index != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				toReturn = 0;
				*index = i;
				break;
			}
		}
	}


	return toReturn;
}

int Confederacion_arrayIsEmpty(eConfederacion* list, int len)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}

// ==================== Funciones eConfederacion Carga ==========================

int Confederacion_cargarUno(eConfederacion* list, int len, int* id)
{
	int toReturn = -1;

	char nombre[LENGHT_NOMBRE];
	char region[LENGHT_REGION];
	int anioCreacion;

	if(list != NULL && len > 0 && id != NULL)
	{
		if(!getString(nombre, "\nIngrese el nombre de la confederacion", "\nError, vuelva a intentarlo: ", 1, LENGHT_NOMBRE) &&
		   !getString(region, "\nIngrese la region a donde pertenece la confederacion: ", "Error, vuelva a intentarlo: ", 1, LENGHT_REGION) &&
		   !getInt(&anioCreacion, "\nIngrese el año de creacion de la confederacion: ", "Error, vuelva a intentarlo: ", 1900, 2022) &&
		   !Confederacion_cargarEnArray(list, len, *id, nombre, region, anioCreacion))
		{
			(*id)++;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Confederacion_cargarEnArray(eConfederacion* list, int len, int id, char nombre[], char region[], int anioCreacion)
{
	int toReturn = -1;

	int index;

	if(list != NULL && len > 0)
	{
		if(!Confederacion_buscarLibre(list, len, &index))
		{
			list[index].id = id;
			strncpy(list[index].nombre, nombre, LENGHT_NOMBRE);
			strncpy(list[index].region, region, LENGHT_REGION);
			list[index].anioCreacion = anioCreacion;

			toReturn = 0;
		}
	}

	return toReturn;
}

// ==================== Funciones eConfederacion Baja ==========================

int Confederacion_baja(eConfederacion* list, int len, int id)
{
	int toReturn = -1;

	int index;
	int respuesta;

	if(list != NULL && len > 0)
	{
		index = Confederacion_buscarPorId(list, len, id);

		if(index > -1)
		{
			printf("\t BAJA DE UNA CONFEDERACION \n\n");
		    printf("======================================================================= \n");
			printf("| %2s  |  %8s     |      %12s \t     |  %7s  | \n", "ID", "NOMBRE", "REGION", "AÑO CREACION");
			//         ID       NOMBRE        			REGION      		AÑO CREACION
		    printf("|=====|===============|==============================|================| \n");
			Confederacion_mostrarUnaConfederacion(&list[index]);

	    	printf("|_____|_______________|______________________________|________________| \n");

			printf("\n");
			printf("0 = NO.\n");
			printf("1 = SI.\n");

			if(!getInt(&respuesta, "\nEsta seguro de eliminar a esta confederacion? ", "Error, solo 0 o 1. Vuelva a intentarlo: ", 0, 1))
			{
				switch(respuesta)
				{
					case 0:
						// EL USUARIO CANCELO LA BAJA
						toReturn = 1;
						break;

					case 1:
						list[index].isEmpty = TRUE;

						toReturn = 0;
						break;

					default:
						printf("\n\aError, ha ingresado un valor invalido.\n");
						break;

				}
			}

		}
	}

	return toReturn;
}

// ==================== Funciones eConfederacion Modificar ==========================

int Confederacion_modificarConfederacion(eConfederacion* list, int len, int index)
{
	int toReturn = -1;

	int option;
	int flag = FALSE;

	eConfederacion auxConfederacion;

	if(list != NULL && len > 0 && index > -1)
	{
		do
		{
			if(!Menu_modificarConfederacion(&option))
			{
				switch(option)
				{
					case 1:
						// MOD NOMBRE
						if(!getString(auxConfederacion.nombre, "\nIngrese el nuevo nombre de la confederacion: ", "\nError, vuelva a intentarlo: ", 1, LENGHT_NOMBRE))
						{
							strncpy(list[index].nombre, auxConfederacion.nombre, LENGHT_NOMBRE);

							flag = TRUE;
						}
						break;

					case 2:
						// MOD REGION
						if(!getString(auxConfederacion.region, "\nIngrese la nueva region de la confederacion: ", "\nError, vuelva a intentarlo: ", 1, LENGHT_REGION))
						{
							strncpy(list[index].region, auxConfederacion.region, LENGHT_REGION);

							flag = TRUE;
						}
						break;

					case 3:
						// MOD AÑO
						if(!getInt(&auxConfederacion.anioCreacion, "\nIngrese el nuevo año de creacion de la confederacion: ", "\nError, vuelva a intentarlo: ", 1900, 2022))
						{
							list[index].anioCreacion = auxConfederacion.anioCreacion;

							flag = TRUE;
						}
						break;

					case 4:
						// SALIR
						printf("\nSaliendo del sub-menu modificar confederacion. \n");

						flag = TRUE;
						break;

					default:
						// ERRROR
						printf("\a\nError, ha ingresado un valor invalido. \n");
						break;
				}

				printf("\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}

		}while(option != 4);

		if(flag)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}
int Confederacion_modificar(eConfederacion* list, int len, int id)
{
	int toReturn = -1;

	int index;
	int respuesta;

	int auxReturn;

	if(list != NULL && len > 0)
	{
		index = Confederacion_buscarPorId(list, len, id);

		if(index > -1)
		{
			printf("\t MODIFICAR DE UNA CONFEDERACION \n\n");
		    printf("======================================================================= \n");
			printf("| %2s  |  %8s     |      %12s \t     |  %7s  | \n", "ID", "NOMBRE", "REGION", "AÑO CREACION");
			//         ID       NOMBRE        			REGION      		AÑO CREACION
		    printf("|=====|===============|==============================|================| \n");
			Confederacion_mostrarUnaConfederacion(&list[index]);

	    	printf("|_____|_______________|______________________________|________________| \n");

			printf("\n");
			printf("0 = NO.\n");
			printf("1 = SI.\n");

			if(!getInt(&respuesta, "\nEsta seguro de modificar a esta confederacion? ", "Error, solo 0 o 1. Vuelva a intentarlo: ", 0, 1))
			{
				switch(respuesta)
				{
					case 0:
						// EL USUARIO CANCELO LA MODIFICACION
						toReturn = 1;
						break;

					case 1:
						auxReturn = Confederacion_modificarConfederacion(list, len, index);

						printf("\nAUX RETURN FUNCION: %d.\n", auxReturn);

						if(auxReturn == 0)
						{
							toReturn = 0;
						}
						else
						{
							// ERROR
							toReturn = -1;
						}
						break;


					default:
						printf("\n\aError, ha ingresado un valor invalido.\n");
						break;
				}
			}
		}
	}

	return toReturn;
}

// ==================== Funciones eConfederacion Mostrar ==========================

int Confederacion_mostrarUnaConfederacion(eConfederacion* unaConfederacion)
{
	int toReturn = -1;

	if(unaConfederacion != NULL)
	{
		printf("|  %d  |  %-10s   | %-22s       |     %d       | \n", unaConfederacion->id, unaConfederacion->nombre, unaConfederacion->region, unaConfederacion->anioCreacion);

		toReturn = 0;
	}
	return toReturn;
}

int Confederacion_mostrarConfederaciones(eConfederacion* listConfederacion, int len)
{
	int toReturn = -1;

	int i;
	int flag = FALSE;

	if(listConfederacion != NULL && len > 0)
	{
	    printf("======================================================================= \n");

		printf("| %2s  |  %8s     |      %12s \t     |  %7s  | \n", "ID", "NOMBRE", "REGION", "AÑO CREACION");

		//         ID       NOMBRE        			REGION      		AÑO CREACION
	    printf("|=====|===============|==============================|================| \n");
	    for(i = 0; i < len; i++)
	    {
	    	if(listConfederacion[i].isEmpty == FALSE && !Confederacion_mostrarUnaConfederacion(&listConfederacion[i]))
	    	{
	    		//printf("|_____|_______________|______________________________|________________| \n");

	    		flag = TRUE;
	    	}
	    }

	    if(flag)
	    {
	    	printf("|_____|_______________|______________________________|________________| \n");

	    	toReturn = 0;
	    }
	}

	return toReturn;
}
