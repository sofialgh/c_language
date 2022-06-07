//
// Created by sgallo_pickit on 7/6/2022.
//
#include <stdlib.h>
#include <string.h>
#define SIN_MEM 1
#define CLA_DUP 2
#define TODO_BIEN 0
#include "archivos.h"

typedef Producto tDato;

typedef struct sNodo
{
 tDato *info;
 unsigned tamInfo;
 struct sNodo *sig;
 } tNodo;
typedef tNodo *tLista;

//void sumarListas(tLista *listaResultante, const tLista *p1, const tLista *p2,void (*sumar)(const void*,const void*,tDato*),int (*comparar)(const void*, const void *));

void crearLista(tLista *p);

int listaVacia(const tLista *p);

int listaLlena(const tLista *p, unsigned cantBytes);

void vaciarLista(tLista *p);

int ponerAlComienzo(tLista *p, const tDato *d, unsigned cantBytes);

int sacarPrimeroLista(tLista *p, tDato *d, unsigned cantBytes);

int verPrimeroLista(const tLista *p, tDato *d, unsigned cantBytes);

int ponerAlFinal(tLista *p, const tDato *d, unsigned cantBytes);

int sacarUltimoLista(tLista *p, tDato *d, unsigned cantBytes);

int verUltimoLista(const tLista *p, tDato *d, unsigned cantBytes);
void mostrar (const tDato *info);
int comparar ( const tDato *info1, const tDato *info2);
int eliminarDuplicados(tLista *p, int (*comparar) (const tDato *info1, const tDato *info2));


void recorrerYMostrarLista( tLista *p, void (*mostrar)(const void *));
int deArchivoOrdenadoALista(tLista *p, char *nombreArchivo);


#ifndef PARCIAL2022_LISTA_H
#define PARCIAL2022_LISTA_H

#endif //PARCIAL2022_LISTA_H
