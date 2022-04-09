/*
 * UTN_get_int.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Julio
 */
#include "UTN_pedirEntero.h"

#include <stdio.h>
#include <stdlib.h>

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);

int main(void) {
	setbuf(stdout, NULL);

	int edad;
	int alturaDelDomicilio;
	int validacionRetorno;
	int opcionDelMenu;

	do{
		printf("1) Ingresar edad\n");
		printf("2) Ingresar altura\n");
		printf("3) Salir\n");

		validacionRetorno = getInt(&opcionDelMenu,"Ingrese la opcion que quiera:\n"
					,"La opcion es incorrecta:\n",3,1,1);
		if(validacionRetorno == 0){
			switch(opcionDelMenu){
			case 1:
				validacionRetorno = getInt(&edad,"Ingrese la edad entre 18 y 99:\n"
							,"La edad es incorrecta:\n",99,18,2);
					if(validacionRetorno == 0){
						printf("%d", edad);
					}else{
						printf("La edad no fue ingresada bien\n");
					}
				break;
			case 2:
				validacionRetorno = getInt(&alturaDelDomicilio,"Ingrese la altura de su casa:\n"
							,"La altura de su casa es incorrecta:\n",60000,1,2);
					if(validacionRetorno == 0){
						printf("%d", alturaDelDomicilio);
					}else{
						printf("La altura no fue ingresada bien\n");
				}
				break;

			case 3:
				printf("Nos vimos\n");
				break;
				}

		}
	}while(opcionDelMenu != 3);
	return 0;
}

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}
