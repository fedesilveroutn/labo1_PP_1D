/*
 * menu.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */

#include "menu.h"
#include "perro.h"
#include "estadia.h"

int menu (sEstadia listaEstadias[], int tamEstadias , sPerro listaPerros[] , int tamPerros , int ultimoId)
{
	int opcion;
	int auxUltimoId;

	do
	{
		getInt (&opcion,
				"\n-------------------------------------------\n"
				"\n1. RESERVAR ESTADIA"
				"\n2. MODIFICAR ESTADIA"
				"\n3. CANCELAR ESTADÍA"
				"\n4. LISTAR ESTADÍAS"
				"\n5. LISTAR PERROS"
				"\n6. Promedio de edad de los perros"
				"\n7. SALIR"
				"\n-------------------------------------------\n"
				"Ingrese una opcion (1-7): ",
				"\n-------------------------------------------\n"
				"\n1. RESERVAR ESTADIA"
				"\n2. MODIFICAR ESTADIA"
				"\n3. CANCELAR ESTADÍA"
				"\n4. LISTAR ESTADÍAS"
				"\n5. LISTAR PERROS"
				"\n6. Promedio de edad de los perros"
				"\n7. SALIR"
				"\n-------------------------------------------\n"
				"Error. Reingrese una opcion válida (1-7): ", 1 , 7);


		switch (opcion)
		{
		case 1:
				auxUltimoId = estadia_reservar (listaEstadias, tamEstadias , ultimoId);
				if (auxUltimoId != -1)
				{
					ultimoId = auxUltimoId;
				}
				break;

		}



	}while (opcion != 7);


	return 0;
}

