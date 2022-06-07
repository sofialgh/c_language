#include "cadenas.h"

#define esBlanco(x) ((x) == ' ' || (x) == ',' || (x) == '/') ? 1:0
#define aMayusculas(x) ((x) >= 'a' && (x) <= 'z' ? (x) -32 : (x))
#define aMinusculas(x) ((x) >= 'A' && (x) <= 'Z' ? (x) +32 : (x))

void normalizarCadena2 ( char *cadena)
{
    char *inicio = cadena;
    char *actual = cadena;
    while(*actual)
    {
        while(esBlanco(*actual) && *actual)
        {
            actual++;
        }
        if(esLetra (*actual))
        {
            escribirPalabra(&actual,&inicio);
            escribirCaracter(' ', &inicio);
        }
    }
    escribirCaracter('\0', &inicio);
}
int esLetra( char caracter)
{
    return((caracter>= 'a' && caracter <= 'z')||caracter >= 'A' && caracter <= 'Z' );
}

void escribirPalabra(char **origen, char **destino)
{
    **destino = aMayusculas(**origen);
    (*destino)++;
    (*origen)++;

    while(esLetra(**origen))
    {
        **destino = aMinusculas(**origen);
        (*destino)++;
        (*origen)++;

    }
}
void escribirCaracter(char caracter, char **destino)
{
    **destino = caracter;
    (*destino)++;
}


void normalizarCadena ( char *cadena)
{
    char *inicio = cadena;
    char *actual = cadena;
    while(*actual)
    {
        while(esBlanco(*actual))
        {
            actual++;
        }
        if(esLetra(*actual))
        {
            *inicio = aMayusculas(*actual);
            inicio++;
            actual++;
        }
        while(esLetra(*actual))
        {
            *inicio = aMinusculas(*actual);
            inicio++;
            actual++;
        }
        *inicio= ' ';
        inicio++;

    }
    *inicio = '\0';
}
