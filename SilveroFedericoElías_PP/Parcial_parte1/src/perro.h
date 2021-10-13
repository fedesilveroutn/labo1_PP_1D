/*
 * perro.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */

#ifndef PERRO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PERRO_H_

typedef struct
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estado;

} sPerro;

int perro_inicializar (sPerro perros[], int tam);

#endif /* PERRO_H_ */
