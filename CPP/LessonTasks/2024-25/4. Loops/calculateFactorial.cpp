#include <iostream>
using namespace std;

int main() {
    int liczba, silnia = 1;

    cout << "Podaj liczbę mniejszą od 20: ";
    cin >> liczba;

    for (int i = 2; i <= liczba; i++) {
        silnia *= i;
    }

    cout << "Silnia liczby " << liczba << " to " << silnia;


    return 0;
}
