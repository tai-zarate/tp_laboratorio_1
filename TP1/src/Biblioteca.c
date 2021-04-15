/*
 * Biblioteca.c
 *
 *  Created on: 13 abr. 2021
 *      Author: Zarate Enzo Taiel
 */

#include "Biblioteca.h"
#include "Funciones.h"

void MenuPrincipal()
{
	int opcion;
	int numeroA;
	int numeroB;

	int suma;
	int resta;
	float division;
	int multiplicacion;
	int factorialA;
	int factorialB;

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
			printf("1. Ingresar 1er operando (A=%d)\n", numeroA);
		}

		if (banderaNumeroB == 0)
		{
			printf("2. Ingresar 2do operando (B=y)\n");
		} else
		{
			printf("2. Ingresar 2do operando (B=%d)\n", numeroB);
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
				numeroA = TomarNumeros("Ingrese el número que quiere que sea A: ");
				banderaNumeroA = 1;

			break;
			case 2:
				numeroB = TomarNumeros("Ingrese el número que quiere que sea B: ");
				banderaNumeroB = 1;

			break;
			case 3:
					if (banderaNumeroA == 1 && banderaNumeroB == 1)
					{
						suma = SumarNumeros (numeroA, numeroB);
						resta = RestarNumeros (numeroA, numeroB);
						division = DivisionNumeros (numeroA, numeroB);
						multiplicacion = MultiplicarNumeros(numeroA, numeroB);
						factorialA = FactorialNumero (numeroA);
						factorialB =FactorialNumero (numeroB);
						banderaFunciones = 1;

						printf("Se han calculado todas las funciones.\n");
					} else
					{
						if (banderaNumeroA == 1 && banderaNumeroB == 0)
						{
							factorialA = FactorialNumero (numeroA);
							banderaFunciones = 2;

							printf("Se ha calculado solo el factorial del primer operando, los demás calculos no se harán porque no ha ingresado el segundo operando.\n");
						} else
						{
							if (banderaNumeroA == 0 && banderaNumeroB == 1)
								{
								factorialB =FactorialNumero (numeroB);
								banderaFunciones = 3;

								printf("Se ha calculado solo el factorial del segundo operando, los demás calculos porque no ha ingresado el primer operando.\n");
								} else
								{

									printf("Usted no ingresado ningún operando para calcular, ingrese al menos uno y vuelva intentar.\n");
								}
						}
					}
			break;
			case 4:

				MostrarResultados (suma, resta, division, numeroB,  multiplicacion, factorialA, factorialB, banderaFunciones);
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
	}

	return opcion;
}

int TomarNumeros (char prompt[])
{
    int numero;
    char confirmar;
    do
    {
        printf("%s", prompt);
        scanf("%d", &numero);
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

void MostrarResultados (int suma, int resta, float division, int numeroB, int multiplicacion, int factorialA, int factorialB, int banderaFuncion)
{
	switch(banderaFuncion)
	{
		case 0:
			printf("Usted no ingresado la opción 3 que calcula las operaciones, ingresela y vuelva intentar.\n");
		break;
		case 1:
			printf("El total de la suma es de: %d\n", suma);
			printf("El total de la resta es de: %d\n", resta);
			if(numeroB == 0)
			{
				printf("No se puede dividir un número por 0\n");
			} else
			{
				printf("El total de la división es de: %.1f\n", division);
			}
			printf("El total de la multiplicación es de: %d\n", multiplicacion);
			printf("El factorial del primer operando es: %d\n", factorialA);
			printf("El factorial del segundo operando es: %d\n", factorialB);
		break;
		case  2:
			printf("El segundo operando no se ha ingresado, por lo cuál la suma, resta, divisón y multiplicación no podrán ser reaizadas.\n");
			printf("El factorial del primer operando es: %d\n", factorialA);
		break;
		case 3:
			printf("El primer operando no se ha ingresado, por lo cuál la suma, resta, divisón y multiplicación no podrán ser reaizadas.\n");
			printf("El factorial del segundo operando es: %d\n", factorialB);
		break;
	}
}
