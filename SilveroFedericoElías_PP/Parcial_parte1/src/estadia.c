/*
 * estadia.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */
#include "estadia.h"

//**
int estadia_inicializar (sEstadia reservas[], int tam)
{
	int i;
	int ret = -1;
	if (reservas != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			reservas[i].estado = 0;
		}
		ret = 0;
	}

	return ret;
}



//**
int estadia_buscarLugar (sEstadia reserva[] , int tam)
{
	int i;
	int posicion = -1;
	for (i = 0; i < tam; i++)
	{
		if ( reserva[i].estado == 0)
		{
			posicion = i;
			break;
		}
	}

	return posicion;
}


//**
sEstadia estadia_pedirDatos (sEstadia auxiliar , int ultimoId , sPerro lista[] , int tam)
{
	int id;
	char nombreDuenio[21];
	int telefonoContacto;
	int idPerro;
	sFecha fecha;

	id = ultimoId + 1;
	getString (nombreDuenio, "\nIngrese el nombre del dueño: ", "Error. Ingrese un nombre válido (hasta 20 caracteres): ", 21);
	getInt (&telefonoContacto, "Ingrese tel: ", "Error. Ingrese teléfono válido: ", 1100000000 , 1199999999);
	getInt (&idPerro, "Ingrese el ID del perro: ", "Error. Ingrese un ID válido: ", 1000 , 10000);
		while (estadia_buscarCoincidenciaId (lista, tam , idPerro) == -1)
		{
			printf("Error. ID inexistente. Reintente.\n");
			getInt (&idPerro, "Ingrese el ID del perro: ", "Error. Ingrese un ID válido: ", 1000 , 2000);
		}

	fecha = fecha_pedir("\nDatos de la reserva");

	auxiliar.id = id;
	strcpy (auxiliar.nombreDuenio , nombreDuenio);
	auxiliar.telefonoContacto = telefonoContacto;
	auxiliar.idPerro = idPerro;
	auxiliar.fecha = fecha;

	return auxiliar;
}

//**
int estadia_buscarCoincidenciaId (sPerro lista[] , int tam , int id)
{
	int ret = -1;
	int i;
	if (lista != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].id == id)
			{
				ret = 0;
			}
		}
	}

	return ret;
}



int estadia_buscarCoincidenciaId2 (sEstadia reserva[] , int tam , int id)
{
	int i;
	int posicion = -1;
	for (i = 0; i < tam; i++)
	{
		if ( reserva[i].id == id)
		{
			posicion = i;
			break;
		}
	}

	return posicion;
}

//**
int estadia_buscarExistenciaId (sEstadia reserva[] , int tam , int id)
{
	int ret = -1;
	int i;
	if (reserva != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if (reserva[i].estado == 1	&& reserva[i].id == id)
			{
				ret = 0;
			}
		}
	}

	return ret;
}




