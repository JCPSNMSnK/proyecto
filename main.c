#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include "SopaDeLetras.h"

int opMain; 
void menuMain();
void conceptos();

int main(){
	
	do{
		menuMain();
		do{
			scanf("%i", &opMain);
		}while(opMain<0||opMain>4);
		
		switch(opMain){
			case 1:
				conceptos();
				system("pause");
				break;
			case 2:
				sopaDeLetras();
				break;
		}
		
	}while(opMain!=3);
	
	return 0;
}

void menuMain(){
	system("cls");
		printf("¡BIENVENIDO AL PROGRAMA!");
	
		printf("\n\t1- Conceptos");
		printf("\n\t2- Jugar Sopa de Letras");
		printf("\n\t3- Salir\n");
		printf("\nIngrese una opcion: ");
}

void conceptos(){
	printf("\t\t CICLO DE VIDA DEL SOFTWARE\n\n");
	printf("El Ciclo de Vida del Software está compuesto por 6 etapas principales: \n");
	printf("\t 1- Analisis: \n");
	printf("\t 2- Diseno: \n");
	printf("\t 3- Codificacion: \n");
	printf("\t 4- Compilacion: \n");
	printf("\t 5- Mantenimiento: \n");
	printf("\t 6- Documentacion: \n");
	
}
