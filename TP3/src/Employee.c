#include "Employee.h"

/** \brief Asigna el id del empleado
 *
 * \param empleado
 * \param id a asignar
 * \return int
 *
 */
int employee_setId(Employee* empleado,int id)
{
	int retorno;
	retorno = -1;

	if(empleado != NULL)
	{
		empleado->id = id;
		retorno = 0;
	}

	return retorno;
}

/** \brief Consigue el id de un empleado
 *
 * \param empleado
 * \param id a conseguir
 * \return int
 *
 */
int employee_getId(Employee* empleado,int* id)
{
	int retorno;
	retorno = -1;

	if(empleado!=NULL && id != NULL)
	{
		*id = empleado->id;
		retorno = 0;
	}

	return retorno;
}

/** \brief Asigna el nombre a un empleado
 *
 * \param empleado
 * \param nombre a asignar
 * \return int
 *
 */
int employee_setNombre(Employee* empleado,char* nombre)
{
	int retorno;
	retorno = -1;

	if(empleado != NULL)
	{
		strcpy(empleado->nombre,nombre);
		retorno = 0;
	}

	return retorno;
}

/** \brief Consigue el nombre a un empleado
 *
 * \param empleado
 * \param nombre a conseguir
 * \return int
 *
 */
int employee_getNombre(Employee* empleado,char* nombre)
{
	int retorno;
	retorno = -1;

	if(empleado!=NULL && nombre != NULL)
	{
		strcpy(nombre, empleado->nombre);
		retorno = 0;
	}

	return retorno;
}

/** \brief Asigna las horas de trabajo un empleado
 *
 * \param empleado
 * \param horas a asignar
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* empleado,int horasTrabajadas)
{
	int retorno;
	retorno = -1;

	if(empleado != NULL)
	{
		empleado->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

/** \brief Consigue las horas de trabajo un empleado
 *
 * \param empleado
 * \param horas a conseguir
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* empleado,int* horasTrabajadas)
{
	int retorno;
	retorno = -1;

	if(empleado!=NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = empleado->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

/** \brief Asigna un sueldo a un empleado
 *
 * \param empleado
 * \param sueldo a asignar
 * \return int
 *
 */
int employee_setSueldo(Employee* empleado,int sueldo)
{
	int retorno;
	retorno = -1;

	if(empleado != NULL)
	{
		empleado->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

/** \brief Consigue el sueldo de un empleado
 *
 * \param empleado
 * \param sueldo a conseguir
 * \return int
 *
 */
int employee_getSueldo(Employee* empleado,int* sueldo)
{
	int retorno;
	retorno = -1;

	if(empleado!=NULL && sueldo != NULL)
	{
		*sueldo = empleado->sueldo;
		retorno = 0;
	}

	return retorno;
}

/** \brief Muestra un empleado
 *
 * \param empleado
 *
 */
void employee_showOneEmployee(Employee* empleado)
{
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(empleado!=NULL)
	{
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horasTrabajadas);
		employee_getSueldo(empleado, &sueldo);

		printf("%7d %15s %15d %15d\n", id, nombre, horasTrabajadas, sueldo);
	}
}

/** \brief Constructor de un empleado
 *
 */
Employee* employee_new()
{
	Employee* pEmpleado;

	pEmpleado = (Employee*)malloc(sizeof(Employee));

	return pEmpleado;
}

/** \brief Constructor parametrizado de un empleado
 *
 * \param id a asignar
 * \param nombre a asignar
 * \param horas a asignar
 * \param sueldo a asignar
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmpleado;
	pEmpleado = employee_new();

	if(pEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		employee_setId(pEmpleado, atoi(idStr));
		employee_setNombre(pEmpleado, nombreStr);
		employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmpleado, atoi(sueldoStr));
	}

	return pEmpleado;
}

/** \brief Borra los datos de un empleado de la memoria dinamica
 *
 */

void employee_delete(Employee* empleado)
{
	if(empleado!=NULL)
	{
		free(empleado);
	}
}

/** \brief Compara los nombres para ordenar
 *
 * \param empleado
 * \param empleado
 */
int CompararPorNombre(Employee* empleadoI,Employee* empleadoJ)
{
	int comparacion;

	if(empleadoI!=NULL && empleadoJ!=NULL)
	{
		comparacion = strcmp(empleadoI->nombre,empleadoJ->nombre);
	}

	return comparacion;
}

/** \brief Compara los id para ordenar
 *
 * \param empleado
 * \param empleado
 */
int CompararPorId(Employee* empleadoI,Employee* empleadoJ)
{
	int comparacion;

	if(empleadoI!=NULL && empleadoJ!=NULL)
	{
		if(empleadoI->id > empleadoJ->id)
		{
			comparacion = 1;
		} else
		{
			if(empleadoI->id == empleadoJ->id)
			{
				comparacion = 0;
			} else
			{
				comparacion = -1;
			}
		}
	}

	return comparacion;
}

/** \brief Compara los sueldos para ordenar
 *
 * \param empleado
 * \param empleado
 */
int CompararPorSueldo(Employee* empleadoI,Employee* empleadoJ)
{
	int comparacion;

	if(empleadoI!=NULL && empleadoJ!=NULL)
	{
		if(empleadoI->sueldo > empleadoJ->sueldo)
		{
			comparacion = 1;
		} else
		{
			if(empleadoI->sueldo == empleadoJ->sueldo)
			{
				comparacion = 0;
			} else
			{
				comparacion = -1;
			}
		}
	}

	return comparacion;
}

/** \brief Compara las horas para ordenar
 *
 * \param empleado
 * \param empleado
 */
int CompararPorHorasTrabajadas(Employee* empleadoI,Employee* empleadoJ)
{
	int comparacion;

	if(empleadoI!=NULL && empleadoJ!=NULL)
	{
		if(empleadoI->horasTrabajadas > empleadoJ->horasTrabajadas)
		{
			comparacion = 1;
		} else
		{
			if(empleadoI->horasTrabajadas == empleadoJ->horasTrabajadas)
			{
				comparacion = 0;
			} else
			{
				comparacion = -1;
			}
		}
	}

	return comparacion;
}
