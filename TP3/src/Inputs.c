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
	int numero;
	retorno = -1;

	if(msj!=NULL && msjError!=NULL && valor!=NULL)
	{
		printf("%s", msj);
		scanf("%s", valor);

		numero = atoi(valor);
		while(numero <= 0)
		{
			printf("%s", msjError);
			scanf("%s", valor);
			numero = atoi(valor);
		}

		retorno = 0;
	}

	return retorno;
}


