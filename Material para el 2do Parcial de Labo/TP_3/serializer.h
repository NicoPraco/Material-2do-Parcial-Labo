/*
 * serializer.h
 *
 *  Created on: 11 nov. 2022
 *      Author: kualo
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include "LinkedList.h"

int Serializer_jugadorToText(FILE* pFile, LinkedList* pArrayListJugador);
int Serializer_convocadosToBinary(FILE* pFile, LinkedList* pArrayListJugador);

int Serializer_seleccionToText(FILE* pFile, LinkedList* pArrayListSeleccion);

#endif /* SERIALIZER_H_ */
