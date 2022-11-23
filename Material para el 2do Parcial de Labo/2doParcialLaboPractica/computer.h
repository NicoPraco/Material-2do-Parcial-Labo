/*
 * funciones.h
 *
 *  Created on: 22 nov. 2022
 *      Author: kualo
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

#define BUFFER_LEN 300

#include "LinkedList.h"
#include "computer.h"

#define DESC_LEN 110

#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char descripcion[DESC_LEN];
	float precio;
	int idTipo;

} eComputer;

// ==========================================================================================================================
// ==================== 					Funciones eComputer Basicas 					==========================

eComputer* Computer_new();
eComputer* Computer_newParametros(int id, char* desc, float precio, int idTipo);
eComputer* Computer_newParametrosAsText(char* idStr, char* desc, char* precioStr, char* idTipoStr);
int Computer_delete(eComputer* this);

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter ID 					========================== | INT

int Computer_setId(eComputer* this, int id);
int Computer_getId(eComputer* this, int* id);

int Computer_setIdTxt(eComputer* this, char* idStr);
int Computer_getIdTxt(eComputer* this, char* idStr);

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter Desc 					========================== | CHAR *

int Computer_setDesc(eComputer* this, char* desc);
int Computer_getDesc(eComputer* this, char* desc);

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter Precio 				========================== | FLOAT

int Computer_setPrecio(eComputer* this, float precio);
int Computer_getPrecio(eComputer* this, float* precio);

int Computer_setPrecioTxt(eComputer* this, char* precioStr);
int Computer_getPrecioTxt(eComputer* this, char* precioStr);

// ==========================================================================================================================
// ==================== 		Funciones eComputer | Setter y Getter ID Tipo 				========================== | INT

int Computer_setIdTipo(eComputer* this, int idTipo);
int Computer_getIdTipo(eComputer* this, int* idTipo);

int Computer_setIdTipoTxt(eComputer* this, char* idTipoStr);
int Computer_getIdTipoTxt(eComputer* this, char* idTipoStr);

/// ==========================================================================================================================
/// ==========================================================================================================================

// ==================== 		Funciones eJugador | Buscar Por ID 						========================== |

int Computer_findJugadorPorId(LinkedList* pArrayList, int id, int* index);

int Computer_comparaByIdSeleccion(void* pElement1, void* pElement2);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | SORT  								========================== |

int Computer_sort(LinkedList* pArrayList);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | PRINT - LIST					========================== |

int Computer_print(eComputer* this);
int Computer_list(LinkedList* pArrayList);

// ==========================================================================================================================
// ==================== 		Funciones eJugador | MAP					========================== |

int Computer_aumentoToDesktop(void* pElement);
int Computer_aumentoToLaptop(void* pElement);

#endif /* COMPUTER_H_ */
