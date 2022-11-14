#ifndef SOPADELETRAS_H
#define SOPADELETRAS_H
#define MAX 6

typedef char tString[50];
typedef tString tVectorStrings[MAX];

void sopaDeLetras();
void mostrarSopa();
void aciertoOError(tString );
void inicializarScore();
bool buscarPalabraSecuencial(tVectorStrings , tString );
void actualizarScore ();
void instrucciones();

#endif
