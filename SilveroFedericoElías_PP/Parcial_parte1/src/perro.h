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
#include "input.h"
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
int perro_buscarLugar (sPerro lista[] , int tam);
sPerro perro_pedirDatos (sPerro perro, int tam , int ultimoIdPerro);
int perro_verificar (sPerro perro);
int perro_cargar (sPerro lista[] , int tam , int ultimoIdPerro);
void perro_mostrar (sPerro perro);
sPerro perro_pedirDatosSinId (sPerro perro, int tam);
int perro_verificarSinId (sPerro perro);
int perro_modificar (sPerro lista[] , int tam , int index , int id);
int perro_buscarCoincidenciaId (sPerro lista[] , int tam, int id);


#endif /* PERRO_H_ */
