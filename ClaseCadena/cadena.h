#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <iostream>
#include<string.h>
using namespace std;

class Cadena
{
    private:
        char *cad;

    public:
        Cadena(char* = NULL);
        Cadena(const Cadena&);
        ~Cadena();

        Cadena operator+(const Cadena&)const;
        Cadena operator+(const char*)const;
        Cadena& operator=(const Cadena&);

        friend Cadena operator+(const char*,const Cadena&);
        friend ostream& operator<<(ostream&,Cadena&);
        friend istream& operator>>(istream&,Cadena&);

        int longitud();
};


#endif // CADENA_H_INCLUDED
