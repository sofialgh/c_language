#include "Racional.h"

int mcd(int num,int den)
{
    int rest=1;
    for(int i=1;i<=num;i++)
    {
        if((num%i == 0) && (den%i == 0))
            rest=i;
    }
    return rest;

}

Racional::Racional(int num,int den)
{
    int div;

    if(den == 0)
    {
        numerador=num;
        denominador=1;
        cerr<<"No se puede dividir por 0"<<endl;

    }
    else
    {
        div=mcd(num,den);
        if((num<0 && den<0) || (num>0 && den>0))  // son los dos del mismo signo
        {
            if((num<0 && den<0))
            {
                numerador=num/div;
                denominador=(den/div)*-1;
            }
            else
            {
                numerador=num/div;
                denominador=den/div;
            }

        }
        else
        {
            if(num<0)
            {
                numerador=num/div;
                denominador=den/div;
            }
            else
            {
                numerador=(num/div)*-1;
                denominador=(den/div)*-1;
            }
        }

    }

}

Racional Racional::operator+(const Racional& obj)const
{
    Racional nue((numerador*obj.denominador)+(denominador*obj.numerador),denominador * obj.denominador);
    return nue;
}

Racional Racional::operator+(const int n)const
{
    Racional nue(numerador+(denominador*n),denominador);
    return nue;
}

Racional& Racional::operator=(const Racional& obj)
{
    numerador= obj.numerador;
    denominador= obj.denominador;

    return *this;
}

Racional operator+(const int n,const Racional& obj)
{
    Racional nue(((n*obj.denominador)+obj.numerador),obj.denominador);
    return nue;
}

ostream& operator<<(ostream& sal,const Racional& obj)
{
    sal<<obj.numerador<<"/"<<obj.denominador<<endl;
    return sal;
}

istream& operator>>(istream& ent,Racional &obj)
{
    ent>>obj.numerador;
    ent>>obj.numerador;
    return ent;
}

