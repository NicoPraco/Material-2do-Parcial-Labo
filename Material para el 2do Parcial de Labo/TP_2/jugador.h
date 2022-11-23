/*
 * jugador.h
 *
 *  Created on: 15 oct. 2022
 *      Author: kualo
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "confederacion.h"
#include "menu.h"
#include "input.h"

#define TRUE 1
#define FALSE 0

#define PLAYER_NAME_LENGHT 51
#define PLAYER_POSITION_LENGHT 51

typedef struct
{
	int id;
	char nombre[PLAYER_NAME_LENGHT];
	char posicion[PLAYER_POSITION_LENGHT];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;

	short isEmpty;

} eJugador;

// ==========================================================================================================================
// ==================== 	Funciones eJugador Basicas 		==========================

int Jugador_inicializarJugadores(eJugador* list, int len);
int Jugador_hardcode(eJugador* list, int len, int* id);
int Jugador_buscarPorID(eJugador* list, int len, int id);
int Jugador_buscarLibre(eJugador* list, int len, int* index);
int Jugador_arrayIsEmpty(eJugador* list, int len);

// ==================== 	Funciones eJugador Carga 		==========================
int Jugador_cargarUno(eJugador* list, int len, int* id);
int Jugador_cargarEnArray(eJugador* list, int len, int id, char nombre[], char posicion[], short numeroCamiseta, int idConfederacion, float salario, short aniosContrato, int index);
int Jugador_cargarPosicion(char* posicion, int posicionElegida);

// ==================== 	Funciones eJugador Baja 		==========================

int Jugador_baja(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int id);

// ==================== 	Funciones eJugador Modificar 	==========================

int Jugador_modificarJugador(eJugador* list, int len, int index);
int Jugador_modificar(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int id);

// ==================== 	Funciones eJugador Ordenamiento ==========================

int Jugador_ordenamientoPorNombreConfederacion_Y_NombreJugador(eJugador* list, int len, int order); // ORDEN ALFABETICO

// ==================== 	Funciones eJugador Informes 	==========================

int Jugador_menuDeInformes(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion);

int Jugador_listadoDeConfederacionesConJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion);
int Jugador_mostrarListadoJugadoresSegunConfederacion(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int confederacionElegida);

int Jugador_realizarInformeDePromedios(eJugador* list, int len);
int Jugador_acumuladorDeSalarios(eJugador* list, int len, float* acumulador);
int Jugador_contadorJugadores(eJugador* list, int len, int* contador);
int Jugador_promedioDeSalarios(eJugador* list, int len, float* acumulador, float* promedio);
int Jugador_contadorExcedePromedio(eJugador* list, int len, float promedio, int* contadorExcede);
int Jugador_mostrarInformeDePromedios(float acumulador, float promedio, int contadorExcede);

int Jugador_confederacionConMayorCantidadDeAniosDeContrato(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion);
int Jugador_mostrarInformeConfederacionConMayorAniosDeContrato(eConfederacion* list, int len, int aniosContrato, int idConfederacion);

int Jugador_porcentajeDeJugadoresPorConfederacion(eJugador* listJugadores, int lenJugadores, eConfederacion* listConfederacion, int lenConfederacion);
int Jugador_contadorDeJugadoresPorConfederacion(eJugador* list, int len, int* contadorCONMEBOL,	int* contadorUEFA, int* contadorAFC, int* contadorCAF, int* contadorCONCACAF, int* contadorOFC);
int Jugador_mostrarPorcentajeDeJugadores(float porcentajeCONMEBOL, float porcentajeUEFA, float porcentajeAFC, float porcentajeCAF, float porcentajeCONCACAF, float porcentajeOFC);

int Jugador_verificarConfederacionConMasJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion);
int Jugador_mostrarConfederacionConMasJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion, int idConfederacion, int contador);

// ==================== 	Funciones eJugador Mostrar 		==========================

int Jugador_mostrarUnJugador(eJugador* unJugador, eConfederacion* unaConfederacion);
int Jugador_mostrarJugadores(eJugador* listJugador, int lenJugador, eConfederacion* listConfederacion, int lenConfederacion);



#endif /* JUGADOR_H_ */
