/*
 * fecha.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Fede
 */
#include "fecha.h"

sFecha fecha_pedir (char* mensaje)
{
	sFecha fecha;

	printf("%s", mensaje);
	getInt(&fecha.dia , "\nIngrese el d�a: ", "\nError. Ingrese d�a v�lido (1-30): ", 1 , 30);
	getInt(&fecha.mes , "Ingrese el mes: ", "\nError. Ingrese mes v�lido (1-12): ", 1 , 12);
	getInt(&fecha.anio , "Ingrese el a�o: ", "\nError. Ingrese a�o v�lido (2020-2030): ", 2020 , 2030);


	return fecha;
}
