#include "Racional.h"

int main()
{
    Racional r0(2,3),r1(-2,3),r2(-2,-4),r3(3,-2),r4;

   cout << "Valores iniciales:" << endl
        << "r0 = " << r0 << endl << "r1 = " << r1 << endl
        << "r2 = " << r2 << endl << "r3 = " << r3 << endl;

   r0 = 4 + r3;
   r1 = r2 + r3;
   r4= r3 + 4;

   cout << "Valores finales:" << endl
        << "r0 = " << r0 << endl
        << "r1 = " << r1 << endl
        << "r4 = " << r4 <<endl;

    return 0;
}
