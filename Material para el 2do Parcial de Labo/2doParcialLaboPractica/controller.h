/*
 * controller.h
 *
 *  Created on: 22 nov. 2022
 *      Author: kualo
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

// ==========================================================================================================================
// ==================== 			Funciones Controller Computer | Carga 							=========================

int Controller_cargarDesdeTexto(char* path , LinkedList* pArrayList, int* id);

int Controller_guardarMapeado(char* path , LinkedList* pArrayList);


#endif /* CONTROLLER_H_ */
