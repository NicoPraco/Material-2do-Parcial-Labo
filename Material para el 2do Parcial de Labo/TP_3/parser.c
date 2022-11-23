#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador, int* id)
{
	int toReturn = -1;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		int auxId;

		char idStr[BUFFER_LEN];
		char nombreCompletoStr[BUFFER_LEN];
		char edadStr[BUFFER_LEN];
		char posicionStr[BUFFER_LEN];
		char nacionalidadStr[BUFFER_LEN];
		char idSeleccionStr[BUFFER_LEN];

		eJugador* this = NULL;

		if(pFile != NULL && pArrayListJugador != NULL && id != NULL)
		{
			while(!feof(pFile))
			{
				if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr) == 6)
				{
					this = Jugador_newParametrosAsText(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);

					if(this != NULL)
					{
						auxId = atoi(idStr);

						if(auxId > *id)
						{
							*id = auxId;
						}
						ll_add(pArrayListJugador, this);

					}
				}
			}
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador, int* id)
{
	int toReturn = -1;

	int auxId;

	int index;

	int auxIdSeleccion;

	eJugador* this = NULL;

	if(pFile != NULL && pArrayListJugador != NULL && id != NULL)
	{
		while(!feof(pFile))
		{
			this = Jugador_new();

			if(this != NULL && fread(this, sizeof(eJugador), 1, pFile) == 1)
			{
				Jugador_getIdSeleccion(this, &auxIdSeleccion);

				if((!Jugador_getId(this, &auxId) && auxId > *id) || Jugador_findJugadorPorId(pArrayListJugador, auxId, &index))
				{
					*id = auxId;
					ll_add(pArrayListJugador, this);
				}
			}
		}
		toReturn = 0;
	}

    return toReturn;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion, int* id)
{
	int toReturn = -1;

	int auxId;

	char idStr[BUFFER_LEN];
	char paisStr[BUFFER_LEN];
	char confederacionStr[BUFFER_LEN];
	char convocadosStr[BUFFER_LEN];

	eSeleccion* this = NULL;

	if(pFile != NULL && pArrayListSeleccion != NULL && id != NULL)
	{
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr, paisStr, confederacionStr, convocadosStr) == 4)
			{
				this = Seleccion_newParametrosAsText(idStr, paisStr, confederacionStr, convocadosStr);

				if(this != NULL)
				{
					auxId = atoi(idStr);

					if(auxId > *id)
					{
						*id = auxId;
					}
					ll_add(pArrayListSeleccion, this);
				}
			}
		}
		toReturn = 0;
	}

    return toReturn;
}

