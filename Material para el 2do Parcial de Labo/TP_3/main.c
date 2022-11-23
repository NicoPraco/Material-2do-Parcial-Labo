#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "menu.h"
#include "input.h"

/*
 * 1. CARGA DE ARCHIVOS: Se deben leer los archivos .csv de jugadores y selecciones | DONE
 *
 * 2. ALTA DE JUGADOR: Se debe permitir ingresar un jugador calculando automáticamente el número de Id, | DONE
 * el id de la selección debe quedar en 0. El resto de los campos se le pedirá al usuario.
 *
 * 		Nota: el id del jugador debe ser autoincremental, único, autónomo y debe persistir, es decir,
 * 		que su valor no debe reiniciarse cada vez que se reinicie la ejecución del programa,
 * 		no debe depender de la posición de un array/lista ni calcularse en base a buscar el mayor id que tenga un jugador dentro del array/lista.
 * 		El primer id disponible para la carga manual es el 371.
 *
 * 3. MODIFICACIÓN DE JUGADOR: Se deberá mostrar la lista completa de jugadores con todos sus datos y se podrá elegir uno, permitiendo modificar solamente: | DONE
 *
 * 		nombre, edad, posición, nacionalidad.
 *
 * Este proceso debe contar con menú propio permitiendo elegir qué campo se desea modificar.
 *
 * 4. BAJA DE JUGADOR: Se deberá mostrar la lista completa de jugadores con todos sus datos, se podrá elegir uno y se eliminará el jugador del sistema. | DONE
 *
 * 		Nota: si el jugador a dar de baja estaba convocado a una selección, en dicha selección se debe disminuir en 1 el contador de convocados.
 *
 * 5. LISTADOS:
 *
 * 			A) TODOS LOS JUGADORES. | DONE
 * 			B) TODAS LAS SELECCIONES. | DONE
 * 			C) JUGADORES CONVOCADOS (únicamente). | DONE
 *
 * 		Este proceso debe contar con menú propio permitiendo elegir qué listado se desea ver.
 *
 * 6. CONVOCAR JUGADORES:	| DONE
 *
 * 			A) CONVOCAR: siempre y cuando el jugador no esté convocado en otra selección y
 * 			la selección a donde será convocado no haya llegado a la cantidad máxima de convocados,
 * 			se deberá asociar al jugador el id de la selección y en dicha selección se deberá aumentar el contador de convocados en 1.
 * 			Al momento de tener que elegir qué dato ingresar se deberá mostrar un listado con las opciones disponibles.
 *
 * 			B) QUITAR DE LA SELECCIÓN: Se deberá mostrar el listado de jugadores convocados,
 * 			se podrá elegir uno, se pondrá el id de selección en 0 dejando al jugador disponible para una nueva convocatoria y
 * 			se deberá disminuir en 1 el contador de convocados de dicha selección.
 *
 * 7. ORDENAR Y LISTAR:	| DONE
 *
 * 			A) JUGADORES POR NACIONALIDAD.
 * 			B) SELECCIONES POR CONFEDERACIÓN.
 * 			C) JUGADORES POR EDAD.
 * 			D) JUGADORES POR NOMBRE.
 *
 * 	Este proceso debe contar con menú propio permitiendo elegir por cuál criterio se desea ordenar.
 *
 * 	8. GENERAR ARCHIVO BINARIO: Generar y guardar en binario una nueva lista que contenga los jugadores convocados de una confederación ingresada por el usuario.
 * 	| ESTA HECHO LO DEL GUARDAR PERO NO ES DE LOS JUGADORES CONVOCADOS
 *
 * 	9. CARGAR ARCHIVO BINARIO: Se deberá leer e imprimir los datos del archivo generado en el punto 8.
 * 	| DONE
 *
 * 	10. GUARDAR ARCHIVOS .CSV: Se deberá guardar en sus respectivos archivos todos los cambios realizados en jugadores y selecciones.
 * 	| DONE
 *
 * 	11. SALIR: Termina la ejecución del programa previa confirmación del usuario,
 * 	si se realizaron cambios en los archivos y estos no fueron guardados debería informarse antes de permitir la salida.
 *
 *
 * Nota 1: El programa debe evitar el acceso a las distintas opciones si no dispone de los datos necesarios.
 *
 * Nota 2: Al momento de listar los jugadores, si está convocado se debe mostrar el nombre de dicha selección y si no el mensaje de no convocado.
 *
 * Nota 3: Todos los campos de la estructura Selección serán de solo lectura (utilizar funciones getters),
 * salvo el contador de convocados que debe ser de lectura y escritura (getters, setters).
 *
 * Nota 4: Los operadores flecha (->) y/o punto (.) solo podrán usarse dentro de las funciones SETTERS, GETTERS y/o CONSTRUCTOR,
 * en cualquier otra función o parte del proyecto no está permitido.
 *
 * Nota 5: Se deberá contar con bibliotecas de funciones para entradas y salidas de datos, verificando y validando los mismos.
 *
 */

