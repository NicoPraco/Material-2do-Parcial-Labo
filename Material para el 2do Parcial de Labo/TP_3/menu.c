/*
 * menu.c
 *
 *  Created on: 5 nov. 2022
 *      Author: kualo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "input.h"
#include "Jugador.h"

int Menu_optionsMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "MENU DE OPCIONES PRINCIPAL");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Carga de Archivos CSVs.", "|");
		printf("| 2. %-50s      %10s \n", "Alta de Jugador.", "|");
		printf("| 3. %-50s      %10s \n", "Modificacion de Jugador.", "|");
		printf("| 4. %-50s      %10s \n", "Baja de Jugador.", "|");
		printf("| 5. %-50s      %10s \n", "Listados.", "|");
		printf("| 6. %-50s      %10s \n", "Convocar Jugadores.", "|");
		printf("| 7. %-50s      %10s \n", "Ordenar y Listar.", "|");
		printf("| 8. %-50s      %10s \n", "Generar Archivo Binario.", "|");
		printf("| 9. %-50s      %10s \n", "Cargar Archivo Binario.", "|");
		printf("| 10. %-50s     %10s \n", "Guardar Archivos CSVs.", "|");
		printf("| 11. %-50s     %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija una opcion: ", "\nError, solo numeros del 1 al 11. Vuelva a intentarlo: ", 1, 11))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

// SOLO MOD: NOMBRE - EDAD - POSICION - NACIONALIDAD
int Menu_modMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU MODIFICAR JUGADOR");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Modificar Nombre.", "|");
		printf("| 2. %-50s      %10s \n", "Modificar Edad.", "|");
		printf("| 3. %-50s      %10s \n", "Modificar Posicion.", "|");
		printf("| 4. %-50s      %10s \n", "Modificar Nacionalidad.", "|");
		printf("| 5. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija la posicion del jugador: ", "\nError, solo numeros del 1 al 5. Vuelva a intentarlo: ", 1, 5))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}


/*
 * 5. LISTADOS:
			A) TODOS LOS JUGADORES.
			B) TODAS LAS SELECCIONES.
			C) JUGADORES CONVOCADOS (únicamente).
 */
int Menu_listadosMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU LISTAR");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Listar los Jugadores.", "|");
		printf("| 2. %-50s      %10s \n", "Listar todas las Selecciones.", "|");
		printf("| 3. %-50s      %10s \n", "Listar todos los Jugadores Convocados.", "|");
		printf("| 4. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija la posicion del jugador: ", "\nError, solo numeros del 1 al 4. Vuelva a intentarlo: ", 1, 4))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_convocarMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU LISTAR");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Convocar Jugadores.", "|");
		printf("| 2. %-50s      %10s \n", "Quitar convocatoria.", "|");
		printf("| 3. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija la posicion del jugador: ", "\nError, solo numeros del 1 al 3. Vuelva a intentarlo: ", 1, 3))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

/*
 * ORDENAR POR:
				1. JUGADORES POR NACIONALIDAD.
				2. SELECIONES POR CONFE
 				3. JUGADORES POR EDAD.
 				4. JUGADORES POR NOMBRE
*/
int Menu_sortMenuPrincipal(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU ORDENAR PRINCIPAL");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Ordenamiento de Jugadores.", "|");
		printf("| 2. %-50s      %10s \n", "Ordenar Selecciones por Confederacion.", "|");
		printf("| 3. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija una opcion: ", "\nError, solo numeros del 1 al 3. Vuelva a intentarlo: ", 1, 3))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_sortJugador(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU ORDENAR JUGADOR");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Ordenar Jugadores por Nacionalidad.", "|");
		printf("| 2. %-50s      %10s \n", "Ordenar Jugadores por Edad.", "|");
		printf("| 3. %-50s      %10s \n", "Ordenar Jugadores por Nombre.", "|");
		printf("| 4. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija una opcion: ", "\nError, solo numeros del 1 al 4. Vuelva a intentarlo: ", 1, 4))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_sortOrderMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU ORDENA DEL ORDENAMIENTO");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Orden Ascendente.", "|");
		printf("| 2. %-50s      %10s \n", "Orden Descendente.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija una opcion: ", "\nError, solo numeros entre 1 y 2. Vuelva a intentarlo: ", 1, 2))
		{
				toReturn = 0;
		}
	}

	return toReturn;
}

