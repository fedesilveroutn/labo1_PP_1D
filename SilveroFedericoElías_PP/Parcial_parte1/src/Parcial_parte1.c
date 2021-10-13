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
#include "perro.h"
#include "estadia.h"
#include "menu.h"
#include "fecha.h"
#define TAM 3
#define IDESTADIA 100000
#define IDPERRO 7002

int main(void) {
	setbuf(stdout, NULL);

	sPerro perros [TAM] = { {7000, "Lobo", "Sharpei", 2 , 1 } , {7001, "Sheila", "Golden", 12 , 1 } , {7002, "Reina", "Galgo", 13 ,1 } };
	sEstadia reservas [TAM];

	perro_inicializar (perros , TAM);
	estadia_inicializar (reservas, TAM);

	menu (reservas , TAM , perros, TAM , IDESTADIA , IDPERRO);

	printf("\nFin del programa.");

















	return 0;
}
