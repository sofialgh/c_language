
#include "Fecha.h"


int main()
{
    Fecha f1(1, 12, 2017);
    Fecha f2(20, 2, 2015);
    Fecha f3(1, 1, 2018);
    Fecha f4(10, 3, 2017);
    Fecha f5;
    Fecha f6;

    cout << f1 << f2 << f3 << f4 << f5;

    f5 = f1 + 1;
    f6 = 1 + f1;

    cout << "f5 = f1 + 1 " << " y "<< "f5 = 1 + f1 " << endl;
    cout << f5 << f6;

    if(f1 == f2)
        cout << "f1 Y f2 SON IGUALES" << endl;
    else
        cout << "f1 Y f2 SON DISTINTOS" << endl;

    cout << "LA DIFERENCIA ENTRE f3 y f4: " << f3.diferenciaFechas(f4) << endl;

    if(f5 == f6)
        cout << "f5 Y f6 SON IGUALES" << endl;
    else
        cout << "SON DISTINTOS" << endl;

    if(f5 != f6)
        cout << "f5 Y f6 SON DISTINTOS" << endl;
    else
        cout << "f5 Y f6 SON DISTINTOS" << endl;

    return 0;
}
