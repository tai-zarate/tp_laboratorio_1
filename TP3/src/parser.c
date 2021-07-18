#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	int bandera = 0;
	int maximoId;
	Employee* empleado;
	FILE* pIdSave;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
			empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, empleado);
			if(bandera==0 || maximoId < atoi(id))
			{
				maximoId = atoi(id);
				bandera = 1;
				pIdSave = fopen("idSave.txt", "w");
				if(pIdSave!=NULL)
				{
					fprintf(pIdSave,"%d", maximoId);
					fclose(pIdSave);
				}
			}
		}
	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int cant;
	FILE* pIdSave;
	int bandera = 0;
	int maximoId;
	int idObtenido;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			empleado = employee_new();
			cant = fread(empleado,sizeof(Employee),1,pFile);
			if(cant == 1)
			{
				ll_add(pArrayListEmployee, empleado);
				employee_getId(empleado, &idObtenido);
				if(bandera == 0 || maximoId < idObtenido)
				{
					maximoId = idObtenido;
					bandera = 1;
					pIdSave = fopen("idSave.txt", "w");
					if(pIdSave!=NULL)
					{
						fprintf(pIdSave,"%d", maximoId);
						fclose(pIdSave);
					}
				}
			}
		}
	}

    return 1;
}
