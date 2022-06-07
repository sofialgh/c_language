//
// Created by sgallo_pickit on 7/6/2022.
//

#ifndef CLASECADENA_CLASECADENA_H
#define CLASECADENA_CLASECADENA_H


class Cadena{
private:
    char *cadena;

public:
    Cadena (char* = NULL);
    Cadena const (Cadena&);
    ~Cadena();

    Cadena operator+(const Cadena& const);
    Cadena operator+(const char* const);
    Cadena& operator=(const Cadena&);
    friend Cadena operator+(const char*,const Cadena&);
    friend ostream&  operator<<(ostream&,Cadena&);
    friend istream& operator>>(istream&,Cadena&);
    int longitud;
};


#endif //CLASECADENA_CLASECADENA_H
