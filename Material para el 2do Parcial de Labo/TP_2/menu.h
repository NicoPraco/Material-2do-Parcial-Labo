/*
 * menu.h
 *
 *  Created on: 15 oct. 2022
 *      Author: kualo
 */

#ifndef MENU_H_
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int Menu_menuDeOpcionesPrincipal(int* input);
int Menu_subMenuInformes(int* input);

int Menu_posicionJugador(int* input);
int Menu_confederacionJugador(int* input);
int Menu_elegirConfederacion_A_Mostrar(int* input);

int Menu_modificarJugador(int* input);

int Menu_modificarConfederacion(int* input);

#endif /* MENU_H_ */
