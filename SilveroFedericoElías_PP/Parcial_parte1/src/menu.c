#include "menu.h"


int menu ()
{
	int opcion;

	do
	{
		getInt(&opcion,
				"\n----------------------------------\n"
				"1. RESERVAR ESTADIA\n"
				"2. MODIFICAR ESTADIA\n"
				"3. CANCELAR ESTADIA\n"
				"4. LISTAR ESTADIAS\n"
				"5. LISTAR PERROS\n"
				"6. PROMEDIO DE EDAD DE LOS PERROS\n"
				"7. SALIR DEL PROGRAMA\n"
				"\n----------------------------------\n"
				"Ingrese una opción (1-7): ",
				"\n----------------------------------\n"
				"1. RESERVAR ESTADIA\n"
				"2. MODIFICAR ESTADIA\n"
				"3. CANCELAR ESTADIA\n"
				"4. LISTAR ESTADIAS\n"
				"5. LISTAR PERROS\n"
				"6. PROMEDIO DE EDAD DE LOS PERROS\n"
				"7. SALIR DEL PROGRAMA\n"
				"\n----------------------------------\n"
				"Error. Reingrese una opción válida (1-7): ", 1 , 7);








	}while (opcion != 7);

	return 0;
}
