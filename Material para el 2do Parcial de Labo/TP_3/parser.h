
#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

#define BUFFER_LEN 200

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador, int* id);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador, int* id);

int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion, int* id);


#endif /* PARSER_H_ */
