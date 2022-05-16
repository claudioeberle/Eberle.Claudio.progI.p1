/*
 ============================================================================
 Name        : PARCIAL_PROGRAMACIN1_EBERLE.c
 Author      : Eberle, Claudio Emanuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	int id;
	char procesador[10];
	char marca[10];
	float precio;

}eNotebook;

float aplicarDescuento (float numero);

int contarCaracteres(char cadena[], int tamanio, char caracter);

int ordenarMarcaPrecio(eNotebook notebooks[], int tamanio);

void mostrarLista(eNotebook notebooks[], int tamanio);



int main() {

	setbuf(stdout, NULL);

	float resultado;
	char cadena[10] = {"anana"};
	int contador;

	eNotebook notebooks [5]= {

			{1000, "core5", "intel", 25500},
			{1000, "core3", "intel", 23500},
			{1000, "core7", "intel", 40500},
			{1000, "xmr", "amd", 33750},
			{1000, "zmr", "amd", 25999}
	};

	resultado = aplicarDescuento(100);

	printf("%.2f\n\n", resultado);

	contador = contarCaracteres(cadena, 10, 'a');

	printf("%d\n\n", contador);

	ordenarMarcaPrecio(notebooks, 5);

	mostrarLista(notebooks, 5);




	return 0;
}




void mostrarLista(eNotebook notebooks[], int tamanio)
{

	printf("  ID    PROCESADOR       MARCA         PRECIO\n");
	printf("----------------------------------------------------\n");
	for (int i = 0; i < tamanio; i++)
	{
		printf("%4d     %10s      %10s        %7.2f \n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio );
	}
}


int ordenarMarcaPrecio(eNotebook notebooks[], int tamanio)
{
	int retorno = 0;
	eNotebook aux;

	if(notebooks != NULL && tamanio > 0)
	{
		for(int i=0; i < tamanio - 1; i++)
		{
			for(int j= i+1; j < tamanio; j++)
			{
				if((strcmp(notebooks[i].marca,notebooks[j].marca) > 0) ||
				   (strcmp(notebooks[i].marca,notebooks[j].marca) == 0 &&
					notebooks[i].precio > notebooks[j].precio))
				{
					aux = notebooks[i];
					notebooks[i] = notebooks[j];
					notebooks[j] = aux;
				}
			}
		}
	}

	return retorno;
}

int contarCaracteres(char cadena[], int tamanio, char caracter)
{
	int contador = 0;

	if(cadena != NULL && tamanio > 0)
	{

		for (int i = 0; i < tamanio; i++)
		{
			if(cadena[i] == caracter)
			{
				contador++;
			}
		}
	}

	return contador;
}

float aplicarDescuento (float numero)
{

	float resultado;

	resultado = numero * 0.95;

	return resultado;

}


