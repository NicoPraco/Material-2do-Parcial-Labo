#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"

// ==========================================================================================================================
// ==================== 			Funciones Controller Jugador | Carga 							=========================

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador, int* id);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int* id);

// ==========================================================================================================================
// ==================== 			Funciones Controller Jugador | ADD - EDIT - REMOVE 				=========================

int controller_agregarJugador(LinkedList* pArrayListJugador, int* id);
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 			Funciones Controller Jugador | SORT 		 					=========================

int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 			Funciones Controller Jugador | LIST - LIST WITH SELECCION 		=========================

int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 			Funciones Controller Jugador | Guardar Jugador					=========================

int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

// ==========================================================================================================================
// ==================== 			Funciones Controller Jugador | CONVOCAR 		 				=========================

int controller_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================
/// ==========================================================================================================================

// ==========================================================================================================================
// ==================== 			Funciones Controller Seleccion | SEARCH 							=========================

int controller_buscarSeleccion(LinkedList* pArrayListSeleccion, int* id, int* index);

// ==========================================================================================================================
// ==================== 			Funciones Controller Seleccion | Carga 							=========================

int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion, int* id);

// ==========================================================================================================================
// ==================== 			Funciones Controller Seleccion | EDIT							=========================

int controller_editarSeleccion(LinkedList* pArrayListSeleccion, int id, int option);

// ==========================================================================================================================
// ==================== 			Funciones Controller Seleccion | SORT 		 					=========================

int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 			Funciones Controller Seleccion | LIST 							=========================

int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 			Funciones Controller Seleccion | Guardar Seleccion				=========================

int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);







#endif // CONTROLLER_H_INCLUDED
