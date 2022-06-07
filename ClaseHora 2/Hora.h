#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

#include <iostream>
using namespace std;

class Hora
{
    private:
    int hora,minutos,segundos;

    public:
        Hora();

        Hora(const int,const int, const int);
        Hora(const Hora& hora);

        Hora& operator ++();
        Hora operator ++(int);
        Hora& operator=(const Hora&);
        Hora operator+(const Hora&)const;
        Hora operator+(const long&)const;

        friend Hora operator+(const long&,const Hora&);
        friend ostream& operator << (ostream& salida, Hora& hora);
        friend istream& operator >> (istream& entrada, Hora& hora);
        void HoraReal(int &h,int &m,int &seg);
        void Horanegativa(int &h,int &m,int &seg);
};



#endif // HORA_H_INCLUDED
