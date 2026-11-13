#include <iostream>
using namespace std;

int main()
{
    int liczba1, liczba2;

    cout << "Podaj pierwszą liczbę: ";
    cin >> liczba1;

    cout << "Podaj drugą liczbę: ";
    cin >> liczba2;

    cout << liczba2 << "% z liczby " << liczba1 << " = " << (liczba1 * liczba2) / 100;

    return 0;
}
