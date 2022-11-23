/*
 * parser.c
 *
 *  Created on: 22 nov. 2022
 *      Author: kualo
 */

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int Parser_fromText(FILE* pFile, LinkedList* pArrayList, int* id)
{
	int toReturn = -1;

	int auxId;

	char idStr[BUFFER_LEN];
	char desc[BUFFER_LEN];
	char precioStr[BUFFER_LEN];
	char idTipoStr[BUFFER_LEN];

	eComputer* this = NULL;

	if(pFile != NULL && pArrayList != NULL && id != NULL)
	{
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr, desc, precioStr, idTipoStr) == 4)
			{
				this = Computer_newParametrosAsText(idStr, desc, precioStr, idTipoStr);

				if(this != NULL)
				{
					auxId = atoi(idStr);

					if(auxId > *id)
					{
						*id = auxId;
					}
					ll_add(pArrayList, this);
				}
			}
		}
		toReturn = 0;
	}

	return toReturn;
}

int Parser_mapeado(FILE* pFile, LinkedList* pArrayList)
{
	int toReturn = -1;

	int i;
	int len;

	eComputer* this = NULL;

	char auxId[BUFFER_LEN];
	char auxDesc[BUFFER_LEN];
	char auxPrecio[BUFFER_LEN];
	char auxIdTipo[BUFFER_LEN];

	if(pFile != NULL && pArrayList != NULL)
	{
		len = ll_len(pArrayList);

		if(len > 0)
		{
			fprintf(pFile, "id,descripcion,precio,idTipo\n");

			for(i = 0; i < len; i++)
			{
				this = (eComputer*) ll_get(pArrayList, i);

				if(this != NULL && !Computer_getIdTxt(this, auxId) && !Computer_getDesc(this, auxDesc) && !Computer_getPrecioTxt(this, auxPrecio) && !Computer_getIdTipoTxt(this, auxIdTipo))
				{
					fprintf(pFile, "%s,%s,%s,%s\n", auxId, auxDesc, auxPrecio, auxIdTipo);
				}
				else
				{
					break;
				}
			}

			if(i == len)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}
