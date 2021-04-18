/*
 * Biblioteca.h
 *
 *  Created on: 13 abr. 2021
 *      Author: Zarate Enzo Taiel
 */
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
/**
 * @fn void MenuPrincipal()
 * @brief Muestra el menú
 *
 */
void MenuPrincipal();

/**
 * @fn int TomarNumeros(char[])
 * @brief Recibe el valor que va a tomar un numero
 *
 * @param El mensaje que se le muestra al usurio, indicando que ingrese un número
 * @return El número ingresado
 */
int TomarNumeros (char[]);

/**
 * @fn char VerificarConfimarcion(char)
 * @brief Se asegura que se ingreso el caracter 's' o 'n' y no otro
 *
 * @param El caracter ingresado para confirmar el ingreso del nuúmero
 * @return El caracter ingresado
 */
char VerificarConfimarcion(char);

/**
 * @fn int VerificarOpcion(int)
 * @brief Se asegura que se ingreso una opción del menú
 *
 * @param El número ingresado para el menú
 * @return
 */
int VerificarOpcion(int);

/**
 * @fn void MostrarResultados(int, int, float, int, int, int, int, int)
 * @brief Muestra los resultados de las funciones
 *
 * @param El resultado final de la suma
 * @param El resultado final de la resta
 * @param El resultado final de la división
 * @param El segundo operando, para verificar si es igual a 0 o no
 * @param El resultado final de la multiplicación
 * @param El resultado final del factorial del primer operando
 * @param El resultado final del factorial del segundo operando
 * @param La bandera de las funciones, para verificar que debería mostrar
 */
void MostrarResultados (int, int, float, int, int, int, int, int);

#endif /* BIBLIOTECA_H_ */
