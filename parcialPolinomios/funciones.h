#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOM_ARCH1 "p1.txt"
#define NOM_ARCH2 "p2.txt"
#define NOM_ARCH3 "pr.txt"


typedef struct{
    int potencia;
    int coeficiente;
}tPolinomio;
typedef tPolinomio tDato;

int abrirArchivo(FILE **pf, const char *nombreArchivo,const char* modoApertura, int muestraError);
int crearArchivoTxt(const char *nombreArchivo, char **registros, int cantidadRegistros);
void trozarCamposLongitudVariable(tPolinomio *d, char *s);
void mostrar (const void *info);
//int comparar(const tDato *d1, const tDato *d2);
int compararPotencia(const void *d1, const void *d2);
int acumularCoeficiente (void **pol1 , const void *pol2);
void sumarTerminos(const void *p1,const void *p2,tDato *resultado);

#endif // FUNCIONES_H_INCLUDED