//**
int estadia_verificar (sEstadia reserva)
{
	int respuesta;

	printf("\n----------------------------------------------------------------"
		   "\nDatos de la estadia A CONFIRMAR: \n"
		   "\nID: %d\nNOMBRE DUEÑO: %s\nTEL: %d\nID PERRO: %d\nFECHA: %d/%d/%d\n"
		   "\n----------------------------------------------------------------\n", reserva.id, reserva.nombreDuenio,
			 reserva.telefonoContacto, reserva.idPerro, reserva.fecha.dia, reserva.fecha.mes, reserva.fecha.anio);

	getInt (&respuesta, "Desea CONFIRMAR los datos de la estadia (0 = no / 1 = si)? : ", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}



//**
int estadia_reservar (sEstadia reserva[] , int tam , int ultimoId , sPerro lista[] , int tamPerro)
{
	sEstadia aux;
	int ret = -1;
	int confirmacion;
	int index;


	if (estadia_buscarLugar (reserva , tam) != -1)
	{
		aux = estadia_pedirDatos (aux , ultimoId , lista , tamPerro);
		confirmacion = estadia_verificar (aux);

		if(confirmacion == 1)
		{
			index = estadia_buscarLugar (reserva , tam);
			reserva[index] = aux;
			reserva[index].estado = 1;
			ultimoId++;
			ret = ultimoId;
		}

		else
		{
			printf("\nUsted ha cancelado la reserva.\n");
		}
	}

	else
	{
		printf("\nNo hay lugar disponible para reservar.");
	}

	return ret;
}




int estadia_modificar (int elemento)
{
	int ret = -1;
	int nuevoTelefono;
	int respuesta;

	if (elemento == 1 )
	{
		getInt (&nuevoTelefono ,"\nIngrese su nuevo NUMERO DE TELEFONO: ","\nError. Reingrese un número válido (1100000000-1199999999): ", 1100000000,1199999999);
		printf("\nSu nuevo número de teléfono es: %d\n", nuevoTelefono);
		getInt (&respuesta, "\nDesea confirmar la modificacion del TELEFONO (0 = no / 1 = si) ?: ", "\nError. Ingrese una opción válida (0 = no / 1 = si): ", 0 , 1);

		if ( respuesta == 1)
		{
			ret = nuevoTelefono;
		}

		else
		{
			printf("\nUsted ha cancelado la modificacion del tel dentro de la funcion estadia_modificar");
		}
	}
	else
	{
		printf("\nNo se puede modificar una opcion que no existe.");
	}

	return ret;
}




void estadia_mostrar (sEstadia reservas[] , sPerro listaPerros[],  int tamReservas)
{
	int i;

	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s %-20s %-15s\n", "ID ESTADIA", "ID PERRO", "NOMBRE PERRO", "RAZA", "EDAD", "NOMBRE DUEÑO", "TELEFONO CONTACTO", "FECHA");

	for(i = 0; i < tamReservas; i++)
	{
		if (reservas[i].estado == 1)
		{
			printf("%-15d %-15d %-15s %-15s %-15d %-15s %-20d %-2d/%-2d/%-2d\n",
																			reservas[i].id,
																			listaPerros[i].id,
																			listaPerros[i].nombre,
																			listaPerros[i].raza,
																			listaPerros[i].edad,
																			reservas[i].nombreDuenio,
																			reservas[i].telefonoContacto,
																			reservas[i].fecha.dia,
																			reservas[i].fecha.mes,
																			reservas[i].fecha.anio);
	    }
	}
}



int estadia_cancelar (sPerro perros[], int tamPerros, sEstadia reserva[], int tamEstadias , int id)
{
	int ret = -1;
	int pos;

	if (reserva != NULL)
	{
		pos = estadia_buscarCoincidenciaId2(reserva, tamEstadias, id);
		reserva[pos].estado = 0;
		perros[pos].estado = 0;
		ret = 0;
	}

	return ret;
}


void estadia_mostrarSoloEstadia (sEstadia reservas[] ,  int tamReservas)
{
	int i;

	estadia_ordenarPorFecha (reservas, tamReservas);

	printf("\n%-15s %-15s %-20s %-15s\n", "ID ESTADIA", "NOMBRE DUEÑO", "TELEFONO CONTACTO", "FECHA");

	for(i = 0; i < tamReservas; i++)
	{
		if (reservas[i].estado == 1)
		{
			printf("%-15d %-15s %-20d %-2d/%-2d/%-2d\n",
														reservas[i].id,
														reservas[i].nombreDuenio,
														reservas[i].telefonoContacto,
														reservas[i].fecha.dia,
														reservas[i].fecha.mes,
														reservas[i].fecha.anio);
		}
	}
}




int estadia_ordenarPorFecha (sEstadia reservas[], int tamReservas)
{
	int i;
	int swap;
	int nuevoLimite;
	sEstadia aux;
	int ret = -1;

	nuevoLimite = tamReservas - 1;

	do
	{
		swap = 0;
		for ( i = 0; i < nuevoLimite; i++)
		{
			if (reservas[i].fecha.anio < reservas[i+1].fecha.anio || reservas[i].fecha.mes < reservas[i+1].fecha.mes || reservas[i].fecha.dia < reservas[i+1].fecha.dia )
			{
				aux = reservas[i];
				reservas[i] = reservas[i+1];
				reservas[i+1] = aux;
				swap = 1;
			}
			else if (reservas[i].fecha.anio == reservas[i+1].fecha.anio)
			{
				if ( strcmp (reservas[i].nombreDuenio , reservas[i+1].nombreDuenio) == 1 )
				{
					aux = reservas[i];
					reservas[i] = reservas[i+1];
					reservas[i+1] = aux;
					swap = 1;
				}
			}
		}
		nuevoLimite--;

	}while (swap == 1);

	ret = 0;
	return ret;
}



