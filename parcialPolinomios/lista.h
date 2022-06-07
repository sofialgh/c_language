#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "funciones.h"
typedef tPolinomio tDato;

typedef struct sNodo
{
    tDato *info;
    unsigned tamInfo;
    struct sNodo *sig;

}tNodo;
typedef tNodo *tLista;


void crearLista(tLista *p);
void vaciarLista(tLista *p);

int listaVacia (const tLista *p);
int listaLlena(const tLista *p, unsigned cantBytes);
void recorrerYMostrarLista( tLista *p,void (*mostrar)(const void *));
//int insertarEnOrden(tLista *p, const tDato *d, int (*comparar)(const void*, const void *), int (*acumular)(void **, const void *));
int insertarEnOrden(tLista *p, const tDato *d, int (*comparar)(const void*, const void *));

int ponerAlComienzoLista(tLista *p, tDato *d, unsigned cantBytes);
int deArchivoTxtAListaOrdenada(tLista *p, const char *nombreArchivo);
int deListaAArchivoTxt(tLista *p, FILE **pf,const char *nombreArchivo);

void sumarListas(tLista *listaResultante,const tLista *p1, const tLista *p2,void (*sumar) (const void*,const void*,tDato *resultado),int (*comparar)(const void*, const void *) );


#endif // LISTA_H_INCLUDED
