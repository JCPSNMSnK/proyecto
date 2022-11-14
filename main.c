#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include "SopaDeLetras.h"

int opMain; 
void menuMain();

int main(){
	
	do{
		menuMain();
		do{
			scanf("%i", &opMain);
		}while(opMain<0||opMain>4);
		
		switch(opMain){
			case 1:
				printf("Hola hice un cambio");
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
