/*
 * Biblioteca.c
 *
 *  Created on: 13 abr. 2021
 *      Author: Zarate Taiel
 */

#include "Biblioteca.h"

void MenuPrincipal()
{
	int opcion;
	float numeroA;
	float numeroB;
	float suma;
	float resta;
	float division;
	int banderaNumeroA;
	int banderaNumeroB;
	int banderaFunciones;

	banderaNumeroA = 0;
	banderaNumeroB = 0;
	banderaFunciones = 0;

	do
	{
		if (banderaNumeroA == 0)
		{
			printf("1. Ingresar 1er operando (A=x)\n");
		} else
		{
			printf("1. Ingresar 1er operando (A=%.2f)\n", numeroA);
		}

		if (banderaNumeroB == 0)
		{
			printf("2. Ingresar 2do operando (B=y)\n");
		} else
		{
			printf("2. Ingresar 2do operando (B=%.2f)\n", numeroB);
		}
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		opcion = VerificarOpcion(opcion);

		switch(opcion)
		{
			case 1:
				numeroA = TomarEnteros("Ingrese el número que quiere que sea A: ");
				banderaNumeroA = 1;
			break;
			case 2:
				numeroB = TomarEnteros("Ingrese el número que quiere que sea B: ");
				banderaNumeroB = 1;
			break;
			case 3:
				suma = SumarNumeros (numeroA, numeroB);
				resta = RestarNumeros (numeroA, numeroB);
				division =DivisionNumeros (numeroA, numeroB);
				banderaFunciones = 1;
			break;
			case 4:
				MostrarResultados (suma, resta, division, banderaFunciones, banderaNumeroA, banderaNumeroB);
			break;
		}
	}while(opcion!=5);
}

int VerificarOpcion(int opcion)
{
	while(opcion<1 || opcion>5)
	{
		printf("ERROR.Esa opción no existe\nElija una opcion: ");
		scanf("%d", &opcion);

		return opcion;
	}
}

float TomarEnteros (char prompt[])
{
    float numero;
    char confirmar;
    do
    {
        printf("%s", prompt);
        scanf("%f", &numero);
        printf("Confirme que este es el número que desea ingresar (s/n): ");
        fflush(stdin);
        scanf("%c", &confirmar);
        confirmar = VerificarConfimarcion(confirmar);
    }while(confirmar != 's');

    return numero;
}

char VerificarConfimarcion(char letra)
{
    while(letra != 's' && letra != 'n')
    {
        printf("ERROR.Confirme que este es el número que desea ingresar (s/n): ");
        fflush(stdin);
        scanf("%c", &letra);
    }
    return letra;
}

float SumarNumeros (float numeroA, float numeroB)
{
	float resultado;

	resultado = numeroA + numeroB;

	return resultado;
}

float RestarNumeros (float numeroA, float numeroB)
{
	float resultado;

	resultado = numeroA - numeroB;

	return resultado;
}

float DivisionNumeros (float numeroA, float numeroB)
{
	float resultado;

	if(numeroB == 0)
	{
		return 0;
	}

	resultado =numeroA / numeroB;

	return resultado;
}

void MostrarResultados (float suma, float resta, float division, int banderaFuncion, int banderaA, int banderaB)
{
	switch(banderaFuncion)
	{
		case 0:
			printf("Usted no ingresado la opción 3 que calcula las operaciones, ingresela y vuelva intentar\n");
		break;
		case 1:
			if (banderaA == 1 && banderaB ==1)
				{
					printf("El total de la suma es de: %.2f\n", suma);
					printf("El total de la resta es de: %.2f\n", resta);
					if(division == 0)
					{
						printf("No se puede dividir un número por 0\n");
					} else
					{
						printf("El total de la división es de: %.2f\n", division);
					}
				} else
				{
					printf("Uno de los operando no ha sido ingresado\n");
				}
		break;
	}
}
