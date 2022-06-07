#include "cadena.h"

Cadena::Cadena(char *cad)
{
    if(cad == NULL)
    {
        this->cad= new char[1];
        strcpy(this->cad,"\0");
    }
    else
    {
        this->cad= new char[strlen(cad)+1];
        strcpy(this->cad,cad);
    }

}

Cadena::Cadena(const Cadena& obj)
{
    cad= new char[strlen(obj.cad)+1];
    strcpy(cad,obj.cad);
}

Cadena::~Cadena()
{
    delete[]cad;
}


Cadena Cadena::operator+(const Cadena& obj)const
{
    Cadena nue;
    nue.cad= new char[strlen(cad)+strlen(obj.cad)+1];
    strcpy(nue.cad,cad);
    strcat(nue.cad,obj.cad);
    return nue;
}

Cadena Cadena::operator+(const char *c)const
{
    Cadena nue;
    nue.cad= new char[strlen(cad)+strlen(c)+1];
    strcpy(nue.cad,cad);
    strcat(nue.cad,c);
    return nue;

}

Cadena& Cadena::operator=(const Cadena& obj)
{
    delete[]cad;
    cad= new char[strlen(obj.cad)+1];
    strcpy(cad,obj.cad);
    return (*this);
}

Cadena operator+(const char* c,const Cadena& obj)
{
    Cadena nue;
    nue.cad= new char[strlen(c)+strlen(obj.cad)+1];
    strcpy(nue.cad,c);
    strcat(nue.cad,obj.cad);
    return nue;
}

ostream& operator<<(ostream& sal,Cadena& obj)
{
    sal<<obj.cad<<endl;
    return sal;
}

istream& operator>>(istream& ent,Cadena& obj)
{
    char s[300];
    cout<<"ingrese una cadena:"<<endl;
    ent.getline(s,sizeof(s));
    delete[]obj.cad;
    obj.cad= new char[strlen(s)+1];
    strcpy(obj.cad,s);
    return ent;
}

int Cadena::longitud()
{
    return strlen(cad);
}
