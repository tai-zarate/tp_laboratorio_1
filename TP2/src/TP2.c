/*
 ============================================================================
 Name        : TP2.c
 Author      : Zarate Taiel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
#define LEN 1000
#define TRUE -1
#define FALSE 1
#define UP 1
#define DOWN 0

int main(void) {
	setbuf(stdout, NULL);

	Employee empleados[LEN];

	int opcion;
	int empleado;
	int index;
	int opcionMostrar;
	int contadorIteraciones;
	char continuar;

	InitEmployees(empleados, LEN);

	do
	{
		printf("1. ALTA\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. MOSTRAR\n");
		printf("5. Salir\n");
		opcion =  GetInt("Ingrese una opción: ");

		switch(opcion)
		{
			case 1:
				do
				{
					index = BuscarLibre(empleados, LEN);
					if(index != TRUE)
						{
							empleado = AddEmployee(empleados, LEN);
							continuar = GetChar("Desea agregar otro? (s/n): ");
						} else
						{
							printf("No hay más espacio\n");
						}
				} while(continuar == 's' && index != TRUE);
			break;
			case 2:
				do
				{
					contadorIteraciones = ContadorIsEmptyEmpleados(empleados, LEN);
					if(contadorIteraciones != 0)
					{
						RemoveEmployee(empleados, LEN);
						continuar = GetChar("Desea dar de baja otro? (s/n): ");
					} else
					{
						printf("No hay más empleados para dar de baja\n");
					}
				}while(continuar == 's' && contadorIteraciones != 0);
			break;
			case 3:
				do
				{
					contadorIteraciones = ContadorIsEmptyEmpleados(empleados, LEN);
					if(contadorIteraciones != 0)
					{
						ModificarEmpleado(empleados, LEN);
						continuar = GetChar("Desea modificar otro? (s/n): ");
					} else
					{
						printf("No hay empleados para modificar\n");
					}
				}while(continuar == 's' && contadorIteraciones != 0);
			break;
			case 4:
				contadorIteraciones = ContadorIsEmptyEmpleados(empleados, LEN);
				if(contadorIteraciones != 0)
				{
					printf("1.Listado de empleados\n");
					printf("2.Promedio de salarios\n");
					printf("3.Salir\n");
					opcionMostrar = GetInt("Ingrese una opción: ");
					switch(opcionMostrar)
					{
						case 1:
							SortEmployees(empleados, LEN, UP);
							PrintEmployees(empleados, LEN);
						break;
						case 2:
							PromedioSalarios(empleados, LEN);
						break;
					}
				} else
				{
					printf("No hay empleados para mostrar\n");
				}
			break;
		}
	}while(opcion!=5);

	return EXIT_SUCCESS;
}

