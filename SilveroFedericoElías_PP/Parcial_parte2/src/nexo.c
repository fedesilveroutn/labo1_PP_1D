/*
 * nexo.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Fede
 */

#include "nexo.h"

void nexo_mostrarPerrosConEstadias (sPerro listaPerros[] , int tamPerros, sEstadia reservas[] ,  int tamReservas)
{
	int i;

	if (listaPerros != NULL && reservas != NULL)
	{
		perro_ordenarPorId (listaPerros , tamPerros);

		printf("\n----------------------------------------------------------------------------------------");
		printf("\n%-20s %-20s %-20s %-20s %-20s %-20s\n", "ID PERRO", "NOMBRE", "RAZA", "EDAD", "ID ESTADIA", "FECHA");
		for (i = 0; i < tamPerros; i++)
		{
			if (listaPerros[i].estado == 1 && reservas[i].estado == 1)
			{
				perro_mostrar(listaPerros[i]);
				printf(" %-15d %-2d/%-2d/%-2d\n",
												reservas[i].id,
												reservas[i].fecha.dia,
												reservas[i].fecha.mes,
												reservas[i].fecha.anio);
			}
		}
	}
}
