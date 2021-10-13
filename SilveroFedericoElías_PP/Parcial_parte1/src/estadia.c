/*
 * estadia.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */
#include "estadia.h"

//ABM de estadia necesito pedir el ingreso de:

//id (comienza en 100000, autoincremental)
//nombreDuenio (cadena de caracteres) Validar
//telefonoContacto (sólo números) Validar
//idPerro (debe existir) Validar
//fecha (Validar día, mes y año)



int estadia_reservar (sEstadia reserva[] , int tam , int ultimoId)
{
	sEstadia aux;
	int ret = -1;
	int confirmacion;
	int index;


	if (estadia_buscarLugar (reserva , tam) != -1)
	{
		aux = estadia_pedirDatos (aux , ultimoId);
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




int estadia_verificar (sEstadia reserva)
{
	int respuesta;

	printf("ID: %d\nNOMBRE DUEÑO: %s\nTEL: %d\nID PERRO: %d\nFECHA: %d\n", reserva.id, reserva.nombreDuenio, reserva.telefonoContacto, reserva.idPerro, reserva.fecha);
	getInt (&respuesta, "Desea confirmar los datos de la estadia (0 = no / 1 = si)? :", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}




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



sEstadia estadia_pedirDatos (sEstadia auxiliar , int ultimoId)
{
	int id;
	char nombreDuenio[21];
	int telefonoContacto;
	int idPerro;
	int fecha;

	id = ultimoId + 1;
	getString (nombreDuenio, "Ingrese el nombre del dueño: ", "Error. Ingrese un nombre válido (hasta 20 caracteres): ", 21);
	getInt (&telefonoContacto, "Ingrese tel: ", "Error. Ingrese teléfono válido: ", 1100000000 , 1199999999);
	getInt (&idPerro, "Ingrese el ID del perro: ", "Error. Ingrese un ID válido: ", 1000 , 2000);
	getInt (&fecha, "Ingrese fecha: ", "Error. Ingrese una fecha válida: ", 01012020 , 31122025);

	auxiliar.id = id;
	strcpy (auxiliar.nombreDuenio , nombreDuenio);
	auxiliar.telefonoContacto = telefonoContacto;
	auxiliar.idPerro = idPerro;
	auxiliar.fecha = fecha;

	return auxiliar;
}



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





