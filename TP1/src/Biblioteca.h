/*
 * Biblioteca.h
 *
 *  Created on: 13 abr. 2021
 *      Author: usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

void MenuPrincipal();
float TomarEnteros (char[]);
char VerificarConfimarcion(char);
int VerificarOpcion(int);

float SumarNumeros (float, float);
float RestarNumeros (float, float);
float DivisionNumeros (float, float);

void MostrarResultados (float, float, float, int, int, int);

#endif /* BIBLIOTECA_H_ */
