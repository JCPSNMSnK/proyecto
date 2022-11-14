#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include "SopaDeLetras.h" //declarar las struct de listaEnlazada y Arbol directamente aqui, simplifico

int op, puntos, oportunidades;

tString palabraIn, nombre;
tVectorStrings vectorRespuestas = {"analisis", "diseno", "codificacion", "compilacion", "mantenimiento", "documentacion"};
int vectorRespuestasEncontradas[MAX] = {0, 0, 0, 0, 0, 0}; //cuando una palabra sea encontrada, meto 1 como encontrado, 0 no encontrado

tListaPuntajes *listaPuntajes;

void sopaDeLetras(){ //principal donde voy citando 
	inicializarLista();
    do{
        system("cls");
        printf("¡BIENVENIDO A LA SOPA DE LETRAS!\n");
        printf("1- Jugar\n");
        printf("2- Instrucciones\n");
        printf("3- Puntos\n");
        printf("4- Salir\n");
        
		do{
			scanf("%i", &op);
		}while(op<0||op>4);
        
		switch(op){
            case 1:
            	inicializarScore();
                do{
                    system("cls");
                    mostrarSopa();
                    aciertoOError(palabraIn);
                }while(oportunidades!=0);
                //Mostrar el 'gano!'
                system("cls");
                printf("Juego acabado!\n");
                printf("\nTus puntos: %i\n", puntos);
		insertarPuntaje(nombre, puntos);
		//generarRegistro(nombre, puntos); así guardo los datos historicos en un archivo binario para imprimirlos
                system("pause");
                    
            break;
                     
            case 2:
                //Instrucciones
                instrucciones();
            break;
            case 3:
                //Puntos aca deberia imprimir los datos y el puntaje, ejemplo imprimirArbolDeBusqueda();
                system("cls");
                printf("\t\tCLASIFICACION DE PUNTAJES: \n");
            	if(puntos!=0){
            		
                    printf("El ultimo puntaje grabado fue de: %i\n", puntos);
                    printf("Vas a poder superarlo?\n");
                    system("pause");
                    
                }else{
                    printf("No hay puntajes grabados. Juega una partida para grabarlo.\n");
                    system("pause");
                }
            break;
        }
    }while(op!=4);
    
} 

void inicializarScore(){//inicia las variables a mostrar del puntaje y oportunidades
	printf("\nIngrese su nombre: ");
	scanf("%s", &nombre);
	
	oportunidades=6;
	puntos=0;
}

void mostrarSopa(){//imprime la sopa
	printf("Puntaje           : %i\n", puntos);
    printf("Intentos restantes: %i\n", oportunidades);
    
    printf("\n PISTA: 6 Etapas del Ciclo de Vida del Software\n");
    
    printf("\n\t t a n a l i s i s k n a k m i b k n g a h j\n");
    printf("\n\t h a j f m a n t e n i m i e n t o i n u s g\n");
    printf("\n\t g h x f s v t e w b y h j r f r d s f u d t\n");
    printf("\n\t l r f i d i s e n o r w f b o j u b m o r u\n");
    printf("\n\t n j n j m l j l a u t o b u s u n l g b l o\n");
    printf("\n\t i u b e s t a c i o n a m i e n t o u u p m\n");
	printf("\n\t l r f s d v h y f d r w f b h j u b m l n v\n");
    printf("\n\t c o d i f i c a c i o n t r w v k b k j c w\n");
    printf("\n\t i u b d o c u m e n t a c i o n n i i u q s\n");
    printf("\n\t c o m p i l a c i o n j t r w v k b k j a z\n");
    printf("\n\t i u b d t e s v l m g o i e a w n i i u x q\n");
	
	printf("\n\n Palabra encotrada: ");
	
	scanf("%s", &palabraIn);
	
	int i;
	
	for (i=0; palabraIn[i]; i++){
		palabraIn[i] = tolower(palabraIn[i]);
	}
	
	printf("\nPalabra leida!\n");
}

