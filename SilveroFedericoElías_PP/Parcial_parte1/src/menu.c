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
	int opcionSubMenu;
	int auxUltimoIdEstadia;
	int auxUltimoIdPerro;
	int auxNuevoTelefono;
	int idSearch;
	int indexSearch;

	do
	{
		getInt (&opcion,
				"-------------------------------------------\n"
				"\n1. RESERVAR ESTADIA"
				"\n2. MODIFICAR ESTADIA"
				"\n3. CANCELAR ESTAD�A"
				"\n4. LISTAR ESTAD�AS"
				"\n5. LISTAR PERROS"
				"\n6. Promedio de edad de los perros"
				"\n7. SALIR"
				"\n-------------------------------------------\n"
				"Ingrese una opcion (1-7): ",
				"\n-------------------------------------------\n"
				"\n1. RESERVAR ESTADIA"
				"\n2. MODIFICAR ESTADIA"
				"\n3. CANCELAR ESTAD�A"
				"\n4. LISTAR ESTAD�AS"
				"\n5. LISTAR PERROS"
				"\n6. Promedio de edad de los perros"
				"\n7. SALIR"
				"\n-------------------------------------------\n"
				"Error. Reingrese una opcion v�lida (1-7): ", 1 , 7);


		switch (opcion)
		{
		case 1:
				printf("\nReservando estad�a...\n\n");
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

		case 2:
				printf("\nModificando la estad�a...\n");
				estadia_mostrar (listaEstadias, listaPerros, tamEstadias);
				printf("\n\nIngrese el ID de la estad�a a modificar: ");
				fflush(stdin);
				scanf("%d", &idSearch);
				while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
				{
					printf("\nError. Reingrese el un ID existente: ");
					fflush(stdin);
					scanf("%d", &idSearch);
				}

				getInt (&opcionSubMenu,
										"\nMENU DE MODIFICACIONES"
										"\n--------------------------\n"
										"\n1. TELEFONO DE CONTACTO"
										"\n2. PERRO"
										"\n3. SALIR"
										"\n--------------------------\n"
										"Ingrese una opci�n (1-3): ",
										"\n--------------------------\n"
										"\n1. TELEFONO DE CONTACTO"
										"\n2. PERRO"
										"\n3. SALIR"
										"\n--------------------------\n"
										"Error. Reingrese una opci�n v�lida (1-3): " , 1 , 3);

				switch (opcionSubMenu)
				{
				case 1:
						printf("\nModificando el tel�fono de contacto...\n");
						indexSearch = estadia_buscarLugar (listaEstadias , tamEstadias);
						auxNuevoTelefono = estadia_modificar (1);


						if (auxNuevoTelefono != -1)
						{
							listaEstadias[indexSearch].telefonoContacto = auxNuevoTelefono;
							printf("\nHa modificado el NUEVO TELEFONO exitosamente!\n");
							system("pause");
						}

						else
						{
							printf("\nHa cancelado la modificaci�n del nuevo telefono.\n");
							system("pause");
						}
						break;
				}

				break;


		}



	}while (opcion != 7);


	return 0;
}

