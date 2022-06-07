#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED

#include <iostream>
using namespace std;

class Complejo
{
private:
    float re,im;
public:
    Complejo(float=0,float=0);
    Complejo& operator =(const Complejo&);
    Complejo& operator++();
    Complejo operator++(int);
    Complejo operator+(const Complejo&)const; //suma de dos objetos
    Complejo operator+(const float&)const;    //suma de un objeto mas un escalar
    Complejo operator *(const Complejo &obj) const;   // obj*obj

    bool operator ==(const Complejo&)const;
    friend Complejo operator *(int n, const Complejo &obj); // num*obj
    friend Complejo operator+(const float,const Complejo&); //suma de un escalar mas un complejo
    friend ostream& operator<<(ostream&,const Complejo&);
    friend istream& operator>>(istream&,Complejo&);
};


#endif // COMPLEJO_H_INCLUDED
