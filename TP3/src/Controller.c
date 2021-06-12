#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;

	archivo = fopen(path,"r");
	ll_clear(pArrayListEmployee);
	if(archivo != NULL)
	{
		parser_EmployeeFromText(archivo, pArrayListEmployee);
		fclose(archivo);
	}
	printf("Se han cargado todos los empleados\n");
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;

	archivo = fopen(path,"rb");
	if(archivo != NULL)
	{
		parser_EmployeeFromBinary(archivo, pArrayListEmployee);
		fclose(archivo);
	}
	printf("Se han cargado todos los empleados\n");

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	FILE* pIdSave;
	char idStr[128];
	char nombreStr[128];
	char horasTrabajadasStr[128];
	char sueldoStr[128];
	int idSiguiente;

	if(pArrayListEmployee!=NULL)
	{
		pIdSave = fopen("idSave.txt", "r");
		if(pIdSave!=NULL)
		{
			fscanf(pIdSave,"%s", idStr);
			fclose(pIdSave);
		}
		sprintf(idStr, "%d", atoi(idStr)+1);
		GetString("Ingrese el nombre: ", nombreStr);
		GetString_SinNegativo("Ingrese la nueva cantidad de horas trabajadas: ", "Error. Asegurese de ingreser un número mayor a 0: ", horasTrabajadasStr);
		GetString_SinNegativo("Ingrese el nuevo sueldo: ", "Error. Asegurese de ingreser un número mayor a 0: ", sueldoStr);

		empleado = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

		ll_add(pArrayListEmployee, empleado);

		idSiguiente = atoi(idStr);

		pIdSave = fopen("idSave.txt", "w");
		if(pIdSave!=NULL)
		{
			fprintf(pIdSave,"%d", idSiguiente);
			fclose(pIdSave);
		}
	}

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int flag;
	Employee* aux;
	int id;
	int indice;
	int opcion;
	char nombreNuevo[128];
	char horasTrabajadasNuevo[128];
	char sueldoNuevo[128];

	if(pArrayListEmployee!=NULL)
	{
		do
		{
			controller_ListEmployee(pArrayListEmployee);
			GetInt("Ingrese el id del trabajador que quiere dar de baja: ", &id);
			flag = existencia_id(pArrayListEmployee, id, &indice);
			if(flag == -1)
			{
				printf("El id que se ingreso no existe\n");
			} else
			{
				aux = (Employee*)ll_get(pArrayListEmployee, indice);
				do
				{
					printf("1.Modificar nombre\n");
					printf("2.Modificar horas trabajadas\n");
					printf("3.Modificar sueldos\n");
					printf("4.Salir\n");
					GetInt("Ingrese la opción de lo que desea modificar: ", &opcion);

					switch(opcion)
					{
						case 1:
							GetString("Ingrese el nuevo nombre: ", nombreNuevo);
							employee_setNombre(aux, nombreNuevo);
							printf("Se ha moidificado el nombre con exito\n");
						break;
						case 2:
							GetString_SinNegativo("Ingrese la nueva cantidad de horas trabajadas: ", "Error. Asegurese de ingreser solamente números y que las horas sean mayor a 0: ", horasTrabajadasNuevo);
							employee_setHorasTrabajadas(aux, atoi(horasTrabajadasNuevo));
						break;
						case 3:
							GetString_SinNegativo("Ingrese el nuevo sueldo: ", "Error. Asegurese de ingreser solamente números y que las horas sean mayor a 0: ", sueldoNuevo);
							employee_setSueldo(aux, atoi(sueldoNuevo));
						break;
					}
				}while(opcion!=4);
			}
		}while(flag == -1);
		printf("Se ha modificado con exito\n");
	}

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int flag;
	Employee* aux;
	int id;
	int indice;

	if(pArrayListEmployee!=NULL)
	{
		do
		{
			controller_ListEmployee(pArrayListEmployee);
			GetInt("Ingrese el id del trabajador que quiere dar de baja: ", &id);
			flag = existencia_id(pArrayListEmployee, id, &indice);
			if(flag == -1)
			{
				printf("El id que se ingreso no existe\n");
			} else
			{
				aux = (Employee*)ll_pop(pArrayListEmployee, indice);
				employee_delete(aux);
			}
		}while(flag == -1);
		printf("Se ha dado de baja con exito\n");
	}

    return 1;
}
/** \brief Verificar ID existente
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int existencia_id(LinkedList* pArrayListEmployee, int idIngresado, int* index)
{
	int retorno;
	int i;
	int len;
	int idComparacion;
	Employee* verificacion;

	retorno = -1;

	if(pArrayListEmployee != NULL && index!=NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			verificacion = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(verificacion, &idComparacion);
			if(idIngresado == idComparacion)
			{
				*index = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int len;
    int i;

    if(pArrayListEmployee!=NULL)
    {
    	len = ll_len(pArrayListEmployee);

		for(i=0; i<len; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);
			employee_showOneEmployee(aux);
		}
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	if(pArrayListEmployee!=NULL)
	{
		printf("1. Ordenar por ID\n");
		printf("2. Ordenar por orden alfabetico\n");
		printf("3. Ordenar por horas trabajadas\n");
		printf("4. Ordenar por sueldos\n");
		GetInt("Ingrese la opción en la que quiere ordenar: ", &opcion);

		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListEmployee, CompararPorId, 1);
				printf("Se han ordenado por ID con exito.\n");
			break;
			case 2:
				ll_sort(pArrayListEmployee, CompararPorNombre, 1);
				printf("Se han ordenado por orden alfabetico con exito.\n");
			break;
			case 3:
				ll_sort(pArrayListEmployee, CompararPorHorasTrabajadas, 1);
				printf("Se han ordenado por horas trabajadas con exito.\n");
			break;
			case 4:
				ll_sort(pArrayListEmployee, CompararPorSueldo, 1);
				printf("Se han ordenado por sueldos con exito.\n");
			break;
			default:
				printf("La opción que ingreso no se encuentra disponible\n");
			break;
		}
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	Employee* aux;
	int i;
	int len;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		archivo = fopen(path, "w");
		len = ll_len(pArrayListEmployee);
		if(archivo!=NULL)
		{
			fprintf(archivo, "Id,Nombre,Horas trabajadas, sueldo\n");
			for(i=0;i<len;i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(aux, &id);
				employee_getNombre(aux, nombre);
				employee_getHorasTrabajadas(aux, &horasTrabajadas);
				employee_getSueldo(aux, &sueldo);
				fprintf(archivo,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
			}
			printf("Se han guardado todos los empleados en modo texto.\n");
			fclose(archivo);
		}
	}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	Employee* aux;
	int i;
	int len;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		archivo = fopen(path, "wb");
		len = ll_len(pArrayListEmployee);
		if(archivo!=NULL)
		{
			for(i=0;i<len;i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(aux,sizeof(Employee),1,archivo);
			}
			printf("Se han guardado todos los empleados en modo binario.\n");
			fclose(archivo);
		}
	}

    return 1;
}

