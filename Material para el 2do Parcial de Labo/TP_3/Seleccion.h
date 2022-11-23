#ifndef SELECCION_H_INCLUDED
#define SELECCION_H_INCLUDED

#define BUFFER_LEN 200

#define PAIS_LEN 31
#define CONFEDERACION_LEN 31

#include "LinkedList.h"

typedef struct
{
	int id;
	char pais[PAIS_LEN];
	char confederacion[CONFEDERACION_LEN];
	int convocados;

} eSeleccion;

// ==========================================================================================================================
// ==================== 					Funciones eSeleccion Basicas 					==========================

eSeleccion* Seleccion_new();
eSeleccion* Seleccion_newParametros(int id, char* paisStr, char* confederacionStr, int convocados);
eSeleccion* Seleccion_newParametrosAsText(char* idStr, char* paisStr,char* confederacionStr, char* convocadosStr);
int Seleccion_delete(eSeleccion* this);

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | Setter y Getter ID 					========================== | INT

int Seleccion_setId(eSeleccion* this, int id);
int Seleccion_getId(eSeleccion* this, int* id);

int Seleccion_setIdTxt(eSeleccion* this, char* idStr);
int Seleccion_getIdTxt(eSeleccion* this, char* idStr);

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | Setter y Getter Pais 				========================== | CHAR *

int Seleccion_setPais(eSeleccion* this, char* pais);
int Seleccion_getPais(eSeleccion* this, char* pais);

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | Setter y Getter Confederacion 		========================== | CHAR *

int Seleccion_setConfederacion(eSeleccion* this, char* confederacion);
int Seleccion_getConfederacion(eSeleccion* this, char* confederacion);

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | Setter y Getter Convocados 			========================== | INT

int Seleccion_setConvocados(eSeleccion* this, int convocados);
int Seleccion_getConvocados(eSeleccion* this, int* convocados);

int Seleccion_setConvocadosTxt(eSeleccion* this, char* convocados);
int Seleccion_getConvocadosTxt(eSeleccion* this, char* convocados);

/// ==========================================================================================================================
/// ==========================================================================================================================

// ==================== 		Funciones eSeleccion | Buscar Por ID 						========================== |

int Seleccion_findSeleccionPorId(LinkedList* pArrayListSeleccion, int id, int* index);

int Seleccion_comparaById(void* pElement1, void* pElement2);
int Seleccion_comparaByPais(void* pElement1, void* pElement2);
int Seleccion_comparaByConfederacion(void* pElement1, void* pElement2);
int Seleccion_comparaByConvocados(void* pElement1, void* pElement2);

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | EDIT  								========================== |

int Seleccion_edit(LinkedList* pArrayListSeleccion, int id, int option);

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | SORT  								========================== |

int Seleccion_sort(LinkedList* pArrayListSeleccion);

int Seleccion_sortById(LinkedList* pArrayListSeleccion);

// ==========================================================================================================================
// ==================== 		Funciones eSeleccion | PRINT - LIST 						========================== |

int Seleccion_print(eSeleccion* this);
int Seleccion_list(LinkedList* pArrayListSeleccion, int option);

#endif // SELECCION_H_INCLUDED
