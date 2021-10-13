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
#include "input.h"
#define ESTADIA_H_

typedef struct
{
	int id;
	char nombreDuenio[21];
	int telefonoContacto;
	int idPerro;
	int fecha;
	int estado;

} sEstadia;


int estadia_reservar (sEstadia reserva[] , int tam, int ultimoId);
int estadia_verificar (sEstadia reserva);
int estadia_buscarLugar (sEstadia reserva[] , int tam);
sEstadia estadia_pedirDatos (sEstadia auxiliar , int ultimoId);
int estadia_inicializar (sEstadia reservas[], int tam);


#endif /* ESTADIA_H_ */
