#include <iostream>
using namespace std;

int main() {
    int liczba;
    cout << "Podaj liczbę: ";
    cin >> liczba;

    for (int i = 2; i <= liczba; i++) {
        if (liczba % i == 0) {
            cout << "Najmniejszy dzielnik liczby " << liczba << " to " << i;
            break;
        }
    }

    return 0;
}
