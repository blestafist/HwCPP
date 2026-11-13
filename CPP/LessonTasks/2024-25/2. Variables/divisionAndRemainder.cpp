#include <iostream>
using namespace std;

int main()
{
    int dzielna, dzielnik;  // deklarowanie zmiennych

    cout << "Podaj dzielną: ";  // dzielna
    cin >> dzielna;

    cout << "Podaj dzielnik: ";  // dzielnik
    cin >> dzielnik;

    cout << "Iloczyn wynosi: " << dzielna / dzielnik << endl;   // wynik działania (dzielenia)
    cout << "Reszta z dzielenia wynosi: " << dzielna % dzielnik << endl;  // reszta z dzielenia

    return 0;
}
