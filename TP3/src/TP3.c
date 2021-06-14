/*
 ============================================================================
 Name        : TP3Practica.c
 Author      : Taiel Zarate
 Version     :
 Copyright   : Your copyright notice
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
	setbuf(stdout, NULL);
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    	printf("3. Alta de empleado\n");
    	printf("4. Modificar datos de empleado\n");
    	printf("5. Baja de empleado\n");
    	printf("6. Listar empleados\n");
    	printf("7. Ordenar empleados\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    	printf("10. Salir\n");
    	GetInt("Seleccione una opción: ", &option);
    	{
    		switch(option)
			{
				case 1:
					controller_loadFromText("data.csv",listaEmpleados);
				break;
				case 2:
					controller_loadFromBinary("data.bin", listaEmpleados);
				break;
				case 3:
					controller_addEmployee(listaEmpleados);
				break;
				case 4:
					controller_editEmployee(listaEmpleados);
				break;
				case 5:
					controller_removeEmployee(listaEmpleados);
				break;
				case 6:
					controller_ListEmployee(listaEmpleados);
				break;
				case 7:
					controller_sortEmployee(listaEmpleados);
				break;
				case 8:
					controller_saveAsText("data.csv", listaEmpleados);
				break;
				case 9:
					controller_saveAsBinary("data.bin", listaEmpleados);
				break;
			}
    	}
    }while(option != 10);
    return 0;
}
