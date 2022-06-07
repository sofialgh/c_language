#include <iostream>
#include "Persona.h"

using namespace std;

int main()
{
    Persona p1;
    Persona p2(1,"german");
    Persona p3(p2);
    char tecla[35];
    cout<<"Ingrese una palabra:"<<endl;
    cin>>tecla;
    p1.MostrarDatos();
    p2.MostrarDatos();
    p3.MostrarDatos();
    cout<<tecla<<endl;
    return 0;
}
