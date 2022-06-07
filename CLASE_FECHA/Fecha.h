#ifndef FECHA_H
#define FECHA_H

#include <stdlib.h>
#include <iostream>

using namespace std;


class Fecha
{
    public:
        /// Constructores Destructor
        Fecha(int dia = 1, int mes = 1, int anio = 1600);
        Fecha(const Fecha &f);

        ~Fecha();

        /// Sobrecarga de operadores
        bool    operator == (const Fecha &)     const;
        bool    operator >= (const Fecha &)     const;
        bool    operator >  (const Fecha &)     const;
        bool    operator <  (const Fecha &)     const;
        bool    operator <= (const Fecha &)     const;
        bool    operator != (const Fecha &)     const;

        Fecha & operator    =  (const Fecha &);
        Fecha   operator    +  (int);
        Fecha   operator    -  (int);

        Fecha & operator    += (int);
        Fecha & operator    -= (int);

        Fecha & operator    ++ ();
        Fecha & operator    -- ();
        Fecha   operator    ++ (int);
        Fecha   operator    -- (int);

        friend Fecha operator + (int,  Fecha &);
        friend Fecha operator - (int,  Fecha &);
        friend ostream & operator << (ostream &, const Fecha &f);
        friend istream & operator >> (istream &, Fecha &);


        /// Metodos
        int cantidadDiasMes(int, int);
        bool validarFecha(int, int, int);
        int bisiesto(int);
        Fecha sumarNDias(int);
        Fecha restarNDias(int);
        int diferenciaFechas(Fecha &);
        int diaJul(Fecha &);


    protected:
    private:
        int dia;
        int mes;
        int anio;
};

#endif // FECHA_H
