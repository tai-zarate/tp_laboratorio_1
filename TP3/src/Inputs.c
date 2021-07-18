#include "Inputs.h"

/** \brief Carga un entero
 *
 * \param mensaje
 * \param variable donde guarda el valor
 * \return int
 */
int GetInt (char* msj, int* valor)
{
	int retorno;
	retorno = -1;

	if(msj!=NULL && valor!=NULL)
	{
		printf("%s", msj);
		scanf("%d", valor);

		retorno = 0;
	}

	return retorno;
}

/** \brief Carga un flotante
 *
 * \param mensaje
 * \param variable donde guarda el valor
 * \return int
 */
int GetFloat (char* msj, float* valor)
{
	int retorno;
	retorno = -1;

	if(msj!=NULL && valor!=NULL)
	{
		printf("%s", msj);
		scanf("%f", valor);

		retorno = 0;
	}

	return retorno;
}

/** \brief Carga un carácter
 *
 * \param mensaje
 * \param variable donde guarda el valor
 * \return int
 */
int GetChar (char* msj, char* valor)
{
	int retorno;
	retorno = -1;

	if(msj!=NULL && valor!=NULL)
	{
		printf("%s", msj);
		fflush(stdin);
		scanf("%c", valor);

		retorno = 0;
	}

	return retorno;
}

/** \brief Carga un string
 *
 * \param mensaje
 * \param variable donde guarda el valor
 * \return int
 */
int GetString(char* msj, char *valor)
{
	int retorno;
	retorno = -1;
	if(msj!=NULL && valor!=NULL)
	{
		printf(msj);
		fflush(stdin);
		scanf("%[^\n]", valor);

		retorno = 0;
	}
    return retorno;
}

/** \brief Carga un string donde no se permite ingresar números negativos
 *
 * \param mensaje
 * \param mensaje de error
 * \param variable donde guarda el valor
 * \return int
 */
int GetString_SinNegativo(char* msj, char* msjError, char* valor)
{
	int retorno;
	int verificar;
	retorno = -1;

	if(msj!=NULL && msjError!=NULL && valor!=NULL)
	{
		printf("%s", msj);
		fflush(stdin);
		scanf("%[^\n]", valor);
		verificar = SoloNumeros(valor);

		while(verificar == -1)
		{
			printf("ERROR.%s", msj);
			scanf("%s", valor);
			verificar = SoloNumeros(valor);
		}

		retorno = 0;
	}

	return retorno;
}

/**
 * @fn int SoloNumeros(char*)
 * @brief Verifica que cada caracter del string sea un número
 *
 * @param texto string
 * @return 0 si funcion, -1 si encontro algún caracter que no es un número
 */
int SoloNumeros(char* texto)
{
	int returnAux;
	int i;
	returnAux = 0;

	for(i=0; texto[i] != '\0'; i++)
	{
		if(texto[i] > '9' || texto[i] < '0')
		{
			returnAux = -1;
			break;
		}
	}

	return returnAux;
}

int GetStringSoloLetras(char* msj, char *valor)
{
	int retorno;
	int verificar;
	retorno = -1;
	if(msj!=NULL && valor!=NULL)
	{
		printf(msj);
		fflush(stdin);
		scanf("%[^\n]", valor);
		verificar = SoloLetras(valor);
		while(verificar == -1)
		{
			printf("ERROR.%s", msj);
			fflush(stdin);
			scanf("%[^\n]", valor);
			verificar = SoloLetras(valor);
		}

		retorno = 0;
	}
    return retorno;
}

int SoloLetras(char* texto)
{
	int returnAux;
	int i;
	returnAux = 0;

	for(i=0; texto[i] != '\0'; i++)
	{
		if((texto[i] > 'Z' || texto[i] < 'A') && (texto[i] > 'z' || texto[i] < 'a'))
		{
			returnAux = -1;
			break;
		}
	}

	return returnAux;
}
