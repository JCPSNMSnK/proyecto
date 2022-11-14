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

void sopaDeLetras();
void mostrarSopa();
void aciertoOError(tString );
void inicializarScore();
bool buscarPalabraSecuencial(tVectorStrings , tString );
void actualizarScore ();
void instrucciones();

void inicializarLista();
bool listaVacia(tListaPuntajes * );
void insertarPrimerPuntaje (tString , int );
void insertarPuntajeAdelante(tString, int );
void insertarPuntaje(tString , int );

void generarRegistro();
void iniciaProceso();
void grabarRegistroPuntaje(tListaPuntajes * );
void finalizarProceso();

#endif
