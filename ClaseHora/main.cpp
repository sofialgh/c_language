#include "Hora.h"

int main()
{

    Hora h1(27,58,0);
    Hora h2(2,3,4);
    Hora h3;
    Hora h4;
    Hora h5;
    Hora h6(55);
    Hora h7(h6);
    Hora h8(3*h7);
    Hora h9(h7*3);
    Hora h10;

    h3=3600+h1;
    h4=h2+3600;
    h5=h1+h2;
    h6--;

    cout<<"h1:\t"<<h1<<endl;
    cout<<"h2:\t"<<h2<<endl;
    cout<<"h3=3600+h1:\t"<<h3<<endl;
    cout<<"h4=h2+3600:\t"<<h4<<endl;
    cout<<"h5=h1+h2:\t"<<h5<<endl;
    cout<<"h6:\t"<<h6<<endl;
    cout<<"h7:\t"<<h7<<endl;
    cout<<"h8:\t"<<h8<<endl;
    cout<<"h9:\t"<<h9<<endl;

    h10=h7+=h6+=h8+=5;
    cout<<"h10=h7+=h6+=h8+=5:\t"<<h10<<endl;
    //cout<<"h7-h6:\t"<<h7-h6<<endl;


    return 0;
}
