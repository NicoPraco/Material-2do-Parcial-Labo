/*
 * controller.c
 *
 *  Created on: 22 nov. 2022
 *      Author: kualo
 */

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "computer.h"
#include "LinkedList.h"

// ==========================================================================================================================
// ==================== 			Funciones Controller Computer | Carga 							=========================

int Controller_cargarDesdeTexto(char* path , LinkedList* pArrayList, int* id)
{
	int toReturn = -1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayList != NULL && id != NULL)
	{
		pFile = fopen(path, "r+");

		printf("\n pFILE = %p.\n", pFile);

		if(pFile != NULL)
		{
			if(!Parser_fromText(pFile, pArrayList, id))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}

	}

	return toReturn;
}

int Controller_guardarMapeado(char* path , LinkedList* pArrayList)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayList )
	{
		pFile = fopen(path, "w+");

		if(pFile != NULL)
		{
			if(!Parser_mapeado(pFile, pArrayList))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

	return toReturn;
}
