#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);//Ya est�
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);//Ya est�
int controller_editEmployee(LinkedList* pArrayListEmployee);//Ya est�
int controller_removeEmployee(LinkedList* pArrayListEmployee);//Ya est�
int controller_ListEmployee(LinkedList* pArrayListEmployee);//Ya est�
int controller_sortEmployee(LinkedList* pArrayListEmployee);//Ya est�
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);//Ya est�
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);//Ya est�

int existencia_id(LinkedList*, int, int*);
