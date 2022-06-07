#include "Hora.h"

Hora::Hora(const int seg)
{
    this->totalseg =seg;
}

Hora::Hora(const int hora, const int minutos, const int seg)
{
    this->totalseg =  hora*3600 + minutos*60 + seg;
}

Hora::Hora(const Hora& hora)
{
    this->totalseg = hora.totalseg;
}

Hora Hora::operator++(int)
{
    Hora nue(*this);
    this->totalseg++;

    return nue;
}

Hora& Hora::operator++()
{
    this->totalseg++;
    return (*this);
}

Hora Hora::operator--(int)
{
    Hora nue(*this);
    totalseg--;

    return nue;
}

Hora& Hora::operator--()
{
    totalseg--;
    return (*this);
}

Hora& Hora:: operator =(const Hora & obj)
{
    totalseg=obj.totalseg;
    return *this;
}

Hora Hora::operator+(const Hora &obj)const
{
    Hora nue(totalseg+obj.totalseg);
    return nue;
}

Hora Hora::operator+(const long &seg)const
{
    Hora nue(totalseg+seg);

    return nue;
}

Hora Hora::operator-(const long& seg)const
{
    Hora nue(totalseg-seg);
    return nue;
}

Hora Hora::operator-(const Hora& obj)const
{
    Hora nue(totalseg-obj.totalseg);
    return nue;
}

Hora Hora::operator*(const long &n)const
{
    Hora nue(totalseg*n);
    return nue;
}

Hora operator+(const long &seg,const Hora &obj)
{
    Hora nue(seg+obj.totalseg);

    return nue;
}

Hora operator*(const long &n,const Hora &obj)
{
    Hora nue(n*obj.totalseg);

    return nue;
}

Hora& Hora::operator+=(const Hora &obj)
{
    this->totalseg= (this->totalseg+obj.totalseg);
    return (*this);
}

Hora& Hora::operator+=(const long& seg)
{
    this->totalseg= (this->totalseg+seg);
    return (*this);
}

ostream& operator << (ostream& salida, Hora& obj)
{
    int h=0,m=0,s=obj.totalseg;

    HoraReal(h,m,s);

    salida << h << ':' << m << ':' << s << endl;

    return salida;
}

istream& operator >> (istream& entrada, Hora& obj)
{
    int h,m,s;
    cout << "ingrese hora: ";
    entrada >> h;
    cout << "ingrese minutos: ";
    entrada >> m;
    cout << "ingrese segundos: ";
    entrada >> s;

    HoraReal(h,m,s);

    return entrada;
}

void HoraReal(int &h, int &m, int &s)
{

    while((s - 3600) >= 0)
    {
        h++;
        s -= 3600;
    }
    while((s - 60) >= 0)
    {
        m++;
        s -= 60;
    }

    while((h-24)>=0)
    {
        while((m-60)>=0)
        {
            while((s-60)>=0)
            {
                m++;
                s-=60;
            }
            h++;
            m-=60;
        }
        h-=24;
    }

}
