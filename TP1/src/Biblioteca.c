/*
 * Biblioteca.c
 *
 *  Created on: 13 abr. 2021
 *      Author: usuario
 */

#include "Biblioteca.h"

void MenuPrincipal()
{
	int opcion;
	int numeroA;
	int numeroB;

	do
	{
		printf("1. Ingresar 1er operando (A=x)\n");
		printf("2. Ingresar 2do operando (B=y)\n");
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				numeroA = TomarEnteros("Ingrese el número que quiere que sea A: ");
			break;
			case 2:
				numeroB = TomarEnteros("Ingrese el número que quiere que sea B: ");
			break;
			case 3:

			break;
			case 4:

			break;
		}
	}while(opcion!=5);
}

int TomarEnteros (char prompt[])
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
