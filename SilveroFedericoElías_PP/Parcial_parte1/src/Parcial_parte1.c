/*
 ============================================================================
Parcial: Parte 1
Alumno: Federico Elías Silvero
División: 1°D

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perros.h"
#include "estadia.h"
#include "input.h"
#include "menu.h"
#define TAM 3
int main(void) {
	setbuf(stdout, NULL);

	sPerro perros [TAM] = { {7000, "Lobo", "Sharpei", 2} , {7001, "Sheila", "Golden", 12} , {7002, "Reina", "Galgo", 13} };

	for(int i = 0; i < TAM; i++)
	{
		printf("ID: %d - NOMBRE: %s - RAZA: %s - EDAD: %d\n",perros[i].id , perros[i].nombre, perros[i].raza, perros[i].edad);
	}

	return 0;
}
