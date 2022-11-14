#ifndef SOPADELETRAS_H
#define SOPADELETRAS_H
#define MAX 6

typedef char tString[50];
typedef tString tVectorStrings[MAX];

typedef struct {
  tString nombreJugador;
  int puntaje;
} tDato;

typedef struct{
  tDato infoJugador;
  struct nodo * siguiente;
}tListaPuntajes;

typedef struct nodoArbol {
  tDato datoArPunt;
  struct nodoArbol *hijoIzq;
  struct nodoArbol *hijoDer;
}tArbolPuntaje;

void sopaDeLetras();
void mostrarSopa();
void aciertoOError(tString );
void inicializarScore();
bool buscarPalabraSecuencial(tVectorStrings , tString );
void actualizarScore ();
void instrucciones();

//Lista Enlazada como Pila
void inicializarLista();
bool listaVacia(tListaPuntajes * );
void insertarPrimerPuntaje (tString , int );
void insertarPuntajeAdelante(tString, int );
void insertarPuntaje(tString , int );

//Archivos
void generarRegistro();
void iniciaProceso();
void grabarRegistroPuntaje(tListaPuntajes * );
void finalizarProceso();

//Arbol
void crearArbolVacio (tArbolPuntaje * );
bool arbolVacio(tArbolPuntaje * );
void insertarPuntajeArbol (tArbolPuntaje ** , tDato);
void recorrrerInOrden(tArbolPuntaje * );

#endif
