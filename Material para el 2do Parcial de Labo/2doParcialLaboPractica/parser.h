/*
 * parser.h
 *
 *  Created on: 22 nov. 2022
 *      Author: kualo
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "computer.h"

#define BUFFER_LEN 300

int Parser_fromText(FILE* pFile, LinkedList* pArrayList, int* id);
//int Parser_fromBinary(FILE* pFile, LinkedList* pArrayList, int* id);

int Parser_mapeado(FILE* pFile, LinkedList* pArrayList);

#endif /* PARSER_H_ */
