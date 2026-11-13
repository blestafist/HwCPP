#include <iostream>
using namespace std;

int main() {
    int liczba, nowaLiczba;

    cout << "Podaj liczbę: ";
    cin >> liczba;

    if (liczba < 0) {
        nowaLiczba = liczba * -1;
        cout << "Wartość bezwzględna liczby " << liczba << " to " << nowaLiczba;
    }

    else
        cout << "Wartość bezwzględna liczby " << liczba << " to " << liczba;

    return 0;
}