int main()
{
	setbuf(stdout, NULL);

	LinkedList* listaJugadores = ll_newLinkedList();
	LinkedList* listaSeleccion = ll_newLinkedList();

    int option;
    int optionExit;
    int idJugador = 1;
    int idSeleccion = 1;

    int auxReturn;

    int flagAdd = FALSE;
    int flagEdit = FALSE;
    int flagRemove = FALSE;
    int flagSort = FALSE;

    int flagConvocar = FALSE;

    if(listaJugadores != NULL && listaSeleccion != NULL)
    {
    	do{
    		if(!Menu_optionsMenu(&option))
    		{
    			switch(option)
	    		{
	    			case 1:
	    				// CARGA DE DATOS
	    				if(ll_isEmpty(listaJugadores) && ll_isEmpty(listaSeleccion))
	    				{
							if(!controller_cargarJugadoresDesdeTexto("jugadores2.csv", listaJugadores, &idJugador) &&
							   !controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSeleccion, &idSeleccion))
							{
								printf("\nSe ha cargado los archivos .CSV con exito.\n");
							}
							else
							{
								printf("\nError en la carga de archivos .CSV.\n");
							}
	    				}
	    				else
	    				{
	    					printf("\nLa lista ya ha sido cargada.\n");
	    				}
						break;

	    			case 2:
	    				// ALTA DE JUGADOR
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					if(!controller_agregarJugador(listaJugadores, &idJugador))
	    					{
	    						printf("\nJugador cargado con exito.\n");

	    						flagAdd = TRUE;
	    					}
	    					else
	    					{
	    						printf("\nError en la carga de un jugador.\n");
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 3:
	    				// MODIFICAR JUGADOR
	    						// SUB-MENU | OPCIONES
	    						// RETURN -1 - 0 - 1.
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					auxReturn = controller_editarJugador(listaJugadores, listaSeleccion);

	    					switch(auxReturn)
	    					{
	    						case -1:
	    							printf("\nSe ha producido un error al editar el jugador.\n");
	    							break;

	    						case 0:
	    							printf("\nSe ha modificado al jugador con exito.\n");

	    							flagEdit = TRUE;
	    							break;

	    						case 1:
	    							printf("\nEl usuario acepto la modificacion pero no realizo ningun cambio.\n");
	    							break;

	    						case 2:
	    							printf("\nEl usuario cancelo el editar.\n");
	    							break;

	    						default:
	    							printf("\nError, se ha ingresado un valor invalido.");
	    							break;
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 4:
	    				// BAJA DE JUGADOR
	    						// RETURN -1 - 0 - 1
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					auxReturn = controller_removerJugador(listaJugadores, listaSeleccion);

	    					switch(auxReturn)
	    					{
	    						case -1:
	    							printf("\nSe ha producido un error al eliminar el jugador.\n");
	    							break;

	    						case 0:
	    							printf("\nSe ha eliminado al jugador con exito.\n");

	    							flagRemove = TRUE;
	    							break;

	    						case 1:
	    							printf("\nEl usuario cancelo la baja.\n");
	    							break;

	    						default:
	    							printf("\nError, se ha ingresado un valor invalido.");
	    							break;
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 5:
	    				// LISTADOS
	    						// SUB-MENU | 3 OPCIONES
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					auxReturn = controller_listarJugadores(listaJugadores, listaSeleccion);

	    					switch(auxReturn)
	    					{
	    						case -1:
	    							printf("\nSe ha producido un error al listar el menu.\n");
	    							break;

	    						case 0:
	    							printf("\nSe ha mostrado el menu de listar con exito.\n");
	    							break;

	    						case 1:
	    							printf("\nEl usuario no realizo nada.\n");
	    							break;

	    						default:
	    							printf("\nError, se ha ingresado un valor invalido.");
	    							break;
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 6:
	    				// CONVOCAR JUGADORES
	    						// SUB-MENU | 2 OPCIONES
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					auxReturn = controller_convocar(listaJugadores, listaSeleccion);

	    					switch(auxReturn)
	    					{
	    						case -1:
	    							printf("\nSe ha producido un error al mostrar el menu de convocatoria.\n");
	    							break;

	    						case 0:
	    							printf("\nSe ha mostrado el menu de convocatoria con exito.\n");

	    							flagConvocar = TRUE;
	    							break;

	    						case 1:
	    							printf("\nEl usuario no realizo ningun cambio.\n");
	    							break;

	    						default:
	    							printf("\nError, se ha ingresado un valor invalido.");
	    							break;
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 7:
	    				// ORDENAR Y LISTAR
	    						// SUB-MENU | 4 OPCIONES
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					auxReturn = controller_ordenarJugadores(listaJugadores, listaSeleccion);

	    					switch(auxReturn)
	    					{
	    						case -1:
	    							printf("\nSe ha producido un error al mostrar el menu de ordenamientos.\n");
	    							break;

	    						case 0:
	    							printf("\nSe ha mostrado el menu de ordenamientos con exito.\n");

	    							flagSort = TRUE;
	    							break;

	    						case 1:
	    							printf("\nEl usuario realizo ningun cambio.\n");
	    							break;

	    						default:
	    							printf("\nError, se ha ingresado un valor invalido.");
	    							break;
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 8:
	    				// GENERAR ARCHIVO BINARIO | JUGADORES CONVOCADOS
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					if(!controller_guardarJugadoresModoBinario("convocados.bin", listaJugadores))
	    					{
	    						printf("\nSe ha realizao el guardado con exito.\n");
	    					}
	    					else
	    					{
	    						printf("\nSe ha producido un error al guardar los datos.\n");
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 9:
	    				// CARGAR ARCHIVO BINARIO | Punto 8
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					if(!controller_cargarJugadoresDesdeBinario("convocados.bin", listaJugadores, listaSeleccion, &idJugador))
	    					{
	    						printf("\nSe ha realizao la carga con exito.\n");
	    					}
	    					else
	    					{
	    						printf("\nSe ha producido un error al cargar los datos.\n");
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 10:
	    				// GUARDAR ARCHIVOS .CSV |
	    				if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSeleccion))
	    				{
	    					if(!controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) &&
	    					   !controller_guardarSeleccionesModoTexto("selecciones.csv", listaSeleccion))
	    					{
	    						printf("\nSe ha realizao el guardado con exito.\n");

	    						flagAdd = FALSE;
	    						flagEdit = FALSE;
	    						flagRemove = FALSE;
	    						flagSort = FALSE;
	    						flagConvocar = FALSE;
	    					}
	    					else
	    					{
	    						printf("\nSe ha producido un error al guardar los datos.\n");
	    					}
	    				}
	    				else
	    				{
	    					printf("\nError. La lista no ha sido cargada.\n");
	    				}
	    				break;

	    			case 11:
	    				// SALIR
	    				if(flagAdd || flagEdit || flagRemove || flagSort || flagConvocar)
	    				{
	    					printf("\nSe ha detectado que hay cambios sin guardar.\n");

	    				    printf("0 = NO.\n");
	    				    printf("1 = SI.\n");

	    					getInt(&optionExit, "\nEsta seguro que desea salir sin guardar esoso cambios?: ", "\nError, solo numeros del 0 al 1. Vuelva a intentarlo: ", 0, 1);

	    					switch(optionExit)
	    					{
	    						case 0:
	    							option = 0;
	    							break;

	    						case 1:
	    							break;

	    						default:
	    							printf("\nError, se ha ingresado un valor invalido.");
	    							break;
	    					}
	    				}
	    				break;

	    			default:
	    				// ERROR
	    				printf("\nError, se ha ingresado un valor invalido.\n");
	    				break;
	    		}
    		}
    		printf("\n");
    		//clearScreen();
    		system("pause");
    		system("cls");
    		printf("\n");
    	}while(option != 11);
    }

    return 0;
}

