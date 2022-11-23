/*
 * confederacion.h
 *
 *  Created on: 18 oct. 2022
 *      Author: kualo
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "input.h"

#define LENGHT_NOMBRE 50
#define LENGHT_REGION 50

#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char nombre[LENGHT_NOMBRE];
	char region[LENGHT_REGION];
	int anioCreacion;

	int isEmpty;

} eConfederacion;

// ==========================================================================================================================
// ==================== Funciones eConfederacion Basicas ==========================

int Confederacion_inicializarConfederacion(eConfederacion* list, int len);
int Confederacion_hardcode(eConfederacion* list, int len, int* id);
int Confederacion_buscarPorId(eConfederacion* list, int len, int id);
int Confederacion_buscarLibre(eConfederacion* list, int len, int* index);
int Confederacion_arrayIsEmpty(eConfederacion* list, int len);

// ==================== Funciones eConfederacion Carga ==========================

int Confederacion_cargarUno(eConfederacion* list, int len, int* id);
int Confederacion_cargarEnArray(eConfederacion* list, int len, int id, char nombre[], char region[], int anioCreacion);

// ==================== Funciones eConfederacion Baja ==========================

int Confederacion_baja(eConfederacion* list, int len, int id);

// ==================== Funciones eConfederacion Modificar ==========================

int Confederacion_modificarConfederacion(eConfederacion* list, int len, int index);
int Confederacion_modificar(eConfederacion* list, int len, int id);

// ==================== Funciones eConfederacion Mostrar ==========================

int Confederacion_mostrarUnaConfederacion(eConfederacion* unaConfederacion);
int Confederacion_mostrarConfederaciones(eConfederacion* listConfederacion, int len);

//




#endif /* CONFEDERACION_H_ */