void aciertoOError(tString pPalabraIn){//identifica si la palabra ingresada es un acierto o error
	printf("Entrando en acierto o error con la palabra: %s \n ", pPalabraIn);
	bool resultBus;
	resultBus = buscarPalabraSecuencial(vectorRespuestas, pPalabraIn);
	
	if(resultBus){
        actualizarScore; 
        system("pause");
    }else{
		printf("\n\nIncorrecto. Ya la escribiste o no es correcta!\n");
       	oportunidades=oportunidades-1;
        puntos = puntos-3;
		system("pause");
	}
}

bool buscarPalabraSecuencial(tVectorStrings pVectorRespuestas, tString pPalabraIn){ //tipo de Busqueda Secuencial
	
	bool result = false;
	int i = 0; //si pongo 0 no me mostraba nunca cuando v[0] era ingresado
	
	//printf("Estoy en busqueda secuencial! \n"); lo use para verificar que aca llegaba cuando no podia aislar el problema
	
	while((strcmp(vectorRespuestas[i], pPalabraIn)!=0) && (i != MAX)){
		i = i+1; //si ponia i++ me metia en bucle infinito
		//printf("Iterando con %d", i); //tengo un bucle infinito use printf para verificarlo
	}
	
	if((strcmp(vectorRespuestas[i], pPalabraIn))==0 && vectorRespuestasEncontradas[i]==0){
		vectorRespuestasEncontradas[i] = 1; //marca la palabra como encontrada
		result = true;
	}
	
	return result;
}

void actualizarScore (){
	printf("Palabra encontrada! 5 puntos\n");
	puntos=puntos+5;
	oportunidades=oportunidades-1;
}

void instrucciones(){
	system("cls");
    printf ("Instrucciones\n");
    printf ("\n1. Encuentre las palabras escondidas entre las letras.");
    printf ("\n2. aga una lista introduciendo las palabras que encontro, el mismo programa resolvera sus aciertos y sus errores.");
    printf ("\n3. Por cada acierto se sumaran 5 puntos y por cada error se restarán 3 puntos. \n\t Si ingresa una palabra que ya había ingresado previamente, se tomará como un error!. ");
    printf ("\n4. Cuando se acaben los intentos , el juego finalizara y obtendra el puntaje final.\n");
    system("pause");
}

void inicializarLista(){
	listaPuntajes = NULL;
}

bool listaVacia(tListaPuntajes *pListaPuntajes ){
	return pListaPuntajes == NULL;
}

void insertarPrimerPuntaje (tString pNombre, int pPuntaje){
	tListaPuntajes *nuevoPuntaje;
	
	nuevoPuntaje = (tListaPuntajes*)malloc(sizeof(tListaPuntajes));
	nuevoPuntaje->infoJugador.nombreJugador = pNombre;
	nuevoPuntaje->infoJugador.puntaje = pPuntaje;
	nuevoPuntaje->siguiente = NULL;
	
	listaPuntajes = nuevoPuntaje;
	printf("\nPuntaje insertado en la Lista!\n");
	
}

void insertarPuntajeAdelante(tString pNombre, int pPuntaje){
	tListaPuntajes * nuevoPuntaje;
	
	nuevoPuntaje = (tListaPuntajes*)malloc(sizeof(tListaPuntajes));
	nuevoPuntaje->infoJugador.nombreJugador = pNombre;
	nuevoPuntaje->infoJugador.puntaje = pPuntaje;
	nuevoPuntaje->siguiente = listaPuntajes;
	
	listaPuntajes = nuevoPuntaje;
	printf("\nPuntaje insertado en la Lista!\n");
}
void insertarPuntaje(tString pNombre, int pPuntaje){
	if(listaVacia(listaPuntajes)){
		insertarPrimerPuntaje (pNombre, pPuntaje);
	}else{
		insertarPuntajeAdelante(pNombre, pPuntaje);
	}
}
