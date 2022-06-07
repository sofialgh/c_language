#include "funciones.h"
#include "lista.h"

int abrirArchivo(FILE **pf, const char *nombreArchivo, const char* modoApertura, int muestraError)
{
*pf = fopen(nombreArchivo,modoApertura);
if (*pf == NULL)
{
    if(muestraError == 1) // flag activo para que se muestre el error por pantalla
    {
        fprintf(stderr,"Error abriendo \"%s\" en modo \"%s\".", nombreArchivo, modoApertura);
    }
    return 0;
}
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

void trozarCamposLongitudVariable(tPolinomio *d, char *s)
{
    char *aux = strrchr(s, ')'); // Busco el salto de línea y lo apunto con aux
    *aux = '\0'; // Agrego el caracter de fin de cadena

    /** Coeficiente **/

    aux = strrchr(s,'(');
    sscanf (aux+1,"%d", &d->coeficiente); ///sscanf (aux,"%(d", &d->coeficiente);

    aux = strrchr(s, ')');
    *aux = '\0';

    /** Potencia **/

    aux = strrchr(s,'(');
    sscanf (aux+1,"%d", &d->potencia);
}

void mostrar (const void *info)
{
    tDato *aux = (tDato *)info;
    printf("X(%d)(%d)\n",aux->potencia,aux->coeficiente);
}
int compararPotencia(const void  *d1, const void *d2)
{
  tDato *dato1 = (tDato *)d1;
  tDato *dato2 = (tDato *)d2;
    return (dato1->potencia-dato2->potencia);
}
int acumularCoeficiente (void  **pol1 ,const void *pol2)
{
    tDato **polinomio1 = (tDato **)polinomio1;
    tDato *polinomio2 = (tDato*)polinomio2;
    (*polinomio1)->coeficiente+=polinomio2->coeficiente;
    return 1;
}

void sumarTerminos(const void *p1,const void *p2, tDato *resultado)
{
    tDato *d1 = (tDato *)p1;
    tDato *d2 = (tDato*)p2;
    resultado->coeficiente = d1->coeficiente+d2->coeficiente;
    resultado->potencia= d1->potencia;

}
