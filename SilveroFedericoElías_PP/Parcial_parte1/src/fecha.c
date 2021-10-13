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
	getInt(&fecha.dia , "\nIngrese el día: ", "\nError. Ingrese día válido (1-30): ", 1 , 30);
	getInt(&fecha.mes , "Ingrese el mes: ", "\nError. Ingrese mes válido (1-12): ", 1 , 12);
	getInt(&fecha.anio , "Ingrese el año: ", "\nError. Ingrese año válido (2020-2030): ", 2020 , 2030);


	return fecha;
}
