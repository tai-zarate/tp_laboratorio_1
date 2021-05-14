#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"

#define LEN 1000
#define TRUE -1
#define FALSE 1
#define UP 1
#define DOWN 0

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;
/**
 * Inicializa los isEmpty del array de empleados en TRUE
 *
 * @param Array de empleados
 * @param Tamaño del array
 * @return (0) if Ok
 */
int InitEmployees(Employee[], int);
/**
 * Busca un isEmpty que tenga el isEmpty en TRUE
 *
 * @param Array de empleados
 * @param Tamaño del array
 * @return Indice del empleado encontrado
 */
int BuscarLibre (Employee[], int);
/**
 * Carga los datos de un nuevo empleado ingresado
 *
 * @param Array de empleados
 * @param Tamaño del array
 * @return Empleado con los datos cargados
 */
Employee PedirDatos (Employee[], int);

/**
 * Crea un id autoincremental y verifica que no se repitan los id
 *
 * @param Array de empleados
 * @param Tamaño del array
 * @return Id
 */
int AsignarIdEmpleado(Employee[], int);

/**
 * Cuenta los isEmpty que esten ocupados del array de empleados
 *
 * @param Array de empleados
 * @param Tamaño del array
 * @return Cantidad de empleados
 */
int ContadorIsEmptyEmpleados (Employee[], int);

/**
 * Pide nombre o apellido y confirma si es el deseado
 *
 * @param Mensaje
 * @param Guarda el array de caracteres
 */
void PedirNombre(char[], char *);

/**
 * Pide precio, verifica que no sea negativo y confirma que lo ingresado es lo deseado
 * @param msj
 * @return Precio ingresado
 */
float PedirPrecio (char msj[]);

/**
 * Pide sector y confirma que lo ingresado es lo deseado
 * @param msj
 * @return Sector ingresado
 */
int PedirSector (char msj[]);

/**
 * Da de alta un nuevo empleado
 *
 * @param Array de empleados
 * @param Tamaño del array
 * @return Indice que ocupa ese nuevo empleado cargado en el array
 */
int AddEmployee (Employee[], int);

/**
 * Verifica que el id de servicio ingresado existe
 * @param id ingresado
 * @param Array de trabajos
 * @param Tamaño del array
 * @return
 */
int FindEmployeeById(int,Employee[], int);

/**
 * Da de baja un empleado seleccionado por el id correspondiente
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void RemoveEmployee (Employee[], int);

/**
 * Modifica los datos de un empleado seleccionado por el id correspondiente
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void ModificarEmpleado(Employee[], int);

/**
 * Muestra un empleado seleccionado
 *
 * @param Empleado seleccionado
 */
void MostrarUnEmpleado(Employee);

/**
 * Muestra todos los empleados que tengan su isEmpty == FALSE
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void PrintEmployees(Employee[], int);

/**
 * Ordena los empleados por sector, si hay coincidencia de sector, los ordena alfabeticamente por apellido
 *
 * @param Array de trabajos
 * @param Tamaño del array
 * @param Si queremos ordenarlo de menor a mayor por sector, se coloca el define UP, sino el define DOWN
 */
void SortEmployees(Employee[], int, int);

/**
 * Hace la suma de todos los salarios
 *
 * @param Array de trabajos
 * @param Tamaño del array
 * @return Total de la suma de todos los salarios
 */
float SumaSalarios(Employee[], int);

/**
 * Calcula un promedio
 *
 * @param Dividendo
 * @param Divisor
 * @return Resultado de la división
 */
float Promedio(float, int);

/**
 * Calcula el salario promedio sumando todos los salarios y lo divide por la cantidad de empleados
 *
 * @param Array de trabajos
 * @param Tamaño del array
 * @return Salario promedio
 */
float CalcularPromedioSalario(Employee[], int);

/**
 * Muestra el total de la suma de todos los salarios, el salario promedio y que empleados superan el salario promedio
 *
 * @param Array de trabajos
 * @param Tamaño del array
 */
void PromedioSalarios(Employee[], int);

/**
 * Verifica si hay empleados que superan el salario promedio y muestran cuales son
 *
 * @param Array de trabajos
 * @param Tamaño del array
 * @param Salario promedio
 */
void EmpleadosConSalarioMayor (Employee[], int, float);
