/*
 ============================================================================
Parcial: Parte 1
Alumno: Federico El�as Silvero
Divisi�n: 1�D

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perro.h"
#include "estadia.h"
#include "duenio.h"
#include "menu.h"
#include "fecha.h"
#define TAM 5
#define IDESTADIA 100002 //inicializo los IDs porque los hab�a hardcodeado
#define IDPERRO 7002
#define IDDUENIO 30002

int main(void) {
	setbuf(stdout, NULL);

	sPerro perros [TAM];
	sEstadia reservas [TAM];
	sDuenio duenios [TAM];

	menu (reservas , TAM , perros, TAM , duenios, TAM , IDESTADIA , IDPERRO , IDDUENIO );

	printf("\nFin del programa.");

	return 0;
}
