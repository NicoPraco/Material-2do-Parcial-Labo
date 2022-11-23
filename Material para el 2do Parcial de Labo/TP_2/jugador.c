/*
 * jugador.c
 *
 *  Created on: 15 oct. 2022
 *      Author: kualo
 */

#include "jugador.h"

// ==================== Funciones eJugador Basicas ==========================

int Jugador_inicializarJugadores(eJugador* list, int len)
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

//{0, "CONMEBOL", "Sudamerica", 				1916, FALSE},
//{0, "UEFA", 	"Europa", 					1954, FALSE},
//{0, "AFC", 		"Asia", 					1954, FALSE},
//{0, "CAF", 		"Africa", 					1957, FALSE},
//{0, "CONCACAF", "Norte y Centro America", 	1961, FALSE},
//{0, "OFC", 		"Oceania", 					1966, FALSE}

int Jugador_hardcode(eJugador* list, int len, int* id)
{
	int toReturn = -1;

	int i;
	int cant;
	int index;

	int flag = FALSE;

	eJugador auxJugador[] =
	{
		{0, "Lionel Messi", 			"Delantero", 	10, 2, 200000.00, 	4,	FALSE},
		{0, "Giovanildo Vieira (Hulk)", "Delantero", 	7, 	1, 100000.00, 	3,	FALSE},
		{0, "Mohamed El Shenawy", 		"Arquero", 		1, 	4,  80000.00, 	2,	FALSE},
		{0, "Enzo Coppeti", 			"Delantero", 	9, 	1,  86000.00, 	4,	FALSE}
	};

	if(list != NULL && len > 0 && id != NULL)
	{
		cant = sizeof(auxJugador) / sizeof(eJugador);

		if(cant <= len)
		{
			for(i = 0; i < cant; i++)
			{
				if(!Jugador_buscarLibre(list, len, &index))
				{
					list[i] = auxJugador[i];
					list[i].id = *id;

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
int Jugador_buscarPorID(eJugador* list, int len, int id)
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

int Jugador_buscarLibre(eJugador* list, int len, int* index)
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

int Jugador_arrayIsEmpty(eJugador* list, int len)
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

// ==================== Funciones eJugador Carga ==========================

int Jugador_cargarUno(eJugador* list, int len, int* id)
{
	int toReturn = -1;

	int index;

	char nombre[PLAYER_NAME_LENGHT];
	char posicion[PLAYER_POSITION_LENGHT];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;

	int posicionElegida;

	if(list != NULL && len > 0 && id != NULL)
	{
		if(!Jugador_buscarLibre(list, len, &index) &&
		   !getString(nombre, "\nIngrese el nombre del jugador: ", "\nError, vuelva a intentarlo: ", 1, PLAYER_NAME_LENGHT) &&
		   !Menu_posicionJugador(&posicionElegida) && !Jugador_cargarPosicion(posicion, posicionElegida) &&
		   !getShort(&numeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "\nError,", 1, 99) &&
		   !Menu_confederacionJugador(&idConfederacion) &&
		   !getFloat(&salario, "\nIngrese el salario del jugador: ", "\nError, solo numeros entre 1 y 1.000.000", 1, 1000000) &&
		   !getShort(&aniosContrato, "\nIngrese los años de contrato del jugador: ", "\nError, solo numeros del 1 al 20. Vuelva a intentarlo: ", 1, 20) &&
		   !Jugador_cargarEnArray(list, len, *id, nombre, posicion, numeroCamiseta, idConfederacion, salario, aniosContrato, index))
		{
			(*id)++;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_cargarEnArray(eJugador* list, int len, int id, char nombre[], char posicion[], short numeroCamiseta, int idConfederacion, float salario, short aniosContrato, int index)
{
	int toReturn = -1;

	if(list != NULL && len > 0)
	{
		list[index].id = id;
		strncpy(list[index].nombre, nombre, PLAYER_NAME_LENGHT);
		strncpy(list[index].posicion, posicion, PLAYER_POSITION_LENGHT);
		list[index].numeroCamiseta = numeroCamiseta;
		list[index].idConfederacion = idConfederacion;
		list[index].salario = salario;
		list[index].aniosContrato = aniosContrato;

		list[index].isEmpty = FALSE;

		toReturn = 0;

	}

	return toReturn;
}

int Jugador_cargarPosicion(char* posicion, int posicionElegida)
{
	int toReturn = -1;

	if(posicion != NULL && !isnan(posicionElegida))
	{
		switch(posicionElegida)
		{
			case 1:
				// Arquero
				strncpy(posicion, "Arquero", PLAYER_POSITION_LENGHT);

				toReturn = 0;
				break;

			case 2:
				// Defensor
				strncpy(posicion, "Defensor", PLAYER_POSITION_LENGHT);

				toReturn = 0;
				break;

			case 3:
				// Mediocampista
				strncpy(posicion, "Mediocampista", PLAYER_POSITION_LENGHT);

				toReturn = 0;
				break;

			case 4:
				// Delantero
				strncpy(posicion, "Delantero", PLAYER_POSITION_LENGHT);

				toReturn = 0;
				break;

			default:
				printf("\n\aError, se ha ingresado un valor invalido.\n");
				break;

		}
	}

	return toReturn;
}

// ==================== Funciones eJugador Baja ==========================

int Jugador_baja(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int id)
{
	int toReturn = -1;

	int index;
	int indexConfederacion;

	int respuesta;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		index = Jugador_buscarPorID(listJugador, lenJugador, id);

		if(index > -1)
		{
			printf("\n");
			fflush(stdin);
			system("pause");
			system("cls");

			indexConfederacion = Confederacion_buscarPorId(listConfederacion, lenConfederacion, listJugador[index].idConfederacion);

		    printf("=========================================================================================================================== \n");

			printf("| %s  |  %-10s \t\t\t| %-10s   |  %-12s  | %-10s | %-15s | %-18s | \n", "ID", "NOMBRE", "POSICION", "Nº CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");

			//         ID            NOMBRE                     POSICION     Nº DE CAMISETA   SUELDO       CONFEDERACION    AÑOS DE CONTRATO
		    printf("|=====|=================================|==============|===============|============|=================|===================| \n");
		    Jugador_mostrarUnJugador(&listJugador[index], &listConfederacion[indexConfederacion]);
	    	printf("|_____|_________________________________|______________|_______________|____________|_________________|___________________| \n");

			printf("\n");
			printf("0 = NO.\n");
			printf("1 = SI.\n");

			if(!getInt(&respuesta, "\nEsta seguro de eliminar el jugador: ", "Error, solo 0 o 1. Vuelva a intentarlo: ", 0, 1))
			{
				switch(respuesta)
				{
					case 0:
						toReturn = 1; // USUARIO CANCELO LA BAJA
						break;

					case 1:
						listJugador[index].isEmpty = TRUE;

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

// ==================== Funciones eJugador Modificar ==========================

int Jugador_modificarJugador(eJugador* list, int len, int index)
{
	int toReturn = -1;

	int option;
	int auxOption;

	int flag = FALSE;

	eJugador auxJugador;

	if(list != NULL && len > 0 && index > -1)
	{
		do
		{
			if(!Menu_modificarJugador(&option))
			{
				switch(option)
				{
					case 1:
						//MODIFICAR NOMBRE
						if(!getString(auxJugador.nombre, "\nIngrese el nuevo nombre del jugador: ", "\nError, vuelva a intentarlo: ", 1, PLAYER_NAME_LENGHT))
						{
							strncpy(list[index].nombre, auxJugador.nombre, PLAYER_NAME_LENGHT);

							flag = TRUE;
						}
						break;

					case 2:
						//MODIFICAR POSICION
						if(!Menu_posicionJugador(&auxOption) && !Jugador_cargarPosicion(auxJugador.posicion, auxOption))
						{
							strncpy(list[index].posicion, auxJugador.posicion, PLAYER_POSITION_LENGHT);

							flag = TRUE;
						}
						break;

					case 3:
						//MODIFICAR NUMERO DE CAMISETA
						if(!getShort(&auxJugador.numeroCamiseta, "\nIngrese el nuevo numero de camiseta: ", "\nError, vuelva a intentarlo: ", 1, 99))
						{
							list[index].numeroCamiseta = auxJugador.numeroCamiseta;

							flag = TRUE;
						}
						break;

					case 4:
						//MODIFICAR CONFEDERACION
						if(!Menu_confederacionJugador(&auxJugador.idConfederacion))
						{
							list[index].idConfederacion = auxJugador.idConfederacion;

							flag = TRUE;
						}
						break;

					case 5:
						//MODIFICAR SALARIO
						if(!getFloat(&auxJugador.salario, "\nIngrese el nuevo salario del jugador: ", "\nError, vuelva a intentarlo: ", 1, 1000000))
						{
							list[index].salario = auxJugador.salario;

							flag = TRUE;
						}
						break;

					case 6:
						//MODIFICAR AÑOS DE CONTRATO
						if(!getShort(&auxJugador.aniosContrato, "\nIngrese los nuevos años de contrato: ", "\nError, vuelva a intentarlo: ", 1, 20))
						{
							list[index].aniosContrato = auxJugador.aniosContrato;

							flag = TRUE;
						}
						break;

					case 7:
						printf("\nSaliendo....\n");
						break;


					default:
						printf("\nError, ha ingresado un valor invalido.\n");
						break;
				}

				printf("\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}
		}while(option != 7);

		if(flag)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_modificar(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int id)
{
	int toReturn = -1;

	int index;
	int indexConfederacion;

	int respuesta;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		index = Jugador_buscarPorID(listJugador, lenJugador, id);

		if(index > -1)
		{
			printf("\n");
			fflush(stdin);
			system("pause");
			system("cls");

			indexConfederacion = Confederacion_buscarPorId(listConfederacion, lenConfederacion, listJugador[index].idConfederacion);

		    printf("=========================================================================================================================== \n");

			printf("| %s  |  %-10s \t\t\t| %-10s   |  %-12s  | %-10s | %-15s | %-18s | \n", "ID", "NOMBRE", "POSICION", "Nº CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");

			//         ID            NOMBRE                     POSICION     Nº DE CAMISETA   SUELDO       CONFEDERACION    AÑOS DE CONTRATO
		    printf("|=====|=================================|==============|===============|============|=================|===================| \n");
		    Jugador_mostrarUnJugador(&listJugador[index], &listConfederacion[indexConfederacion]);
	    	printf("|_____|_________________________________|______________|_______________|____________|_________________|___________________| \n");

			printf("\n");
			printf("0 = NO.\n");
			printf("1 = SI.\n");

			if(!getInt(&respuesta, "\nEsta seguro de modificar el jugador: ", "Error, solo 0 o 1. Vuelva a intentarlo: ", 0, 1))
			{
				switch(respuesta)
				{
					case 0:
						toReturn = 1; // USUARIO CANCELO LA BAJA
						break;

					case 1:
						if(!Jugador_modificarJugador(listJugador, lenJugador, index))
						{
							toReturn = 0;
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

// ==================== 	Funciones eJugador Ordenamiento ==========================


int Jugador_ordenamientoPorNombreConfederacion_Y_NombreJugador(eJugador* list, int len, int order) // ORDEN ALFABETICO
{
	int toReturn = -1;

	int i;
	int auxLen;
	int auxCmp;
	int flagSwap;

	eJugador auxJugador;

	if(list != NULL && len > 0 && (order == 1 || order == 0))
	{
		auxLen = len;

		do
		{
			flagSwap = FALSE;

			for(i = 0; i < auxLen - 1; i++)
			{
				if(list[i].isEmpty == FALSE && list[i + 1].isEmpty == FALSE)
				{
					auxCmp = strncmp(list[i].nombre, list[i + 1].nombre, PLAYER_NAME_LENGHT);

					if((list[i].idConfederacion > list[i + 1].idConfederacion && order == 0) || (list[i].idConfederacion < list[i + 1].idConfederacion && order == 1) ||
					   ((auxCmp > 0 || auxCmp == 0) && order == 0) || ((auxCmp < 0 || auxCmp == 0) && order == 1))
					{
						auxJugador = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxJugador;

						flagSwap = TRUE;
					}
				}
			}
			auxLen--;

		}while(flagSwap);

		toReturn = 0;
	}

	return toReturn;
}

//printf("| 1. %-50s      %10s \n", "Listado de Jugadores ordenado por nombre de confederacion y nombre de jugador.", "|");
//printf("| 2. %-50s      %10s \n", "Listado de Confederaciones con sus Jugadores.", "|");
//printf("| 3. %-50s      %10s \n", "Total y promedio de todos los salarios y cuantos Jugadores cobran mas del salario promedio.", "|");
//printf("| 4. %-50s      %10s \n", "Informar la confederacion con mayor cantidad de años de contrato.", "|");
//printf("| 5. %-50s      %10s \n", "Informar el porcentaje de los jugadores por cada confederacion.", "|");
//printf("| 6. %-50s      %10s \n", "Informar cual es la region con mas jugadores y el listado de los mismos.", "|");
//printf("| 7. %-50s      %10s \n", "Salir.", "|");

// ==================== 	Funciones eJugador Informes 	==========================

int Jugador_menuDeInformes(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion)
{
	int toReturn = -1;

	int option;

	int flag = FALSE;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		do
		{
			if(!Menu_subMenuInformes(&option))
			{
				switch(option)
				{
					case 1:
						// Listado de Jugadores ordenado por nombre de confederacion y nombre de jugador."
						if(!Jugador_ordenamientoPorNombreConfederacion_Y_NombreJugador(listJugador, lenJugador, 0) &&
						   !Jugador_mostrarJugadores(listJugador, lenJugador, listConfederacion, lenConfederacion))
						{
							printf("\nSe ha realizado el ordenamiento y se ha mostrado el listado de jugadores con exito");

							flag = TRUE;
						}
						else
						{
							printf("\a\nSe ha producido un error al ordenar y mostrar el listado de jugadores.\n");
						}
						break;

					case 2:
						// Listado de Confederaciones con sus Jugadores.
						if(!Jugador_listadoDeConfederacionesConJugadores(listJugador, lenJugador, listConfederacion, lenConfederacion))
						{
							printf("\nSe ha mostrado el listado de confederaciones con sus jugadores con exito.\n");

							flag = TRUE;
						}
						else
						{
							printf("\a\nSe ha producido un error al mostrar el listado de confederaciones con sus jugadores.\n");
						}
						break;

					case 3:
						// Total y promedio de todos los salarios y cuantos Jugadores cobran mas del salario promedio.
						if(!Jugador_realizarInformeDePromedios(listJugador, lenJugador))
						{
							printf("\nSe ha realizado el informe de promedios, totales y jugadores que superan el promedio con exito.\n");

							flag = TRUE;
						}
						else
						{
							printf("\a\nSe ha producido un error al realizar el informe de promedios, totales y jugadores que superan el promedio.\n");
						}
						break;

					case 4:
						// Informar la confederacion con mayor cantidad de años de contrato
						if(!Jugador_confederacionConMayorCantidadDeAniosDeContrato(listJugador, lenJugador, listConfederacion, lenConfederacion))
						{
							printf("\nSe ha realizado el informe de la confederacion con mayor años de contrato.\n");

							flag = TRUE;
						}
						else
						{
							printf("\a\nSe ha producido un error al realizar el informe de la confederacion con mayor cantidad de años de contrato.\n");
						}
						break;

					case 5:
						// Informar el porcentaje de los jugadores por cada confederacion.
						if(!Jugador_porcentajeDeJugadoresPorConfederacion(listJugador, lenJugador, listConfederacion, lenConfederacion))
						{
							printf("\nSe ha realizado el informe de los porcentajes por cada confederacion.\n");

							flag = TRUE;
						}
						else
						{
							printf("\a\nSe ha producido un error al realizar y mostrar los informes de los jugadores segun su confederacion.\n");
						}
						break;

					case 6:
						// Informar cual es la region con mas jugadores y el listado de los mismos
						if(!Jugador_verificarConfederacionConMasJugadores(listJugador, lenJugador, listConfederacion, lenConfederacion))
						{
							printf("\nSe ha realizado el informe de la region con mas jugadores y tambien se han listado los jugadores con exito.\n");

							flag = TRUE;
						}
						else
						{
							printf("\a\nSe ha producido un error al informar cual es la region con mas jugadores y mostrar un listado de estos.\n");
						}
						break;

					case 7:
						// Salir.
						printf("\nSaliendo del sub-menu de informes.\n");
						break;

					default:
						printf("\a\nError, se ha ingresado un valor invalido.\n");
						break;
				}
			}

			printf("\n\n");
			fflush(stdin);
			system("pause");
			system("cls");

		}while(option != 7);

		if(flag)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

// INFORME 2

int Jugador_listadoDeConfederacionesConJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion)
{
	int toReturn = -1;

	int option;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		do
		{
			if(!Menu_elegirConfederacion_A_Mostrar(&option))
			{
				switch(option)
				{
					case 1:
						// CONMEBOL
						if(!Jugador_mostrarListadoJugadoresSegunConfederacion(listJugador, lenJugador, listConfederacion, lenConfederacion, option))
						{
							toReturn = 0;
						}
						break;

					case 2:
						// UEFA
						if(!Jugador_mostrarListadoJugadoresSegunConfederacion(listJugador, lenJugador, listConfederacion, lenConfederacion, option))
						{
							toReturn = 0;
						}
						break;

					case 3:
						// AFC
						if(!Jugador_mostrarListadoJugadoresSegunConfederacion(listJugador, lenJugador, listConfederacion, lenConfederacion, option))
						{
							toReturn = 0;
						}
						break;

					case 4:
						// CAF
						if(!Jugador_mostrarListadoJugadoresSegunConfederacion(listJugador, lenJugador, listConfederacion, lenConfederacion, option))
						{
							toReturn = 0;
						}
						break;

					case 5:
						// CONCACAF
						if(!Jugador_mostrarListadoJugadoresSegunConfederacion(listJugador, lenJugador, listConfederacion, lenConfederacion, option))
						{
							toReturn = 0;
						}
						break;

					case 6:
						// OFC
						if(!Jugador_mostrarListadoJugadoresSegunConfederacion(listJugador, lenJugador, listConfederacion, lenConfederacion, option))
						{
							toReturn = 0;
						}
						break;

					case 7:
						// SALIR
						printf("\nSaliendo...\n");
						break;

					default:
						printf("\nError, se ha ingresado un valor invalido.\n");
						break;
				}
			}

		}while(option != 7);
	}

	return toReturn;
}

int Jugador_mostrarListadoJugadoresSegunConfederacion(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int confederacionElegida)
{
	int toReturn = -1;

	int i;
	int indexConfederacion;

	int flag = FALSE;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		printf("\n");
		fflush(stdin);

	    printf("=========================================================================================================================== \n");

		printf("| %s  |  %-10s \t\t\t| %-10s   |  %-12s  | %-10s | %-15s | %-18s | \n", "ID", "NOMBRE", "POSICION", "Nº CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");

		//         ID            NOMBRE                     POSICION     Nº DE CAMISETA   SUELDO       CONFEDERACION    AÑOS DE CONTRATO
	    printf("|=====|=================================|==============|===============|============|=================|===================| \n");

	    for(i = 0; i < lenJugador; i++)
	    {
	    	indexConfederacion = Confederacion_buscarPorId(listConfederacion, lenConfederacion, listJugador[i].idConfederacion);

	    	if(listJugador[i].isEmpty == FALSE && listJugador[i].idConfederacion == confederacionElegida && !Jugador_mostrarUnJugador(&listJugador[i], &listConfederacion[indexConfederacion]))
	    	{
	    		flag = TRUE;
	    	}
	    }

	    printf("|_____|_________________________________|______________|_______________|____________|_________________|___________________| \n");

	    if(flag)
	    {
	    	toReturn = 0;
	    }
	}

	return toReturn;
}

// INFORME 3

int Jugador_realizarInformeDePromedios(eJugador* list, int len)
{
	int toReturn = 0;

	int contadorExcede;

	float acumulador;
	float promedio;

	if(list != NULL && len > 0)
	{
		if(!Jugador_promedioDeSalarios(list, len, &acumulador, &promedio) && !Jugador_contadorExcedePromedio(list, len, promedio, &contadorExcede) &&
		   !Jugador_mostrarInformeDePromedios(acumulador, promedio, contadorExcede))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_acumuladorDeSalarios(eJugador* list, int len, float* acumulador)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && acumulador != NULL)
	{
		*acumulador = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				*acumulador = *acumulador + list[i].salario;
			}
		}

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_contadorJugadores(eJugador* list, int len, int* contador)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && contador != NULL)
	{
		*contador = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				(*contador)++;
			}
		}

		toReturn = 0;
	}

	return toReturn;
}

int Jugador_promedioDeSalarios(eJugador* list, int len, float* acumulador, float* promedio)
{
	int toReturn = -1;

	int contador;

	if(list != NULL && len > 0 && promedio != NULL)
	{
		*promedio = 0;

		if(!Jugador_acumuladorDeSalarios(list, len, acumulador) && !Jugador_contadorJugadores(list, len, &contador))
		{
			*promedio = (float) *acumulador / contador;

			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_contadorExcedePromedio(eJugador* list, int len, float promedio, int* contadorExcede)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && contadorExcede != NULL)
	{
		*contadorExcede = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salario > promedio)
			{
				(*contadorExcede)++;
			}
		}
		toReturn = 0;
	}

	return toReturn;
}

int Jugador_mostrarInformeDePromedios(float acumulador, float promedio, int contadorExcede)
{
	int toReturn = -1;

	if(!isnan(acumulador) && !isnan(promedio) && !isnan(contadorExcede))
	{
	    printf("======================================================================= \n");
		printf("| \t   %40s \t\t      | \n", "INFORME | TOTAL Y PROMEDIO SALARIOS");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| Total de salarios: $%.2f %39s \n", acumulador, "|");
		printf("| Promedio de salarios: $%.2f %36s \n", promedio, "|");
		printf("| Jugadores que exceden el promedio:  %d %31s \n", contadorExcede, "|");

		printf("|_____________________________________________________________________| \n");

		toReturn = 0;
	}

	return toReturn;
}

// INFORME 4

int Jugador_confederacionConMayorCantidadDeAniosDeContrato(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion)
{
	int toReturn = -1;

	int i;
	int flag = TRUE;
	int mayorAniosContrato;
	int idConfederacionConMayorAniosContrato;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		for(i = 0; i < lenJugador; i++)
		{
			if(listJugador[i].isEmpty == FALSE)
			{
				if(flag)
				{
					mayorAniosContrato = listJugador[i].aniosContrato;
					idConfederacionConMayorAniosContrato = listJugador[i].idConfederacion;

					flag = FALSE;
				}
				else if(listJugador[i].aniosContrato > mayorAniosContrato)
				{
					mayorAniosContrato = listJugador[i].aniosContrato;
					idConfederacionConMayorAniosContrato = listJugador[i].idConfederacion;
				}
			}
		}

		if(!Jugador_mostrarInformeConfederacionConMayorAniosDeContrato(listConfederacion, lenConfederacion, mayorAniosContrato, idConfederacionConMayorAniosContrato))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_mostrarInformeConfederacionConMayorAniosDeContrato(eConfederacion* list, int len, int aniosContrato, int idConfederacion)
{
	int toReturn = -1;

	int index;

	index = Confederacion_buscarPorId(list, len, idConfederacion);

	if(list != NULL && len > 0 && !isnan(aniosContrato) && !isnan(idConfederacion))
	{
	    printf("======================================================================= \n");
		printf("| \t   %40s %11s \n", "INFORME | CONFEDERACION CON MAS AÑOS DE CONTRATO", "|");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| Confederacion: %-20s %33s \n", list[index].nombre, "|");
		printf("| Años de Contrato: %d %49s \n", aniosContrato, "|");

		printf("|_____________________________________________________________________| \n");

		toReturn = 0;
	}

	return toReturn;
}

// INFORME 5

int Jugador_porcentajeDeJugadoresPorConfederacion(eJugador* listJugadores, int lenJugadores, eConfederacion* listConfederacion, int lenConfederacion)
{
	int toReturn = -1;

	int totalJugadores;

	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorOFC = 0;

	float porcentajeCONMEBOL;
	float porcentajeUEFA;
	float porcentajeAFC;
	float porcentajeCAF;
	float porcentajeCONCACAF;
	float porcentajeOFC;

	if(listJugadores != NULL && lenJugadores > 0)
	{
		if(!Jugador_contadorJugadores(listJugadores, lenJugadores, &totalJugadores) && !Jugador_contadorDeJugadoresPorConfederacion(listJugadores, lenJugadores, &contadorCONMEBOL, &contadorUEFA, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorOFC))
		{
			if(contadorCONMEBOL >= 0 && contadorUEFA >= 0 && contadorAFC >= 0 && contadorCAF >= 0 && contadorCONCACAF >= 0 && contadorOFC >= 0)
			{
				porcentajeCONMEBOL = ((float) contadorCONMEBOL * 100 / totalJugadores);
				porcentajeUEFA = ((float) contadorUEFA * 100 / totalJugadores);
				porcentajeAFC = ((float) contadorAFC * 100 / totalJugadores);
				porcentajeCAF = ((float) contadorCAF * 100 / totalJugadores);
				porcentajeCONCACAF = ((float) contadorCONCACAF * 100 / totalJugadores);
				porcentajeOFC = ((float) contadorOFC * 100 / totalJugadores);
			}

			if(!Jugador_mostrarPorcentajeDeJugadores(porcentajeCONMEBOL, porcentajeUEFA, porcentajeAFC, porcentajeCAF, porcentajeCONCACAF, porcentajeOFC))
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int Jugador_contadorDeJugadoresPorConfederacion(eJugador* list, int len, int* contadorCONMEBOL,	int* contadorUEFA, int* contadorAFC, int* contadorCAF, int* contadorCONCACAF, int* contadorOFC)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && contadorCONMEBOL != NULL && contadorUEFA != NULL && contadorAFC != NULL && contadorCAF != NULL && contadorCONCACAF != NULL && contadorOFC != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				switch(list[i].idConfederacion)
				{
				case 1:
					// CONMEBOL
					(*contadorCONMEBOL)++;

					toReturn = 0;
					break;

				case 2:
					// UEFA
					(*contadorUEFA)++;

					toReturn = 0;
					break;

				case 3:
					// AFC
					(*contadorAFC)++;

					toReturn = 0;
					break;

				case 4:
					// CAF
					(*contadorCAF)++;

					toReturn = 0;
					break;

				case 5:
					// CONCACAF
					(*contadorCONCACAF)++;

					toReturn = 0;
					break;

				case 6:
					// OFC
					(*contadorOFC)++;

					toReturn = 0;
					break;
				}
			}
		}
	}

	return toReturn;
}

int Jugador_mostrarPorcentajeDeJugadores(float porcentajeCONMEBOL, float porcentajeUEFA, float porcentajeAFC, float porcentajeCAF, float porcentajeCONCACAF, float porcentajeOFC)
{
	int toReturn = -1;

	if(!isnan(porcentajeCONMEBOL) && !isnan(porcentajeUEFA) && !isnan(porcentajeAFC) && !isnan(porcentajeCAF) && !isnan(porcentajeCONCACAF) && !isnan(porcentajeOFC))
	{
	    printf("======================================================================= \n");
		printf("|   %-50s    | \n", "SUB-MENU | MOSTRAR PORCENTAJE DE JUGADORES SEGUN CONFEDERACION");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| Porcentaje CONMEBOL: %s%-10.2f %36s \n", "%", porcentajeCONMEBOL, "|");
		printf("| Porcentaje UEFA: %s%-10.2f %40s \n", "%", porcentajeUEFA, "|");
		printf("| Porcentaje AFC: %s%-10.2f %41s \n", "%", porcentajeAFC, "|");
		printf("| Porcentaje CAF: %s%-10.2f %41s \n", "%", porcentajeCAF, "|");
		printf("| Porcentaje CONCACAF: %s%-10.2f %36s \n", "%", porcentajeCONCACAF, "|");
		printf("| Porcentaje OFC: %s%-10.2f %41s \n", "%", porcentajeOFC, "|");

		printf("|_____________________________________________________________________| \n");

		toReturn = 0;
	}

	return toReturn;
}

// INFORME 6

int Jugador_verificarConfederacionConMasJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion)
{
	int toReturn = -1;

	int flag = FALSE;

	int contador = 0;

	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorOFC = 0;

	int idConfederacion;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion && lenConfederacion > 0)
	{
		if(!Jugador_contadorDeJugadoresPorConfederacion(listJugador, lenJugador, &contadorCONMEBOL, &contadorUEFA, &contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorOFC))
		{
			// CONMEBOL
			if(contadorCONMEBOL > contadorUEFA && contadorCONMEBOL > contadorAFC && contadorCONMEBOL > contadorCAF && contadorCONMEBOL > contadorCONCACAF && contadorCONMEBOL > contadorOFC)
			{
				idConfederacion = 1;

				contador = contadorCONMEBOL;

				flag = TRUE;
			}
			// UEFA
			else if(contadorUEFA > contadorCONMEBOL && contadorUEFA > contadorAFC && contadorUEFA > contadorCAF && contadorUEFA > contadorCONCACAF && contadorUEFA > contadorOFC)
			{
				idConfederacion = 2;

				contador = contadorUEFA;

				flag = TRUE;
			}
			// AFC
			else if(contadorAFC > contadorCONMEBOL && contadorAFC > contadorUEFA && contadorAFC > contadorCAF && contadorAFC > contadorCONCACAF && contadorAFC > contadorOFC)
			{
				idConfederacion = 3;

				contador = contadorAFC;

				flag = TRUE;
			}
			// CAF
			else if(contadorCAF > contadorCONMEBOL && contadorCAF > contadorUEFA && contadorCAF > contadorAFC && contadorCAF > contadorCONCACAF && contadorCAF > contadorOFC)
			{
				idConfederacion = 4;

				contador = contadorCAF;

				flag = TRUE;
			}
			// CONCACAF
			else if(contadorCONCACAF > contadorCONMEBOL && contadorCONCACAF > contadorUEFA && contadorCONCACAF > contadorAFC && contadorCONCACAF > contadorCAF && contadorCONCACAF > contadorOFC)
			{
				idConfederacion = 5;

				contador = contadorCONCACAF;

				flag = TRUE;
			}
			// OFC
			else
			{
				idConfederacion = 6;

				contador = contadorOFC;

				flag = TRUE;
			}
		}

		if(flag && !Jugador_mostrarConfederacionConMasJugadores(listJugador, lenJugador, listConfederacion, lenConfederacion, idConfederacion, contador))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Jugador_mostrarConfederacionConMasJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int idConfederacion, int contador)
{
	int toReturn = -1;

	int i;
	int index;

	int flag = FALSE;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		index = Confederacion_buscarPorId(listConfederacion, lenConfederacion, idConfederacion);

		fflush(stdin);

	    printf("======================================================================= \n");
		printf("| \t %-50s \t      | \n", "SUB-MENU | MOSTRAR CONFEDERACIONES CON MAS JUGADORES");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| La confederacion con mas jugadores es %-8s \t\t      | \n| y tiene %d jugadores %49s \n",  listConfederacion[index].nombre, contador, "|");

		printf("|_____________________________________________________________________| \n");

		printf("\n");
	    printf("=========================================================================================================================== \n");

		printf("| %s  |  %-10s \t\t\t| %-10s   |  %-12s  | %-10s | %-15s | %-18s | \n", "ID", "NOMBRE", "POSICION", "Nº CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");

		//         ID            NOMBRE                     POSICION     Nº DE CAMISETA   SUELDO       CONFEDERACION    AÑOS DE CONTRATO
	    printf("|=====|=================================|==============|===============|============|=================|===================| \n");

	    for(i = 0; i < lenJugador; i++)
	    {
	    	if(listJugador[i].isEmpty == FALSE && listJugador[i].idConfederacion == idConfederacion && !Jugador_mostrarUnJugador(&listJugador[i], &listConfederacion[index]))
	    	{
	    		flag = TRUE;
	    	}
	    }

	    if(flag)
	    {
	    	toReturn = 0;

	    	printf("|_____|_________________________________|______________|_______________|____________|_________________|___________________| \n");

	    }
	}

	return toReturn;
}

// ==================== Funciones eJugador Mostrar ==========================

int Jugador_mostrarUnJugador(eJugador* unJugador, eConfederacion* unaConfederacion)
{
	int toReturn = -1;

	if(unJugador != NULL && unaConfederacion != NULL)
	{
		printf("|  %d  |  %-30s | %-12s | %-12d  | %-10.2f | %-15s | %-17d | \n", unJugador->id, unJugador->nombre, unJugador->posicion,
																				  unJugador->numeroCamiseta, unJugador->salario, unaConfederacion->nombre, unJugador->aniosContrato);

		toReturn = 0;
	}

	return toReturn;
}
int Jugador_mostrarJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion)
{
	int toReturn = -1;

	int i;
	int indexConfederacion;

	int flag = FALSE;

	if(listJugador != NULL && lenJugador > 0 && listConfederacion != NULL && lenConfederacion > 0)
	{
		printf("\n");
		fflush(stdin);

	    printf("=========================================================================================================================== \n");

		printf("| %s  |  %-10s \t\t\t| %-10s   |  %-12s  | %-10s | %-15s | %-18s | \n", "ID", "NOMBRE", "POSICION", "Nº CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");

		//         ID            NOMBRE                     POSICION     Nº DE CAMISETA   SUELDO       CONFEDERACION    AÑOS DE CONTRATO
	    printf("|=====|=================================|==============|===============|============|=================|===================| \n");

	    for(i = 0; i < lenJugador; i++)
	    {
	    	indexConfederacion = Confederacion_buscarPorId(listConfederacion, lenConfederacion, listJugador[i].idConfederacion);

	    	if(listJugador[i].isEmpty == FALSE && !Jugador_mostrarUnJugador(&listJugador[i], &listConfederacion[indexConfederacion]))
	    	{
	    		flag = TRUE;
	    	}
	    }

	    if(flag)
	    {
	    	toReturn = 0;

	    	printf("|_____|_________________________________|______________|_______________|____________|_________________|___________________| \n");

	    }
	}

	return toReturn;
}






