/*
 * estadia.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */

#ifndef ESTADIA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESTADIA_H_

typedef struct
{
	int id;	//comienza en 100K , autoincremental
	char nombreDuenio[51]; //validar
	int telefonoContacto; //validar
	int idPerro; //validar
	int fecha; //validar dia, mes y año

} sEstadiaDiaria;


#endif /* ESTADIA_H_ */
