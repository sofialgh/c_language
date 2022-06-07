#include "lista.h"
#include "funciones.h"

#define TAM_LINEA 100
//////////****JUAMPI TE AMO****////
void crearLista(tLista *p)
{
    *p = NULL;
}

void vaciarLista(tLista *p)
{
    while(*p)
    {
        tNodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int listaVacia(const tLista *p)
{
    return (*p == NULL);
}

int listaLlena(const tLista *p, unsigned cantBytes)
{
   tNodo *aux = (tNodo *) malloc(sizeof (tNodo));
   void *info = (void *) malloc(cantBytes);
   free(aux);
   free(info);
   return ( aux == NULL || info == NULL);
}

void recorrerYMostrarLista( tLista *p, void (*mostrar)(const void *))
{

    while(*p)
    {
       //mostrar(&(*p)->info);
      printf("X(%d)(%d)\n",(*p)->info->potencia,(*p)->info->coeficiente);

        //p = &(*p)->sig;
        p = &(*p)->sig;

    }
    printf("\n");
}
///int insertarEnOrden(tLista *p, const tDato *d, int (*comparar)(const tDato *, const tDato *));

int insertarEnOrden(tLista *p,const tDato *d,
                    int (*comparar)(const void *,const void *)
                    )
{
    int cmp;
    while(*p && (cmp=comparar(d,(*p)->info))<=0)  ///> ASC , <DESC
    {
        if(cmp == 0)
        {
           (*p)->info->coeficiente+=d->coeficiente;
            //acumular(&(*p)->info,d);  ///Tener en cuenta que si son lineas de texto lo q hay que acumular puede fallar
            return 1;

        }
        p=&(*p)->sig;

    }
    tNodo *nue=(tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
        return 0;
    nue->info = malloc(sizeof(tDato));
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info,d,sizeof(tPolinomio));
    nue->tamInfo = sizeof(tPolinomio);
    nue->sig = *p;
    *p = nue;
    return 1;
}

int ponerAlComienzoLista(tLista *p, tDato *d, unsigned cantBytes)
{
    tNodo *nue;
    if((nue = (tNodo *)malloc (sizeof(tNodo)))== NULL || (nue->info = malloc(cantBytes))== NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig= *p;
    *p = nue;
    return 1;
}

int deArchivoTxtAListaOrdenada(tLista *p, const char *nombreArchivo)
{
    FILE *archivo;
    char buffer[TAM_LINEA];
    tDato p1;

if(abrirArchivo(&archivo,nombreArchivo,"rt",1))
{
    while(fgets(buffer,sizeof(buffer),archivo))
    {
        trozarCamposLongitudVariable(&p1,buffer);
        insertarEnOrden(p,&p1,compararPotencia);
    }
    fclose(archivo);
    return 1;
}
return 0;
}
void sumarListas(tLista *listaResultante, const tLista *p1, const tLista *p2,void (*sumar)(const void*,const void*,tDato*),int (*comparar)(const void*, const void *))
{

    tDato polinomioResultante;
    while(*p1 && *p2 )
    {


            if(comparar((*p1)->info,(*p2)->info)== 0) //los terminos tienen igual grado entonces sumo
            {
                    sumar((*p1)->info,(*p2)->info,&polinomioResultante);
                    ponerAlComienzoLista(listaResultante,&polinomioResultante,sizeof(tPolinomio));
                    p1=&(*p1)->sig; //avanzo los dos punteros al siguiente nodo
                    p2=&(*p2)->sig;
            }

            else if(comparar((*p1)->info,(*p2)->info)>0)
            {
                    ponerAlComienzoLista(listaResultante,(*p1)->info,sizeof(tPolinomio));

                    p1=&(*p1)->sig;

            }

            else if(comparar((*p1)->info,(*p2)->info)< 0)
            {
                    ponerAlComienzoLista(listaResultante,(*p2)->info,sizeof(tPolinomio));
                    p2=&(*p2)->sig;

            }
    }
    while(*p1)
    {
        ponerAlComienzoLista(listaResultante,(*p1)->info,sizeof(tPolinomio));
                    p1=&(*p1)->sig;
    }

while(*p2)
    {
        ponerAlComienzoLista(listaResultante,(*p2)->info,sizeof(tPolinomio));
                    p2=&(*p2)->sig;
    }
}
int deListaAArchivoTxt(tLista *p, FILE **pf,const char *nombreArchivo)
{
    if(abrirArchivo(pf,nombreArchivo,"wt",1))
    {
        while(*p)
        {
            fprintf(*pf,"X(%d)(%d)\n",(*p)->info->potencia,(*p)->info->coeficiente);
            p=&(*p)->sig;
        }
        return 1;
    }
    return 0;
}
