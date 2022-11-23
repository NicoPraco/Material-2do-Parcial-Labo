/**
 * brief Limpia la consola.
 */
void clearScreen();

/**
* \brief Solicita un numero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un numero al usuario y lo valida
*
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
*
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getShort(short* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un numero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud minima de la cadena
* \param hiLimit Longitud maxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

////////////////////////////////////////////////////////////////////////////////////

/**
* \brief Solicita un numero al usuario y no lo valida.
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getIntNoVal(int* input, char message[]);

/**
* \brief Solicita un numero al usuario y no lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloatNoVal(float* input,char message[]);

////////////////////////////////////////////////////////////////////////////////////

int isNumInt(char* input, int limit);

int isNumFloat(char* input, int limit);

int isStringAlphabetical(char* input, int limit);
