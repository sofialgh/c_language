//
// Created by sgallo_pickit on 7/6/2022.
//

#include "lista.h"



#define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )


void crearLista(tLista *p)
{
 *p = NULL;
}


int listaVacia(const tLista *p)
{
 return *p == NULL;
}


int listaLlena(const tLista *p, unsigned cantBytes)
{
 tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
 tDato *info = malloc(cantBytes);
 free(aux);
 free(info);
 return aux == NULL || info == NULL;
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

 int ponerAlComienzo(tLista *p, const tDato *d, unsigned cantBytes)
 {
 tNodo *nue;

 if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
   (nue->info = malloc(cantBytes)) == NULL)
 {
 free(nue);
 return 0;
 }
 memcpy(nue->info, d, cantBytes);
 nue->tamInfo = cantBytes;
 nue->sig = *p;
 *p = nue;
 return 1;
 }


 int sacarPrimeroLista(tLista *p, tDato *d, unsigned cantBytes)
 {
 tNodo *aux = *p;

 if(aux == NULL)
  return 0;
 *p = aux->sig;
 memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
 free(aux->info);
 free(aux);
 return 1;
 }


 int verPrimeroLista(const tLista *p, tDato *d, unsigned cantBytes)
 {
 if(*p == NULL)
  return 0;
 memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
 return 1;
 }


 int ponerAlFinal(tLista *p, const tDato *d, unsigned cantBytes)
 {
 tNodo *nue;

 while(*p)
     p = &(*p)->sig;
 if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
 (nue->info = malloc(cantBytes)) == NULL)
 {
 free(nue);
 return 0;
 }
 memcpy(nue->info, d, cantBytes);
 nue->tamInfo = cantBytes;
 nue->sig = NULL;
 *p = nue;
 return 1;
 }


 int sacarUltimoLista(tLista *p, tDato *d, unsigned cantBytes)
 {
 if(*p == NULL)
  return 0;
 while((*p)->sig)
  p = &(*p)->sig;
 memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
 free((*p)->info);
 free(*p);
 *p = NULL;
 return 1;
 }


 int verUltimoLista(const tLista *p, tDato *d, unsigned cantBytes)
 {
 if(*p == NULL)
  return 0;
 while((*p)->sig)
  p = &(*p)->sig;
 memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
 return 1;
 }
void recorrerYMostrarLista( tLista *p, void (*mostrar)(const void *))
{

    while(*p)
    {
        mostrar((*p)->info);
        p = &(*p)->sig;

    }
    printf("\n");
}

void mostrar (const tDato *info)
{
    printf("%d %s %d\n",info->codigo,info->descripcion,info->cantidad);
}
int deArchivoOrdenadoALista(tLista *p, char *nombreArchivo)
{
    FILE *pf;
    Producto buffer;
    if(!abrirArchivo(&pf,nombreArchivo,"rb",0))
        return 0;
    while((fread(&buffer,sizeof(Producto),1,pf)))
    {   if(!listaLlena(p,sizeof(tDato)))
            ponerAlFinal(p,&buffer,sizeof(Producto));
    }
    fclose(pf);
    return 1;
}

int comparar ( const tDato *info1, const tDato *info2)
{
    return(info1->codigo-info2->codigo);
}
int eliminarDuplicados(tLista *p, int (*comparar) (const tDato *info1, const tDato *info2))
{
   tNodo *actual = *p;
   tNodo *sig;
   int cmp;
   while(actual->sig && (cmp=comparar(actual->info,actual->sig->info)) <= 0)
   {
       if(cmp == 0)
       {
           actual->info->cantidad+=actual->sig->info->cantidad;
           sig=actual->sig->sig;
           free(actual->sig->info);

           free(actual->sig);
           actual->sig= sig;
       }
       else
       actual = actual->sig;
   }
}
/*
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
}*/
