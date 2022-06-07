#include "Complejo.h"

Complejo::Complejo(float re,float im): re(re), im(im)
{}

Complejo& Complejo::operator=(const Complejo& obj)
{
    re=obj.re;
    im=obj.im;
    return *this;
}

Complejo& Complejo::operator++()
{
    re++;
    im++;
    return *this;
}

Complejo Complejo::operator++(int)
{
    Complejo nue(*this);
    re++;
    im++;
    return nue;
}

Complejo Complejo::operator+(const Complejo& obj)const
{
    Complejo nue(re+obj.re,im+obj.im);
    return nue;
}

Complejo Complejo::operator+(const float& real)const
{
    Complejo nue(re+real,im);
    return nue;
}

bool Complejo::operator==(const Complejo& obj)const
{
    return (re== obj.re && im==obj.im);
}

Complejo operator+(const float izq,const Complejo& der)
{
    Complejo nue(izq+der.re,der.im);
    return nue;
}

Complejo operator *(int n, const Complejo &obj)
{
   Complejo aux(n * obj.re, n * obj.im);
   return aux;
}


Complejo Complejo::operator *(const Complejo &obj) const
{
   Complejo aux(re * obj.re - im * obj.im,
                im * obj.re + re * obj.im);
   return aux;
}

ostream& operator<<(ostream &sal,const Complejo& obj)
{
    sal<<"Real:"<<obj.re<<endl;
    sal<<"Imaginario:"<<obj.im<<endl;
    return sal;
}

istream& operator>>(istream& ent,Complejo& obj)
{
    cout<<"Ingrese parte real:";
    ent>>obj.re;
    cout<<"ingrese parte imaginaria:";
    ent>>obj.im;

    return ent;
}
