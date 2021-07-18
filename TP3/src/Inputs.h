/*
 * Inputs.h
 *
 *  Created on: 3 jun. 2021
 *      Author: usuario
 */

#ifndef SRC_INPUTS_H_
#define SRC_INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetInt (char*, int*);
int GetFloat (char*, float*);
int GetChar (char*, char*);
int GetString(char*, char*);
int GetString_SinNegativo(char* msj, char* msjError, char* valor);
int SoloNumeros(char* texto);
int GetStringSoloLetras(char* msj, char *valor);
int SoloLetras(char* texto);


#endif /* SRC_INPUTS_H_ */
