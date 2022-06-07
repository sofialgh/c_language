#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED

#include <iostream>
using namespace std;

class Racional
{
    private:
        int numerador;
        int denominador;
    public:

        Racional(int num=0,int den=0);

        Racional operator+(const Racional&)const;
        Racional operator+(const int)const;
        Racional& operator=(const Racional&);

        friend Racional operator+(const int num,const Racional&);
        friend int mcd(int num,int den);
        friend ostream &operator <<(ostream &sal, const Racional &obj);
        friend istream& operator>>(istream&,Racional&);


};



#endif // RACIONAL_H_INCLUDED
