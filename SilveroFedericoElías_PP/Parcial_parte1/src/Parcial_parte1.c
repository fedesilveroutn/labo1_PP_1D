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
#define TAM 5
#define IDESTADIA 100002
#define IDPERRO 7002

int main(void) {
	setbuf(stdout, NULL);

	sPerro perros [TAM];
	sEstadia reservas [TAM];

	menu (reservas , TAM , perros, TAM , IDESTADIA , IDPERRO);

	printf("\nFin del programa.");

















	return 0;
}
