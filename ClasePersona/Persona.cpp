#include "Persona.h"
Persona::Persona()
{
    dni=0;
    strcpy(nombre,"nn");
}

Persona::Persona(long dni,char *nombre)
{
    this->dni=dni;
    strcpy(this->nombre,nombre);
}

void Persona::MostrarDatos(void)
{
    cout<<"["<<dni<<"-"<<nombre<<"]"<<endl;
}

Persona::Persona(const Persona&obj)
{
    dni= obj.dni;
    strcpy(nombre,obj.nombre);
}
