/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "confederacion.h"
#include "menu.h"
#include "input.h"

#define CANT_CONFEDERACION 10
#define CANT_JUGADORES 3000

int main(void)
{
	setbuf(stdout, NULL);

	eConfederacion arrayConfederacion[CANT_CONFEDERACION];
	eJugador arrayJugador[CANT_JUGADORES];

	int idJugador = 1;
	int idConfederacion = 1;

	int option;
	int auxID;

	int auxReturnRemove;
	int auxReturnModificar;

	if(!Confederacion_inicializarConfederacion(arrayConfederacion, CANT_CONFEDERACION) && !Confederacion_hardcode(arrayConfederacion, CANT_CONFEDERACION, &idConfederacion) &&
       !Jugador_inicializarJugadores(arrayJugador, CANT_JUGADORES) && !Jugador_hardcode(arrayJugador, CANT_JUGADORES, &idJugador))
	{
		do
		{
			if(!Menu_menuDeOpcionesPrincipal(&option))
			{
				switch(option)
				{
					case 1:
						// CARGA
						if(!Jugador_cargarUno(arrayJugador, CANT_JUGADORES, &idJugador))
						{
							printf("\nSe ha cargado un nuevo jugador con exito.\n");
						}
						else
						{
							printf("\a\nSe ha producido un error al cargar un nuevo libro.\n");
						}
						break;

					case 2:
						// BAJA
						if(!Jugador_arrayIsEmpty(arrayJugador, CANT_JUGADORES))
						{
							if(!Jugador_mostrarJugadores(arrayJugador, CANT_JUGADORES, arrayConfederacion, CANT_CONFEDERACION) &&
							   !getInt(&auxID, "\nElija un jugador para dar de baja: ", "\nError, vuelva a intentarlo: ", 1, CANT_JUGADORES))
							{
								auxReturnRemove = Jugador_baja(arrayJugador, CANT_JUGADORES, arrayConfederacion, CANT_CONFEDERACION, auxID);

								switch(auxReturnRemove)
								{
									case -1:
										printf("\a\nSe ha producido un error al dar de baja al jugador.\n");
									break;

									case 0:
										printf("\nSe ha eliminado el jugador con exito.\n");
										break;

									case 1:
										printf("\nEl usuario cancelo la baja.\n");
										break;

									default:
										printf("\a\nError, se ha ingresado un valor invalido.\n");
										break;
								}
							}
						}
						else
						{
							printf("\a\nError, no hay jugadores que eliminar.\n");
						}
						break;

					case 3:
						// MOD
						if(!Jugador_arrayIsEmpty(arrayJugador, CANT_JUGADORES))
						{
							if(!Jugador_mostrarJugadores(arrayJugador, CANT_JUGADORES, arrayConfederacion, CANT_CONFEDERACION) &&
							   !getInt(&auxID, "\nElija un jugador para dar modificar: ", "\nError, vuelva a intentarlo: ", 1, CANT_JUGADORES))
							{
								auxReturnModificar = Jugador_modificar(arrayJugador, CANT_JUGADORES, arrayConfederacion, CANT_CONFEDERACION, auxID);

								switch(auxReturnModificar)
								{
									case -1:
										printf("\a\nSe ha producido un error al modificar al jugador.\n");
									break;

									case 0:
										printf("\nSe ha modificado el jugador con exito.\n");
										break;

									case 1:
										printf("\nEl usuario cancelo la modificacion.\n");
										break;

									default:
										printf("\a\nError, se ha ingresado un valor invalido.\n");
										break;
								}
							}
						}
						else
						{
							printf("\a\nError, no hay jugadores que modificar.\n");
						}
						break;

					case 4:
						// INFORMES
						if(!Jugador_arrayIsEmpty(arrayJugador, CANT_JUGADORES))
						{
							if(!Jugador_menuDeInformes(arrayJugador , CANT_JUGADORES, arrayConfederacion, CANT_CONFEDERACION))
							{
								printf("\nSe ha entrado al sub-menu de informes con exioto.\n");
							}
							else
							{
								printf("\a\nSe ha producido un error al ingresar al menu de opciones.\n");
							}
						}
						else
						{
							printf("\a\nError, no hay jugadores que informar.\n");
						}
						break;

					case 5:
						// SALIR
						break;

					default:
						printf("\nSaliendo del programa.\n");
						break;
				}
			}
			else
			{
				printf("\nError al cargar el menu de opciones.\n");
			}

			printf("\n");
			fflush(stdin);
			system("pause");
			system("cls");

		}while(option != 5);
	}
	else
	{
		printf("\nError al inicializar y harcodear datos.\n");
	}


	return EXIT_SUCCESS;
}
