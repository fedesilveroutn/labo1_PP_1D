/*
 * perro.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Fede
 */

#include "perro.h"

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
