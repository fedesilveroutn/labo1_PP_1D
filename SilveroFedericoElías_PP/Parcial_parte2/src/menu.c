
#include "menu.h"
#include "perro.h"
#include "estadia.h"
#include "duenio.h"

/**
 * @fn int menu(sEstadia[], int, sPerro[], int, int, int)
 * @brief contiene la lógica del programa, muestra los menus de opciones y sus distintos posibles flujos
 *
 * @param listaEstadias recibe un array de sEstadia
 * @param tamEstadias recibe el tamaño del array listaEstadia
 * @param listaPerros recibe un array de sPerro
 * @param tamPerros recibe el tamaño del array listaPerros
 * @param uIdEstadia recibe el último id correspondiente a las estadías
 * @param uIdPerro recibe el último id correspondiente a los perros
 * @return retorna 0 si funcionó correctamente.
 */
int menu (sEstadia listaEstadias[], int tamEstadias , sPerro listaPerros[] , int tamPerros, sDuenio listaDuenios [], int tamDuenios , int uIdEstadia ,int uIdPerro,int uIdDuenio)
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
	float edadPromedio;
	int contadorPerros = 3; //inicializo en 1 porque había hardcodeado
	int flag = 1; //inicializo en 1 porque había hardcodeado

	//PARTE 2
	int auxUltimoIdDuenio;
	int contadorDuenios = 3;
	int contadorEstadias = 3;
	int posPerroConMasEstadias;

	if (listaEstadias != NULL && listaPerros != NULL)
	{
		perro_inicializar (listaPerros , tamPerros);
		estadia_inicializar (listaEstadias, tamEstadias);
		duenio_inicializar(listaDuenios, tamDuenios);
		perro_hardcodear(listaPerros);
		estadia_hardcodear (listaEstadias);
		duenio_hardcodear (listaDuenios);
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
					"\n7. Perro que tiene más estadias reservadas"
					"\n8. Listado de perros con sus estadías diarias reservadas"
					"\n9. SALIR"
					"\n-------------------------------------------\n"
					"Ingrese una opcion (1-9): ",
					"\n-------------------------------------------\n"
					"\n1. RESERVAR ESTADIA"
					"\n2. MODIFICAR ESTADIA"
					"\n3. CANCELAR ESTADÍA"
					"\n4. LISTAR ESTADÍAS"
					"\n5. LISTAR PERROS"
					"\n6. Promedio de edad de los perros"
					"\n7. Perro que tiene más estadias reservadas"
					"\n8. Listado de perros con sus estadías diarias reservadas"
					"\n9. SALIR"
					"\n-------------------------------------------\n"
					"Error. Reingrese una opcion válida (1-9): ", 1 , 9);


			switch (opcion)
			{
			case 1:
					printf("\nReservando estadía...\n\n");
					//cargo perro y el ret lo guardo en aux q retorna el ult ID actualizado
					auxUltimoIdPerro = perro_cargar (listaPerros, tamPerros, uIdPerro);
					if (auxUltimoIdPerro != -1)
					{
						uIdPerro = auxUltimoIdPerro;
						contadorPerros++;
					}

					///////////////////////////////
					auxUltimoIdDuenio = duenio_cargar (listaDuenios, tamDuenios, uIdDuenio);
					if (auxUltimoIdDuenio != -1)
					{
						uIdDuenio = auxUltimoIdDuenio;
						contadorDuenios++;
					}


					auxUltimoIdEstadia = estadia_reservar (listaEstadias, tamEstadias , uIdEstadia, listaPerros, tamPerros , listaDuenios, tamDuenios);
					if (auxUltimoIdEstadia != -1)
					{
						uIdEstadia = auxUltimoIdEstadia;
						contadorEstadias++;
						flag = 1; //desbloqueo las otras funciones
						printf("\nHa realizado la reserva exitosamente!\n\n");
						system("pause");
					}


					break;

			case 2:
					if (flag == 1 || contadorPerros > 0 || contadorDuenios > 0)
					{
					printf("\nModificando la estadía...\n");
					estadia_mostrarSoloEstadia(listaEstadias, tamEstadias, listaDuenios, tamDuenios);
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
									printf("\nModificando el teléfono de contacto...\n");
									auxNuevoTelefono = estadia_modificar (1);
									if (auxNuevoTelefono != -1)
									{
										listaDuenios[posicion].telefono = auxNuevoTelefono;
										//listaEstadias[posicion].telefonoContacto = auxNuevoTelefono;
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
					estadia_mostrarSoloEstadia(listaEstadias, tamEstadias, listaDuenios, tamDuenios);

					printf("\n\nIngrese el ID de la ESTADIA a cancelar: ");
					fflush(stdin);
					scanf("%d", &idSearch);
					while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
					{
						printf("\nError. Reingrese el un ID existente: ");
						fflush(stdin);
						scanf("%d", &idSearch);
					}

					cancelacion = estadia_cancelar(listaPerros, tamPerros, listaEstadias, tamEstadias, listaDuenios, tamDuenios, idSearch);
					if (cancelacion != -1)
					{
						contadorPerros--;
						contadorDuenios--;
						contadorEstadias--;
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
						estadia_mostrarSoloEstadia(listaEstadias, tamEstadias , listaDuenios, tamDuenios);
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





			case 7:

					//Perro que tiene más estadias reservadas
					posPerroConMasEstadias = perro_encontrarMayorCantidadEstadias (listaPerros, tamPerros);
					printf("El perro que más estadías tiene es...\n");
					perro_mostrar(listaPerros[posPerroConMasEstadias]);
					system("pause");
					break;



			case 8:
				    //Listado de perros con sus estadías diarias reservadas.
				    nexo_mostrarPerrosConEstadias (listaPerros, tamPerros, listaEstadias ,  tamEstadias);
					break;


			case 9:
					printf("\nSaliendo...\n");
					break;

			}

		}while (opcion != 9);
	}

	return 0;
}

