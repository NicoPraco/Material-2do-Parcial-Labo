/*
 * serializer.c
 *
 *  Created on: 11 nov. 2022
 *      Author: kualo
 */

#include <stdio.h>
#include <stdlib.h>

#include "serializer.h"
#include "Jugador.h"
#include "Seleccion.h"

int Serializer_jugadorToText(FILE* pFile, LinkedList* pArrayListJugador)
{
	int toReturn = -1;

	int i;
	int len;

	eJugador* this = NULL;

	char auxId[BUFFER_LEN];
	char auxNombreCompleto[BUFFER_LEN];
	char auxEdad[BUFFER_LEN];
	char auxPosicion[BUFFER_LEN];
	char auxNacionalidad[BUFFER_LEN];
	char auxIdSeleccion[BUFFER_LEN];

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);

		if(len > 0)
		{
			fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");

			for(i = 0; i < len; i++)
			{
				this = (eJugador*) ll_get(pArrayListJugador, i);

				if(this != NULL && !Jugador_getIdTxt(this, auxId) && !Jugador_getNombreCompleto(this, auxNombreCompleto) &&
				  !Jugador_getEdadTxt(this, auxEdad) && !Jugador_getPosicion(this, auxPosicion) && !Jugador_getNacionalidad(this, auxNacionalidad) &&
				  !Jugador_getIdSeleccionTxt(this, auxIdSeleccion))
				{
					fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxIdSeleccion);
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

int Serializer_convocadosToBinary(FILE* pFile, LinkedList* pArrayListJugador)
{
	int toReturn = -1;

	int i;
	int len;

	int auxIdSeleccion;

	eJugador* this = NULL;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (eJugador*) ll_get(pArrayListJugador, i);

				Jugador_getIdSeleccion(this, &auxIdSeleccion);

				if(this == NULL || auxIdSeleccion != 0 || fwrite(this, sizeof(eJugador), 1, pFile) != 1)
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

int Serializer_seleccionToText(FILE* pFile, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int i;
	int len;

	char auxId[BUFFER_LEN];
	char auxPais[BUFFER_LEN];
	char auxConfederacion[BUFFER_LEN];
	char auxConvocados[BUFFER_LEN];

	eSeleccion* this = NULL;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		len = ll_len(pArrayListSeleccion);

		if(len > 0)
		{
			fprintf(pFile, "id,pais,confederacion,convocados\n");

			for(i = 0; i < len; i++)
			{
				this = (eSeleccion*) ll_get(pArrayListSeleccion, i);

				if(this != NULL && !Seleccion_getIdTxt(this, auxId) && !Seleccion_getPais(this, auxPais) &&
				  !Seleccion_getConfederacion(this, auxConfederacion) && !Seleccion_getConvocadosTxt(this, auxConvocados))
				{
					fprintf(pFile, "%s,%s,%s,%s\n", auxId, auxPais, auxConfederacion, auxConvocados);
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
