
#ifndef ESTADIA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "fecha.h"
#include "perro.h"
#define ESTADIA_H_

typedef struct
{
	int id;
	char nombreDuenio[21];
	int telefonoContacto;
	int idPerro;
	sFecha fecha;
	int estado;

} sEstadia;


int estadia_inicializar (sEstadia reservas[], int tam);
int estadia_hardcodear (sEstadia reserva[]);
int estadia_buscarLugar (sEstadia reserva[] , int tam);
int estadia_buscarExistenciaId (sEstadia reserva[] , int tam , int id);
int estadia_buscarCoincidenciaId (sPerro lista[] , int tam , int id);
int estadia_buscarCoincidenciaId2 (sEstadia reserva[] , int tam , int id);
sEstadia estadia_pedirDatos (sEstadia auxiliar , int ultimoId , sPerro lista[] , int tam);
int estadia_verificar (sEstadia reserva);
int estadia_reservar (sEstadia reserva[] , int tam , int ultimoId , sPerro lista[] , int tamPerro);
int estadia_modificar (int elemento);
int estadia_cancelar (sPerro perros[], int tamPerros, sEstadia reserva[], int tamEstadias , int id);
int estadia_ordenarPorFecha (sEstadia reservas[], int tamReservas);
void estadia_mostrarSoloEstadia (sEstadia reservas[] ,  int tamReservas);



#endif /* ESTADIA_H_ */
