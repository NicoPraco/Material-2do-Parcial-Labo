/*
 * menu.c
 *
 *  Created on: 15 oct. 2022
 *      Author: kualo
 */

#include "menu.h"

int Menu_menuDeOpcionesPrincipal(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "MENU DE OPCIONES PRINCIPAL");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Alta de Jugador.", "|");
		printf("| 2. %-50s      %10s \n", "Baja de Jugador.", "|");
		printf("| 3. %-50s      %10s \n", "Modificacion de Jugador.", "|");
		printf("| 4. %-50s      %10s \n", "Informes.", "|");
		printf("| 5. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija la posicion del jugador: ", "\nError, solo numeros del 1 al 5. Vuelva a intentarlo: ", 1, 5))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_subMenuInformes(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("================================================================================================================ \n");
		printf("| \t\t   %40s \t\t\t\t\t\t       | \n", "MENU DE INFORMES");
		printf("| \t\t\t\t\t\t\t\t %47s \n", "|");

		printf("| 1. %-60s      %23s \n", "Listado de Jugadores ordenado por nombre de confederacion y nombre de jugador.", "|");
		printf("| 2. %-60s      %41s \n", "Listado de Confederaciones con sus Jugadores.", "|");
		printf("| 3. %-60s      %10s \n", "Total y promedio de todos los salarios y cuantos Jugadores cobran mas del salario promedio.", "|");
		printf("| 4. %-60s      %36s \n", "Informar la confederacion con mayor cantidad de años de contrato.", "|");
		printf("| 5. %-60s      %38s  \n", "Informar el porcentaje de los jugadores por cada confederacion.", "|");
		printf("| 6. %-60s      %29s \n", "Informar cual es la region con mas jugadores y el listado de los mismos.", "|");
		printf("| 7. %-60s      %41s \n", "Salir.", "|");

		printf("|______________________________________________________________________________________________________________| \n");

		if(!getInt(input, "\nElija la posicion del jugador: ", "\nError, solo numeros del 1 al 7. Vuelva a intentarlo: ", 1, 7))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_posicionJugador(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU POSICION DEL JUGADOR");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Arquero.", "|");
		printf("| 2. %-50s      %10s \n", "Defensor.", "|");
		printf("| 3. %-50s      %10s \n", "Mediocampista.", "|");
		printf("| 4. %-50s      %10s \n", "Delantero.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija la posicion del jugador: ", "\nError, solo numeros del 1 al 4. Vuelva a intentarlo: ", 1, 4))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_confederacionJugador(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU ELEGIR CONFEDERACION DEL JUGADOR");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "CONMEBOL.", "|");
		printf("| 2. %-50s      %10s \n", "UEFA.", "|");
		printf("| 3. %-50s      %10s \n", "AFC.", "|");
		printf("| 4. %-50s      %10s \n", "CAF.", "|");
		printf("| 5. %-50s      %10s \n", "CONCACAF.", "|");
		printf("| 6. %-50s      %10s \n", "OFC.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija la confederacion del jugador: ", "\nError, solo numeros del 1 al 6. Vuelva a intentarlo: ", 1, 6))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_elegirConfederacion_A_Mostrar(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("| \t   %40s       | \n", "SUB-MENU MOSTRAR JUGADORES SEGUN SU CONFEDERACIONES ");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "CONMEBOL.", "|");
		printf("| 2. %-50s      %10s \n", "UEFA.", "|");
		printf("| 3. %-50s      %10s \n", "AFC.", "|");
		printf("| 4. %-50s      %10s \n", "CAF.", "|");
		printf("| 5. %-50s      %10s \n", "CONCACAF.", "|");
		printf("| 6. %-50s      %10s \n", "OFC.", "|");
		printf("| 7. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija la confederacion a mostrar: ", "\nError, solo numeros del 1 al 7. Vuelva a intentarlo: ", 1, 7))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_modificarJugador(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU MODFICAR JUGADOR");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Nombre.", "|");
		printf("| 2. %-50s      %10s \n", "Posicion.", "|");
		printf("| 3. %-50s      %10s \n", "Numero de Camiseta.", "|");
		printf("| 4. %-50s      %10s \n", "Confederacion.", "|");
		printf("| 5. %-50s      %10s \n", "Salario.", "|");
		printf("| 6. %-50s      %10s \n", "Años de Contrato.", "|");
		printf("| 7. %-50s      %10s \n", "Salir.", "|");

		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija una opcion: ", "\nError, solo numeros del 1 al 7. Vuelva a intentarlo: ", 1, 7))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int Menu_modificarConfederacion(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
	    printf("======================================================================= \n");
		printf("|    %40s \t\t\t      | \n", "SUB-MENU MODIFICAR CONFEDERACION");
		printf("| \t\t\t\t\t\t\t\t %6s \n", "|");

		printf("| 1. %-50s      %10s \n", "Modificar nombre de la confederacion.", "|");
		printf("| 2. %-50s      %10s \n", "Modificar region de la confederacion.", "|");
		printf("| 3. %-50s      %11s \n", "Modificar año de creacion de la confederacion.", "|");
		printf("| 4. %-50s      %10s \n", "Salir.", "|");
		printf("|_____________________________________________________________________| \n");

		if(!getInt(input, "\nElija una opcion: ", "Error, solo numeros del 1 al 4. Vuelva a intentarlo: ", 1, 4))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}
