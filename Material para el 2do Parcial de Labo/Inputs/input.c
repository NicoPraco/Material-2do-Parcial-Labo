#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

void clearScreen()
{
	int i;
    for (i = 0; i < 1; i++)
    {
    	printf( "\n\n\n\n\n" );
    }
}

////////////////////////////////////////////////////////////////////////////////////

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            else
            {
                printf("%s \a\a", eMessage);
            }
            fflush(stdin);
            indice = scanf("%d%c", input, &temp);


        }while((indice != 2 || temp != '\n') || (*input < lowLimit || *input > hiLimit));

        retorno = 0;
    }

    return retorno;

}

////////////////////////////////////////////////////////////////////////////////////

int getShort(short* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
	int toReturn = -1;
	int index;
	int flagWhile = 0;

	char temp;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            else
            {
                printf("%s \a\a", eMessage);
            }
            fflush(stdin);
            index = scanf("%hd%c", input, &temp);


        }while((index != 2 || temp != '\n') || (*input < lowLimit || *input > hiLimit));

        toReturn = 0;
    }

	return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int retorno = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            else
            {
                printf("%s \a\a", eMessage);
            }
            fflush(stdin);
            indice = scanf("%f%c", input, &temp);


        }while((indice != 2 || temp != '\n') || (*input < lowLimit || *input > hiLimit));

        retorno = 0;
    }

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////////

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int retorno = -1;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            else
            {
                printf("\a\a %s ", eMessage);
            }
            fflush(stdin);
            scanf("%c%c", input, &temp);


        }while( (temp != '\n') || (*input < lowLimit || *input > hiLimit) );

        retorno = 0;
    }

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////////

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
     int retorno = -1;
     int length;
     int flagWhile = 0;

     if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
     {
         do
         {
             if(flagWhile == 0)
             {
                 printf("%s", message);

                 flagWhile = 1;
             }
             else
             {
                 printf("%s \a\a", eMessage);
             }
             fgets(input, hiLimit, stdin);
             length = strlen(input);

             if(input[length - 1] == '\n')
             {
                 input[length - 1] = '\0';
             }

             length = strlen(input);

         }while(length < lowLimit || length > hiLimit);

         retorno = 0;
     }

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////////

int getIntNoVal(int* input, char message[])
{
	int toReturn = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            fflush(stdin);
            indice = scanf("%d%c", input, &temp);


        }while((indice != 2 || temp != '\n'));

        toReturn = 0;
    }

	return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////

int getFloatNoVal(float* input,char message[])
{
    int toReturn = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
			fflush(stdin);
            indice = scanf("%f%c", input, &temp);


        }while((indice != 2 || temp != '\n'));

        toReturn = 0;
    }

    return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////

int isNumInt(char* input, int limit)
{
	int toReturn = -1;

	int i;

	if(input != NULL && limit > 0)
	{
		toReturn = 1;

		for(i = 0; i < limit && input[i] != '\0'; i++)
		{
			if(!isdigit(input[i]))
			{
				if(i == 0 && input[i] == '+')
				{
					continue;
				}

				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}


int isNumFloat(char* input, int limit)
{
	int toReturn = -1;

	int i;
	int flagDot = 0;  // TIENE UN PUNTO

	if(input != NULL && limit > 0)
	{
		toReturn = 1;

		for(i = 0; i < limit && input[i] != '\0'; i++)
		{
			if(!isdigit(input[i]))
			{
				if(i == 0 && input[i] == '+')
				{
					continue;
				}

				if(input[i] == '.' && flagDot == 0)
				{
					flagDot = 1;

					continue;
				}

				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}

int isStringAlphabetical(char* input, int limit)
{
	int toReturn = -1;

	int i;

	if(input != NULL && limit > 0)
	{
		toReturn = 1;

		for(i = 0; i < limit && input[i] != '\0'; i++)
		{
			if(!isalpha(input[i]) && !isspace(input[i]) && input[i] != '-')
			{
				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}
