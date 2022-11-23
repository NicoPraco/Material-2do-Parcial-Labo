/*
 ============================================================================
 Name        : 2doParcialLaboPractica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "computer.h"
// #include "menu.h"
#include "input.h"

int main(void)
{
	setbuf(stdout, NULL);

	LinkedList* listaComputadoras = ll_newLinkedList();

	int auxReturn;
	int idComputadoras = 1;

	auxReturn = Controller_cargarDesdeTexto("computadoras.csv", listaComputadoras, &idComputadoras);

	printf("\nAUX RETURN = %d.\n", auxReturn);

//	auxReturn = Computer_sort(listaComputadoras);
//
//	printf("\nAUX RETURN = %d.\n", auxReturn);

	auxReturn = Computer_list(listaComputadoras);

	printf("\nAUX RETURN = %d.\n", auxReturn);

	auxReturn = ll_map(listaComputadoras, Computer_aumentoToDesktop);
	auxReturn = ll_map(listaComputadoras, Computer_aumentoToLaptop);

	system("pause");

	printf("\nAUX RETURN = %d.\n", auxReturn);

	Computer_list(listaComputadoras);

	auxReturn = Controller_guardarMapeado("mapeado.csv", listaComputadoras);

	printf("\nAUX RETURN = %d.\n", auxReturn);

	return EXIT_SUCCESS;
}
