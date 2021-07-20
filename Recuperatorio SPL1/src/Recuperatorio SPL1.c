/*
 ============================================================================
 Name        : Recuperatorio_Segundo_Parcial_Laboratorio_1.c
 Author      : Mariano Forte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#define TAMP 5

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* clientListing = ll_newLinkedList();
	LinkedList* carListing = ll_newLinkedList();
	int option;
	do{
		puts("\n\t****** MENU DE OPERACIONES ******\n");
		puts("1. Cargar archivo de Clientes");
		puts("2. Cargar archivo de Autos");
		puts("3. Listar Clientes con sus respectivos Autos");
		puts("4. Filtrar duenios que posean un Volkswagen New Beetle");
		puts("5. Filtrar autos fabricados en el 2012");
		puts("6. Contar cantidad de personas con el apellido Stollard");
		puts("7. Contar cantidad de modelos de marca Toyota");
		puts("8. Salir");
		printf("\nOpcion elegida: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				forte_controller_loadFromText("Clientes.csv",clientListing, 0);
				break;
			case 2:
				forte_controller_loadFromText("Autos.csv",carListing, 1);
				break;
			case 3:
				if(clientListing != NULL && carListing != NULL){
					forte_controller_ListClientsWithCars(clientListing, carListing);
				}
				break;
			case 4:
				if(clientListing != NULL && carListing != NULL){
					forte_controller_FilterClientsByCar(clientListing, carListing, 6);
				}
				break;
			case 5:
				if(carListing != NULL){
					forte_controller_FilterCarsByYear(carListing, 2012);
				}
				break;
			case 6:
				if(clientListing != NULL){
					forte_controller_CountClientsByLastName(clientListing, "Stollard");
				}
				break;
			case 7:
				if(clientListing != NULL && carListing != NULL){
					forte_controller_CountCarsByBrand(clientListing, carListing, "Toyota");
				}
				break;
			case 8:
				if(clientListing != NULL && carListing != NULL){
					free(clientListing);
					free(carListing);
				}
				printf("\n-------------------------------------------------------------------------------\n");
				puts("\nGracias por utilizar la aplicacion.\nEscrita y desarrollada por Mariano Forte.\n");
				system("pause");
				break;
			default:
				puts("Opcion invalida\n");
				break;
		}
		printf("-------------------------------------------------------------------------------\n");
	}while(option != 8);
	return EXIT_SUCCESS;
}
