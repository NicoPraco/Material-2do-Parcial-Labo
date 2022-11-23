#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#define BUFFER_LEN 200

#include "LinkedList.h"
#include "Seleccion.h"

#define NAME_LEN 101
#define POSITION_LEN 31
#define NATIONALITY_LEN 31

#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char nombreCompleto[NAME_LEN];
	int edad;
	char posicion[POSITION_LEN];
	char nacionalidad[NATIONALITY_LEN];
	int idSeleccion;

} eJugador;

// ==========================================================================================================================
// ==================== 					Funciones eJugador Basicas 					==========================

eJugador* Jugador_new();
eJugador* Jugador_newParametros(int id, char* nombreCompletoStr, int edad, char* posicionStr, char* nacionalidadStr, int idSeleccion);
eJugador* Jugador_newParametrosAsText(char* idStr, char* nombreCompletoStr, char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);
int Jugador_delete(eJugador* this);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter ID 				========================== | INT

int Jugador_setId(eJugador* this, int id);
int Jugador_getId(eJugador* this, int* id);

int Jugador_setIdTxt(eJugador* this, char* idStr);
int Jugador_getIdTxt(eJugador* this, char* idStr);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter Nombre Completo 	========================== | CHAR *

int Jugador_setNombreCompleto(eJugador* this, char* nombreCompleto);
int Jugador_getNombreCompleto(eJugador* this, char* nombreCompleto);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter Posicion 			========================== | CHAR *

int Jugador_setPosicion(eJugador* this, char* posicion);
int Jugador_getPosicion(eJugador* this, char* posicion);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter Nacionalidad 		========================== | CHAR *

int Jugador_setNacionalidad(eJugador* this, char* nacionalidad);
int Jugador_getNacionalidad(eJugador* this, char* nacionalidad);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter Edad 				========================== | INT

int Jugador_setEdad(eJugador* this, int edad);
int Jugador_getEdad(eJugador* this, int* edad);

int Jugador_setEdadTxt(eJugador* this, char* edadStr);
int Jugador_getEdadTxt(eJugador* this, char* edadStr);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | Setter y Getter ID Seleccion 		========================== | INT

int Jugador_setIdSeleccion(eJugador* this, int idSeleccion);
int Jugador_getIdSeleccion(eJugador* this, int* idSeleccion);

int Jugador_setIdSeleccionTxt(eJugador* this, char* idSeleccionStr);
int Jugador_getIdSeleccionTxt(eJugador* this, char* idSeleccionStr);

/// ==========================================================================================================================
/// ==========================================================================================================================

// ==================== 		Funciones eJugador | Buscar Por ID 						========================== |

int Jugador_findJugadorPorId(LinkedList* pArrayListJugador, int id, int* index);

int Jugador_comparaById(void* pElement1, void* pElement2);
int Jugador_comparaByNombreCompleto(void* pElement1, void* pElement2);
int Jugador_comparaByEdad(void* pElement1, void* pElement2);
int Jugador_comparaByPosicion(void* pElement1, void* pElement2);
int Jugador_comparaByNacionalidad(void* pElement1, void* pElement2);
int Jugador_comparaByIdSeleccion(void* pElement1, void* pElement2);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | ADD - EDIT - REMOVE 				========================== |

int Jugador_add(LinkedList* pArrayListJugador, int* id);
int Jugador_edit(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int Jugador_remove(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | SORT  								========================== |

int Jugador_sort(LinkedList* pArrayListJugador);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | PRINT - LIST - LIST 2				========================== |

int Jugador_print(eJugador* this);
int Jugador_printConSeleccion(eJugador* this, eSeleccion* this2);

int Jugador_list(LinkedList* pArrayListJugador);
int Jugador_listConSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int Jugador_listarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | CONVOCAR 							========================== |

int Jugador_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int idJugador, int idSeleccion);

int Jugador_quitarConvocacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | MENUS 								========================== |

int Jugador_showModMenu(LinkedList* pArrayListJugador, eJugador* this);
int Jugador_showSortMenu(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int Jugador_showListMenu(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int Jugador_showConvocarMenu(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);


#endif // JUGADOR_H_INCLUDED
