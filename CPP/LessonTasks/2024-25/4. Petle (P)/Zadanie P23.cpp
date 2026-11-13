#include <iostream>
using namespace std;

int main() {
    int liczba, dz = 2;
    cout << "Podaj liczbę: ";
    cin >> liczba;

    while (liczba != 1) {
        if (liczba % dz == 0) {
            cout << dz << ' ';
            liczba /= dz;
        }

        else {
            dz++;
        }
    }

    return 0;
}
