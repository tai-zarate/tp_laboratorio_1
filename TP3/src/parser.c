#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	int idContador;
	char idObtenido[50];
	int idVerificador;
	Employee* empleado;
	FILE* pIdSave;

	idContador = 0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		if((ll_isEmpty(pArrayListEmployee)) == 1)
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
			while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
				empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				ll_add(pArrayListEmployee, empleado);
				idContador++;
			}

			pIdSave = fopen("idSave.txt", "w");
			if(pIdSave!=NULL)
			{
				fprintf(pIdSave,"%d", idContador);
				fclose(pIdSave);
			}
		} else
		{
			ll_clear(pArrayListEmployee);
			pIdSave = fopen("idSave.txt", "w");
			if(pIdSave!=NULL)
			{
				fscanf(pIdSave,"%s", idObtenido);
				idVerificador = atoi(idObtenido);
				fclose(pIdSave);
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
			while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
				empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				ll_add(pArrayListEmployee, empleado);
				idContador++;
			}

			if(pIdSave!=NULL)
			{
				if(idContador>idVerificador)
				{
					fprintf(pIdSave,"%d", idContador);
				} else
				{
					fprintf(pIdSave,"%d", idVerificador);
				}
				fclose(pIdSave);
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
	int idContador;
	char idObtenido[50];
	int idVerificador;
	idContador=0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		if((ll_isEmpty(pArrayListEmployee)) == 1)
		{
			while(!feof(pFile))
			{
				empleado = employee_new();
				cant = fread(empleado,sizeof(Employee),1,pFile);
				if(cant == 1)
				{
					ll_add(pArrayListEmployee, empleado);
					idContador++;

				}
			}
			pIdSave = fopen("idSave.txt", "w");
			if(pIdSave!=NULL)
			{
				fprintf(pIdSave,"%d", idContador);
				fclose(pIdSave);
			}
		} else
		{
			ll_clear(pArrayListEmployee);
			pIdSave = fopen("idSave.txt", "w");
			if(pIdSave!=NULL)
			{
				fscanf(pIdSave,"%s", idObtenido);
				idVerificador = atoi(idObtenido);
				fclose(pIdSave);
			}
			while(!feof(pFile))
			{
				empleado = employee_new();
				cant = fread(empleado,sizeof(Employee),1,pFile);
				if(cant == 1)
				{
					ll_add(pArrayListEmployee, empleado);
					idContador++;
				}
			}
			pIdSave = fopen("idSave.txt", "w");
			if(pIdSave!=NULL)
			{
				if(idContador>idVerificador)
				{
					fprintf(pIdSave,"%d", idContador);
				} else
				{
					fprintf(pIdSave,"%d", idVerificador);
				}
				fclose(pIdSave);
			}
		}
	}

    return 1;
}
