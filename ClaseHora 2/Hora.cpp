#include "Hora.h"

Hora::Hora()
{
    hora=0;
    minutos=0;
    segundos=0;
}


Hora::Hora(const int hora, const int minutos, const int segundos)
{
    this->hora=hora;
    this->minutos=minutos;
    this->segundos=segundos;
}

Hora::Hora(const Hora& obj)
{
    hora=obj.hora;
    minutos=obj.minutos;
    segundos=obj.segundos;
}

Hora Hora::operator++(int)
{
    Hora nue(*this);
    segundos++;

    return nue;
}

Hora& Hora::operator++()
{
    segundos++;
    return (*this);
}

Hora& Hora:: operator =(const Hora & obj)
{
    hora=obj.hora;
    minutos=obj.minutos;
    segundos=obj.segundos;
    return *this;
}

Hora Hora::operator+(const Hora &obj)const
{
    Hora nue(hora+obj.hora,minutos+obj.minutos,segundos+obj.segundos);
    return nue;
}

Hora Hora::operator+(const long &seg)const
{
    Hora nue(hora,minutos,segundos+seg);
    return nue;
}

Hora operator+(const long &seg,const Hora &obj)
{
    Hora nue(obj.hora,obj.minutos,seg+obj.segundos);
    return nue;
}

ostream& operator << (ostream& salida, Hora& obj)
{
    if((obj.hora<0)||(obj.minutos<0)||(obj.segundos)<0)
        obj.Horanegativa(obj.hora,obj.minutos,obj.segundos);
    else
        obj.HoraReal(obj.hora,obj.minutos,obj.segundos);

    //obj.HoraReal(obj.hora,obj.minutos,obj.segundos);
    salida << obj.hora << ':' << obj.minutos << ':' << obj.segundos << endl;

    return salida;
}

istream& operator >> (istream& entrada, Hora& obj)
{

    cout << "ingrese hora: ";
    entrada >> obj.hora;
    cout << "ingrese minutos: ";
    entrada >> obj.minutos;
    cout << "ingrese segundos: ";
    entrada >> obj.segundos;
    return entrada;
}


void Hora::HoraReal(int &h, int &m, int &s)
{

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

void Hora::Horanegativa(int &h, int &m, int &s)
{
    if(h<0)
        h*=-1;
    if(m<0)
        m*=-1;
    if(s<0)
        s*=-1;

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
