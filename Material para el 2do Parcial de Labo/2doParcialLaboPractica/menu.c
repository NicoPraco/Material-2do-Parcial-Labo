/*
 * menu.c
 *
 *  Created on: 23 nov. 2022
 *      Author: kualo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "input.h"
#include "computer.h"

int Menu_principal(int* input)
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

