/*
 * duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Fede
 */

#ifndef DUENIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#define DUENIO_H_

typedef struct
{
	int id;
	char nombre [41];
	int telefono;
	int estado;

}sDuenio;



int duenio_inicializar (sDuenio lista[], int tam);
int duenio_hardcodear (sDuenio lista[]);
int duenio_cargar (sDuenio listaDuenios[], int tamDuenios, int ultimoIdDuenio);
int duenio_buscarLugar(sDuenio listaDuenios[], int tamDuenios);
sDuenio duenio_pedirDatos (sDuenio duenio , int ultimoIdDuenio);
sDuenio duenio_pedirDatosSinId (sDuenio duenio);
int duenio_verificar (sDuenio duenio);
void duenio_mostrar (sDuenio duenio);
int duenio_modificar (sDuenio listaDuenios[] , int tamDuenios , int pos , int id);
int duenio_pedirNuevoTelefono ();
int duenio_verificarSinId (sDuenio duenio);


#endif /* DUENIO_H_ */
