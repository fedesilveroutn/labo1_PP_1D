/*
 * menu.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */

#include "menu.h"
#include "perro.h"
#include "estadia.h"

int menu (sEstadia listaEstadias[], int tamEstadias , sPerro listaPerros[] , int tamPerros , int uIdEstadia , int uIdPerro )
{
	int opcion;
	int auxUltimoIdEstadia;
	int auxUltimoIdPerro;

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
				printf("\nReservando estadía...\n\n");
				auxUltimoIdPerro = perro_cargar (listaPerros, tamPerros, uIdPerro);
				if (auxUltimoIdPerro != -1)
				{
					uIdPerro = auxUltimoIdPerro;
					auxUltimoIdEstadia = estadia_reservar (listaEstadias, tamEstadias , uIdEstadia, listaPerros, tamPerros);
					if (auxUltimoIdEstadia != -1)
					{
						uIdEstadia = auxUltimoIdEstadia;
						printf("\nHa realizado la reserva exitosamente!\n\n");
						system("pause");
					}
				}

				break;







		}



	}while (opcion != 7);


	return 0;
}

