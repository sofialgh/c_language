#include <iostream>

int main() {
    Cadena c1("Hsola"),
            c2(c1),
            c3(c1 + c2),
            c4, c5, c6;
    c4 = c1 + " Juan Carlos";
    cin >> c5;
    c6 = "Pedro. " + c1;
    cout << "c1 = " << c1 << endl
         << "c2 = " << c2 << endl
         << "c3 = " << c3 << endl
         << "c4 = " << c4 << endl
         << "c5 = " << c5 << endl
         << "c6 = " << c6 << endl;
    cout << "Longitud de c1 = " << c1.longitud() << endl;
}
