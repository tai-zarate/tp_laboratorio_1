#include "ArrayEmployees.h"

int InitEmployees(Employee empleados[], int len)
{
    int i;

    for(i=0; i<len;i++)
	{
    	empleados[i].isEmpty = TRUE;
	}

    return 0;
}

int BuscarLibre(Employee empleados[], int len)
{
    int i;
    int index;
    index = TRUE;
    for(i=0; i<len;i++)
	{
		if(empleados[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}

    return index;
}

Employee PedirDatos(Employee empleados[], int len)
{
	Employee empleado;

	empleado.id = AsignarIdEmpleado(empleados, len);

	PedirNombre("Ingrese el nombre: ", empleado.name);

	PedirNombre("Ingrese el apellido: ", empleado.lastName);

	empleado.salary = PedirPrecio("Ingrese su salario: ");

	empleado.sector = PedirSector("Ingrese el sector: ");

    empleado.isEmpty = FALSE;

    printf("Se agregó con exíto\n");

    return empleado;
}

int AsignarIdEmpleado(Employee empleados[], int len)
{
	int i;
	int numero;

	numero = ContadorIsEmptyEmpleados(empleados, len);

	for(i=0;i<len;i++)
	{
		if(empleados[i].isEmpty == FALSE)
		{
			if(numero == empleados[i].id)
			{
				numero = numero+1;
			}
		}
	}

	return numero;
}

int ContadorIsEmptyEmpleados(Employee empleados[], int len)
{
    int i;
    int contador;

    contador = 0;
    for(i=0; i<len; i++)
    {
        if(empleados[i].isEmpty == FALSE)
        {
            contador++;
        }
    }
    return contador;
}

void PedirNombre(char msj[], char *nombre)
{
	char confirmar;
	GetString(msj, nombre);
	nombre[0] = toupper(nombre[0]);

	confirmar = GetChar("Seguro/a (s/n): ");

	while(confirmar != 's')
	{
		GetString(msj, nombre);
		nombre[0] = toupper(nombre[0]);
		confirmar = GetChar("Seguro/a (s/n): ");
	}
}

float PedirPrecio (char msj[])
{
	float precio;
	char confirmar;

	do
	{
		precio = GetFloat(msj);

		while(precio < 0)
		{
			 precio = GetFloat("ERROR.El precio no puede ser negativos: ");
		}

		confirmar = GetChar("Seguro/a? (s/n): ");

	}while(confirmar != 's');

    return precio;
}

int PedirSector (char msj[])
{
	int sector;
	char confirmar;

	do
	{
		sector = GetInt(msj);
		confirmar = GetChar("Seguro/a? (s/n): ");
	}while(confirmar != 's');

    return sector;
}

int AddEmployee(Employee empleados[], int len)
{
    int i;

    i = BuscarLibre (empleados, len);

    if(i != TRUE)
    {
    	empleados[i] = PedirDatos(empleados, len);
    }

    return i;
}

int FindEmployeeById(int idIngreasado,Employee empleados[], int len)
{
    int i;
    int resultado;


    resultado = TRUE;

    for(i=0;i<len;i++)
    {
        if(idIngreasado == empleados[i].id && empleados[i].isEmpty == FALSE)
        {
            resultado = FALSE;
        }
    }
    return resultado;
}

void RemoveEmployee(Employee empleados[], int len)
{
    int i;
    int idIngresado;
    int verificar;
    char confirmar;

    do
    {
    	PrintEmployees(empleados, len);
		idIngresado = GetInt("Ingrese el id del que desea dar de baja: ");
		verificar = FindEmployeeById(idIngresado, empleados, len);

		while(verificar == TRUE)
		{
			idIngresado = GetInt("ERROR. Ese id no existe: ");
			verificar = FindEmployeeById(idIngresado, empleados, len);
		}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');

	for(i=0; i<=len; i++)
	{
		if(idIngresado == empleados[i].id && empleados[i].isEmpty == FALSE)
		{
			empleados[i].isEmpty = TRUE;
			break;
		}
	}

	printf("Se ha dado de baja con exito.\n");
}

void ModificarEmpleado(Employee empleados[], int len)
{
	int i;
	int idIngresado;
	int verificar;
	int opcion;
	char confirmar;

	do
	{
		PrintEmployees(empleados, len);
		idIngresado = GetInt("Ingrese el id del que desea dar de baja: ");
		verificar = FindEmployeeById(idIngresado, empleados, len);

		while(verificar == TRUE)
		{
			idIngresado = GetInt("ERROR. Ese id no existe: ");
			verificar = FindEmployeeById(idIngresado, empleados, len);
		}

		confirmar = GetChar("Seguro/a (s/n): ");
	}while(confirmar != 's');

	for(i=0; i<len; i++)
	{
		if(idIngresado == empleados[i].id)
		{
			do
				{
					printf("1. Cambiar nombre\n");
					printf("2. Cambiar apellido\n");
					printf("3. Cambiar salario\n");
					printf("4. Cambiar sector\n");
					printf("5. Salir\n");
					opcion = GetInt("Ingrese una opción: ");

					switch(opcion)
					{
						case 1:
							PedirNombre("Ingrese el nombre: ", empleados[i].name);
							printf("Se realizo el cambio\n");
						break;
						case 2:
							PedirNombre("Ingrese el nombre: ", empleados[i].lastName);
							printf("Se realizo el cambio\n");
						break;
						case 3:
							empleados[i].salary = PedirPrecio("Ingrese su salario: ");
							printf("Se realizo el cambio\n");
						break;
						case 4:
							empleados[i].sector = PedirSector("Ingrese el sector: ");
							printf("Se realizo el cambio\n");
						break;
					}
				}while(opcion!=5);
			break;
		}
	}

}

void MostrarUnEmpleado(Employee empleado)
{
	printf("Id: %d ---- Nombre: %s ---- Apellido: %s ---- Salario: %.1f ---- Sector: %d\n", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}

void PrintEmployees(Employee empleados[], int len)
{
	int i;

	for(i=0; i<len; i++)
	{
		if(empleados[i].isEmpty == FALSE)
		{
			MostrarUnEmpleado(empleados[i]);
		}
	}
}

void SortEmployees(Employee empleados[], int len, int order)
{
	int i;
	int j;
	Employee auxiliar;

	switch(order)
	{
		case UP:
		for(i=0; i<len-1;i++)
		{
			for(j=i+1; j<len;j++)
			{
				if(empleados[i].isEmpty==FALSE && empleados[j].isEmpty == FALSE)
				{
					if(empleados[i].sector>empleados[j].sector)
					{
						auxiliar = empleados[i];
						empleados[i] = empleados[j];
						empleados[j] = auxiliar;
					} else
					{
						if(strcmp(empleados[i].lastName,empleados[j].lastName) > 0)
						{
							auxiliar = empleados[i];
							empleados[i] = empleados[j];
							empleados[j] = auxiliar;
						}
					}
				}
			}
		}
		break;
		case DOWN:
		for(i=0; i<len-1;i++)
		{
			for(j=i+1; j<len;j++)
			{
				if(empleados[i].isEmpty==FALSE && empleados[j].isEmpty == FALSE)
				{
					if(empleados[i].sector<empleados[j].sector)
					{
						auxiliar = empleados[i];
						empleados[i] = empleados[j];
						empleados[j] = auxiliar;
					} else
					{
						if(strcmp(empleados[i].lastName,empleados[j].lastName) > 0)
						{
							auxiliar = empleados[i];
							empleados[i] = empleados[j];
							empleados[j] = auxiliar;
						}
					}
				}
			}
		}
		break;
	}
}

float SumaSalarios(Employee empleados[], int len)
{
    int i;
    float sumaSalarios;

    sumaSalarios = 0;

    for(i=0; i<len; i++)
    {
    	if(empleados[i].isEmpty == FALSE)
    	{
    		sumaSalarios = sumaSalarios + empleados[i].salary;
    	}
    }

    return sumaSalarios;
}

float Promedio(float suma,int division)
{
    float promedio;

    if(suma!=0)
    {
        promedio = suma/division;
    } else
    {
        promedio = 0;
    }


    return promedio;
}

float CalcularPromedioSalario(Employee empleados[], int len)
{
    int contador;
    float sumaSalarios;
    float promedio;

    contador = ContadorIsEmptyEmpleados(empleados, len);
    sumaSalarios = SumaSalarios(empleados, len);
    promedio = Promedio(sumaSalarios, contador);

    return promedio;
}

void PromedioSalarios(Employee empleados[], int len)
{
	float totalSalarios;
	float promedioSalarios;

	totalSalarios = SumaSalarios(empleados, len);
	promedioSalarios = CalcularPromedioSalario(empleados, len);

	printf("La suma de todos los salarios es de un total de: %.2f\n", totalSalarios);
	printf("El salario promedio es de: %.2f\n", promedioSalarios);

	EmpleadosConSalarioMayor (empleados, len, promedioSalarios);
}

void EmpleadosConSalarioMayor (Employee empleados[], int len, float promedio)
{
	int i;
	int contador;

	contador = 0;

	for(i=0;i<len;i++)
	{
		if(empleados[i].salary > promedio && empleados[i].isEmpty == FALSE)
		{
			contador++;
		}
	}

	if(contador == 0)
	{
		printf("No hay empleados que superen el salario promedio\n");
	} else
	{
		printf("Los empleados que superan el salrio promedio son:\n");
		for(i=0;i<len;i++)
		{
			if(empleados[i].salary > promedio && empleados[i].isEmpty == FALSE)
			{
				MostrarUnEmpleado(empleados[i]);
			}
		}
	}
}
