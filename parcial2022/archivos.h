//
// Created by sgallo_pickit on 6/6/2022.
//
#include <stdio.h>

#define PARAM_STOCK1 1
#define PARAM_STOCK2 2
#define ERROR_ARCHIVO 0

typedef struct{
    int codigo;
    char descripcion[21];
    int cantidad;
}Producto;



void crearLoteDePrueba();
void leerArchivo(char *nombreArchivo);
int fusionarArchivos(char *nombreArchivo1, char *nombreArchivo2, char *archivoResultante);
void algoritmoMerge((char *nombreArchivo1, char *nombreArchivo2, char *archivoResultante);
int abrirArchivo(FILE **pf, const char *nombreArchivo, const char* modoApertura, int muestraError);


#ifndef PARCIAL2022_ARCHIVOS_H
#define PARCIAL2022_ARCHIVOS_H

#endif //PARCIAL2022_ARCHIVOS_H
