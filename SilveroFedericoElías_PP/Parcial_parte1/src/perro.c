/*
 * perro.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */

#include "perro.h"
/**
 *
 * @param perros
 * @param tam
 * @return
 */
int perro_inicializar (sPerro perros[], int tam)
{
	int i;
		int ret = -1;
		if (perros != NULL)
		{
			for (i = 0; i < tam; i++)
			{
				perros[i].estado = 0;
			}
			ret = 0;
		}
		return ret;
}


/**
 *
 * @param lista
 * @param tam
 * @return
 */
int perro_buscarLugar (sPerro lista[] , int tam)
{
	int i;
	int posicion = -1;
	if (lista != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if ( lista[i].estado == 0)
			{
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}

/**
 *
 * @param perro
 * @param tam
 * @param ultimoIdPerro
 * @return
 */
sPerro perro_pedirDatos (sPerro perro , int ultimoIdPerro)
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	sPerro aux;

	id = ultimoIdPerro + 1;
	getString (nombre, "Ingrese el NOMBRE del perro: ", "Error. Ingrese un nombre válido (hasta 20 caracteres):", 21);
	getString (raza, "Ingrese la RAZA del perro: ", "Error. Ingrese una raza válida (hasta 20 caracteres):", 21);
	getInt (&edad, "Ingrese la EDAD del perro: ", "Error. Ingrese una edad válida (1-20): ", 1 , 20);

	aux.id = id;
	strcpy (aux.nombre , nombre);
	strcpy (aux.raza , raza);
	aux.edad = edad;

	return aux;
}


sPerro perro_pedirDatosSinId (sPerro perro)
{
	char nombre[21];
	char raza[21];
	int edad;
	sPerro aux;

	getString (nombre, "Ingrese el NOMBRE del perro: ", "Error. Ingrese un nombre válido (hasta 20 caracteres):", 21);
	getString (raza, "Ingrese la RAZA del perro: ", "Error. Ingrese una raza válida (hasta 20 caracteres):", 21);
	getInt (&edad, "Ingrese la EDAD del perro: ", "Error. Ingrese una edad válida (1-20): ", 1 , 20);

	strcpy (aux.nombre , nombre);
	strcpy (aux.raza , raza);
	aux.edad = edad;

	return aux;
}


/**
 *
 * @param perro
 * @return
 */
int perro_verificar (sPerro perro)
{
	int respuesta;

	printf("\n----------------------------------------------------------------"
		   "\nDatos del perro A CONFIRMAR: \n"
		   "\nID: %d\nNOMBRE: %s\nRAZA: %s\nEDAD: %d\n"
		   "\n----------------------------------------------------------------\n", perro.id, perro.nombre, perro.raza, perro.edad);

	getInt (&respuesta, "Desea CONFIRMAR los datos del perro (0 = no / 1 = si)? : ", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}


int perro_verificarSinId (sPerro perro)
{
	int respuesta;

	printf("\n----------------------------------------------------------------"
		   "\nDatos del perro A CONFIRMAR: \n"
		   "\nNOMBRE: %s\nRAZA: %s\nEDAD: %d\n"
		   "\n----------------------------------------------------------------\n", perro.nombre, perro.raza, perro.edad);

	getInt (&respuesta, "Desea CONFIRMAR los datos del perro (0 = no / 1 = si)? : ", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}



int perro_cargar (sPerro lista[] , int tam , int ultimoIdPerro)
{
	sPerro aux;
	int ret = -1;
	int confirmacion;
	int index;
	if (lista != NULL)
	{
		if (perro_buscarLugar (lista , tam) != -1)
		{
			aux = perro_pedirDatos (aux , ultimoIdPerro);
			confirmacion = perro_verificar (aux);

			if(confirmacion == 1)
			{
				index = perro_buscarLugar (lista , tam);
				lista[index] = aux;
				lista[index].estado = 1;
				ultimoIdPerro++;
				printf("\n----------------------------------------------------------------------------------------");
				printf("\n%-20s %-20s %-20s %-20s\n", "ID PERRO", "NOMBRE", "RAZA", "EDAD");
				perro_mostrar(lista[index]);
				ret = ultimoIdPerro;
			}

			else
			{
				printf("\nUsted ha cancelado la carga del perro.\n");
			}
		}

		else
		{
			printf("\nNo hay lugar disponible para la carga del perro.");
		}
	}
	return ret;
}



void perro_mostrar (sPerro perro)
{
	if (perro.estado == 1 )
	{
		printf("%-20d %-20s %-20s %-20d\n", perro.id, perro.nombre, perro.raza, perro.edad);
	}
}




int perro_modificar (sPerro lista[] , int tam , int pos , int id)
{
	sPerro aux;
	int ret = -1;
	int confirmacion;
	if(lista != NULL)
	{
		aux = perro_pedirDatosSinId (aux);
		aux.id = id;

		confirmacion = perro_verificarSinId (aux);
		if(confirmacion == 1)
		{
			lista[pos] = aux;
			perro_mostrar(lista[pos]);
			ret = 0;
		}

		else
		{
			printf("\nUsted ha cancelado la modificacion del perro.\n");
		}
	}

	return ret;
}




int perro_buscarCoincidenciaId (sPerro lista[] , int tam, int id)
{
	int posicion = -1;
	int i;
	if (lista != NULL)
	{
		for ( i = 0 ; i < tam ; i++)
		{
			if (lista[i].id == id)
			{
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}


int perro_ordenarPorId (sPerro lista[], int tamPerros)
{
	int i;
	int swap;
	int nuevoLimite;
	sPerro aux;
	int ret = -1;

	if (lista != NULL)
	{
		nuevoLimite = tamPerros - 1;

		do
		{
			swap = 0;
			for ( i = 0; i < nuevoLimite; i++)
			{
				if (lista[i].id > lista[i+1].id)
				{
					aux = lista[i];
					lista[i] = lista[i+1];
					lista[i+1] = aux;
					swap = 1;
				}
				else if (lista[i].id == lista[i+1].id)
				{
					if ( strcmp (lista[i].nombre , lista[i+1].nombre) == 1 )
					{
						aux = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = aux;
						swap = 1;
					}
				}
			}
			nuevoLimite--;

		}while (swap == 1);

		ret = 0;
	}
		return ret;
}


void perro_mostrarTodos (sPerro lista[] , int tamPerros)
{
	int i;

	if (lista != NULL)
	{
		perro_ordenarPorId (lista , tamPerros);

		printf("\n----------------------------------------------------------------------------------------");
		printf("\n%-20s %-20s %-20s %-20s\n", "ID PERRO", "NOMBRE", "RAZA", "EDAD");
		for (i = 0; i < tamPerros; i++)
		{
			if (lista[i].estado == 1)
			{
				perro_mostrar(lista[i]);
			}
		}
	}
}




float perro_edadPromedio (sPerro lista[], int tamPerros, int contador)
{
	int i;
	int acumulador = 0;
	float promedio;

	if (lista != NULL)
	{
		for (i = 0 ; i < tamPerros; i++)
		{
			if (lista[i].estado == 1)
			{
				acumulador += lista[i].edad;
			}
		}

	promedio = (float) acumulador / contador;

	}

	return promedio;
}



int perro_hardcodear (sPerro lista[])
{
	int ret = -1;
	int i;

	if (lista != NULL)
	{
		int ids[3] = {7000 , 7001, 7002};
		char nombres[3][21] = {"Lobo" , "Sheila", "Reina" }    ;
		char razas[3][21] = {"Sharpei" , "Golden" , "Galgo" };
		int edades[3] = {2 , 12 , 13} ;
		int estados[3] = {1 , 1 , 1 } ;

		for (i = 0; i < 3; i++)
		{
			lista[i].id = ids[i];
			strcpy (lista[i].nombre , nombres[i]);
			strcpy (lista[i].raza , razas[i]);
			lista[i].edad = edades[i];
			lista[i].estado = estados[i];
		}

		ret = 0;
	}
	return ret;
}


