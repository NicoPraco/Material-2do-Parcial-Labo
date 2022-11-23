#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "serializer.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador, int* id)
{
	int toReturn = -1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListJugador != NULL && id != NULL)
	{
		pFile = fopen(path, "r+");

		if(pFile != NULL)
		{
			if(!parser_JugadorFromText(pFile, pArrayListJugador, id))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int* id)
{
	int toReturn  =-1;

	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL && id != NULL)
	{
		pFile = fopen(path, "rb+");

		if(pFile != NULL)
		{
			if(!parser_JugadorFromBinary(pFile, pArrayListJugador, id) &&
			   !Jugador_listarConvocados(pArrayListJugador, pArrayListSeleccion))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, int* id)
{
	int toReturn  =-1;

	if(pArrayListJugador != NULL && id != NULL)
	{
		if(!Jugador_add(pArrayListJugador, id))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn  =-1;

	int auxReturn;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		if(!Jugador_listConSeleccion(pArrayListJugador, pArrayListSeleccion))
		{
			auxReturn = Jugador_edit(pArrayListJugador, pArrayListSeleccion);

			switch(auxReturn)
			{
				case -1:
					// ERROR
					toReturn = -1;
					break;

				case 0:
					// SE REALIZO LA MODIFICACION
					toReturn = 0;
					break;

				case 1:
					// EL USUARIO NO MODIFICO NADA
					toReturn = 1;
					break;

				case 2:
					// EL USUARIO NO QUISO REALIZAR LA MODIFICACION
					toReturn = 2;
					break;

				default:
					// ERROR
					printf("\nError, se ha ingresado un valor invalido.\n");
					break;
			}
		}
	}

    return toReturn;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn  =-1;

	int auxReturn;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		if(!Jugador_listConSeleccion(pArrayListJugador, pArrayListSeleccion))
		{
			auxReturn = Jugador_remove(pArrayListJugador, pArrayListSeleccion);

			switch(auxReturn)
			{
				case -1:
					// ERROR
					toReturn = -1;
					break;

				case 0:
					// SE REALIZO LA BAJA
					toReturn = 0;
					break;

				case 1:
					// EL USUARIO CANCELO LA BAJA
					toReturn = 1;
					break;

				default:
					// ERROR
					printf("\nError, se ha ingresado un valor invalido.\n");
					break;
			}
		}
	}

    return toReturn;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn  =-1;

	int auxReturn;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		auxReturn = Jugador_showListMenu(pArrayListJugador, pArrayListSeleccion);

		switch(auxReturn)
		{
			case -1:
				// ERROR
				toReturn = -1;
				break;

			case 0:
				// SE LISTO CORRECATMENTE
				toReturn = 0;
				break;

			case 1:
				// EL USUARIO NO LISTO NADA
				toReturn = 1;
				break;

			default:
				// ERROR
				printf("\nError, se ha ingresado un valor invalido.\n");
				break;
		}
	}

    return toReturn;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn  =-1;

	int auxReturn;

	if(pArrayListJugador != NULL)
	{
		auxReturn = Jugador_showSortMenu(pArrayListJugador, pArrayListSeleccion);

		switch(auxReturn)
		{
			case -1:
				// ERROR
				toReturn = -1;
				break;

			case 0:
				// TODO OK
				toReturn = 0;
				break;

			case 1:
				// EL USUARIO NO REALIZO NINGUN CAMBIO
				toReturn = 1;
				break;

			default:
				// ERROR
				printf("\nError, se ha ingresado un valor invalido.\n");
				break;
		}
	}

    return toReturn;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int toReturn  =-1;

	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "w+");

		if(pFile != NULL)
		{
			if(!Serializer_jugadorToText(pFile, pArrayListJugador))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int toReturn  =-1;

	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "wb+");

		if(pFile != NULL)
		{
			if(!Serializer_convocadosToBinary(pFile, pArrayListJugador))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

// ==========================================================================================================================
// ==================== 			Funciones Controller Jugador | CONVOCAR 		 				=========================

int controller_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int toReturn = -1;

	int auxReturn;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		auxReturn = Jugador_showConvocarMenu(pArrayListJugador, pArrayListSeleccion);

		switch(auxReturn)
		{
			case -1:
				// ERROR
				toReturn = -1;
				break;

			case 0:
				// TODO OK
				toReturn = 0;
				break;

			case 1:
				// EL USUARIO NO REALIZO NINGUN CAMBIO
				toReturn = 1;
				break;

			default:
				// ERROR
				printf("\nError, se ha ingresado un valor invalido.\n");
				break;
		}
	}

	return toReturn;
}

/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================

// ==========================================================================================================================
// ==================== 			Funciones Controller Seleccion | SEARCH 							=========================

int controller_buscarSeleccion(LinkedList* pArrayListSeleccion, int* id, int* index)
{
	int toReturn = -1;

	if(pArrayListSeleccion != NULL && id != NULL && index != NULL)
	{
		if(!Seleccion_findSeleccionPorId(pArrayListSeleccion, *id, index))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion, int* id)
{
	int toReturn = -1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListSeleccion != NULL && id != NULL)
	{
		pFile = fopen(path, "r+");

		if(pFile != NULL)
		{
			if(!parser_SeleccionFromText(pFile, pArrayListSeleccion, id))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion, int id, int option)
{
	int toReturn = -1;

	if(pArrayListSeleccion != NULL)
	{
		if(!Seleccion_edit(pArrayListSeleccion, id, option))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion, int option)
{
	int toReturn  =-1;

	if(pArrayListSeleccion != NULL)
	{
		if(!Seleccion_list(pArrayListSeleccion, option))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int toReturn  =-1;

	if(pArrayListSeleccion != NULL)
	{
		if(!Seleccion_sort(pArrayListSeleccion))
		{
			toReturn = 0;
		}
	}

    return toReturn;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int toReturn  =-1;

	FILE* pFile;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pFile = fopen(path, "w+");

		if(pFile != NULL)
		{
			if(!Serializer_seleccionToText(pFile, pArrayListSeleccion))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}


