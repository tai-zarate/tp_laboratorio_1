/*
 * Funciones.c
 *
 *  Created on: 15 abr. 2021
 *      Author: Zarate Enzo Taiel
 */

#include "Funciones.h"
#include "Biblioteca.h"

int SumarNumeros (int numeroA, int numeroB)
{
	int resultado;

	resultado = numeroA + numeroB;

	return resultado;
}

int RestarNumeros (int numeroA, int numeroB)
{
	int resultado;

	resultado = numeroA - numeroB;

	return resultado;
}

float DivisionNumeros (int numeroA, int numeroB)
{
	float resultado;

	resultado = numeroA / (float)numeroB;

	return resultado;
}

int MultiplicarNumeros (int numeroA, int numeroB)
{
	int resultado;

	resultado = numeroA * numeroB;

	return resultado;
}

int FactorialNumero (int numero)
{
	int i;
	int resultado;
	resultado = 1;

	for(i=numero; i > 0; i--)
	{
		resultado *= i;
	}

	return resultado;
}
