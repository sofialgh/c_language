#include "archivos.h"

void crearLoteDePrueba()
{
    Producto lote1[6]={{2,"PAN",8},
                       {4,"LECHE",10},
                       {9,"AZUCAR",15},
                       {9,"AZUCAR",6},
                       {12,"CAFE",50},
                       {13,"HUEVOS",7}
    };

    Producto lote2[4]={{0,"QUESO",7},
                       {4,"LECHE",10},
                       {4,"LECHE",-5},
                       {14,"ARROZ",60}
    };
    Producto movimientos[7]={{2,"PAN",8},
                            {4,"LECHE",10},
                            {9,"AZUCAR",6},
                            {12,"CAFE",-50},
                            {13,"HUEVOS",7},
                            {13,"HUEVOS",20},
                            {14,"ARROZ",30}

    };
   // FILE *pf1 = fopen("STOCK1","wb");
  //  FILE *pf2 = fopen("STOCK2","wb");
  //FILE *pf3 = fopen("Movimientos.bin","wb");
   // fwrite(movimientos,sizeof(Producto),7,pf3);
  /*    fwrite(lote1,sizeof(Producto),6,pf1);
      fwrite(lote2,sizeof(Producto),4,pf2);
      fclose(pf1);
      fclose(pf2);*/
    //leerArchivo("STOCK1");
   // leerArchivo("STOCK2");
    //fclose(pf3);
   // leerArchivo("Movimientos.bin");



}

void leerArchivo(char *nombreArchivo)
{
    FILE *pf = fopen(nombreArchivo,"rb");
    Producto buffer;
    while(fread(&buffer,sizeof(Producto),1,pf))
        fprintf(stdout,"%d %s %d \n", buffer.codigo,buffer.descripcion,buffer.cantidad);
    puts("");
    fclose(pf);
}
int abrirArchivo(FILE **pf, const char *nombreArchivo, const char* modoApertura, int muestraError)
{
    *pf = fopen(nombreArchivo,modoApertura);
    if (pf == NULL)
    {
        if(muestraError == 1) // flag activo para que se muestre el error por pantalla
        {
            fprintf(stderr,"Error abriendo \"%s\" en modo \"%s\".", nombreArchivo, modoApertura);
        }
        return 0;
    }
    return 1;

}

int fusionarArchivos(char *nombreArchivo1, char *nombreArchivo2, char *archivoResultante)
{
    FILE *archivoStock1 = fopen(nombreArchivo1, "rb");
    FILE *archivoStock2 = fopen(nombreArchivo2, "rb");
    FILE *archivoTmp = fopen(archivoResultante, "wb");
    if (archivoStock1 == NULL || archivoStock2 == NULL) {
        return ERROR_ARCHIVO;
    }
    Producto prod1, prod2, prodNuevo;
    int cmp;
    fread(&prod1, sizeof(Producto), 1, archivoStock1);
    fread(&prod2, sizeof(Producto), 1, archivoStock2);
    while (!feof(archivoStock1) && !feof(archivoStock2)) {
        cmp = prod1.codigo - prod2.codigo;
        if (cmp == 0) {
            fwrite(&prod1, sizeof(Producto), 1, archivoTmp);
            fwrite(&prod2, sizeof(Producto), 1, archivoTmp);
            fread(&prod1, sizeof(Producto), 1, archivoStock1);
            fread(&prod2, sizeof(Producto), 1, archivoStock2);
        } else if (cmp < 0) {
            fwrite(&prod1, sizeof(Producto), 1, archivoTmp);
            fread(&prod1, sizeof(Producto), 1, archivoStock1);

        } else if (cmp > 0) {
            fwrite(&prod2, sizeof(Producto), 1, archivoTmp);
            fread(&prod2, sizeof(Producto), 1, archivoStock2);
        }

    }
    while (!feof(archivoStock1))
    {
        fwrite(&prod1, sizeof(Producto), 1, archivoTmp);
        fread(&prod1, sizeof(Producto), 1, archivoStock1);
    }
    while (!feof(archivoStock2))
    {
        fwrite(&prod2, sizeof(Producto), 1, archivoTmp);
        fread(&prod2, sizeof(Producto), 1, archivoStock2);
    }
    fclose(archivoStock2);
    fclose(archivoStock1);
    fclose(archivoTmp);
    return 1;
}
int crearArchivoTxt(const char *nombreArchivo, char **registros, int cantidadRegistros)
{
    FILE *pf;
    int i=0;
    if(abrirArchivo(&pf,nombreArchivo,"wt",1))
    {
        while (i<cantidadRegistros)
        {
            fprintf(pf,"%s\n",*registros++);
            i++;
        }
        return 1;
    }

    return 0;
}
/*
void trozarCamposLongitudVariable(tPolinomio *d, char *s)
{
    char *aux = strrchr(s, ')'); // Busco el salto de línea y lo apunto con aux
    *aux = '\0'; // Agrego el caracter de fin de cadena

    */
/** Coeficiente **//*


    aux = strrchr(s,'(');
    sscanf (aux+1,"%d", &d->coeficiente); ///sscanf (aux,"%(d", &d->coeficiente);

    aux = strrchr(s, ')');
    *aux = '\0';

    */
/** Potencia **//*


    aux = strrchr(s,'(');
    sscanf (aux+1,"%d", &d->potencia);
}
*/

void algoritmoMerge((char *nombreArchivo1, char *nombreArchivo2, char *archivoResultante)
{
    FILE *archProductos = fopen(argv[PARAM_PROD],"rb");
    FILE *archMovimientos = fopen(argv[PARAM_MOV],"rb");
    FILE *archivoTmp = fopen("Productos.tmp","wb");

    if(archProductos == NULL || archMovimientos == NULL || archivoTmp == NULL)
    {
     printf("Error al abrir el archivo\n");
     return ERR_ARCHIVO;
    }

    Producto producto, movimiento, productoNuevo;
    int cmp;
    fread(&producto,sizeof(Producto),1,archProductos);
    fread(&movimiento,sizeof(Producto),1,archMovimientos);
    while(!feof(archProductos) && !feof (archMovimientos))
    {
     cmp = producto.codigo - movimiento.codigo;
     if(cmp == 0)
     {
     productoNuevo.cantidad+=movimiento.cantidad;
     fread(&movimiento,sizeof(Producto),1,archMovimientos);
     }
     else if (cmp < 0)
     {
     fwrite(&producto,sizeof(Producto),1,archivoTmp);
     fread(&producto,sizeof(Producto),1,archProductos);
     }
     else (cmp > 0)
    {
     productoNuevo = movimiento;
     fread(&movimiento,sizeof(Producto),1,archMovimientos);
     while(!feof(archMovimientos) && productoNuevo.codigo == movimiento.codigo)
     {
     productoNuevo.cantidad += movimiento.cantidad;
     fread(&movimiento,sizeof(Producto),1,archMovimientos);
     }

     fwrite(&productoNuevo,sizeof(Producto),1,archivoTmp);
    }
    }
}