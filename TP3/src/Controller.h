#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);//Ya está
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);//Ya está
int controller_editEmployee(LinkedList* pArrayListEmployee);//Ya está
int controller_removeEmployee(LinkedList* pArrayListEmployee);//Ya está
int controller_ListEmployee(LinkedList* pArrayListEmployee);//Ya está
int controller_sortEmployee(LinkedList* pArrayListEmployee);//Ya está
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);//Ya está
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);//Ya está

int existencia_id(LinkedList*, int, int*);
