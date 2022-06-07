#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Persona
{
private:
    long dni;
    char nombre[35];
public:
    Persona();
    Persona(long,char *);
    void MostrarDatos(void);
    Persona(const Persona&);
};



#endif // PERSONA_H_INCLUDED
