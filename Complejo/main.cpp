#include <iostream>
#include "Complejo.h"

using namespace std;

int main()
{
    Complejo c1(1,2),c2,c3(1);
    cout<<c2;
    c2=c1+c3;
    cout<<c2;
    c2++;
    cout<<c2;
    ++c2;
    cout<<c2;
    cin>>c2;
    if(c1==c2)
        cout<<"Son iguales"<<endl;
    else
        cout<<"No son iguales"<<endl;
    c2=c1+3;
    cout<<c2;
    c2=3+c1;
    cout<<c2;

    return 0;
}
