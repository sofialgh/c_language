#include "Fecha.h"


/// Constructores Destructor
Fecha::Fecha(int dia, int mes, int anio)
{
    if(validarFecha(dia,mes,anio))
    {
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
    else
    {
        this->dia = 1;
        this->mes = 1;
        this->anio = 1600;
        cout << "Fecha Invalida" << endl;
    }
}


Fecha::Fecha(const Fecha &f)
{
    dia = f.dia;
    mes = f.mes;
    anio = f.anio;
}

Fecha::~Fecha()
{
    //dtor
}

/// Sobrecarga de operadores
ostream & operator << (ostream &o, const Fecha & f)
{
    o << f.dia << "/" << f.mes << "/" << f.anio << endl;
    return o;
}

Fecha operator + (int numDias , Fecha &f)
{
    f = f.sumarNDias(numDias);
    return f;
}

Fecha operator - (int numDias , Fecha &f)
{
    f = f.restarNDias(numDias);
    return f;
}

Fecha & Fecha::operator = (const Fecha &f)
{
    if(this != &f)
    {
        dia = f.dia;
        mes = f.mes;
        anio = f.anio;
    }

    return *this;
}

Fecha   Fecha::operator + (int numDias)
{
    Fecha fechaAux(*this);
    fechaAux = fechaAux.sumarNDias(numDias);
    return fechaAux;
}


Fecha   Fecha::operator - (int numDias)
{
    Fecha fechaAux(*this);
    fechaAux = fechaAux.restarNDias(numDias);
    return fechaAux;
}

Fecha & Fecha::operator += (int numDias)
{
    *this = sumarNDias(numDias);
    return *this;
}

Fecha & Fecha::operator -= (int numDias)
{
    *this = restarNDias(numDias);
    return *this;
}

Fecha & Fecha::operator ++ ()
{
    *this = sumarNDias(1);
    return *this;
}

Fecha Fecha::operator ++ (int)
{
    Fecha fechaAux(*this);
    *this = sumarNDias(1);
    return fechaAux;
}

Fecha & Fecha::operator -- ()
{
    *this = restarNDias(1);
    return *this;
}

Fecha Fecha::operator -- (int)
{
    Fecha fechaAux(*this);
    *this = restarNDias(1);
    return fechaAux;
}

istream & operator >> (istream &i, Fecha &f)
{
    int valida;
    do
    {
        cout << "Introducir fecha: " << endl;
        cout << "Dia: ";
        i >> f.dia;
        cout << "Mes: ";
        i >> f.mes;
        cout << "Anio: ";
        i >> f.anio;
        valida = f.validarFecha(f.dia, f.mes,f.anio);
        if(!valida)
        {
            cout << "Fecha Incorrecta" << endl;
            system("pause");
            system("cls");

        }

    }while(!valida);

    return i;
}


bool   Fecha::operator == (const Fecha &f) const
{
    return  this->anio == f.anio && this->mes == f.mes && this->dia == f.dia;
}

bool   Fecha::operator != (const Fecha &f) const
{
    return  this->anio != f.anio || this->mes != f.mes || this->dia != f.dia;
}

bool  Fecha::operator < (const Fecha  &f) const
{
    int cmp;
    if(this->anio != f.anio)
        cmp =  this->anio - f.anio;
    else if(this->mes != f.mes)
        cmp =  this->mes - f.mes;
    else
        cmp =  this->dia - f.dia;
    return cmp < 0;
}


bool   Fecha::operator > (const Fecha &f) const
{
    int cmp;
    if(this->anio != f.anio)
        cmp =  this->anio - f.anio;
    else if(this->mes != f.mes)
        cmp =  this->mes - f.mes;
    else
        cmp =  this->dia - f.dia;
    return cmp > 0;
}

bool   Fecha::operator >= (const Fecha &f) const
{
    int cmp;
    if(this->anio != f.anio)
        cmp =  this->anio - f.anio;
    else if(this->mes != f.mes)
        cmp =  this->mes - f.mes;
    else
        cmp =  this->dia - f.dia;
    return cmp >= 0;
}

bool   Fecha::operator <= (const Fecha &f) const
{
    int cmp;
    if(this->anio != f.anio)
        cmp =  this->anio - f.anio;
    else if(this->mes != f.mes)
        cmp =  this->mes - f.mes;
    else
        cmp =  this->dia - f.dia;
    return cmp <= 0;
}


/// Metodos
int Fecha::bisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0 ? 1 : 0 ;
}

int Fecha::cantidadDiasMes(int mes, int anio)
{
    int cantDias[2][12] =   {
                                {    31,28,31,30,31,30,31,31,30,31,30,31     },
                                {    31,29,31,30,31,30,31,31,30,31,30,31     }
                            };/// no hace falta los 2 vectors... con ver si mes es 2 y bisieto.. ):<

    return cantDias[bisiesto(anio)][mes - 1];
}

bool Fecha::validarFecha(int dia, int mes, int anio)
{
    if(anio >= 1600)
        if(mes >= 1 && mes <= 12)
            if(dia >= 1 && dia <= cantidadDiasMes(mes, anio))
                return true;
    return false;
}

Fecha Fecha::sumarNDias(int dias)
{
    Fecha f(*this);
    int cantidad;

    dias += f.dia;

    while(dias > (cantidad = cantidadDiasMes(f.mes,f.anio)))
    {
        f.anio = f.mes == 12 ? f.anio + 1 : f.anio;
        f.mes = f.mes == 12 ? 1 : f.mes + 1;
        dias -= cantidad;
    }
    f.dia = dias;
    return f;
}

Fecha Fecha::restarNDias(int dias)
{
    Fecha f(*this);

    while(dias >= f.dia)
    {
        f.anio = f.mes == 1 ? f.anio - 1 : f.anio;
        f.mes =  f.mes == 1 ?  12 : f.mes - 1;
        dias -= cantidadDiasMes(f.mes,f.anio);
    }

    f.dia -= dias;
    return f;
}

int Fecha::diferenciaFechas(Fecha & f2)
{
    int ca1 = anio - 1600;
    int ca2 = f2.anio - 1600;

    int cd1 = ca1 * 365 + ca1 / 4 - ca1 / 100 + ca1 / 400 + diaJul(*this);
    int cd2 = ca2 * 365 + ca2 / 4 - ca2 / 100 + ca2 / 400 + diaJul(f2);

    return  cd1 - cd2;
}

int Fecha::diaJul(Fecha &f)
{
    int dj = 0, i;
    for(i = 0; i < f.mes; i ++)
        dj += cantidadDiasMes(i + 1, f.anio);
    dj += f.dia;
    return dj;
}

