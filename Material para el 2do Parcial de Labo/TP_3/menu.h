/*
 * menu.h
 *
 *  Created on: 5 nov. 2022
 *      Author: kualo
 */

#ifndef MENU_H_
#define MENU_H_

#include "LinkedList.h"

// ==========================================================================================================================

int Menu_optionsMenu(int* input);

// SOLO MOD: NOMBRE - EDAD - POSICION - NACIONALIDAD
int Menu_modMenu(int* input);

int Menu_listadosMenu(int* input);

int Menu_convocarMenu(int* input);

// ORDENAR POR:
//				1. JUGADORES POR NACIONALIDAD.
//				2. SELECIONES POR CONFE
// 				3. JUGADORES POR EDAD.
// 				4. JUGADORES POR NOMBRE

int Menu_sortMenuPrincipal(int* input);

int Menu_sortJugador(int* input);

int Menu_sortOrderMenu(int* input);

// ==========================================================================================================================
// DEL VIEJO TP3
//int Passenger_choosePassengerType(char* passengerType);
//
//int Passenger_choosePassengerFlightStatus(char* flightStatus);

#endif /* MENU_H_ */
