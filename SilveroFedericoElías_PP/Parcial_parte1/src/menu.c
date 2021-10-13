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
	int idModificacion;
	int posicion;
	int cancelacion;
	int contadorPerros = 0;
	float edadPromedio;
	int flag = 0;

	do
	{
		getInt (&opcion,
				"-------------------------------------------\n"
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
						contadorPerros++;
						flag = 1;
						printf("\nHa realizado la reserva exitosamente!\n\n");
						system("pause");
					}
				}

				break;

		case 2:
				if (flag == 1 || contadorPerros > 0)
				{
				printf("\nModificando la estadía...\n");
				estadia_mostrar (listaEstadias, listaPerros, tamEstadias);
				printf("\n\nIngrese el ID de la ESTADIA a modificar: ");
				fflush(stdin);
				scanf("%d", &idSearch);
				while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
				{
					printf("\nError. Reingrese el un ID existente: ");
					fflush(stdin);
					scanf("%d", &idSearch);
				}

				posicion = estadia_buscarCoincidenciaId2 (listaEstadias , tamEstadias, idSearch);

					do
					{
					getInt (&opcionSubMenu,
											"\nMENU DE MODIFICACIONES"
											"\n--------------------------\n"
											"\n1. TELEFONO DE CONTACTO"
											"\n2. PERRO"
											"\n3. SALIR"
											"\n--------------------------\n"
											"Ingrese una opción (1-3): ",
											"\n--------------------------\n"
											"\n1. TELEFONO DE CONTACTO"
											"\n2. PERRO"
											"\n3. SALIR"
											"\n--------------------------\n"
											"Error. Reingrese una opción válida (1-3): " , 1 , 3);

						switch (opcionSubMenu)
						{
						case 1:
								//modificacion telefono
								printf("\nModificando el teléfono de contacto...\n");
								auxNuevoTelefono = estadia_modificar (1);
								if (auxNuevoTelefono != -1)
								{
									listaEstadias[posicion].telefonoContacto = auxNuevoTelefono;
									printf("\nHa modificado el NUEVO TELEFONO exitosamente!\n");
									system("pause");
								}

								else
								{
									printf("\nHa cancelado la modificación del nuevo telefono.\n");
									system("pause");
								}
								break;



						case 2:
								//modificacion perro
								printf("\nModificando el perro...\n");
								if (posicion != -1)
								{
									idModificacion = listaPerros[posicion].id;
									perro_modificar(listaPerros, tamPerros, posicion , idModificacion);
									printf("\nHa modificado el PERRO exitosamente!\n");
									system("pause");
								}
								else
								{
									printf("\nNo fue posible encontrar el perro solicitado.\n");
								}

								break;

						case 3:
								printf("\nVolviendo al menú principal...\n");
								break;
						}


					}while (opcionSubMenu != 3);
				}
				else
				{
					printf("\nError. Para acceder a las funciones primero debe hacer una reserva!\n");
				}

					break;

		case 3:

			if( flag == 1 || contadorPerros > 0)
			{
				printf("\nCancelando estadía...\n");
				estadia_mostrar (listaEstadias, listaPerros, tamEstadias);

				printf("\n\nIngrese el ID de la ESTADIA a cancelar: ");
				fflush(stdin);
				scanf("%d", &idSearch);
				while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
				{
					printf("\nError. Reingrese el un ID existente: ");
					fflush(stdin);
					scanf("%d", &idSearch);
				}

				cancelacion = estadia_cancelar(listaPerros, tamPerros, listaEstadias, tamEstadias, idSearch);
				if (cancelacion != -1)
				{
					contadorPerros--;
					printf("\nHa CANCELADO la estadía exitosamente!\n");
					system("pause");
				}

				else
				{
					printf("\nError. No se ha podido cancelar la estadía.\n");
					system("pause");
				}
			}
			else
			{
				printf("\nError. Para acceder a las funciones primero debe hacer una reserva\n");
			}
				break;




		case 4:

				if(flag == 1 || contadorPerros > 0)
				{
					estadia_mostrarSoloEstadia(listaEstadias, tamEstadias);
					system("pause");
				}
				else
				{
					printf("\nError. Para acceder a las funciones primero debe hacer una reserva\n");
				}
				break;


		case 5:
				if (flag == 1 || contadorPerros > 0)
				{
				perro_mostrarTodos(listaPerros, tamPerros);
				system("pause");
				}
				else
				{
					printf("\nError. Para acceder a las funciones primero debe hacer una reserva\n");
				}

				break;


		case 6:
				if (flag == 1 || contadorPerros > 0)
				{
					edadPromedio = perro_edadPromedio(listaPerros, tamPerros, contadorPerros);
					printf("\nLa edad promedio de los perros cargados es: %.2f\n", edadPromedio);
					system("pause");
				}
				else
				{
					printf("\nError. Para acceder a las funciones primero debe hacer una reserva\n");
				}
				break;
		}


	}while (opcion != 7);

	return 0;
}

