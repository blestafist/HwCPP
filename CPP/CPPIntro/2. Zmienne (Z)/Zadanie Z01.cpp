#include <iostream>
using namespace std;

int main()
{
    int a, b;  // deklarowanie zmiennych

    cout << "Podaj długość pierwszego boku: ";  // input pierwszego boku
    cin >> a;

    cout << "Podaj długość drugiego boku: ";  // input drugiego boku
    cin >> b;

    cout << "Pole prostokąta = " << a * b << endl;   // obliczenie i wyświetlenie pola prostokąta
    cout << "Obwód prostokąta = " << 2 * (a + b) << endl;  // obliczenie i wyświetlenie obwodu prostokąta


    return 0;
}
