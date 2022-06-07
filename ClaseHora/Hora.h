#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

#include <iostream>
using namespace std;

class Hora
{
    private:
    long totalseg;

    public:

        Hora(const int=0);
        Hora(const int,const int, const int);
        Hora(const Hora&);

        Hora& operator ++();
        Hora operator ++(int);
        Hora operator --(int);
        Hora& operator --();
        Hora& operator=(const Hora&);
        Hora operator+(const Hora&)const;
        Hora operator+(const long&)const;
        Hora operator-(const Hora&)const;
        Hora operator-(const long&)const;
        Hora operator*(const long&)const;
        Hora& operator+=(const Hora&);
        Hora& operator+=(const long&);

        friend Hora operator+(const long&,const Hora&);
        friend Hora operator*(const long&,const Hora&);
        friend ostream& operator << (ostream& salida, Hora& hora);
        friend istream& operator >> (istream& entrada, Hora& hora);

};

void HoraReal(int &h,int &m,int &seg);


#endif // HORA_H_INCLUDED
